#include "problemOne.h"

#include <thread>
#include <iostream>

#include "config.h"

void ProblemOne::runA(int numIter) {
    static int numIterations = numIter;
    static double stackTime, heapTime, staticTime;

    std::thread stackThread([]() {
        clock_t stackStart, stackEnd;
        stackStart = clock();
        for (int i = 0; i < numIterations; i++) {
            createOnStack();
        }
        stackEnd = clock();
        stackTime = (double)(stackEnd - stackStart) / CLOCKS_PER_SEC;
    });

    std::thread heapThread([]() {
        clock_t heapStart, heapEnd;
        heapStart = clock();
        for (int i = 0; i < numIterations; i++) {
            createOnHeap(true);
        }
        heapEnd = clock();

        heapTime = (double)(heapEnd - heapStart) / CLOCKS_PER_SEC;
    });

    std::thread staticThread([]() {
        clock_t staticStart, staticEnd;
        staticStart = clock();
        for (int i = 0; i < numIterations; i++) {
            createAsStatic();
        }
        staticEnd = clock();

        staticTime = (double)(staticEnd - staticStart) / CLOCKS_PER_SEC;
    });

    stackThread.join();
    heapThread.join();
    staticThread.join();

    // Convert all units to seconds and display in a table.
    std::cout << "Total time for stack execution:  " << stackTime << " seconds" << std::endl;
    std::cout << "Total time for heap execution:   " << heapTime << " seconds" << std::endl;
    std::cout << "Total time for static execution: " << staticTime << " seconds" << std::endl;
}

void ProblemOne::runB(int numIterations) {
    runA(numIterations);

    // Run as many iterations on the stack as possible.
    int iterations = 0;
    clock_t timeStart = clock();
    try {
        while (iterations < numIterations) {
            iterations++;
            createOnHeap(false);
        }
    } catch (std::exception e) {
        std::cout << "Maximum number of iterations possible: " << iterations << std::endl;
    }
    clock_t timeEnd = clock();

    double timeTotal = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
    std::cout << "Total time for heap execution, no cleanup: " << timeTotal << " seconds" << std::endl;
}

void ProblemOne::createOnStack() {
    // Creates a 1000x1000 array on the stack.
    int arrOne[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];
    int arrTwo[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];
}

void ProblemOne::createOnHeap(bool shouldDelete) {
    // Creates a 1000x1000 array on the heap.
    int** arrOne = new int*[MATRIX_DIMENSIONS];

    // Allocate memory for each column as well
    for (int i = 0; i < MATRIX_DIMENSIONS; i++)
        arrOne[i] = new int[MATRIX_DIMENSIONS];

    // Then, delete the array.
    if (shouldDelete) {
        for (int i = MATRIX_DIMENSIONS - 1; i >= 0; i--)
            delete[] arrOne[i];
        delete[] arrOne;
    }

    // Repeat the process.
    int** arrTwo = new int*[MATRIX_DIMENSIONS];
    for (int i = 0; i < MATRIX_DIMENSIONS; i++)
        arrTwo[i] = new int[MATRIX_DIMENSIONS];
    if (shouldDelete) {
        for (int i = MATRIX_DIMENSIONS - 1; i >= 0; i--)
            delete[] arrTwo[i];
        delete[] arrTwo;
    }
}

void ProblemOne::createAsStatic() {
    static int arrOne[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];
    static int arrTwo[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];
}