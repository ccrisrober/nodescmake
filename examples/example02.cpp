#include <iostream>

#include <nodes/nodes.h>

int main( )
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
  std::cout << fv2.rq.size( ) << std::endl;*/

  ChildrenCounterVisitor ccv;
  ccv.traverse( scene );
  std::cout << ccv._childrens << std::endl;



  /*centerSwitch->currentNodeIndex( 0 );

  ChildrenCounterVisitor ccv2;
  ccv2.traverse( scene );
  std::cout << ccv2._childrens << std::endl;*/
  delete scene;
}
