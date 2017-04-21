#ifndef __NODES_SEPIA_EFFECT__
#define __NODES_SEPIA_EFFECT__

#include "ImageEffect.hpp"

namespace nodes
{
  class Camera;

  class SepiaToneEffect :
    public ImageEffect
  {
  public:
    NODES_API
    virtual void compute( Camera* camera ) override;
    NODES_API
    virtual void apply( Camera* camera ) override;
  protected:
    int shader;
  };
}

#endif /* __NODES_SEPIA_EFFECT__ */
