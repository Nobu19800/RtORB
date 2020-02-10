
cmake_minimum_required(VERSION 2.6)
set(TARGET RtORB)

set(OUTPUT_HEADERS
    ${CMAKE_CURRENT_BINARY_DIR}/CosName/CosNaming.h
)

set(OUTPUT_SOURCES
    ${CMAKE_CURRENT_BINARY_DIR}/CosName/CosNaming-common.c
    ${CMAKE_CURRENT_BINARY_DIR}/CosName/CosNaming-stubs.c
    ${OUTPUT_HEADERS}
    ${CMAKE_CURRENT_BINARY_DIR}/CosName/CosNaming-skels.c)
    #${CMAKE_SOURCE_DIR}/CosName/NameService_impl.c)

set(SOURCES 
	socket.c
	hashtable.c
	list.c
	array.c
	util.c
	endian.c
	allocater.c
	iop.c
	giop.c
	giop-msg.c
	giop-marshal.c
	orb.c
	corba.c
	corba-typecode.c
	corba-exception.c 
	corba-sequence.c 
	corba-any.c 
	poa.c 
        rtorb.c 
	connection.c 
	server_loop.c
        ./CosName/NameService_impl.c
	${OUTPUT_SOURCES}
 )

	#pthread.c

set(IDL_EXE ${CMAKE_BINARY_DIR}/idl-compiler/rtorb-idl)
set(IDL_SOURCES ${CMAKE_SOURCE_DIR}/idl/CosNaming.idl)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CosName)

add_custom_command( OUTPUT ${OUTPUT_SOURCES}
  COMMAND ${IDL_EXE} ${IDL_SOURCES}
  COMMAND ${IDL_EXE} --skeleton-impl ${IDL_SOURCES}
  DEPENDS iop.c 
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CosName
  )



IF("${OS_NAME}" MATCHES "FreeBSD")
add_definitions(-D${OS_NAME} -DUSE_UUID -fPIC -O2)
ELSEIF("${OS_NAME}" MATCHES "Linux")
add_definitions(-D${OS_NAME} -fPIC -O2)
ELSEIF("${OS_NAME}" MATCHES "CYGWIN_NT-5.1")
add_definitions(-DCygwin -DUSE_UUID -fPIC -O2)
ENDIF()


IF("${OS_NAME}" MATCHES "CYGWIN_NT-5.1")

link_directories(${GLIB_LIBRARY_DIRS} ${IDL_LIBRARY_DIRS} ${UUID_LIBRARY_DIRS})
add_library(${TARGET} SHARED ${SOURCES})
ELSE()
link_directories(${GLIB_LIBRARY_DIRS} ${IDL_LIBRARY_DIRS} ${UUID_LIBRARY_DIRS})
add_library(${TARGET} SHARED ${SOURCES})
SET_TARGET_PROPERTIES(${TARGET} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
add_library(${TARGET}-static STATIC ${SOURCES})
set_target_properties(${TARGET}-static PROPERTIES OUTPUT_NAME "RtORB")
set_target_properties(${TARGET}-static PROPERTIES PREFIX "lib")
SET_TARGET_PROPERTIES(${TARGET}-static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
ENDIF()

target_compile_options(${TARGET} PRIVATE $<$<CONFIG:Debug>:-O0>)

include_directories(/usr/include ${GLIB_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/lib  ${CMAKE_CURRENT_BINARY_DIR})


IF("${OS_NAME}" MATCHES "FreeBSD")
target_link_libraries(${TARGET} uuid)
ELSEIF("${OS_NAME}" MATCHES "CYGWIN_NT-5.1")
target_link_libraries(${TARGET} uuid)
ELSEIF("${OS_NAME}" MATCHES "Linux")
target_link_libraries(${TARGET} uuid ${GLIB_LIBRARIES})
ENDIF()

install(TARGETS ${TARGET} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                          ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                          RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(TARGETS ${TARGET}-static LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                                 ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                                 RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES ${OUTPUT_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/CosName)

add_subdirectory(CXX)
