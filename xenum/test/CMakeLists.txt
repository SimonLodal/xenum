include_directories(
	inc
	../lib/inc
)

file(GLOB XENUM_TEST_HDRS
	inc/test/xenum/*.hpp
	inc/test/xenum/xenums/*.hpp
	)
file(GLOB XENUM_TEST_SRCS
	src/*.cpp
	src/xenums/*.cpp
	)

set(GTEST_ROOT /usr/src/gtest)
include_directories(${GTEST_ROOT})
include_directories(${GTEST_ROOT}/include)
link_directories(${GTEST_ROOT})
#find_library(GTEST gtest)
#find_library(GTEST_MAIN gtest_main)

add_executable(xenum3-test ${XENUM_TEST_HDRS} ${XENUM_TEST_SRCS})
target_link_libraries(xenum3-test gtest gtest_main
	# Not a library anymore, only headers.
	#xenum
	)

#install(TARGETS xenum-test
#	RUNTIME DESTINATION bin
#	LIBRARY DESTINATION lib
#	)

add_test(
	NAME xenum3-test
	COMMAND xenum3-test
)

