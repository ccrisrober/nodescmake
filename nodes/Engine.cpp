#include "Engine.h"

Engine::Engine( )
{
  renderer = new OpenGLRenderer( );
}
void Engine::setScene( Group *g )
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
void Engine::start( void )
{
}
bool Engine::update( void )
{
  std::cout << "Engine will update" << std::endl;
  std::cout << "~~~~~~~~~~ BEGIN UPDATE ~~~~~~~~~~" << std::endl;
  // UPDATE STEP
  // TODO: Fixed update
  scene->perform( UpdateWorldState( ) );

  std::vector<RenderQueue*> rqCollection;

  forEachCamera( [ &] ( Camera *c )
  {
    if ( c != nullptr )
    {
      RenderQueue* rq = new RenderQueue( );
      FetchGeometry fg( c, rq );
      scene->perform( fg );
      rqCollection.push_back( rq );
    }
  } );
  // \\ UPDATE STEP
  std::cout << "~~~~~~~~~~~ END UPDATE ~~~~~~~~~~~" << std::endl;

  // RENDER STEP
  // TODO
  std::cout << "~~~~~~~~~~ BEGIN RENDER ~~~~~~~~~~" << std::endl;
  renderer->beginRender( );
  renderer->clearBuffers( );
  std::cout << "~~~~~~~~~~ RENDER SCENE ~~~~~~~~~~" << std::endl;
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
        renderer->render( rq, rq->camera( )->renderPass( ) );
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
      renderer->render( mainQueue, mainQueue->camera( )->renderPass( ) );
    }
  }
  std::cout << "~~~~~~~~~~~ END RENDER ~~~~~~~~~~~" << std::endl;
  renderer->endRender( );
  // \\ RENDER STEP
  std::cout << "Engine did update" << std::endl;

  return false;
}
int Engine::run( void )
{
  start( );
  bool done = false;
  while ( !done )
  {
    done = !update( );
  }
  return 0;
}
void Engine::forEachCamera( std::function< void( Camera * ) > callback )
{
  for ( auto camera : _cameras )
  {
    callback( camera );
  }
}
void Engine::iAddSystem( System* ss )
{
  _systems.insert( std::make_pair( ss->name( ), ss ) );
}
void Engine::iStart( void )
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
void Engine::iUpdate( void )
{

}
void Engine::iStop( void )
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
