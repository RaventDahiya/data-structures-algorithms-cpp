project(C++ Data Structures and Algorithms)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

file(GLOB_RECURSE SOURCES
    src/arrays/*.cpp
    src/linked_lists/*.cpp
    src/stacks/*.cpp
    src/queues/*.cpp
    src/trees/*.cpp
    src/graphs/*.cpp
    src/sorting/*.cpp
)

add_executable(data_structures_algorithms ${SOURCES})