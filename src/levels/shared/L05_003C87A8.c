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

/* localdecomp:start func_L05_003C8890 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C8890;
extern void func_003C5180(void *, void *, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00443B88_003C8890(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_0046B458_003C8890(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_00470C78_003C8890(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
extern u8 D_001D66B0;
__asm__(".extern D_L05_001DEC70_003C8890, 8");
extern s32 D_L05_001DEC70_003C8890[2];
__asm__(".extern D_L05_001DEC90_003C8890, 8");
extern f32 D_L05_001DEC90_003C8890[2];
__asm__(".extern D_L05_001DECB0_003C8890, 8");
extern f32 D_L05_001DECB0_003C8890[2];
__asm__(".extern D_L05_001DECD0_003C8890, 8");
extern s32 D_L05_001DECD0_003C8890[2];

u8 *func_L05_003C8890(void *a0, void *a1, void *pos, void *dir, f32 scale)
{
    V_3C8890 v;
    V_3C8890 d;
    u8 *obj;
    u8 *m;
    f32 t;
    s32 i;

    func_003C5180(pos, &v, 1);
    obj = func_003C24B0(0x1C33, 0x80);
    if (obj != 0) {
        m = *(u8 **)(obj + 0x68);
        *(u16 *)(obj + 0x34) |= 0x100;
        *(s32 *)(m + 0x20) = 0xFA;
        obj[0x30] = 0xFF;
        *(s16 *)(obj + 0x32) = 0xFF;
        *(f32 *)(obj + 0x2C) = 0.003f;
        obj[0x20] = 0;
        *(u128_t *)(obj + 0x10) = *(u128_t *)pos;
        *(u128_t *)m = *(u128_t *)dir;
        *(void **)(m + 0x34) = a1;
        func_L01_00443B88_003C8890(m + 0x10, 0.2f, 1.0f);
        t = func_003824E0(-1000.0f, 1000.0f) * 0.017453292f * 0.020000001f;
        func_0038CF68(m + 0x10, m + 0x10, func_0038D0B0(t));
        *(f32 *)(m + 0x1C) = func_0038D098(t);
        *(f32 *)(m + 0x2C) = scale;
        *(s32 *)(m + 0x28) = 0;
        *(s32 *)(m + 0x24) = 0;
        func_0038CF68(&d, dir, 1.0f);
        *(V_3C8890 *)(obj + 0xC0) = d;
        func_0038CE90(obj + 0xD0, obj + 0xC0, &v);
        func_0038CF68(obj + 0xD0, obj + 0xD0, 1.0f);
        func_0038CE90(obj + 0xE0, obj + 0xD0, obj + 0xC0);
        *(f32 *)(obj + 0xCC) = *(f32 *)(obj + 0xDC) = *(f32 *)(obj + 0xEC) = 0.0f;
        *(void **)(m + 0x30) = a0;
        for (i = 0; i < 4; i++) {
            func_L01_0046B458_003C8890(pos, 0xC, D_L05_001DEC90_003C8890[i], D_L05_001DECB0_003C8890[i], D_L05_001DEC70_003C8890[i], 2, 1, &D_001D66B0, 0.0f, 1);
        }
        for (; i < 7; i++) {
            func_L01_00470C78_003C8890(pos, 0x11, D_L05_001DEC90_003C8890[i], D_L05_001DECB0_003C8890[i], D_L05_001DEC70_003C8890[i], 2, 2, &D_001D66B0, 0, D_L05_001DECD0_003C8890[i - 4], 6, 1);
        }
    }
    return obj;
}
/* localdecomp:end func_L05_003C8890 */

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
