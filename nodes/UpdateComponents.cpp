#include "UpdateComponents.h"
#include "Node.h"

UpdateComponents::UpdateComponents( const float& dt )
: ApplyVisitor( [ dt ] ( Node*n ) { n->updateComponents( dt ); } )
{
}


UpdateComponents::~UpdateComponents( )
{
}
