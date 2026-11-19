#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003C87A8 */
extern void func_L05_003C8CE8(u8 *a0);
extern void func_L05_003C8B78(u8 *, void *);
extern s32 func_0038CAD0(void *);
extern void func_L05_003C9318(void *);
extern void func_003C2880(void *);
extern void func_L01_00404A10(void *, void *);

void func_L05_003C87A8(u8 *a0) {
    u8 *m;
    vu0_v4 p;

    a0[0x31] = 0;
    *(u16 *)(a0 + 0x34) |= 1;
    m = *(u8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        a0[0x20] = 1;
    case 1:
        *(vu0_q *)&p = *(vu0_q *)(a0 + 0x10);
        vec_add_ba(a0 + 0x10, m, a0 + 0x10);
        func_L05_003C8B78(a0, &p);
        if (func_0038CAD0(m + 0x20)) {
            a0[0x20] = 2;
        }
        func_L05_003C9318(a0 + 0x10);
        break;
    case 2:
        func_003C2880(a0);
        return;
    }
    func_L01_00404A10(func_L05_003C8CE8, a0);
}
/* localdecomp:end func_L05_003C87A8 */

INCLUDE_ASM("asm/levels", func_L05_003C8890);

/* localdecomp:start func_L05_003C8B78 */
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_003CD248_003C8B78(void *, s32, s32, s32, void *);
extern void func_L01_00446BC8(void *, void *, s32, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *D_L05_001EA6D8_003C8B78[];
extern s32 D_001D545C;

void func_L05_003C8B78(u8 *a0, void *p) {
    u8 *m;
    u8 *t;
    s32 r;
    u8 *pos;

    pos = a0 + 0x10;
    m = *(u8 **)(a0 + 0x68);
    func_L01_004CB320();
    r = func_003D3CB0(p, pos, 0, a0, 0);
    if (r != 0) {
        t = D_L05_001EA6D8_003C8B78[0];
        if (t != 0 && *(s16 *)(t + 0xAA) == 0x186D && t[0x20] != 2 && t[0x20] != 5) {
            t[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (r != 0) {
        func_L01_003CD248_003C8B78(a0 + 0x10, 10, 3, 0, a0);
        t = D_L05_001EA6D8_003C8B78[0];
        if (t != 0 && t != *(u8 **)(m + 0x30) && (*(u16 *)(t + 0x34) & 0x4000) &&
            (*(s16 *)(t + 0xAA) != *(s16 *)(*(u8 **)(m + 0x30) + 0xAA) || t == *(u8 **)(m + 0x34))) {
            if (D_001D545C != 0x14) {
                func_L01_00446BC8(t, a0, 0x10001, a0 + 0x10, *(f32 *)(m + 0x2C));
            } else {
                func_L01_00446BC8(t, a0, 1, a0 + 0x10, *(f32 *)(m + 0x2C));
            }
        } else {
            func_003A52A0(0, 0, a0);
        }
        a0[0x20] = 2;
    }
}
/* localdecomp:end func_L05_003C8B78 */

/* localdecomp:start func_L05_003C8CE8 */
extern f32 func_0038CEA8(void *);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
__asm__(".extern D_L05_001DECE0, 8");
extern f32 D_L05_001DECE0[2];
__asm__(".extern D_L05_001DECF0, 8");
extern s32 D_L05_001DECF0[2];
__asm__(".extern D_L05_001DED00, 8");
extern s32 D_L05_001DED00[2];
__asm__(".extern D_L05_001DED10, 8");
extern s32 D_L05_001DED10[2];

void func_L05_003C8CE8(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 t;
    s32 i;
    t = *(f32 *)(pv + 0x24) - 0.1f;
    *(f32 *)(pv + 0x24) = t;
    if (t <= -8.0f) {
        *(f32 *)(pv + 0x24) = t + 8.0f;
    }
    *(f32 *)(pv + 0x28) = *(f32 *)(pv + 0x28) + func_0038CEA8(pv);
    for (i = 0; i < 2; i++) {
        func_003D9508(a0 + 0x10, D_L05_001DED00[i], D_L05_001DECF0[i], D_L05_001DED10[i], D_L05_001DECE0[i], 0.0f, func_00382538());
    }
}
/* localdecomp:end func_L05_003C8CE8 */
