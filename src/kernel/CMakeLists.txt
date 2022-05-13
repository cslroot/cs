cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME cs.kernel)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJ_NAME} ${CS_LIB_TYPE})

generate_export_header(${PROJ_NAME} BASE_NAME cs_kernel)
target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_compile_definitions(${PROJ_NAME} PRIVATE BUILD_CS_KERNEL_LIB)
target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)

file(GLOB_RECURSE ${PROJ_NAME}_SRC CONFIGURE_DEPENDS "*.cpp")
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_SRC})
if(WIN32)
target_sources(${PROJ_NAME} PRIVATE ${CMAKE_BINARY_DIR}/version.rc)
endif()

target_link_libraries(${PROJ_NAME} PUBLIC cs.base)
target_link_libraries(${PROJ_NAME} PUBLIC cs.core)
target_link_libraries(${PROJ_NAME} PUBLIC cs.math)

target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJ_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/cs/kernel)
