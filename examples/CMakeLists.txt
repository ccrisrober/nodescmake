include_directories(
  ${PROJECT_BINARY_DIR}/include
  ${PROJECT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
)

set( NODESFOO_HEADERS )
set( NODESFOO_SOURCES foo.cpp )
set( NODESFOO_LINK_LIBRARIES
  nodes
)
common_application( nodesFoo )


set( NODESEXAMPLE01_HEADERS )
set( NODESEXAMPLE01_SOURCES example01.cpp )
set( NODESEXAMPLE01_LINK_LIBRARIES
  nodes
)
common_application( nodesExample01 )



set( NODESEXAMPLE02_HEADERS )
set( NODESEXAMPLE02_SOURCES example02.cpp )
set( NODESEXAMPLE02_LINK_LIBRARIES
  nodes
)
common_application( nodesExample02 )


set( NODESEXAMPLE03_HEADERS )
set( NODESEXAMPLE03_SOURCES example03.cpp )
set( NODESEXAMPLE03_LINK_LIBRARIES
  nodes
)
common_application( nodesExample03 )


set( NODESEXAMPLE04_HEADERS )
set( NODESEXAMPLE04_SOURCES example04.cpp )
set( NODESEXAMPLE04_LINK_LIBRARIES
  nodes
)
common_application( nodesExample04 )
