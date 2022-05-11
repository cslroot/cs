message(STATUS "generate installer")

add_executable(cs.installer main.cpp)
set(CPACK_GENERATOR WIX)

install(TARGETS cs.installer DESTINATION bin)
install(FILES main.cpp DESTINATION src)

set(CPACK_WIX_UPGRADE_GUID "049F0A4C-8AD7-4471-A0B4-03E2570EAACE")

include(CPack)
