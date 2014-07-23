# Created by the script cgal_create_cmake_script_with_options
# This is the CMake script for compiling a set of CGAL applications.

project( BGL )


cmake_minimum_required(VERSION 2.6.2)
if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" VERSION_GREATER 2.6)
  if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}" VERSION_GREATER 2.8.3)
    cmake_policy(VERSION 2.8.4)
  else()
    cmake_policy(VERSION 2.6)
  endif()
endif()

set( CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true )
 
if ( COMMAND cmake_policy )

  cmake_policy( SET CMP0003 NEW )  

endif()

# CGAL and its components
find_package( CGAL QUIET COMPONENTS  )

if ( NOT CGAL_FOUND )

  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  

endif()

# include helper file
include( ${CGAL_USE_FILE} )


# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )
  message(STATUS "This project requires the Boost library, and will not be compiled.")
  return()  
endif()

find_package( OpenMesh QUIET )

if ( OpenMesh_FOUND )
include( UseOpenMesh )
else()
  message(STATUS "Examples that use OpenMesh will not be compiled.")
endif()



# include for local package
include_directories( BEFORE ../../include )

# Creating entries for all .cpp/.C files with "main" routine
# ##########################################################

include( CGAL_CreateSingleSourceCGALProgram )

if(OpenMesh_FOUND)
  create_single_source_cgal_program( "graph_concept_OpenMesh.cpp" )
  target_link_libraries( graph_concept_OpenMesh ${OPENMESH_LIBRARIES} )
endif()

create_single_source_cgal_program( "test_circulator.cpp" )

create_single_source_cgal_program( "graph_concept_Polyhedron_3.cpp" )

create_single_source_cgal_program( "graph_concept_Triangulation_2.cpp" )

create_single_source_cgal_program( "test_graph_geometry.cpp" )
if(OpenMesh_FOUND)
  target_link_libraries( test_graph_geometry ${OPENMESH_LIBRARIES})
endif()

create_single_source_cgal_program( "test_Euler_operations.cpp" )
if(OpenMesh_FOUND)
  target_link_libraries( test_Euler_operations ${OPENMESH_LIBRARIES})
endif()

create_single_source_cgal_program( "test_graph_traits.cpp" )

if(OpenMesh_FOUND)
  target_link_libraries( test_graph_traits ${OPENMESH_LIBRARIES} )
endif()


create_single_source_cgal_program( "test_Properties.cpp" )
if(OpenMesh_FOUND)
  target_link_libraries( test_Properties ${OPENMESH_LIBRARIES})
endif()
