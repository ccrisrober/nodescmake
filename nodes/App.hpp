#ifndef __NODES_APP__
#define __NODES_APP__

#include <nodes/api.h>
#include "scenegraph/Node.h"
#include "scenegraph/Camera.h"
#include "Clock.hpp"

#include <unordered_map>

#include "systems/System.h"

#include "Renderer.h"

namespace nodes
{
  class App
  {
  public:
    NODES_API
    App( void );
    NODES_API
    virtual ~App( void );
    NODES_API
    void setSceneNode( Node* node );
    NODES_API
    virtual int run( void );

    virtual void start( void );
    virtual bool update( void );
    virtual void stop( void );

    System* system( const std::string& name )
    {
      return _systems[ name ];
    }
  protected:
    void startSystems( void )
    {
      std::cout << "Starting systems" << std::endl;
      for ( auto& sys : _systems )
      {
        if ( sys.second != nullptr )
        {
          sys.second->start( );
        }
      }
    }
    void stopSystems( void )
    {
      std::cout << "Stopping systems" << std::endl;
      for ( auto& sys : _systems )
      {
        if ( sys.second != nullptr )
        {
          sys.second->stop( );
        }
      }
    }
    void addSystem( System* sys )
    {
      // TODO: Check if exist
      _systems[ sys->name( ) ] = sys;
    }
    void forEachCamera( std::function< void( Camera * ) > callback )
    {
      for ( auto camera : _cameras )
      {
        callback( camera );
      }
    }
  protected:
    Clock _simulationClock;
    Node* _scene;
    Renderer *_renderer;
    std::vector<Camera*> _cameras;

    std::unordered_map< std::string, System*> _systems;
  };
}

#endif /* __NODES_APP__ */
