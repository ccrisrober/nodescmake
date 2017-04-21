#ifndef __NODES_CAMERA__
#define __NODES_CAMERA__

#include "Node.h"
#include <nodes/api.h>

namespace nodes
{
  class RenderPass;

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
    Camera( void );
    NODES_API
    Camera( RenderPass* rp );
    NODES_API
    virtual ~Camera( );
  public:
    NODES_API
    virtual void accept( Visitor& v ) override;
  public:
    NODES_API
    void renderPass( RenderPass* rp );
    NODES_API
    RenderPass* renderPass( );

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
}

#endif /* __NODES_CAMERA__ */
