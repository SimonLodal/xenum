project(xenum)
cmake_minimum_required(VERSION 2.8)
set(APP_VERSION "4.0.pre3")

############################### COMPILER FLAGS ###############################
# Do not use -ansi, it prevents boost.prepropcessor's variadic stuff from working.
if(CMAKE_CXX_COMPILER_ID STREQUAL GNU)
	add_definitions(-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE)
	set(CFLAGS_COMMON " -Wall -Wstrict-overflow=5 -std=c++11 -Os")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CFLAGS_COMMON}")
	set(CMAKE_EXE_LINKER_FLAGS "-Wl,--no-undefined -lstdc++")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL Clang)
	# Same as g++ options
	add_definitions(-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE)
	set(CFLAGS_COMMON " -Wall -Wstrict-overflow=5 -std=c++11 -Os")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CFLAGS_COMMON}")
	# -lstdc++ required for clang-3.5 to link with exceptions enabled
	set(CMAKE_EXE_LINKER_FLAGS "-Wl,--no-undefined -lstdc++")
else()
	message(FATAL_ERROR "Unhandled C++ compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()


################################ STD DEFINES #################################
add_definitions(-D_GNU_SOURCE)
set(BUILD_SHARED_LIBS true)
enable_testing()

################################ SUBPROJECTS #################################
add_definitions(-DAPP_VERSION="${APP_VERSION}")
add_subdirectory(../xenum xenum)


########################### DOXYGEN DOCUMENTATION ############################
# NOTE: Use "make doc", not done automatically since it takes too long.
include (${CMAKE_ROOT}/Modules/FindDoxygen.cmake)

if(DOXYGEN_FOUND)
	get_filename_component(XENUM_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
	set(DOX_CFG_DIR ${XENUM_ROOT_DIR}/dox)

	#MESSAGE("XENUM_ROOT_DIR = '${XENUM_ROOT_DIR}'")
	#MESSAGE("DOX_CFG_DIR = '${DOX_CFG_DIR}'")

	# doxygen.conf.in configures it to place output here.
	set(DOX_DST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dox)

	# doxygen.conf.in configures it to parse source files in these dirs.
	set(DOX_INC_DIRS "")
	set(DOX_SRC_DIRS "${DOX_CFG_DIR}")

	set(DOX_INC_DIRS "${DOX_INC_DIRS} ${XENUM_ROOT_DIR}/xenum/lib/inc")
	set(DOX_SRC_DIRS "${DOX_SRC_DIRS} ${XENUM_ROOT_DIR}/xenum/lib")

	file(GLOB_RECURSE XENUM_FILES ${XENUM_ROOT_DIR}/xenum/lib/*.hpp)

	#MESSAGE("DOX_INC_DIRS = '${DOX_INC_DIRS}'")
	#MESSAGE("DOX_SRC_DIRS = '${DOX_SRC_DIRS}'")
	#MESSAGE("XENUM_FILES = '${XENUM_FILES}'")

	configure_file(
		"${DOX_CFG_DIR}/doxygen.conf.in"
		${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf
		@ONLY IMMEDIATE
		)
	add_custom_command(
		OUTPUT ${DOX_DST_DIR}
		COMMAND ${DOXYGEN_EXECUTABLE}
		ARGS ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf # > /dev/null
		DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf"
		DEPENDS "${DOX_CFG_DIR}/DoxygenLayout.xml"
		#DEPENDS "${XENUM_FILES}"
		COMMENT "Generating documentation (doxygen) ..."
		VERBATIM
	)
	add_custom_target(doc DEPENDS ${DOX_DST_DIR})
	install(
		DIRECTORY ${DOX_DST_DIR}/html/
		DESTINATION share/doc/xenum4/api
		OPTIONAL
		)
else()
	message(WARNING "Doxygen not found, can not generate API documentation.")
endif(DOXYGEN_FOUND)
