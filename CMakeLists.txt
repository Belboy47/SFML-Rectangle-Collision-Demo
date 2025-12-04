cmake_minimum_required(VERSION 3.20)
project(MySFMLApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.2
)

FetchContent_MakeAvailable(sfml)

add_executable(MySFMLApp src/main.cpp)

target_include_directories(MySFMLApp PRIVATE
  ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(MySFMLApp PRIVATE
  SFML::Graphics
  SFML::Window
  SFML::System
)
