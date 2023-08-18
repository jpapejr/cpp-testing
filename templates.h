//
//  templates.h
//  cpp-test
//
//  Created by John Pape on 8/18/23.
//

#ifndef templates_h
#define templates_h

#include <cstdio>

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

#endif /* templates_h */
