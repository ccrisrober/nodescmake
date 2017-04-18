#pragma once

#include "ICollider.hpp"

class BoxCollider: public ICollider
{
  IMPLEMENT_COMPONENT( BoxCollider )
  NODES_API
  BoxCollider( void )
  : ICollider( )
  {
  }
};
