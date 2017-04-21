#ifndef __NODES_PRINT_NAME_VISITOR__
#define __NODES_PRINT_NAME_VISITOR__

#include "LambdaVisitor.h"
#include <nodes/api.h>

namespace nodes
{
  class PrintNameVisitor :
    public LambdaVisitor
  {
  public:
    NODES_API
    PrintNameVisitor( );
    NODES_API
    virtual ~PrintNameVisitor( );
  };
}

#endif /* __NODES_PRINT_NAME_VISITOR__ */
