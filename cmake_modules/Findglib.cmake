#hogehogehoge

if(UNIX)
  if("${OS_NAME}" MATCHES "Linux")
    find_package(PkgConfig REQUIRED)
    pkg_search_module(GLIB REQUIRED glib-2.0)
    set(GLIB_LIBRARIES ${GLIB_LIBRARIES})
    set(GLIB_INCLUDE_DIRS ${GLIB_INCLUDE_DIRS})
  else()
    if(NOT IDL_LIBRARY_DIRS)
      find_library(
        IDL_LIBRARY IDL-2
        PATHS PATHS /usr/lib/ /home/lib/ /usr/local/lib/ /lib/
        NO_DEFAULT_PATH)

     if(NOT IDL_LIBRARY)
       MESSAGE(FATAL_ERROR "STOP CMAKE ---> Install libIDL package.......")
        find_library(IDL_LIBRARY IDL)
     endif()
 
     if(IDL_LIBRARY)
      get_filename_component(IDL_LIBRARY_DIRS ${IDL_LIBRARY} PATH)
      message(STATUS "detected ${IDL_LIBRARY}")
     else()
        message(STATUS "NOT detected ${IDL_LIBRARY}")
     endif()
    endif()
  endif()

endif(UNIX)




