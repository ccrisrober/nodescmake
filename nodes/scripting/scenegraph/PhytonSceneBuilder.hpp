#pragma once

class PythonSceneBuilder
{
public:
  typedef std::function<Node>( ScriptEvaluator& ) > NodeBuilderFn;
  NODES_API
  PythonSceneBuilder( void );
  virtual ~PythonSceneBuilder( void );

  template< typename T >
  void registerNodeBuilder( const std::string& type )
  {
    _nodeBuilders[ type ] = [] ( ScriptEvaluator &ev )
    {
      auto node = T( );
      node->load( ev );
      return node;
    }

    void registerCustomNodeBuilder( const std::string& type, NodeBuilderFn builder )
    {
      _nodeBuilders[ type ] = builder;
    }

    NodeBuilderFn builder( const std::string& type )
    {
      return _nodeBuilders[ type ];
    }
  public:
    template< class T>
    class RegistrationHelper
    {
    public:

    private:
      std::map< std::string, NodeBuilderFn> _nodeBuilders;
    };
  }
};
