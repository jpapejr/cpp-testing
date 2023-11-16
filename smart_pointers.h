//
//  smart_pointers.h
//  cpp-test
//
//  Created by John Pape on 11/14/23.
//
#ifndef smart_pointers_h
#define smart_pointers_h

#include <boost/smart_ptr/scoped_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <iostream>
#include <memory>
#include <cstdio>

struct DeadMenOfDunharrow{
    const char* message;
    static int oaths_to_fulfill;
    DeadMenOfDunharrow(const char* m=" ") : message {m} {
        oaths_to_fulfill++;
    }
    ~DeadMenOfDunharrow(){
        oaths_to_fulfill--;
    }
};
int DeadMenOfDunharrow::oaths_to_fulfill{};

// using ScopedOathBreakers = boost::scoped_ptr<DeadMenOfDunharrow>;
using ScopedOathBreakers = std::unique_ptr<DeadMenOfDunharrow>;
using SharedOathBreakers = std::shared_ptr<DeadMenOfDunharrow>;


// using FileGuard = std::unique_ptr<FILE, int(*)(FILE*)>;
using FileGuard = std::shared_ptr<FILE>; //uses shared_

void say_hello(FileGuard file){
    fprintf(file.get(), "HELLO, DAVE");
}

auto my_shared_ptr = std::make_shared<int>(808);
std::weak_ptr<int> wp { my_shared_ptr };

#endif