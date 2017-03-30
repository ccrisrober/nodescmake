#pragma once

#include "visitors/StartComponents.h"
#include "visitors/FetchCameras.h"
#include "visitors/UpdateWorldState.h"
#include "scenegraph/Node.h"
#include "scenegraph/Group.h"
#include "scenegraph/Camera.h"
#include "RenderQueue.h"

#include <algorithm>
#include <string>

#include <nodes/api.h>

#include "systems/System.h"
#include "systems/RenderSystem.h"
#include "systems/UpdateSystem.h"

#include <unordered_map>

class Engine
{
public:
  Group* scene = nullptr;
  NODES_API
  void setScene( Group *g )
  {
    scene = g;
    if ( scene != nullptr )
    {
      //scene->perform( UpdateWorldState( ) );
      //scene->perform( UpdateRenderState( ) );

      FetchCameras fetchCameras;
      scene->perform( fetchCameras );
      fetchCameras.forEachCamera( [ &] ( Camera *camera ) {
        if ( Camera::mainCamera( ) == nullptr || camera->isMainCamera( ) )
        {
          Camera::mainCamera( camera );
        }
        _cameras.push_back( camera );
      } );

      scene->perform( StartComponents( ) );
      //scene->perform( UpdateWorldState( ) );
      //scene->perform( UpdateRenderState( ) );
    }
  }
  std::vector< Camera * > _cameras;
  NODES_API
  virtual void start( void )
  {
  }
  NODES_API
  virtual bool update( void )
  {
    std::cout << "Engine will update" << std::endl;
    // UPDATE STEP
    // TODO: Fixed update
    scene->perform( UpdateWorldState( ) );

    std::vector<RenderQueue*> rqCollection;

    forEachCamera( [ &] ( Camera *c )
    {
      if ( c != nullptr )
      {
        auto renderQueue = new RenderQueue( );
        renderQueue->camera( c );
        //scene->perform( ComputeRenderQueue( c, renderQueue ) );
        rqCollection.push_back( renderQueue );
      }
    } );
    // \\ UPDATE STEP

    // RENDER STEP
    // TODO
    if ( !rqCollection.empty( ) )
    {
      RenderQueue *mainQueue = nullptr;
      std::for_each( rqCollection.begin( ),
        rqCollection.end( ), [ &] ( RenderQueue* rq )
      {
        if ( rq->camera( ) != Camera::mainCamera( ) )
        {
          // Render queue with rq camera
          std::cout << "Render outscreen (" << rq->camera( )->name( ) << ")" << std::endl;
        }
        else
        {
          mainQueue = rq;
        }
      } );

      if ( mainQueue != nullptr )
      {
        // Render main queue
        std::cout << "render main queue (" << mainQueue->camera( )->name( ) << ")" << std::endl;
      }
    }
    // \\ RENDER STEP
    std::cout << "Engine did update" << std::endl;

    return false;
  }
  NODES_API
  virtual int run( void )
  {
    start( );
    bool done = false;
    while ( !done )
    {
      done = !update( );
    }
    return 0;
  }
  NODES_API
  void forEachCamera( std::function< void( Camera * ) > callback )
  {
    for ( auto camera : _cameras )
    {
      callback( camera );
    }
  }



  NODES_API
  void iAddSystem( System* ss )
  {
    _systems.insert( std::make_pair( ss->name( ), ss ) );
  }

  NODES_API
  void iStart( void )
  {
    iAddSystem( new UpdateSystem( ) );
    iAddSystem( new RenderSystem( ) );

    for ( auto system : _systems )
    {
      if ( system.second != nullptr )
      {
        system.second->start();
      }
    }
  }
  NODES_API
  void iStop( void )
  {
    for ( auto system: _systems )
    {
      if ( system.second != nullptr )
      {
        system.second->stop( );
      }
      delete system.second; // TODO: Because be pointers, my friend ;)
    }

    _systems.clear( );
  }
  std::unordered_map< std::string, System* > _systems;
};
