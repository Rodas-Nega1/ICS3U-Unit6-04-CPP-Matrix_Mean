// Copyright (c) 2021 Rodas Nega All rights reserved.
//
// Created by: Rodas Nega
// Created on: Oct 2021
// This program finds the mean of elements in a 2D array


#include <iostream>
#include <random>


template <int rows, int cols>
int MatrixMean(int (&randomGrid)[rows][cols], int rowNumber, int columnNumber) {
    // this function calculates the mean of all the elements in a 2D array

    int sumOfMatrixElements = 0;

    // process
    for (size_t rowValue = 0; rowValue < rows; rowValue++) {
        for (size_t columnValue = 0; columnValue < cols; columnValue++)
            sumOfMatrixElements += randomGrid[rowValue][columnValue];
    }
    sumOfMatrixElements = sumOfMatrixElements / (rowNumber * columnNumber);

    return sumOfMatrixElements;
}


int main() {
    // this function creates a 2D array

    int randomNumber = 0;
    int roundedMatrixMean;
    const int rows = 4;
    const int columns = 4;
    int matrix[rows][columns];

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 50);
    // [0, 50]

    // output
    for (int rowValue = 0; rowValue < rows; rowValue++) {
        for (int columnValue = 0; columnValue < columns; columnValue++) {
            randomNumber = idist(rgen);
            matrix[rowValue][columnValue] = randomNumber;
            std::cout << randomNumber << ", ";
        }
        std::cout << std::endl;
    }

    roundedMatrixMean = MatrixMean(matrix, rows, columns);
    std::cout << "" << std::endl;
    std::cout << "The mean of the matrix is: "
    << roundedMatrixMean << std::endl;
}
