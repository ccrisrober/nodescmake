#ifndef __NODES_BOX_COLLIDER__
#define __NODES_BOX_COLLIDER__

#include "Collider.hpp"

namespace nodes
{
  class BoxCollider: public Collider
  {
    IMPLEMENT_COMPONENT( BoxCollider )
    NODES_API
    BoxCollider( void )
    : Collider( )
    {
    }
  };
}

#endif /* __NODES_BOX_COLLIDER__ */
