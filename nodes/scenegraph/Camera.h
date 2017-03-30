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

class RenderPass
{
public:
  std::vector< ImageEffect *> _imageEffects;
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

