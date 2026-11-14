#include "common.h"

/* NTSC-U counterpart of func_L39_00545740 (src/levels/shared/L39_00545498.c): 12 -> 15 */
/* localdecomp:start func_L39_00544EB0 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

__asm__(".extern D_L39_0024AFE8_00544EB0, 4");
extern f32 D_L39_0024AFE8_00544EB0;
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388E78(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern u8 *func_L39_00528810(s32 a0, void *a1, void *a2, s32 a3, s32 a4, f32 f0, f32 f1, f32 f2, f32 f3);
extern s32 func_L39_0066B708(void *, s32, void *, s32, void *);

void func_L39_00544EB0(u8 *a0, u8 *a1, u32 a2) {
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
    yaw = func_00388A28(d.x, d.y);
    pitch = -func_00388A28(func_003887A0(&d), d.z);
    *(u128_t *)&d = *(u128_t *)(a0 + 0xC0);
    func_003886E8(&off, s + 0x290, 3.0f);
    vec_add_ab(&d, &d, &off);
    yaw = func_00388A28(d.x, d.y);
    pitch = -func_00388A28(func_003887A0(&d), d.z);
    func_003BDA38(a0, s[0x380], &pos);
    func_00388E78(m, rot);
    func_003888F0(&o, s + 0x290, m);
    r = func_L39_00528810((s32)a0, &pos, a1, a2, 0, yaw, pitch, o.x, D_L39_0024AFE8_00544EB0);
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
            *(s32 *)(*(u8 **)(r + 0x68) + 0x60) = func_L39_0066B708(p, 8, r, 0, a1);
        }
        *(s16 *)(s + 0x37E) = 0xF;
    }
    s[0x380] ^= 1;
}
/* localdecomp:end func_L39_00544EB0 */
