#include "problemTwo.h"

#include <iostream>
#include <chrono>
#include <random>

#include "config.h"

void ProblemTwo::run() {
    double stackTime = multiplyStack();
    double heapTime = multiplyHeap();
    double staticTime = multiplyStatic();

    std::cout << "\tTotal time for stack multiplication:  " << stackTime << " seconds" << std::endl;
    std::cout << "\tTotal time for heap multiplication:   " << heapTime << " seconds" << std::endl;
    std::cout << "\tTotal time for static multiplication: " << staticTime << " seconds" << std::endl;
}

double ProblemTwo::multiplyStack() {
    // Create matrices on stack
    int arrOne[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];
    int arrTwo[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];

    std::default_random_engine generator (std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, 100);

    // Fill with random values
    for (int i = 0; i < MATRIX_DIMENSIONS; i++) {
        for (int j = 0; j < MATRIX_DIMENSIONS; j++) {
            arrOne[i][j] = dist(generator);
            arrTwo[i][j] = dist(generator);
        }
    }

    int result[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];

    // Multiply matrices together
    clock_t start = clock();
    for (int row = 0; row < MATRIX_DIMENSIONS; row++) {
        for (int col = 0; col < MATRIX_DIMENSIONS; col++) {
            for (int i = 0; i < MATRIX_DIMENSIONS; i++) {
                result[row][col] = result[row][col] + (arrOne[row][i] * arrTwo[i][col]);
            }
        }
    }
    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

double ProblemTwo::multiplyHeap() {
    // Create matrices on the heap
    int** arrOne = new int*[MATRIX_DIMENSIONS];
    int** arrTwo = new int*[MATRIX_DIMENSIONS];

    std::default_random_engine generator (std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, 100);

    // Fill with random values
    for (int i = 0; i < MATRIX_DIMENSIONS; i++) {
        arrOne[i] = new int[MATRIX_DIMENSIONS];
        arrTwo[i] = new int[MATRIX_DIMENSIONS];

        for (int j = 0; j < MATRIX_DIMENSIONS; j++) {
            arrOne[i][j] = dist(generator);
            arrTwo[i][j] = dist(generator);
        }
    }

    // Allocate results on the heap
    int** result = new int*[MATRIX_DIMENSIONS];
    for (int i = 0; i < MATRIX_DIMENSIONS; i++) {
        result[i] = new int[MATRIX_DIMENSIONS];
    }

    // Multiply matrices together
    clock_t start = clock();
    for (int row = 0; row < MATRIX_DIMENSIONS; row++) {
        for (int col = 0; col < MATRIX_DIMENSIONS; col++) {
            for (int i = 0; i < MATRIX_DIMENSIONS; i++) {
                result[row][col] = result[row][col] + (arrOne[row][i] * arrTwo[i][col]);
            }
        }
    }
    clock_t end = clock();

    // Delete all arrays to save memory
    for (int i = 0; i < MATRIX_DIMENSIONS; i++) {
        delete[] arrOne[i];
        delete[] arrTwo[i];
        delete[] result[i];
    }
    delete[] arrOne;
    delete[] arrTwo;
    delete[] result;

    return (double)(end - start) / CLOCKS_PER_SEC;
}

double ProblemTwo::multiplyStatic() {
    static int arrOne[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];
    static int arrTwo[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];

    std::default_random_engine generator (std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, 100);

    // Fill with random values
    for (int i = 0; i < MATRIX_DIMENSIONS; i++) {
        for (int j = 0; j < MATRIX_DIMENSIONS; j++) {
            arrOne[i][j] = dist(generator);
            arrTwo[i][j] = dist(generator);
        }
    }

    static int result[MATRIX_DIMENSIONS][MATRIX_DIMENSIONS];

    // Multiply matrices together
    clock_t start = clock();
    for (int row = 0; row < MATRIX_DIMENSIONS; row++) {
        for (int col = 0; col < MATRIX_DIMENSIONS; col++) {
            for (int i = 0; i < MATRIX_DIMENSIONS; i++) {
                result[row][col] = result[row][col] + (arrOne[row][i] * arrTwo[i][col]);
            }
        }
    }
    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}
