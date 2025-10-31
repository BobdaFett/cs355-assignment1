#include "problemThree.h"

#include <iostream>

void ProblemThree::run() {
    testEnumCast();
    testFromInt();
    testIntoInt();
    testSwitch();
}

void ProblemThree::testFromInt() {
    std::cout << "\tTesting conversion of enum from an int value." << std::endl;

    int num = 2;
    TestingEnumOne converted = (TestingEnumOne)num;
    std::cout << "\tConverted number " << num << " into enum value " << converted << std::endl;

    num = 5;
    converted = (TestingEnumOne)num;
    std::cout << "\tConverted number " << num << " into enum value " << converted << std::endl;
    std::cout << "\tThis succeeds, however TestingEnumOne does not have a definition for the value 5. This is unsafe." << std::endl;

    TestingEnumOne staticConverted = static_cast<TestingEnumOne>(num);
    std::cout << "\tA static_cast still does not solve this. Value: " << staticConverted << std::endl;
    std::cout << "\tThis is extremely unsafe!\n" << std::endl;
}

void ProblemThree::testIntoInt() {
    std::cout << "\tTesting conversion of enum into an int value." << std::endl;

    TestingEnumOne test = TestingEnumOne::IndexOne;
    int converted = (int)test;
    std::cout << "\tConverted enum " << test << " into number value " << converted << std::endl;
    std::cout << "\tThis is safe - we cannot convert into a value that isn't already defined in the enum.\n" << std::endl;
}

void ProblemThree::testEnumCast() {
    std::cout << "\tTesting conversion from one enum into another." << std::endl;

    // This is syntactically legal, but a cast that doesn't technically fit the enum doesn't fail
    // and is therefore unsafe.
    TestingEnumTwo toConvert = TestingEnumTwo::NumberFour;
    TestingEnumOne test = (TestingEnumOne)toConvert;  // legal, but fails at runtime
    std::cout << "\tConverted enum " << toConvert << " into " << test << std::endl;
    std::cout << "\tThis succeeds, however TestingEnumOne does not have a definition for the value 4. This is unsafe." << std::endl;

    // TestingEnumOne testStatic = static_cast<TestingEnumOne>(toConvert);
    std::cout << "\tA static_cast would solve this during compile time.\n" << std::endl;
}

void ProblemThree::testSwitch() {
    std::cout << "\tTesting usage of enums in switch statements." << std::endl;

    TestingEnumOne testOne = TestingEnumOne::IndexTwo;
    TestingEnumTwo testTwo = TestingEnumTwo::NumberFour;

    switch (testOne) {
        case TestingEnumOne::IndexTwo:
            std::cout << "\tFound TestingEnumOne::IndexTwo" << std::endl;
            break;
        default:
            std::cout << "\tValue was incorrect." << std::endl;
            break;
    }

    switch (testTwo) {
        case TestingEnumOne::IndexOne:
            std::cout << "\tFound TestEnumClass::IndexOne" << std::endl;
            break;
        case TestingEnumOne::IndexTwo:
            std::cout << "\tFound TestEnumClass::IndexTwo" << std::endl;
            break;
        case TestingEnumOne::IndexThree:
            std::cout << "\tFound TestEnumClass::IndexThree" << std::endl;
            break;
        case TestingEnumOne::IndexFour:
            std::cout << "\tFound TestEnumClass::IndexFour" << std::endl;
            break;
        default:
            std::cout << "\tFound an undefined enum value. This would be very unsafe." << std::endl;
            break;
    }

    std::cout << "\n";
}

void ProblemThree::testInsideClass() {
    // TODO Implement. Not sure what to do to test this though.
}
