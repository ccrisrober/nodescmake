#pragma once

#include <vector>
#include "components/MeshRenderer.h"

class Camera;

#include <nodes/api.h>

class RenderQueue
{
public:
  enum class RenderableType
  {
    OPAQUE,
    TRANSPARENT
  };
  NODES_API
    RenderQueue( );
  NODES_API
  virtual ~RenderQueue( );
  /*void sortGeometry( std::function<bool( int, int )> cb )
  {
    std::sort( _queue.begin( ), _queue.end( ), cb );
  }*/
  NODES_API
  void pushGeometry( MeshRenderer* mr )
  {
    _queue.push_back( mr );
  }
  NODES_API
  unsigned int size( ) const
  {
    return _queue.size( );
  }
  NODES_API
  void reset( )
  {
    _queue.clear( );
  }
  NODES_API
  void camera( Camera* c )
  {
    _camera = c;
  }
  NODES_API
  Camera* camera( )
  {
    return _camera;
  }
protected:
  std::vector< MeshRenderer* > _queue;
  Camera* _camera;
};

