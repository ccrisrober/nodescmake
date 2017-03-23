#include "NodeVisitor.h"

#include "Node.h"
#include "Group.h"
#include "Camera.h"

NodeVisitor::NodeVisitor( )
{
}

NodeVisitor::~NodeVisitor( )
{
}

NodeVisitor::NodeVisitor( const NodeVisitor& ) {
}
NodeVisitor &NodeVisitor::operator= ( const NodeVisitor& )
{
  return *this;
}

void NodeVisitor::reset( void )
{

}

void NodeVisitor::traverse( Node *n )
{
  reset( );
  n->accept( *this );
}

void NodeVisitor::visitNode( Node *node )
{
  // do nothing
}

void NodeVisitor::visitGroup( Group* group )
{
  group->forEachNode( [&] ( Node* n ) {
    n->accept( *this );
  } );
}

void NodeVisitor::visitCamera( Camera *camera )
{
  visitNode( camera );
}