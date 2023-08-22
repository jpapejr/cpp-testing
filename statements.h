//
//  statements.h
//  cpp-test
//
//  Created by John Pape on 8/22/23.
//
#ifndef statements_h
#define statements_h

#include <cstdio>
#include <cstdint>

namespace Fruit::Red {
    enum class Berries {
        Strawberry,
        Raspberry,
        Shnozberry
    };
}


void randomize(uint32_t& x){
    x = 0x3FFFFFFF & (0x41C64E6D * x + 12345) % 0x80000000;
}


struct RandomNumberGenerator {
    explicit RandomNumberGenerator(uint32_t v) : value{ v } {}
    uint32_t next() {
        uint32_t value{0x3FFFFFFF & (0x41C64E6D * value + 12345) % 0x80000000};
        increment_iterations();
        return value;
    }
    size_t get_iterations(){
        return iterations;
    }
    void increment_iterations(){
        ++iterations;
    }
    
    void decrement_iterations();
private:
    unsigned int value;
    unsigned int iterations;
};

//could be in a completely diff source file/compilation unit

void RandomNumberGenerator::decrement_iterations() {
    --iterations;
}


#endif /* statements_h */
