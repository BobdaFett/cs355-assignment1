#include <iostream>

#include "problemThree.h"
#include "problemFive.h"
#include "problemSix.h"

using namespace System;

int main() {
    Console::WriteLine("Running problem 3 code - enum testing");
    ProblemThree::run();
    Console::WriteLine("");

    Console::WriteLine("Running problem 5 code - operand evaluation order");
    ProblemFive::run();
    Console::WriteLine("");

    Console::WriteLine("Running problem 6 code - argument evaluation order");
    ProblemSix::run();
    Console::WriteLine();
    
    return 0;
}
