#pragma once
#include "NodeVisitor.h"
#include "RenderQueue.h"
#include <nodes/api.h>
class FetchGeometry :
  public NodeVisitor
{
public:
  NODES_API
  FetchGeometry( int camera );
  NODES_API
  virtual ~FetchGeometry( );
  NODES_API
  virtual void traverse( Node* n ) override;
  NODES_API
  virtual void visitNode( Node* n ) override;
  NODES_API
  virtual void visitGroup( Group* g ) override;
  RenderQueue rq;
protected:
  int camera;
};

