cmake_minimum_required(VERSION 3.10)
project(ChessGame)

# Use C++11
set(CMAKE_CXX_STANDARD 11)

# Find all your source files
set(SOURCES 
    main.cpp 
    piece.cpp 
    plateau.cpp 
    partie.cpp 
    joueur.cpp
)

# Create the executable
add_executable(echecs ${SOURCES})

target_compile_options(echecs PRIVATE -Wall -Wextra)