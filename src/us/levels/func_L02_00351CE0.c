#include "common.h"

/* NTSC-U counterpart of func_L02_00352DF0 (src/levels/shared/L02_00352DF0.c): 0.02 -> 0.0166667 */
typedef struct B_L02_00352C80 {
    s32 id;
    u8 pad04[0x1C];
    s32 cnt20;
    s32 a24;
    s32 a28;
    s32 r2C;
    u8 pad30[0x10];
    s32 cnt40;
    s32 a44;
    s32 a48;
    s32 r4C;
    s32 flag50;
    f32 f54;
    f32 f58;
} B_L02_00352C80;
typedef struct A_L02_00352C80 {
    u8 pad00[0x20];
    u8 b20;
    u8 pad21[0x47];
    B_L02_00352C80 *sub;
} A_L02_00352C80;
extern void func_L02_00351CE0(A_L02_00352C80 *, B_L02_00352C80 *);

/* localdecomp:start func_L02_00351CE0 */
#include "vu0.h"
extern void func_00388BD0(void *, void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern f32 func_00388770(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern u8 *D_L02_001DEB00;
extern f32 D_L02_001DCFC0_00351CE0;
__asm__(".extern D_L02_001DCFC0_00351CE0, 4");

void func_L02_00351CE0(A_L02_00352C80 *a, B_L02_00352C80 *b) {
    u8 *o = (u8 *)a;
    u8 *s = (u8 *)b;
    vu0_v4 vec;
    f32 x;
    s32 i;
    u8 *p;

    func_00388BD0(o + 0xC0, o + 0xF0);
    if (b->cnt20 > 32) {
        b->cnt20 = 32;
    }
    b->r2C = 0;
    b->r4C = 0;
    b->f58 = 0;
    if (s[9]) {
        *(f32 *)(o + 0x18) = func_003BE7F0(o + 0x10, 0, 0, 0.5f);
    }
    if (*(s32 *)(s + 0x10) != -1) {
        p = D_L02_001DEB00 + (*(s32 *)(s + 0x10) << 7);
        *(f32 *)(o + 0x10) = *(f32 *)(p + 0x30);
        *(f32 *)(o + 0x14) = *(f32 *)(p + 0x34);
        vec_add_ab(&vec, p, p + 0x10);
        x = func_00388770(&vec) + *(f32 *)(s + 4) + D_L02_001DCFC0_00351CE0;
    } else {
        x = *(f32 *)(s + 4) + *(f32 *)(s + 0x14) + D_L02_001DCFC0_00351CE0;
    }
    *(s16 *)(o + 0x32) = (s32)x;
    if (x > 255.0f) {
        x = 255.0f;
    }
    o[0x30] = (s32)x;
    for (i = 0; i < b->cnt20; i++) {
        *(s32 *)(s + 0x74 + i * 0x20) = -1;
    }
    *(f32 *)(s + 0x30) *= 0.0166666675f;
    *(f32 *)(s + 0x34) *= 0.0166666675f;
    func_L01_00441FB8(a, 1, -1);
}
/* localdecomp:end func_L02_00351CE0 */
