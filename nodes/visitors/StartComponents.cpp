#include "StartComponents.h"
#include "../scenegraph/Node.h"

namespace nodes
{
  StartComponents::StartComponents( )
  : LambdaVisitor( [] ( Node*n ){ n->startComponents( ); } )
  {
  }

  StartComponents::~StartComponents( )
  {
  }
}
