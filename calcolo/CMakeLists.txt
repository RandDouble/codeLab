# CMakeList.txt : CMake project for calcolo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("calcolo")

# Add source to this project's executable.
add_executable (calcolo "main.cpp" "function.cpp" "dati.cpp" "arrayDati.cpp")

# TODO: Add tests and install targets if needed.
configure_file (prova1.dat prova1.dat COPYONLY)
