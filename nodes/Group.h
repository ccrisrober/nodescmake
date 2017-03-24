#pragma once
#include "Node.h"
#include <nodes/api.h>
class Group :
  public Node
{
public:
  NODES_API
  Group( const std::string name );
  NODES_API
  virtual ~Group( );

  NODES_API
  bool hasNodes( void ) const;
  NODES_API
  unsigned int numChildren( void ) const;

  NODES_API
  void addChild( Node* node );
  NODES_API
  void removeChild( Node* node );
  NODES_API
  void removeChildren( void );
  NODES_API
  Node* nodeAt( unsigned int idx );

  template<typename T>
  T* nodeAt( unsigned int idx )
  {
    return static_cast< T* >( nodeAt( idx ); )
  }
  NODES_API
  void insertChild( unsigned int idx, Node* node )
  {
    // TODO Insert at position (WARNING: CHECK position)
  }
  NODES_API
  void removeChild( unsigned int idx )
  {
    // TODO: Same as insertChild warnings
  }

  // TODO: getNode (string)
  // TODO: T* getNode<T>(string)
  NODES_API
  virtual void forEachNode( std::function< void( Node * ) > callback );
protected:
  std::vector<Node*> _children;

public:
  NODES_API
  virtual void accept( NodeVisitor& v );
};

