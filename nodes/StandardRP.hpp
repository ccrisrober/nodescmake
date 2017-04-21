#ifndef __NODES_STANDARD_RP__
#define __NODES_STANDARD_RP__

#include "RenderPass.hpp"

#include "Renderer.h"
#include "RenderQueue.h"

namespace nodes
{
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
}

#endif /* __NODES_STANDARD_RP__ */
