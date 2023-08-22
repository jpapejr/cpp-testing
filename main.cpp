//
//  main.cpp
//  cpp-test
//
//  Created by John Pape on 7/11/23.
//

#include <iostream>
#include <cstdio>
#include <stdexcept>
#include "lifecycle.h"
#include "pointers.h"
#include "polymorphism.h"
#include "templates.h"
#include "expressions.h"
#include "statements.h"

using namespace std;

int main(int argc, const char * argv[]) {
  
    // statements
    size_t iterations{};
    uint32_t number {123};
    uint32_t target{99999};
    while (number != target){
        randomize(number);
        ++iterations;
    }
    printf("Took %zu iterations to reach %d!\n\n", iterations, target);
    
    iterations = 0;
    RandomNumberGenerator rng{42};
    
    while (rng.next() != target){
        
    }
    printf("Took %zu iterations to reach target of %d!\n\n", rng.get_iterations(), target);
    rng.decrement_iterations();
    printf("One less iteration would be %lu. \n\n", rng.get_iterations());

    auto b = Fruit::Red::Berries::Shnozberry;
    
    switch (b) {
        case Fruit::Red::Berries::Shnozberry:
            cout << "I like shnozberries!" << endl;
            break;
        case Fruit::Red::Berries::Strawberry:
            cout << "I love strawberries!!" << endl;
        default:
            cout << "I'm not a big fan of red berries" << endl;
            break;
    }
    
//    //expressions
//    int x{};
//    auto y = confusing(x);
//    print_addr(&x);
//    printf("x: %d\ny: %d\n", x, y);
//
//    CheckedInteger a{ 100 };
//    auto b = a + 200;
//    printf("a + 200 = %d\n", b.value);
//    try {
//        auto c = a + std::numeric_limits<unsigned int>::max();
//        printf("c: %p", &c);
//    } catch (const std::overflow_error& e){
//        printf("a(max) Exception: %s\n", e.what());
//    }
//
//    MyType t{42};
//    auto ten_times = static_cast<int>(t) * 10;
//    printf("ten x t: %d\n", ten_times);
    
    
    
    
//    //templates and casts
//    const long x[] = { 10, 20 , 30, 40 , 50};
//    auto const result = mean(x, 5);
//    printf("result is %ld.\n", result);
//
//    const double y[] = { 50.0, -69.456, 128.0 };
//    auto const result2 = mean(y, 3);
//    printf("result2 is now %f.\n", result2);
//
//    // won't compile because it doesn't satisfy the concepts/constraints we defined for mean()
//    auto value1 { 0.0 };
//    auto value2 { 0.0 };
//    const double* values[] { &value1, &value2 };
//    mean(values, 2);
    
    
//    short beast{665};
//    auto mark_of_the_beast = increment_as_short(&beast);
//    printf("The mark of the beast is %d.\n", mark_of_the_beast);
    
    
//    polymorphism
//    ConsoleLogger consoleLogger;
//    FileLogger fileLogger;
//    Bank bank{ &consoleLogger };
//    //bank.set_logger(&consoleLogger);
//    bank.make_transfer(659099, 12777453, 100);
//    bank.make_transfer(9298583, 4832757, 1755.69);
//    bank.set_logger(&fileLogger);
//    bank.make_transfer(659099, 12777453, 100);
//    bank.make_transfer(9298583, 4832757, 1755.69);
    
    
}


