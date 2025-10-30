#include <iostream>

#include "problemOne.h"
#include "problemTwo.h"
#include "problemThree.h"

int main() {
    std::cout << "Running problem 1A code - creation of arrays with cleanup" << std::endl;
    ProblemOne::runA(ALLOC_ITER);

    std::cout << "Running problem 1B code - creation of arrays without cleanup" << std::endl;
    std::cout << "Note - don't run this function without a full cleanup afterwards." << std::endl;
    // ProblemOne::runB(ALLOC_OVERFLOW_ITER);

    std::cout << "Running problem 2 code - timing of memory access in large matrices" << std::endl;
    ProblemTwo::run();

    std::cout << "Running problem 3 code - enum testing" << std::endl;
    ProblemThree::run();

    return 0;
}
