//
//  main.cpp
//  cpp-test
//
//  Created by John Pape on 7/11/23.
//

#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <functional>
#include "lifecycle.h"
#include "pointers.h"
#include "polymorphism.h"
#include "templates.h"
#include "expressions.h"
#include "statements.h"
#include "functions.h"
#include "take_a_brake.h"

using namespace std;


int main(int argc, const char * argv[]) {
    cout << "-----------------------Program arguments-------------------------" << endl;
    for (size_t i{}; i<argc; i++){
        cout << "Arg" << i << " = " << argv[i] << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    
    // IServiceBus& bus{}; 
    // AutoBrake ab{bus};
    
    
    // while (true) {
        
    //     ab.observe(SpeedUpdate{ 10L });
    //     ab.observe(CarDetected{ 250L, 25L });
    // }



    // //functions
    // volatile Distillate ethanol;
    // cout << ethanol.apply() << " tequila" << endl;
    // cout << ethanol.apply() << " tequila" << endl;
    // cout << ethanol.apply() << " tequila" << endl;
    // cout << "Floor!" << endl;
    
    
    // cout << "Result from the sum() variadic function is " << sum(1, -100) << endl;
    // cout << "Result from the subtract() variadic function is " << subtract(1,2,3,100, -104) << endl;
    // cout << "Result from the print() variadic function is " << print("String1", "String2", "This is a really long string.") << endl;
    
    // //function pointer
    // float (*fpointer)(int x, int y){};
    // fpointer = &add;
    // cout << "Function pointer execution result: " << fpointer(1,2) << endl;
    
    // CountIf s_counter{ 's' }, f_counter{ 'f' };
    // auto sally = s_counter("Sally sells seashells by the seashore");
    // cout << "There are " << sally << " instances of the letter 's' in the string" << endl;
    // auto foxtrot = f_counter("Buffalo, Buffalo!!");
    // cout << "There are " << foxtrot << " instances of the letter 'f' in the string" << endl;
    // auto tango = CountIf{'d'}("If Peter Piper picked a peck of pickeled peppers");
    // cout << "There are " << tango << " instances of the letter 'd' in the string" << endl;
    // char to_count{ 'g' };
    // auto golf_counter = [&] (const char* str){
    //     size_t index{}, result{};
    //     while (str[index]){
    //         if (tolower(str[index]) == tolower(to_count)) result++;
    //         index++;
    //     }
    //     return result;
    // };
    // auto g_units = golf_counter("Golfy, golf, golf!");
    // cout << "There are " << g_units << " instances of the letter 'g' in the string" << endl;

    // const size_t len {3};
    // int base[]{1,2,3}, a[len], b[len], c[len];
    // transform([] (int x) { return 1; }, base, a, len);
    // transform([] (int x) { return x; }, base, b, len);
    // transform([] (int x) { return 10*x+5; }, base, c, len);
    // for (size_t i{}; i<len; i++){
    //     cout << "Element" << i << " : " << a[i] << " " << b[i] << " " << c[i] << endl;
    // }

    // auto increment = [] (int x, int y = 1) -> int { return x+y; };
    // cout << "Increment 10 : " << increment(10) << endl;
    // cout << "Increment 30 : " << increment(20, 10) << endl;


    // // function containers
    // std::function<void()> func { [] { cout << "A lambda function" << endl;}};
    // func();
    // func  = static_func;
    // func();

    // auto text = "Sailor went to sea to see what he could see.";
    // size_t index{};
    // for(const auto& func : funcs){
    //     cout << "func" << index++ << " : " << func(text) << endl;
    // }

//    // statements
//    size_t iterations{};
//    uint32_t number {123};
//    uint32_t target{99999};
//    while (number != target){
//        randomize(number);
//        ++iterations;
//    }
//    printf("Took %zu iterations to reach %d!\n\n", iterations, target);
//
//    iterations = 0;
//    RandomNumberGenerator rng{42};
//
//    while (rng.next() != target){
//
//    }
//    printf("Took %zu iterations to reach target of %d!\n\n", rng.get_iterations(), target);
//    rng.decrement_iterations();
//    printf("One less iteration would be %lu. \n\n", rng.get_iterations());
//
//    auto b = Fruit::Red::Berries::Shnozberry;
//
//    switch (b) {
//        case Fruit::Red::Berries::Shnozberry:
//            cout << "I like shnozberries!" << endl;
//            break;
//        case Fruit::Red::Berries::Strawberry:
//            cout << "I love strawberries!!" << endl;
//        default:
//            cout << "I'm not a big fan of red berries" << endl;
//            break;
//    }
//
//    if (const auto [success, content, size] = read_text_file("./file.txt"); success){
//        cout << "File content: " << content << endl;
//        cout << "File size: " << size << endl;
//    } else {
//        cout << "Error reading file" << endl;
//    }
//
//
//    try {
//        toss_knuckleball();
//    } catch (std::runtime_error& e){
//        cout << "Error: " << e.what() << endl;
//    }
//
//    int32_t ui { 10000 };
//    cout << ui << " is " << sign(ui) << endl;
//
//    uint32_t level { 8998 };
//    auto *power_level = &level;
//    auto &power_ref = level;
//
//    cout << "Power level: " << value_of(power_level) << endl;
//    ++*power_level;
//    cout << "Power level: " << value_of(power_ref) << endl;
//    ++power_ref;
//    cout << "Power level is " << value_of(level) << "!" << endl;
//
//    const int x[] { 1,2,3,4,5,6,7,8,9,10};
//    for (const auto element : x){
//        cout << element << endl;
//    }
     
    
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


