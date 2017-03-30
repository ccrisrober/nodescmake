#include "ChildrenCounterVisitor.h"
#include "../scenegraph/Node.h"
#include "../scenegraph/Group.h"

ChildrenCounterVisitor::ChildrenCounterVisitor( )
: Visitor( )
, _childrens( 0 )
{
}

ChildrenCounterVisitor::~ChildrenCounterVisitor( )
{
}

void ChildrenCounterVisitor::reset( )
{
  _childrens = 0;
  Visitor::reset( );
}

void ChildrenCounterVisitor::traverse( Node* n )
{
  this->reset( );
  Visitor::traverse( n );
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
  Visitor::visitGroup( group );
}
