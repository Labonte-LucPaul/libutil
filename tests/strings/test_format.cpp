//   *MIT License
//
//  Copyright (c) 2020 Luc Paul Labonté
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <string>

#include "strings/format.h"

TEST_CASE("String only.", "[strings::format]") {
    constexpr auto exp = "test";
    const auto str = libutil::format("test");
    REQUIRE(str == exp);
}

TEST_CASE("String cat const char", "[strings::format]") {
    constexpr auto exp = "test str";
    const auto str = libutil::format("test {}", "str");
    REQUIRE(str == exp);
}

TEST_CASE("String cat std::string", "[strings::format]") {
    constexpr auto exp = "test str";
    const auto str = libutil::format("test {}", std::string("str"));
    REQUIRE(str == exp);
}

TEST_CASE("String with int.", "[strings::format]") {
    constexpr auto exp = "test 42";
    const auto str = libutil::format("test {}", 42);
    REQUIRE(str == exp);
}

TEST_CASE("String double.", "[strings::format]") {
    constexpr auto exp = "test 666.77";
    const auto str = libutil::format("test {}", 666.77);
    REQUIRE(str == exp);

    constexpr auto exp2 = "test 23.3";
    const auto str2 = libutil::format("test {}", 23.3);
    REQUIRE(str2 == exp2);
}

TEST_CASE("String float.", "[strings::format]") {
    constexpr auto exp = "test 3.200000";
    const auto str = libutil::format("test {}", 3.2f);
    REQUIRE(str == exp);
}

TEST_CASE("String with curl braces.", "[strings::format]") {
    constexpr auto exp = R"(body: {"body": "value"}.)";
    const auto str = libutil::format("body: {}{}", R"({"body": "value"})", ".");
    REQUIRE(str == exp);
}

TEST_CASE("String char", "[strings::format]") {
    constexpr auto exp = "char a";
    const auto str = libutil::format("char {}", 'a');
    REQUIRE(str == exp);

    const auto exp2 = "char 2 with string and a";
    const auto str2 = libutil::format("{} {} with {} and {}", "char", '2', "string", 'a');
    REQUIRE(str2 == exp2);

    constexpr auto exp3 = "2";
    const auto str3 = libutil::format("{}", '2');
    REQUIRE(str3 == exp3);
}
