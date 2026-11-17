#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003B1BD0 */
extern u16 *D_L05_0021DAE0[];
extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DFB9C, 16");
extern s32 D_001DFBD8_sda;
__asm__(".extern D_001DFBD8_sda, 4");
extern s32 func_L01_00456250(u8 *);
extern f32 func_L01_0040E570(u8 *, void *);

u8 *func_L05_003B1BD0(u8 *a0, void *a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p = D_L05_0021DAE0[*(s32 *)(s + 0x2AC)];
    u8 *e;
    while ((*(s32 *)(s + 0x2AC) & 0xFF) != 0xFF
        && D_001DFBD8_sda >= *(s32 *)(s + 0x2AC)
        && p != 0
        && ((s16)p[-1] >= 0 || p == D_L05_0021DAE0[*(s32 *)(s + 0x2AC)])) {
        e = D_L05_001DFB9C + ((*p & 0x7FFF) << 8);
        if (e == 0) return 0;
        if (e[0x20] != 0xFE) {
            if (e[0x20] == 0xFD) {
                p++;
                continue;
            }
            if (func_L01_00456250(e) != 0) {
                p++;
                continue;
            }
            if (func_L01_0040E570(e + 0x10, a1) < 4.84f) {
                return e;
            }
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L05_003B1BD0 */

INCLUDE_ASM("asm/levels", func_L05_003B1CF8);

/* localdecomp:start func_L05_003B1E80 */
s32 func_L05_003B1E80(s32 arg0, s32 arg1) {
    return (arg1 * 2) + arg0;
}
/* localdecomp:end func_L05_003B1E80 */

/* localdecomp:start func_L05_003B1E90 */
typedef struct {
    vu0_v4 pos;
    u8 pad[0x134];
    u8 *f144;
    s32 f148;
} S_3B1E90;
extern S_3B1E90 D_L05_001E2700;
extern f32 func_0038D098(f32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0040C3C0(void *, s32, s32, s32, s32, s32, s32, f32, f32);

void func_L05_003B1E90(u8 *o) {
    vu0_v4 q[4];
    vu0_v4 e;
    u8 *v;
    f32 t;
    f32 sz;
    s32 n;
    s32 al;
    s32 col;

    v = *(u8 **)(o + 0x68);
    t = 1.0f - __builtin_fabsf(1.0f - (f32)(*(s16 *)(v + 0x2B4) - 1) * 2.0f / (f32)(*(s16 *)(v + 0x2B6) - 2));
    if (t < 0.0f) {
        return;
    }
    t = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f;
    n = (f32)(*(s16 *)(v + 0x2B6) - 2) * 0.5f;
    sz = t * 0.6f;
    if (v[0x2B9] != 0 && n >= *(s16 *)(v + 0x2B4)) {
        if (v[0x2B9] == 2) {
            *(u16 *)(o + 0x34) &= 0xFFBE;
            *(u16 *)(o + 0x34) |= *(u16 *)(*(u8 **)(o + 0x24) + 0x44) & 0x1000;
            *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
            if (D_L05_001E2700.f144 == 0) {
                D_L05_001E2700.f144 = o;
                D_L05_001E2700.f148 = 0;
            }
        } else {
            *(s32 *)(o + 0x98) = 0;
            *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(o, 1);
            if (D_L05_001E2700.f144 == o) {
                D_L05_001E2700.f144 = 0;
            }
        }
        v[0x2B9] = 0;
    }
    vec_sub_ab(&q[0], &D_L05_001E2700.pos, o + 0x10);
    func_0038CF68(&q[0], &q[0], *(f32 *)(o + 0x2C) * 15.5f + 2.0f);
    func_0038CF68(&q[2], o + 0xE0, *(f32 *)(o + 0x2C) * 12.0f + 2.0f);
    func_0038CE90(&q[1], &q[2], &q[0]);
    func_0038CF68(&q[1], &q[1], *(f32 *)(o + 0x2C) * 26.0f + 2.0f);
    func_0038CF68(&e, &q[2], -1.8f);
    vec_add_ba(&q[3], o + 0x10, &e);
    func_0038CE20(&q[0], &q[0], 0.5f);
    vec_add_ab(&q[3], &q[3], &q[0]);
    *(f32 *)(v + 0x298) = func_0038DAB8(*(f32 *)(v + 0x298), 0.013962635f);
    if (t < 0.05f) {
        al = (u8)(s32)(t * 20.0f * 127.0f);
    } else {
        al = 0x7F;
    }
    col = (al << 24) | 0x808080;
    func_L01_0040C3C0(q, 0x40, col, col, col, 0x4D, -1, sz, *(f32 *)(v + 0x298));
}
/* localdecomp:end func_L05_003B1E90 */
