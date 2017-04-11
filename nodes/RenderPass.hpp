#pragma once

class Renderer;
class RenderQueue;
#include "ImageEffect.hpp"

#include <vector>

class Camera;

class RenderPass
{
public:
  void render( Renderer* renderer, RenderQueue* rq, Camera* c );
  std::vector< ImageEffect *> _imageEffects;
};
