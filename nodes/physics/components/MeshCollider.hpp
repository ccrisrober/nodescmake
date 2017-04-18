#pragma once

#include "ICollider.hpp"

class MeshCollider: public ICollider
{
  IMPLEMENT_COMPONENT( MeshCollider )
  NODES_API
  MeshCollider( void )
  : ICollider( )
  {
  }
};
