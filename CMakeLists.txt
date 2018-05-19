#/*******************************************************************************
#
# 19-05-2018
# Lite version of CMAKE to compile get the project working on Macos High Sierra
# and to have the code autocompletion on the software CLion.
#
#/*******************************************************************************

cmake_policy(SET CMP0017 NEW)
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(APP_NAME TeamFightHeroes)
project(${APP_NAME})

set(COCOS2D_ROOT ${CMAKE_SOURCE_DIR}/cocos2d)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${COCOS2D_ROOT}/cmake/Modules/")
include(CocosBuildHelpers)


ADD_DEFINITIONS(-DCC_TARGET_OS_MAC)
ADD_DEFINITIONS(-DUSE_FILE32API)
set(PLATFORM_FOLDER mac)

add_subdirectory(${COCOS2D_ROOT})

include_directories(
        /usr/local/include/GLFW
        /usr/include/GLFW
        ${COCOS2D_ROOT}
        ${COCOS2D_ROOT}/cocos
        ${COCOS2D_ROOT}/external
        ${COCOS2D_ROOT}/cocos/platform
        ${COCOS2D_ROOT}/cocos/audio/include/
        Classes
)

# Specific project files
set(GAME_SRC ${PLATFORM_SPECIFIC_SRC} Classes/AppDelegate.cpp)
set(GAME_HEADERS ${PLATFORM_SPECIFIC_HEADERS} Classes/AppDelegate.h)
file(GLOB_RECURSE Classes/MoriorGames "*.h" "*.cpp")

set(SOURCE_FILES proj.ios_mac/mac/main.cpp)

add_executable(main ${SOURCE_FILES} ${GAME_SRC} ${GAME_HEADERS} ${Classes/MoriorGames})
