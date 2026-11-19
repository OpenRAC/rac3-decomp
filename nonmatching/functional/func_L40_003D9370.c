/* functional: high. not byte exact: float constants via lui/ori in retail but .sdata here, branch layout of the kill test; semantics identical; table D_L40_0035746C read as pointer+0x88 array as neighbours do */
#include "common.h"
extern u8 *D_L40_0035746C __attribute__((section(".data")));
extern u8 D_L40_00249FC0[];
extern void func_L40_0053DAE8(u8 *a0, s32 team);
extern f32 func_003C3D30(void *, s32, f32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L40_0053F850(u8 *m, u8 *p, s32 a2);
extern u32 func_L40_0053F018(u8 *p);
extern void func_L39_0066C470(void *);
extern void func_L40_003D8FB0(u8 *a0, u8 *a1);
extern f32 func_L01_0040E548(u8 *, u8 *);
extern void func_L01_004472C0(u8 *);

void func_L40_003D9370(u8 *m, u8 *s, u8 *a2) {
    s32 r;
    s32 kill;

    if (*(u8 *)(m + 0x20) == 0) {
        f32 v[4];
        func_L40_0053DAE8(a2, *(s32 *)(D_L40_0035746C + 0x88 + *(s32 *)(s + 0x1A0) * 4));
        *(u16 *)(s + 0x118) &= 0xFFFC;
        *(u8 *)(s + 0x128) = 0xFF;
        *(f32 *)(s + 0x13C) = 0.0005f;
        *(u8 *)(s + 0xF2) = 3;
        *(f32 *)(s + 0x138) = 0.0001f;
        *(f32 *)(s + 0x30) = *(f32 *)(s + 0x1C4);
        *(u8 *)(s + 0x3E) = 1;
        *(u8 *)(s + 0xF0) = 3;
        *(u8 *)(s + 0xF1) = 3;
        *(s32 *)(s + 0x1A8) = 0;
        v[0] = *(f32 *)(m + 0x10);
        v[1] = *(f32 *)(m + 0x14);
        v[2] = *(f32 *)(m + 0x18);
        v[3] = *(f32 *)(m + 0x1C);
        v[2] += 1.0f;
        *(f32 *)(m + 0x18) = func_003C3D30(v, 0, 0.5f, 0);
        func_L01_004450F0(m, 1, -1);
    }
    r = func_L40_0053F850(m, s + 0xE0, 0);
    kill = 0;
    if (r == 4 || *(f32 *)(s + 0x30) <= 0.0f) {
        if (func_L40_0053F018(m) != 0) {
            kill = 1;
        }
    }
    if (kill == 0 && *(f32 *)(s + 0x30) < 0.0f) {
        kill = 1;
    }
    if (kill != 0) {
        func_L39_0066C470(a2);
    }
    func_L40_003D8FB0(a2, m);
    if (*(u8 *)(m + 0x31) != 0) {
        if (func_L01_0040E548(D_L40_00249FC0, m + 0x10) < 256.0f) {
            func_L01_004472C0(m);
            *(u8 *)(m + 0x6F) = 0xF;
        }
    }
}
