#pragma once
#include "ApplyVisitor.h"
#include <nodes/api.h>
class PrintNameVisitor :
  public ApplyVisitor
{
public:
  NODES_API
  PrintNameVisitor( );
  NODES_API
  virtual ~PrintNameVisitor( );
};

