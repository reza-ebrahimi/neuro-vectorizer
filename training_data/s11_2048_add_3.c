#include "header.h"

short short1[2048];
short short2[2048];
short short3[2048];
int   int1[2048] ALIGNED16;
int   int2[2048] ALIGNED16;
int   int3[2048] ALIGNED16;

__attribute__((noinline))
void example10a(short *__restrict__ short1, short *__restrict__ short2, short *__restrict__ short3, int* __restrict__ int1, int* __restrict__ int2, int* __restrict__ int3) {
  int i;
  for (i = 0; i < 2048; i++) {
    int1[i] = int2[i] + int3[i];
    short1[i] = short2[i] + short3[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&int1[0], &int1[2048]);
  init_memory(&int2[0], &int2[2048]);
  init_memory(&int3[0], &int3[2048]);
  init_memory(&short1[0], &short1[2048]);
  init_memory(&short2[0], &short2[2048]);
  init_memory(&short3[0], &short3[2048]);
  BENCH("Example10a", example10a(short1,short2,short3,int1,int2,int3), Mi/2048*512, digest_memory(&int1[0], &int1[2048]) + digest_memory(&short1[0], &short1[2048]));
 
  return 0;
}