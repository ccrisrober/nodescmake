#pragma once

#include "Node.h"
#include <nodes/api.h>

class Camera;

class ImageEffect
{
public:
  NODES_API
  // TODO Renderer?
  virtual void apply( Camera* camera ) = 0;
  NODES_API
  // TODO Renderer?
  virtual void compute( Camera* camera ) = 0;

  bool enabled = true;
protected:

};


class SepiaToneEffect :
  public ImageEffect
{
public:
  NODES_API
    virtual void compute( Camera* camera ) override;
  NODES_API
  virtual void apply( Camera* camera ) override;
protected:
  int shader;
};

class Renderer;
class RenderQueue;

class RenderPass
{
public:
  void render( Renderer* renderer, RenderQueue* rq, Camera* c )
  {

  }
  std::vector< ImageEffect *> _imageEffects;
};

class StandardRP: public RenderPass
{
public:
  void render( Renderer* renderer, RenderQueue* rq, Camera* c )
  {
    // computeShadows( )S
    renderOpaqueObjects( renderer, rq, c );
    renderTransparentObjects( renderer, rq, c );
  }

protected:
  void renderOpaqueObjects( Renderer* renderer, RenderQueue* rq, Camera* c )
  {
    /*auto renderables = rq->renderables( OPAQUE );
    if ( renderables.empty( ) )
    {
      return;
    }
    rq->each( renderables, {
      auto mat = r->material;
      mat->set( "projection", ... );
      mat->set( "view", ... );
      // if (isShadowEnabled( )) { }
      // if (isLightEnabled( )) { bindEachLight( ); }

      renderStandardGeometry( renderer, renderable->geometry, material, renderable->modelTransform );

      // if (isLightEnabled( )) { unbindEachLight( ); }
      // if (isShadowEnabled( )) { }

    });*/
  }
  void renderTransparentObjects( Renderer* renderer, RenderQueue* rq, Camera* c )
  {
    /*auto renderables = rq->renderables( OPAQUE );
    if ( renderables.empty( ) )
    {
      return;
    }

    rq->each( renderables, {
      auto mat = renderable->material;
      mat->set( "projection", ... );
      mat->set( "view", ... );

      renderStandardGeometry( renderer, renderable->geometry, material, renderable->modelTransform );
    });*/
  }
  /*void renderStandardGeometry( Renderer* renderer, Geometry *g, Material* m, std::vector< float > modelTransform )
  {

  }*/
};

class Camera:
  public Node
{
public:
  NODES_API
  static Camera *mainCamera( void )
  {
    return _mainCamera;
  }
  NODES_API
  static void mainCamera( Camera *camera )
  {
    _mainCamera = camera;
  }
private:
  static Camera *_mainCamera;
public:
  NODES_API
    Camera( );
  NODES_API
  virtual ~Camera( );
public:
  NODES_API
  virtual void accept( Visitor& v ) override;
public:
  NODES_API
  void renderPass( RenderPass* rp )
  {
    _renderPass = rp;
  }
  NODES_API
  RenderPass* renderPass( )
  {
    return _renderPass;
  }

  NODES_API
  bool isMainCamera( void ) const
  {
    return _isMainCamera;
  }
  NODES_API
  void setIsMainCamera( bool v )
  {
    _isMainCamera = v;
  }

private:
  bool _isMainCamera = false;
protected:
  RenderPass* _renderPass;
};

