cmake_minimum_required(VERSION 3.10)
project(SDL_Game)

if(APPLE)
    set(CMAKE_MACOSX_BUNDLE ON)
endif()
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)
set(SDL_STATIC ON)
set(SDL_SHARED OFF)
set(SDL_X11 OFF)

add_subdirectory(SDL)
add_subdirectory(SDL_image)

add_executable(sdl_gamev1 MACOSX_BUNDLE main.c)
if(APPLE)
    set_source_files_properties(resources/ds4_retro_art.icns PROPERTIES
        MACOSX_PACKAGE_LOCATION "Resources"
    )

    set_target_properties(sdl_gamev1 PROPERTIES
        MACOSX_BUNDLE_ICON_FILE "ds4_retro_art.icns"
    )
endif()

target_link_libraries(sdl_gamev1 SDL3_image::SDL3_image SDL3::SDL3)
