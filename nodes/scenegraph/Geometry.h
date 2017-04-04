#pragma once

#include "Node.h"

class Geometry: public Node
{
public:
  Geometry( const std::string& name = "" )
    : Node( name )
  {
  }

  virtual ~Geometry( )
  {
    while( hasPrimitives( ) )
    {
      removePrimitive( )
    }
  }
  void removeAllPrimitivives( void )
  {

  }

  bool hasPrimitives( void ) const
  {
    return !_primitives.empty( );
  }

  void addPrimitive( Primitive* p )
  {

  }
  void removePrimitive( Primitive *p )
  {

  }

  void forEachPrimitive( std::function< void(Primitive* )> cb );
  void updateModelBounds( void );

protected:
  std::vector< Primitive* > _primitives;

public:
  virtual void accept( Visitor& v ) override;
};


void Geometry::accept( Visitor& v )
{
  v.visitGeometry( this );
}
