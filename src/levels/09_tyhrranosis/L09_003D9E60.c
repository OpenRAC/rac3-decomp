#include "common.h"

/* localdecomp:start func_L09_003D9E60 */
extern void func_L09_003DA2A8(u8 *);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_0038D308(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0039EF28(void);
extern void func_L09_00317588(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L03_0043FC00(void *, s32, void *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L09_003CCB28(void *, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern u8 *D_L09_001E009C;
extern f32 D_L09_002F1D74 __attribute__((section(".data")));
extern u8 D_001426E0[];
extern s32 D_L09_001D66B0[2];

void func_L09_003D9E60(u8 *a0) {
    u8 *q;
    u8 *o;
    func_L09_003DA2A8(a0);
    *(u16 *)(a0 + 0x34) &= ~0x100;
    q = *(u8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0: {
        u16 v;
        *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        *(s16 *)(q + 0x8A) = *(s16 *)(q + 0x88);
        if (func_L01_0041A4F0() != 0) {
            *(s16 *)(q + 0x8A) = *(s16 *)(q + 0x8A) * (s32)D_L09_002F1D74;
        }
        v = *(u16 *)(q + 0x8A);
        q[0x38] = 1;
        q[0x39] = 0;
        q[0x3F] = 0;
        q[0x64] = 0;
        *(f32 *)(q + 0x40) = 0.5f;
        q[0x3E] = 3;
        *(f32 *)(q + 0x30) = (f32)(s16)v;
        q[0x58] = 0x14;
        q[0x5A] = 0xE;
        *(u16 *)(q + 0x34) = v;
        func_L01_004450F0(a0, 1, -1);
        break;
    }
    case 1:
        if (func_L01_004561B8(a0) != 0) {
            break;
        }
        if (a0[0x31] != 0) {
            f32 f;
            f32 s;
            *(u16 *)(a0 + 0x34) |= 0x100;
            func_0038D308(a0 + 0xC0, a0 + 0xF0);
            f = func_0038DAB8(*(f32 *)(q + 0x94), *(f32 *)(q + 0x98));
            *(f32 *)(q + 0x94) = f;
            *(f32 *)(q + 0x98) = (*(f32 *)(q + 0x98) - 0.13962635f) * 0.97600001f + 0.13962635f;
            s = func_0038D0B0(f) * 0.02f + 0.99f;
            func_0038CF68(a0 + 0xC0, a0 + 0xC0, s);
            func_0038CF68(a0 + 0xD0, a0 + 0xD0, s);
            func_0038CF68(a0 + 0xE0, a0 + 0xE0, 1.0f / (s * s));
        }
        if (*(s32 *)(q + 0x80) != -1) {
            o = D_L09_001E009C + (*(s32 *)(q + 0x80) << 8);
            if (*(s16 *)(o + 0xAA) == 0x1A77) {
                *(s32 *)(*(u8 **)(o + 0x68) + 0xC) = 0;
            }
        }
        break;
    case 2: {
        s16 n = *(s16 *)(q + 0x8E);
        if (n < 2) {
            s32 i = n + 0x1A;
            if (D_001426E0[i] == 0) {
                D_001426E0[i] = 1;
                func_0039EF28();
            }
        }
        if (*(s32 *)(q + 0x84) != -1) {
            u8 *m = D_L09_001E009C + (*(s32 *)(q + 0x84) << 8);
            if (*(s16 *)(m + 0xAA) == 0xC2B) {
                func_L09_00317588(m);
            }
        }
        func_003A52A0(0, 0, a0);
        func_L03_0043FC00(a0, 0x1FFF, D_L09_001D66B0, 2, 3, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
        func_L01_004443E8(a0, 0, 3);
        if (*(s32 *)(q + 0x80) != -1) {
            s16 id;
            o = D_L09_001E009C + (*(s32 *)(q + 0x80) << 8);
            id = *(s16 *)(o + 0xAA);
            if (id == 0x1A77) {
                *(s32 *)(*(u8 **)(o + 0x68) + 0xC) = 1;
            } else if (id == 0x1A19) {
                func_L09_003CCB28(o, *(s16 *)(q + 0x8E) + 0x1A);
            }
        }
        func_L01_003303B8(a0 + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x14, 0, 1.25f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
            0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C2880(a0);
        return;
    }
    }
    if (a0[0x31] != 0) {
        func_L01_00451DB8(a0, q + 0x90, 0x8A909090, 0x8A303030, 0.12566371f);
    }
}
/* localdecomp:end func_L09_003D9E60 */

/* localdecomp:start func_L09_003DA2A8 */
extern f32 D_001A4C60[];
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_0038CB00(void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
void func_L09_003DA2A8(u8 *a0) {
    u8 *q;
    u8 *hit;
    u8 *o;
    if (a0[0x20] == 0) {
        return;
    }
    q = *(u8 **)(a0 + 0x68);
    func_L01_0044ABD0(a0, q + 0x70);
    if (func_0038CB00(q + 0x8C) != 0 && *(f32 *)(a0 + 0x18) - D_001A4C60[2] < 10.0f) {
        hit = (u8 *)func_L01_00447490(a0, 0x30000, 0);
        if (hit != 0 && (o = *(u8 **)(hit + 0x20)) != 0 && *(s16 *)(o + 0xAA) != 0xABC && *(s16 *)(o + 0xAA) != 0x1A17) {
            f32 dmg = *(f32 *)(hit + 0x2C);
            *(s16 *)(q + 0x8C) = 10;
            q[0x77] = 0xFF;
            *(s16 *)(q + 0x8A) -= (s32)dmg;
            func_003C4A40(a0, q + 0x70);
            *(f32 *)(q + 0x98) = 0.31415927f;
            if (*(s16 *)(q + 0x8A) <= 0) {
                func_L01_004450F0(a0, 2, -1);
            } else {
                func_003A52A0(1, 0, a0);
            }
        }
    }
    a0[0xA8] = 0xFF;
    *(f32 *)(q + 0x30) = (f32)*(s16 *)(q + 0x8A);
}
/* localdecomp:end func_L09_003DA2A8 */
