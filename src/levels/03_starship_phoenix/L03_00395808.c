#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00395808);

/* localdecomp:start func_L03_00395BF0 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 v10; u8 pad20[0x48]; u8 *p68; } A_00395BF0;
typedef struct { vu0_v4 v0; vu0_v4 v10; u8 pad20[0xC]; s32 i2C; u8 pad30[8]; f32 f38; u8 pad3C[4]; s32 i40; f32 f44; u8 pad48[4]; f32 f4C; s32 i50; u8 pad54[4]; s32 f58; } P_00395BF0;
typedef struct { u8 b[0x80]; } E_00395BF0;
extern E_00395BF0 *D_L03_001DFA80;
extern void func_L01_004450F0(void *, s32, s32);
void func_L03_00395BF0(void *arg) {
    A_00395BF0 *a = arg;
    P_00395BF0 *p;
    if (*(u8 *)((u8 *)arg + 0x20) == 0) {
        p = (P_00395BF0 *)a->p68;
        p->f58 = 0;
        p->v0 = *(vu0_v4 *)&a->v10;
        if (p->i2C != -1) {
            vec_sub_ba(&p->v10, D_L03_001DFA80[p->i2C].b + 0x30, &a->v10);
        }
        p->f44 = p->f38 / (f32)p->i40 * 0.017453292f;
        p->f4C = 1.0f / (f32)p->i50;
        func_L01_004450F0(arg, 1, -1);
    }
}
/* localdecomp:end func_L03_00395BF0 */

INCLUDE_ASM("asm/levels", func_L03_00395CA8);

INCLUDE_ASM("asm/levels", func_L03_00395D60);

INCLUDE_ASM("asm/levels", func_L03_00396190);

INCLUDE_ASM("asm/levels", func_L03_00396320);

INCLUDE_ASM("asm/levels", func_L03_003965E8);
