#   *MIT License
#
#  Copyright (c) 2020 Luc Paul Labonté
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.

cmake_minimum_required(VERSION 3.16)
project(libutil)

set(CMAKE_CXX_STANDARD 17)

set(LIB
        src/libutil.cpp
        src/strings/format.h
)

set(TESTS
    ${LIB}
    tests/catch.hpp
    tests/strings/test_format.cpp
)


add_library(libutil ${LIB})

add_executable(libutil_tests ${TESTS})
target_include_directories(libutil_tests PUBLIC ${PROJECT_SOURCE_DIR}/tests ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(libutil_tests PUBLIC)
