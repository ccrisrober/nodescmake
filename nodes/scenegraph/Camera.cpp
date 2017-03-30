#include "Camera.h"

Camera* Camera::_mainCamera = nullptr;

Camera::Camera( )
: Node( "camera" )
{
}

Camera::~Camera( )
{
}

void Camera::accept( Visitor& v )
{
  v.visitCamera( this );
}

void SepiaToneEffect::compute( Camera* )
{

}

void SepiaToneEffect::apply( Camera* camera )
{
  // bind shader, texture, draw and unbind texture and shader
  std::cout << "Aplicando SepiaToneEffect" << std::endl;
}
