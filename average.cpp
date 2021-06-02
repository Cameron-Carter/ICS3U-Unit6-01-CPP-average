// Copyright (c) Cameron Carter All rights reserved
//
// Created by: Cameron Carter
// Created on: June 2021
// This program averages numbers

#include <iostream>
#include <random>


main() {
    // This function averages random numbers

    // Declaring variables
    int randomNumbers[10];
    float average = 0;
    int generatedNumber;

    // Process and Output
    for (
        int loopCounter = 0;
        // I leanred how to get array length in c++ from:
        // https://stackoverflow.com/questions/4108313/
        // how-do-i-find-the-length-of-an-array
        loopCounter < sizeof(randomNumbers)/sizeof(*randomNumbers);
        loopCounter++
    ) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());  // mersenne_twister
        std::uniform_int_distribution<int> idist(1, 100);
        generatedNumber = idist(rgen);
        randomNumbers[loopCounter] = generatedNumber;
    }
    for (
        int loopCounter = 0;
        loopCounter < sizeof(randomNumbers)/sizeof(*randomNumbers);
        loopCounter++
    ) {
        std::cout << "Random number " << loopCounter + 1 << " is "
        << randomNumbers[loopCounter] << "." << std::endl;
        average += randomNumbers[loopCounter];
    }
    average = average / (sizeof(randomNumbers) / sizeof(*randomNumbers));
    std::cout << "\nThe average is " << average << "." << std::endl;
    std::cout << "\nDone" << std::endl;
}
