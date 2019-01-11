set(BUILD_CP CourseProject)
set(HEADER_FILES models.h config.h menu.h)
set(SOURCE_FILES_CP main.cpp get_infos.cpp menu.cpp)
add_executable(${BUILD_CP} ${HEADER_FILES} ${SOURCE_FILES_CP})