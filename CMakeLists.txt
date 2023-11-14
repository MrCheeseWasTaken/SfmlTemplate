cmake_minimum_required(VERSION 3.21)
set(PROJECT_NAME Game)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

# Default to release builds
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB_RECURSE source_files
   src/*.cpp
   src/*.hpp
   src/**/*.cpp
   src/**/*.hpp
)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} ${source_files})
target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib" "res" "src")
target_link_libraries(${PROJECT_NAME}
   ${CMAKE_SOURCE_DIR}/lib/libsfml-system.a
   ${CMAKE_SOURCE_DIR}/lib/libsfml-window.a 
   ${CMAKE_SOURCE_DIR}/lib/libsfml-graphics.a 
   ${CMAKE_SOURCE_DIR}/lib/libsfml-audio.a 
   opengl32
)

if (UNIX)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)

# Copy data dir to the binary directory
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/res" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
