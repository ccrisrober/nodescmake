#pragma once

#include "Node.h"
#include "../components/MeshRenderer.h"

#include <iostream>
#include <string>

class Primitive
{
public:
  Primitive( const std::string& name_ )
    : name( name_ )
  {
  }
  std::string name;
  void render( )
  {
    std::cout << "\t-Primitive '" << name << "'" << std::endl;
  }
};

class Geometry: public Node
{
public:
  NODES_API
  Geometry( const std::string& name = "" )
    : Node( name )
  {
    addComponent( new MeshRenderer( 1 ) );
  }

  virtual ~Geometry( )
  {
    removeAllPrimitives( );
  }
  void removeAllPrimitives( void )
  {
    _primitives.clear( );
  }

  bool hasPrimitives( void ) const
  {
    return !_primitives.empty( );
  }

  void addPrimitive( Primitive* p )
  {
    _primitives.push_back( p );
  }
  void removePrimitive( Primitive *p )
  {
    // TODO: Worst code in the world xD
    _primitives.erase( std::find( _primitives.begin( ), _primitives.end( ), p ) );
  }
  void forEachPrimitive( std::function< void(Primitive* )> cb );

protected:
  std::vector< Primitive* > _primitives;

public:
  virtual void accept( Visitor& v ) override;
};
