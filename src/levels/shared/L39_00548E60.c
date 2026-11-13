#include "common.h"

/* localdecomp:start func_L39_00548E60 */
#include "vu0.h"
extern void func_L01_0040E020(void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005B4398(s32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, s32, void *, f32, u32, s32);

void func_L39_00548E60(u8 *self) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 vel;
    s32 i;
    s32 j;
    s32 k;
    s32 life;
    f32 size;

    if (self[0xBC] == 0) {
        return;
    }
    func_L01_0040E020(self + 0xBC);
    func_0038CE20(&pos, self + 0xD0, 0.1f);
    vec_add_ba(&pos, &pos, self + 0x10);
    func_0038CE20(&off, self + 0xC0, 0.275f);
    vec_add_ab(&pos, &pos, &off);
    func_0038CE20(&vel, self + 0xD0, 0.120000005f);
    for (i = 0; i < 4; i++) {
        u8 *p;
        k = func_L39_005B4398(0x10);
        if (func_L39_005B4398(2) != 0) {
            k = -k;
        }
        p = func_L01_004669B0(&pos, 0.04f, 1.0f, 0.9f, k, &vel, 52500.0f, 0x7F204080, 0);
        if (p != 0) {
            u8 *t = p + 0x20;
            *(s16 *)(p + 0xA) = 7;
            p[9] = ((*(s16 *)(self + 0x32) >> 5) << 4) + 4;
            *(s32 *)(t + 4) = 2;
            t[0xA] = 0x7F;
            t[0xB] = p[0xA];
        }
    }
    k = 0x10;
    size = 15750.001f;
    life = 2;
    for (j = 0; j < 3; j++) {
        u8 *p;
        p = func_L01_004669B0(&pos, 0.02f, 1.0f, 1.0f, k, &vel, size, 0x7FFFFFFF, 0);
        if (p != 0) {
            u8 *t = p + 0x20;
            p[9] = ((*(s16 *)(self + 0x32) >> 5) << 4) + 4;
            *(s16 *)(p + 0xA) = life;
            p[8] = func_L39_005B4398(0xFF);
            *(s32 *)(t + 4) = 2;
            t[0xA] = 0x7F;
            t[0xB] = p[0xA];
        }
        k = -k;
        life <<= 1;
        size -= 3150.0f;
    }
}
/* localdecomp:end func_L39_00548E60 */

/* localdecomp:start func_L39_005490D0 */
#include "vu0.h"

extern f32 D_L39_0024AFE0;
__asm__(".extern D_L39_0024AFE0, 4");
extern f32 D_L39_0024AFE4;
__asm__(".extern D_L39_0024AFE4, 4");
extern s32 D_L39_0024AFE8;
__asm__(".extern D_L39_0024AFE8, 4");
extern s32 D_L39_0024AFEC;
__asm__(".extern D_L39_0024AFEC, 4");
extern s32 D_L39_0024AFF0;
__asm__(".extern D_L39_0024AFF0, 4");
extern f32 D_L39_0024AFF4;
__asm__(".extern D_L39_0024AFF4, 4");
extern f32 D_L39_0024AFF8;
__asm__(".extern D_L39_0024AFF8, 4");
extern f32 D_L39_0024AFFC;
__asm__(".extern D_L39_0024AFFC, 4");
extern f32 D_L39_0024B000;
__asm__(".extern D_L39_0024B000, 4");
extern f32 D_L39_0024B004;
__asm__(".extern D_L39_0024B004, 4");
extern f32 D_L39_0024B008;
__asm__(".extern D_L39_0024B008, 4");

extern void func_0038D000(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_004660F8(void *, void *);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L39_005490D0(u8 *a0) {
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
    func_0038D000(&v20, &v20, a0 + 0xC0);
    ang = 0.0f;
    vec_add_ab(&v30, a0 + 0x10, &v20);
    a0[0xBC] = 5;
    func_0038D890(&v20, s + 0x380, s + 0x390, 0.34906584f);
    v10 = v20;
    for (i = 19; i >= 0; i--) {
        ang = func_0038DAB8(ang, func_L39_005B4410(0.0f, 0.62831855f));
        func_0038CE20(&v40, &v10, func_L39_005B4410(0.120000005f, 0.36f));
        p = func_L01_004660F8(&v30, &v40);
        if (p != 0) {
            c = (vu0_v4 *)(p + 0x30);
            func_0038CE20(&v40, &v10, 0.75f);
            vec_add_ab(p + 0x10, &v30, &v40);
            *(vu0_v4 *)(p + 0x20) = v30;
            c->w = 2.0f;
            *(f32 *)(p + 0x1C) = 0.05f;
            *(f32 *)(p + 0x2C) = 0.5f;
            *(s32 *)(p + 0x4) = col;
            *(s32 *)(p + 0xC) = col;
        }
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, s + 0x380, ang);
            func_0038D850(&v10, &v20, &q);
        }
    }
    func_0038D890(&v20, s + 0x380, s + 0x390, D_L39_0024AFE0 * 0.017453292f);
    ang = 0.0f;
    v10 = v20;
    qzero(&v60);
    if (*(s32 *)(s + 0x2D0) != 0) {
        func_0038CE20(&v60, s + 0x140, 1.7f);
    }
    for (i = 0; i < 20; i++) {
        ang = func_0038DAB8(ang, func_L39_005B4410(0.0f, 0.62831855f));
        func_0038CE20(&v40, &v10, func_L39_005B4410(D_L39_0024AFF8 * 0.020000001f, D_L39_0024AFFC * 0.020000001f));
        vec_add_ab(&v40, &v40, &v60);
        life = (D_L39_0024AFF0 * 5 + 2) / 6;
        spin = func_L39_005B4468(1.0f, 2.0f);
        v50.x = v30.x + func_L39_005B4468(0.0f, D_L39_0024AFE4);
        v50.y = v30.y + func_L39_005B4468(0.0f, D_L39_0024AFE4);
        v50.z = v30.z + func_L39_005B4468(0.0f, D_L39_0024AFE4);
        f = func_L39_005B4410(D_L39_0024B000, D_L39_0024B004);
        vec_sub_ab(&v50, &v50, &v40);
        func_L01_0046A610(&v50, &v40, life, D_L39_0024AFE8, D_L39_0024AFEC, spin,
                          f * 210000.0f, D_L39_0024B008, D_L39_0024AFF4, 0.0f, 0.0f);
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, s + 0x380, ang);
            func_0038D850(&v10, &v20, &q);
        }
    }
}
/* localdecomp:end func_L39_005490D0 */

INCLUDE_ASM("asm/levels", func_L39_00549510);
