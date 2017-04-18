#include "SepiaImageEffect.hpp"
#include "scenegraph/Camera.h"

void SepiaToneEffect::compute( Camera* )
{

}

void SepiaToneEffect::apply( Camera* camera )
{
  // bind shader, texture, draw and unbind texture and shader
  //std::cout << "Apply SepiaToneEffect" << std::endl;
  std::cout << "Bind program (SepiaToneEffect)" << std::endl;
  std::cout << "\tBind texture" << std::endl;
  std::cout << "\tDraw ScreenQuad" << std::endl;
  std::cout << "\tUnbind texture" << std::endl;
  std::cout << "Unbind program (SepiaToneEffect)" << std::endl;
}
