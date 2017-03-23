#include <iostream>

#include "Node.h"
#include "Group.h"
#include "Switch.h"
#include "Camera.h"
#include "CustomComponent.h"
#include "OtherComponent.h"
#include "PrintNameVisitor.h"
#include "FetchGeometry.h"
#include "MeshRenderer.h"
#include "ChildrenCounterVisitor.h"

void example01( )
{
  Node n("fooNode");
  n.addComponent( new OtherComponent( ) );

  bool exist = n.hasComponent<CustomComponent>( );
  auto comp = n.getComponent<CustomComponent>( );
  n.addComponent( new CustomComponent( ) );
  exist = n.hasComponent<CustomComponent>( );
  comp = n.getComponent<CustomComponent>( );
}

void example02( )
{
  auto scene = new Group( "scene" );
  auto leftNode = new Node( "leftNode" );
  auto centerSwitch = new Switch( "centerSwitch" );
  auto rightNode = new Node( "rightNode" );

  scene->addChild( leftNode );
  scene->addChild( centerSwitch );
  scene->addChild( rightNode );

  auto firstNodeSwitch = new Node( "firstNodeSwitch" );
  auto secondNodeSwitch = new Group( "secondNodeSwitch" );
  secondNodeSwitch->addChild( new Node( "firstSecondNodeSwitch" ) );
  auto thirdNodeSwitch = new Node( "thirdNodeSwitch" );

  centerSwitch->addChild( firstNodeSwitch );
  centerSwitch->addChild( secondNodeSwitch );
  centerSwitch->addChild( thirdNodeSwitch );

  leftNode->addComponent( new MeshRenderer( 3 ) );
  secondNodeSwitch->addComponent( new MeshRenderer( 12 ) );
  //rightNode->addComponent( new MeshRenderer( 2 ) );

  centerSwitch->currentNodeIndex( 1 );

  /*PrintNameVisitor v;
  v.visitGroup( scene );

  FetchGeometry fv( 2 );
  fv.traverse( scene );
  std::cout << fv.rq.size( ) << std::endl;
  FetchGeometry fv2( 3 );
  fv2.traverse( scene );
  std::cout << fv2.rq.size( ) << std::endl;

  ChildrenCounterVisitor ccv;
  ccv.traverse( scene );
  std::cout << ccv._childrens << std::endl;



  centerSwitch->currentNodeIndex( 0 );

  ChildrenCounterVisitor ccv2;
  ccv2.traverse( scene );
  std::cout << ccv2._childrens << std::endl;*/
  delete scene;
}

#include "Engine.h"


void example03( )
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
}

void example04( )
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
}

int main( )
{
  example04( );

  system( "PAUSE" );
  return 0;
}

// TODO: PIPELINE CLASS ??
// TODO: DESTROY ALL TREE NODES
