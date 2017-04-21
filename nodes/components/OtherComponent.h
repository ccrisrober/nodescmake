#ifndef __NODES_ORBIT_CAMERA__
#define __NODES_ORBIT_CAMERA__

#include "Component.h"
#include <nodes/api.h>

namespace nodes
{
  class OtherComponent : public Component
  {
    IMPLEMENT_COMPONENT( OtherComponent )
  public:
    NODES_API
      OtherComponent( );
    NODES_API
    virtual ~OtherComponent( );
  };
}

#endif /* __NODES_ORBIT_CAMERA__ */
