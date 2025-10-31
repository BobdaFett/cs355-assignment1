#pragma once

#ifndef PROBLEM_ONE
#define PROBLEM_ONE

class ProblemOne {
public:
    static void runA(int numIter);

    /// @brief Runs problem B, which runs all of problem A and then tests how many iterations are possible
    ///        until we over-allocate the heap.
    static void runB(int numIterations);

protected:
    static void createOnStack();
    static void createOnHeap(bool shouldDelete);
    static void createAsStatic();
};

#endif