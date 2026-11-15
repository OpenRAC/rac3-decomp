#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L21_003AFCF0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003AFCF0;
typedef struct {
    V4_003AFCF0 m[4];
    s32 c[4];
    f32 x50, x54, x58, x5C, x60, x64, x68, x6C;
    long x70, x78, x80, x88;
} S_003AFCF0;
extern long func_00389598(s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L21_003AFCF0(u8 *m) {
    S_003AFCF0 s;
    V4_003AFCF0 t;
    V4_003AFCF0 base;
    V4_003AFCF0 pts[4];
    V4_003AFCF0 off;
    s32 i;

    s.x78 = func_00389598(0x65);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0xFF00000048L;
    s.x70 = 0;
    s.c[3] = 0xFFFF004F;
    s.c[2] = 0xFFFF004F;
    s.c[1] = 0xFFFF004F;
    s.c[0] = 0xFFFF004F;
    s.x50 = 0.0f;
    s.x54 = 0.0f;
    s.x58 = 1.0f;
    s.x5C = 0.0f;
    s.x60 = 0.0f;
    s.x64 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    func_003C2F58(m, 1, &t);
    *(u128_t *)&base = *(u128_t *)(m + 0x10);
    base.z = t.z;
    for (i = 0; i < 4; i++) {
        f32 r = func_0038D160(t.x - *(f32 *)(m + 0x10), t.y - *(f32 *)(m + 0x14));
        f32 a = (f32)(i * 90) * 0.017453292f;
        off.x = func_0038D098(func_0038DAB8(r, a)) * 1.8f;
        off.y = func_0038D0B0(func_0038DAB8(func_0038D160(t.x - *(f32 *)(m + 0x10), t.y - *(f32 *)(m + 0x14)), a)) * 1.8f;
        off.z = 0;
        vec_add_ab(&pts[i], &base, &off);
    }
    s.m[0] = pts[0];
    s.m[2] = pts[1];
    s.m[3] = pts[2];
    s.m[1] = pts[3];
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L21_003AFCF0 */
