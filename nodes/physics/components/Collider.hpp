#ifndef __NODES_COLLIDER__
#define __NODES_COLLIDER__

#include "../../components/Component.h"

namespace nodes
{
  class Collider: public Component
  {
    IMPLEMENT_COMPONENT( Collider )
  protected:
    Collider( ) { };
  };
}

#endif /* __NODES_COLLIDER__ */
