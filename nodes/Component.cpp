#include "Component.h"
#include "Node.h"

Component::Component( )
{
}

Component::~Component( )
{
  std::cout << "[D] Component" << std::endl;
}

Node* Component::node( )
{
  return _node;
}

void Component::node( Node* n )
{
  _node = n;
}

void Component::update( const float &dt )
{
}

void Component::start( void )
{
}
#include <string>
void Component::onAttach( void )
{
  std::cout << "Attached " << this->GetUID( ) << " to node '" << this->node( )->name( ) << "'" << std::endl;
}

void Component::onDetach( void )
{
}