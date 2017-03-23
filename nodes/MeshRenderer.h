#pragma once
#include "Component.h"
#include <nodes/api.h>
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

