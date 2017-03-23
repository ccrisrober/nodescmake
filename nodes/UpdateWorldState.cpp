#include "UpdateWorldState.h"


UpdateWorldState::UpdateWorldState( )
{
}

UpdateWorldState::~UpdateWorldState( )
{
}

#include "Node.h"
#include "Group.h"

void UpdateWorldState::visitNode( Node *node )
{
  // TODO UPDATE WORLD MODEL
}

void UpdateWorldState::visitGroup( Group *group )
{
  visitNode( group );
  NodeVisitor::visitGroup( group );

  if ( group->hasNodes( ) )
  {
    group->forEachNode( [&] ( Node *node )
    {
      // TODO: COMPUTE WORLD MODEL
    } );
  }
}

