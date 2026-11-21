#include "common.h"

/* declared by functions of L32_003B5828.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L32_003B5C98 */
typedef struct {
    u8 pad0[3];
    u8 alpha;
    s32 col0;
    u8 pad8[2];
    s16 hA;
    s32 col1;
    f32 p0[4];
    f32 p1[4];
} A_003B5C98;
typedef struct {
    u8 *moby;
    void *p4;
    u8 b8;
    u8 b9;
    u8 padA[2];
    f32 fC;
} B_003B5C98;
extern s32 D_L32_001DF9C0;
__asm__(".extern D_L32_001DF9C0, 16");
extern u8 D_L32_001E24A0[] __attribute__((section(".sdata")));
extern f32 D_L32_001DEEE0;
__asm__(".extern D_L32_001DEEE0, 4");
extern f32 D_L32_001DEEE4;
__asm__(".extern D_L32_001DEEE4, 4");
extern s32 D_L32_001DEEE8;
__asm__(".extern D_L32_001DEEE8, 4");
extern s32 D_L32_001DEEEC;
__asm__(".extern D_L32_001DEEEC, 4");
extern s32 D_L32_001DEEF0;
__asm__(".extern D_L32_001DEEF0, 4");
extern s32 D_L32_001DEEF4;
__asm__(".extern D_L32_001DEEF4, 4");
extern f32 D_L32_001DEEFC;
__asm__(".extern D_L32_001DEEFC, 4");
extern f32 D_L32_001DEF00;
__asm__(".extern D_L32_001DEF00, 4");
extern f32 D_L32_001DEF04;
__asm__(".extern D_L32_001DEF04, 4");
extern f32 D_L32_001DEF14;
__asm__(".extern D_L32_001DEF14, 4");
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L03_0034B440(f32, f32, f32, s32, s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

void func_L32_003B5C98(void *arg0, void *arg1) {
    A_003B5C98 *a0 = arg0;
    B_003B5C98 *a1 = arg1;
    u8 *moby;
    u8 *sys;
    u8 *m68;
    f32 d;
    f32 s;
    f32 t;

    if (a1 == 0) {
        return;
    }
    moby = a1->moby;
    sys = D_L32_001E24A0;
    m68 = *(u8 **)(moby + 0x68);
    if (moby == 0 || m68 == 0 || sys == 0) {
        return;
    }
    if (a1->b9 & 1) {
        func_003C2F58(moby, 0, a0->p0);
        a0->p0[2] += D_L32_001DEF00 * 0.5f;
        *(u128_t *)a0->p1 = *(u128_t *)a0->p0;
        a0->p1[2] -= D_L32_001DEF00;
        a0->p1[3] = 1.0f;
        a0->p0[3] = D_L32_001DEF14;
        a1->fC = D_L32_001DEF04 * *(f32 *)(m68 + 0x140);
        a0->alpha = sys[0x10];
    }
    s = 1.0f - (f32)a0->hA * 0.25f / (f32)a1->b8;
    a0->p0[0] += a1->fC;
    a0->p1[0] += a1->fC;
    d = D_L32_001DEEFC - D_L32_001DEF00;
    a0->p0[2] += d / ((f32)a1->b8 * 4.0f);
    a0->p1[2] -= d / ((f32)a1->b8 * 4.0f);
    a0->p0[3] += D_L32_001DEF14 * d / (D_L32_001DEF00 * 4.0f * (f32)a1->b8);
    t = func_L03_0034B440((f32)(D_L32_001DF9C0 % D_L32_001DEEF4), (f32)D_L32_001DEEF4, 1.0f, 0, 0, 5);
    a0->col0 = func_0038DBD8(D_L32_001DEEEC, D_L32_001DEEF0, t);
    t = func_L03_0034B440((f32)(D_L32_001DF9C0 % D_L32_001DEEE8), (f32)D_L32_001DEEE8, 1.0f, 0, 0, 5);
    a0->col1 = a0->col0 = (a0->col0 & 0xFFFFFF) + ((s32)(func_003C4088(D_L32_001DEEE4, D_L32_001DEEE0, t) * (1.0f - s)) << 24);
}
/* localdecomp:end func_L32_003B5C98 */
