/* functional: medium. Written from the PAL asm only. Main per-frame work of the Marcadia boss-type object (called by func_L04_00360D80): keeps its eight child objects (state+0x4B0..) in step while its health-like float at +0x30 is positive; reacts when the player is near (<24 units) and its state byte +0x61 is 0x3F or the global target at D_001E0E78 is close (<6 units, within the per-slot threshold in D_002C5F40); runs the hit/damage test (func_L01_00452FB0 / func_L01_00452860), kills the children and finishes (func_L04_003627C8) when that reports a hit; counts a one-time kill in world 0x16 (D_001D67C4, announce at 15); picks the hurt reaction (func_L01_00456BD0 type 3/5) and on a matching 8-frame beat of the global frame counter plays the idle effect (func_L01_00456C98 with state+0x2E0/0x2E8 parameters); finally tests the linked-target chain at +0x4D0/+0x4D4 (types 1/2/4, or 3 in world 0x1D) and copies the target pose into +0x220/+0x230. Returns 1 when the object finished (func_L04_00362568), else 0. Unsure: the semantic names of most state fields. The stack arguments of func_L01_00456C98 are the two booleans (state+0x500 != 0 and state+0x510 != 0) retail passes. */
#include "common.h"
#include "vu0.h"

extern s32 D_001D545C;
extern s32 D_001DF940;
extern s32 D_001D67C4;
extern u8 *D_001E0E78;
extern u8 D_00142637;
extern u8 D_001A4BE0[];
extern u8 D_L04_002C5F40[];
extern u8 D_L04_001E2840[];
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_003C7C38(void *);
extern void func_L01_004472C0(void *);
extern s32 func_L04_00361DB8(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00445BE0(s32, s32);
extern void func_L04_003627C8(void *);
extern void func_L01_00452860(void *, void *, s32);
extern void func_L01_00459C50(s32);
extern void func_L04_00362568(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00456500(void *, s32);

s32 func_L04_00361DF8(void *op) {
    u8 *o = op;
    u8 *m = *(u8 **)(o + 0x68);
    u8 *c;
    s32 i, r, hit, x, s3, cnt;
    f32 f20, d;
    unsigned long bits;

    if (0.0f < *(f32 *)(m + 0x30)) {
        for (i = 0; i < 8; i++) {
            c = *(u8 **)(m + 0x4B0 + i * 4);
            if (c != 0) {
                *(s32 *)(c + 0x98) = *(s32 *)(*(u8 **)(c + 0x24) + 0x10);
                func_003C7C38(c);
            }
        }
    }
    if (o[0x31] != 0) {
        d = func_L01_0040E548(D_L04_001E2840, o + 0x10);
        if (d < 576.0f) {
            func_L01_004472C0(o);
            o[0x6F] = 0x16;
        }
    }
    if (m[0x3E] == 2) {
        func_L04_00362568(o);
        return 1;
    }
    if (m[0x61] == 0x3F) {
        if (func_L04_00361DB8(o, m) != 0) {
            func_L01_004450F0(o, 0x1D, -1);
            if (o[0x43] != 0x14) func_003C3A10(o, 0x14, 1, 2);
        }
    }
    if (D_001E0E78 != 0) {
        if (func_L04_00361DB8(o, m) != 0) {
            d = func_0038CF38(o + 0x10, D_001E0E78 + 0x10);
            if (d < 6.0f) {
                f32 lim = *(f32 *)(D_L04_002C5F40 + D_00142637 * 0xF0 + 0x6C);
                if (*(f32 *)(m + 0x30) <= lim) {
                    func_L01_004450F0(o, 0x1D, -1);
                    if (o[0x43] != 0x14) func_003C3A10(o, 0x14, 1, 2);
                }
            }
        }
    }
    c = *(u8 **)(m + 0x2FC);
    if (c != 0) {
        func_L01_0044FD88(o, c, 0, 0);
    }
    s3 = (s32)*(f32 *)(m + 0x30);
    f20 = (f32)s3;
    hit = func_L01_00452FB0(o, m + 0x160, 0, 0, *(s32 *)(m + 0x4E4) != 0 ? 1 : 0);
    if (hit != 0) {
        if (*(s32 *)(m + 0x4E4) != 0 && hit >= 2) {
            func_003A52A0(5, 0, o);
        } else if (*(s32 *)(m + 0x4E4) == 0) {
            func_003A52A0(5, 0, o);
        }
        for (i = 0; i < 8; i++) {
            c = *(u8 **)(m + 0x4B0 + i * 4);
            if (c != 0) {
                *(s32 *)(c + 0x98) = 0;
                func_003C7C38(c);
            }
        }
        if (o[0x21] != 0xFF) func_L01_00445BE0(o[0x21], 0);
        func_L04_003627C8(o);
    }
    if (*(f32 *)(m + 0x30) < f20) {
        *(s32 *)(m + 0x2F8) = 1;
        func_L04_003627C8(o);
    }
    func_L01_00452860(o, m + 0x30, 0);
    if (m[0x5F] != 0 && D_001D545C == 0x16 && *(s32 *)(m + 0x50C) == 0) {
        *(s32 *)(m + 0x50C) = 1;
        cnt = D_001D67C4 + 1;
        D_001D67C4 = cnt;
        if (cnt >= 0xF) func_L01_00459C50(0x17);
    }
    if (m[0x5E] != 0) {
        func_L04_00362568(o);
        return 1;
    }
    bits = *(unsigned long *)(o + 0x30);
    x = D_001DF940;
    if ((bits & (0x8208UL << 29)) == (0x8200UL << 23) && *(s32 *)(o + 0x98) == 0) {
        /* skip the hurt reaction */
    } else if (0.0f < *(f32 *)(m + 0x30)) {
        if (m[0x5F] != 0) {
            func_L01_00456BD0(o, 5);
            x = D_001DF940;
        } else if (D_001D545C != 9 || *(s16 *)(o + 0xB2) == 0xCA || o[0x95] == 3 || o[0x95] == 5) {
            func_L01_00456BD0(o, 3);
            x = D_001DF940;
        }
    }
    s3 = *(s16 *)(o + 0xB2) + 8;
    if ((s3 % 8) == (x % 8)) {
        if (m[0x5F] != 0) {
            if (o[0x95] == 1) {
                func_L01_00456C98(o, *(s32 *)(m + 0x2E0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(m + 0x2E4), 10.0f, 1.0f);
            } else {
                func_L01_00456C98(o, *(s32 *)(m + 0x2E8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(m + 0x2EC), 10.0f, 1.0f);
            }
        } else if (o[0x95] == 1 || o[0x95] == 8) {
            func_L01_00456C98(o, *(s32 *)(m + 0x2E0), 0, 0, 0, 0, 1, *(s32 *)(m + 0x500) != 0, 0, *(s32 *)(m + 0x510) != 0, *(f32 *)(m + 0x2E4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(o, *(s32 *)(m + 0x2E8), 0, 0, 0, 0, 1, *(s32 *)(m + 0x500) != 0, 0, *(s32 *)(m + 0x510) != 0, *(f32 *)(m + 0x2EC), 10.0f, 1.0f);
        }
    }
    if (*(s32 *)(m + 0x4D0) == -1) return 0;
    if (*(s32 *)(m + 0x4D4) == -1) return 0;
    if (*(s16 *)(m + 0x234) == 1 && D_001D545C != 0x1D) return 0;
    r = o[0x95];
    if (r != 1 && r != 4 && r != 2 && (D_001D545C != 0x1D || r != 3)) return 0;
    if (func_L01_00456500(D_001A4BE0 + 0x80, *(s32 *)(m + 0x4D0)) != 0) {
        *(s32 *)(m + 0x4D8) = 1;
        *(s32 *)(m + 0x230) = *(s32 *)(D_001A4BE0 + 0x25C0);
        *(vu0_v4 *)(m + 0x220) = *(vu0_v4 *)(D_001A4BE0 + 0xD0);
    } else {
        *(s32 *)(m + 0x4D8) = 0;
    }
    return 0;
}
