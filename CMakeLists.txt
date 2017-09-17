cmake_minimum_required(VERSION 3.8)
project(spaceInvaders)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

set(UTILS utils/utils.cpp utils/utils.hpp)
set(SDL_WRAP sdlWrap/Texture.hpp sdlWrap/Exception.hpp sdlWrap/Exception.cpp sdlWrap/Texture.cpp sdlWrap/sdlWrap.hpp sdlWrap/Window.cpp sdlWrap/Window.hpp sdlWrap/TextureUtilis.cpp sdlWrap/EventHanlder.hpp sdlWrap/utils.cpp sdlWrap/string/Font.cpp sdlWrap/string/Font.hpp)
set(PHYSIC physicSystem/Object.hpp physicSystem/Object.cpp physicSystem/SolidObject.cpp physicSystem/SolidObject.hpp physicSystem/CollisionHandler.hpp)

set(SOURCE_FILES main.cpp game/game.cpp game/game.hpp game/handlers/handlers.cpp game/handlers/handlers.hpp)

add_executable(spaceInvaders ${SDL_WRAP} ${PHYSIC} ${UTILS} ${SOURCE_FILES})
target_link_libraries(spaceInvaders ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY})

# COPY ASSETTs
file(COPY asset/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/asset)
