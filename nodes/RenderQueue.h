#pragma once

#include <vector>
#include <unordered_map>
#include "components/MeshRenderer.h"

#include "scenegraph/Light.h"
#include "scenegraph/Geometry.h"
#include "scenegraph/Camera.h"

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
  NODES_API
  std::vector<Renderable*> renderables( RenderableType t );
  NODES_API
  void pushGeometry( Geometry* g );
  NODES_API
  void pushLight( Light * l );
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

