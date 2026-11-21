/* functional: high. Near-miss draft; the only multiset difference is where the 0.02f constant is loaded (CSE'd into f20 here, reloaded in retail). */
/* localdecomp:start func_L01_005133E8 */
#include "vu0.h"
typedef struct { Vec4 row[4]; } Matrix_005133E8;
extern D_001A4BE0_t D_001A4BE0;
extern S_50D8F8 D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_001D5477 __attribute__((section(".data")));
extern f32 D_001DC080_sda;
__asm__(".extern D_001DC080_sda, 4");
extern f32 D_L01_001DC084 __attribute__((section(".data")));
extern f32 D_001A62A4[];
extern u8 D_L01_001DFB40[];
extern u8 D_L01_001E2A40[];
extern u8 D_L01_001EAA20[];
extern u128_t D_L01_001E2A50[];
void func_L01_005133E8(void) {
    extern s32 func_L01_004E9270(s32);
    extern void func_003C7C38(u8 *);
    extern void func_0038D570(void *, void *);
    extern s32 func_L01_00513EF0(void);
    extern void func_003C4138(f32 *, f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
    extern void func_0038D328(M_0050D430 *, u8 *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_003C48A8(void *, void *);
    extern void func_003C3FC0(void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
    extern void func_0038D590(void *, void *);
    Matrix_005133E8 matrix, rotation;
    Vec4 offset, point, delta;
    u8 *g = (u8 *)&D_001A4BE0;
    u8 *m = *(u8 **)(g + 0x1200);
    u8 *weapon;
    u8 *attachment;
    u8 *base;
    f32 speed, radius, height;
    if (m == 0) return;
    if (*(s16 *)(m + 0xAA) == 0x47) {
        if (g[0x121C] == 0 && m[0x20] == 0) {
            m[0x31] = 0;
            *(u16 *)(m + 0x34) |= 1;
        } else {
            m[0x31] = 1;
            *(u16 *)(m + 0x34) &= ~1;
        }
        return;
    }
    if (func_L01_004E9270(0)) {
        m[0x31] = 0;
        *(u16 *)(m + 0x34) |= 1;
        if (*(void (**)(u8 *))(m + 0x64)) (*(void (**)(u8 *))(m + 0x64))(m);
        func_003C7C38(m);
        return;
    }
    weapon = (u8 *)&D_L01_002C5600[D_001425C0[*(s32 *)(g + 0x1228)]];
    func_0038D570(&matrix, g + 0x1540);
    attachment = weapon + 0xA0;
    offset.q = *(u128_t *)attachment;
    offset.f[0] += *(f32 *)(g + 0x16B8);
    matrix.row[3].q = *(u128_t *)(g + 0x1570);
    matrix.row[3].f[3] = 1.0f;
    if (D_001D5477 != 0 && !func_L01_00513EF0()) offset.f[1] = -offset.f[1];
    {
        u8 *h = (u8 *)&D_001A4BE0;
        speed = D_001DC080_sda;
        if (*(f32 *)(h + 0x174) > 0.02f) speed = D_L01_001DC084;
    }
    speed *= 0.017453292f;
    speed *= 0.020000001f;
    func_003C4138(D_001A62A4, speed, 0.010053097f);
    base = (u8 *)D_001A62A4 - 0x16C4;
    *(f32 *)(base + 0x16C0) = func_0038DAB8(*(f32 *)(base + 0x16C0), *(f32 *)(base + 0x16C4));
    offset.f[2] += func_0038D0B0(*(f32 *)(base + 0x16C0)) * 0.02f;
    func_0038D028((V_0050D430 *)(m + 0x10), (V_0050D430 *)&offset, (M_0050D430 *)&matrix);
    if (!func_L01_00513EF0()) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)(m + 0x10))
            : "m"(*(vu0_v4 *)(m + 0x10)), "m"(*(vu0_v4 *)(base + 0x150))
            : "vf1", "vf2");
    }
    func_0038D328((M_0050D430 *)&rotation, attachment + 0x10);
    func_0038D5F0(m + 0xC0, &matrix, &rotation);
    func_003C48A8(m + 0xC0, m + 0xF0);
    func_003C3FC0((u8 *)D_001A62A4 - 0x1C4, m + 0xF0);
    m[0x31] = 1;
    *(u16 *)(m + 0x34) &= ~1;
    func_003C7C38(m);
    if (((D_L01_001DFB40[0] ^ 1) & 1) != 0) {
        f32 scale = 0.0009765625f;
        radius = *(f32 *)(m + 0xC) * scale;
        func_0038CE20(point.f, (f32 *)m, scale);
        func_0038CF68(delta.f, (f32 *)(m + 0xD0), radius * -1.2f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(*(vu0_v4 *)&delta)
            : "m"(*(vu0_v4 *)&delta), "m"(*(vu0_v4 *)&point)
            : "vf1", "vf2");
        if (func_003D3CB0(D_L01_001E2A40, &delta, 0, *(u8 **)(base + 0x25C0), 0)) {
            height = func_0038CF00(D_L01_001EAA20, &point);
            height = (*(f32 *)(base + 0x16B8) - radius) + height;
            *(f32 *)(base + 0x16BC) = height;
            if (height > 0.0f) *(f32 *)(base + 0x16BC) = 0.0f;
            else if (height < -1.5f) *(f32 *)(base + 0x16BC) = -1.5f;
        } else *(s32 *)(base + 0x16BC) = 0;
    }
    {
    u8 *tail = (u8 *)&D_001A4BE0;
    if (tail[0x25F0]) *(f32 *)(tail + 0x16BC) = -1.5f;
    func_003C41A0((f32 *)(tail + 0x16B8), (f32 *)(tail + 0x16B4), *(f32 *)(tail + 0x16BC), 0.006f, 0.006f, 0.10000001f);
    func_0038D590(tail + 0x6C0, &matrix);
    {
        u128_t a = *(u128_t *)&matrix;
        u128_t b = D_L01_001E2A50[0];
        *(u128_t *)(tail + 0x6F0) = a;
        *(u128_t *)(tail + 0x700) = b;
    }
    if (*(void (**)(u8 *))(m + 0x64)) (*(void (**)(u8 *))(m + 0x64))(m);
    }
}
/* localdecomp:end func_L01_005133E8 */
