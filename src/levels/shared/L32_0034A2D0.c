#include "common.h"

/* localdecomp:start func_L32_0034A2D0 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern s32 D_L32_001DD018;
extern s32 D_L32_001DD01C;
extern f32 D_L32_001DD020;
extern s32 D_L32_001DD024;
extern f32 D_L32_001DD028;
extern f32 D_L32_001DD02C;
extern f32 D_L32_001DD030;
extern f32 D_L32_001DD034;
extern f32 D_L32_001DD088;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(Vec4 *, Vec4 *, f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern void func_L01_004713C8(Vec4 *, Vec4 *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

void func_L32_0034A2D0(u8 *m) {
    Vec4 v;
    Vec4 w;
    u8 *pv;
    s32 c;
    s32 r;

    pv = *(u8 **)(m + 104);
    *(f32 *)(pv + 28) += D_L32_001DD028;
    while (*(f32 *)(pv + 28) > 1.0f) {
        *(f32 *)(pv + 28) -= 1.0f;
        v.q = *(u128_t *)(m + 16);
        v.f[0] += func_003824E0(-D_L32_001DD088, 0.0f);
        v.f[2] += func_003824E0(-D_L32_001DD02C, D_L32_001DD02C);
        w.q = *(u128_t *)pv;
        func_0038CE20(&w, &w, D_L32_001DD034);
        c = func_L30_0034DBA0(D_L32_001DD018, D_L32_001DD01C);
        r = func_00382498(-4, 4);
        func_L01_004713C8(&v, &w, D_L32_001DD024, D_L32_001DD030, c, r, 128, 0, 0.0f, func_003824E0(-D_L32_001DD020, D_L32_001DD020), 0);
    }
}
/* localdecomp:end func_L32_0034A2D0 */

/* localdecomp:start func_L32_0034A428 */
void func_L32_0034A428(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 104);
    s32 i;
    for (i = 2; i >= 0; i--) {
        p[4 + i] = 0;
    }
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
}
/* localdecomp:end func_L32_0034A428 */

/* localdecomp:start func_L32_0034A460 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x20];
    s32 flags;
    u8 pad24[0xC];
} S_0034A460;
typedef struct { u8 pad[0x25C0]; void *f25C0; } S_1A4BE0_0034A460;
extern S_1A4BE0_0034A460 D_001A4BE0;
extern f32 D_L32_001DD040;
/* the loop's three limits, reached through $gp (addiu $a3, $gp, 0x7E8): the default assembler
 * only does that for an extern it knows to be 8 bytes or less */
__asm__(".extern D_L32_001DD098, 8");
extern f32 D_L32_001DD098[] __attribute__((section(".sdata")));
extern Vec4 D_L32_001E99A0;
extern void func_0038CF68(Vec4 *, Vec4 *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
s32 func_L32_0034A460(void *arg) {
    u8 *a0 = arg;
    u8 *s = *(u8 **)(a0 + 0x68);
    Vec4 p0;
    Vec4 p1;
    Vec4 dir;
    S_0034A460 info;
    f32 *v;
    f32 *lim;
    f32 step;
    s32 i;

    qzero(&dir);
    dir.f[2] = *(f32 *)(s + 8);
    dir.f[0] = *(f32 *)(s + 0);
    func_0038CF68(&dir, &dir, 1.0f);
    func_L01_00446760(&info, D_001A4BE0.f25C0, 0x10000, &dir, 1.0f);
    info.flags |= 1;
    p1.q = p0.q = *(u128_t *)(a0 + 0x10);
    p1.f[2] += *(f32 *)(s + 8);
    p1.f[0] += *(f32 *)(s + 0);
    step = D_L32_001DD040;
    v = (f32 *)(s + 0x10);
    lim = D_L32_001DD098;
    for (i = 2; i >= 0; i--) {
        f32 t = *v + step;
        f32 l = *lim;
        f32 r;
        if (l > t) {
            r = t;
        } else {
            r = l;
        }
        *v = r;
        v++;
        lim++;
    }
    if (func_003D3CB0(&p0, &p1, 0x10, D_001A4BE0.f25C0, &info) != 0) {
        *(u128_t *)(a0 + 0x10) = D_L32_001E99A0.q;
        return 1;
    }
    *(u128_t *)(a0 + 0x10) = p1.q;
    return 0;
}
/* localdecomp:end func_L32_0034A460 */
