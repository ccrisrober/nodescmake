#ifndef __NODES_FETCH_CAMERAS__
#define __NODES_FETCH_CAMERAS__

#include "Visitor.h"
#include <vector>
#include <functional>

#include <nodes/api.h>

namespace nodes
{
  class FetchCameras :
    public Visitor
  {
  public:
    NODES_API
    FetchCameras( );
    NODES_API
    virtual ~FetchCameras( );
    NODES_API
    virtual void reset( void ) override;
    NODES_API
    virtual void visitCamera( Camera* c ) override;
    NODES_API
    bool hasCameras( void ) const
    {
      return !_cameras.empty( );
    }
    NODES_API
    void forEachCamera( std::function<void( Camera* )> cb );
  protected:
    std::vector<Camera*> _cameras;
  };
}

#endif /* __NODES_FETCH_CAMERA__ */
