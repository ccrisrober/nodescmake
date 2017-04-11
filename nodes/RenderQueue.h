#pragma once

#include <vector>
#include <unordered_map>
#include "components/MeshRenderer.h"

class Camera;
#include "scenegraph/Light.h"
#include "scenegraph/Geometry.h"

#include <nodes/api.h>

struct Renderable
{
  unsigned int material;
  Geometry* geom;
};

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
    std::vector<Renderable*> renderables( RenderableType t )
  {
      return _renderables[ t ];
    }
  NODES_API
  void pushGeometry( Geometry* g )
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
  void pushLight( Light * l )
  {
    _lights.push_back( l );
  }
  NODES_API
  void reset( );
  NODES_API
  void setCamera( Camera* c );
  NODES_API
  Camera* camera( );
protected:
  Camera* _camera;

  std::vector< Light* > _lights;

  std::unordered_map< RenderableType, std::vector< Renderable* >> _renderables;
};

