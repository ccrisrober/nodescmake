#pragma once

#include "RenderPass.hpp"

#include "Renderer.h"
#include "RenderQueue.h"

class StandardRP: public RenderPass
{
public:
  NODES_API
  void render( Renderer* renderer, RenderQueue* rq, Camera* c );

protected:
  void renderOpaqueObjects( Renderer* renderer, RenderQueue* rq,
    Camera* c );
  void renderTransparentObjects( Renderer* renderer,
    RenderQueue* rq, Camera* c );
  void renderStandardGeometry( Renderer* renderer, Renderable* renderable );
};
