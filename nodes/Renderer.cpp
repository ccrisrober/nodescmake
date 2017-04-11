#include "Renderer.h"
#include "RenderPass.hpp"
#include "RenderQueue.h"
#include "scenegraph/Camera.h"

Renderer::Renderer( )
{
}

Renderer::~Renderer( )
{
}

void Renderer::beginRender( void )
{
  std::cout << "Set viewport" << std::endl;
}

void Renderer::render( RenderQueue* rq, RenderPass* rp )
{
  rp->render( this, rq, rq->camera( ) );
}

void Renderer::endRender( void )
{
  // Clear data
  std::cout << "unbind renderer" << std::endl;
}
