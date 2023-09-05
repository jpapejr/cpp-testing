//
//  functions.h
//  cpp-test
//
//  Created by John Pape on 8/23/23.
//

#ifndef functions_h
#define functions_h

#include <cstdio>
#include <stdexcept>
#include <cstdarg>
#include <sstream>



struct BostonCorbett {
    virtual void shoot() final {
        std::cout << "What a God we have..God avenged Abraham Lincoln!" << std::endl;
    }
};

//struct BostonCorbettJunior : BostonCorbett {
//    void shoot() override {     // cannot do this because the parent shoot() is final
//        std::cout << "What now?" << std::endl;
//    }
//};

struct Distillate {
    int apply() volatile {
        return ++applications;
    }
private:
    int applications{};
};


//template<typename T>
//constexpr T sum(T value) {
//    return value;
//}
//
//template<typename T, typename... Args>
//constexpr T sum(T first, Args... args) {
//    return first + sum(args...);
//}
//fold expression
template<typename... T>
constexpr auto sum(T... args) {
  return (... + args);
}

//another fold expression
template<typename... T>
constexpr auto subtract(T... args){
    return(... - args);
}

template<typename T>
constexpr auto print(T x){
    return x;
}

template<typename T, typename... Args>
auto print(T x, Args... args){
    std::stringstream ss;
    ss << x << " " << print(args...);
    return ss.str();
}

float add(int x, int y){
    float result{};
    result = x + y;
    return result;
}

#endif /* functions_h */
