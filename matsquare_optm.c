// optimized versions of matrix diagonal summing
#include "matvec.h"

int matsquare_VER1(matrix_t *mat, matrix_t *matsq) {
  // YOUR CODE HERE
  return 0;
}

int matsquare_VER2(matrix_t *mat, matrix_t *matsq) {
  // OPTIONALLY, OTHER VERSIONS
  return 0;
}


int matsquare_OPTM(matrix_t *mat, matrix_t *matsq){
  if(mat->rows != mat->cols   ||      // must be a square matrix to square it
     mat->rows != matsq->rows ||
     mat->cols != matsq->cols)
  {
    printf("matsquare_OPTM: dimension mismatch\n");
    return 1;
  }

  // Call to some version of optimized code
  return matsquare_VER1(mat, matsq);
}
/////////////////////////////////////////////////////////////////////////////////
// ADDITIONAL INFORMATION
//
// (A) VERSION: If you implemented several versions, indicate which
// version you timed
// 
// ####################### YOUR ANSWER HERE #########################
// 
// ##################################################################
// 
//
// (B) TIMING ON loginNN.cselabs.umn.edu:
// Paste a copy of the results of running matsquare_benchmark on the
// above machines in the space below which shows how your performance
// optimizations improved on the baseline codes.
// 
// ####################### YOUR ANSWER HERE #########################
// 
// ##################################################################
// 
// (C) OPTIMIZATIONS:
// Describe in some detail the optimizations you used to speed the code
// up.  THE CODE SHOULD CONTAIN SOME COMMENTS already to describe these
// but in the section below, describe in English the techniques you used
// to make the code run faster.  Format your descriptions into discrete
// chunks such as.
// 
// Optimization 1: Blah bla blah... This should make run faster because
// yakkety yakeety yak.
// 
// Optimization 2: Blah bla blah... This should make run faster because
// yakkety yakeety yak.
// ...
// Optimization N: Blah bla blah... This should make run faster because
// yakkety yakeety yak.
// 
// Full credit solutions will describe 2-3 optimizations and describe
// WHY these improved performance in at least a couple sentences.
// 
// ####################### YOUR ANSWER HERE #########################
// 
// ##################################################################
