#include "Light.h"

Light::Light( )
: Node( std::string("Light") )
{
}

Light::~Light( )
{
}

void Light::accept( Visitor& visitor )
{
  visitor.visitLight( this );
}
