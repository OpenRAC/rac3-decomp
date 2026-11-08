#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003619F0);

INCLUDE_ASM("asm/levels", func_L05_00362148);

INCLUDE_ASM("asm/levels", func_L05_003622D0);

INCLUDE_ASM("asm/levels", func_L05_003624B0);

/* localdecomp:start func_L05_003627A0 */
extern void func_L01_004450F0(s32, s32, s32);
extern u8 *D_L05_001DFB9C;
extern u8 *D_001DFB9C_sda;
__asm__(".extern D_L05_001DFB9C, 16");
__asm__(".extern D_001DFB9C_sda, 4");

void func_L05_003627A0(void *arg0) {
    u8 *p;
    s32 a;

    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        p = *(u8 **)((u8 *)arg0 + 0x68);
        a = *(s32 *)p;
        *(s32 *)(p + 0x8) = 0;
        *(s32 *)(p + 0xC) = 0;
        if (a != -1) {
            *(u8 **)(p + 0x8) = D_L05_001DFB9C + (a << 8);
        }
        a = *(s32 *)(p + 0x4);
        if (a != -1) {
            *(u8 **)(p + 0xC) = D_001DFB9C_sda + (a << 8);
        }
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L05_003627A0 */

INCLUDE_ASM("asm/levels", func_L05_00362810);

/* localdecomp:start func_L05_00362968 */
typedef struct P_362968 {
    f32 f0;
    s32 w4;
    f32 f8;
    s32 wC;
} P_362968;

typedef struct S_362968 {
    char pad0[0x18];
    f32 f18;
    char pad1[0x20 - 0x1C];
    u8 b20;
    char pad2[0x68 - 0x21];
    P_362968 *p68;
} S_362968;

s32 func_L01_004450F0_00362968(void *, s32, s32);

void func_L05_00362968(S_362968 *a0) {
    P_362968 *p;
    f32 t;
    f32 g;

    p = a0->p68;
    if (a0->b20 == 0) {
        g = p->f8;
        p->wC = -1;
        t = a0->f18 + g;
        p->w4 = 0;
        p->f0 = t;
        func_L01_004450F0_00362968(a0, 1, -1);
    }
}
/* localdecomp:end func_L05_00362968 */
