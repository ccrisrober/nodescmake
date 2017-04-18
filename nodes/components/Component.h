#pragma once

#include <iostream>
#include <nodes/api.h>

typedef std::string ComponentUID;
#define IMPLEMENT_COMPONENT(__CLASS__) \
public: \
  static ComponentUID StaticGetUID( ) { \
  static std::string sUID = #__CLASS__; \
  return ( ComponentUID ) sUID; /* This will be unique in the executable! */ \
  } \
  virtual ComponentUID GetUID( ) const { return StaticGetUID( ); }

class Node;

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
  void node( Node* n );
protected:
  Component( );
  Node* _node;
};
