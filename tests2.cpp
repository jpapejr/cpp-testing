#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
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
