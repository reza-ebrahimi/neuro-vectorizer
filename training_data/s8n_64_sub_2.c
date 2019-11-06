#include "header.h"

int output[64] ALIGNED16;
int input[64] ALIGNED16;

__attribute__((noinline))
void  example7 (int x) {
   int i;

   /* feature: support for read accesses with an unknown misalignment  */
   for (i=0; i<64-x; i++){
      output[i] -= input[i+x];
   }
}

int main(int argc,char* argv[]){
  init_memory(&output[0], &output[64]);
  init_memory(&input[0], &input[64]);
 
  BENCH("Example7",   example7(4), Mi*8/64*512, digest_memory(&output[0], &output[64]));
  return 0;
}