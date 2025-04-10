#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility> // std::exchange
using namespace std;

#include "simpleString.h"

bool SimpleString::equal_to(const SimpleString &other, bool case_sensitive) const {
    if (this == &other) return true;
    if (size_ != other.size_) return false;

    for (std::size_t i = 0; i < size_; i++) {
        char a = data_[i];
        char b = other.data_[i];

        if (case_sensitive) {
            a = std::tolower(static_cast<unsigned char>(a));
            b = std::tolower(static_cast<unsigned char>(b));
        }
        if (a != b) return false;
    }
    return true;
}


void SimpleString::assign(const char *text) {
    SimpleString copy(text);
    swap(copy);
}


void SimpleString::swap(SimpleString &other) {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(data_, other.data_);
}
