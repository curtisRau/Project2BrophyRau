//  main.cpp
//  Project 2
//
//  Created by Curtis Rau on 2/18/16.
//  Copyright © 2016 Curtis Rau. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>              // for working with files.  Is this necessary?
#include "math.h"       // Need to change?

void jacobiMethod () {



    
}


////////////////////////////////////////
//
//
////////////////////////////////////////
double frobeniusNorm (double** A) {
    int N = 1;
    double sum = 0.0;
    for (int i = 0; i<N; i++) {         // The order of this sum will matter.  row-column indexed?
        for (int j = 0; j<N; j++) {
            sum += A[i][j] * A[i][j];
        }
    }
    return sqrt(sum);
}

double offDiagonalSumOfSquares (double** A, double norm) {
    int N = 1;
    double diagSum = 0.0;
    for (int i = 0; i<N; i++) {
        diagSum += A[i][i] * A[i][i];
    }
    return norm - sqrt(diagSum);
}

double off (double** A, int N) {
    // The square root of the sum of the squares of the off diagonal elements.
    double sum = 0.0;
    for (int i=0; i < N; i++) {
        for (int j=0; (j<N && i!=j); j++) {
            sum += (A[i][j]) * (A[i][j]);
        }
    }
    return sqrt(sum);
}

const double beta = 1.0;             // beta may not be equal to one.  This is a constant in the equation we are trying to solve.
const double L = 2.0;                // the length over which we are solving.  This probably shouldn't be 2.0.  Something to think about.

// This is the potential
double V (double rho) {
    return rho * rho + beta / rho;
}



int main(int argc, const char * argv[]) {

    // Get the arguments from the main
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    int N;
//    double tol;                   // The tolerence
//    bool PLOT = false;
//    bool SAVE = false;
//    const char* filename;
//    for (int i=0; i<argc; i++) {
//        if (strcmp(argv[i], "-N")==0) {N = std::stoi(argv[i+1]);}
        
//        if (strcmp(argv[i], "-t")==0) {tol = std::stoi(argv[i+1]);}
        
//        if (strcmp(argv[i], "-plot")==0) {PLOT = true;}
        
//        if (strcmp(argv[i], "-save")==0) {                  // If the "-save" flag is passed to main()
//            filename = argv[i+1];                           // The filename should be the next argument passed to main()
//        }
//    }
    
<<<<<<< HEAD
    // Check in N is valid.  The program ends if N = 0.
    if (N == 0) {
        return 0;
    }
    
    // Check if filename is valid
    if (!filename) {                                // If the filename = NULL...
        std::cout << "No path to file specified.  Was expecting '-save path_to_file' /r";
    } else {                                        // If the filename != NULL...
        std::ofstream outputFile;
        outputFile.open(filename);                  // Try opening the file
        if (!outputFile.is_open()) {                // If the file doesn't open...
            std::cout << "Could not open file.  Was expecting '-save path_to_file' /r";
        } else {                                    // If the file can be opened...
            SAVE = true;
        }
    }
=======
//    // Check if filename is valid
//    if (!filename) {                                // If the filename = NULL...
//        std::cout << "No path to file specified.  Was expecting '-save path_to_file' /r";
//    } else {                                        // If the filename != NULL...
//        std::ofstream outputFile;
//        outputFile.open(filename);                  // Try opening the file
//        if (!outputFile.is_open()) {                // If the file doesn't open...
//            std::cout << "Could not open file.  Was expecting '-save path_to_file' /r";
//        } else {                                    // If the file can be opened...
//            SAVE = true;
//        }
//    }
>>>>>>> origin/master
    
    // Implement Jacobi's Method
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Initialize A matrix
    int** A = new int*[N];
    for(int i = 0; i < N; ++i) {
        A[i] = new int[N];
    }

    //while (<#condition#>) {
    //    <#statements#>
    //}
    
    
    return 0;
}
