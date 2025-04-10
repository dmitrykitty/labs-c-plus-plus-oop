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


void SimpleString::append(const SimpleString &other) {
    std::size_t new_size_ = size_ + other.size_;
    char *new_data_ = new char[new_size_ + 1];

    memcpy(new_data_, data_, size_);
    memcpy(new_data_ + size_, other.data_, other.size_);
    new_data_[new_size_] = '\0';

    delete [] data_;
    size_ = new_size_;
    capacity_ = size_ + 1;
    data_ = new_data_;
}
