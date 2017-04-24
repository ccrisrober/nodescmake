#ifndef __NODES_BLUR_IMAGE_EFFECT__
#define __NODES_BLUR_IMAGE_EFFECT__

#include "ImageEffect.hpp"

namespace nodes
{
  class Camera;

  class BlurToneEffect :
    public ImageEffect
  {
  public:
    NODES_API
    virtual void compute( Renderer*, Camera* camera ) override;
    NODES_API
    virtual void apply( Renderer*, Camera* camera ) override;
  protected:
    int shader;
  };
}

#include "BlurToneEffect.hpp"
#include "scenegraph/Camera.h"
#include "Renderer.h"

namespace nodes
{

}

#endif /* __NODES_BLUR_IMAGE_EFFECT__ */
