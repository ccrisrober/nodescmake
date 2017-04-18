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


set( NODESEXAMPLEGROUP_HEADERS )
set( NODESEXAMPLEGROUP_SOURCES exampleGroup.cpp )
set( NODESEXAMPLEGROUP_LINK_LIBRARIES
  nodes
)
common_application( nodesExampleGroup )



set( NODESEXAMPLEXML_HEADERS )
set( NODESEXAMPLEXML_SOURCES exampleXML.cpp )
set( NODESEXAMPLEXML_LINK_LIBRARIES
  nodes
)
common_application( nodesExampleXML )

set( NODESTESTS_HEADERS )
set( NODESTESTS_SOURCES tests.cpp )
set( NODESTESTS_LINK_LIBRARIES
  nodes
)
common_application( nodesTests )

set( NODESEXAMPLEPOSTPROCESS_HEADERS )
set( NODESEXAMPLEPOSTPROCESS_SOURCES examplePostProcess.cpp )
set( NODESEXAMPLEPOSTPROCESS_LINK_LIBRARIES
  nodes
)
common_application( nodesExamplePostProcess )

set( NODESEXAMPLEOFFSCREEN_HEADERS )
set( NODESEXAMPLEOFFSCREEN_SOURCES exampleOffScreen.cpp )
set( NODESEXAMPLEOFFSCREEN_LINK_LIBRARIES
  nodes
)
common_application( nodesExampleOffScreen )
