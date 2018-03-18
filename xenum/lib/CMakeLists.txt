# Note: No source files anymore, only headers; no library to distribute.

include_directories(
	inc
)

file(GLOB XENUM_LIB_HDRS_ROOT
	inc/xenum3/*.hpp
)
file(GLOB XENUM_LIB_HDRS_IMPL
	inc/xenum3/impl/*.hpp
)
set(XENUM_LIB_HDRS
	${XENUM_LIB_HDRS_ROOT}
	${XENUM_LIB_HDRS_IMPL}
	)
file(GLOB XENUM_LIB_SRCS
	src/*.cpp
	)

#add_library(xenum ${XENUM_LIB_HDRS} ${XENUM_LIB_SRCS})
#target_link_libraries(xenum)

# Defining VERSION causes the binary to be installed as "xenum-$VERSION",
# with "xenum" as a symlink to it.
#set_target_properties(
#	xenum
#	PROPERTIES
#	VERSION "${APP_VERSION}"
#	)

#install(TARGETS xenum
#	RUNTIME DESTINATION bin
#	LIBRARY DESTINATION lib
#	)
install(FILES ${XENUM_LIB_HDRS_ROOT}
	DESTINATION include/xenum3
	)
install(FILES ${XENUM_LIB_HDRS_IMPL}
	DESTINATION include/xenum3/impl
	)
