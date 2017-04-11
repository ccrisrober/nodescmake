#pragma once

#include "ImageEffect.hpp"
class Camera;

class SepiaToneEffect :
  public ImageEffect
{
public:
  NODES_API
  virtual void compute( Camera* camera ) override;
  NODES_API
  virtual void apply( Camera* camera ) override;
protected:
  int shader;
};
