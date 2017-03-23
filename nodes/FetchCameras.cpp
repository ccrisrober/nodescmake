#include "FetchCameras.h"

FetchCameras::FetchCameras( )
{
}

FetchCameras::~FetchCameras( )
{
}

void FetchCameras::reset( void )
{
  _cameras.clear( );
  NodeVisitor::reset( );
}

void FetchCameras::visitCamera( Camera *c )
{
  _cameras.push_back( c );
}

void FetchCameras::forEachCamera( std::function< void( Camera * ) > cb )
{
  for ( auto& camera : _cameras ) {
    cb( camera );
  }
  _cameras.clear( );
}

