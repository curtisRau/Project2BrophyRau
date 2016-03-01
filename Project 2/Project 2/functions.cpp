//  functions.cpp
//  Project 2
//
//  Created by Curtis Rau on 2/18/16.
//  Copyright © 2016 Curtis Rau. All rights reserved.
//

#include "functions.hpp"
#include "math.h"           // For sqrt function.
#include <iostream>

namespace function {
    
    // A function to print a matrix for debugging purposes
    void printMatrix (double** A, unsigned int m, unsigned int n) {
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                std::cout << A[i][j] << "\t\t\t";
            }
            std::cout << "\r";
        }
    }
    
    
    // Generate a Constant Vector of length "length", initialized
    // with all values of value "val".  This function is vectorizable.
    double* generateConstantVector (unsigned int length, double val) {
        double* vec = new double[length];
        for (int i = 0; i<length; i++) {
            vec[i] = val;
        }
        return vec;
    }
    
    
    // Generate Tridiagonal Matrix with Constant Arguments Exact:
    // Returns a n by n tridiagonal matrix.  The sub-diagonal elements are
    // value a, diagonal elements are value b, super-diagonal elements are
    // value c.  All other elements are 0.  This function is non-vectorizable,
    // due to the if else statements in the for loop, so it will be slow, but
    // it generates a matrix exactly how it advertizes.
    double** genTridiagMatConstArgsExact (unsigned int n, double a, double b, double c) {
        double** A = new double*[n];
        for(int i = 0; i < n; i++) {
        
            A[i] = new double[n];
            for (int j = 0; j<n; j++) {
        
                if (j == (i-1)) {
                    A[i][j] = a;
                } else if (j == i) {
                    A[i][j] = b;
                } else if (j == (i+1)) {
                    A[i][j] = c;
                } else {
                    A[i][j] = 0.0;
                }
            }
        }
        return A;
    }
    
    // Generate Tridiagonal Matrix with Constant Arguments Fast:
    // Returns a n by n tridiagonal matrix.  The sub-diagonal elements are
    // value a, diagonal elements are value b, super-diagonal elements are
    // value c.  All other elements are roughly 0.  This function assumes
    // values of an array are initialized to 0, which they are sometimes not.
    // This function is fast though, being vectorizable, and could even be
    // parallelized (with some tweeking?).
    double** genTridiagMatConstArgsFast (unsigned int n, double a, double b, double c) {
        double** A = new double*[n];
        A[0]       = new double[n];
        A[0][0]    = b;
        A[0][1]    = c;
        
        for(int i = 1; i < n-1; i++) {
            A[i]      = new double[n];
            A[i][i-1] = a;
            A[i][i]   = b;
            A[i][i+1] = c;
        }
        
        A[n-1]      = new double[n];
        A[n-1][n-2] = a;
        A[n-1][n-1] = b;
        
        return A;
    }
    
    // Generate Tridiagonal Matrix with Vector Arguments Exact:
    // Returns a n by n tridiagonal matrix.  The sub-diagonal elements are
    // value a, diagonal elements are value b, super-diagonal elements are
    // value c.  All other elements are 0.  This function is non-vectorizable,
    // due to the if else statements in the for loop, so it will be slow, but
    // it generates a matrix exactly how it advertizes.
    double** genTridiagMatVectArgsExact (unsigned int n, double* a, double* b, double* c) {
        double** A = new double*[n];
        for(int i = 0; i < n; i++) {
            
            A[i] = new double[n];
            for (int j = 0; j<n; j++) {
                
                if (j == (i-1)) {
                    A[i][j] = a[i];
                } else if (j == i) {
                    A[i][j] = b[i];
                } else if (j == (i+1)) {
                    A[i][j] = c[i];
                } else {
                    A[i][j] = 0.0;
                }
            }
        }
        return A;
    }
    
    // Generate Tridiagonal Matrix with Vector Arguments Fast:
    // Returns a n by n tridiagonal matrix.  The sub-diagonal elements are
    // value a, diagonal elements are value b, super-diagonal elements are
    // value c.  All other elements are 0.  This function is vectorizable.
    double** genTridiagMatVectArgsFast (unsigned int n, double* a, double* b, double* c) {
        double** A = new double*[n];
        A[0]       = new double[n];
        A[0][0]    = b[0];
        A[0][1]    = c[0];
        
        for(int i = 1; i < n-1; i++) {
            A[i]      = new double[n];
            A[i][i-1] = a[i];
            A[i][i]   = b[i];
            A[i][i+1] = c[i];
        }
        
        A[n-1]      = new double[n];
        A[n-1][n-2] = a[n-2];
        A[n-1][n-1] = b[n-1];
        
        return A;
    }
    
    
    double frobeniusNorm (double** A, unsigned int m, unsigned int n) {
        double sum = 0.0;
        for (int i = 0; i<m; i++) {         // The order of this sum will matter.  row-column indexed?
            for (int j = 0; j<n; j++) {
                sum += A[i][j] * A[i][j];
            }
        }
        return sqrt(sum);
    }
    
    
    //NEED TO CHECK THIS FUNCTION.
    void jacobiRotation (double** A, unsigned int p, unsigned int q, float theta) {
        double s = sin(theta);
        double c = cos(theta);
        
        A[p][p] = (c*c) * A[p][p] - (s*c) * A[p][q] - (s*c) * A[q][p] + (s*s) * A[q][q];
        A[p][q] = (s*c) * A[p][p] + (c*c) * A[p][q] - (s*s) * A[q][p] - (s*c) * A[q][q];
        A[q][p] = (s*c) * A[p][p] - (s*s) * A[p][q] + (c*c) * A[q][p] - (s*c) * A[q][q];
        A[q][q] = (s*s) * A[p][p] - (s*c) * A[p][q] - (s*c) * A[q][p] + (c*c) * A[q][q];
    }
    
}