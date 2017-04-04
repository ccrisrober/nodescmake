#include <iostream>

#include <nodes/nodes.h>

int main( )
{
  auto scene = new Group( "scene" );
  auto geom = new Node( "nodeGeom" );
  geom->addComponent( new MeshRenderer( 1 ) );
  scene->addChild( geom );

  auto camera = new Camera( );
  camera->name( "customCam" );
  camera->renderPass( new RenderPass( ) );
  camera->renderPass( )->_imageEffects.push_back( new SepiaToneEffect() );

  scene->addChild( camera );

  Engine e;
  e.setScene( scene );
  e.run( );
  delete scene;
  system( "PAUSE" );
  return 0;
}
