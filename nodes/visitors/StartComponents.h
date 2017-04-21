#ifndef __NODES_START_COMPONENTS__
#define __NODES_START_COMPONENTS__

#include "LambdaVisitor.h"
#include <nodes/api.h>

namespace nodes
{
  class StartComponents :
    public LambdaVisitor
  {
  public:
    NODES_API
    StartComponents( );
    NODES_API
    virtual ~StartComponents( );
  };
}

#endif /* __NODES_START_COMPONENTS__ */
