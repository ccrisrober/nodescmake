#ifndef __NODES_VISITOR__
#define __NODES_VISITOR__

#include <nodes/api.h>

namespace nodes
{
  class Node;
  class Geometry;
  class Group;
  class Camera;
  class Light;

  class Visitor
  {
  protected:
    Visitor( ) {}
  public:
    NODES_API
      virtual ~Visitor( );
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
    NODES_API
      virtual void visitLight( Light* light );
    NODES_API
      virtual void visitGeometry( Geometry *geometry );
  private:
    Visitor( const Visitor& );
    Visitor &operator= ( const Visitor& );
  };
}

#endif /* __NODES_VISITOR__ */
