#ifndef __NODES_BOX_COLLIDER__
#define __NODES_BOX_COLLIDER__

#include "ICollider.hpp"

namespace nodes
{
  class BoxCollider: public ICollider
  {
    IMPLEMENT_COMPONENT( BoxCollider )
    NODES_API
    BoxCollider( void )
    : ICollider( )
    {
    }
  };
}

#endif /* __NODES_BOX_COLLIDER__ */
