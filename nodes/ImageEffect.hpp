#pragma once

class Camera;

#include <nodes/api.h>

class ImageEffect
{
public:
  NODES_API
  // TODO Renderer?
  virtual void apply( Camera* camera ) = 0;
  NODES_API
  // TODO Renderer?
  virtual void compute( Camera* camera ) = 0;

  bool enabled = true;
protected:

};
