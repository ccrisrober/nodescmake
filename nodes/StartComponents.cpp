#include "StartComponents.h"
#include "Node.h"

StartComponents::StartComponents( )
: ApplyVisitor( [] ( Node*n ){ n->startComponents( ); } )
{
}

StartComponents::~StartComponents( )
{
}
