cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.app)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJ_NAME} ${CS_LIB_TYPE})

generate_export_header(${PROJ_NAME}
  BASE_NAME cs_app
  # EXPORT_MACRO_NAME CS_APP_EXPORT  # default
  # EXPORT_FILE_NAME cs_app_export.h  # default
)
target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE ${PROJ_NAME}_SRC CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE ${PROJ_NAME}_HEADER CONFIGURE_DEPENDS "*.h")
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_SRC})
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_HEADER})
if(WIN32)
target_sources(${PROJ_NAME} PRIVATE ${CMAKE_BINARY_DIR}/version.rc)
endif()

target_compile_definitions(${PROJ_NAME} PRIVATE BUILD_CS_APP_LIB)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

target_precompile_headers(${PROJ_NAME}
  PRIVATE
    <chrono>
    <fstream>
    <cassert>
    <vector>
)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(${PROJ_NAME} PRIVATE unofficial::sqlite3::sqlite3)

find_package(Poco CONFIG REQUIRED Foundation Util)
target_link_libraries(${PROJ_NAME} PRIVATE Poco::Util)

target_link_libraries(${PROJ_NAME} PUBLIC cs.core)
target_link_libraries(${PROJ_NAME} PUBLIC cs.modeler)
target_link_libraries(${PROJ_NAME} PUBLIC cs.render)

target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/cs/app)

message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
