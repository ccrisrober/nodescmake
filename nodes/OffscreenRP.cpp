#include "OffscreenRP.hpp"
#include "StandardRP.hpp"
#include "RenderQueue.h"

OffscreenRP::OffscreenRP( unsigned int fbo )
: OffscreenRP( fbo, new StandardRP( ) )
{
}

OffscreenRP::OffscreenRP( unsigned int fbo, RenderPass* sceneRenderPass )
: _fbo( fbo )
, _sceneRenderPass( sceneRenderPass )
{
}

void OffscreenRP::render( Renderer* renderer, RenderQueue* rq, Camera* cam )
{
  std::cout << "Bind FBO" << std::endl;
  //renderer->bindFBO( targetFBO );
  _sceneRenderPass->render( renderer, rq, cam );
  //renderer->unbindFBO( );
  std::cout << "Unbind FBO" << std::endl;
  applyImageEffects( renderer, cam );
}
