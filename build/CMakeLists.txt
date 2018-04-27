project(xenum)
cmake_minimum_required(VERSION 2.8)
set(APP_VERSION "5.0")

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
	set(PP_BASE_DIR ${CMAKE_BINARY_DIR}/pp)
	set(XENUMS_IN_DIR ${XENUM_ROOT_DIR}/xenum/test/inc/test/xenum/xenums)
	set(XENUMS_PP_DIR ${PP_BASE_DIR}/test/xenum/xenums)

	#MESSAGE("XENUM_ROOT_DIR = '${XENUM_ROOT_DIR}'")
	#MESSAGE("DOX_CFG_DIR = '${DOX_CFG_DIR}'")

	# doxygen.conf.in configures it to place output here.
	set(DOX_DST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dox)

	# doxygen.conf.in configures it to parse source files in these dirs.
	set(DOX_INC_DIRS "")
	set(DOX_SRC_DIRS "${DOX_CFG_DIR}")

	set(DOX_INC_DIRS "${DOX_INC_DIRS} ${XENUM_ROOT_DIR}/xenum/lib/inc")
	set(DOX_SRC_DIRS "${DOX_SRC_DIRS} ${XENUM_ROOT_DIR}/xenum/lib")

	set(DOX_INC_DIRS "${DOX_INC_DIRS} ${XENUM_ROOT_DIR}/xenum/test/inc")
	set(DOX_SRC_DIRS "${DOX_SRC_DIRS} ${XENUM_ROOT_DIR}/xenum/test/src")

	# Argh. doxygen trouble in so many ways...
	# If added as include files they are just ignored.
	# If added as input files, they are of course included. However...
	# - They easily conflict with the original header files.
	# - They are not recognized as headers at all.
	# - They appear in the file list, but the link leads to the original header,
	#   not the preprocessed one.
	# - The build/pp dir has to be added manually to STRIP_FROM_INC_PATH since
	#   it is not an include dir.
	# Headache...
	#set(DOX_INC_DIRS "${DOX_INC_DIRS} ${PP_BASE_DIR}")
	set(DOX_SRC_DIRS "${DOX_SRC_DIRS} ${PP_BASE_DIR}")

	set(DOX_SRC_DIRS "${DOX_SRC_DIRS} ${XENUM_ROOT_DIR}/docs")

#	file(GLOB_RECURSE XENUM_FILES ${XENUM_ROOT_DIR}/xenum/lib/*.hpp)

	set(DOX_INC_DIRS_STRIP "${DOX_INC_DIRS} ${PP_BASE_DIR}")

	#MESSAGE("DOX_INC_DIRS = '${DOX_INC_DIRS}'")
	#MESSAGE("DOX_SRC_DIRS = '${DOX_SRC_DIRS}'")
	#MESSAGE("XENUM_FILES = '${XENUM_FILES}'")

	file(MAKE_DIRECTORY ${XENUMS_PP_DIR})
	add_custom_command(
		OUTPUT ${XENUMS_PP_DIR}/FruitsInNsInCls.hpp
		WORKING_DIRECTORY ${XENUM_ROOT_DIR}
		COMMAND util/xenum5-inject
		ARGS -i ${XENUMS_IN_DIR}/FruitsInNsInCls.hpp -o ${XENUMS_PP_DIR}/FruitsInNsInCls.hpp
		DEPENDS ${XENUMS_IN_DIR}/FruitsInNsInCls.hpp
		COMMENT "Preprocessing FruitsInNsInCls.hpp ..."
		VERBATIM
	)
	add_custom_command(
		OUTPUT ${XENUMS_PP_DIR}/FruitsInNsNoCls.hpp
		WORKING_DIRECTORY ${XENUM_ROOT_DIR}
		COMMAND util/xenum5-inject
		ARGS -i ${XENUMS_IN_DIR}/FruitsInNsNoCls.hpp -o ${XENUMS_PP_DIR}/FruitsInNsNoCls.hpp
		DEPENDS ${XENUMS_IN_DIR}/FruitsInNsNoCls.hpp
		COMMENT "Preprocessing FruitsInNsNoCls.hpp ..."
		VERBATIM
	)
	add_custom_command(
		OUTPUT ${XENUMS_PP_DIR}/FruitsNoNsInCls.hpp
		WORKING_DIRECTORY ${XENUM_ROOT_DIR}
		COMMAND util/xenum5-inject
		ARGS -i ${XENUMS_IN_DIR}/FruitsNoNsInCls.hpp -o ${XENUMS_PP_DIR}/FruitsNoNsInCls.hpp
		DEPENDS ${XENUMS_IN_DIR}/FruitsNoNsInCls.hpp
		COMMENT "Preprocessing FruitsNoNsInCls.hpp ..."
		VERBATIM
	)
	add_custom_command(
		OUTPUT ${XENUMS_PP_DIR}/FruitsNoNsNoCls.hpp
		WORKING_DIRECTORY ${XENUM_ROOT_DIR}
		COMMAND util/xenum5-inject
		ARGS -i ${XENUMS_IN_DIR}/FruitsNoNsNoCls.hpp -o ${XENUMS_PP_DIR}/FruitsNoNsNoCls.hpp
		DEPENDS ${XENUMS_IN_DIR}/FruitsNoNsNoCls.hpp
		COMMENT "Preprocessing FruitsNoNsNoCls.hpp ..."
		VERBATIM
	)
	add_custom_command(
		OUTPUT ${XENUMS_PP_DIR}/Icmp.hpp
		WORKING_DIRECTORY ${XENUM_ROOT_DIR}
		COMMAND util/xenum5-inject
		ARGS -i ${XENUMS_IN_DIR}/Icmp.hpp -o ${XENUMS_PP_DIR}/Icmp.hpp
		DEPENDS ${XENUMS_IN_DIR}/Icmp.hpp
		COMMENT "Preprocessing Icmp.hpp ..."
		VERBATIM
	)
	add_custom_command(
		OUTPUT ${XENUMS_PP_DIR}/Numbers.hpp
		WORKING_DIRECTORY ${XENUM_ROOT_DIR}
		COMMAND util/xenum5-inject
		ARGS -i ${XENUMS_IN_DIR}/Numbers.hpp -o ${XENUMS_PP_DIR}/Numbers.hpp
		DEPENDS ${XENUMS_IN_DIR}/Numbers.hpp
		COMMENT "Preprocessing Numbers.hpp ..."
		VERBATIM
	)
	add_custom_command(
		OUTPUT ${XENUMS_PP_DIR}/Pcombs.hpp
		WORKING_DIRECTORY ${XENUM_ROOT_DIR}
		COMMAND util/xenum5-inject
		ARGS -i ${XENUMS_IN_DIR}/Pcombs.hpp -o ${XENUMS_PP_DIR}/Pcombs.hpp
		DEPENDS ${XENUMS_IN_DIR}/Pcombs.hpp
		COMMENT "Preprocessing Pcombs.hpp ..."
		VERBATIM
	)

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
		DEPENDS ${XENUMS_PP_DIR}/FruitsInNsInCls.hpp
		DEPENDS ${XENUMS_PP_DIR}/FruitsInNsNoCls.hpp
		DEPENDS ${XENUMS_PP_DIR}/FruitsNoNsInCls.hpp
		DEPENDS ${XENUMS_PP_DIR}/FruitsNoNsNoCls.hpp
		DEPENDS ${XENUMS_PP_DIR}/Icmp.hpp
		DEPENDS ${XENUMS_PP_DIR}/Numbers.hpp
		DEPENDS ${XENUMS_PP_DIR}/Pcombs.hpp
		COMMENT "Generating documentation (doxygen) ..."
		VERBATIM
	)
	add_custom_target(doc DEPENDS ${DOX_DST_DIR})
	install(
		DIRECTORY ${DOX_DST_DIR}/html/
		DESTINATION share/doc/xenum5/api
		OPTIONAL
		)
else()
	message(WARNING "Doxygen not found, can not generate API documentation.")
endif(DOXYGEN_FOUND)
