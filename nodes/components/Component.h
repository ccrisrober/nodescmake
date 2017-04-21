#ifndef __NODES_COMPONENT__
#define __NODES_COMPONENT__

#include <iostream>
#include <nodes/api.h>

namespace nodes
{
  typedef std::string ComponentUID;
  #define IMPLEMENT_COMPONENT(__CLASS__) \
  public: \
    static nodes::ComponentUID StaticGetUID( ) { \
    static std::string sUID = #__CLASS__; \
    return ( nodes::ComponentUID ) sUID; /* This will be unique! */ \
    } \
    virtual nodes::ComponentUID GetUID( ) const { return StaticGetUID( ); }

  class Node;

  NODES_API
  class Component
  {
    friend class Node;
  public:
    NODES_API
    virtual ComponentUID GetUID( ) const = 0;
    NODES_API
    virtual ~Component( );
    NODES_API
    Node* node( );
    NODES_API
    void update( const float &dt );
    NODES_API
    virtual void start( void );
    NODES_API
    virtual void onAttach( void );
    NODES_API
    virtual void onDetach( void );
    bool activo = true;

  private:
    void setNode( Node* n );
  protected:
    NODES_API
    Component( );
    Node* _node;
  };
}

#endif /* __NODES_COMPONENT__ */
