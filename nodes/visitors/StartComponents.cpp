#include "StartComponents.h"
#include "../scenegraph/Node.h"

StartComponents::StartComponents( )
: LambdaVisitor( [] ( Node*n ){ n->startComponents( ); } )
{
}

StartComponents::~StartComponents( )
{
}
