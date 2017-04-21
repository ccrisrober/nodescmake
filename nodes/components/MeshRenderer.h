#ifndef __NODES_MESH_RENDERER__
#define __NODES_MESH_RENDERER__

#include "Component.h"
#include <nodes/api.h>

namespace nodes
{
  class MeshRenderer :
    public Component
  {
    IMPLEMENT_COMPONENT( MeshRenderer )
  public:
    NODES_API
      MeshRenderer( int vao );
    NODES_API
    virtual ~MeshRenderer( );
  public:
    int vao;
  };
}

#endif /* __NODES_MESH_RENDERER__ */
