#include "StandardRP.hpp"

namespace nodes
{
  void StandardRP::render( Renderer* renderer, RenderQueue* rq, Camera* c )
  {
    // computeShadows( )
    renderOpaqueObjects( renderer, rq, c );
    renderTransparentObjects( renderer, rq, c );
  }

  void StandardRP::renderOpaqueObjects( Renderer* renderer, RenderQueue* rq, Camera* c )
  {
    auto renderables = rq->renderables( RenderQueue::RenderableType::OPAQUE );
    if ( renderables.empty( ) )
    {
      return;
    }
    std::cout << "Render OpaqueObjects" << std::endl;
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
    std::cout << "Render TransparentObjects" << std::endl;
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
}
