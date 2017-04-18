#pragma once
#include "Visitor.h"
#include "../RenderQueue.h"
#include <nodes/api.h>

class Group;
class Geometry;
class Light;

class FetchGeometry :
  public Visitor
{
public:
  NODES_API
  FetchGeometry( Camera* cam, RenderQueue *rq );
  NODES_API
  virtual ~FetchGeometry( );
  NODES_API
  virtual void traverse( Node* n ) override;
  //NODES_API
  //virtual void visitNode( Node* n ) override;
  NODES_API
  virtual void visitGroup( Group* g ) override;
  NODES_API
  virtual void visitGeometry( Geometry* n ) override;
  NODES_API
  virtual void visitLight( Light* l ) override;
protected:
  Camera* camera;
  RenderQueue* rq;
};

/* TODO
if ( camera->layer( ).check( geometry->layer( ) ) )
{
rq->pushGeometry( geometry );
}
*/