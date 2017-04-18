#pragma once

#include "visitors/StartComponents.h"
#include "visitors/FetchCameras.h"
#include "visitors/UpdateWorldState.h"
#include "scenegraph/Node.h"
#include "scenegraph/Group.h"
#include "scenegraph/Camera.h"
#include "RenderQueue.h"

#include <algorithm>
#include <string>

#include <nodes/api.h>

#include "systems/System.h"
#include "systems/RenderSystem.h"
#include "systems/UpdateSystem.h"
#include "visitors/FetchGeometry.h"

#include <unordered_map>

#include "Renderer.h"
#include "Clock.hpp"

class Engine
{
public:
  Renderer * renderer;
  NODES_API
  Engine( );
  Group* scene = nullptr;
  NODES_API
  void setScene( Group *g );
  std::vector< Camera * > _cameras;
  NODES_API
  virtual void start( void );
  NODES_API
  virtual bool update( void );
  NODES_API
  virtual int run( void );
  NODES_API
  void forEachCamera( std::function< void( Camera * ) > callback );
  NODES_API
  void iAddSystem( System* ss );
  NODES_API
  void iStart( void );
  NODES_API
  void iUpdate( void );
  NODES_API
  void iStop( void );
  std::unordered_map< std::string, System* > _systems;
};
