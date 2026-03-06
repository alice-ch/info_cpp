cmake_minimum_required(VERSION 3.10)
project(ChessGame)

set(CMAKE_CXX_STANDARD 11)
set(SOURCES
    main.cpp
    piece.cpp
    plateau.cpp
    partie.cpp
    joueur.cpp
)
add_executable(echecs ${SOURCES})
target_compile_options(echecs PRIVATE -Wall -Wextra)