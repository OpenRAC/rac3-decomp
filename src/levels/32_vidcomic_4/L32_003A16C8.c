#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L32_003A16C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A16C8;
typedef struct { u8 pad[0x200]; u8 *nodes[6]; } Own_003A16C8;
typedef struct {
    u8 pad0[3];
    u8 alpha;
    u32 col0;
    u8 pad8[2];
    s16 len;
    u32 col1;
    V4_003A16C8 p0;
    V4_003A16C8 p1;
} O_003A16C8;
void *memcpy(void *, const void *, unsigned int);
extern u8 D_L32_001E2280[] __attribute__((section(".sdata")));
extern f32 D_L32_001DE790;
extern f32 D_L32_001DE78C;
extern s32 D_L32_001DE798;
extern s32 D_L32_001DE794;
extern s32 D_L32_001DE7A8;
extern f32 D_L32_001DE77C;
extern f32 D_L32_001DE7A4;
extern s32 D_L32_001DE7A0;
extern s32 D_L32_001DE79C;
__asm__(".extern D_L32_001DE790, 4");
__asm__(".extern D_L32_001DE78C, 4");
__asm__(".extern D_L32_001DE798, 4");
__asm__(".extern D_L32_001DE794, 4");
__asm__(".extern D_L32_001DE7A8, 4");
__asm__(".extern D_L32_001DE77C, 4");
__asm__(".extern D_L32_001DE7A4, 4");
__asm__(".extern D_L32_001DE7A0, 4");
__asm__(".extern D_L32_001DE79C, 4");
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_00448070(f32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(f32, s32, s32);

void func_L32_003A16C8(O_003A16C8 *o, u8 *p) {
    V4_003A16C8 d0, d1, d2;
    u8 *owner;
    Own_003A16C8 *data;
    u8 *settings;
    u8 *from;
    u8 *to;
    s32 first, wrapped, second, i;
    u16 bits;
    f32 r0, r1, half, frac, power;

    if (p == 0) return;
    owner = *(u8 **)p;
    settings = D_L32_001E2280;
    data = *(Own_003A16C8 **)(owner + 0x68);
    if (owner == 0) return;
    if (data == 0) return;
    if (settings == 0) return;
    first = func_00382498(0, 5);
    if (func_003824E0(0.0f, 1.0f) < 0.33f) {
        second = first + 3;
    } else if (func_003824E0(0.0f, 1.0f) < 0.5f) {
        second = first + 1;
    } else {
        second = first + 5;
    }
    wrapped = second % 6;
    second = (s16)wrapped;
    if (p[9] & 1) {
        r0 = func_003824E0(0.0f, 1.0f);
        r1 = func_003824E0(0.0f, 1.0f);
        *(u16 *)(p + 0xA) = first + (second << 3) + ((s32)(r1 * 31.0f) << 6) + ((s32)(r0 * 31.0f) << 11);
        if (data->nodes[first] == 0) goto fail;
        if (data->nodes[second] == 0) {
            o->len = 0;
            return;
        }
        *(vu0_q *)&o->p0 = *(vu0_q *)(data->nodes[first] + 0x10);
        half = (r0 + 1.0f) * 0.5f;
        *(vu0_q *)&o->p1 = *(vu0_q *)(data->nodes[first] + 0x10);
        o->p0.w = func_003C4088(D_L32_001DE790, D_L32_001DE78C, half);
        o->p1.w = 1.0f;
        p[8] = func_L01_00448070(half, D_L32_001DE798, D_L32_001DE794) / 4;
        o->len = p[8] << 2;
        o->alpha = settings[0x10];
    }
    if (data->nodes[first] == 0 || data->nodes[wrapped] == 0) {
fail:
        o->len = 0;
        return;
    }
    frac = 1.0f - (f32)o->len * 0.25f / (f32)p[8];
    power = 1.0f;
    bits = *(u16 *)(p + 0xA);
    for (i = 0; i < D_L32_001DE7A8; i++) {
        power *= frac;
    }
    first = bits & 7;
    if (data->nodes[first] == 0) return;
    from = *(u8 **)(data->nodes[first] + 0x68);
    if (from == 0) return;
    if (data->nodes[(bits & 0x38) >> 3] == 0) return;
    to = *(u8 **)(data->nodes[(bits & 0x38) >> 3] + 0x68);
    if (to == 0) return;
    r0 = (f32)(bits >> 11) / 31.0f;
    r1 = (f32)((bits & 0x7C0) >> 6) / 31.0f;

    vec_sub_ba(&d0, to + 0x30, from + 0x30);
    func_0038CE20(&d0, &d0, frac);
    vec_add_ab(&d2, &d0, from + 0x30);
    vec_sub_ab(&d1, &d2, owner + 0x10);
    func_0038CF68(&d1, &d1, D_L32_001DE77C * r1 * ((0.5f - fabs_asm(frac - 0.5f)) + (0.5f - fabs_asm(frac - 0.5f))) + r0 * D_L32_001DE7A4);
    vec_add_ba(&d2, &d2, &d1);
    memcpy(&o->p0, &d2, 12);

    vec_sub_ba(&d0, to + 0x30, from + 0x30);
    func_0038CE20(&d0, &d0, power);
    vec_add_ab(&d2, &d0, from + 0x30);
    vec_sub_ab(&d1, &d2, owner + 0x10);
    func_0038CF68(&d1, &d1, D_L32_001DE77C * r1 * ((0.5f - fabs_asm(power - 0.5f)) + (0.5f - fabs_asm(power - 0.5f))) + r0 * D_L32_001DE7A4);
    vec_add_ab(&d2, &d2, &d1);
    memcpy(&o->p1, &d2, 12);

    o->col0 = (func_0038DBD8(frac, D_L32_001DE7A0, D_L32_001DE79C) & 0xFFFFFF) + ((s32)(frac * 64.0f + 63.0f) << 24);
    func_0038DBD8(power, D_L32_001DE7A0, D_L32_001DE79C);
    o->col1 = (o->col0 & 0xFFFFFF) + ((s32)(power * 64.0f + 63.0f) << 24);
}
/* localdecomp:end func_L32_003A16C8 */
