#pragma once

#ifndef PROBLEM_THREE
#define PROBLEM_THREE

enum TestingEnumOne {
    IndexOne = 0,
    IndexTwo = 1,
    IndexThree = 2,
    IndexFour = 3,
};

enum TestingEnumTwo {
    NumberOne = 1,
    NumberTwo = 2,
    NumberThree = 3,
    NumberFour = 4,
};

class ProblemThree {
public:
    static void run();

protected:
    static void testSwitch();
    static void testIntoInt();
    static void testFromInt();
    static void testEnumCast();
    static void testInsideClass();

    class TestingClass {
    public:
        TestingEnumOne value;
    };
};

#endif