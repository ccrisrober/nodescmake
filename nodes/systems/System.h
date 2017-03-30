#pragma once

#include <string>

class System
{
public:
  System( const std::string& name );
  virtual bool start( );
  virtual void stop( );
  std::string name( ) const
  {
    return _name;
  }
protected:
  std::string _name;
};
