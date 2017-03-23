#pragma once
#include "ApplyVisitor.h"
#include <nodes/api.h>
class UpdateComponents :
  public ApplyVisitor
{
public:
  // TODO: USE CLOCK
  NODES_API
  UpdateComponents( const float& dt );
  NODES_API
  virtual ~UpdateComponents( );
};

