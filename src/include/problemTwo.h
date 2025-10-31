#pragma once

#ifndef PROBLEM_TWO
#define PROBLEM_TWO

#include <iostream>
#include <random>

#include "config.h"

class ProblemTwo {
public:
    static void run();

protected:
    static double multiplyStack();
    static double multiplyHeap();
    static double multiplyStatic();
};

#endif