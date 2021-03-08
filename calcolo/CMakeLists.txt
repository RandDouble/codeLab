cmake_minimum_required(VERSION 3.8)
project("calcolo.exe")

include(CTest)
enable_testing()

add_executable(calcolo "main.cpp" "dati.cpp" "function.cpp" "arrayDati.cpp")

include_directories(calcoloLib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
