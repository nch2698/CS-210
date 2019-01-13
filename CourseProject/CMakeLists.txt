set(BUILD_CP CourseProject)
set(HEADER_FILES models.h config.h menu.h storage.h util.h)
set(SOURCE_FILES_CP main.cpp menu.cpp storage.cpp util.cpp)
add_executable(${BUILD_CP} ${HEADER_FILES} ${SOURCE_FILES_CP})