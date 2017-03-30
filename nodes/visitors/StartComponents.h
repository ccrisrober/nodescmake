#pragma once
#include "LambdaVisitor.h"
#include <nodes/api.h>
class StartComponents :
  public LambdaVisitor
{
public:
  NODES_API
  StartComponents( );
  NODES_API
  virtual ~StartComponents( );
};

