#include "vu0.h"
#include "common.h"

/* declared by functions of L06_003506E0.c, which this file was cut from */
extern void func_L06_00350BB8(void *arg0, u8 *arg1);
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad1[52 - 33];
    u16 flags;
    u8 pad2[104 - 54];
    void *vars;
} Moby_0034F9E8;
extern void func_L06_00350788(Moby_0034F9E8 *, void *);

INCLUDE_ASM("asm/levels", func_L06_00350788);
