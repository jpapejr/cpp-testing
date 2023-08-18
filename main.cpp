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

using namespace std;


int main(int argc, const char * argv[]) {
    short beast{665};
    auto mark_of_the_beast = increment_as_short(&beast);
    printf("The mark of the beast is %d.\n", mark_of_the_beast);
    
    
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


