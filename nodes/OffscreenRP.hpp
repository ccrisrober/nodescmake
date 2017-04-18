#pragma once

#include "RenderPass.hpp"

struct Renderable;

class OffscreenRP: public RenderPass
{
public:
  NODES_API
  OffscreenRP( unsigned int fbo );
  NODES_API
  OffscreenRP( unsigned int fbo, RenderPass* sceneRenderPass );
  NODES_API
  void render( Renderer* renderer, RenderQueue* rq, Camera* c );
  NODES_API
  unsigned int targetFBO( void )
  {
    return _fbo;
  }
  NODES_API
  RenderPass* sceneRenderPass( void )
  {
    return _sceneRenderPass;
  }
protected:
  unsigned int _fbo;
  RenderPass* _sceneRenderPass;
};
