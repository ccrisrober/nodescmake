#include "ApplyVisitor.h"
#include "Node.h"
#include "Group.h"

ApplyVisitor::ApplyVisitor( CallbackType cb )
: _callback(cb )
{
}

ApplyVisitor::~ApplyVisitor( )
{
}

void ApplyVisitor::visitNode( Node* n )
{
  _callback( n );
}

void ApplyVisitor::visitGroup( Group *group )
{
  _callback( group );
  NodeVisitor::visitGroup( group );
}

