#pragma once
#include "Group.h"
#include <nodes/api.h>
class Switch :
  public Group
{
public:
  NODES_API
  Switch( const std::string name );
  NODES_API
  virtual ~Switch( );

  NODES_API
  virtual void forEachNode( std::function<void( Node* )> cb );
  NODES_API
  Node* currentNode( void );

  NODES_API
  int currentNodeIndex( void ) const;
  NODES_API
  void currentNodeIndex( int idx );

  NODES_API
  void selectNextNode( void );
  NODES_API
  void selectPrevNode( void );

private:
  int _currentIdx;
};

