#include "Visitor.h"

#include "../scenegraph/Node.h"
#include "../scenegraph/Geometry.h"
#include "../scenegraph/Group.h"
#include "../scenegraph/Camera.h"
#include "../scenegraph/Light.h"

namespace nodes
{
  Visitor::~Visitor( )
  {
  }

  Visitor::Visitor( const Visitor& )
  {
  }

  Visitor &Visitor::operator= ( const Visitor& )
  {
    return *this;
  }

  void Visitor::reset( void )
  {
  }

  void Visitor::traverse( Node *n )
  {
    reset( );
    n->accept( *this );
  }

  void Visitor::visitNode( Node *node )
  {
    // do nothing
  }

  void Visitor::visitGroup( Group* group )
  {
    group->forEachNode( [&] ( Node* n ) {
      n->accept( *this );
    } );
  }

  void Visitor::visitCamera( Camera *camera )
  {
    visitNode( camera );
  }

  void Visitor::visitLight( Light* light )
  {
    visitNode( light );
  }

  void Visitor::visitGeometry( Geometry *geometry )
  {
    visitNode( geometry );
  }
}
