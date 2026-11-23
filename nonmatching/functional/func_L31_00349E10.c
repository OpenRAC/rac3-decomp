/* functional: high. 165 words differ (scheduling/regalloc; the vu0 flag is needed for the pv_add helper, the file line lacks it). Constants (2*pi, 128.0, 1/256), gp globals and the s16/s32 conversions re-read against the asm. */
/* localdecomp:start func_L31_00349E10 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) PV4;
static void pv_add(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *p = (f32 *)a, *q = (f32 *)b;
    f32 x = p[0] + q[0], y = p[1] + q[1], z = p[2] + q[2];
    o[0] = x; o[1] = y; o[2] = z;
}
static void pv_sub(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *p = (f32 *)a, *q = (f32 *)b;
    f32 x = p[0] - q[0], y = p[1] - q[1], z = p[2] - q[2];
    o[0] = x; o[1] = y; o[2] = z;
}
__asm__(".extern D_L31_001DD0F8, 4");
__asm__(".extern D_L31_001DD0FC, 4");
__asm__(".extern D_L31_001DD100, 4");
__asm__(".extern D_L31_001DD104, 4");
__asm__(".extern D_L31_001DD108, 4");
__asm__(".extern D_L31_001DD10C, 4");
__asm__(".extern D_L31_001DD110, 4");
__asm__(".extern D_L31_001DD114, 4");
extern f32 D_L31_001DD0F8;
extern f32 D_L31_001DD0FC;
extern f32 D_L31_001DD100;
extern f32 D_L31_001DD104;
extern f32 D_L31_001DD108;
extern f32 D_L31_001DD10C;
extern s32 D_L31_001DD110;
extern s32 D_L31_001DD114;
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern void func_L31_00349D18(void *, f32 *, f32 *, f32);
void func_L31_00349E10(u8 *e, u8 *r) {
    u8 *owner;
    u8 *st;
    PV4 s0, s10, s20;
    f32 ang, rnd, scale, k, t, lo, hi;

    if (r == 0) {
        return;
    }
    owner = *(u8 **)r;
    if (owner == 0) {
        return;
    }
    st = *(u8 **)(owner + 0x68);
    if (*(s32 *)(r + 4) == 0) {
        return;
    }
    if (*(u16 *)(r + 0xA) & 1) {
        ang = func_003824E0(0.0f, 6.2831855f);
        k = func_0038DB48(ang);
        rnd = func_003824E0(0.0f, 1.0f);
        scale = D_L31_001DD0F8 * rnd;
        *(PV4 *)(e + 0x10) = *(PV4 *)(owner + 0x10);
        s0.x = func_0038D098(k) * scale;
        s0.y = 0.0f;
        s0.z = func_0038D0B0(k) * scale;
        pv_add(e + 0x10, e + 0x10, &s0);
        func_L31_00349D18(owner, &s10.x, &s20.x, *(f32 *)(st + 0x54));
        t = D_L31_001DD108 * scale / D_L31_001DD0F8;
        *(f32 *)(r + 0x10) = (*(f32 *)(owner + 0x10) - s10.x) * D_L31_001DD104;
        rnd = scale / D_L31_001DD0F8;
        k = 1.0f - t;
        *(f32 *)(r + 0x14) = (*(f32 *)(owner + 0x18) - s10.z) * D_L31_001DD104;
        *(s16 *)(r + 8) = (s16)(s32)((f32) * (s16 *)(r + 8) * k);
        *(s16 *)(e + 0xA) = (s16)(s32)((f32) * (s16 *)(e + 0xA) * k);
        *(s32 *)(e + 4) = func_0038DBD8(D_L31_001DD110, D_L31_001DD114, sqrt_asm(rnd));
    }
    *(f32 *)(e + 0x10) = *(f32 *)(e + 0x10) + *(f32 *)(r + 0x10);
    *(f32 *)(e + 0x18) = *(f32 *)(e + 0x18) + *(f32 *)(r + 0x14);
    *(s32 *)(e + 4) = (*(s32 *)(e + 4) & 0xFFFFFF) | ((s32)((f32) * (s16 *)(e + 0xA) * 128.0f / (f32) * (s16 *)(r + 8)) << 24);
    hi = (f32)(*(u16 *)(r + 0xE) >> 8);
    lo = (f32)(*(u16 *)(r + 0xE) & 0xFF);
    t = lo + D_L31_001DD10C * (f32) * (s16 *)(r + 8) * hi * 0.00390625f;
    e[8] = (u8)(s32)func_003C4088(lo, t, func_L03_0034B148(*(s16 *)(e + 0xA), *(s16 *)(r + 8), 0.0f));
    *(f32 *)(e + 0xC) = func_003C4088(D_L31_001DD100, D_L31_001DD0FC, (f32) * (s16 *)(e + 0xA) / (f32) * (s16 *)(r + 8));
}
/* localdecomp:end func_L31_00349E10 */
