#include "Renderer.h"


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
  // TODO: rp->render( this, rq, rq->camera( ) );
}

void Renderer::endRender( void )
{
  // Clear data
}