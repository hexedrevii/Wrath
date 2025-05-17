cmake_minimum_required(VERSION 3.15)
project(Bweakout LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Asan and Atan for debug builds.
if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(SANITIZER_FLAGS "-fsanitize=address,undefined -fno-omit-frame-pointer")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SANITIZER_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")
endif()

find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC
  wrath/lib.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System
)
