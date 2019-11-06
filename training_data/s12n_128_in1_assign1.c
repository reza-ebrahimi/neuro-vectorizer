#include "header.h"

short in1[128];
short in2[128];
int   assign1[128] ALIGNED16;
int   assign2[128] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in1, short *__restrict__ in2, int* __restrict__ assign1, int* __restrict__ assign2) {
  int i;
  for (i = 0; i < 128; i++) {
    assign1[i] = (int) in1[i];
    assign2[i] = (int) in2[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&assign1[0], &assign1[128]);
  init_memory(&assign2[0], &assign2[128]);
  init_memory(&in1[0], &in1[128]);
  init_memory(&in2[0], &in2[128]);
  BENCH("Example10b", example10b(in1,in2,assign1,assign2), Mi*4/128*512, digest_memory(&assign1[0], &assign1[128])+digest_memory(&assign2[0], &assign2[128]));
 
  return 0;
}