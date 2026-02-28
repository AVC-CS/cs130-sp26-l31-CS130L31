#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include <cstdio>
#include <array>
#include "catch.hpp"
#include "answers.hpp"

// Helper: compile and run a program, return its stdout output
static std::string compileAndRun(const std::string &sourceFile) {
    std::string compileCmd = "g++ -std=c++17 " + sourceFile + " -o /tmp/cs130_test_prog 2>&1";
    std::array<char, 256> buffer;
    std::string compileOutput;
    FILE *pipe = popen(compileCmd.c_str(), "r");
    if (!pipe) return "ERROR: popen failed for compile";
    while (fgets(buffer.data(), buffer.size(), pipe))
        compileOutput += buffer.data();
    int rc = pclose(pipe);
    if (rc != 0)
        return "COMPILE_ERROR: " + compileOutput;

    std::string runCmd = "/tmp/cs130_test_prog 2>&1";
    std::string runOutput;
    pipe = popen(runCmd.c_str(), "r");
    if (!pipe) return "ERROR: popen failed for run";
    while (fgets(buffer.data(), buffer.size(), pipe))
        runOutput += buffer.data();
    pclose(pipe);
    return runOutput;
}

// Helper: check that output contains an expected line (trimmed)
static bool containsLine(const std::string &output, const std::string &expected) {
    return output.find(expected) != std::string::npos;
}

// ============================================================
// T1 — Compile & run main1.cpp and main2.cpp, verify output
// ============================================================
TEST_CASE("T1: main1.cpp and main2.cpp compile and produce correct output", "[T1]") {
    SECTION("main1.cpp") {
        std::string out = compileAndRun("main1.cpp");
        INFO("main1.cpp output:\n" << out);
        REQUIRE(out.find("COMPILE_ERROR") == std::string::npos);
        CHECK(containsLine(out, "Jane"));
        CHECK(containsLine(out, "19"));
        CHECK(containsLine(out, "After getRefStruct().age ;21"));
    }
    SECTION("main2.cpp") {
        std::string out = compileAndRun("main2.cpp");
        INFO("main2.cpp output:\n" << out);
        REQUIRE(out.find("COMPILE_ERROR") == std::string::npos);
        CHECK(containsLine(out, "getRefNum(num) = 100"));
        CHECK(containsLine(out, "num = 100"));
        CHECK(containsLine(out, "100"));
    }
}

// ============================================================
// T2 — Compile & run main3.cpp and main4.cpp, verify output
// ============================================================
TEST_CASE("T2: main3.cpp and main4.cpp compile and produce correct output", "[T2]") {
    SECTION("main3.cpp") {
        std::string out = compileAndRun("main3.cpp");
        INFO("main3.cpp output:\n" << out);
        REQUIRE(out.find("COMPILE_ERROR") == std::string::npos);
        CHECK(containsLine(out, "The field value is 100"));
        CHECK(containsLine(out, "The field value is 200"));
        CHECK(containsLine(out, "The field strvalue is Hello"));
        CHECK(containsLine(out, "The variable str is Hello"));
        CHECK(containsLine(out, "The field strvalue is World"));
    }
    SECTION("main4.cpp") {
        std::string out = compileAndRun("main4.cpp");
        INFO("main4.cpp output:\n" << out);
        REQUIRE(out.find("COMPILE_ERROR") == std::string::npos);
        CHECK(containsLine(out, "**** After changeStruct(ms) ****"));
        CHECK(containsLine(out, "The field value is 100"));
        CHECK(containsLine(out, "The field strvalue is Hello"));
        CHECK(containsLine(out, "**** After changeStruct2(ms) ****"));
        CHECK(containsLine(out, "The field value is 300"));
        CHECK(containsLine(out, "**** After changeStruct3(&ms) ****"));
        CHECK(containsLine(out, "The field value is 400"));
        CHECK(containsLine(out, "The field strvalue is World"));
    }
}

// ============================================================
// T3 — Multiple choice answers from answers.hpp
// ============================================================
TEST_CASE("T3: Multiple choice answers", "[T3]") {
    // Q1: s.age is 21 after getRefStruct().age = 21
    CHECK(Q1 == 3);
    // Q2: num is 100 because getRefNum returns a reference
    CHECK(Q2 == 2);
    // Q3: ms.strvalue is still "Hello" because str is a copy
    CHECK(Q3 == 2);
    // Q4: ms.value is still 100 because changeStruct1 passes by value
    CHECK(Q4 == 1);
    // Q5: pass by value makes a copy
    CHECK(Q5 == 1);
    // Q6: str is a copy, strRef is a reference to the member
    CHECK(Q6 == 1);
}

// ============================================================
// T4 — Test swapByRef and swapByPtr from answers.hpp
// ============================================================
TEST_CASE("T4: swapByRef and swapByPtr", "[T4]") {
    SECTION("swapByRef swaps two integers") {
        int a = 5, b = 10;
        swapByRef(a, b);
        REQUIRE(a == 10);
        REQUIRE(b == 5);
    }
    SECTION("swapByRef with equal values") {
        int a = 7, b = 7;
        swapByRef(a, b);
        REQUIRE(a == 7);
        REQUIRE(b == 7);
    }
    SECTION("swapByRef with negative values") {
        int a = -3, b = 8;
        swapByRef(a, b);
        REQUIRE(a == 8);
        REQUIRE(b == -3);
    }
    SECTION("swapByPtr swaps two integers") {
        int a = 5, b = 10;
        swapByPtr(&a, &b);
        REQUIRE(a == 10);
        REQUIRE(b == 5);
    }
    SECTION("swapByPtr with equal values") {
        int a = 7, b = 7;
        swapByPtr(&a, &b);
        REQUIRE(a == 7);
        REQUIRE(b == 7);
    }
    SECTION("swapByPtr with negative values") {
        int a = -3, b = 8;
        swapByPtr(&a, &b);
        REQUIRE(a == 8);
        REQUIRE(b == -3);
    }
}
