#include "common.h"

/* NTSC-U counterpart of func_L39_005490D0 (src/levels/shared/L39_00548E60.c) */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L39_005487B8 */
#include "vu0.h"

extern f32 D_L39_0024B0F0;
__asm__(".extern D_L39_0024B0F0, 4");
extern f32 D_L39_0024B0F4;
__asm__(".extern D_L39_0024B0F4, 4");
extern s32 D_L39_0024B0F8;
__asm__(".extern D_L39_0024B0F8, 4");
extern s32 D_L39_0024B0FC;
__asm__(".extern D_L39_0024B0FC, 4");
extern s32 D_L39_0024B100;
__asm__(".extern D_L39_0024B100, 4");
extern f32 D_L39_0024B104;
__asm__(".extern D_L39_0024B104, 4");
extern f32 D_L39_0024B108;
__asm__(".extern D_L39_0024B108, 4");
extern f32 D_L39_0024B10C;
__asm__(".extern D_L39_0024B10C, 4");
extern f32 D_L39_0024B110;
__asm__(".extern D_L39_0024B110, 4");
extern f32 D_L39_0024B114;
__asm__(".extern D_L39_0024B114, 4");
extern f32 D_L39_0024B118;
__asm__(".extern D_L39_0024B118, 4");

extern void func_003888C8(void *, void *, void *);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_L01_00462B40(void *, void *);
extern void func_003BF2F8(void *, void *, f32);
extern void func_00389118(void *, void *, void *);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L39_005487B8(u8 *a0) {
    vu0_v4 q;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    u8 *s;
    u8 *p;
    s32 i;
    f32 ang;
    s32 life;
    s32 spin;
    f32 f;
    vu0_v4 *c;
    s32 col;

    s = *(u8 **)(*(u8 **)(a0 + 0x68) + 0x40);
    if (s == 0) {
        return;
    }
    *(vu0_q *)&v20 = 0;
    v20.x = 0.3f;
    v20.y = -1.0f;
    v20.w = 1.0f;
    col = 0x307F7F7F;
    func_003888C8(&v20, &v20, a0 + 0xC0);
    ang = 0.0f;
    vec_add_ab(&v30, a0 + 0x10, &v20);
    a0[0xBC] = 6;
    func_00389158(&v20, s + 0x380, s + 0x390, 0.34906584f);
    v10 = v20;
    for (i = 19; i >= 0; i--) {
        ang = func_00389380(ang, func_L39_005B2510(0.0f, 0.62831855f));
        func_003886E8(&v40, &v10, func_L39_005B2510(0.10000001f, 0.3f));
        p = func_L01_00462B40(&v30, &v40);
        if (p != 0) {
            c = (vu0_v4 *)(p + 0x30);
            func_003886E8(&v40, &v10, 0.75f);
            vec_add_ab(p + 0x10, &v30, &v40);
            *(vu0_v4 *)(p + 0x20) = v30;
            c->w = 2.0f;
            *(f32 *)(p + 0x1C) = 0.05f;
            *(f32 *)(p + 0x2C) = 0.5f;
            *(s32 *)(p + 0x4) = col;
            *(s32 *)(p + 0xC) = col;
        }
        if (fabs_asm(ang) > 1e-5f) {
            func_003BF2F8(&q, s + 0x380, ang);
            func_00389118(&v10, &v20, &q);
        }
    }
    func_00389158(&v20, s + 0x380, s + 0x390, D_L39_0024B0F0 * 0.017453292f);
    ang = 0.0f;
    v10 = v20;
    qzero(&v60);
    if (*(s32 *)(s + 0x2D0) != 0) {
        func_003886E8(&v60, s + 0x140, 1.7f);
    }
    for (i = 0; i < 20; i++) {
        ang = func_00389380(ang, func_L39_005B2510(0.0f, 0.62831855f));
        func_003886E8(&v40, &v10, func_L39_005B2510(D_L39_0024B108 * 0.0166666675f, D_L39_0024B10C * 0.0166666675f));
        vec_add_ab(&v40, &v40, &v60);
        life = D_L39_0024B100;
        spin = func_L39_005B2568(1.0f, 2.0f);
        v50.x = v30.x + func_L39_005B2568(0.0f, D_L39_0024B0F4);
        v50.y = v30.y + func_L39_005B2568(0.0f, D_L39_0024B0F4);
        v50.z = v30.z + func_L39_005B2568(0.0f, D_L39_0024B0F4);
        f = func_L39_005B2510(D_L39_0024B110, D_L39_0024B114);
        vec_sub_ab(&v50, &v50, &v40);
        func_L01_00466F98(&v50, &v40, life, D_L39_0024B0F8, D_L39_0024B0FC, spin,
                          f * 210000.0f, D_L39_0024B118, D_L39_0024B104, 0.0f, 0.0f);
        if (fabs_asm(ang) > 1e-5f) {
            func_003BF2F8(&q, s + 0x380, ang);
            func_00389118(&v10, &v20, &q);
        }
    }
}
/* localdecomp:end func_L39_005487B8 */
