project(xenum)
cmake_minimum_required(VERSION 2.6)

############################### COMPILER FLAGS ###############################
# Do not use -ansi, it prevents boost.prepropcessor's variadic stuff from working.
if(CMAKE_CXX_COMPILER_ID STREQUAL GNU)
	add_definitions(-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE)
	set(CFLAGS_COMMON " -Wall -Wstrict-overflow=5 -std=c++11 -Os")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CFLAGS_COMMON}")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL Clang)
	# Same as g++ options
	add_definitions(-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE)
	set(CFLAGS_COMMON " -Wall -Wstrict-overflow=5 -std=c++11 -Os")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CFLAGS_COMMON}")
else()
	message(FATAL_ERROR "Unhandled C++ compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()


################################ STD DEFINES #################################
add_definitions(-D_GNU_SOURCE)
set(BUILD_SHARED_LIBS true)
enable_testing()

################################ SUBPROJECTS #################################
set(APP_VERSION "3.0")
add_definitions(-DAPP_VERSION="${APP_VERSION}")
add_subdirectory(../xenum xenum)
