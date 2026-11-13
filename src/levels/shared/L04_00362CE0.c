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

INCLUDE_ASM("asm/levels", func_L04_00362EF0);

INCLUDE_ASM("asm/levels", func_L04_00362F18);

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

INCLUDE_ASM("asm/levels", func_L04_00363388);

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

INCLUDE_ASM("asm/levels", func_L04_003636F0);

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

INCLUDE_ASM("asm/levels", func_L04_00363B60);

INCLUDE_ASM("asm/levels", func_L04_00363D00);

INCLUDE_ASM("asm/levels", func_L04_00363F80);

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

INCLUDE_ASM("asm/levels", func_L04_00364B90);

INCLUDE_ASM("asm/levels", func_L04_00364D38);

INCLUDE_ASM("asm/levels", func_L04_00364EC0);

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

INCLUDE_ASM("asm/levels", func_L04_003655E8);

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

INCLUDE_ASM("asm/levels", func_L04_00365910);

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

INCLUDE_ASM("asm/levels", func_L04_00365D80);

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

INCLUDE_ASM("asm/levels", func_L04_00366200);

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
