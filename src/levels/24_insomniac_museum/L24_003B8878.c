#include "common.h"

typedef int u128_t __attribute__((mode(TI)));


/* localdecomp:start func_L24_003B8878 */
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    Vec4 v;
    u8 *o;
    s32 pad14;
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[20];
} S_357DC0;

extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_L24_0042D168(S_357DC0 *s, u8 *o, s32 a, Vec4 *v, f32 f);
extern s32 func_003D3CB0(s32 a, s32 b, s32 c, u8 *o, S_357DC0 *s);
extern u8 D_001A4BE0[];

s32 func_L24_003B8878(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f12, f32 f13) {
    Vec4 v;
    S_357DC0 s;
    u8 *b;
    u8 *p;
    s32 r;

    if (*(u16 *)(a0 + 52) & 0x100) {
        v.q = *(u128_t *)(a0 + 192);
    } else {
        v.f[0] = func_0038D098(*(f32 *)(a0 + 248));
        v.f[1] = func_0038D0B0(*(f32 *)(a0 + 248));
        v.f[2] = 0.0f;
    }
    func_0038CE20(v.f, v.f, f13);
    v.f[2] = 1.0f;
    v.f[3] = 5627.9248046875f;
    func_L24_0042D168(&s, a0, a3, &v, f12);
    b = D_001A4BE0;
    s.b18 = a4;
    s.b19 = a5;
    s.h1A = *(u16 *)(a0 + 170);
    s.o = a0;
    *(s32 *)(*(u8 **)(b + 9664) + 152) = 0;
    r = func_003D3CB0(a1, a2, a6, a0, &s);
    p = *(u8 **)(b + 9664);
    *(s32 *)(p + 152) = *(s32 *)(*(u8 **)(p + 36) + 16);
    return r;
}
/* localdecomp:end func_L24_003B8878 */
