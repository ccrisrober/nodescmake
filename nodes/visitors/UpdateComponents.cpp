#include "UpdateComponents.h"
#include "../scenegraph/Node.h"

UpdateComponents::UpdateComponents( const float& dt )
: LambdaVisitor( [ dt ] ( Node*n ) { n->updateComponents( dt ); } )
{
}


UpdateComponents::~UpdateComponents( )
{
}
