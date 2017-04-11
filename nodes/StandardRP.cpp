#include "StandardRP.hpp"
#include "RenderQueue.h"

void StandardRP::render( Renderer* renderer, RenderQueue* rq, Camera* c )
{
  // computeShadows( )
  std::cout << "Render OpaqueObjects" << std::endl;
  renderOpaqueObjects( renderer, rq, c );
  std::cout << "Render TransparentObjects" << std::endl;
  renderTransparentObjects( renderer, rq, c );
}

void StandardRP::renderOpaqueObjects( Renderer* renderer, RenderQueue* rq, Camera* c )
{
  auto renderables = rq->renderables( RenderQueue::RenderableType::OPAQUE );
  if ( renderables.empty( ) )
  {
    return;
  }
  /*rq->each( renderables, {
    auto mat = r->material;
    mat->set( "projection", ... );
    mat->set( "view", ... );
    // if (isShadowEnabled( )) { }
    // if (isLightEnabled( )) { bindEachLight( ); }

    renderStandardGeometry( renderer, renderable->geometry, material, renderable->modelTransform );

    // if (isLightEnabled( )) { unbindEachLight( ); }
    // if (isShadowEnabled( )) { }

  });*/
  for ( auto& renderable : renderables )
  {
    // TODO: set projection and view

    renderStandardGeometry( renderer, renderable );
  }
}
void StandardRP::renderTransparentObjects( Renderer* renderer, RenderQueue* rq, Camera* c )
{
  auto renderables = rq->renderables( RenderQueue::RenderableType::TRANSPARENT );
  if ( renderables.empty( ) )
  {
    return;
  }

  for ( auto& renderable : renderables )
  {
    // TODO: set projection and view

    renderStandardGeometry( renderer, renderable );
  }
}
void StandardRP::renderStandardGeometry( Renderer* renderer, Renderable* renderable )
{
  renderable->geom->forEachPrimitive( [] ( Primitive *pr )
  {
    //std::cout << "Draw primitive" << std::endl;
    pr->render( );
  } );
}
