

cmake_minimum_required(VERSION 2.6)

set(TARGET RtORB_cpp)
set(SOURCES corba.cc poa.cc CosName.cc corba-any.cc corba-exception.cc orb.cc cdrStream.cpp)

IF("${OS_NAME}" MATCHES "FreeBSD")
add_definitions(-D${OS_NAME} -DUSE_UUID)
ELSEIF("${OS_NAME}" MATCHES "Linux")
add_definitions(-D${OS_NAME} -DUSE_UUID)
ENDIF()


include_directories(/usr/include ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/lib ${CMAKE_SOURCE_DIR}/CosName ${CMAKE_BINARY_DIR}/include)

#add_definitions(-fPIC)

link_directories(${GLIB_LIBRARY_DIR} ${IDL_LIBRARY_DIR} ${CMAKE_SOURCE_DIR}/lib)


add_library(${TARGET} SHARED ${SOURCES})
add_dependencies(${TARGET} RtORB)
SET_TARGET_PROPERTIES(${TARGET} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
add_library(${TARGET}-static STATIC ${SOURCES})
add_dependencies(${TARGET}-static RtORB-static)
set_target_properties(${TARGET}-static PROPERTIES OUTPUT_NAME "RtORB_cpp")
set_target_properties(${TARGET}-static PROPERTIES PREFIX "lib")
SET_TARGET_PROPERTIES(${TARGET}-static PROPERTIES CLEAN_DIRECT_OUTPUT 1)


set(HOGE_VERSION 0)
set(HOGESOVERSION 0)
target_link_libraries(${TARGET} RtORB uuid)

#set_target_properties(${TARGET} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/)




install(TARGETS ${TARGET} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                          ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                          RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})


install(TARGETS ${TARGET}-static LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                                 ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                                 RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

