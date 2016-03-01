//
//  functions.hpp
//  Project 2
//
//  Created by Curtis Rau on 2/18/16.
//  Copyright © 2016 Curtis Rau. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>

#endif

namespace function {
    // Curtis's Functions:
    void printMatrix (double** A, unsigned int m, unsigned int n);
    double* generateConstantVector (unsigned int length, double val);
    double** genTridiagMatConstArgsExact (unsigned int n, double a, double b, double c);
    double** genTridiagMatConstArgsFast (unsigned int n, double a, double b, double c);
    double** genTridiagMatVectArgsExact (unsigned int n, double* a, double* b, double* c);
    double** genTridiagMatVectArgsFast (unsigned int n, double* a, double* b, double* c);
    double frobeniusNorm (double** A, unsigned int m, unsigned int n);
    
    // Ben's Functions:
};