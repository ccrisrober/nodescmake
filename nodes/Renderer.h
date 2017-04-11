#pragma once
#include "scenegraph/Camera.h"

#include <vector>

class RenderPass;
class RenderQueue;

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


class OpenGLRenderer: public Renderer
{
public:
  //OpenGLRenderer( );
  //~OpenGLRenderer( );
  virtual void setViewport( std::vector< float > )
  {
    std::cout << "CHANGE VIEWPORT" << std::endl;
  }
  virtual void beginRender( void )
  {
    Renderer::beginRender( );
  }
  virtual void clearBuffers( void )
  {
    std::cout << "Clear color and depth buffers" << std::endl;
  }
  virtual void endRender( void )
  {
    Renderer::endRender( );
  }
};