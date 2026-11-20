#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003C4F88);

/* localdecomp:start func_L05_003C6080 */
extern u8 D_001A30B0[];
extern s32 D_001D545C;
extern s32 func_L05_003C63A8_003C6080(void);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L05_003C66F0_003C6080(u8 *a0);
extern s32 func_L01_00452FB0_003C6080(void *, void *, s32, s32, s32);
extern void func_L05_003C6920_003C6080(void *);
extern void func_L01_00455E18_003C6080(void *, void *, void *);
extern s32 func_L01_00452860_003C6080(void *, void *, s32);
extern void func_L01_00456BD0_003C6080(void *, s32);
extern void func_L01_00456C98_003C6080(void *, s32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, f32);

s32 func_L05_003C6080(u8 *o) {
    u8 *t;
    u8 *e;
    s32 id;

    t = *(u8 **)(o + 0x68);
    if (o[0x20] == 0) {
        if (func_L05_003C63A8_003C6080() != 0) {
            return 1;
        }
    }
    id = *(s32 *)(t + 0x420);
    if (id == -1 || (e = D_001A30B0 + id * 0x80, *(u8 **)(e + 0xDC) != o) || e[0xD0] == 0) {
        *(s32 *)(t + 0x420) = func_003A52A0(3, 4, o);
    }
    if (t[0x3E] == 2) {
        func_L05_003C66F0_003C6080(o);
        return 1;
    }
    if (o[0xBC] != 0) {
        o[0xBC] = o[0xBC] - 1;
    }
    if (o[0x20] == 4 && D_001D545C == 0xB) {
        if (func_L01_00452FB0_003C6080(o, t + 0x160, 0, 0, 1) != 0) {
            if (o[0xBC] == 0) {
                func_003A52A0(4, 0, o);
                o[0xBC] = 0x19;
            }
            *(s16 *)(t + 0x42A) = 1;
            func_L05_003C6920_003C6080(o);
        }
    } else {
        if (func_L01_00452FB0_003C6080(o, t + 0x160, 0, 0, 0) != 0) {
            if (o[0xBC] == 0) {
                func_003A52A0(4, 0, o);
                o[0xBC] = 0x19;
            }
            *(s16 *)(t + 0x42A) = 1;
            func_L05_003C6920_003C6080(o);
        }
    }
    func_L01_00455E18_003C6080(o, t + 0x240, t + 0x30);
    func_L01_00452860_003C6080(o, t + 0x30, 0);
    if (t[0x5E] != 0) {
        func_L05_003C66F0_003C6080(o);
        return 1;
    }
    if (t[0x5F] != 0) {
        func_L01_00456BD0_003C6080(o, 5);
        if (o[0x95] == 0) {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E0), *(f32 *)(t + 0x2E4), 10.0f, 0, 0, 0, 0, 3, 0, 0, 0, 1.0f);
        } else {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E8), *(f32 *)(t + 0x2EC), 10.0f, 0, 0, 0, 0, 3, 0, 0, 0, 1.0f);
        }
    } else {
        func_L01_00456BD0_003C6080(o, 3);
        if (*(s16 *)(t + 0x42A) != 0) {
            func_L01_00456C98_003C6080(o, -1, 256.0f, 256.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        } else if (o[0x95] == 0) {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E0), *(f32 *)(t + 0x2E4), 10.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        } else {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E8), *(f32 *)(t + 0x2EC), 10.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L05_003C6080 */

INCLUDE_ASM("asm/levels", func_L05_003C63A8);

/* localdecomp:start func_L05_003C66F0 */
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_00459C50(s32);
extern s32 D_001D545C;
extern s32 D_L05_001D67BC;
extern u8 D_L05_001D66B0[8];

void func_L05_003C66F0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    if (D_001D545C == 0x11 && (pv[0x60] != 0 || pv[0x47] == 0x87)) {
        D_L05_001D67BC = D_L05_001D67BC + 1;
        if (D_L05_001D67BC >= 0x28) {
            func_L01_00459C50(0x13);
        }
    }
    func_L01_004443E8(a0, 0, 3);
    func_L01_00452310(a0, 0x3FFF, D_L05_001D66B0, 1, 0x28, -1.0f, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
}
/* localdecomp:end func_L05_003C66F0 */

/* localdecomp:start func_L05_003C67C0 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern u8 D_L05_001E2700[];

void func_L05_003C67C0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 a;
    f32 b;
    func_0038CAD0(v + 0x2F0);
    func_0038CB00(v + 0x2F4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        (*(u16 *)(a0 + 0x96))++;
    }
    func_L01_00451DF8(a0, v + 0x260, 4, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L05_001E2700, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x1E;
        }
    }
    a = 0.0432000011f;
    *(f32 *)(v + 0x42C) = func_0038DAB8(*(f32 *)(v + 0x42C), 0.069813177f);
    b = 0.432000041f;
    *(s32 *)(a0 + 0x78) = func_0038DBD8(0x80A0A0A0, 0x60101010, (func_0038D0B0(*(f32 *)(v + 0x42C)) + 1.0f) * 0.5f);
    func_L01_0044E850(a0, v + 0x300, 0, a, b);
    func_L01_0044E850(a0, v + 0x380, 1, a, b);
}
/* localdecomp:end func_L05_003C67C0 */
