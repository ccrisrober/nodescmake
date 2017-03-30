#pragma once

#include "../components/Component.h"
#include <unordered_map>
#include <functional>
#include "../visitors/Visitor.h"

#include <nodes/api.h>

class Node
{
public:
  NODES_API
  Node( const std::string& name );
  NODES_API
  virtual ~Node( );
  NODES_API
  std::string name( ) const;
  NODES_API
  void name( const std::string& name )
  {
    _name = name;
  }

protected:
  Node* _parent;
  std::string _name;

public:
  NODES_API
  void perform( Visitor &visitor );
  NODES_API
  void perform( const Visitor &visitor );
  NODES_API
  virtual void accept( Visitor &visitor );

public:
  NODES_API
    bool hasParent( void ) const;
  NODES_API
  Node* parent( void );

  template<class NodeClass>
  NodeClass* parent( void )
  {
    return static_cast< NodeClass* >( _parent );
  }
  void parent( Node* p );

  NODES_API
    void startComponents( );
  NODES_API
    void addComponent( Component* comp );
  NODES_API
    void updateComponents( const float& dt );
  NODES_API
    void detachAllComponents( void );
  NODES_API
  void forEachComponent( std::function< void( Component * ) > callback );

  template <class T>
  bool hasComponent( )
  {
    auto aux = _components.find( T::StaticGetUID( ) );
    if ( aux == _components.end( ) )
    {
      return false;
    }
    return true;
  }
  template <class T>
  T* getComponent( )
  {
    auto aux = _components.find( T::StaticGetUID( ) );
    if ( aux == _components.end( ) )
    {
      return nullptr;
    }
    return static_cast<T*>( aux->second );
  }
  /*template <class T>
  void removeComponent( )
  {
    onDetach( );
  }
  template <class T>
  void removeComponents( )
  {

  }
  template <class T>
  T* componentInparent( void )
  {
    return nullptr;
  }*/
  NODES_API
  Component* getComponentByName( const std::string& name );
  /*std::vector<Componente*> getComponentsByName( const std::string& name )
  {
    std::vector<Componente*> cs;
    auto finds = _components.find( name );
    return cs;
  }*/
  protected:
    std::unordered_multimap<std::string, Component*> _components;
};

