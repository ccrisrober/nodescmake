#include <iostream>

#include <nodes/nodes.h>
using namespace nodes;

int main( )
{
  auto scene = new Group( "scene" );

  auto offScreenView = new Group( "Offscreen" );
  scene->addChild( offScreenView );

  auto offScreenCamera = new Camera( );
  offScreenCamera->name( "OFFCamera" );
  offScreenCamera->renderPass( new OffscreenRP( 1 ) );
  offScreenView->addChild( offScreenCamera );

  auto offGeom = new Geometry( "offGeom" );
  offGeom->addPrimitive( new Primitive( "OffPrimitive" ) );
  offGeom->layer( ).set( 2 );
  offScreenView->addChild( offGeom );


  auto geom = new Geometry( "nodeGeom" );
  geom->addPrimitive( new Primitive( "FirstPrimitive" ) );
  scene->addChild( geom );
  geom->layer( ).set( 2 );

  auto camera = new Camera( );
  camera->name( "PPCamera" );
  Camera::mainCamera( camera );
  scene->addChild( camera );

  camera->layer( ).enable( 1 );
  camera->layer( ).enable( 2 );
  camera->layer( ).enable( 3 );

  nodes::DumpVisitor dv;
  dv.traverse( scene );

  App app;
  app.setSceneNode( scene );
  app.run( );

  /*std::cout << std::endl << std::endl << std::endl;

  geom->layer( ).set( 4 );
  e.run( );*/
  delete scene;
  system( "PAUSE" );
  return 0;
}
