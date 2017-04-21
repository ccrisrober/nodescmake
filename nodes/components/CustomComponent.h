#ifndef __NODES_CUSTOM_COMPONENT__
#define __NODES_CUSTOM_COMPONENT__

#include "Component.h"
#include <nodes/api.h>

namespace nodes
{
  class CustomComponent : public Component
  {
    IMPLEMENT_COMPONENT( CustomComponent )
  public:
    NODES_API
    CustomComponent( );
    NODES_API
    virtual ~CustomComponent( );
    int v;
  };
}

#endif /* __NODES_CUSTOM_COMPONENT__ */
