cmake_minimum_required(VERSION 3.0.0)
project(project1 VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 14)

add_executable(project6 project6.cpp source_files/room.cpp source_files/player.cpp source_files/normal.cpp source_files/tools.cpp source_files/locking.cpp source_files/magic.cpp source_files/building.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)