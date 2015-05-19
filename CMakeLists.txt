cmake_minimum_required(VERSION 2.4)

project(Tetris3d)

file(COPY data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES
	src/*.cpp src/*.h
)

add_executable(Tetris3d ${SOURCE_FILES})

find_package(SDL REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(    ${SDL_INCLUDE_DIR} 
                        ${SDLTTF_INCLUDE_DIR}
                        ${SDLMIXER_INCLUDE_DIR}
                        ${OPENGL_INCLUDE_DIRS}
                    )

target_link_libraries(Tetris3d ${SDL_LIBRARY} ${SDLTTF_LIBRARY} ${SDLMIXER_LIBRARY} ${OPENGL_LIBRARIES})
