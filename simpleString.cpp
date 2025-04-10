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

        if (!case_sensitive) {
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


void SimpleString::swap(SimpleString &other) noexcept {
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


SimpleString SimpleString::substr(std::size_t start, std::size_t count) const {
    if (start >= size_)
        return SimpleString();

    std::size_t max_count = std::min(count, size_ - start);
    char* sub_data_ = new char[max_count + 1];
    memcpy(sub_data_, data_ + start, max_count);
    sub_data_[max_count] = '\0';

    SimpleString result(sub_data_);
    delete [] sub_data_;

    return result;
}


int SimpleString::compare(const SimpleString &other, bool case_sensitive) const {
    if (equal_to(other, case_sensitive)) return 0;

    std::size_t min_size = size_ < other.size_ ? size_ : other.size_;
    for (std::size_t i = 0; i < min_size; i++) {
        char a = data_[i];
        char b = other.data_[i];

        if (!case_sensitive) {
            a = std::tolower(static_cast<unsigned char>(a));
            b = std::tolower(static_cast<unsigned char>(b));
        }
        if (a < b)
            return -1;
        if (a > b)
            return 1;
    }
    return size_ - other.size_ ;
}
