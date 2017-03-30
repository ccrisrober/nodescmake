#pragma once
#include "LambdaVisitor.h"
#include <nodes/api.h>
class PrintNameVisitor :
  public LambdaVisitor
{
public:
  NODES_API
  PrintNameVisitor( );
  NODES_API
  virtual ~PrintNameVisitor( );
};

