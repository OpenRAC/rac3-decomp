/* functional: high. check.py at level_06: 200 diffs, but the opening is instruction-for-instruction identical and the rest is one-instruction shifts and a local copy of m[0x20] (retail re-loads it); every branch, call argument and store was re-derived from the assembly. D_L06_001E1700 declared u8[] here (the file defines its struct type later). */
#include "vu0.h"
#include "common.h"
extern void func_L01_0044ABD0(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_0038CC88(void *, void *, s32);
extern void func_L06_00352110(u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_0038CAD0(void *);
extern void func_L06_00351678(u8 *, u8 *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern u8 D_L06_001E1700[];
extern u8 D_001A4C60[];
extern s32 D_001A71A0[];

s32 func_L06_00351C48(u8 *m, u8 *v) {
    s32 k;
    u8 *p;
    u8 c;

    if (m[0x20] == 0x1F) {
        func_L01_0044ABD0(m, v + 0x160);
        func_L01_0044ABD0(*(u8 **)(v + 0x260), v + 0x250);
        return 1;
    }
    if (m[0x31] != 0) {
        if (func_L01_0040E548(D_L06_001E1700, m + 0x10) < 576.0f) {
            func_L01_004472C0(m);
            m[0x6F] = 0x16;
        }
    }
    p = *(u8 **)(v + 0x260);
    if (p != 0 && p[0x31] != 0) {
        if (func_L01_0040E548(D_L06_001E1700, p + 0x10) < 576.0f) {
            func_L01_004472C0(*(u8 **)(v + 0x260));
            (*(u8 **)(v + 0x260))[0x6F] = 0x16;
        }
    }
    k = func_L01_00452FB0(m, v + 0x160, 0, 0, 0);
    if (k != 0 || *(f32 *)(v + 0x30) <= 0.0f) {
        func_0038CC88(v + 0x250, v + 0x160, 0x10);
        if (k == 5) {
            func_L06_00352110(m, v);
            return 0;
        }
        if (k == 4 || *(f32 *)(v + 0x30) <= 0.0f) {
            if (*(s32 *)(v + 0x350) != 0) {
                func_L06_00352110(m, v);
                return 0;
            }
            func_L01_004450F0(m, 0x1F, -1);
            return 1;
        }
        if ((k == 2 && 0.0f < *(f32 *)(v + 0x328)) || k == 3) {
            c = m[0x20];
            if ((u8)(c - 0xD) >= 2) {
                if (c != 0x1E && c != 0x18 && m[0x94] != 0x18) {
                    if (*(s32 *)(v + 0x350) != 0) {
                        func_L01_004450F0(m, 0xE, -1);
                    } else if ((u8)(c - 4) >= 0xB) {
                        func_L01_004450F0(m, 0x1E, -1);
                    } else {
                        func_L01_004450F0(m, 0xD, -1);
                    }
                }
            }
        }
        if (m[0x95] == 0 && m[0x20] == 1) {
            func_L01_004450F0(m, 2, -1);
        }
    }
    if (v[0x3E] == 2 || v[0x5E] != 0) {
        func_L06_00352110(m, v);
        return 0;
    }
    func_L01_0044ABD0(*(u8 **)(v + 0x260), v + 0x250);
    func_L01_00452860(m, v + 0x30, 0);
    if (v[0x5F] != 0) {
        if (m[0x95] != 0) {
            func_L01_00456BD0(m, 5);
        }
        func_L01_00456C98(m, *(s32 *)(v + 0x378), *(f32 *)(v + 0x31C) + *(f32 *)(v + 0x31C), 0, 0, 0, 0, 3, 0,
                          15.0f, 1.0f, 0, 0);
    } else {
        if (m[0x95] != 0) {
            func_L01_00456BD0(m, 3);
        }
        if (*(s32 *)(v + 0x398) != 0) {
            func_0038CAD0(v + 0x398);
            func_L01_00456C98(m, *(s32 *)(v + 0x378), *(f32 *)(v + 0x31C) + *(f32 *)(v + 0x31C), 0, 0, 0, 0, 4, 0,
                              15.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(m, *(s32 *)(v + 0x378), *(f32 *)(v + 0x31C) + *(f32 *)(v + 0x31C), 0, 0, 0, 0, 1, 0,
                              15.0f, 1.0f, 0, 0);
            if (*(s16 *)(v + 0x23C) != 0 && *(s32 *)(v + 0x230) != D_001A71A0[0]) {
                if (func_L06_00351BB8(m, v) == 0) {
                    func_L01_00456C98(m, *(s32 *)(v + 0x378), *(f32 *)(v + 0x31C) + *(f32 *)(v + 0x31C), 0, 0, 0, 0,
                                      4, 0, 15.0f, 1.0f, 0, 0);
                    *(s32 *)(v + 0x398) = 0x78;
                }
            }
        }
    }
    func_0038CAD0(v + 0x324);
    func_0038CAD0(v + 0x388);
    func_L06_00351678(m, v);
    if (*(s32 *)(v + 0x30C) != -1) {
        if (func_00382380(D_001A4C60, *(s32 *)(v + 0x30C), 0) != 0) {
            *(s32 *)(v + 0x30C) = -1;
            *(f32 *)(v + 0x308) = 1.0f;
        }
    }
    func_L01_00451DF8(*(u8 **)(v + 0x260), v + 0x500, 4, 1, 2.5f);
    return 1;
}
