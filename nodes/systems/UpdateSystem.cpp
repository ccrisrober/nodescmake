#include "UpdateSystem.h"

UpdateSystem::UpdateSystem( )
  : System( std::string( "UpdateSystem" ))
{
}

bool UpdateSystem::start( void )
{
  if (!System::start( ))
  {
    return false;
  }

  // Update??

  return true;
}

void UpdateSystem::update( void )
{
  // Step 1: Update all nodes
  // Step 2:
}

void UpdateSystem::stop( void )
{
  System::stop( );
}
