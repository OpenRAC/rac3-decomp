#include "common.h"

/* localdecomp:start func_L40_00422358 */
typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; u8 *vars;
} S_Moby421A88;

extern S_Moby421A88 *func_L40_00422208(S_Moby421A88 *, s32);

void func_L40_00422358(S_Moby421A88 *m, s32 x) {
    u8 *mv = m->vars;
    s32 n1 = *(s32 *)(mv + 0x30);
    s32 n3 = *(s32 *)(mv + 0x38);
    s32 n2 = *(s32 *)(mv + 0x34);
    s32 i;
    S_Moby421A88 *o;

    if (n1 > 0) {
        i = 0;
        while (i < n1) {
            o = func_L40_00422208(m, 4255);
            if (o == 0) break;
            {
                S_Moby421A88 *p = o;
                u8 *v;
                p->state = 39;
                v = p->vars;
                *(s32 *)(v + 0x2B8) = x;
                *(s32 *)(v + 0x34C) = *(s32 *)(v + 0x3D8);
            }
            i++;
        }
    }
    if (n3 > 0) {
        i = 0;
        while (i < n3) {
            o = func_L40_00422208(m, 6646);
            if (o == 0) break;
            {
                S_Moby421A88 *p = o;
                u8 *v;
                p->state = 39;
                v = p->vars;
                *(s32 *)(v + 0x1C0) = 500;
                *(s32 *)(v + 0x1A0) = x;
            }
            i++;
        }
    }
    if (n2 > 0) {
        i = 0;
        while (i < n2) {
            o = func_L40_00422208(m, 6683);
            if (o == 0) break;
            {
                S_Moby421A88 *p = o;
                u8 *v;
                p->state = 39;
                v = p->vars;
                *(s32 *)(v + 0x2AC) = x;
                *(s32 *)(v + 0x2E8) = *(s32 *)(v + 0x308);
            }
            i++;
        }
    }
}
/* localdecomp:end func_L40_00422358 */

/* localdecomp:start func_L40_004224A0 */
extern u8 D_L40_0026E7D0[];
extern s32 D_L40_0026DD80[];

void func_L40_004224A0(u8 *a0, s32 a1) {
    u8 b;
    *(s16 *)(a0 + 170) = a1;
    b = D_L40_0026E7D0[(s16)a1];
    a0[34] = b;
    *(s32 *)(a0 + 36) = D_L40_0026DD80[a0[34]];
}
/* localdecomp:end func_L40_004224A0 */

/* localdecomp:start func_L40_004224E0 */
int func_L40_004224E0(u8 *a) {
    u8 *p = *(u8 **)(a + 104);
    return *(s32 *)(p + 124) != -1;
}
/* localdecomp:end func_L40_004224E0 */

/* localdecomp:start func_L40_004224F8 */
s32 func_L40_004224F8(u8 *a0) {
    switch (*(s16 *)(a0 + 170)) {
    case 6842:
    case 6843:
    case 6844:
    case 6845:
    case 6846:
    case 6848:
    case 6849:
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L40_004224F8 */

/* localdecomp:start func_L40_00422530 */
s32 func_L40_00422530(u8 *a) {
    return (u32)(*(u16 *)(a + 0xAA) - 6842) < 8;
}
/* localdecomp:end func_L40_00422530 */

/* localdecomp:start func_L40_00422540 */
s32 func_L40_00422540(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0x1f1e;
}
/* localdecomp:end func_L40_00422540 */

/* localdecomp:start func_L40_00422550 */
s32 func_L40_00422550(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0x1af2;
}
/* localdecomp:end func_L40_00422550 */

/* localdecomp:start func_L40_00422560 */
s32 func_L40_00422560(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0x1b0b;
}
/* localdecomp:end func_L40_00422560 */

/* localdecomp:start func_L40_00422570 */
extern s32 func_L40_004224E0(u8 *a0);
extern s32 func_L40_00422560(u8 *a0);
extern s32 func_L40_00422540(u8 *a0);
extern void func_003C2880(u8 *a0);
extern void func_L40_003DB068(u8 *a0);
void func_L40_00422570(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    u8 *p;
    if (*(u8 **)(s1 + 120) != 0) {
        if (func_L40_004224E0(a0) || func_L40_00422560(a0) || func_L40_00422540(a0)) {
            func_003C2880(*(u8 **)(s1 + 120));
            *(u8 **)(s1 + 120) = 0;
        } else {
            p = *(u8 **)(s1 + 120);
            if (*(s16 *)(p + 170) == 6899) {
                func_L40_003DB068(p);
            }
            *(u8 **)(s1 + 120) = 0;
        }
    }
}
/* localdecomp:end func_L40_00422570 */
