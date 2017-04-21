#pragma once

class ScriptContext;

class ScriptEvaluator
{
public:
  ScriptEvaluator( ScriptContext* ctx );
  ~ScriptEvaluator( void );
  ScriptContext* context( void )
  {
    return _ctx; 
  }
  ScriptEvaluator childEvaluator( const std::string& childName )
  {
    return ScriptEvaluator( context( ), "." + childName );
  }
private:
  ScriptContext* _ctx = nullptr;
public:

};

class ScriptContext
{

};

class Scripted
{
protected:
  Scripted( bool loadDefaultLibs = false )
  : _scriptCtx( loadDefaultLibs )
  {
  }
public:
  virtual ~Scripted( void ) { }
  
  ScriptContext& scriptContext( void )
  {
    return _scriptCtx;
  }
private:  // Private for disable direct using in child classes
  ScriptContext _scriptCtx;
};

class ScriptComponent : public Component
{

};