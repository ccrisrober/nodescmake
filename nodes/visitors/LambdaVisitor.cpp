#include "LambdaVisitor.h"
#include "../scenegraph/Node.h"
#include "../scenegraph/Group.h"

namespace nodes
{
  LambdaVisitor::LambdaVisitor( CallbackType cb )
  : _callback(cb )
  {
  }

  LambdaVisitor::~LambdaVisitor( )
  {
  }

  void LambdaVisitor::visitNode( Node* n )
  {
    _callback( n );
  }

  void LambdaVisitor::visitGroup( Group *group )
  {
    _callback( group );
    Visitor::visitGroup( group );
  }
}
