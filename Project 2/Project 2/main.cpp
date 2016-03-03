//  main.cpp
//  Project 2
//
//  Created by Curtis Rau on 2/18/16.
//  Copyright © 2016 Curtis Rau. All rights reserved.
//

//#include <string>
#include <iostream>
//#include <fstream>              // for working with files.  Is this necessary?
#include "math.h"               // for tangent function in Jacobi method implementation
#include <limits>               // to get the maximum precision of a float or double.
#include "functions.hpp"        //
#include "time.h"

typedef std::numeric_limits< double > dbl;


const double beta = 0.0;//1.44;               // units [eVnm].  This is a constant in the equation we are trying to solve.

// This is the potential
double V (double rho) {
    return rho * rho;// + beta / rho;
}



int main(int argc, const char * argv[]) {
    
    std::cout.precision(dbl::max_digits10);
    
    // Get the arguments from the main
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    const unsigned int N = 1000;
    const double rhoMin = 0.0;//00000001;             // The starting position, probably 0.0, but 1/0 encountered.
    const double rhoMax = 200;
    const double h    = (rhoMax - rhoMin) / N;                    // The step length
    const double h2 = h*h;                    // Step Length Squared;
    //    double tol;                   // The tolerence
    //    bool PLOT = false;
    //    bool SAVE = false;
    //    const char* filename;
    //    for (int i=0; i<argc; i++) {
    //        if (strcmp(argv[i], "-N")==0) {N = std::stoi(argv[i+1]);}
    //
    //        if (strcmp(argv[i], "-t")==0) {tol = std::stoi(argv[i+1]);}
    //
    //        if (strcmp(argv[i], "-plot")==0) {PLOT = true;}
    //
    //        if (strcmp(argv[i], "-save")==0) {                  // If the "-save" flag is passed to main()
    //            filename = argv[i+1];                           // The filename should be the next argument passed to main()
    //        }
    //    }
    //
    //    // Check in N is valid.  The program ends if N = 0.
    //    if (N == 0) {
    //        return 0;
    //    }
    //
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
    
    //const clock_t begin_time = std::clock();
    //std::cout << "Total computation time [s] = " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "\r";
    
    // Generate the A matrix which the Jacobi Method will diagonalize
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    double* a = function::generateConstantVector(N-1, -1/h2);
    double* c = function::generateConstantVector(N-1, -1/h2);
    double* b = new double[N];
    for (int i = 0; i < N; i++) {
        b[i] = 2/h2 + V(rhoMin + i*h);
    }
    
    // Passing vector arguments instead of making calls to the functions
    // that generate the vector arguments allows the following function
    // to be vectorizable.
    double** A = function::genTridiagMatVectArgsExact(N, a, b, c);
    
    delete [] a;
    delete [] b;
    delete [] c;
    
    //function::printMatrix(A, N, N);
    
    std::cout << "Sum of off diagonal matrix elements = " << function::off(A, N) << "\r";
    std::cout << "Smallest Eigenvalue =" << function::minDiagonalElement(A, N);
    std::cout << "\t -- \t -- \t -- \t -- \t -- \t -- \t -- \t -- \t -- \t -- \t -- \r\r\r";
    
    // Implement the Jacobi Method
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unsigned int x;
    unsigned int y;
    unsigned int* p = &x;
    unsigned int* q = &y;
    double theta = 0.0;
    unsigned int maxRecursion = 1000;        // Maximum number of times for loop will run.
    double minTheta = 0.0000001;
    
    for (unsigned int i = 0; (i < maxRecursion) || (theta > minTheta); i++) {
        function::indiciesOfMaxOffDiagnalElement(A, N, N, p, q);
        theta = atan(
                     (2*A[*p][*q]) / (A[*q][*q] - A[*p][*p])
                     ) / 2.0;
        function::jacobiRotation(A, N, *p, *q, theta);
        
        //function::printMatrix(A, N, N);
        
        std::cout << "Sum of off diagonal matrix elements = " << function::off(A, N) << "\r";
        std::cout << "Smallest Eigenvalue =" << function::minDiagonalElement(A, N);
        std::cout << "\t -- \t -- \t -- \t -- \t -- \t -- \t -- \t -- \t -- \t -- \t -- \r\r\r";
    }
    
    
    // Clean Up.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Delete the A matrix.
    for (unsigned int i = 0; i<N; i++) {
        delete [] A[i];
    }
    delete [] A;
    
    return 0;
}
