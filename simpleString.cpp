#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility> // std::exchange
using namespace std;

#include "simpleString.h"

bool SimpleString::equal_to(const SimpleString &other, bool case_sensitive) const {
    if (this == &other) return true;
    if (size_ == other.size_ && capacity_ == other.capacity_) {
        for (std::size_t i = 0; i < size_; i++) {
            if (data_[i] != other.data_[i]) return false;
        }
        return true;
    }
    return false;
}
