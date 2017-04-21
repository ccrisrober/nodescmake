#ifndef __NODES_UPDATE_WORLD_STATE__
#define __NODES_UPDATE_WORLD_STATE__

#include "Visitor.h"
#include <nodes/api.h>

namespace nodes
{
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
}

#endif /* __NODES_UPDATE_WORLD_STATE__ */
