#ifndef __NODES_UPDATE_COMPONENTS__
#define __NODES_UPDATE_COMPONENTS__

#include "LambdaVisitor.h"
#include <nodes/api.h>

namespace nodes
{
  class UpdateComponents :
    public LambdaVisitor
  {
  public:
    // TODO: USE CLOCK
    NODES_API
    UpdateComponents( const float& dt );
    NODES_API
    virtual ~UpdateComponents( );
  };
}

#endif /* __NODES_UPDATE_COMPONENTS__ */
