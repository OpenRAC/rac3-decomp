#include "common.h"

/* NTSC-U counterpart of func_L32_0034D748 (src/levels/shared/L32_0034D748.c) */
/* localdecomp:start func_L32_0034CAB8 */
#include "vu0.h"

typedef struct {
    s32 x0;
    f32 x4;
    s32 x8;
    f32 xC;
    s32 x10;
    s32 x14;
} V_34D748;

extern u8 D_001A30B0[];
extern u8 *D_001A71A0[];
extern u8 *D_L32_001EDA00_0034CAB8[];
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_00388398(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern u8 *func_L01_00444358(void *, s32, s32);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L32_0034CF08(u8 *);
extern void func_003BD360(void *);

void func_L32_0034CAB8(u8 *o) {
    V_34D748 *p = *(V_34D748 **)(o + 0x68);
    vu0_v4 v;
    u8 *r;
    u8 *q;
    u8 *t;
    u8 *u;
    u8 *e;
    s32 h;
    s32 n;
    s32 i;
    f32 g;
    f32 d;

    switch (o[0x20]) {
    case 0:
        *(f32 *)(o + 0xF4) = func_00389380(*(f32 *)(o + 0xF4), -0.1163552924990654f);
        h = p->x10;
        if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != o) || e[0xD0] == 0) {
            p->x10 = func_0039FE80(0, 4, o);
        }
        v.x = func_00388960(*(f32 *)(o + 0xF8)) * -0.11666667461395264f;
        v.y = func_00388978(*(f32 *)(o + 0xF8)) * -0.11666667461395264f;
        v.z = 0.0f;
        vec_add_ab(o + 0x10, o + 0x10, &v);
        p->x8++;
        if (func_00388398(p) != 0) {
            goto die;
        }
        if (*(f32 *)(o + 0x18) < p->xC) {
            goto die;
        }
        r = func_L01_00444358(o, 0x10000, 0);
        if (r != 0 && (t = *(u8 **)(r + 0x20)) != 0 &&
            (t == D_001A71A0[0] || *(s16 *)(t + 0xAA) == 0x13A1 || *(s16 *)(t + 0xAA) == 0x18F5)) {
            if (t == 0) {
                goto die;
            }
            if (*(s16 *)(t + 0xAA) == 0x18F5 && p->x14 == 0) {
                p->x14 = 1;
                func_0039FE80(3, 0, o);
            }
            u = *(u8 **)(r + 0x20);
            if (u == 0 || *(s16 *)(u + 0xAA) != 0x13A1) {
                goto die;
            }
            p->x0 = 7;
        }
        o[0xA8] = 0xFF;
        if (p->x8 >= 11 && func_L01_003F9498(o + 0x10, 2, 0, 0.7f) != 0) {
            p->x0 = 0;
            goto die;
        }
        n = func_003CF790(o + 0x10, 0, o, 0, 0.7f);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (D_L32_001EDA00_0034CAB8[i] == D_001A71A0[0]) {
                    goto die;
                }
            }
        }
        g = func_003BE7F0(o + 0x10, 0, 0, 0.5f);
        p->x4 -= 0.008333333767950535f;
        g += 0.75f;
        *(f32 *)(o + 0x18) += p->x4;
        if (*(f32 *)(o + 0x18) <= g) {
            *(f32 *)(o + 0x18) = g;
            p->x4 = 0.0f;
        }
        break;
    case 1:
        break;
    case 2:
        d = 0.3f;
        if (p->x8 == 0) {
            func_0039FE80(2, 0, o);
        }
        p->x8++;
        *(f32 *)(o + 0xF4) = func_00389380(*(f32 *)(o + 0xF4), -0.16580629348754883f);
        p->x4 -= 0.004166666883975267f;
        *(f32 *)(o + 0x18) += p->x4;
        q = func_L01_00444358(o, 0x10000, 0);
        if (q != 0) {
            u = *(u8 **)(q + 0x20);
            if (u != 0 && *(s16 *)(u + 0xAA) == 0x18F5 && p->x14 == 0) {
                p->x14 = 1;
                func_0039FE80(3, 0, o);
            }
            goto die;
        }
        if (p->x8 >= 11 && func_L01_003F9498(o + 0x10, 2, 0, 0.25f) != 0) {
        die:
            func_L32_0034CF08(o);
            func_003BD360(o);
            return;
        }
        n = func_003CF790(o + 0x10, 0, o, 0, d - 0.05f);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (D_L32_001EDA00_0034CAB8[i] == D_001A71A0[0]) {
                    goto die;
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L32_0034CAB8 */
