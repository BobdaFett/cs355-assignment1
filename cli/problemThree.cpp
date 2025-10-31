//
// Created by lvas4_0gev1ym on 10/31/2025.
//

#include "problemThree.h"

using namespace System;

void ProblemThree::run() {
    testFromInt();
    testIntoInt();
    testEnumCast();
    testSwitch();
}

void ProblemThree::testFromInt() {
    Console::WriteLine("\tTesting conversion of enum from an int value.");

    int num = 2;
    TestEnumClass converted = safe_cast<TestEnumClass>(num);
    String^ convertedString = converted.ToString();
    Console::WriteLine("\tConverted number " + num + " into enum value " + convertedString);

    num = 5;
    converted = safe_cast<TestEnumClass>(num);
    convertedString = converted.ToString();
    Console::WriteLine("\tConverted number " + num + " into enum value " + convertedString);
    Console::WriteLine("\tThis succeeds, however TestEnumClass does not have a definition for the value 5.");
    Console::WriteLine("\tThis is unsafe, even in a managed context.");
}

void ProblemThree::testIntoInt() {
    Console::WriteLine("\tTesting conversion of enum an int value.");

    TestEnumClass test = TestEnumClass::IndexOne;
    int converted = safe_cast<int>(test);
    Console::WriteLine("\tConverted enum " + test.ToString() + " into number value " + converted.ToString());
    Console::WriteLine("\tThis is safe, as we cannot convert enums into a value that isn't already defined in the enum.");
}

void ProblemThree::testEnumCast() {
    Console::WriteLine("\tTesting conversion from one enum into another.");

    try {
        TestEnumClassTwo toConvert = TestEnumClassTwo::NumberFour;  // no definition for this in TestEnumClass
        TestEnumClass test = safe_cast<TestEnumClass>(toConvert);
        Console::WriteLine("\tConverted enum " + toConvert.ToString() + " into " + test.ToString());
    } catch (Exception^ e) {
        Console::WriteLine(e->ToString());
    }
}

void ProblemThree::testSwitch() {
    Console::WriteLine("\tTesting usage of enums in switch statements.");

    TestEnumClass testOne = TestEnumClass::IndexTwo;
    TestEnumClassTwo testTwo = TestEnumClassTwo::NumberFour;

    switch (testOne) {
        case TestEnumClass::IndexTwo:
            Console::WriteLine("\tFound TestEnumClass::IndexTwo");
            break;
        default:
            Console::WriteLine("\tValue was incorrect.");
            break;
    }

    switch (testTwo) {
        case TestEnumClass::IndexOne:
            Console::WriteLine("\tFound TestEnumClass::IndexOne");
            break;
        case TestEnumClass::IndexTwo:
            Console::WriteLine("\tFound TestEnumClass::IndexTwo");
            break;
        case TestEnumClass::IndexThree:
            Console::WriteLine("\tFound TestEnumClass::IndexThree");
            break;
        case TestEnumClass::IndexFour:
            Console::WriteLine("\tFound TestEnumClass::IndexFour");
            break;
        default:
            Console::WriteLine("\tFound an undefined enum value. This would be very unsafe.");
            break;
    }
}

void ProblemThree::testInsideClass() {

}

