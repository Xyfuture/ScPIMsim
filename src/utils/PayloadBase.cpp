//
// Created by xyfuture on 2023/3/1.
//

#include "PayloadBase.h"

std::ostream &operator<<(std::ostream & out, PayloadBase & self) {
    out << self.getContent() ;
    return out;
}

std::string PayloadBase::getContent() {
    return std::string("PayloadBase, you need to reload this function");
}
