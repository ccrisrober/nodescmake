#include "Group.h"

Group::Group( const std::string name )
: Node( name )
{
}
#include <string>
Group::~Group( )
{
  std::cout << "[D] Group '" << this->name( ) << "'" << std::endl;
  removeChildren( );
}

bool Group::hasNodes( void ) const
{
  return !_children.empty( );
}
unsigned int Group::numChildren( void ) const
{
  return _children.size( );
}

void Group::addChild( Node* node )
{
  if ( node->parent( ) == this )
  {
    return;
  }
  if ( node->parent( ) != nullptr )
  {
    throw "HasParentException";
  }
  node->parent( this );
  _children.push_back( node );
}

void Group::removeChild( Node* n )
{
  if ( n->parent( ) == this )
  {
    n->parent( nullptr );
    // TODO: _children.erase( n );
  }
}
#include <algorithm>
void Group::removeChildren( void )
{
  std::for_each( _children.begin( ), _children.end( ), [] ( Node* n )
  {
    n->parent( nullptr );
  } );
  _children.clear( );
}

Node* Group::nodeAt( unsigned int idx )
{
  return _children.at( idx );
}

void Group::forEachNode( std::function< void( Node * ) > callback )
{
  std::for_each( _children.begin( ), _children.end( ), [&] ( Node* n )
  {
    /*if ( n->isEnabled( ) )
    {*/
    callback( n );
    /*}*/
  } );
}
void Group::accept( NodeVisitor& v )
{
  v.visitGroup( this );
}