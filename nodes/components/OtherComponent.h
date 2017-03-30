#pragma once

#include "Component.h"
#include <nodes/api.h>

class OtherComponent : public Component
{
  IMPLEMENT_COMPONENT( OtherComponent )
public:
  NODES_API
    OtherComponent( );
  NODES_API
  virtual ~OtherComponent( );
};

