#include "FetchGeometry.h"
#include "../scenegraph/Camera.h"
#include "../scenegraph/Group.h"
#include "../scenegraph/Geometry.h"
#include "../scenegraph/Light.h"

namespace nodes
{
  FetchGeometry::FetchGeometry( Camera* c, RenderQueue *rq_ )
  : Visitor( )
  , camera( c )
  , rq(rq_)
  {
  }

  FetchGeometry::~FetchGeometry( )
  {
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
    rq->reset( );
    rq->setCamera( camera );
    // TODO: COMPUTE CULLING
    Visitor::traverse( node );
  }

  void FetchGeometry::visitGeometry( Geometry *geometry )
  {
    // TODO: Culled camera layer and frustum culling

    if ( camera->layer( ).check( geometry->layer( ) ) )
    {
      rq->pushGeometry( geometry );
    }
    //rq->pushGeometry( geometry );
  }

  void FetchGeometry::visitLight( Light *light )
  {
    rq->pushLight( light );
  }
}
