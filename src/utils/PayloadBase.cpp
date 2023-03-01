//
// Created by xyfuture on 2023/3/1.
//

#include "PayloadBase.h"

PayloadBase::PayloadBase() = default;

PayloadBase::~PayloadBase() = default;

std::ostream &operator<<(std::ostream & out, PayloadBase & self) {
    out << self.getContent() ;
    return out;
}
