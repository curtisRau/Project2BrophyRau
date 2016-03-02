//  main.cpp
//  Project 2
//
//  Created by Curtis Rau on 2/18/16.
//  Copyright © 2016 Curtis Rau. All rights reserved.
//

//#include <string>
#include <iostream>
//#include <fstream>              // for working with files.  Is this necessary?
//#include "math.h"       // Need to change?
#include "functions.hpp"        //



const double beta = 1.0;             // beta may not be equal to one.  This is a constant in the equation we are trying to solve.
//const double L = 2.0;                // the length over which we are solving.  This probably shouldn't be 2.0.  Something to think about.

//// This is the potential
double V (double rho) {
    return rho * rho + beta / rho;
}



int main(int argc, const char * argv[]) {
    
    // Get the arguments from the main
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int N = 10;
    double rho0 = 0.000000001;             // The starting position, probably 0.0, but 1/0 encountered.
    double h    = 1;                    // The step length
    double h2 = h*h;                    // Step Length Squared;
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
    
    // Setup the "A" Matrix (Curtis's Section)
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    const clock_t begin_time = std::clock();
    
    double* a = function::generateConstantVector(N-1, -1/h2);
    double* c = function::generateConstantVector(N-1, -1/h2);
    double* b = new double[N];
    for (int i = 0; i < N; i++) {
        b[i] = 1/h2 + V(rho0 + i*h);
    }
    
    // Passing vector arguments instead of making calls to the functions
    // that generate the vector arguments allows the following function
    // to be vectorizable.
    double** A = function::genTridiagMatVectArgsExact(N, a, b, c);
    
    delete [] a;
    delete [] b;
    delete [] c;
    
    std::cout << "Total computation time [s] = " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "\r";
    
    function::printMatrix(A, N, N);
    
    
//    unsigned int x;
//    unsigned int y;
//    unsigned int *p = &x;
//    unsigned int *q = &y;
//    
//    function::indiciesOfMaxElement(A, 10, 10, p, q);
//    
//    std::cout << "row = " << *p << "column = " << *q << "\r";
    
    
    // Implement Jacobi's Method (Ben's Section)
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    
    return 0;
}