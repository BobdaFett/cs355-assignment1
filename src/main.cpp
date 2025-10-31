#include <iostream>

#include "problemOne.h"
#include "problemTwo.h"
#include "problemThree.h"
#include "problemFour.h"
#include "config.h"

int main() {
    std::cout << "Running problem 1A code - creation of arrays with cleanup" << std::endl;
    ProblemOne::runA(ALLOC_ITER);
    std::cout << "\n";

    std::cout << "Running problem 1B code - creation of arrays without cleanup" << std::endl;
    std::cout << "Cannot run this code without breaking the rest of the tests." << std::endl;
    // ProblemOne::runB(ALLOC_OVERFLOW_ITER);
    std::cout << "\n";

    std::cout << "Running problem 2 code - timing of memory access in large matrices" << std::endl;
    ProblemTwo::run();
    std::cout << "\n";

    std::cout << "Running problem 3 code - enum testing" << std::endl;
    ProblemThree::run();
    std::cout << "\n";

    std::cout << "Running problem 4 code - array accessing" << std::endl;
    ProblemFour::run();
    std::cout << "\n";

    return 0;
}
