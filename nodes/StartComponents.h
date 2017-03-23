#pragma once
#include "ApplyVisitor.h"
#include <nodes/api.h>
class StartComponents :
  public ApplyVisitor
{
public:
  NODES_API
  StartComponents( );
  NODES_API
  virtual ~StartComponents( );
};

