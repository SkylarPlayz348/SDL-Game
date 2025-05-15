cmake_minimum_required(VERSION 3.10)

project(SDL_Game)

set(SDL_STATIC ON)
set(SDL_SHARED OFF)
set(SDL_X11 OFF)
add_subdirectory(SDL)
add_subdirectory(SDL_image)
add_executable(sdl_gamev1 main.c)
target_link_libraries(sdl_gamev1 SDL3_image::SDL3_image-static SDL3::SDL3-static)