#include "header.h"

int   ia[4];
int G[64][64];
int G2[64+4][64];

__attribute__((noinline))
void example14(int A[][64], int coeff[][64], int *out) {
  int k,j,i=0;
  for (k = 0; k < 4; k++) {
    int sum = 0;
    for (i = 0; i < 64; i++)
        for (j = 0; j < 64; j++)
          sum += A[i+k][j] * coeff[i][j];

    out[k] = sum;
  }
}

int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[4]);
  init_memory(&G[0][0], &G[0][64]);
  init_memory(&G2[0][0],&G2[0][64]);
  BENCH("Example14",  example14(G2,G,ia), 131072, digest_memory(&ia[0], &ia[4]));
  return 0;
}