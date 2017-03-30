#include "PrintNameVisitor.h"
#include <iostream>
#include <string>
#include "../scenegraph/Node.h"

PrintNameVisitor::PrintNameVisitor( )
: LambdaVisitor( [] ( Node*n ){
  std::cout << n->name( ) << std::endl;
} )
{
}


PrintNameVisitor::~PrintNameVisitor( )
{
}
