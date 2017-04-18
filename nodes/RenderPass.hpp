#pragma once

#include <vector>
#include "RenderQueue.h"
#include "ImageEffect.hpp"

class Camera;
class Renderer;

class RenderPass
{
public:
  //NODES_API
  virtual void render( Renderer* renderer, RenderQueue* rq, Camera* c ) = 0;
  NODES_API
  virtual void applyImageEffects( Renderer *renderer, Camera *camera );
  NODES_API
  std::vector<ImageEffect*>& imageEffects( void )
  {
    return _imageEffects;
  }
protected:
  std::vector< ImageEffect *> _imageEffects;

private:
  void swapBuffers( Renderer* r );
};
