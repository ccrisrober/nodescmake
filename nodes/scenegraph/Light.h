#ifndef __NODES_LIGHT__
#define __NODES_LIGHT__

#include "Node.h"
#include <nodes/api.h>

namespace nodes
{
  class Light :
    public Node
  {
  public:
    NODES_API
      Light( void );
    NODES_API
    ~Light( void );

  public:
    NODES_API
    virtual void accept( Visitor& v ) override;
  };
}

#endif /* __NODES_LIGHT__ */
