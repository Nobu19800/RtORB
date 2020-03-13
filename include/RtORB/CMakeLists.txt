cmake_minimum_required(VERSION 2.6)


set(CONFIGFILE ${CMAKE_BINARY_DIR}/include/RtORB/config_rtorb.h)
add_custom_command(OUTPUT ${CONFIGFILE}
  COMMAND ${CMAKE_SOURCE_DIR}/tools/gen_config ${OS_NAME}
  DEPENDS ${CMAKE_SOURCE_DIR}/tools/gen_config
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  )
add_custom_target(gen_config DEPENDS ${CONFIGFILE})
install(FILES ${CONFIGFILE} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/RtORB)

add_dependencies(RtORB gen_config)
add_dependencies(RtORB-static gen_config)
