#pragma once

#include "RenderPass.hpp"

struct Renderable;

class StandardRP: public RenderPass
{
public:
  void render( Renderer* renderer, RenderQueue* rq, Camera* c );

protected:
  void renderOpaqueObjects( Renderer* renderer, RenderQueue* rq,
    Camera* c );
  void renderTransparentObjects( Renderer* renderer,
    RenderQueue* rq, Camera* c );
  void renderStandardGeometry( Renderer* renderer, Renderable* renderable );
};
