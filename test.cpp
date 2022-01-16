#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                    "10 3\n"
                    "1 3\n"
                    "2 4\n"
                    "9 9\n"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    INFO(buffer.str());
    REQUIRE(buffer.str() ==
            "5"
    );
}

TEST_CASE("test 2", ""){
    std::stringstream input(
            "10 2\n"
            "1 1\n"
            "1 2\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
                    "8"
    );
}

TEST_CASE("no teachers", ""){
    std::stringstream input(
            "10 0\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
                    "10"
    );
}

TEST_CASE("one teacher covers all", ""){
    std::stringstream input(
            "10 1\n"
            "0 9\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
                    "0"
    );
}

TEST_CASE("2 teachers covers all", ""){
    std::stringstream input(
            "10 2\n"
            "0 4\n"
            "5 9\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
                    "0"
    );
}
