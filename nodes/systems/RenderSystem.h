#ifndef __NODES_RENDER_SYSTEM__
#define __NODES_RENDER_SYSTEM__

#include "System.h"

namespace nodes
{
  class RenderSystem: public System
  {
  public:
    RenderSystem( void );
    virtual bool start( void ) override;
    virtual void stop( void ) override;
  };
}

#endif /* __NODES_RENDER_SYSTEM__ */
