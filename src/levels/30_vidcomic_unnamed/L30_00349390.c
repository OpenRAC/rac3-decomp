#include "common.h"

typedef struct { u8 pad0[0x20]; u8 b20; u8 pad21[0x43 - 0x21]; u8 b43; u8 pad44[0x68 - 0x44]; void *p68; } Obj_0034BC90;
typedef struct { u8 pad0[0x50]; f32 f50; s16 h54; u8 pad56[0x210 - 0x56]; f32 f210; s32 w214; s32 w218; u8 pad21c[0x220 - 0x21c]; f32 f220; } P_0034BC90;

INCLUDE_ASM("asm/levels", func_L30_00349390);

INCLUDE_ASM("asm/levels", func_L30_00349470);

INCLUDE_ASM("asm/levels", func_L30_003494F0);

INCLUDE_ASM("asm/levels", func_L30_00349550);

INCLUDE_ASM("asm/levels", func_L30_00349630);

INCLUDE_ASM("asm/levels", func_L30_003496D8);

INCLUDE_ASM("asm/levels", func_L30_003497B0);

INCLUDE_ASM("asm/levels", func_L30_00349968);

INCLUDE_ASM("asm/levels", func_L30_00349A20);

INCLUDE_ASM("asm/levels", func_L30_00349B28);

INCLUDE_ASM("asm/levels", func_L30_00349CA8);

INCLUDE_ASM("asm/levels", func_L30_00349EE8);

INCLUDE_ASM("asm/levels", func_L30_0034A058);

INCLUDE_ASM("asm/levels", func_L30_0034A0A8);

LINKER_REMNANT("asm/levels", func_L30_0034A100);

INCLUDE_ASM("asm/levels", func_L30_0034A108);

INCLUDE_ASM("asm/levels", func_L30_0034A968);

INCLUDE_ASM("asm/levels", func_L30_0034AA20);

INCLUDE_ASM("asm/levels", func_L30_0034ABF8);

INCLUDE_ASM("asm/levels", func_L30_0034ACC8);

INCLUDE_ASM("asm/levels", func_L30_0034AD28);

INCLUDE_ASM("asm/levels", func_L30_0034B2F0);

/* localdecomp:start func_L30_0034B4A0 */
extern s32 func_L01_0045BD10(u8 *, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
__asm__(".extern D_001DD434, 4");
extern f32 D_001DD434;

void func_L30_0034B4A0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 x, s;
    u8 *q;

    if (*(f32 *)(p + 0x30) < *(f32 *)(a0 + 0x10)) {
        func_L01_0045BD10(a0, 3.1415927f);
    } else {
        func_L01_0045BD10(a0, 0.0f);
    }
    q = a0 + 0xD0;
    x = *(f32 *)(a0 + 0xF8);
    s = func_0038D0B0(x);
    func_0038CF68(q, q, D_001DD434 + (1.0f - D_001DD434) * __builtin_fabsf(s));
}
/* localdecomp:end func_L30_0034B4A0 */

INCLUDE_ASM("asm/levels", func_L30_0034B538);

INCLUDE_ASM("asm/levels", func_L30_0034B688);

INCLUDE_ASM("asm/levels", func_L30_0034B720);

INCLUDE_ASM("asm/levels", func_L30_0034B980);

INCLUDE_ASM("asm/levels", func_L30_0034BA88);

INCLUDE_ASM("asm/levels", func_L30_0034BBC0);

/* localdecomp:start func_L30_0034BC90 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L30_0034BC90(void *a0, f32 a3, s32 a1, s32 a2) {
    Obj_0034BC90 *o = (Obj_0034BC90 *)a0;
    P_0034BC90 *p = (P_0034BC90 *)o->p68;
    p->f50 = (f32)p->h54;
    p->f220 = p->f210 = a3;
    p->w214 = a1;
    p->w218 = a2;
    if (o->b43 != 2) func_003C3A10(a0, 2, 0, 0);
    if ((u32)(p->w214 - 1) < 0x42 && o->b20) func_L01_004450F0(a0, p->w214, -1);
}
/* localdecomp:end func_L30_0034BC90 */

INCLUDE_ASM("asm/levels", func_L30_0034BD28);
