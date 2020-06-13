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

#ifndef LIBUTIL_STRINGS_FORMAT_H
#define LIBUTIL_STRINGS_FORMAT_H

#include <cctype>
#include <regex>
#include <string>
#include <vector>

#include <iostream>

namespace libutil {

std::string format(const char* str) {
    std::cout << "const char\n";
    return std::string(str);
}

std::string convert(const char* t) { return t; }
std::string convert(char c) { return std::string(1, c); }

std::string convert(double d) {
    std::string s = std::to_string(d);
    s.erase(s.find_last_not_of('0') + 1, std::string::npos);
    return s;
}

template<typename T>
std::string convert(T t) {
    return std::to_string(t);
}

template<typename T, typename... Args>
std::string format(const char* str, T value, const Args& ...args) {
    std::cout << "Template\n";
    const std::regex rx("\\{\\}");
    auto v = convert(value);
    auto ret = std::regex_replace(str, rx, v, std::regex_constants::format_first_only);
    ret = format(ret.c_str(), args...);
    return ret;
}

template <typename ... Args>
std::string format(const char* str, char value, const Args& ...args) {
    std::cout << "string\n";
    return format(str, std::string(1, value).c_str(), args...);
}

template<typename... Args>
std::string format(const char* str, const std::string &value, const Args& ...args) {
    std::cout << "main\n";
    return format(str, value.c_str(), args...);
}

} // libutil

#endif // LIBUTIL_STRINGS_FORMAT_H
