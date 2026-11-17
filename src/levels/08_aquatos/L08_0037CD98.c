#include "common.h"

/* localdecomp:start func_L08_0037CD98 */
typedef int Quad_0037CD98 __attribute__((mode(TI)));
typedef struct G_0037CD98 {
    u8 pad00[0x25C0];
    u8 *x25C0;
} G_0037CD98;

extern void func_L01_004450F0(void *, s32, s32);
extern void func_L08_0037CE30(void *);
extern G_0037CD98 D_001A4BE0;

void func_L08_0037CD98(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);

    switch (self[0x20]) {
    case 0:
        func_L01_004450F0(self, 1, -1);
        self[0x30] = 0xFF;
        *(Quad_0037CD98 *)(self + 0xC0) = *(Quad_0037CD98 *)(D_001A4BE0.x25C0 + 0xC0);
        *(Quad_0037CD98 *)(self + 0xD0) = *(Quad_0037CD98 *)(D_001A4BE0.x25C0 + 0xD0);
        *(Quad_0037CD98 *)(self + 0xE0) = *(Quad_0037CD98 *)(D_001A4BE0.x25C0 + 0xE0);
        break;
    case 1:
        if (*(s32 *)(s + 0x24) != 0) {
            func_L08_0037CE30(self);
        }
        break;
    }
}
/* localdecomp:end func_L08_0037CD98 */

/* localdecomp:start func_L08_0037CE30 */
#include "vu0.h"

typedef struct V_0037CE30 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0037CE30;

extern u8 *D_L08_0021EBA0[];

extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern void func_0038D000(void *, void *, void *);
extern u8 *func_L01_0046C470(void *, void *, u32, s32, f32, s32, s32, s32, s32);

void func_L08_0037CE30(void *ov) {
    u8 *o = ov;
    V_0037CE30 a;
    V_0037CE30 b;
    u8 *p;
    u8 *q;
    f32 ang;
    f32 s;
    f32 sz;
    s32 life;
    s32 vis;

    p = *(u8 **)(o + 0x68);
    if (func_00382468(*(s32 *)(p + 0x20)) != 0) {
        return;
    }
    qzero(&b);
    b.z = func_003824E0(*(f32 *)p, *(f32 *)(p + 4)) * 0.020000001f;
    func_0038D000(&b, &b, o + 0xC0);
    ang = func_00382538();
    s = func_003824E0(*(f32 *)(p + 0x18), *(f32 *)(p + 0x1C));
    a.x = func_0038D098(ang) * s;
    a.y = func_0038D0B0(ang) * s;
    a.z = 0.0f;
    func_0038D000(&a, &a, o + 0xC0);
    vec_add_ba(&a, &a, o + 0x10);
    life = ((func_00382498(*(s32 *)(p + 0x10), *(s32 *)(p + 0x14)) * 5) + 2) / 6;
    sz = func_003824E0(*(f32 *)(p + 8), *(f32 *)(p + 0xC));
    q = func_L01_0046C470(&a, &b, 0x4F808080, life, sz, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
    if (q != 0) {
        q[2] = *D_L08_0021EBA0[0];
        q[9] = ((*(s32 *)(p + 0x28) >> 5) << 4) + 4;
    }
}
/* localdecomp:end func_L08_0037CE30 */
