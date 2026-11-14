#include "common.h"

/* localdecomp:start func_L40_00431948 */
typedef struct O_00431948 O_00431948;
typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(O_00431948 *, s32);
} VT_00431948;
struct O_00431948 {
    u8 pad0[0x14];
    VT_00431948 *vt;
};

extern u8 *D_001D5F30_sda;
extern u8 *D_L40_0024845C;
extern f32 D_L40_00247A04;
extern f32 D_L40_00247A08;
extern s32 D_L40_00247A10;
extern f32 D_L40_00247A14;
extern s32 D_L40_00247A18;
extern s32 D_L40_00247A1C;
extern u8 D_001FE020[];
extern void func_L01_0044ABD0(u8 *m, u8 *a1);
extern void func_003C2880(u8 *m);
extern s32 func_L40_003F6078(u8 *m);
extern u8 *func_L39_0066C828(u8 *m, s32 a1, s32 a2);
extern void func_L39_0061C1E0(u8 *m, s32 a1);
extern O_00431948 *func_L39_0061D7B0(u8 *m);
extern void func_L01_004450F0(u8 *m, s32 a1, s32 a2);
extern s32 func_L39_005F33E0(s32 a0, s32 a1, u8 *m);
extern void func_L40_00431EA0(u8 *m);
extern s32 func_L01_004561B8(u8 *m);
extern void func_L40_00431C00(u8 *m);
extern void func_L39_005F2FF8(u8 *m, s32 a1);
extern s32 func_L39_005B4398(s32 n);
extern void func_L40_004311A8(u8 *m, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15);

void func_L40_00431948(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 t;
    s32 idx;
    O_00431948 *o;
    f32 s;
    u8 *e;

    if (*(u16 *)(m + 0x96) < 0xFFFF) {
        *(u16 *)(m + 0x96) += 1;
    }
    if (m[0x20] != 2) {
        func_L01_0044ABD0(m, v + 0x70);
    }
    switch (m[0x20]) {
    case 0:
        t = -1;
        if (*(s8 *)(D_001D5F30_sda + 0x190) == 0) {
            func_003C2880(m);
            break;
        }
        idx = *(s32 *)(v + 0x8C);
        if (idx >= 0) {
            t = func_L40_003F6078(D_L40_0024845C + idx * 0x100);
        }
        *(s32 *)(func_L39_0066C828(m, -1, 1) + 0x28) = t;
        *(s32 *)(v + 0x88) = t;
        func_L39_0061C1E0(m, -1);
        o = func_L39_0061D7B0(m);
        if (o->vt->f1C(o, 0) != 0) {
            m[0xBE] = (m[0xBE] | 0x10) & ~8;
        } else if (o->vt->f1C(o, 1) != 0) {
            m[0xBE] = (m[0xBE] | 8) & ~0x10;
        } else {
            m[0xBE] &= ~0x18;
        }
        *(s32 *)(v + 0x90) = 0;
        *(u16 *)(m + 0x34) |= 0x4000;
        *(s32 *)(v + 0x94) = -1;
        *(f32 *)(v + 0x30) = *(s16 *)(v + 0x34);
        v[0x3E] = 3;
        v[0x38] = v[0x88];
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        idx = *(s32 *)(v + 0x94);
        if (idx == -1 || *(u8 **)((e = D_001FE020 + (idx << 7)) + 0xDC) != m || e[0xD0] == 0) {
            *(s32 *)(v + 0x94) = func_L39_005F33E0(1, 4, m);
        }
        func_L40_00431EA0(m);
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            func_L40_00431C00(m);
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
            func_L39_005F2FF8(m, 1);
            *(s32 *)(v + 0x84) = D_L40_00247A1C;
        }
        if (func_L39_005B4398(4) != 0) {
            break;
        }
        if (*(s32 *)(v + 0x84) > 0) {
            s = *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
            func_L40_004311A8(m, D_L40_00247A10, 0x32, D_L40_00247A18, D_L40_00247A14 * s, D_L40_00247A04 * s, D_L40_00247A08 * s, s);
            *(s32 *)(v + 0x84) -= 1;
        }
        break;
    }
}
/* localdecomp:end func_L40_00431948 */

INCLUDE_ASM("asm/levels", func_L40_00431C00);

INCLUDE_ASM("asm/levels", func_L40_00431EA0);
