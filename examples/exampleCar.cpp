#include <iostream>

#include <nodes/nodes.h>

using namespace nodes;

#include <vector>

class CarController : public nodes::Component
{
  IMPLEMENT_COMPONENT( CarController )
public:
  virtual void start( )
  {
    auto group = ( Group* ) node( );
    group->forEachNode( [ &] ( nodes::Node* n )
    {
      if ( n->name( ) == "front" )
      {
        std::cout << "Fetching lights" << std::endl;
        auto g2 = ( Group* ) n;
        g2->forEachNode( [ &] ( nodes::Node* n2 )
        {
          _lights.push_back( n2 );
        } );
      }
      else if ( n->name( ) == "wheels" )
      {
        std::cout << "Fetching wheels" << std::endl;
        auto g2 = ( Group* ) n;
        g2->forEachNode( [ &] ( nodes::Node* n2 )
        {
          _wheels.push_back( n2 );
        } );
      }
    } );
  }
  std::vector<Node*> _lights;
  std::vector<Node*> _wheels;
};

int main( )
{
  auto scene = new Group( "scene" );

  auto car = new Group( "car" );
  scene->addChild( car );

  auto front = new Group( "front" );
  for ( unsigned int i = 0; i < 2; ++i )
  {
    auto light = new Light( );
    light->name( std::string("Light") + std::to_string( i + 1 ) );
    front->addChild( light );
  }
  car->addChild( front );

  auto wheels = new Group( "wheels" );
  for ( unsigned int i = 0; i < 4; ++i )
  {
    auto wheel = new Geometry(
      std::string("Wheel") +
      std::to_string( i + 1 )
    );
    wheels->addChild( wheel );
  }
  car->addChild( wheels );

  car->addComponent( new CarController( ) );


  auto cam = new Camera( );
  Camera::mainCamera( cam );
  scene->addChild( cam );


  nodes::DumpVisitor dv;
  dv.traverse( scene );

  App app;
  app.setSceneNode( scene );
  app.run( );
  delete scene;
  system( "PAUSE" );
  return 0;
}
