#include "RenderQueue.h"


RenderQueue::RenderQueue( )
{
  _renderables[ RenderableType::OPAQUE ] = std::vector<Renderable*>( );
  _renderables[ RenderableType::TRANSPARENT ] = std::vector<Renderable*>( );
}

RenderQueue::~RenderQueue( )
{
}

void RenderQueue::reset( )
{
  setCamera( nullptr );
  _lights.clear( );
  for ( auto &it : _renderables )
  {
    it.second.clear( );
  }
  _renderables.clear( );
}
void RenderQueue::setCamera( Camera* c )
{
  _camera = c;
}
Camera* RenderQueue::camera( )
{
  return _camera;
}