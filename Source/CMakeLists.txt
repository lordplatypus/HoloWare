cmake_minimum_required(VERSION 3.10)

# set the project name
project(HoloWare)

# set path to findSFML.cmake file
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules")

# find SFML components
find_package(SFML 2.4 COMPONENTS graphics window system audio REQUIRED)

# list .cpp files
set(SOURCES main.cpp LP.cpp MP.cpp Game.cpp SceneTitle.cpp LoadAssets.cpp GameObject.cpp GameObjectManager.cpp KiaraChickenKiara.cpp KiaraChickenSpawner.cpp 
KiaraChickenChicken.cpp KiaraChickenScore.cpp KiaraChickenPoints.cpp KiaraChickenScene.cpp InaTransitionScene.cpp Camera.cpp Math.cpp InaTransitionDoor.cpp InaTransitionDoorOpen.cpp 
InaTransitionDoorClose.cpp InaTransitionHP.cpp InaTransitionLoading.cpp InaTransitionTimer.cpp KoroneYubiScene.cpp KoroneYubiHand.cpp KoroneYubiManager.cpp 
KoroneYubiStream.cpp MiniGameManager.cpp)

# add the executable
add_executable(HoloWare ${SOURCES}) 

# link SFML libraries
target_link_libraries(HoloWare sfml-graphics sfml-window sfml-system sfml-audio)