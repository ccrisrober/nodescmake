#ifndef __NODES_RENDER_PASS__
#define __NODES_RENDER_PASS__

#include <vector>
#include "RenderQueue.h"
#include "ImageEffect.hpp"

namespace nodes
{
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
}

#endif /* __NODES_RENDER_PASS__ */
