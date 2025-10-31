#include "problemFive.h"

#include <iostream>

void ProblemFive::run() {
    Console::WriteLine("\tChecking evaluation order of equation a + b:");
    int result = a() + b();

    Console::WriteLine("\tChecking evaluation order of equation a + (a / b):");
    result = a() + (a() / b());

    Console::WriteLine("\tChecking evaluation order of condition b < a:");
    bool bResult = b() < a();

    Console::WriteLine("\tChecking evaluation order of condition b || a:");
    bResult = b() || a();

    Console::WriteLine("\tChecking evaluation order of f(a, b) -> b + a:");
    result = f(a(), b());
}

int ProblemFive::a() {
    Console::WriteLine("\t\tEvaluated a");
    return 1;
}

int ProblemFive::b() {
    Console::WriteLine("\t\tEvaluated b");
    return 2;
}

int ProblemFive::f(int a, int b) {
    Console::WriteLine("\t\tEvaluated f");
    return b + a;
}
