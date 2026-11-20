#include "common.h"

/* localdecomp:start func_L39_00545740 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

__asm__(".extern D_L39_0024AED8, 4");
extern f32 D_L39_0024AED8;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern u8 *func_L39_00528D28(s32 a0, void *a1, void *a2, s32 a3, s32 a4, f32 f0, f32 f1, f32 f2, f32 f3);
extern s32 func_L39_0066E010(void *, s32, void *, s32, void *);

void func_L39_00545740(u8 *a0, u8 *a1, u32 a2) {
    vu0_v4 pos;
    vu0_v4 d = {0.0f, 0.0f, 0.0f, 0.0f};
    vu0_v4 off;
    f32 m[16] __attribute__((aligned(16)));
    vu0_v4 o;
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *r;
    u8 *g;
    s32 *p;
    u8 *rot;
    f32 yaw;
    f32 pitch;

    if (*(s32 *)(*(u8 **)(s + 0x384) + 0x2D8) == 0) {
        return;
    }
    vec_sub_ba(&d, a1, a0 + 0x10);
    rot = a0 + 0xC0;
    yaw = func_0038D160(d.x, d.y);
    pitch = -func_0038D160(func_0038CED8(&d), d.z);
    *(u128_t *)&d = *(u128_t *)(a0 + 0xC0);
    func_0038CE20(&off, s + 0x290, 3.0f);
    vec_add_ab(&d, &d, &off);
    yaw = func_0038D160(d.x, d.y);
    pitch = -func_0038D160(func_0038CED8(&d), d.z);
    func_003C2F58(a0, s[0x380], &pos);
    func_0038D5B0(m, rot);
    func_0038D028(&o, s + 0x290, m);
    r = func_L39_00528D28((s32)a0, &pos, a1, a2, 0, yaw, pitch, o.x, D_L39_0024AED8);
    if (r == 0) {
        return;
    }
    *(s32 *)(r + 0x90) = **(s32 **)(*(u8 **)(s + 0x384) + 0x2D8);
    if (a2 == 0xFFFFFFFF) {
        g = *(u8 **)(s + 0x384);
        p = *(s32 **)(g + 0x2D8);
        if (p == 0) {
            p = *(s32 **)(g + 0x2DC);
        }
        if (p != 0) {
            *(s32 *)(*(u8 **)(r + 0x68) + 0x60) = func_L39_0066E010(p, 8, r, 0, a1);
        }
        *(s16 *)(s + 0x37E) = 0xC;
    }
    s[0x380] ^= 1;
}
/* localdecomp:end func_L39_00545740 */

/* localdecomp:start func_L39_00545918 */
#include "vu0.h"

extern void func_0038CE20(void *, void *, f32);
extern u8 *D_001D5A54_sda;
extern u8 *D_001D5F30_sda;
extern unsigned int D_L39_0024AEB8_00545918;
extern u8 D_L39_0024DE80_00545918[];
extern void func_L01_003F6F20_00545918(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern int func_L01_003F1F20_00545918(unsigned int, int);
extern s32 func_0038CB00(s16 *);
extern void func_L39_00545740_00545918(u8 *a0, u8 *a1, u32 a2);

void func_L39_00545918(u8 *a0) {
    vu0_v4 v;
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *g = D_001D5A54_sda;
    u8 *base = D_L39_0024DE80_00545918;
    s32 idx = 0;
    u8 *p;

    if (*(u8 **)(s + 0x384) != 0 && (p = *(u8 **)(*(u8 **)(s + 0x384) + 0x2D8)) != 0) {
        g = *(u8 **)(p + 0x2534);
        base = *(u8 **)(p + 0x2530);
        idx = p[0x24C9];
    }
    *(s32 *)(a0 + 0x98) = 0;
    func_0038CE20(&v, base + 0x380, 250.0f);
    vec_add_ab(&v, &v, a0 + 0x10);
    func_L01_003F6F20_00545918(idx, a0, 0xFF0FFF0F, &v, 0x23, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
    if (*(s32 *)(s + 0x3D4) > 0) {
        if (++*(s32 *)(s + 0x3E4) > 10) {
            *(s32 *)(s + 0x3E4) = 10;
        }
    } else {
        *(s32 *)(s + 0x3E4) = 0;
    }
    if ((*(s32 *)(g + 0x1A0) & 0x28) && *(u8 **)(s + 0x384) != 0
        && *(u8 **)(*(u8 **)(s + 0x384) + 0x2D8) != 0 && *(s16 *)(*(u8 **)(*(u8 **)(s + 0x384) + 0x2D8) + 0x320) == 0
        && *(s16 *)(s + 0x37E) == 0 && *(s32 *)(s + 0x3D4) > 0 && *(s32 *)(s + 0x3E4) >= 3) {
        if (*(s8 *)(D_001D5F30_sda + 0x19B) == 0) {
            *(s32 *)(s + 0x3D4) -= 1;
        }
        *(s32 *)(s + 0x3D8) = 0x15;
        if (*(u8 **)(s + 0x384) != 0 && (p = *(u8 **)(*(u8 **)(s + 0x384) + 0x2D8)) != 0 && p[0x1A14] != 0) {
            func_L01_003F1F20_00545918(D_L39_0024AEB8_00545918, *(s32 *)(p + 0x2534));
        }
        func_L39_00545740_00545918(a0, (u8 *)&v, 0xFFFFFFFF);
    }
    func_0038CB00((s16 *)(s + 0x37E));
    if (--*(s32 *)(s + 0x3D8) <= 0 && *(s32 *)(s + 0x3D4) < 8) {
        *(s32 *)(s + 0x3D8) = 0x15;
        *(s32 *)(s + 0x3D4) += 1;
    }
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
}
/* localdecomp:end func_L39_00545918 */
