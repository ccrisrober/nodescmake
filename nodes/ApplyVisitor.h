#pragma once
#include <functional>
#include "NodeVisitor.h"
#include <nodes/api.h>
class ApplyVisitor :
  public NodeVisitor
{
private:
  typedef std::function<void( Node* )> CallbackType;
public:
  NODES_API
    ApplyVisitor( CallbackType cb );
  NODES_API
    virtual ~ApplyVisitor( );
  NODES_API
    virtual void visitNode( Node* n ) override;
  NODES_API
  virtual void visitGroup( Group* g ) override;
private:
  CallbackType _callback;
};

