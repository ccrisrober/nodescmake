#pragma once

#include "Component.h"
#include <nodes/api.h>

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

