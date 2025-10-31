#include "problemFour.h"

#include <iostream>
#include <thread>

#include "config.h"

void ProblemFour::run() {
    static double subscriptTime = 0, pointerTime = 0;

    std::thread subscriptThread([]() {
        for (int i = 0; i < ALLOC_ITER; i++)
            subscriptTime += accessSubscript();
    });

    std::thread pointerThread([]() {
        for (int i = 0; i < ALLOC_ITER; i++)
            pointerTime += accessPointer();
    });

    subscriptThread.join();
    pointerThread.join();

    std::cout << "\tTotal time for subscripting: " << subscriptTime << " seconds" << std::endl;
    std::cout << "\tTotal time for pointer math: " << pointerTime << " seconds" << std::endl;
}

double ProblemFour::accessSubscript() {
    int arr[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];

    clock_t start = clock();
    for (int i = 0; i < MATRIX_DIMENSIONS; i++) {
        for (int j = 0; j < MATRIX_DIMENSIONS; j++) {
            int val = arr[i][j];
        }
    }
    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

double ProblemFour::accessPointer() {
    int arr[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];

    int* pIter = &arr[0][0];

    clock_t start = clock();
    for (int i = 0; i < MATRIX_DIMENSIONS * MATRIX_DIMENSIONS; i++) {
        int val = *pIter;
        pIter++;
    }
    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}
