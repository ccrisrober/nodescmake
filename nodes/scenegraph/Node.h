#ifndef __NODES_NODE__
#define __NODES_NODE__

#include "../components/Component.h"
#include <unordered_map>
#include <functional>
#include "../visitors/Visitor.h"
#include "../Layer.hpp"

#include <nodes/api.h>
#include <algorithm>
#include <string>

namespace nodes
{
  class Quaternion;
  class EulerAngles
  {
  public:
    void setOnChangeCallback( const std::function<void( Quaternion )>& cb )
    {
      _cb = cb;
    }
    std::function<void( Quaternion )> _cb;
  };
  class Quaternion
  {
  public:
    void setOnChangeCallback( const std::function<void( EulerAngles )>& cb )
    {
      _cb = cb;
    }
    std::function<void( EulerAngles )> _cb;
  };
  class Transformation
  {
  public:
    void computeFrom( const Transformation&, const Transformation& )
    {
      std::cout << "Computing transform" << std::endl;
    }
    void translate( const float&, const float&, const float& )
    {
    }
  };

  class Node
  {
  public:
    NODES_API
    Layer& layer( )
    {
      return _layer;
    }
  private:
    Layer _layer;

  public:
    NODES_API
    Node( );
    NODES_API
    Node( const std::string& name );
    NODES_API
    virtual ~Node( void );
    NODES_API
    std::string name( void ) const;
    NODES_API
    void name( const std::string& name );
    std::string tag;
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
    NODES_API
    std::vector<Component*> getComponentsByName( const std::string& name );

  protected:
    std::unordered_multimap<std::string, Component*> _components;

  public:
    void setLocal( const Transformation &t )
    {
      _local = t;
    }
    const Transformation &getLocal( void ) const
    {
      return _local;
    }
    Transformation &local( void )
    {
      return _local;
    }

    void setWorld( const Transformation &t )
    {
      _world = t;
    }
    const Transformation &getWorld( void ) const
    {
      return _world;
    }
    Transformation &world( void )
    {
      return _world;
    }
  protected:
    Transformation _local;
    Transformation _world;
  };

  #include "Node.inl"
}

#endif /* __NODES_NODE__ */
