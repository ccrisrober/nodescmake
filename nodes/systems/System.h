#ifndef __NODES_SYSTEM__
#define __NODES_SYSTEM__

#include <string>

namespace nodes
{
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
}

#endif /* __NODES_SYSTEM__ */
