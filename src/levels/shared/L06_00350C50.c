#include "vu0.h"
#include "common.h"

/* declared by functions of L06_003506E0.c, which this file was cut from */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct {
    Vec4 m[4];
} Mtx4;
extern void func_003C2EC0(void *, s32, Mtx4 *);

INCLUDE_ASM("asm/levels", func_L06_00350C50);
