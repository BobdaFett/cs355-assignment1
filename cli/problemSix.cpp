#include "problemSix.h"

using namespace System;

void ProblemSix::run() {
    Console::WriteLine("\tChecking evaluation of call f(a, b):");
    f(a(), b());

    Console::WriteLine("\tChecking evaluation of call g(a, b, b):");
    g(a(), b(), b());

    Console::WriteLine("\tChecking evaluation of call g(a, f(a, b), b):");
    g(a(), f(a(), b()), b());
}

int ProblemSix::a() {
    Console::WriteLine("\t\tEvaluated a");
    return 1;
}

int ProblemSix::b() {
    Console::WriteLine("\t\tEvaluated b");
    return 2;
}

int ProblemSix::f(int a, int b) {
    Console::WriteLine("\t\tEvaluated f");
    return b + a;
}

int ProblemSix::g(int a, int b, int c) {
    Console::WriteLine("\t\tEvaluated g");
    return c + a + b;
}