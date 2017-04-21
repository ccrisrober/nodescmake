#include "RenderSystem.h"

namespace nodes
{
  RenderSystem::RenderSystem( )
    : System( std::string( "RenderSystem" ))
  {
  }

  bool RenderSystem::start( void )
  {
    if (!System::start( ))
    {
      return false;
    }

    // Update??

    return true;
  }

  void RenderSystem::stop( void )
  {
    System::stop( );
  }
}
