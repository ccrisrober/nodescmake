#include <iostream>

#include <nodes/nodes.h>

int main( )
{
  Node n("fooNode");
  n.addComponent( new OtherComponent( ) );

  bool exist = n.hasComponent<CustomComponent>( );
  auto comp = n.getComponent<CustomComponent>( );
  n.addComponent( new CustomComponent( ) );
  exist = n.hasComponent<CustomComponent>( );
  comp = n.getComponent<CustomComponent>( );
  return 0;
}
