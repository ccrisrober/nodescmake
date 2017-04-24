#ifndef __NODES_CAMERA__
#define __NODES_CAMERA__

#include "Node.h"
#include "../Frustum.hpp"
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
    explicit Camera( void );

    NODES_API
    Camera( const float& fov, const float& ar,
      const float& near, const float& far );

    NODES_API
    virtual ~Camera( void );
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
    Frustum _frustum;
    RenderPass* _renderPass;

  public:
    void computeCullingPlanes( void )
    {
      std::cout << "Computing near plane at _cullingPlanes[0]" << std::endl;
      std::cout << "Computing far plane at _cullingPlanes[1]" << std::endl;
      std::cout << "Computing top plane at _cullingPlanes[2]" << std::endl;
      std::cout << "Computing bottom plane at _cullingPlanes[3]" << std::endl;
      std::cout << "Computing left plane at _cullingPlanes[4]" << std::endl;
      std::cout << "Computing right plane at _cullingPlanes[5]" << std::endl;
    }

    NODES_API
    void setCullingEnabled( bool value ) { _cullingEnabled = value; }
    NODES_API
    bool isCullingEnabled( void ) const { return _cullingEnabled; }

    bool culled( /*const BoundingVolume *v*/ ) const
    {
      if( !isCullingEnabled( ) )
      {
        return false;
      }
      /*for( auto& plane: _cullingPlanes )
      {
        if ( plane->inside( v ) )
        {
          return true;
        }
      }*/
      return false;
    }
  private:
    bool _cullingEnabled = true;
    // std::array< Plane, 6 > _cullingPlanes;
  };
}

#endif /* __NODES_CAMERA__ */
