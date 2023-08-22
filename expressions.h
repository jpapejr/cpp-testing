//
//  expressions.h
//  cpp-test
//
//  Created by John Pape on 8/21/23.
//

#ifndef expressions_h
#define expressions_h

#include <stdexcept>
#include <limits>
#include <cstdio>

void print_addr(void* v){
    printf("0x%p\n", v);
}

int confusing(int &x){
    return x = 9, x++, x / 2;
}

struct CheckedInteger{
    CheckedInteger(unsigned int value) : value { value } {}
    CheckedInteger operator+(unsigned int other) const {
        CheckedInteger result { value + other };
        if (result.value < value ) throw std::overflow_error("Overflow!!");
        return result;
    }
    
    const unsigned int value;
};

//user-defined type conversion

struct MyType {
    MyType(const int val) : value {val} {}
    explicit operator int() const {  // user-defined type conversion impl
        return value;
    }
private:
    const int value;
};
struct Color {
    float H, S, V;
};

#endif /* expressions_h */
