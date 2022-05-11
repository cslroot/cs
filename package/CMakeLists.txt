message(STATUS "generate installer")

# project(cs.install)

# TODO: #6 support cpack...
add_executable(cs.installer main.cpp)
set(CPACK_GENERATOR WIX)

install(TARGETS cs.core  RUNTIME_DEPENDENCIES 
PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
RUNTIME DESTINATION bin)
install(TARGETS cs.base RUNTIME DESTINATION bin)
install(TARGETS cs.kernel RUNTIME DESTINATION bin)
install(TARGETS cs.app  RUNTIME_DEPENDENCIES 
PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
RUNTIME DESTINATION bin)

install(TARGETS cs.math RUNTIME DESTINATION bin)
install(TARGETS cs.drawing RUNTIME DESTINATION bin)
install(TARGETS cs.modeler  RUNTIME_DEPENDENCIES 
PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
RUNTIME DESTINATION bin)

install(TARGETS cs.render 
  RUNTIME_DEPENDENCIES 
    PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
    POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
  RUNTIME DESTINATION bin)
install(TARGETS cs.examples.simple
  RUNTIME_DEPENDENCIES 
    PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
    POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
  RUNTIME DESTINATION bin)
# file(GET_RUNTIME_DEPENDENCIES)
# install(DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} DESTINATION bin)

set(CPACK_PACKAGE_NAME "cs")
set(CPACK_PACKAGE_VENDOR "net.savethebunny.cs")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "CS - Application framework")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "cs")

set(CPACK_WIX_UPGRADE_GUID "049F0A4C-8AD7-4471-A0B4-03E2570EAACE")

include(CPack)
