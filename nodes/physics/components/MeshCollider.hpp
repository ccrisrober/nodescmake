#ifndef __NODES_MESH_COLLIDER__
#define __NODES_MESH_COLLIDER__

#include "Collider.hpp"

namespace nodes
{
  class MeshCollider: public Collider
  {
    IMPLEMENT_COMPONENT( MeshCollider )
    NODES_API
    MeshCollider( void )
    : Collider( )
    {
    }
  };
}

#endif /* __NODES_MESH_COLLIDER__ */
