#pragma once

#include "System.h"

class UpdateSystem: public System
{
public:
  UpdateSystem( void );
  virtual bool start( void ) override;
  virtual void stop( void ) override;

protected:
  virtual void update( void );
};
