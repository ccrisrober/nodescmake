#include "RenderPass.hpp"

#include "Renderer.h"
#include "RenderQueue.h"
#include "ImageEffect.hpp"
#include "scenegraph/Camera.h"

/*void RenderPass::render( Renderer* renderer, RenderQueue* rq, Camera* c )
{

}*/

namespace nodes
{
  void RenderPass::applyImageEffects( Renderer *renderer, Camera *camera )
  {
    for ( auto& ie : _imageEffects )
    {
      unsigned int fbo = 0;
      ie->compute( renderer, camera );

      renderer->bindFBO( fbo );
      ie->apply( renderer, camera );
      renderer->unbindFBO( fbo );
      // Swap FBO?
      swapBuffers( renderer );
    }
  }

  void RenderPass::swapBuffers( Renderer* r )
  {
    //auto source = 1;
    //auto destination = 2;

    std::cout << "Set source buffer with destination texture" << std::endl;
    //renderer->setFBO(SOURCE, destination);
    std::cout << "Set destination buffer with source texture" << std::endl;
    //renderer->setFBO(DESTINATION, source);
  }
}
