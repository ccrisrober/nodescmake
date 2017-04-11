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

void Camera::renderPass( RenderPass* rp )
{
  _renderPass = rp;
}
RenderPass* Camera::renderPass( )
{
  return _renderPass;
}
