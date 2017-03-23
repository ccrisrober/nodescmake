#include "FetchGeometry.h"
#include "Node.h"
#include "Group.h"
#include "MeshRenderer.h"


FetchGeometry::FetchGeometry( int c )
: NodeVisitor( )
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
  NodeVisitor::visitGroup( group );
}

void FetchGeometry::traverse( Node* node )
{
  rq.reset( );
  NodeVisitor::traverse( node );
}