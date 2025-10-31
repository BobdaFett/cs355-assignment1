#include "problemSix.h"

#include <iostream>

void ProblemSix::run() {
    std::cout << "\tChecking evaluation of call f(a, b):" << std::endl;
    f(a(), b());

    std::cout << "\tChecking evaluation of call g(a, b, b):" << std::endl;
    g(a(), b(), b());

    std::cout << "\tChecking evaluation of call g(a, f(a, b), b):" << std::endl;
    g(a(), f(a(), b()), b());
}

int ProblemSix::a() {
    std::cout << "\t\tEvaluated a" << std::endl;
    return 1;
}

int ProblemSix::b() {
    std::cout << "\t\tEvaluated b" << std::endl;
    return 2;
}

int ProblemSix::f(int a, int b) {
    std::cout << "\t\tEvaluated f" << std::endl;
    return b + a;
}

int ProblemSix::g(int a, int b, int c) {
    std::cout << "\t\tEvaluated g" << std::endl;
    return c + a + b;
}
