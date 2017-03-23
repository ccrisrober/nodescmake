#include "PickingVisitor.h"
#include "Node.h"
#include "Group.h"

PickingVisitor::PickingVisitor( const Ray& ray,
  Results &results, FilterType filter )
  : _ray( ray )
  , _results( results)
  , _filter( filter )
{
}

PickingVisitor::~PickingVisitor( )
{
}

void PickingVisitor::traverse( Node* n )
{
  _results.reset( );

  NodeVisitor::traverse( n );
  _results.sortCandidates( [ &] ( Node* first, Node* second ) -> bool
  {
    return false;
  } );
}

void PickingVisitor::visitNode( Node* n )
{
  if ( _filter == nullptr || _filter( n ) )
  {
    _results.pushCandidate( n );
  }
}
void PickingVisitor::visitGroup( Group* group )
{
  visitNode( group );
  group->forEachNode( [ &] ( Node* n )
  {
    /*if (n-> )*/
    n->accept( *this );
    /*}*/
  } );
}