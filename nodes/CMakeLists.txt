source_group(\\ FILES CMakeLists.txt)

set( NODES_PUBLIC_HEADERS
  ApplyVisitor.h
  CustomComponent.h
  Group.h
  OtherComponent.h
  RenderQueue.h
  UpdateWorldState.h
  Camera.h
  Engine.h
  MeshRenderer.h
  PickingVisitor.h
  StartComponents.h
  ChildrenCounterVisitor.h
  FetchCameras.h
  Node.h
  PrintNameVisitor.h
  Switch.h
  Component.h
  FetchGeometry.h
  NodeVisitor.h
  Renderer.h
  UpdateComponents.h
)

set( NODES_HEADERS
)

set( NODES_SOURCES
  ApplyVisitor.cpp
  Engine.cpp
  Node.cpp
  Renderer.cpp
  UpdateComponents.cpp
  Camera.cpp
  FetchCameras.cpp
  NodeVisitor.cpp
  RenderQueue.cpp
  UpdateWorldState.cpp
  ChildrenCounterVisitor.cpp
  FetchGeometry.cpp
  OtherComponent.cpp
  Component.cpp
  Group.cpp
  PickingVisitor.cpp
  StartComponents.cpp
  CustomComponent.cpp
  MeshRenderer.cpp
  PrintNameVisitor.cpp
  Switch.cpp
  #Source.cpp
)

set( NODES_LINK_LIBRARIES
)

common_library( nodes )
