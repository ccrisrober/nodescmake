#ifndef __NODES_DUMP_VISITOR__
#define __NODES_DUMP_VISITOR__

#include "Visitor.h"
#include <string>

#include <nodes/api.h>

namespace nodes
{
  class DumpVisitor :
    public Visitor
  {
  public:
    NODES_API
    DumpVisitor( );
    NODES_API
    virtual ~DumpVisitor( );

    NODES_API
    virtual void traverse( Node *node ) override;

    NODES_API
    virtual void visitNode( Node *node ) override;
    NODES_API
    virtual void visitGroup( Group *group ) override;
    NODES_API
    virtual void visitGeometry( Geometry *geometry ) override;
    NODES_API
    virtual void visitCamera( Camera *camera ) override;
    NODES_API
    virtual void visitLight( Light *light ) override;
  private:
    void _dumpNode( Node *node, const std::string& type );
    int _auxLevel = 0;
  };
}

#endif /* __NODESDUMP_VISITOR__ */
