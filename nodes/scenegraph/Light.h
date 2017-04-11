#ifndef __LIGHT__
#define __LIGHT__

#include "Node.h"
#include <nodes/api.h>
class Light :
  public Node
{
public:
  NODES_API
    Light( void );
  NODES_API
  ~Light( void );

public:
  NODES_API
  virtual void accept( Visitor& v ) override;
};

#endif
