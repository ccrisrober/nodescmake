#pragma once
#include "NodeVisitor.h"
#include <nodes/api.h>
class ChildrenCounterVisitor :
  public NodeVisitor
{
public:
  NODES_API
  ChildrenCounterVisitor( );
  NODES_API
  virtual ~ChildrenCounterVisitor( );
  NODES_API
  virtual void reset( ) override;
  NODES_API
  virtual void traverse( Node* n ) override;
  NODES_API
  virtual void visitNode( Node* n ) override;
  NODES_API
  virtual void visitGroup( Group* g ) override;

//protected:
  unsigned int _childrens;
};

