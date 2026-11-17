#include "common.h"

/* localdecomp:start func_L32_0034D748 */
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
extern u8 *D_L32_001EDA00[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038CAD0(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L32_0034DB98(u8 *);
extern void func_003C2880(void *);

void func_L32_0034D748(u8 *o) {
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
        *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), -0.13962635f);
        h = p->x10;
        if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != o) || e[0xD0] == 0) {
            p->x10 = func_003A52A0(0, 4, o);
        }
        v.x = func_0038D098(*(f32 *)(o + 0xF8)) * -0.14000001f;
        v.y = func_0038D0B0(*(f32 *)(o + 0xF8)) * -0.14000001f;
        v.z = 0.0f;
        vec_add_ab(o + 0x10, o + 0x10, &v);
        p->x8++;
        if (func_0038CAD0(p) != 0) {
            goto die;
        }
        if (*(f32 *)(o + 0x18) < p->xC) {
            goto die;
        }
        r = func_L01_00447490(o, 0x10000, 0);
        if (r != 0 && (t = *(u8 **)(r + 0x20)) != 0 &&
            (t == D_001A71A0[0] || *(s16 *)(t + 0xAA) == 0x13A1 || *(s16 *)(t + 0xAA) == 0x18F5)) {
            if (t == 0) {
                goto die;
            }
            if (*(s16 *)(t + 0xAA) == 0x18F5 && p->x14 == 0) {
                p->x14 = 1;
                func_003A52A0(3, 0, o);
            }
            u = *(u8 **)(r + 0x20);
            if (u == 0 || *(s16 *)(u + 0xAA) != 0x13A1) {
                goto die;
            }
            p->x0 = 6;
        }
        o[0xA8] = 0xFF;
        if (p->x8 >= 9 && func_L01_003FB640(o + 0x10, 2, 0, 0.7f) != 0) {
            p->x0 = 0;
            goto die;
        }
        n = func_003D4D00(o + 0x10, 0, o, 0, 0.7f);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (D_L32_001EDA00[i] == D_001A71A0[0]) {
                    goto die;
                }
            }
        }
        g = func_003C3D30(o + 0x10, 0, 0, 0.5f);
        p->x4 -= 0.012f;
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
            func_003A52A0(2, 0, o);
        }
        p->x8++;
        *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), -0.19896755f);
        p->x4 -= 0.006f;
        *(f32 *)(o + 0x18) += p->x4;
        q = func_L01_00447490(o, 0x10000, 0);
        if (q != 0) {
            u = *(u8 **)(q + 0x20);
            if (u != 0 && *(s16 *)(u + 0xAA) == 0x18F5 && p->x14 == 0) {
                p->x14 = 1;
                func_003A52A0(3, 0, o);
            }
            goto die;
        }
        if (p->x8 >= 9 && func_L01_003FB640(o + 0x10, 2, 0, 0.25f) != 0) {
        die:
            func_L32_0034DB98(o);
            func_003C2880(o);
            return;
        }
        n = func_003D4D00(o + 0x10, 0, o, 0, d - 0.05f);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (D_L32_001EDA00[i] == D_001A71A0[0]) {
                    goto die;
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L32_0034D748 */

INCLUDE_ASM("asm/levels", func_L32_0034DB98);
