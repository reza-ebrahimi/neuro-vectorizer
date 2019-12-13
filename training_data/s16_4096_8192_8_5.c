#include "header.h"

int   ia[8];
int G[4096][8192];
int G2[4096+8][8192];

__attribute__((noinline))
void example14(int mat1[][8192], int mat2[][8192], int *out) {
  int k,j,i=0;
  for (k = 0; k < 8; k++) {
    int sum = 0;
    for (i = 0; i < 4096; i++)
        for (j = 0; j < 8192; j++)
          sum += mat1[i+k][j] * mat2[i][j];

    out[k] = sum;
  }
}

int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[8]);
  init_memory(&G[0][0], &G[0][8192]);
  init_memory(&G2[0][0],&G2[0][8192]);
  BENCH("Example14",  example14(G2,G,ia), 8, digest_memory(&ia[0], &ia[8]));
  return 0;
}