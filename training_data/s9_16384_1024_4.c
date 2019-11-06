#include "header.h"

int assign[16384][1024];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<16384; i++) {
     for (j=0; j<1024; j++) {
       assign[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&assign[0][0], &assign[0][1024]);
  BENCH("Example8",   example8(8), 64, digest_memory(&assign[0][0], &assign[0][1024]));
 
  return 0;
}