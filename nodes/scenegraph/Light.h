#ifndef __LIGHT__
#define __LIGHT__

#include "Node.h"
#include <nodes/api.h>
class Light :
  public Node
{
public:
  Light( void );
  ~Light( void );

public:
  virtual void accept( Visitor& v ) override;
};

#endif
