#pragma once

#include "Visitor.h"
#include <vector>
#include <functional>

#include <nodes/api.h>

class FetchLights :
  public Visitor
{
public:
  NODES_API
  FetchLights( );
  NODES_API
  virtual ~FetchLights( );
  NODES_API
  virtual void reset( void ) override;
  NODES_API
  virtual void visitLight( Light* c ) override;
  NODES_API
  bool hasLights( void ) const
  {
    return !_lights.empty( );
  }
  NODES_API
  void forEachLight( std::function<void( Light* )> cb );
protected:
  std::vector<Light*> _lights;
};

