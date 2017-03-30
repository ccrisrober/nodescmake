source_group(\\ FILES CMakeLists.txt)

set( NODES_PUBLIC_HEADERS
  components/Component.h
  components/CustomComponent.h
  components/MeshRenderer.h
  components/OtherComponent.h

  scenegraph/Camera.h
  scenegraph/Group.h
  scenegraph/Light.h
  scenegraph/Node.h
  scenegraph/Switch.h

  systems/RenderSystem.h
  systems/System.h
  systems/UpdateSystem.h

  visitors/ChildrenCounterVisitor.h
  visitors/FetchCameras.h
  visitors/FetchLights.h
  visitors/FetchGeometry.h
  visitors/LambdaVisitor.h
  visitors/PickingVisitor.h
  visitors/PrintNameVisitor.h
  visitors/StartComponents.h
  visitors/UpdateComponents.h
  visitors/UpdateWorldState.h
  visitors/Visitor.h

  Engine.h
  Renderer.h
  RenderQueue.h
)

set( NODES_HEADERS
)

set( NODES_SOURCES
  components/Component.cpp
  components/CustomComponent.cpp
  components/MeshRenderer.cpp
  components/OtherComponent.cpp

  scenegraph/Camera.cpp
  scenegraph/Group.cpp
  scenegraph/Light.cpp
  scenegraph/Node.cpp
  scenegraph/Switch.cpp

  systems/RenderSystem.cpp
  systems/System.cpp
  systems/UpdateSystem.cpp

  visitors/ChildrenCounterVisitor.cpp
  visitors/FetchCameras.cpp
  visitors/FetchLights.cpp
  visitors/FetchGeometry.cpp
  visitors/LambdaVisitor.cpp
  visitors/PickingVisitor.cpp
  visitors/PrintNameVisitor.cpp
  visitors/StartComponents.cpp
  visitors/UpdateComponents.cpp
  visitors/UpdateWorldState.cpp
  visitors/Visitor.cpp

  Engine.cpp
  Renderer.cpp
  RenderQueue.cpp
)

set( NODES_LINK_LIBRARIES
)

common_library( nodes )
