#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <boost/smart_ptr/scoped_array.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <iostream>
#include "smart_pointers.h"


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

TEST_CASE("ScopedPtr supprts reset()"){
    ScopedOathBreakers aragorn{ new DeadMenOfDunharrow{} };
    SECTION("destructed owned object"){
        aragorn.reset();
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 0);
    }
    SECTION("can replace the owned object"){
        auto message = "It was made by those who are dead";
        auto new_dead_men = new DeadMenOfDunharrow{message};
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        aragorn.reset(new_dead_men);
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
        REQUIRE(aragorn->message == new_dead_men->message);
        REQUIRE(aragorn.get() == new_dead_men);
    }
}

TEST_CASE("ScopedArray supports operator[]"){
    boost::scoped_array<int> squares{
        new int[5] { 0, 4, 9, 16, 25 }
    };
    squares[0] = 1;
    REQUIRE(squares[0] == 1);
    REQUIRE(squares[1] == 4);
    REQUIRE(squares[2] == 9);
}

TEST_CASE("SharedPtr supports copy"){
    auto aragorn = std::make_shared<DeadMenOfDunharrow>();
    SECTION("construction"){
        auto son_of_arathorn { aragorn };
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
    SECTION("assignment"){
        SharedOathBreakers son_of_aragorn;
        auto son_of_arathorn = aragorn;
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
    SECTION("assignment, original gets discarded"){
        auto son_of_arathorn = std::make_shared<DeadMenOfDunharrow>();
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 2);
        son_of_arathorn = aragorn;
        REQUIRE(DeadMenOfDunharrow::oaths_to_fulfill == 1);
    }
}

TEST_CASE("WeakPtr lock() yields") {
    auto message = "The way is shut";
    SECTION("a shared pointer when tracked obj is alive"){
        auto aragorn = std::make_shared<DeadMenOfDunharrow>(message);
        std::weak_ptr<DeadMenOfDunharrow> legolas { aragorn };
        auto sh_ptr = legolas.lock();
        REQUIRE(sh_ptr->message == message);
        REQUIRE(sh_ptr.use_count() == 2);
    }
    SECTION("empty when shared pointer is empty"){
        std::weak_ptr<DeadMenOfDunharrow> legolas;
        {
            auto aragorn = std::make_shared<DeadMenOfDunharrow>();
            legolas = aragorn;
        }
        auto sh_ptr = legolas.lock();
        REQUIRE(nullptr == sh_ptr);

    }
}