#ifndef __NODES_MESH_COLLIDER__
#define __NODES_MESH_COLLIDER__

#include "ICollider.hpp"

namespace nodes
{
  class MeshCollider: public ICollider
  {
    IMPLEMENT_COMPONENT( MeshCollider )
    NODES_API
    MeshCollider( void )
    : ICollider( )
    {
    }
  };
}

#endif /* __NODES_MESH_COLLIDER__ */
