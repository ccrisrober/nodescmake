#include "GreyImageEffect.hpp"
#include "scenegraph/Camera.h"

void GreyToneEffect::compute( Camera* )
{

}

void GreyToneEffect::apply( Camera* camera )
{
  // bind shader, texture, draw and unbind texture and shader
  //std::cout << "Aplicando GreyToneEffect" << std::endl;
  std::cout << "Bind program (GreyToneEffect)" << std::endl;
  std::cout << "\tBind texture" << std::endl;
  std::cout << "\tDraw ScreenQuad" << std::endl;
  std::cout << "\tUnbind texture" << std::endl;
  std::cout << "Unbind program (GreyToneEffect)" << std::endl;
}
