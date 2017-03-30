#pragma once

#include "System.h"

class RenderSystem: public System
{
public:
  RenderSystem( void );
  virtual bool start( void ) override;
  virtual void stop( void ) override;
};
