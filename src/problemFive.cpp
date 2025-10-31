#include "problemFive.h"

#include <iostream>

void ProblemFive::run() {
    std::cout << "\tChecking evaluation order of equation a + b:" << std::endl;
    int result = a() + b();

    std::cout << "\tChecking evaluation order of equation a + (a / b):" << std::endl;
    result = a() + (a() / b());

    std::cout << "\tChecking evaluation order of condition b < a:" << std::endl;
    bool bResult = b() < a();

    std::cout << "\tChecking evaluation order of condition b || a:" << std::endl;
    bResult = b() || a();

    std::cout << "\tChecking evaluation order of f(a, b) -> b + a:" << std::endl;
    result = f(a(), b());
}

int ProblemFive::a() {
    std::cout << "\t\tEvaluated a" << std::endl;
    return 1;
}

int ProblemFive::b() {
    std::cout << "\t\tEvaluated b" << std::endl;
    return 2;
}

int ProblemFive::f(int a, int b) {
    std::cout << "\t\tEvaluated f" << std::endl;
    return b + a;
}
