#include "SepiaImageEffect.hpp"
#include "scenegraph/Camera.h"

void SepiaToneEffect::compute( Camera* )
{

}

void SepiaToneEffect::apply( Camera* camera )
{
  // bind shader, texture, draw and unbind texture and shader
  std::cout << "Aplicando SepiaToneEffect" << std::endl;
}
