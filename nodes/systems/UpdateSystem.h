#ifndef __NODES_UPDATE_SYSTEM__
#define __NODES_UPDATE_SYSTEM__

#include "System.h"

namespace nodes
{
  class UpdateSystem: public System
  {
  public:
    UpdateSystem( void );
    virtual bool start( void ) override;
    virtual void stop( void ) override;

  protected:
    virtual void update( void );
  };
}

#endif /* __NODES_UPDATE_SYSTEM__ */
