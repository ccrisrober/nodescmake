#pragma once

class Node;
class Group;
class Camera;

#include <nodes/api.h>

class NodeVisitor
{
protected:
  NodeVisitor( );
public:
  NODES_API
    virtual ~NodeVisitor( );
  NODES_API
    virtual void reset( void );
  NODES_API
    virtual void traverse( Node* node );
  NODES_API
    virtual void visitNode( Node *node );
  NODES_API
    virtual void visitGroup( Group *group );
  NODES_API
  virtual void visitCamera( Camera *camera );
private:
  NodeVisitor( const NodeVisitor& );
  NodeVisitor &operator= ( const NodeVisitor& );
};

