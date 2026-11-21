/* functional: low. Does not compile in the file context (owner declares func_L01_003D1E30(void) but retail takes two arguments); fix the declaration and its caller func_L01_003D18C0. */
#include "common.h"
/* localdecomp:start func_L01_003D1E30 */
#include "vu0.h"
typedef struct { u8 pad[0x25C4]; s32 state; } Hero_003D1E30;
extern Hero_003D1E30 D_001A4BE0;
extern vu0_v4 D_L01_001E2A40;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E0100;
extern f32 D_L01_001DF2F8, D_L01_001DF300, D_L01_001DF304, D_L01_001DF308;
extern f32 D_L01_001DF30C, D_L01_001DF310, D_L01_001DF314, D_L01_001DF318, D_L01_001DF31C;
__asm__(".extern D_L01_001DF2F8, 4");
__asm__(".extern D_L01_001DF300, 4");
__asm__(".extern D_L01_001DF304, 4");
__asm__(".extern D_L01_001DF308, 4");
__asm__(".extern D_L01_001DF30C, 4");
__asm__(".extern D_L01_001DF310, 4");
__asm__(".extern D_L01_001DF314, 4");
__asm__(".extern D_L01_001DF318, 4");
__asm__(".extern D_L01_001DF31C, 4");
void func_L01_003D1E30(u8 *m, u8 *d) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_003D1900(u8 *, u8 *, void *, f32);
    vu0_v4 p, v;
    u8 *prev = 0;
    u8 *node = *(u8 **)(d + 0x13C);
    f32 t, base, end, speed, radius, f;
    s32 now;
    while (node) {
        if (*(f32 *)(node + 8) > D_L01_001E2A40.z) {
            if (prev) *(u8 **)(prev + 0x28) = *(u8 **)(node + 0x28);
            else *(u8 **)(d + 0x13C) = *(u8 **)(node + 0x28);
            *(u8 **)(node + 0x28) = *(u8 **)(d + 0x138);
            *(u8 **)(d + 0x138) = node;
            if (prev) node = *(u8 **)(prev + 0x28);
            else node = *(u8 **)(d + 0x13C);
        } else {
            *(f32 *)(node + 0x18) = func_0038DAB8(*(f32 *)(node + 0x18), *(f32 *)(node + 0x1C));
            if (*(f32 *)(node + 0x14) < 1.0f) {
                *(f32 *)(node + 0x14) += D_L01_001DF2F8;
                if (*(f32 *)(node + 0x14) > 1.0f) *(f32 *)(node + 0x14) = 1.0f;
            }
            prev = node;
            node = *(u8 **)(node + 0x28);
        }
    }
    if (D_001A4BE0.state != 0xB0) return;
    if (D_L01_001DFB40 < *(s32 *)(d + 0x1C)) return;
    now = D_L01_001DFB40;
    t = *(f32 *)(d + 0x30);
    if (t > D_L01_001DF310) return;
    if (t < D_L01_001DF30C) {
        t /= D_L01_001DF30C;
        base = D_L01_001DF300;
        end = D_L01_001DF304;
    } else {
        t = (t - D_L01_001DF30C) / (D_L01_001DF310 - D_L01_001DF30C);
        base = D_L01_001DF304;
        end = D_L01_001DF308;
    }
    f = base + (end - base) * t;
    *(s32 *)(d + 0x1C) = now + (((s32)f * 5 + 2) / 6);
    speed = D_L01_001DF318 + (D_L01_001DF31C - D_L01_001DF318) * t;
    if (*(f32 *)(d + 0x20) < 40.0f) {
        *(f32 *)(d + 0x20) += 0.5f;
        if (*(f32 *)(d + 0x20) > 40.0f) *(f32 *)(d + 0x20) = 40.0f;
    }
    f = func_003824E0(0.0f, 1.0f);
    radius = (1.0f - f*f*f)*10.0f + 5.0f;
    p.x = func_0038D098(func_00382538()) * radius;
    p.y = func_0038D0B0(func_00382538()) * radius;
    p.z = 0.0f;
    vec_add_ba(&p, &p, &D_L01_001E2A40);
    p.z -= func_003824E0(*(f32 *)(d + 0x20), *(f32 *)(d + 0x20) + 8.0f);
    func_0038CE20(&v, m + 0xC0, 8.0f);
    vec_add_ab(&p, &v, &p);
    if (*(f32 *)((*(s32 *)(d + 4) << 7) + D_L01_001E0100 + 0x38) + D_L01_001DF314 < p.z)
        func_L01_003D1900(m, d, &p, speed);
}
/* localdecomp:end func_L01_003D1E30 */
