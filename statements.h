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
#include <type_traits>
#include <stdexcept>

namespace Fruit::Red {
    enum class Berries {
        Strawberry,
        Raspberry,
        Shnozberry
    };
}

//structured bindings, unpacking PODs
struct TextFile {
    bool success;
    const char* contents;
    size_t n_bytes;
};

TextFile read_text_file(const char* path){
    const static char contents[] = "Somestimes you're the goat.";
    return TextFile{true, contents, sizeof(contents)};
}

[[noreturn]] void toss_knuckleball(){
    throw std::runtime_error("Knuckleball!!");
}

void randomize(uint32_t& x){
    x = 0x3FFFFFFF & (0x41C64E6D * x + 12345) % 0x80000000;
}

template<typename T>
    requires std::is_integral<T>::value
constexpr const char* sign(const T x) {
    const char* result;
    if (x > 0){
        result = "positive";
    } else if (x == 0){
        result = "zero";
    } else {
        result = "negative";
    }
    
    return result;
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

template<typename T>
auto value_of(T x) {
    if constexpr (std::is_pointer<T>::value) {
        if (!x){
            throw new std::runtime_error{"nullptr deref!"};
        } else {
            return *x;
        }
    } else {
        return x;
    }
}



#endif /* statements_h */
