#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L30_00341D88.c, which this file was cut from */
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L30_00342980(u8 *);
extern void func_L30_00342A08(u8 *);

/* localdecomp:start func_L30_00342980 */
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 D_L30_001DCE2C;
__asm__(".extern D_L30_001DCE2C, 4");
extern u8 D_L30_001E9028[];

s32 func_L30_00342980(u8 *a0) {
    u128_t t = *(u128_t *)(a0 + 0x10);
    u8 *p = *(u8 **)(a0 + 0x68);
    *(f32 *)((u8 *)&t + 8) += *(f32 *)(p + 0x74);
    if (func_L01_003FB640(&t, 2, a0, *(f32 *)(p + 0x70) + D_L30_001DCE2C) != 0) {
        if (*(f32 *)D_L30_001E9028 <= *(f32 *)((u8 *)&t + 8)) {
            *(f32 *)(a0 + 0x18) = *(f32 *)D_L30_001E9028;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L30_00342980 */

/* localdecomp:start func_L30_00342A08 */
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern void func_L01_00470668(void *, void *, s32, f32);
__asm__(".extern D_L30_001DCE44, 4");
extern f32 D_L30_001DCE44;

typedef struct {
    f32 x, y, z, w;
} V_00342A08;

void func_L30_00342A08(u8 *o) {
    V_00342A08 dir __attribute__((aligned(16)));
    V_00342A08 vel __attribute__((aligned(16)));
    V_00342A08 pos __attribute__((aligned(16)));
    s32 i;
    s32 n;
    u8 *p;
    f32 a;

    *(u128_t *)&dir = 0;
    *(u128_t *)&vel = 0;
    dir.w = 1.0f;
    vel.w = 1.0f;
    for (i = 0; i < 48; i++) {
        a = (f32)i / 48.0f * 6.2831855f;
        dir.x = D_L30_001DCE44 * 0.020000001f * func_0038D0B0(a);
        dir.y = D_L30_001DCE44 * 0.020000001f * func_0038D098(a);
        n = func_00382498(0, 2) - 1;
        p = func_L01_004669B0(o + 0x10, 0.1f, 1.0f, 1.0f, func_003824E0(0.25f, 1.0f) * 210000.0f, n, &dir, 0x207F7F7F, 0);
        if (p != 0) {
            u8 *q = p + 0x20;
            *(s16 *)(p + 0xA) = 50;
            *(s32 *)(q + 4) = 2;
            q[0xA] = 0x20;
            q[0xB] = p[0xA];
        }
        if (func_00382468(9) != 0) {
            continue;
        }
        *(u128_t *)&pos = *(u128_t *)(o + 0x10);
        vel.x = dir.x * func_003824E0(1.0f, 3.0f);
        vel.y = dir.y * func_003824E0(1.0f, 3.0f);
        vel.z = func_003824E0(1.0f, 4.0f) * 0.020000001f;
        pos.x += func_L01_00443A18(0.0f, 0.4f);
        pos.y += func_L01_00443A18(0.0f, 0.4f);
        func_L01_00470668(&pos, &vel, (func_00382498(20, 30) * 5 + 2) / 6, 0.0f);
    }
}
/* localdecomp:end func_L30_00342A08 */

/* localdecomp:start func_L30_00342C80 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

u8 *func_L30_00342C80(void *pos, void *vel, f32 f12, f32 f13) {
    u8 *s0 = func_003C24B0(0x1398, 0x80);
    u8 *vars;

    if (s0 == 0) {
        return 0;
    }
    *(u128_t *)(s0 + 0x10) = *(u128_t *)pos;
    s0[0x30] = 0xFF;
    *(u16 *)(s0 + 0x32) = 0x40;
    vars = *(u8 **)(s0 + 0x68);
    *(f32 *)(s0 + 0x2C) = f12 * *(f32 *)(*(u8 **)(s0 + 0x24) + 0x24);
    *(u128_t *)(vars + 0x60) = *(u128_t *)vel;
    *(f32 *)(vars + 0x7C) = f13;
    *(s32 *)(vars + 0x84) = 3;
    func_L01_004450F0(s0, 0, -1);
    return s0;
}
/* localdecomp:end func_L30_00342C80 */
