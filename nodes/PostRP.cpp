#include "PostRP.hpp"
#include "StandardRP.hpp"
#include "RenderQueue.h"
#include "Renderer.h"

int PostRP::FBOCOUNTER = 0;

PostRP::PostRP( RenderPass* sceneRP )
: _sceneRenderPass ( sceneRP )
{
  _fbo = ++PostRP::FBOCOUNTER;
}

void PostRP::render( Renderer* renderer, RenderQueue* rq, Camera* cam )
{
  renderer->bindFBO( _fbo );
  _sceneRenderPass->render( renderer, rq, cam );
  renderer->unbindFBO( _fbo );

  applyImageEffects( renderer, cam );
}
