cmake_minimum_required(VERSION 3.5)
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

set(SDL_WRAP src/sdlWrap/Texture.hpp src/sdlWrap/Exception.hpp src/sdlWrap/Exception.cpp src/sdlWrap/Texture.cpp src/sdlWrap/sdlWrap.hpp src/sdlWrap/Window.cpp src/sdlWrap/Window.hpp src/sdlWrap/TextureUtilis.cpp src/sdlWrap/EventHanlder.hpp src/sdlWrap/utils.cpp src/sdlWrap/string/Font.cpp src/sdlWrap/string/Font.hpp)
set(PHYSIC src/physicSystem/Object.hpp src/physicSystem/Object.cpp src/physicSystem/SolidObject.cpp src/physicSystem/SolidObject.hpp src/physicSystem/CollisionHandler.hpp)

set(SOURCE_FILES src/main.cpp src/game/game.cpp src/game/game.hpp src/game/handlers/handlers.cpp src/game/handlers/handlers.hpp)

add_executable(spaceInvaders ${SDL_WRAP} ${PHYSIC} ${UTILS} ${SOURCE_FILES})
target_link_libraries(spaceInvaders ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY})

# COPY ASSETTs
file(COPY asset/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/asset)
