#pragma once
#include "RenderQueue.h"
#include "scenegraph/Camera.h"

#include <vector>

class Renderer
{
public:
  Renderer( );
  ~Renderer( );
  virtual void setViewport ( std::vector< float > ) { }
  virtual void beginRender( void );
  virtual void clearBuffers( void ) = 0;
  virtual void render( RenderQueue* rq, RenderPass* rp );
  virtual void endRender( void );
};

