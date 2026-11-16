#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003BA870 */
typedef int u128_3BA870 __attribute__((mode(TI)));
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00366EA8(void *, void *, void *, s32, s32);
extern void func_003C7C38(void *);
extern void func_L01_004472C0(void *);
extern u8 D_L04_001E2840[];
extern void func_0038D308(u8 *, u8 *);
extern void func_L04_003BAC10(u8 *, u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 D_001D545C;

void func_L04_003BA870(u8 *a0) {
    u8 *mv = *(u8 **)(a0 + 0x68);
    f32 s;
    if (*(u16 *)(a0 + 0x34) & 0x80) {
        return;
    }
    if (a0[0x20] == 0) {
        *(s32 *)(mv + 0xA0) = 0;
    }
    if (func_L01_00456250(*(void **)(a0 + 0xB8)) != 0) {
        if (*(s32 *)(mv + 0xA0) == 0) {
            func_L01_004AAC98(0, 0, a0, 0x1931);
            *(s32 *)(mv + 0xA0) = 1;
        }
    } else {
        *(s32 *)(mv + 0xA0) = 0;
    }
    *(u128_3BA870 *)(a0 + 0x10) = *(u128_3BA870 *)(*(u8 **)(a0 + 0xB8) + 0x10);
    if (*(f32 *)(a0 + 0xF8) != func_0038D160(*(f32 *)(*(u8 **)(a0 + 0xB8) + 0xC0), *(f32 *)(*(u8 **)(a0 + 0xB8) + 0xC4))) {
        *(f32 *)(a0 + 0xF8) = func_0038D160(*(f32 *)(*(u8 **)(a0 + 0xB8) + 0xC0), *(f32 *)(*(u8 **)(a0 + 0xB8) + 0xC4));
        func_0038D308(a0 + 0xC0, a0 + 0xF0);
    }
    if (D_001D545C == 11) {
        u8 *p = *(u8 **)(a0 + 0xB8);
        *(f32 *)(a0 + 0xF8) = *(f32 *)(p + 0xF8);
        *(f32 *)(a0 + 0xF0) = *(f32 *)(p + 0xF0);
        *(f32 *)(a0 + 0xF4) = *(f32 *)(p + 0xF4);
        func_0038D308(a0 + 0xC0, a0 + 0xF0);
    }
    func_L01_00366EA8(mv, mv + 4, mv + 0x10, 0, func_L01_00456250(*(void **)(a0 + 0xB8)));
    func_L04_003BAC10(a0, mv);
    func_003C7C38(a0);
    if (*(f32 *)(mv + 0x88) != 0.0f) {
        s = *(f32 *)(mv + 0x88) / 5000.0f * 1024.0f;
        *(f32 *)(a0 + 0xC) += fabs_asm(s) * 0.55f;
        if (*(f32 *)(a0 + 0xF0) == 3.1415927f) {
            s = -s;
        }
        *(f32 *)(a0 + 8) += s * 0.5f;
    }
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L04_001E2840, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L04_003BA870 */

/* localdecomp:start func_L04_003BAA98 */
typedef int u128_3BAA98 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00366E48(u8 *, u8 *, void *, void *, s32);
extern void func_0038D308(u8 *, u8 *);
extern void func_L04_003BAB98(u8 *, u8 *);

u8 *func_L04_003BAA98(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *m = func_003C24B0(0x192F, 0xC0);
    u8 *mv;
    u8 *rot;
    if (m != 0) {
        *(u8 **)(m + 0xB8) = a0;
        mv = *(u8 **)(m + 0x68);
        m[0x30] = a0[0x30];
        *(u16 *)(m + 0x32) = *(u16 *)(a0 + 0x32);
        m[0x31] = a0[0x31];
        m[0x20] = 1;
        *(long *)(m + 0x38) = *(long *)(a0 + 0x38);
        *(u128_3BAA98 *)(m + 0x10) = *(u128_3BAA98 *)(a0 + 0x10);
        func_L01_00366E48(m, mv, mv + 4, mv + 0x10, 0);
        func_L04_003BAB98(m, mv);
        rot = m + 0xF0;
        qzero(m + 0xF0);
        *(f32 *)(m + 0xF8) = *(f32 *)(a0 + 0xF8);
        if (*(s32 *)(pv + 4) < 0) {
            *(f32 *)(m + 0xF0) = 3.1415927f;
            *(f32 *)(mv + 8) = -*(f32 *)(mv + 8);
        }
        func_0038D308(m + 0xC0, rot);
        *(u16 *)(m + 0x34) |= 0x104;
        *(s32 *)(mv + 0xA0) = 0;
    }
    return m;
}
/* localdecomp:end func_L04_003BAA98 */

/* localdecomp:start func_L04_003BAB98 */
extern void func_L01_0043A800(u8 *, s32, void *);
extern void func_L01_0043A430(u8 *, s32, void *);
extern void func_0038CB78(void *, s32, s32);

void func_L04_003BAB98(u8 *a0, u8 *a1) {
    f32 v[4];
    func_L01_0043A800(a0, 1, v);
    *(s32 *)(a1 + 0xC) = 0;
    *(f32 *)(a1 + 8) = v[2];
    qzero(a1 + 0x90);
    func_0038CB78(a1 + 0x50, 0, 0x40);
    func_L01_0043A430(a0, 1, a1 + 0x50);
}
/* localdecomp:end func_L04_003BAB98 */

/* localdecomp:start func_L04_003BAC10 */
typedef int u128_3BAC10 __attribute__((mode(TI)));
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_L04_00455AF8(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 D_001D545C;
extern u8 D_L04_001D66B0[8];

void func_L04_003BAC10(u8 *a0, u8 *a1) {
    f32 d;
    s32 lv;
    if (func_L01_0040E548(a0 + 0x10, a1 + 0x90) < 0.001f) {
        return;
    }
    if (*(f32 *)(a0 + 0xF0) == 3.1415927f) {
        d = *(f32 *)(a0 + 0x18) - func_L04_00455AF8(a0 + 0x10) - *(f32 *)(a1 + 8);
    } else {
        d = func_003C3D30(a0 + 0x10, 0, 0, 0.5f) - *(f32 *)(a0 + 0x18) - *(f32 *)(a1 + 8);
    }
    if (d > 3.0f) {
        d = 3.0f;
    } else if (d < -3.0f) {
        d = -3.0f;
    }
    lv = D_001D545C;
    *(f32 *)(a1 + 0x88) = *(f32 *)(a1 + 0xC) = d * (1024.0f / *(f32 *)(a0 + 0x2C));
    if (lv == 11) {
        *(f32 *)(a1 + 0x88) = 0.0f;
        *(u128_3BAC10 *)(a1 + 0x70) = *(u128_3BAC10 *)D_L04_001D66B0;
    }
    *(u128_3BAC10 *)(a1 + 0x90) = *(u128_3BAC10 *)(a0 + 0x10);
}
/* localdecomp:end func_L04_003BAC10 */

/* localdecomp:start func_L04_003BAD68 */
typedef int u128_3BAD68 __attribute__((mode(TI)));
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00366EA8(void *, void *, void *, s32, s32);
extern void func_003C7C38(void *);
extern void func_L01_004472C0(void *);
extern void func_L04_003BB0D0(u8 *, u8 *);
extern u8 D_L04_001E2840[];

void func_L04_003BAD68(u8 *a0) {
    u8 *mv = *(u8 **)(a0 + 0x68);
    u8 *p;
    f32 s;
    if (*(u16 *)(a0 + 0x34) & 0x80) {
        return;
    }
    if (a0[0x20] == 0) {
        *(s32 *)(mv + 0xA0) = 0;
    }
    if (func_L01_00456250(*(void **)(a0 + 0xB8)) != 0) {
        if (*(s32 *)(mv + 0xA0) == 0) {
            func_L01_004AAC98(0, 0, a0, 0x1931);
            *(s32 *)(mv + 0xA0) = 1;
        }
    } else {
        *(s32 *)(mv + 0xA0) = 0;
    }
    *(u128_3BAD68 *)(a0 + 0x10) = *(u128_3BAD68 *)(*(u8 **)(a0 + 0xB8) + 0x10);
    if (*(f32 *)(a0 + 0xF8) != func_0038D160(*(f32 *)(*(u8 **)(a0 + 0xB8) + 0xC0), *(f32 *)(*(u8 **)(a0 + 0xB8) + 0xC4))) {
        *(f32 *)(a0 + 0xF8) = func_0038D160(*(f32 *)(*(u8 **)(a0 + 0xB8) + 0xC0), *(f32 *)(*(u8 **)(a0 + 0xB8) + 0xC4));
        func_0038D308(a0 + 0xC0, a0 + 0xF0);
    }
    func_L01_00366EA8(mv, mv + 4, mv + 0x10, 0, func_L01_00456250(*(void **)(a0 + 0xB8)));
    func_L04_003BB0D0(a0, mv);
    func_003C7C38(a0);
    if (*(f32 *)(mv + 0x88) != 0.0f) {
        s = *(f32 *)(mv + 0x88) / 5000.0f * 1024.0f;
        *(f32 *)(a0 + 0xC) += fabs_asm(s) * 0.55f;
        if (*(f32 *)(a0 + 0xF0) == 3.1415927f) {
            s = -s;
        }
        *(f32 *)(a0 + 8) += s * 0.5f;
    }
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L04_001E2840, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L04_003BAD68 */

/* localdecomp:start func_L04_003BAF58 */
typedef int u128_3BAF58 __attribute__((mode(TI)));
extern void func_L04_003BB058(u8 *, u8 *);

u8 *func_L04_003BAF58(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *m = func_003C24B0(0x1930, 0xC0);
    u8 *mv;
    u8 *rot;
    if (m != 0) {
        *(u8 **)(m + 0xB8) = a0;
        mv = *(u8 **)(m + 0x68);
        m[0x30] = a0[0x30];
        *(u16 *)(m + 0x32) = *(u16 *)(a0 + 0x32);
        m[0x31] = a0[0x31];
        m[0x20] = 1;
        *(long *)(m + 0x38) = *(long *)(a0 + 0x38);
        *(u128_3BAF58 *)(m + 0x10) = *(u128_3BAF58 *)(a0 + 0x10);
        func_L01_00366E48(m, mv, mv + 4, mv + 0x10, 0);
        func_L04_003BB058(m, mv);
        rot = m + 0xF0;
        qzero(m + 0xF0);
        *(f32 *)(m + 0xF8) = *(f32 *)(a0 + 0xF8);
        if (*(s32 *)(pv + 8) < 0) {
            *(f32 *)(m + 0xF0) = 3.1415927f;
            *(f32 *)(mv + 8) = -*(f32 *)(mv + 8);
        }
        func_0038D308(m + 0xC0, rot);
        *(u16 *)(m + 0x34) |= 0x104;
        *(s32 *)(mv + 0xA0) = 0;
    }
    return m;
}
/* localdecomp:end func_L04_003BAF58 */

/* localdecomp:start func_L04_003BB058 */
extern void func_L01_0043A800(u8 *, s32, void *);
extern void func_L01_0043A430(u8 *, s32, void *);
extern void func_0038CB78(void *, s32, s32);

void func_L04_003BB058(u8 *a0, u8 *a1) {
    f32 v[4];
    func_L01_0043A800(a0, 1, v);
    *(s32 *)(a1 + 0xC) = 0;
    *(f32 *)(a1 + 8) = v[2];
    qzero(a1 + 0x90);
    func_0038CB78(a1 + 0x50, 0, 0x40);
    func_L01_0043A430(a0, 1, a1 + 0x50);
}
/* localdecomp:end func_L04_003BB058 */

/* localdecomp:start func_L04_003BB0D0 */
typedef int u128_3BB0D0 __attribute__((mode(TI)));
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_L04_00455AF8(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);

void func_L04_003BB0D0(u8 *a0, u8 *a1) {
    f32 d;
    if (func_L01_0040E548(a0 + 0x10, a1 + 0x90) < 0.001f) {
        return;
    }
    if (*(f32 *)(a0 + 0xF0) == 3.1415927f) {
        d = *(f32 *)(a0 + 0x18) - func_L04_00455AF8(a0 + 0x10) - *(f32 *)(a1 + 8);
    } else {
        d = func_003C3D30(a0 + 0x10, 0, 0, 0.5f) - *(f32 *)(a0 + 0x18) - *(f32 *)(a1 + 8);
    }
    if (d > 3.0f) {
        d = 3.0f;
    } else if (d < -3.0f) {
        d = -3.0f;
    }
    *(f32 *)(a1 + 0x88) = *(f32 *)(a1 + 0xC) = d * (1024.0f / *(f32 *)(a0 + 0x2C));
    *(u128_3BB0D0 *)(a1 + 0x90) = *(u128_3BB0D0 *)(a0 + 0x10);
}
/* localdecomp:end func_L04_003BB0D0 */
