//
//  templates.h
//  cpp-test
//
//  Created by John Pape on 8/18/23.
//

#ifndef templates_h
#define templates_h

#include <cstdio>
#include <cstddef>
#include <concepts>

template<typename X, typename Y, typename Z>
struct MyTemplateClass {
    X foo(Y&);
    
private:
    Z* member;
    
};

template <typename X, typename Y, typename Z>
X my_template_function(Y& arg1, const Z* arg2) {
    
}

//uses const_cast to remove const modifier on encased_solo int reference
void carbon_thaw(const int& encased_solo){
    //encased_solo++;
    auto& hibernation_sick_solo = const_cast<int&>(encased_solo);
    hibernation_sick_solo++;
}

short increment_as_short(void* target){
    auto as_short = static_cast<short*>(target);
    *as_short = *as_short + 1;
    return *as_short;
}

template<typename T>
concept Averageable = requires(T a, T b) {
    { a += b };
    { a / size_t{1} };
} && std::is_default_constructible<T>::value ;


template<Averageable T>
T mean(const T* values, size_t length){
    T result{};
    for(size_t i{}; i<length; i++){
        result += values[i];
    }
    return result / length;
    
}

// using requires directly in a template function
template<typename T>
    requires std::is_copy_constructible<T>::value
T get_copy(T* pointer){
    if (!pointer) throw std::runtime_error("Null pointer dereference!!");
    return *pointer;
}


#endif /* templates_h */
