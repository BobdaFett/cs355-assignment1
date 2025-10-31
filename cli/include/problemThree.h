//
// Created by lvas4_0gev1ym on 10/31/2025.
//

#ifndef CS355_ASSIGNMENT1_PROBLEMTHREE_H
#define CS355_ASSIGNMENT1_PROBLEMTHREE_H

public enum class TestEnumClass {
    IndexOne = 0,
    IndexTwo = 1,
    IndexThree = 2,
    IndexFour = 3
};

public enum class TestEnumClassTwo {
    NumberOne = 1,
    NumberTwo = 2,
    NumberThree = 3,
    NumberFour = 4
};

ref class ProblemThree {
public:
    static void run();

protected:
    static void testSwitch();
    static void testIntoInt();
    static void testFromInt();
    static void testEnumCast();
    static void testInsideClass();

    ref class TestingClass {
    public:
        TestEnumClass value;
    };
};

#endif //CS355_ASSIGNMENT1_PROBLEMTHREE_H