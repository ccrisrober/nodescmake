#ifndef __NODES_IMAGE_EFFECT__
#define __NODES_IMAGE_EFFECT__

#include <nodes/api.h>

namespace nodes
{
  class Camera;
  class Renderer;
  class ImageEffect
  {
  public:
    NODES_API
    // TODO Renderer?
    virtual void apply( Renderer* r, Camera* camera ) = 0;
    NODES_API
    // TODO Renderer?
    virtual void compute( Renderer* r, Camera* camera ) = 0;

    bool enabled = true;
  protected:

  };
}

#endif /* __NODES_IMAGE_EFFECT__ */
