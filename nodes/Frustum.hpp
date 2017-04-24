#ifndef __NODES_FRUSTUM__
#define __NODES_FRUSTUM__

#include <math.h>
#include <nodes/api.h>

namespace nodes
{
  class Frustum
  {
    enum {
      FRUSTUM_R_MIN = 0,
      FRUSTUM_R_MAX = 1,
      FRUSTUM_U_MIN = 2,
      FRUSTUM_U_MAX = 3,
      FRUSTUM_D_MIN = 4,
      FRUSTUM_D_MAX = 5,
    };
  public:
    //NODES_API
    Frustum( void )
    {
    }
    NODES_API
    Frustum( const float& fov/* = 45.0f*/, const float& ar/* = 1.0f*/,
      const float& near/* = 0.1f*/, const float& far/* = 1000.0f*/ )
    {
      _data[ FRUSTUM_U_MAX ] = near * std::tan( 0.5f * fov * 3.1415f / 180.0f );
      _data[ FRUSTUM_R_MAX ] = ar * _data[ FRUSTUM_U_MAX ];
      _data[ FRUSTUM_U_MIN ] = -_data[ FRUSTUM_U_MAX ];
      _data[ FRUSTUM_R_MIN ] = -_data[ FRUSTUM_R_MAX ];
      _data[ FRUSTUM_D_MIN ] = near;
      _data[ FRUSTUM_D_MAX ] = far;
    }
    NODES_API
    ~Frustum( )
    {
    }

  protected:
    std::array< float, 6 > _data;
  };
}

#endif /* __NODES_FRUSTUM__ */
