#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t v0, v1, v2;
    u128_t matrix[3];
} Local_51FC18;

typedef struct __attribute__((packed)) { s32 values[2]; } Pair;

/* declared by functions of L39_0051F740.c, which this file was cut from */
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L39_005203E0(char *);
extern void func_L39_00520630(char *);

INCLUDE_ASM("asm/levels", func_L39_005203E0);

INCLUDE_ASM("asm/levels", func_L39_00520630);

INCLUDE_ASM("asm/levels", func_L39_00520870);

INCLUDE_ASM("asm/levels", func_L39_005210A0);

INCLUDE_ASM("asm/levels", func_L39_00521BC0);

INCLUDE_ASM("asm/levels", func_L39_00521DE8);
