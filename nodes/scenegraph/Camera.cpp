#include "Camera.h"

#include "../StandardRP.hpp"

Camera* Camera::_mainCamera = nullptr;

Camera::Camera( )
: Camera( new StandardRP( ) )
{
}

Camera::Camera( RenderPass* rp )
: Node( "camera" )
, _renderPass( rp )
{
  for ( unsigned int i = 0; i < 32; ++i )
  {
    this->layer( ).enable( i );
  }
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
