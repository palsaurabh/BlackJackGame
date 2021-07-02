cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

find_program(CLANGTIDY clang-tidy-11)
set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} -extra-arg=-Wno-unknown-warning-option)

# set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} )

project(BlackJackMultiPlayer)

add_executable(BlackJackMultiPlayer main.cpp BlackJack.cpp)

target_link_libraries(BlackJackMultiPlayer)