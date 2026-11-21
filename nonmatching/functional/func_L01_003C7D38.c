/* functional: medium. 303 instructions differ (scheduling and register use); branch structure follows retail block by block; gp-relative floats named by address; needs the true prototypes of func_L01_003C7A68 (returns f32) and func_L01_003C7BC0 (extra f32 arg in f12). */
#include "vu0.h"
typedef struct { float x, y, z, w; } plain_v4;
static void plain_add(void *d, void *a, void *b) {
    plain_v4 *pd = d, *pa = a, *pb = b;
    pd->x = pa->x + pb->x; pd->y = pa->y + pb->y; pd->z = pa->z + pb->z; pd->w = pa->w;
}
static void plain_sub(void *d, void *a, void *b) {
    plain_v4 *pd = d, *pa = a, *pb = b;
    pd->x = pa->x - pb->x; pd->y = pa->y - pb->y; pd->z = pa->z - pb->z; pd->w = pa->w;
}
extern f32 D_L01_001DEC74_003C7D38;
__asm__(".extern D_L01_001DEC74_003C7D38, 4");
extern f32 D_L01_001DEC7C_003C7D38;
__asm__(".extern D_L01_001DEC7C_003C7D38, 4");
extern f32 D_L01_001DEC80_003C7D38;
__asm__(".extern D_L01_001DEC80_003C7D38, 4");
extern f32 D_L01_001DEC84_003C7D38;
__asm__(".extern D_L01_001DEC84_003C7D38, 4");
extern f32 D_L01_001DEC88_003C7D38;
__asm__(".extern D_L01_001DEC88_003C7D38, 4");
extern f32 D_L01_001DEC90_003C7D38;
__asm__(".extern D_L01_001DEC90_003C7D38, 4");
extern f32 D_L01_001DEC94_003C7D38;
__asm__(".extern D_L01_001DEC94_003C7D38, 4");
extern f32 D_L01_001DEC98_003C7D38;
__asm__(".extern D_L01_001DEC98_003C7D38, 4");
extern f32 D_L01_001DEC9C_003C7D38;
__asm__(".extern D_L01_001DEC9C_003C7D38, 4");
extern f32 D_L01_001DECA0_003C7D38;
__asm__(".extern D_L01_001DECA0_003C7D38, 4");
extern f32 D_L01_001DECA4_003C7D38;
__asm__(".extern D_L01_001DECA4_003C7D38, 4");
extern f32 D_L01_001DECA8_003C7D38;
__asm__(".extern D_L01_001DECA8_003C7D38, 4");
extern f32 D_L01_001DECAC_003C7D38;
__asm__(".extern D_L01_001DECAC_003C7D38, 4");
extern f32 D_L01_001DECB0_003C7D38;
__asm__(".extern D_L01_001DECB0_003C7D38, 4");
extern f32 D_L01_001DECB4_003C7D38;
__asm__(".extern D_L01_001DECB4_003C7D38, 4");
extern f32 D_L01_001DECB8_003C7D38;
__asm__(".extern D_L01_001DECB8_003C7D38, 4");
extern f32 D_L01_001DECBC_003C7D38;
__asm__(".extern D_L01_001DECBC_003C7D38, 4");
extern f32 D_L01_001DECC0_003C7D38;
__asm__(".extern D_L01_001DECC0_003C7D38, 4");
extern s32 D_L01_001DECD4_003C7D38;
__asm__(".extern D_L01_001DECD4_003C7D38, 4");
extern u8 *D_L01_0021F6C0[];
extern u8 *D_L01_001E0100;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CED8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, s32, f32, f32, f32);
extern f32 func_L01_003C7A98(void *, void *, s32 *, f32, f32);
extern void func_L01_003C7C80(void *, void *, void *, f32 *, f32 *);
extern f32 wrap_003C7A68(void *, void *, f32) __asm__("func_L01_003C7A68");
extern void spl_003C7BC0(void *, void *, s32, void *, f32) __asm__("func_L01_003C7BC0");

s32 func_L01_003C7D38(u8 *obj, u8 *s) {
    vu0_v4 dir;
    vu0_q pos_copy;
    vu0_v4 tmp40, tmp30;
    f32 zero_arg = 0.0f;
    s32 idx;
    f32 ret;
    f32 sp20, sp24, sp28;
    f32 limit;
    f32 dist_f;
    s32 result;
    u8 *t = D_L01_0021F6C0[*(s32 *)(s + 0xC0)];
    u8 *p = D_L01_001E0100 + *(s32 *)(s + *(s32 *)(s + 0x6BC) * 4 + 0x6D0) * 128;
    f32 pos, a, x, y, newpos;
    s32 clamped;
    pos_copy = *(vu0_q *)(obj + 0x10);
    dist_f = wrap_003C7A68(obj, s, D_L01_001DEC74_003C7D38);
    pos = *(f32 *)(s + 0xC4);
    if (pos < 0.0f) {
        plain_sub(&dir, t + 0x10, s + 0x140);
    } else {
        idx = (s32)pos;
        if (idx == *(s32 *)t - 1) {
            plain_sub(&dir, s + 0x150, t + idx * 16 + 0x10);
        } else {
            plain_sub(&dir, t + idx * 16 + 0x20, t + idx * 16 + 0x10);
        }
    }
    func_0038CF68(&dir, &dir, 1.0f);
    a = func_0038CE68(&dir, obj + 0xC0);
    if (a <= 0.0f) {
        y = D_L01_001DEC88_003C7D38;
        x = D_L01_001DEC80_003C7D38;
    } else {
        f32 tt = a * D_L01_001DEC7C_003C7D38;
        if (1.0f < tt) tt = 1.0f;
        x = D_L01_001DEC80_003C7D38 + (D_L01_001DEC74_003C7D38 - D_L01_001DEC80_003C7D38) * tt;
        y = D_L01_001DEC88_003C7D38 + (D_L01_001DEC84_003C7D38 - D_L01_001DEC88_003C7D38) * tt;
    }
    *(s32 *)&zero_arg = 0;
    func_003C41A0(&zero_arg, s + 0xC8, dist_f, y * 0.000400000019f, y * 0.000400000019f, x * 0.0200000014f);
    result = 0;
    newpos = func_L01_003C7A98(s, t, &idx, *(f32 *)(s + 0xC4), *(f32 *)(s + 0xC8));
    *(f32 *)(s + 0xC4) = newpos;
    clamped = 0;
    if (!(idx < *(s32 *)t - 1)) {
        idx = *(s32 *)t - 1;
        clamped = 1;
    }
    ret = newpos - (f32)idx;
    if (clamped && ret >= 1.0f) {
        result = 2;
        *(f32 *)(s + 0xC4) = newpos - *(f32 *)(s + 0xC8) / *(f32 *)(t + idx * 16 + 0x1C);
    }
    spl_003C7BC0(s, t, idx, obj + 0x10, ret);
    ret = *(f32 *)(s + 0x14C);
    if (obj[0x20] == 3 && !(idx < *(s32 *)t - D_L01_001DECD4_003C7D38)) {
        func_L01_003C7C80(obj, s, &pos_copy, &sp20, &sp24);
        sp20 = -sp20;
        sp24 = -sp24;
        sp20 = func_0038DAB8(sp20, *(f32 *)(p + 0x70));
        limit = D_L01_001DECA0_003C7D38 * 0.0174532925f;
        if (limit < sp24) sp24 = limit;
        else if (sp24 < -limit) sp24 = -limit;
        sp24 = func_0038DAB8(sp24, *(f32 *)(p + 0x74));
        sp28 = *(f32 *)(p + 0x78);
    } else if ((ret > 0.0f && idx == -1) || (ret < 0.0f && idx == 0)) {
        func_L01_003C7C80(obj, s, &pos_copy, &sp20, &sp24);
        sp20 = func_0038DAB8(sp20, *(f32 *)(p + 0x70));
        limit = D_L01_001DECA0_003C7D38 * 0.0174532925f;
        if (limit < sp24) sp24 = limit;
        else if (sp24 < -limit) sp24 = -limit;
        sp24 = func_0038DAB8(sp24, *(f32 *)(p + 0x74));
        sp28 = *(f32 *)(obj + 0xF8);
    } else {
        f32 step = *(f32 *)(s + 0xC8) * D_L01_001DEC90_003C7D38;
        f32 fr;
        if (D_L01_001DEC94_003C7D38 < step) step = D_L01_001DEC94_003C7D38;
        else if (step < D_L01_001DEC98_003C7D38) step = D_L01_001DEC98_003C7D38;
        newpos = func_L01_003C7A98(s, t, &idx, *(f32 *)(s + 0xC4), step);
        idx = (s32)newpos;
        fr = newpos - (f32)idx;
        spl_003C7BC0(s, t, idx, &tmp30, fr);
        plain_sub(&tmp40, &tmp30, obj + 0x10);
        sp20 = 0.0f;
        sp24 = -func_0038D160(func_0038CED8(&tmp40), tmp40.z);
        limit = D_L01_001DECA0_003C7D38 * 0.0174532925f;
        if (limit < sp24) sp24 = limit;
        else if (sp24 < -limit) sp24 = -limit;
        sp28 = func_0038D160(tmp40.x, tmp40.y);
    }
    func_L01_00448890(obj + 0xF4, sp24, s + 0x134, 0,
                      D_L01_001DECA4_003C7D38 * 0.0174532925f * 0.000400000019f,
                      D_L01_001DECA4_003C7D38 * 0.0174532925f * 0.000400000019f,
                      D_L01_001DECA8_003C7D38 * 0.0174532925f * 0.0200000014f);
    func_L01_00448890(obj + 0xF8, sp28, s + 0x138, 0,
                      D_L01_001DECAC_003C7D38 * 0.0174532925f * 0.000400000019f,
                      D_L01_001DECAC_003C7D38 * 0.0174532925f * 0.000400000019f,
                      D_L01_001DECB0_003C7D38 * 0.0174532925f * 0.0200000014f);
    sp20 = func_0038DAB8(sp20, *(f32 *)(s + 0x138) * *(f32 *)(s + 0xC8) * D_L01_001DECC0_003C7D38);
    limit = D_L01_001DECB4_003C7D38 * 0.0174532925f;
    if (limit < sp20) sp20 = limit;
    else if (sp20 < -limit) sp20 = -limit;
    func_L01_00448890(obj + 0xF0, sp20, s + 0x130, 0,
                      D_L01_001DECBC_003C7D38 * 0.0174532925f * 0.000400000019f,
                      D_L01_001DECBC_003C7D38 * 0.0174532925f * 0.000400000019f,
                      D_L01_001DECB8_003C7D38 * 0.0174532925f * 0.0200000014f);
    sp20 = *(f32 *)(p + 0x70);
    sp24 = *(f32 *)(p + 0x74);
    sp28 = *(f32 *)(p + 0x78);
    if (result == 2) {
        if (fabs_asm(func_0038DBA0(*(f32 *)(obj + 0xF0), sp20)) > D_L01_001DEC9C_003C7D38 ||
            fabs_asm(func_0038DBA0(*(f32 *)(obj + 0xF4), sp24)) > D_L01_001DEC9C_003C7D38 ||
            fabs_asm(func_0038DBA0(*(f32 *)(obj + 0xF8), sp28)) > D_L01_001DEC9C_003C7D38) {
            result = 1;
        }
    }
    return result;
}
