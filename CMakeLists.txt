cmake_minimum_required(VERSION 3.2)

project(cetris)

file(COPY data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCE_FILES
	src/*.cpp
)


add_executable(cetris ${SOURCE_FILES})

find_package(glfw3 REQUIRED)
find_package(SDL2 REQUIRED)
SET(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2TTF   REQUIRED IMPORTED_TARGET SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED IMPORTED_TARGET SDL2_mixer>=2.0.0)

target_link_libraries(cetris
	glfw
	OpenGL::GL
    SDL2::SDL2
    PkgConfig::SDL2TTF
    PkgConfig::SDL2MIXER
)

target_compile_definitions(cetris PUBLIC D_PATH="${CMAKE_INSTALL_PREFIX}/share/cetris/")


install(TARGETS cetris RUNTIME DESTINATION bin)
install(DIRECTORY data DESTINATION share/cetris)
