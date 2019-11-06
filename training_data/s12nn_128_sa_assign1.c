#include "header.h"

short sa[128];
short sb[128];
short sc[128];
int   assign1[128] ALIGNED16;
int   assign2[128] ALIGNED16;
int   assign3[128] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ sa, short *__restrict__ sb, short *__restrict__ sc, int* __restrict__ assign1, int* __restrict__ assign2, int* __restrict__ assign3) {
  int i;
  for (i = 0; i < 128; i++) {
    assign1[i] = (int) sa[i];
    assign2[i] = (int) sb[i];
    assign3[i] = (int) sc[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&assign1[0], &assign1[128]);
  init_memory(&assign2[0], &assign2[128]);
  init_memory(&assign3[0], &assign3[128]);
  init_memory(&sa[0], &sa[128]);
  init_memory(&sb[0], &sb[128]);
  init_memory(&sc[0], &sc[128]);
  BENCH("Example10b", example10b(sa,sb,sc,assign1,assign2,assign3), Mi*4/128*512, digest_memory(&assign1[0], &assign1[128])+digest_memory(&assign2[0], &assign2[128])+digest_memory(&assign3[0], &assign3[128]));
 
  return 0;
}