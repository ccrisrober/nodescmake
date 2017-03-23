#pragma once

#include "NodeVisitor.h"
#include <functional>
#include <vector>

struct Ray
{
  float x;
  float y;
  float z;
  Ray( float xx, float yy, float zz )
  {
    this->x = xx;
    this->y = yy;
    this->z = zz;
  }
};

class Node;
class PickingVisitor :
  public NodeVisitor
{
private:
  typedef std::function< bool( Node* )> FilterType;
public:
  class Results
  {
  public:
    Results( void ) {}
    ~Results( void ) {}
    void reset( void )
    {
      _candidates.clear( );
    }
    void sortCandidates( std::function< bool( Node *, Node * ) > cb )
    {
      // TODO: _candidates.sort( cb );
    }

    void pushCandidate( Node *candidate )
    {
      _candidates.push_back( candidate );
    }
    void foreachCandidate( std::function< void( Node * ) > cb )
    {
      auto cs = _candidates;
      for ( auto c : cs )
      {
        cb( c );
      }
    }

    bool hasResults( void )
    {
      return !_candidates.empty( );
    }

    Node *getBestCandidate( void )
    {
      if ( !hasResults( ) )
      {
        return nullptr;
      }
      return _candidates.front( );
    }
  private:
    std::vector< Node* > _candidates;
  };
  PickingVisitor( const Ray& ray,
    Results &results, FilterType filter );
  virtual ~PickingVisitor( );
  virtual void traverse( Node *node ) override;

  virtual void visitNode( Node *node ) override;
  virtual void visitGroup( Group *node ) override;
private:
  Ray _ray;
  Results &_results;
  FilterType _filter;
};

