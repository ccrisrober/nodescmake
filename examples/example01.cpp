#include <iostream>

#include <nodes/nodes.h>

int main( )
{
  auto scene = new Group( "scene" );

  auto geom = new Geometry( "geom" );
  geom->addPrimitive( new Primitive( "cube" ) );
  scene->addChild( geom );

  auto interactiveLight = new Group( "InteractiveLight" );
  auto lightGeometry = new Geometry( "LightGeometry" );
  lightGeometry->addPrimitive( new Primitive( "sphere" ) );
  auto light = new Light( );
  interactiveLight->addChild( lightGeometry );
  interactiveLight->addChild( light );

  scene->addChild( interactiveLight );

  auto cam = new Camera( );
  Camera::mainCamera( cam );
  scene->addChild( cam );

  Engine e;
  e.setScene( scene );
  e.run( );
  delete scene;

  system( "PAUSE" );
  return 0;
}
