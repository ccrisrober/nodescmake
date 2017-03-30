#pragma once
#include "LambdaVisitor.h"
#include <nodes/api.h>
class UpdateComponents :
  public LambdaVisitor
{
public:
  // TODO: USE CLOCK
  NODES_API
  UpdateComponents( const float& dt );
  NODES_API
  virtual ~UpdateComponents( );
};

