#include "problemThree.h"

#include <iostream>

void ProblemThree::run() {
    testEnumCast();
    testFromInt();
    testIntoInt();
    testSwitch();
}

void ProblemThree::testFromInt() {
    std::cout << "Testing conversion of enum from an int value." << std::endl;

    int num = 2;
    TestingEnumOne converted = (TestingEnumOne)num;
    std::cout << "Converted number " << num << " into enum value " << converted << std::endl;

    num = 5;
    converted = (TestingEnumOne)num;
    std::cout << "Converted number " << num << " into enum value " << converted << std::endl;
    std::cout << "This succeeds, however TestingEnumOne does not have a definition for the value 5. This is unsafe." << std::endl;

    TestingEnumOne staticConverted = static_cast<TestingEnumOne>(num);
    std::cout << "A static_cast still does not solve this. Value: " << staticConverted << std::endl;
    std::cout << "This is extremely unsafe!" << std::endl;
}

void ProblemThree::testIntoInt() {
    std::cout << "Testing conversion of enum into an int value." << std::endl;

    TestingEnumOne test = TestingEnumOne::IndexOne;
    int converted = (int)test;
    std::cout << "Converted enum " << test << " into number value " << converted << std::endl;
    std::cout << "This is safe - we cannot convert into a value that isn't already defined in the enum." << std::endl;
}

void ProblemThree::testEnumCast() {
    std::cout << "Testing conversion from one enum into another." << std::endl;

    // This is syntactically legal, but a cast that doesn't technically fit the enum doesn't fail
    // and is therefore unsafe.
    TestingEnumTwo toConvert = TestingEnumTwo::NumberFour;
    TestingEnumOne test = (TestingEnumOne)toConvert;  // legal, but fails at runtime
    std::cout << "Converted enum " << toConvert << " into " << test << std::endl;
    std::cout << "This succeeds, however TestingEnumOne does not have a definition for the value 4. This is unsafe." << std::endl;

    // TestingEnumOne testStatic = static_cast<TestingEnumOne>(toConvert);
    std::cout << "A static_cast would solve this during compile time." << std::endl;
}

void ProblemThree::testSwitch() {
    std::cout << "Testing usage of enums in switch statements." << std::endl;

    TestingEnumOne testOne = TestingEnumOne::IndexTwo;
    TestingEnumTwo testTwo = TestingEnumTwo::NumberFour;

    switch (testOne) {
        case TestingEnumOne::IndexTwo:
            std::cout << "Success! This is the expected value." << std::endl;
            break;
        default:
            std::cout << "Value was incorrect." << std::endl;
            break;
    }

    switch (testOne) {
        case TestingEnumTwo::NumberOne:
            std::cout << "Found TestingEnumTwo::NumberOne from a TestingEnumOne::IndexTwo." << std::endl;
            std::cout << "This was expected, but implicit and unsafe." << std::endl;
            break;
        default:
            std::cout << "Couldn't find the expected value." << std::endl;
            break;
    }
}
