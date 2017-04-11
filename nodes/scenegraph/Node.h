#pragma once

#include "../components/Component.h"
#include <unordered_map>
#include <functional>
#include "../visitors/Visitor.h"

#include <nodes/api.h>
#include <algorithm>

class Node
{
public:
  NODES_API
  Node( const std::string& name );
  NODES_API
  virtual ~Node( void );
  NODES_API
  std::string name( void ) const;
  NODES_API
  void name( const std::string& name );
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
  NodeClass* parent( void );

  void parent( Node* p );

  NODES_API
  void startComponents( void );
  NODES_API
  void addComponent( Component* comp );
  NODES_API
  void updateComponents( const float& dt );
  NODES_API
  void detachAllComponents( void );
  NODES_API
  void forEachComponent( std::function< void( Component * ) > callback );

  template <class T>
  bool hasComponent( void );
  template <class T>
  T* getComponent( void );
  template <class T>
  void removeComponent( void );
  template <class T>
  void removeComponents( void );
  template <class T>
  T* componentInParent( void );
  NODES_API
  Component* getComponentByName( const std::string& name );
  std::vector<Component*> getComponentsByName( const std::string& name );
  protected:
    std::unordered_multimap<std::string, Component*> _components;
};

#include "Node.inl"