#include "RenderQueue.h"

RenderQueue::RenderQueue( )
{
  _renderables[ RenderableType::OPAQUE ] = std::vector<Renderable*>( );
  _renderables[ RenderableType::TRANSPARENT ] = std::vector<Renderable*>( );
}

RenderQueue::~RenderQueue( )
{
  reset( );
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
std::vector<Renderable*> RenderQueue::renderables( RenderableType t )
{
  return _renderables[ t ];
}
void RenderQueue::pushGeometry( Geometry* g )
{
  auto mr = g->getComponent< MeshRenderer >( );
  if ( mr == nullptr )
  {
    return;
  }

  Renderable* r = new Renderable( );
  r->material = 1;
  r->geom = g;

  _renderables[ RenderableType::OPAQUE ].push_back( r );
}
void RenderQueue::pushLight( Light * l )
{
  _lights.push_back( l );
}