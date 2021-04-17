cmake_minimum_required(VERSION 3.18)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_BUILD_TYPE "Debug")

# set the project name
project(HoloWare)

# find SFML components
find_package(SFML 2.4 COMPONENTS graphics window system audio REQUIRED)

set(SOURCES)

add_subdirectory(Lib)
add_subdirectory(Ina_Transition)
add_subdirectory(Kiara_Loading_Minigame)
add_subdirectory(Korone_Yubi_Minigame)

# add the executable
add_executable(HoloWare ${SOURCES})

target_link_directories(HoloWare PUBLIC "${HoloWare_SOURCE_DIR}/Lib")
target_link_directories(HoloWare PUBLIC "${HoloWare_SOURCE_DIR}/Ina_Transition")
target_link_directories(HoloWare PUBLIC "${HoloWare_SOURCE_DIR}/Kiara_Loading_Minigame")
target_link_directories(HoloWare PUBLIC "${HoloWare_SOURCE_DIR}/Korone_Yubi_Minigame")

# link SFML libraries
target_link_libraries(HoloWare sfml-graphics sfml-window sfml-system sfml-audio)