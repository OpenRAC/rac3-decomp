#include "common.h"

typedef int Q __attribute__((mode(TI)));
typedef int U64 __attribute__((mode(DI)));
typedef struct { u8 pad[0x30]; u8 a,b; short c; u16 flags; u16 pad36; U64 data; } M;

INCLUDE_ASM("asm/levels", func_L09_00350718);
