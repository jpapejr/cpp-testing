#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <iostream>

struct DeadMenOfDunharrow{
    const char* message;
    static int oaths_to_fulfill;
    DeadMenOfDunharrow(const char* m="") : message { m } {
        oaths_to_fulfill++;
    }
    ~DeadMenOfDunharrow(){
        oaths_to_fulfill--;
    }
};
int DeadMenOfDunharrow::oaths_to_fulfill{};

using ScopedOathBreakers = boost::scoped_ptr<DeadMenOfDunharrow>;


TEST_CASE("ScopedPtr evaluates to") {
    SECTION("true when full") {
        ScopedOathBreakers aragorn{new DeadMenOfDunharrow{} };
        REQUIRE(aragorn);
    }
    SECTION("false when empty") {
        ScopedOathBreakers aragorn;
        REQUIRE_FALSE(aragorn);
    }
}

TEST_CASE("ScopedPtr is an RAII wrapper") {
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);
    ScopedOathBreakers aragorn { new DeadMenOfDunharrow{} };
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    {
        ScopedOathBreakers legolas { new DeadMenOfDunharrow{} };
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);

    }
    REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
}

TEST_CASE("ScopedPtr supports pointer semantics, like"){
    auto message = "The way is shut!";
    ScopedOathBreakers aragorn { new DeadMenOfDunharrow{message} };
    SECTION("operator*") {
        REQUIRE((*aragorn).message == message);
    }
    SECTION("operator->") {
        REQUIRE(aragorn->message == message);
    }
    SECTION("get(), which returns a raw pointer") {
        REQUIRE(aragorn.get() != nullptr);
    }
}

TEST_CASE("ScopedPtr supports compare with nullptr"){
    SECTION("operator=="){
        ScopedOathBreakers legolas{};
        REQUIRE(legolas == nullptr);
    }
    SECTION("operator!="){
        ScopedOathBreakers legolas { new DeadMenOfDunharrow{} };
        REQUIRE(legolas != nullptr);
    }
}


TEST_CASE("ScopedPtr supports swap"){
    auto message1 = "The way is shut";
    auto message2 = "Until the time comes";
    ScopedOathBreakers aragorn { new DeadMenOfDunharrow(message1) };
    ScopedOathBreakers legolas { new DeadMenOfDunharrow{message2} };
    aragorn.swap(legolas);
    REQUIRE(legolas->message == message1);
    REQUIRE(aragorn->message == message2);
}