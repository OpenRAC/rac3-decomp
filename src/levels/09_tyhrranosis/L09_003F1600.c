#include "common.h"

typedef int Q87e __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V87e;
typedef struct { char pad[32]; float rate; int pad24, timer, count; } G87e;

INCLUDE_ASM("asm/levels", func_L09_003F1600);
