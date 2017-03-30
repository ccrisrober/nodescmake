#pragma once
#include <functional>
#include "Visitor.h"
#include <nodes/api.h>
class LambdaVisitor :
  public Visitor
{
private:
  typedef std::function<void( Node* )> CallbackType;
public:
  NODES_API
    LambdaVisitor( CallbackType cb );
  NODES_API
    virtual ~LambdaVisitor( );
  NODES_API
    virtual void visitNode( Node* n ) override;
  NODES_API
  virtual void visitGroup( Group* g ) override;
private:
  CallbackType _callback;
};

