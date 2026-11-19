#include "common.h"

/* declared by functions of L30_00343398.c, which this file was cut from */
extern void func_L30_00343798(u8 *, f32);

/* localdecomp:start func_L30_00343660 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00343660;
extern u8 D_001A4BE0[];
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L30_00343AC8(void *, void *, f32 *, f32 *);
extern void func_L30_0034C540(void *, void *, f32, f32, f32, s32);
extern void func_003C7DD8(void *);

void func_L30_00343660(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 x = *(f32 *)(m + 0x10);
    V_00343660 buf[10];
    f32 a, b;
    u8 *hero;

    func_0038D308(m + 0xC0, m + 0xF0);
    func_0038CE20(m + 0xC0, m + 0xC0, *(f32 *)(v + 0x1A4));
    func_0038CE20(m + 0xD0, m + 0xD0, *(f32 *)(v + 0x1A8));
    func_0038CE20(m + 0xE0, m + 0xE0, *(f32 *)(v + 0x1AC));
    func_L30_00343AC8(m, buf, &a, &b);
    vec_sub_ab(m + 0x10, v + 0x130, &buf[0]);
    hero = D_001A4BE0;
    if (*(u8 **)(hero + 0x3C0) == m && *(u8 **)(hero + 0x35C) == m && *(s16 *)(hero + 0x36E) == 0 &&
        x != *(f32 *)(m + 0x10)) {
        V_00343660 t;
        qzero(&t);
        t.x = x - *(f32 *)(m + 0x10);
        vec_add_ab(hero + 0x370, hero + 0x370, &t);
    }
    func_L30_0034C540(&buf[1], v + 0x130, a + a, b + b, 0.0f, 0);
    func_003C7DD8(m);
    *(vu0_q *)(v + 0x70) = *(vu0_q *)(m + 0x10);
}
/* localdecomp:end func_L30_00343660 */

/* localdecomp:start func_L30_00343798 */
void func_L30_00343798(u8 *m, f32 t) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 old;
    vu0_v4 d;

    *(vu0_q *)&old = *(vu0_q *)(v + 0x130);
    func_0038CE20(&a, v + 0x140, 1.0f - t);
    func_0038CE20(&b, v + 0x150, t);
    vec_add_ab(v + 0x130, &a, &b);
    vec_sub_ab(&d, v + 0x130, &old);
    vec_add_ab(m + 0x10, m + 0x10, &d);
}
/* localdecomp:end func_L30_00343798 */

INCLUDE_ASM("asm/levels", func_L30_00343830);

/* localdecomp:start func_L30_00343AC8 */
__asm__(".extern D_L30_001DCE54, 4");
extern f32 D_L30_001DCE54;
__asm__(".extern D_L30_001DCE58, 4");
extern f32 D_L30_001DCE58;
__asm__(".extern D_L30_001DCE5C, 4");
extern f32 D_L30_001DCE5C;
__asm__(".extern D_L30_001DCE60, 4");
extern f32 D_L30_001DCE60;
__asm__(".extern D_L30_001DCE64_00343AC8, 4");
extern f32 D_L30_001DCE64_00343AC8;
__asm__(".extern D_L30_001DCE68, 4");
extern f32 D_L30_001DCE68;
__asm__(".extern D_L30_001DCE6C, 4");
extern f32 D_L30_001DCE6C;
__asm__(".extern D_L30_001DCE70_00343AC8, 4");
extern f32 D_L30_001DCE70_00343AC8;
__asm__(".extern D_L30_001DCE74, 4");
extern f32 D_L30_001DCE74;
__asm__(".extern D_L30_001DCE78_00343AC8, 4");
extern f32 D_L30_001DCE78_00343AC8;
__asm__(".extern D_L30_001DCE7C, 4");
extern f32 D_L30_001DCE7C;
__asm__(".extern D_L30_001DCE80, 4");
extern f32 D_L30_001DCE80;
__asm__(".extern D_L30_001DCE84, 4");
extern f32 D_L30_001DCE84;
__asm__(".extern D_L30_001DCE88_00343AC8, 4");
extern f32 D_L30_001DCE88_00343AC8;
__asm__(".extern D_L30_001DCE8C_00343AC8, 4");
extern f32 D_L30_001DCE8C_00343AC8;
extern void func_0038D000(void *, void *, void *);

void func_L30_00343AC8(void *arg0, void *arg1, f32 *ow, f32 *oh) {
    u8 *o = arg0;
    vu0_v4 *out = arg1;
    vu0_v4 t;
    f32 w;
    f32 h;
    f32 s;

    switch (*(s16 *)(o + 0xAA)) {
    case 0x1745:
        w = D_L30_001DCE58;
        h = D_L30_001DCE54;
        break;
    case 0x19B7:
        w = D_L30_001DCE60;
        h = D_L30_001DCE5C;
        break;
    case 0x19B9:
        w = D_L30_001DCE6C;
        h = D_L30_001DCE68;
        break;
    case 0x1A2A:
        w = D_L30_001DCE74;
        h = D_L30_001DCE70_00343AC8;
        break;
    case 0x1AED:
        w = D_L30_001DCE7C;
        h = D_L30_001DCE78_00343AC8;
        break;
    case 0x1AEF:
        w = D_L30_001DCE84;
        h = D_L30_001DCE80;
        break;
    case 0x1B16:
        w = D_L30_001DCE8C_00343AC8;
        h = D_L30_001DCE88_00343AC8;
        break;
    default:
        h = 1.0f;
        w = h;
        break;
    }
    s = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
    qzero(&t);
    w *= s;
    h *= s;
    t.x = w;
    t.z = h;
    func_0038D000(&t, &t, o + 0xC0);
    w = t.x;
    h = t.z;
    if (out != 0) {
        qzero(out);
        if (*(s16 *)(o + 0xAA) == 0x19B7 || *(s16 *)(o + 0xAA) == 0x1AED || *(s16 *)(o + 0xAA) == 0x1AEF) {
            out->x += w;
        }
        if (*(s16 *)(o + 0xAA) == 0x19B7) {
            out->z -= h;
        }
        if (*(s16 *)(o + 0xAA) == 0x19B9) {
            out->z += D_L30_001DCE64_00343AC8;
        }
        if (*(s16 *)(o + 0xAA) == 0x1AED || *(s16 *)(o + 0xAA) == 0x1AEF) {
            out->z += h;
        }
    }
    if (ow != 0) {
        *ow = w;
    }
    if (oh != 0) {
        *oh = h;
    }
}
/* localdecomp:end func_L30_00343AC8 */
