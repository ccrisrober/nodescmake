#ifndef __NODES_NODES_POST_RP__
#define __NODES_NODES_POST_RP__

#include "RenderPass.hpp"

namespace nodes
{
  struct Renderable;
  class Renderer;
  class RenderQueue;

  class PostRP: public RenderPass
  {
  public:
    NODES_API
    PostRP( RenderPass* sceneRP );
    NODES_API
    void render( Renderer* renderer, RenderQueue* rq, Camera* c );
  protected:
    RenderPass *_sceneRenderPass;

    int _fbo;

    // HARDCODED
    static int FBOCOUNTER;
  };
}

#endif /* __NODES_POST_RP__ */
