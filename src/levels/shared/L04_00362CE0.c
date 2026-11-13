#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00362CE0 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L04_00362CE0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *cls;
    u8 *m;
    s32 t;
    pv[0x5E] = 0;
    pv[0x60] = 0;
    pv[0x5F] = 0;
    qzero(a0 + 0xF0);
    cls = *(u8 **)(a0 + 0x24);
    *(f32 *)(a0 + 0x2C) = *(f32 *)(cls + 0x24);
    *(vu0_q *)(a0 + 0x10) = *(vu0_q *)(pv + 0x320);
    *(f32 *)(a0 + 0xF8) = *(f32 *)(pv + 0x36C);
    *(u16 *)(a0 + 0x34) &= ~0x41;
    *(u16 *)(a0 + 0x34) |= *(u16 *)(cls + 0x44) & 0x1000;
    t = *(s32 *)(cls + 0x10);
    *(u16 *)(a0 + 0x34) &= ~2;
    *(s32 *)(a0 + 0x98) = t;
    if (*(u8 **)(pv + 0x2FC) == 0) {
        m = func_003C24B0(0x194E, 0x80);
        *(u8 **)(pv + 0x2FC) = m;
        if (m != 0) {
            func_L01_00456160(m, a0);
            *(u16 *)(*(u8 **)(pv + 0x2FC) + 0x32) = *(u16 *)(a0 + 0x32);
            *(u8 **)(pv + 0x240) = *(u8 **)(pv + 0x2FC);
        }
    }
    func_L01_004450F0(a0, 0xB, 3);
    if (a0[0x43] != 3) {
        func_003C3A10(a0, 3, 0, 0);
    }
    if (*(s32 *)(pv + 0x30C) != -1) {
        func_L01_004450F0(a0, 9, -1);
    }
}
/* localdecomp:end func_L04_00362CE0 */

/* localdecomp:start func_L04_00362DF0 */
extern u8 *func_00382348(void *);
extern u8 *func_L01_00448FF0(u8 *);
extern s32 func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003A4F28(s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L04_00362DF0(u8 *a0) {
    s32 i;
    u8 *p;
    u8 *q;
    a0[0x7F] = 0;
    p = func_00382348(a0);
    *(f32 *)p = *(s16 *)(p + 4);
    q = func_L01_00448FF0(a0);
    *(s16 *)(q + 0x38) = 0;
    q[7] = 0;
    q[9] = 0;
    q[8] = 0;
    func_L01_00456C98(a0, -1, 0, 0, 0, 0, 3, 0, 0, 0, 0.0f, 0.0f, 1.0f);
    *(s32 *)(a0 + 0x98) = 0;
    a0[0xA8] = 0xFF;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x43) & ~0x1000;
    func_L01_004AA7E8(a0, 1);
    for (i = 0; i < 0x34; i++) {
        if (func_L01_004AA710(a0, i) != 0) {
            func_003A4F28(i);
        }
    }
    func_L01_004450F0(a0, 0x1A, 7);
}
/* localdecomp:end func_L04_00362DF0 */

/* localdecomp:start func_L04_00362EF0 */
u8 func_L04_00362EF0(u8 *s) {
    long r = 0;
    if (s[0x95] == 7) {
        s32 t = s[0x20] == 0x1A;
        r = t;
    }
    return r;
}
/* localdecomp:end func_L04_00362EF0 */

/* localdecomp:start func_L04_00362F18 */
extern s32 func_L01_004561E0(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L04_00361D20(u8 *, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_003A52A0(s32, s32, void *);
extern u8 *D_L04_001DFA4C;
extern u8 *D_L04_001DFD9C;

s32 func_L04_00362F18(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    u8 *nav;
    s32 ok;
    if (func_L01_004561E0(a0) != 0 && *(s32 *)(pv + 0x374) == 0 && *(s16 *)(pv + 0x2F6) == 0) {
        *(s16 *)(pv + 0x2F6) = (func_00382498(0, 40) * 5 + 2) / 6;
    }
    ok = 1;
    if (*(s32 *)(pv + 0x4F4) != -1 && func_L01_00456250(D_L04_001DFD9C + (*(s32 *)(pv + 0x4F4) << 8)) == 0) {
        ok = 0;
    }
    if (*(s16 *)(pv + 0x234) == 1 && ok != 0 && func_0038CB00(pv + 0x2F6) != 0) {
        if (*(s32 *)(pv + 0x504) != 0) {
            func_003A52A0(2, 0, a0);
        }
        func_L01_004450F0(a0, 0xB, 3);
        if (*(s32 *)(pv + 0x30C) != -1) {
            func_L01_004450F0(a0, 9, -1);
        } else if (*(s32 *)(pv + 0x304) != -1) {
            func_L01_004450F0(a0, 10, -1);
        } else if (*(s32 *)(pv + 0x38C) != -1 && (row = D_L04_001DFA4C + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
            func_L01_004450F0(a0, 10, -1);
        } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
            if (0.5f < func_0038CF38(a0 + 0x10, pv + 0x320)) {
                func_L01_004450F0(a0, 10, -1);
            } else if (func_L04_00361D20(a0, pv) != 0) {
                func_L01_004450F0(a0, 0x12, -1);
            } else {
                func_L01_004450F0(a0, 0xD, -1);
            }
        }
        if (*(s32 *)(pv + 0x4E8) != 0) {
            func_L01_004450F0(a0, 0xC, -1);
        }
        return 1;
    }
    if (*(s32 *)(pv + 0x4D8) != 0) {
        if (*(s32 *)(pv + 0x4D4) != -1 && (nav = D_L04_001DFA4C + *(s32 *)(pv + 0x4D4) * 0x30, *(s16 *)(nav + 0x32) != 0)) {
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 8);
            }
            func_L01_004450F0(a0, 10, 4);
        }
        return 0;
    }
    if (*(s32 *)(pv + 0x2F8) != 0 && func_0038CB00(pv + 0x2F6) != 0) {
        func_L01_004450F0(a0, 6, 2);
        *(s32 *)(pv + 0x2F8) = 0;
        if (*(s32 *)(pv + 0x2F0) < 0xFA) {
            *(s32 *)(pv + 0x2F0) = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00362F18 */

/* localdecomp:start func_L04_003631D0 */
extern s32 func_L01_004561E0(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L04_00361D20(u8 *, u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_001D545C;
extern u8 *D_L04_001DFA4C;

s32 func_L04_003631D0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    if (func_L01_004561E0(a0) != 0 && *(s32 *)(pv + 0x374) == 0 && *(s16 *)(pv + 0x2F6) == 0) {
        if (D_001D545C == 0x1D) {
            *(s32 *)(pv + 0x30C) = -1;
        }
        *(s16 *)(pv + 0x2F6) = (func_00382498(0, 40) * 5 + 2) / 6;
    }
    if (*(s16 *)(pv + 0x234) != 1) {
        return 0;
    }
    if (func_0038CB00(pv + 0x2F6) != 0) {
        if (D_001D545C != 0x1D || *(s32 *)(pv + 0x4D8) == 0) {
            func_L01_004450F0(a0, 0xB, 3);
            if (*(s32 *)(pv + 0x30C) != -1) {
                func_L01_004450F0(a0, 9, -1);
            } else if (*(s32 *)(pv + 0x304) != -1 || (*(s32 *)(pv + 0x38C) != -1 && (row = D_L04_001DFA4C + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0))) {
                func_L01_004450F0(a0, 10, -1);
            } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
                if (0.5f < func_0038CF38(a0 + 0x10, pv + 0x320)) {
                    func_L01_004450F0(a0, 10, -1);
                } else if (func_L04_00361D20(a0, pv) != 0) {
                    func_L01_004450F0(a0, 0x12, -1);
                } else {
                    func_L01_004450F0(a0, 0xD, -1);
                }
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_003631D0 */

/* localdecomp:start func_L04_00363388 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L04_00361D20(u8 *, u8 *);
extern u8 *D_L04_001DFA4C;

s32 func_L04_00363388(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    u8 *nav;
    if (*(s16 *)(pv + 0x234) == 1) {
        func_L01_004450F0(a0, 0xB, 3);
        if (*(s32 *)(pv + 0x30C) != -1) {
            func_L01_004450F0(a0, 9, -1);
        } else if (*(s32 *)(pv + 0x304) != -1) {
            func_L01_004450F0(a0, 0xA, -1);
        } else if (*(s32 *)(pv + 0x38C) != -1
            && (row = D_L04_001DFA4C + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
            func_L01_004450F0(a0, 0xA, -1);
        } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
            if (0.5f < func_0038CF38(a0 + 0x10, pv + 0x320)) {
                func_L01_004450F0(a0, 0xA, -1);
            } else if (func_L04_00361D20(a0, pv) != 0) {
                func_L01_004450F0(a0, 0x12, -1);
            } else {
                func_L01_004450F0(a0, 0xD, -1);
            }
        }
        if (*(s32 *)(pv + 0x4E4) != 0) {
            func_L01_004450F0(a0, 0xD, -1);
        }
        return 1;
    }
    if (*(s32 *)(pv + 0x4D8) != 0 && *(s32 *)(pv + 0x4D4) != -1
        && (nav = D_L04_001DFA4C + *(s32 *)(pv + 0x4D4) * 0x30, *(s16 *)(nav + 0x32) != 0)) {
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, 8);
        }
        func_L01_004450F0(a0, 0xA, 4);
    }
    return 0;
}
/* localdecomp:end func_L04_00363388 */

/* localdecomp:start func_L04_00363520 */
extern s32 func_L01_004561E0(void *);
extern void func_L01_00445BE0(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 D_001D545C;
extern u8 *D_L04_001DFA4C;

s32 func_L04_00363520(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    if (*(s16 *)(pv + 0x234) != 1 && func_L01_004561E0(a0) == 0) {
        if (a0[0x21] != 0xFF) {
            func_L01_00445BE0(a0[0x21], 0);
        }
        if (*(s32 *)(pv + 0x30C) == -1) {
            if (a0[0x43] != 2) {
                func_003C3A10(a0, 2, 0, 8);
            }
            func_L01_004450F0(a0, 4, 2);
            if (*(s32 *)(pv + 0x318) != 0) {
                func_L01_004450F0(a0, 7, -1);
            }
            if (*(s32 *)(pv + 0x4E4) != 0) {
                if (a0[0x43] != 1) {
                    func_003C3A10(a0, 1, 0, 8);
                }
                func_L01_004450F0(a0, 4, 2);
            }
        } else {
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 8);
            }
            func_L01_004450F0(a0, 6, 2);
        }
        *(s32 *)(pv + 0x2F0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        return 1;
    }
    if (D_001D545C == 0x1D && *(s32 *)(pv + 0x4D8) != 0 && *(s32 *)(pv + 0x4D4) != -1
        && (row = D_L04_001DFA4C + *(s32 *)(pv + 0x4D4) * 0x30, *(s16 *)(row + 0x32) != 0)) {
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, 8);
        }
        func_L01_004450F0(a0, 10, 4);
    }
    return 0;
}
/* localdecomp:end func_L04_00363520 */

/* localdecomp:start func_L04_003636F0 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L04_00361D20(u8 *, u8 *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00454370(void *, void *);
extern void func_L04_00362568(u8 *);
extern void func_L01_00315900(void *, s32, void *);
extern void func_L01_00356568_003636F0(void *);
extern u8 *D_L04_001DFA4C;

s32 func_L04_003636F0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    s32 hit;
    if (*(f32 *)(pv + 0x30) <= 0.0f) {
        *(f32 *)(pv + 0x194) = *(f32 *)(pv + 0x190) = 1.25f;
    }
    *(f32 *)(pv + 0x80) = 0.785398185f;
    hit = func_L01_00454370(a0, pv + 0x160);
    *(f32 *)(pv + 0x80) = 1.48352981f;
    if ((hit & 1) || (a0[0x42] == 0x15 && func_L01_0044E1B8(a0, 23.0f) != 0)
        || (*(f32 *)(pv + 0x30) <= 0.0f && *(u16 *)(a0 + 0x96) > 100)) {
        func_L04_00362568(a0);
        func_L01_00315900(a0, 0, func_L01_00356568_003636F0);
        return 5;
    }
    if (hit & 2) {
        if (*(s16 *)(pv + 0x234) == 1) {
            if (*(s32 *)(pv + 0x304) != -1) {
                func_L01_004450F0(a0, 0xA, 3);
            } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
                if (0.5f < func_0038CF38(a0 + 0x10, pv + 0x320)) {
                    func_L01_004450F0(a0, 0xA, 3);
                } else if (func_L04_00361D20(a0, pv) != 0) {
                    func_L01_004450F0(a0, 0x12, 3);
                } else {
                    func_L01_004450F0(a0, 0xD, 3);
                }
            } else if (*(s32 *)(pv + 0x38C) != -1
                && (row = D_L04_001DFA4C + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
                func_L01_004450F0(a0, 0xA, 3);
            } else {
                func_L01_004450F0(a0, 0xB, 3);
            }
        } else {
            func_L01_004450F0(a0, 6, 2);
            *(s32 *)(pv + 0x2F0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 0);
            }
            if (*(long *)(pv + 0x310) != -1) {
                func_L01_004450F0(a0, 5, 6);
            }
            if (*(s32 *)(pv + 0x300) != -1) {
                func_L01_004450F0(a0, 2, -1);
            } else if (*(s32 *)(pv + 0x318) == 0) {
                func_L01_004450F0(a0, 4, -1);
            } else if (*(s32 *)(pv + 0x4E4) != 0) {
                func_L01_004450F0(a0, 3, -1);
            }
        }
        pv[0x61] = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_003636F0 */

/* localdecomp:start func_L04_003639A0 */
extern u8 *D_L04_001DFD9C;
extern u8 *func_00382348(void *);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L04_003639A0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    s32 ok = 1;
    s32 h = *(s32 *)(pv + 0x310);
    u8 *m;
    u8 *p;
    if (h != -1) {
        m = D_L04_001DFD9C + (h << 8);
        if (m != 0 && m[0x20] != 0xFE && m[0x20] != 0xFD) {
            p = func_00382348(m);
            if (p == 0 || 0.0f < *(f32 *)p) {
                ok = 0;
            }
        }
    }
    if (*(s32 *)(pv + 0x314) != -1 && func_L01_00445AD0(*(s32 *)(pv + 0x314), -1, 1) != 0) {
        ok = 0;
    }
    if (ok != 0 || *(s16 *)(pv + 0x234) == 1) {
        *(s32 *)(pv + 0x310) = -1;
        *(s32 *)(pv + 0x314) = -1;
        *(s32 *)(pv + 0x2E0) = *(s32 *)(pv + 0x2E8);
        func_L01_004450F0(a0, 1, 1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_003639A0 */

/* localdecomp:start func_L04_00363AA0 */
extern s32 func_L01_004561B8();
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L04_00363AA0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0) != 0) {
        func_L01_0045BD78(a0, 0.0024f, 0.040000003f, 0.010053097f, 0.25132743f);
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 8);
        }
    }
    if (func_L01_0045BDE8(a0, *(s32 *)(pv + 0x300)) != 0) {
        func_L01_004450F0(a0, 3, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00363AA0 */

/* localdecomp:start func_L04_00363B60 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L03_00449C30(void *, s32, s32, s32);
extern s32 *D_L04_0021E240[];

s32 func_L04_00363B60(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    s32 *path;
    f32 d;
    if (func_L01_004561B8(a0) != 0) {
        *(f32 *)(a0 + 0x48) = func_003824E0(0.85000002f, 1.15f);
        if (a0[0x43] != 1) {
            func_003C3A10(a0, 1, 0, (s32)((func_003824E0(4.0f, 12.0f) * 5.0f + 2.0f) / 6.0f));
        }
    }
    if (a0[0x60] & 2) {
        if (*(s32 *)(pv + 0x300) != -1) {
            path = D_L04_0021E240[*(s32 *)(pv + 0x300)];
            func_L01_004450F0(a0, 2, -1);
            d = func_0038CF38(a0 + 0x10, path + 4);
            if (func_0038CF38(a0 + 0x10, path + path[0] * 4) < d) {
                func_L03_00449C30(a0, *(s32 *)(pv + 0x300), 0, path[0] - 1);
            } else {
                func_L03_00449C30(a0, *(s32 *)(pv + 0x300), path[0] - 1, 0);
            }
        } else {
            func_L01_004450F0(a0, 4, -1);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00363B60 */

/* localdecomp:start func_L04_00363D00 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_0045A898(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_0038CAD0(void *);

s32 func_L04_00363D00(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 a;
    f32 r;
    u8 *p;
    u8 *t;
    if (func_L01_004561B8(a0) != 0) {
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 8);
        }
        p = pv + 0x340;
        a = func_00382538();
        r = func_003824E0(2.0f, 6.0f);
        qzero(pv + 0x340);
        *(f32 *)(pv + 0x340) = func_0038D098(a) * r;
        *(f32 *)(pv + 0x344) = func_0038D0B0(a) * r;
        vec_add_ab(pv + 0x340, pv + 0x340, pv + 0x320);
        if (*(s32 *)(pv + 0x31C) != -1 && func_L01_00456500(p, *(s32 *)(pv + 0x31C)) == 0) {
            *(vu0_q *)(pv + 0x340) = *(vu0_q *)(pv + 0x320);
        }
        *(s32 *)(pv + 0x360) = func_00382498(0x12C, 0x212);
        func_L01_0045BD78(a0, 0.0024f, 0.040000003f, 0.010053097f, 0.25132743f);
    }
    if (*(s32 *)(pv + 0x4E4) == 0) {
        t = pv + 0x340;
        func_L01_0045A898(a0, t, *(f32 *)(a0 + 0xF8));
        func_L01_00448890(a0 + 0xF8, func_0038D160(*(f32 *)(pv + 0x340) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x344) - *(f32 *)(a0 + 0x14)), pv + 0x370, 0.0018151426f, 0.0018151426f, 0.034906588f, 0);
        if (func_0038CF38(a0 + 0x10, t) < 0.75f) {
            a = func_00382538();
            r = func_003824E0(2.0f, 6.0f);
            qzero(pv + 0x340);
            *(f32 *)(pv + 0x340) = func_0038D098(a) * r;
            *(f32 *)(pv + 0x344) = func_0038D0B0(a) * r;
            vec_add_ab(pv + 0x340, pv + 0x340, pv + 0x320);
            if (*(s32 *)(pv + 0x31C) != -1 && func_L01_00456500(t, *(s32 *)(pv + 0x31C)) == 0) {
                *(vu0_q *)(pv + 0x340) = *(vu0_q *)(pv + 0x320);
            }
        }
        if (func_0038CAD0(pv + 0x360) == 0) {
            return 0;
        }
    }
    func_L01_004450F0(a0, 3, -1);
    return 1;
}
/* localdecomp:end func_L04_00363D00 */

/* localdecomp:start func_L04_00363F80 */
extern s32 func_L01_004561B8();
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L04_0046CFE0(u8 *, s32 *);
extern s32 func_L01_0045BDE8(void *, s32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L04_00361D20(u8 *, u8 *);
extern void func_003C48A8(void *, void *);
extern s32 *D_L04_0021E240[];
extern u8 *D_L04_001DFA4C;
extern s32 D_001D545C;

s32 func_L04_00363F80(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    u8 *nav;
    if (func_L01_004561B8(a0) != 0) {
        func_L01_0045BD78(a0, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, 8);
        }
    }
    if (*(s32 *)(pv + 0x4E4) != 0) {
        if (func_L04_0046CFE0(a0, D_L04_0021E240[*(s32 *)(pv + 0x30C)]) == 0
            && (!(func_0038CF38(a0 + 0x10, pv + 0x220) < 6.0f) || *(s32 *)(pv + 0x4A4) != 0)) {
            return 0;
        }
        if (*(s32 *)(pv + 0x508) != 0) {
            *(u16 *)(a0 + 0x34) &= ~0x100;
            func_003C48A8(a0 + 0xC0, a0 + 0xF0);
            *(s32 *)(pv + 0x4E4) = 0;
        }
        *(s32 *)(pv + 0x30C) = -1;
        if (*(s32 *)(pv + 0x304) != -1) {
            func_L01_004450F0(a0, 0xA, -1);
        } else if (*(s32 *)(pv + 0x38C) != -1 && (row = D_L04_001DFA4C + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
            func_L01_004450F0(a0, 0xA, -1);
        } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
            if (0.5f < func_0038CF38(a0 + 0x10, pv + 0x320)) {
                func_L01_004450F0(a0, 0xA, -1);
            } else if (func_L04_00361D20(a0, pv) != 0) {
                func_L01_004450F0(a0, 0x12, -1);
            } else {
                func_L01_004450F0(a0, 0xD, -1);
            }
        } else {
            func_L01_004450F0(a0, 0xB, -1);
        }
        if (D_001D545C == 0x10 && *(s32 *)(pv + 0x4E4) != 0) {
            func_L01_004450F0(a0, 0xD, -1);
        }
        return 1;
    }
    if (func_L01_0045BDE8(a0, *(s32 *)(pv + 0x30C)) == 0
        && (!(func_0038CF38(a0 + 0x10, pv + 0x220) < 6.0f) || *(s32 *)(pv + 0x4A4) != 0)) {
        return 0;
    }
    if (*(s32 *)(pv + 0x508) != 0) {
        *(s32 *)(pv + 0x4E4) = 0;
    }
    *(s32 *)(pv + 0x30C) = -1;
    if (*(s32 *)(pv + 0x304) != -1) {
        func_L01_004450F0(a0, 0xA, -1);
    } else if (*(s32 *)(pv + 0x38C) != -1 && (nav = D_L04_001DFA4C + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(nav + 0x32) != 0)) {
        func_L01_004450F0(a0, 0xA, -1);
    } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
        if (0.5f < func_0038CF38(a0 + 0x10, pv + 0x320)) {
            func_L01_004450F0(a0, 0xA, -1);
        } else if (func_L04_00361D20(a0, pv) != 0) {
            func_L01_004450F0(a0, 0x12, -1);
        } else {
            func_L01_004450F0(a0, 0xD, -1);
        }
    } else {
        func_L01_004450F0(a0, 0xB, -1);
    }
    return 1;
}
/* localdecomp:end func_L04_00363F80 */

INCLUDE_ASM("asm/levels", func_L04_003642B8);

/* localdecomp:start func_L04_003649B8 */
extern s32 func_L01_004561B8();
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00459188(void *, s32, void *);
extern void func_L01_00458F78(void *, void *, s32, s32);
extern void func_L01_0045A748(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);

s32 func_L04_003649B8(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0) != 0) {
        func_L01_0045BD78(a0, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, (func_00382498(8, 14) * 5 + 2) / 6);
        }
        func_L01_00459188(a0, *(s32 *)(pv + 0x230), pv + 0x410);
    }
    if (*(s32 *)(pv + 0x4E4) == 0) {
        *(s32 *)(pv + 0x460) = *(s32 *)(pv + 0x230);
        func_L01_00458F78(a0, pv + 0x410, 0, 0);
        func_L01_0045A748(a0, pv + 0x410);
    }
    if (*(f32 *)(pv + 0x120) < *(f32 *)(pv + 0x98) * 0.8f) {
        (*(s32 *)(pv + 0x450))++;
    }
    if (*(s32 *)(pv + 0x230) != *(s32 *)(pv + 0x460)) {
        func_L01_00459188(a0, *(s32 *)(pv + 0x230), pv + 0x410);
    }
    if (func_0038CF38(a0 + 0x10, pv + 0x220) < 15.0f
        && func_0038DBA0(*(f32 *)(a0 + 0xF8), func_0038D160(*(f32 *)(pv + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x224) - *(f32 *)(a0 + 0x14))) < 0.17453292f) {
        func_L01_004450F0(a0, 0xD, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_003649B8 */

/* localdecomp:start func_L04_00364B90 */
extern s32 func_L01_004561B8();
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0045D218(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 D_001D545C;

s32 func_L04_00364B90(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    if (func_L01_004561B8(a0) != 0) {
        func_L01_0045BD78(a0, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, (func_00382498(8, 0xE) * 5 + 2) / 6);
        }
    }
    *(vu0_q *)&d = *(vu0_q *)(a0 + 0xC0);
    func_0038CF68(&d, &d, 2.0f);
    vec_add_ab(&d, &d, a0 + 0x10);
    func_L01_0045D218(a0, &d);
    if (D_001D545C != 0x16 && func_0038CF38(a0 + 0x10, pv + 0x220) < 15.0f
        && func_0038DBA0(*(f32 *)(a0 + 0xF8), func_0038D160(*(f32 *)(pv + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x224) - *(f32 *)(a0 + 0x14))) < 0.17453292f) {
        func_L01_004450F0(a0, 0xD, -1);
        return 1;
    }
    if (func_0038CAD0(pv + 0x4E8) != 0) {
        *(s32 *)(pv + 0x4E8) = 1;
        func_L01_004450F0(a0, 0xD, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00364B90 */

/* localdecomp:start func_L04_00364D38 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C48A8(void *, void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D0C8(f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern s32 D_001D545C;

s32 func_L04_00364D38(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_v4 m0[3];
    vu0_v4 d;
    vu0_v4 m1[3];
    vu0_v4 v;
    vu0_v4 w;
    f32 f;
    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(pv + 0x124) = 0;
        if (a0[0x43] != 4) {
            func_003C3A10(a0, 4, 0, 8);
        }
        if (*(s32 *)(pv + 0x4E4) != 0) {
            func_003C48A8(a0 + 0xC0, a0 + 0xF0);
        }
    }
    func_L01_0045BD10(a0, func_0038D160(*(f32 *)(pv + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x224) - *(f32 *)(a0 + 0x14)));
    if (*(s32 *)(pv + 0x4E4) != 0 && D_001D545C == 0x10) {
        func_L01_0040EE50(m0, a0 + 0xC0);
        vec_sub_ab(&d, pv + 0x220, a0 + 0x10);
        func_0038D000(&d, &d, m0);
        d.z = 0.0f;
        func_0038CF68(&d, &d, 1.0f);
        f = func_0038D0C8(d.y);
        {
            f32 y = *(f32 *)(pv + 0x88);
            f32 z = *(f32 *)(pv + 0x8C);
            f32 x = *(f32 *)(pv + 0x84);
            w.x = 0.0f;
            func_L01_00448890(&w, f, pv + 0x124, x, y, z, 0);
        }
        qzero(&v);
        v.z = *(f32 *)(pv + 0x124);
        func_0038D308(m1, &v);
        func_0038D5F0(a0 + 0xC0, a0 + 0xC0, m1);
    }
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 0xE, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00364D38 */

/* localdecomp:start func_L04_00364EC0 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D0C8(f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L01_00445BE0(s32, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_003A8CF0(void *, void *, void *, f32);
extern void func_L01_003AEA58(void *, void *, void *, s32, f32);
extern s32 D_001D545C;
__asm__(".extern D_L04_001DD6E4, 4");
extern f32 D_L04_001DD6E4;

s32 func_L04_00364EC0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    s32 r;
    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(pv + 0x124) = 0;
        *(s32 *)(pv + 0x4AC) = 0x32;
        if (a0[0x43] != 5) {
            func_003C3A10(a0, 5, 0, 8);
        }
    }
    func_L01_0045BD10(a0, func_0038D160(*(f32 *)(pv + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x224) - *(f32 *)(a0 + 0x14)));
    if (*(s32 *)(pv + 0x4E4) != 0) {
        {
            vu0_v4 m0[3];
            vu0_v4 d;
            vu0_v4 m1[3];
            vu0_v4 v;
            vu0_v4 w;
            f32 f;
            func_L01_0040EE50(m0, a0 + 0xC0);
            vec_sub_ab(&d, pv + 0x220, a0 + 0x10);
            func_0038D000(&d, &d, m0);
            d.z = 0.0f;
            func_0038CF68(&d, &d, 1.0f);
            f = func_0038D0C8(d.y);
            {
                f32 y = *(f32 *)(pv + 0x88);
                f32 z = *(f32 *)(pv + 0x8C);
                f32 x = *(f32 *)(pv + 0x84);
                w.x = 0.0f;
                func_L01_00448890(&w, f, pv + 0x124, x, y, z, 0);
            }
            qzero(&v);
            v.z = *(f32 *)(pv + 0x124);
            func_0038D308(m1, &v);
            func_0038D5F0(a0 + 0xC0, a0 + 0xC0, m1);
        }
    }
    if (a0[0x21] == 0xFF) {
        r = 1;
    } else {
        r = a0[0xBC] == 0;
        if (func_0038CAD0(pv + 0x4AC) == 0) {
            r = 0;
        }
    }
    if (func_L01_0044E1B8(a0, 16.0f) != 0 && a0[0x42] == 5 && func_L01_004561B8(a0) == 0 && r != 0) {
        if (a0[0x21] != 0xFF) {
            func_L01_00445BE0(a0[0x21], 1);
        }
        func_L01_004450F0(a0, 0xF, -1);
        return 2;
    }
    if (D_001D545C != 0x10 && D_001D545C != 0xD && r != 0
        && (func_L01_0044E1B8(a0, 3.0f) != 0 || func_L01_0044E1B8(a0, 7.0f) != 0
            || func_L01_0044E1B8(a0, 11.0f) != 0 || func_L01_0044E1B8(a0, 15.0f) != 0)
        && a0[0x42] == 5) {
        vu0_v4 v;
        vu0_v4 m[4];
        vu0_v4 a;
        vu0_v4 b;
        func_003C2EC0(*(void **)(pv + 0x2FC), 0, m);
        func_003A52A0(0, 0, a0);
        a = m[3];
        b = m[0];
        func_L01_003A8CF0(a0, &a, &b, 0.649999976f);
        func_0038CF68(&v, &m[0], D_L04_001DD6E4 * 0.0200000014f);
        if (func_L01_0044E1B8(a0, 3.0f) != 0) {
            v.z -= 0.200000003f;
        }
        if (func_L01_0044E1B8(a0, 7.0f) != 0) {
            v.z -= 0.150000006f;
        }
        if (func_L01_0044E1B8(a0, 11.0f) != 0) {
            v.z -= 0.100000001f;
        }
        if (func_L01_0044E1B8(a0, 15.0f) != 0) {
            v.z -= 0.0500000007f;
        }
        func_L01_003AEA58(a0, &v, &m[3], 1, 1.0f);
    }
    if (func_0038CF38(a0 + 0x10, pv + 0x220) < 2.5f && r == 0 && *(s32 *)(pv + 0x4E4) == 0) {
        func_L01_004450F0(a0, 0x10, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00364EC0 */

/* localdecomp:start func_L04_003652B8 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_004395E0(void *);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_00446780(void *, f32, void *, s32, f32, f32, s32, s32, s32);

s32 func_L04_003652B8(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_v4 b;
    vu0_v4 a;
    f32 d;
    if (func_L01_004561B8(a0) != 0 && a0[0x43] != 0x16) {
        func_003C3A10(a0, 0x16, 0, 5);
    }
    d = func_L01_004395E0(a0);
    if (14.0f <= d && d < 19.0f && a0[0x42] == 0x16) {
        func_003C2F58(*(void **)(pv + 0x2FC), 0, &a);
        func_003C2F58(a0, 0, &b);
        func_L01_00446780(a0, 0.5f, &a, 1, pv[0x45], 1.0f, 0, 1, 0);
        func_L01_00446780(a0, 0.5f, &b, 1, pv[0x45], 1.0f, 0, 1, 0);
    }
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 0xD, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_003652B8 */

INCLUDE_ASM("asm/levels", func_L04_00365438);

/* localdecomp:start func_L04_003655E8 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L04_00361D20(u8 *, u8 *);
extern f32 func_0038CF38(void *, void *);
extern u8 *D_L04_001DFA4C;
extern s32 D_001D545C;

s32 func_L04_003655E8(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    if (func_L01_004561B8(a0) != 0) {
        if (a0[0x43] != 0x13) {
            func_003C3A10(a0, 0x13, 0, (func_00382498(6, 10) * 5 + 2) / 6);
        }
        *(f32 *)(a0 + 0x48) = func_003824E0(0.899999976f, 1.5f);
    }
    if (func_L01_0044E1B8(a0, 50.0f) != 0) {
        if (*(s32 *)(pv + 0x304) != -1 || func_L04_00361D20(a0, pv) != 0) {
            func_L01_004450F0(a0, 0xA, -1);
            if (func_0038CF38(a0 + 0x10, pv + 0x320) != 0.0f) {
                if (a0[0x43] != 4) {
                    func_003C3A10(a0, 4, 0, 0xC);
                }
                func_L01_004450F0(a0, 0xD, -1);
            }
        } else if (*(s32 *)(pv + 0x38C) != -1
            && (row = D_L04_001DFA4C + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
            func_L01_004450F0(a0, 0xA, -1);
        } else {
            func_L01_004450F0(a0, 0xB, -1);
            if (func_0038CF38(a0 + 0x10, pv + 0x220) < 17.0f) {
                if (a0[0x43] != 4) {
                    func_003C3A10(a0, 4, 0, 8);
                }
                func_L01_004450F0(a0, 0xD, -1);
            }
        }
        if (a0[0x95] == 4) {
            func_L01_004450F0(a0, 0xA, -1);
        }
        if (*(s32 *)(pv + 0x4E8) != 0 || (D_001D545C == 0x10 && *(s32 *)(pv + 0x4E4) != 0)) {
            func_L01_004450F0(a0, 0xD, -1);
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_003655E8 */

/* localdecomp:start func_L04_00365818 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_0038CE68(void *, void *);

s32 func_L04_00365818(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    s32 t;
    if (func_L01_004561B8(a0) != 0 && a0[0x43] != 3) {
        func_003C3A10(a0, 3, 0, 5);
    }
    func_L01_0045BD10(a0, *(f32 *)(pv + 0x36C));
    if (*(f32 *)(a0 + 0xF8) == *(f32 *)(pv + 0x36C)) {
        t = *(s32 *)(pv + 0x308);
        if (t == 2) {
            vec_sub_ab(&d, pv + 0x220, pv + 0x320);
            t = 0.0f < func_0038CE68(&d, pv + 0x330) ? -1 : 1;
        }
        if (t == 1) {
            func_L01_004450F0(a0, 0x13, -1);
        } else {
            func_L01_004450F0(a0, 0x16, -1);
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00365818 */

/* localdecomp:start func_L04_00365910 */
extern s32 func_L01_004561B8();
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_004395E0(void *);
extern void func_L04_00361BD0(u8 *, u8 *, f32);
__asm__(".extern D_L04_001DD6D0, 4");
__asm__(".extern D_L04_001DD6D4, 4");
extern f32 D_L04_001DD6D0;
extern f32 D_L04_001DD6D4;

s32 func_L04_00365910(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 d;
    if (func_L01_004561B8(a0) != 0) {
        func_L01_0045BD78(a0, D_L04_001DD6D4 * 0.00040000002f, D_L04_001DD6D0 * 0.020000001f, 0.010053097f, 0.25132743f);
        if (a0[0x43] != 0xB) {
            func_003C3A10(a0, 0xB, 0, (func_00382498(6, 0xC) * 5 + 2) / 6);
        }
        if ((*(u16 *)(a0 + 0x34) & 0x8000) && a0[0x43] != 7) {
            func_003C3A10(a0, 7, 0, (func_00382498(6, 0xC) * 5 + 2) / 6);
        }
    }
    d = func_L01_004395E0(a0);
    if (3.0f < d && d < 12.0f) {
        func_L04_00361BD0(a0, pv, -1.0f);
    }
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 0x14, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00365910 */

/* localdecomp:start func_L04_00365A98 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L04_00361948(u8 *, u8 *, s32, s32);
__asm__(".extern D_L04_001DD708, 4");
extern f32 D_L04_001DD708[] __attribute__((section(".sdata")));

s32 func_L04_00365A98(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 m[16];
    s32 i;
    if (func_L01_004561B8(a0) != 0) {
        func_003C2EC0(*(void **)(pv + 0x2FC), 0, m);
        if (a0[0x43] != 0xD) {
            func_003C3A10(a0, 0xD, 0, 0);
        }
        if ((*(u16 *)(a0 + 0x34) & 0x8000) && a0[0x43] != 9) {
            func_003C3A10(a0, 9, 0, 0);
        }
        *(s32 *)(pv + 0x368) = -1;
    }
    for (i = *(s32 *)(pv + 0x368); i < 6; i++) {
        if (func_L01_0044E1B8(a0, D_L04_001DD708[i]) != 0) {
            *(s32 *)(pv + 0x368) = i;
            func_L04_00361948(a0, pv, i, 6);
        }
    }
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 0x15, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00365A98 */

/* localdecomp:start func_L04_00365BC0 */
extern s32 func_L01_004561B8();
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_004395E0(void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L02_00431568(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L04_00361D20(u8 *, u8 *);
__asm__(".extern D_L04_001DD6D8, 4");
__asm__(".extern D_L04_001DD6DC, 4");
extern f32 D_L04_001DD6D8;
extern f32 D_L04_001DD6DC;

s32 func_L04_00365BC0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 d;
    if (func_L01_004561B8(a0) != 0) {
        func_L01_0045BD78(a0, D_L04_001DD6DC * 0.00040000002f, D_L04_001DD6D8 * 0.020000001f, 0.010053097f, 0.25132743f);
        *(f32 *)(pv + 0xA4) = 0.0f;
        if (a0[0x43] != 0xE) {
            func_003C3A10(a0, 0xE, 0, 4);
        }
        if ((*(u16 *)(a0 + 0x34) & 0x8000) && a0[0x43] != 0xA) {
            func_003C3A10(a0, 0xA, 0, 4);
        }
    }
    d = func_L01_004395E0(a0);
    if (12.0f < d && d < 19.0f) {
        func_L02_00431568(a0, pv + 0x320, 0x10, func_0038D160(*(f32 *)(pv + 0x320) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x324) - *(f32 *)(a0 + 0x14)), -1.0f, -1.0f, -1.0f);
    }
    if (a0[0x60] & 2) {
        *(f32 *)(pv + 0xA4) = 0.5f;
        if (0.5f < *(f32 *)(pv + 0x13C) || func_L04_00361D20(a0, pv) == 0) {
            func_L01_004450F0(a0, 0xD, -1);
        } else {
            func_L01_004450F0(a0, 0x12, -1);
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00365BC0 */

/* localdecomp:start func_L04_00365D80 */
extern s32 func_L01_004561B8();
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_004395E0(void *);
extern void func_L04_00361BD0(u8 *, u8 *, f32);
__asm__(".extern D_L04_001DD6D0, 4");
__asm__(".extern D_L04_001DD6D4, 4");
extern f32 D_L04_001DD6D0;
extern f32 D_L04_001DD6D4;

s32 func_L04_00365D80(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 d;
    if (func_L01_004561B8(a0) != 0) {
        func_L01_0045BD78(a0, D_L04_001DD6D4 * 0.00040000002f, D_L04_001DD6D0 * 0.020000001f, 0.010053097f, 0.25132743f);
        if (a0[0x43] != 7) {
            func_003C3A10(a0, 7, 0, (func_00382498(6, 0xC) * 5 + 2) / 6);
        }
        if ((*(u16 *)(a0 + 0x34) & 0x8000) && a0[0x43] != 0xB) {
            func_003C3A10(a0, 0xB, 0, (func_00382498(6, 0xC) * 5 + 2) / 6);
        }
    }
    d = func_L01_004395E0(a0);
    if (3.0f < d && d < 12.0f) {
        func_L04_00361BD0(a0, pv, 1.0f);
    }
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 0x17, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00365D80 */

/* localdecomp:start func_L04_00365F08 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L04_00361948(u8 *, u8 *, s32, s32);
__asm__(".extern D_L04_001DD720, 4");
extern f32 D_L04_001DD720[] __attribute__((section(".sdata")));

s32 func_L04_00365F08(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 m[16];
    s32 i;
    if (func_L01_004561B8(a0) != 0) {
        func_003C2EC0(*(void **)(pv + 0x2FC), 0, m);
        if (a0[0x43] != 9) {
            func_003C3A10(a0, 9, 0, 0);
        }
        if ((*(u16 *)(a0 + 0x34) & 0x8000) && a0[0x43] != 0xD) {
            func_003C3A10(a0, 0xD, 0, 0);
        }
        *(s32 *)(pv + 0x368) = -1;
    }
    for (i = *(s32 *)(pv + 0x368); i < 6; i++) {
        if (func_L01_0044E1B8(a0, D_L04_001DD720[i]) != 0) {
            *(s32 *)(pv + 0x368) = i;
            func_L04_00361948(a0, pv, i, 6);
        }
    }
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 0x18, -1);
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00365F08 */

/* localdecomp:start func_L04_00366030 */
extern s32 func_L01_004561B8();
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_004395E0(void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L02_00431568(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L04_00361D20(u8 *, u8 *);
extern s32 func_L01_0045BD10(void *, f32);
__asm__(".extern D_L04_001DD6D8, 4");
__asm__(".extern D_L04_001DD6DC, 4");
extern f32 D_L04_001DD6D8;
extern f32 D_L04_001DD6DC;

s32 func_L04_00366030(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 d;
    if (func_L01_004561B8(a0) != 0) {
        func_L01_0045BD78(a0, D_L04_001DD6DC * 0.00040000002f, D_L04_001DD6D8 * 0.020000001f, 0.010053097f, 0.25132743f);
        *(f32 *)(pv + 0xA4) = 0.0f;
        if (a0[0x43] != 0xA) {
            func_003C3A10(a0, 0xA, 0, 4);
        }
        if ((*(u16 *)(a0 + 0x34) & 0x8000) && a0[0x43] != 0xE) {
            func_003C3A10(a0, 0xE, 0, 4);
        }
    }
    d = func_L01_004395E0(a0);
    if (12.0f < d && d < 19.0f) {
        func_L02_00431568(a0, pv + 0x320, 0x10, func_0038D160(*(f32 *)(pv + 0x320) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x324) - *(f32 *)(a0 + 0x14)), -1.0f, -1.0f, -1.0f);
        func_L01_0045BD10(a0, *(f32 *)(pv + 0x36C));
    }
    if (a0[0x60] & 2) {
        *(f32 *)(pv + 0xA4) = 0.5f;
        if (0.5f < *(f32 *)(pv + 0x13C) || func_L04_00361D20(a0, pv) == 0) {
            func_L01_004450F0(a0, 0xD, -1);
        } else {
            func_L01_004450F0(a0, 0x12, -1);
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00366030 */

/* localdecomp:start func_L04_00366200 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_0045C2A0(void *, f32, f32, f32);
extern void func_L01_0045A9F0(void *);
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_0044E1B8(void *, f32);
__asm__(".extern D_L04_001DD738, 4");
__asm__(".extern D_L04_001DD73C, 4");
__asm__(".extern D_L04_001DD740, 4");
__asm__(".extern D_L04_001DD744, 4");
__asm__(".extern D_L04_001DD754, 4");
__asm__(".extern D_L04_001DD758, 4");
__asm__(".extern D_L04_001DD75C, 4");
__asm__(".extern D_L04_001DD760, 4");
extern s32 D_L04_001DD738;
extern f32 D_L04_001DD73C;
extern f32 D_L04_001DD740;
extern f32 D_L04_001DD744;
extern f32 D_L04_001DD754;
extern f32 D_L04_001DD758;
extern f32 D_L04_001DD75C;
extern f32 D_L04_001DD760;

s32 func_L04_00366200(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *c;
    u8 *c1;
    u8 *c2;
    u8 a;
    f32 lim;
    s32 t;
    f32 y;
    f32 s;
    if (func_L01_004561B8(a0) != 0) {
        *(f32 *)(pv + 0x1BC) = *(f32 *)(pv + 0x1B8) = 2.0f;
    }
    if (*(f32 *)(pv + 0x37C) < 1.0f) {
        *(f32 *)(pv + 0x37C) += D_L04_001DD754 * 0.0200000014f;
        if (1.0f < *(f32 *)(pv + 0x37C)) {
            *(f32 *)(pv + 0x37C) = 1.0f;
        }
        *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * *(f32 *)(pv + 0x37C);
        c1 = *(u8 **)(pv + 0x2FC);
        if (c1 != 0) {
            *(f32 *)(c1 + 0x2C) = *(f32 *)(*(u8 **)(c1 + 0x24) + 0x24) * *(f32 *)(pv + 0x37C);
        }
    }
    a = a0[0x23];
    if (a < 0x7F) {
        t = a + (s32)(D_L04_001DD760 * 0.0200000014f * 127.0f);
        *(s8 *)(a0 + 0x23) = t;
        if (*(s8 *)(a0 + 0x23) < 0) {
            a0[0x23] = 0x7F;
        }
        if (a0[0x23] == 0x7F) {
            *(u16 *)(a0 + 0x34) &= 0xD7FF;
        }
        c2 = *(u8 **)(pv + 0x2FC);
        if (c2 != 0) {
            c2[0x23] = a0[0x23];
            c2 = *(u8 **)(pv + 0x2FC);
            if (c2[0x23] == 0x7F) {
                *(u16 *)(c2 + 0x34) &= 0xD7FF;
            }
        }
    }
    s = (D_L04_001DD758 - 1.0f) * 1.20000005f + 1.0f;
    y = *(f32 *)(pv + 0x118);
    *(f32 *)(pv + 0x118) = 0.0f;
    *(f32 *)(pv + 0x120) *= s;
    func_0038CF68(pv + 0x110, pv + 0x110, *(f32 *)(pv + 0x120));
    lim = D_L04_001DD75C * 0.0200000014f;
    *(f32 *)(pv + 0x118) = y;
    *(f32 *)(pv + 0x9C) = 0.0160000008f;
    if (lim < y) {
        *(f32 *)(pv + 0x9C) = 0.00400000019f;
    }
    if (*(u8 **)(pv + 0x378) != 0) {
        *(s32 *)(*(u8 **)(pv + 0x378) + 0x98) = 0;
    }
    if (func_L01_0045C2A0(a0, D_L04_001DD73C, D_L04_001DD740, D_L04_001DD744) != 0) {
        *(f32 *)(a0 + 0x48) = 1.0f;
        func_L01_0045A9F0(a0);
        *(f32 *)(pv + 0x1BC) = 0.75f;
        *(f32 *)(pv + 0x1B8) = 0.200000003f;
        *(f32 *)(pv + 0x9C) = 0.00800000038f;
        if (*(s32 *)(pv + 0x380) != 0) {
            func_L01_004450F0(a0, 0xA, -1);
        } else {
            func_L01_004450F0(a0, 1, 1);
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 8);
            }
            if (*(s32 *)(pv + 0x310) != -1) {
                func_L01_004450F0(a0, 5, 6);
            } else if (*(s32 *)(pv + 0x300) != -1) {
                func_L01_004450F0(a0, 2, -1);
            } else if (*(s32 *)(pv + 0x318) == 0) {
                func_L01_004450F0(a0, 4, -1);
            }
        }
        if (*(s32 *)(pv + 0x30C) != -1) {
            func_L01_004450F0(a0, 9, -1);
        }
        c = *(u8 **)(pv + 0x378);
        if (c != 0) {
            *(s32 *)(c + 0x98) = *(s32 *)(*(u8 **)(c + 0x24) + 0x10);
        }
        return 1;
    }
    if (D_L04_001DD744 < func_L01_004395E0(a0)) {
        *(f32 *)(pv + 0x1BC) = 0.75f;
        *(f32 *)(pv + 0x1B8) = 0.200000003f;
    }
    c = *(u8 **)(pv + 0x378);
    if (c != 0) {
        *(s32 *)(c + 0x98) = *(s32 *)(*(u8 **)(c + 0x24) + 0x10);
    }
    if (func_L01_0044E1B8(a0, 18.0f) != 0 && a0[0x42] == D_L04_001DD738) {
        *(f32 *)(a0 + 0x18) = *(f32 *)(pv + 0x100);
        qzero(pv + 0x110);
    }
    return 0;
}
/* localdecomp:end func_L04_00366200 */

/* localdecomp:start func_L04_003665C0 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L04_003665C0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    if (a0[0x60] & 2) {
        func_L01_004450F0(a0, 1, 1);
        if (a0[0x43] != 0) {
            func_003C3A10(a0, 0, 0, 0);
        }
        if (*(long *)(pv + 0x310) != -1) {
            func_L01_004450F0(a0, 5, 6);
        } else if (*(s32 *)(pv + 0x300) != -1) {
            func_L01_004450F0(a0, 2, -1);
        } else if (*(s32 *)(pv + 0x318) == 0) {
            func_L01_004450F0(a0, 4, -1);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_003665C0 */

/* localdecomp:start func_L04_00366690 */
extern s32 func_L01_004561B8();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004591B8(void *, void *, void *);
extern void func_L01_00458F78(void *, void *, s32, s32);
extern void func_L01_0045A748(void *, void *);
extern f32 func_0038CF38(void *, void *);

s32 func_L04_00366690(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_v4 p;
    if (func_L01_004561B8(a0) != 0) {
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 8);
        }
        func_L01_0045BD78(a0, 0.0024f, 0.040000003f, 0.010053097f, 0.25132743f);
        *(vu0_q *)&p = *(vu0_q *)(pv + 0x490);
        func_L01_004591B8(a0, &p, pv + 0x410);
    }
    if (*(s32 *)(pv + 0x4E4) == 0) {
        func_L01_00458F78(a0, pv + 0x410, 0, 0);
        func_L01_0045A748(a0, pv + 0x410);
    }
    if (func_0038CF38(a0 + 0x10, pv + 0x490) < 0.5f) {
        func_L01_004450F0(a0, 8, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00366690 */

/* localdecomp:start func_L04_003667B0 */
void func_003C3A10(void *, s32, s32, s32);
s32 func_L01_004561B8();

s32 func_L04_003667B0(void *arg0) {
    if ((func_L01_004561B8() != 0) && ((*(u8 *)((u8 *)arg0 + 0x43)) != 0)) {
        func_003C3A10(arg0, 0, 0, 8);
    }
    return 0;
}
/* localdecomp:end func_L04_003667B0 */
