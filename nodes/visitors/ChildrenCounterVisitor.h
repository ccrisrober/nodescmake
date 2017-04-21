#ifndef __NODES_CHILDREN_COUNTER_VISITOR__
#define __NODES_CHILDREN_COUNTER_VISITOR__

#include "Visitor.h"
#include <nodes/api.h>

namespace nodes
{
  class ChildrenCounterVisitor :
    public Visitor
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
}

#endif /* __NODES_CHILDREN_COUNTER_VISITOR__ */
