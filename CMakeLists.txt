
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# set the project name

project(misc
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(treeSO main/main.cpp src/Item.cpp src/treeSOListItem.cpp src/treeSOList.cpp src/treeSO.cpp src/indexList.cpp src/indexNode.cpp)
target_include_directories(treeSO PUBLIC ${PROJECT_SOURCE_DIR}/include)



# add the executable