#include <iostream>

#include <nodes/nodes.h>

int main( )
{
  auto scene = new Group( "scene" );

  auto offscreenCamera = new Camera( );
  offscreenCamera->name( "offscreen camera" );
  offscreenCamera->renderPass( new RenderPass( ) );
  offscreenCamera->renderPass( )->_imageEffects.push_back( new SepiaToneEffect( ) );
  scene->addChild( offscreenCamera );

  auto geom = new Node( "nodeGeom" );
  geom->addComponent( new MeshRenderer( 1 ) );
  scene->addChild( geom );

  auto camera = new Camera( );
  camera->name( "sampleCamera" );
  Camera::mainCamera( camera );
  scene->addChild( camera );

  Engine e;
  e.setScene( scene );
  e.run( );
  delete scene;
  system( "PAUSE" );
  return 0;
}
