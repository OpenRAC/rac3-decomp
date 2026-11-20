/* functional: high. Hand-written from PAL assembly. Called as a draw callback with the object in a0 (registered via func_L01_00404808), so it takes the object pointer although the unit declares it void. Needs -mvu0-use-vf0-vf2 for the vec helpers under the file flags. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L12_003D73C0 */
static void v4_sub(void *d, void *a, void *b) {
    f32 *dd = (f32 *)d, *aa = (f32 *)a, *bb = (f32 *)b;
    dd[0] = aa[0] - bb[0];
    dd[1] = aa[1] - bb[1];
    dd[2] = aa[2] - bb[2];
}
static void v4_add(void *d, void *a, void *b) {
    f32 *dd = (f32 *)d, *aa = (f32 *)a, *bb = (f32 *)b;
    dd[0] = aa[0] + bb[0];
    dd[1] = aa[1] + bb[1];
    dd[2] = aa[2] + bb[2];
}
typedef struct {
    vu0_v4 q[4];
    s32 k[4];
    f32 e0[4];
    f32 f0[4];
    u8 pad[0x20];
} S_003D73C0;

extern s32 D_L12_001DF840;
extern u8 D_L12_001DF010_sda[];
extern u8 D_L12_001DF011[];
extern u8 D_L12_001DF012[];
extern vu0_v4 D_L12_001E2700;
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L12_003D73C0(u8 *self) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    S_003D73C0 obj;
    s32 idx;
    u32 r;
    u32 g;
    u32 bl;
    u32 col;
    f32 step;
    f32 *p;
    s32 i;

    idx = *(s32 *)(*(u8 **)(self + 0x68) + 0x44);
    bl = D_L12_001DF010_sda[idx * 3];
    g = D_L12_001DF011[idx * 3];
    r = D_L12_001DF012[idx * 3];
    func_003D93B0(&obj, 0x17, 0, 0x80);
    col = (r << 16) | (g << 8) | 0x40000000 | bl;
    obj.k[0] = col;
    obj.k[1] = col;
    obj.k[2] = col;
    obj.k[3] = col;
    obj.e0[0] = 0.0f;
    obj.e0[1] = 0.0f;
    obj.e0[2] = 0.0f;
    obj.e0[3] = 1.0f;
    obj.f0[0] = 5.0f;
    obj.f0[1] = 0.0f;
    obj.f0[2] = 5.0f;
    obj.f0[3] = 1.0f;
    step = (f32)(D_L12_001DF840 % 10) / 10.0f;
    p = &obj.e0[0];
    for (i = 3; i >= 0; i--) {
        *p = *p - step;
        if (*p <= 7.0f) {
            *p = *p + 7.0f;
        }
        p += 2;
    }
    a = *(vu0_v4 *)(self + 0x10);
    v4_sub(&b, self + 0x10, &D_L12_001E2700);
    a.z = a.z + 500.0f;
    v4_sub(&c, &a, self + 0x10);
    func_0038CE90(&d, &b, &c);
    func_0038CF68(&d, &d, 2.0f);
    v4_add(&obj.q[0], self + 0x10, &d);
    v4_sub(&obj.q[1], self + 0x10, &d);
    v4_add(&obj.q[2], &a, &d);
    v4_sub(&obj.q[3], &a, &d);
    func_003D2DA0(&obj, 0, 0);

    func_003D93B0(&obj, 0xE, 1, 0x80);
    i = bl + 0x20;
    if (i >= 0x100) {
        i = 0xFF;
    }
    col = (r << 16) | (g << 8) | 0x40000000 | i;
    obj.k[0] = col;
    obj.k[1] = col;
    obj.k[2] = col;
    obj.k[3] = col;
    obj.e0[0] = 0.0f;
    obj.e0[1] = 0.0f;
    obj.e0[2] = 0.0f;
    obj.e0[3] = 1.0f;
    obj.f0[0] = 1.0f;
    obj.f0[1] = 0.0f;
    obj.f0[2] = 1.0f;
    obj.f0[3] = 1.0f;
    func_0038CF68(&d, &d, 6.0f);
    v4_add(&obj.q[0], self + 0x10, &d);
    v4_sub(&obj.q[1], self + 0x10, &d);
    v4_add(&obj.q[2], &a, &d);
    v4_sub(&obj.q[3], &a, &d);
    func_003D2DA0(&obj, 0, 0);
}
/* localdecomp:end func_L12_003D73C0 */
