cmake_minimum_required(VERSION 2.6)

file(GLOB HEADERFILES_H "${CMAKE_CURRENT_SOURCE_DIR}/RtORB/*.h")

file(GLOB HEADERFILES_HH "${CMAKE_CURRENT_SOURCE_DIR}/RtORB/*.hh")


install(FILES ${HEADERFILES_H} ${HEADERFILES_HH} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/RtORB)

file(GLOB HEADERFILES_FUNC_H "${CMAKE_CURRENT_SOURCE_DIR}/RtORB/functions/*.h")
file(GLOB HEADERFILES_FUNC_HH "${CMAKE_CURRENT_SOURCE_DIR}/RtORB/functions/*.hh")

install(FILES ${HEADERFILES_FUNC_H} ${HEADERFILES_FUNC_HH} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/RtORB/functions)
add_subdirectory(RtORB)
