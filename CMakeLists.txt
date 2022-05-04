cmake_minimum_required(VERSION 3.7)
project(AntlrPython)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set (CMAKE_CXX_STANDARD 17)
#required to get rid of getNextToken() issue. This issue should be resolved soon, remove when resolved.
set(ANTLR4_TAG e4c1a74)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)
# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})
# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.9.2-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(Python3Lexer Python3Lexer.g4 LEXER)
antlr_target(Python3Parser Python3Parser.g4 PARSER
             DEPENDS_ANTLR Python3Lexer
             COMPILE_FLAGS -lib ${ANTLR_Python3Lexer_OUTPUT_DIR})

# include generated files in project environment
include_directories(${ANTLR_Python3Lexer_OUTPUT_DIR})
include_directories(${ANTLR_Python3Parser_OUTPUT_DIR})

# Now build our tools
add_executable(antlr-compiler main.cpp ${ANTLR_Python3Lexer_CXX_OUTPUTS} ${ANTLR_Python3Parser_CXX_OUTPUTS})

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Link against LLVM libraries
target_link_libraries(antlr-compiler ${llvm_libs} antlr4_static)