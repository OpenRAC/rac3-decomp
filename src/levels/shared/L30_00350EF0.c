#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern s32 D_L30_001DF2C0;
extern f32 func_0038D098(f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

INCLUDE_ASM("asm/levels", func_L30_00350EF0);

/* localdecomp:start func_L30_00350FA8 */
typedef struct { s32 x0[2]; u8 pad8[0x1C - 0x8]; s32 x1C; s32 x20; } V_350FA8;
typedef struct { u8 pad[0x34]; u16 x34; u8 pad36[0x68 - 0x36]; V_350FA8 *x68; u8 pad6C[0x98 - 0x6C]; s32 x98; } O_350FA8;
typedef struct { u8 pad[0x25C0]; void *x25C0; } S_350FA8;
__asm__(".extern D_L30_001DD870, 4");
__asm__(".extern D_L30_001DD888, 4");
__asm__(".extern D_L30_001DD88C, 4");
__asm__(".extern D_L30_001DD894, 4");
__asm__(".extern D_L30_001DD89C, 4");
__asm__(".extern D_L30_001DD8D4, 4");
__asm__(".extern D_L30_001DD8D8, 4");
__asm__(".extern D_L30_001DD8DC, 4");
__asm__(".extern D_L30_001DD8F0, 4");
__asm__(".extern D_L30_001DD920, 4");
__asm__(".extern D_L30_001DD928, 4");
__asm__(".extern D_L30_001DD92C, 4");
__asm__(".extern D_L30_001DD940, 4");
__asm__(".extern D_L30_001DD948, 4");
extern s32 D_L30_001DD870;
extern s32 D_L30_001DD888;
extern s32 D_L30_001DD88C;
extern f32 D_L30_001DD894;
extern s32 D_L30_001DD89C;
extern s32 D_L30_001DD8D4;
extern s32 D_L30_001DD8D8;
extern f32 D_L30_001DD8DC;
extern s32 D_L30_001DD8F0;
extern s32 D_L30_001DD920;
extern s32 D_L30_001DD928;
extern s32 D_L30_001DD92C;
extern f32 D_L30_001DD940;
extern s32 D_L30_001DD948;
extern u8 D_L30_001E1360;
extern u8 D_L30_001E1380;
extern u8 D_L30_001E13A0;
extern s32 D_L30_001E13B0;
extern S_350FA8 D_001A4BE0;
extern void func_L01_004AA7E8(void *, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L30_003510C8(u8 *, u8 *);
extern void func_L30_00351558(u8 *, u8 *);
extern void func_L30_003518F0(u8 *, u8 *);
extern s32 func_003A52A0(s32, s32, void *);

void func_L30_00350FA8(O_350FA8 *o) {
    V_350FA8 *v = o->x68;
    s32 i;
    s32 m = -1;

    for (i = 1; i >= 0; i--) {
        v->x0[i] = m;
    }
    o->x98 = 0;
    o->x34 = (o->x34 | 0x41) & ~0x1000;
    func_L01_004AA7E8(o, 1);
    if (D_L30_001DD870 == 0) {
        D_L30_001DD870 = 1;
        func_L03_0034B218(&D_L30_001E1360, D_L30_001DD888, D_L30_001DD88C, D_L30_001DD894, D_L30_001DD89C, (void *)func_L30_003510C8);
        func_L03_0034B218(&D_L30_001E1380, D_L30_001DD8D4, D_L30_001DD8D8, D_L30_001DD8DC, D_L30_001DD8F0, (void *)func_L30_00351558);
        func_L03_0034B218(&D_L30_001E13A0, D_L30_001DD928, D_L30_001DD92C, D_L30_001DD940, D_L30_001DD948, (void *)func_L30_003518F0);
        D_L30_001E13B0 = D_L30_001DD920;
    }
    v->x1C = 0;
    v->x20 = -1;
    v->x20 = func_003A52A0(0x20, 4, D_001A4BE0.x25C0);
}
/* localdecomp:end func_L30_00350FA8 */

INCLUDE_ASM("asm/levels", func_L30_003510C8);
