#ifndef __NODES_IMAGE_EFFECT__
#define __NODES_IMAGE_EFFECT__

#include <nodes/api.h>

namespace nodes
{
  class Camera;
  class ImageEffect
  {
  public:
    NODES_API
    // TODO Renderer?
    virtual void apply( Camera* camera ) = 0;
    NODES_API
    // TODO Renderer?
    virtual void compute( Camera* camera ) = 0;

    bool enabled = true;
  protected:

  };
}

#endif /* __NODES_IMAGE_EFFECT__ */
