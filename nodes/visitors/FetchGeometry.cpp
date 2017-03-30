#include "FetchGeometry.h"
#include "../scenegraph/Node.h"
#include "../scenegraph/Group.h"
#include "../components//MeshRenderer.h"


FetchGeometry::FetchGeometry( int c )
: Visitor( )
, camera( c )
{
}

FetchGeometry::~FetchGeometry( )
{
}

void FetchGeometry::visitNode( Node* n )
{
  auto comp = n->getComponent<MeshRenderer>( );
  if ( comp != nullptr )
  {
    MeshRenderer *mr = static_cast< MeshRenderer* >( comp );
    std::cout << "Has geometry" << std::endl;
    if ( mr->vao % camera == 0 )
    {
      rq.pushGeometry( mr );
    }
  }
}

void FetchGeometry::visitGroup( Group *group )
{
  // No ejecutamos culling de la cámara
  //  sobre los grupos porque los hijos pueden
  //  tener nodos útiles (?)
  Visitor::visitGroup( group );
}

void FetchGeometry::traverse( Node* node )
{
  rq.reset( );
  Visitor::traverse( node );
}
