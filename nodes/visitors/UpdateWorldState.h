#pragma once
#include "Visitor.h"
#include <nodes/api.h>
class UpdateWorldState :
  public Visitor
{
public:
  NODES_API
  UpdateWorldState( );
  NODES_API
  virtual ~UpdateWorldState( );
  NODES_API
  virtual void visitNode( Node *node ) override;
  NODES_API
  virtual void visitGroup( Group *node ) override;
};

