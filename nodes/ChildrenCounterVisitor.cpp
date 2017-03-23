#include "ChildrenCounterVisitor.h"
#include "Node.h"
#include "Group.h"

ChildrenCounterVisitor::ChildrenCounterVisitor( )
: NodeVisitor( )
, _childrens( 0 )
{
}

ChildrenCounterVisitor::~ChildrenCounterVisitor( )
{
}

void ChildrenCounterVisitor::reset( )
{
  _childrens = 0;
  NodeVisitor::reset( );
}

void ChildrenCounterVisitor::traverse( Node* n )
{
  this->reset( );
  NodeVisitor::traverse( n );
  --_childrens; // TODO: WHYY??? Remove myself
}
#include <iostream>
#include <string>
void ChildrenCounterVisitor::visitNode( Node* n )
{
  ++_childrens;
  std::cout << n->name( ) << std::endl;
}

void ChildrenCounterVisitor::visitGroup( Group* group )
{
  visitNode( group );
  NodeVisitor::visitGroup( group );
}