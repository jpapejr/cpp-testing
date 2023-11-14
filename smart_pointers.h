//
//  smart_pointers.h
//  cpp-test
//
//  Created by John Pape on 11/14/23.
//
#ifndef smart_pointers_h
#define smart_pointers_h

#include <boost/smart_ptr/scoped_ptr.hpp>
#include <iostream>

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

using ScopedOathBreakers = boost::scoped_ptr<DeadMenOfDunharrow>;


#endif