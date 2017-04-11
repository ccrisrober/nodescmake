#include "Geometry.h"

void Geometry::accept( Visitor& v )
{
  v.visitGeometry( this );
}

#include <algorithm>

void Geometry::forEachPrimitive( std::function<void(Primitive*)> cb )
{
  std::for_each( _primitives.begin( ), _primitives.end( ), cb );
}
