#include "PrintNameVisitor.h"
#include <iostream>
#include <string>
#include "Node.h"

PrintNameVisitor::PrintNameVisitor( )
: ApplyVisitor( [] ( Node*n ){ 
  std::cout << n->name( ) << std::endl;
} )
{
}


PrintNameVisitor::~PrintNameVisitor( )
{
}
