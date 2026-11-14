#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003DB1C0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DB1C0;

struct R_3DB1C0 {
    u8 pad[0x24];
    f32 f24;
};

typedef struct S_3DB1C0 {
    u8 pad0[0x10];
    u128_t v10;
    u8 pad1[4];
    struct R_3DB1C0 *p24;
    u8 pad2[4];
    f32 f2c;
    u8 f30;
    u8 f31;
    u16 f32h;
    u16 f34;
    u8 pad3[2];
    unsigned long f38;
    u8 pad4[0xB0];
    u128_t vF0;
} S_3DB1C0;

extern S_3DB1C0 *func_003C24B0(s32, s32);
extern s32 func_00382468(s32);
extern void func_0038D328(void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern void func_003C7C38(void *);

S_3DB1C0 *func_L05_003DB1C0(S_3DB1C0 *src, s32 arg1, s32 arg2) {
    S_3DB1C0 *s;
    V4_3DB1C0 t0, t1, t2;
    unsigned long v;
    char buf[0x10];

    s = func_003C24B0(arg1, 0x80);
    if (s != 0) {
        s->f32h = 0xFF;
        s->f31 = 1;
        s->f2c = s->f2c * (src->f2c / src->p24->f24);
        s->v10 = src->v10;
        if (func_00382468(2)) {
            func_0038D328(&t0, &src->vF0);
            func_0038D890(&t1, &t1, &t0, 3.1415927f);
            func_0038D890(&t2, &t2, &t0, 3.1415927f);
            func_003C48A8(&t0, &s->vF0);
        } else {
            s->vF0 = src->vF0;
        }
        v = src->f38;
        s->f30 = arg2;
        s->f34 = 0;
        s->f38 = v;
        func_003C7C38(s);
        return s;
    }
    return 0;
}
/* localdecomp:end func_L05_003DB1C0 */

/* localdecomp:start func_L05_003DB2D0 */
extern f32 D_L05_001DF150;
__asm__(".extern D_L05_001DF150, 4");
extern f32 D_L05_001DF154;
__asm__(".extern D_L05_001DF154, 4");
extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, f32, s32, s32, f32, f32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L05_003DB2D0(u8 *o) {
    vu0_v4 c;
    vu0_v4 b;
    vu0_v4 d;
    vu0_v4 *cp;
    u8 *r;
    s32 i;

    cp = &c;
    c = *(vu0_v4 *)(o + 0xC0);
    func_0038CE20(&c, &c, D_L05_001DF150 * 0.020000001f);
    func_003A52A0(0, 0, o);
    func_L01_00451FE0(o, 0x1FF, cp, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    r = (u8 *)func_L05_003DB1C0((S_3DB1C0 *)o, 0x1E42, 0);
    *(s32 *)(o + 0x98) = 0;
    o[0x31] = 0;
    *(u16 *)(o + 0x34) |= 1;
    if (r != 0) {
        *(s32 *)(r + 0x98) = *(s32 *)(*(u8 **)(r + 0x24) + 0x10);
    }
    *(vu0_q *)&b = 0;
    b.x = 1.0f;
    for (i = 0; i < 10; i++) {
        func_00382580(&c, 0.020000001f, 0.040000003f);
        func_0038CE20(&d, &b, 0.10000001f);
        vec_add_ab(&c, &d, &c);
        func_L02_003E2E38(o, D_L05_001D66B0, 0.0f, &c, func_00382498(3, 6), 0.0f, 3, 0, 1.5f, 20.0f, 1.0f);
    }
    func_L01_003303B8(o + 0x10, 0, 0, 0, 0, 2, 5, 0, D_L05_001DF154, 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0,
                      0x7F60A0FF, 0x280000FF, 0, 0);
    func_L01_00451E78(o, 1, 0.0f);
    func_003C2880(o);
}
/* localdecomp:end func_L05_003DB2D0 */

/* localdecomp:start func_L05_003DB580 */
s32 func_L01_00447490(s32, s32, s32);
void func_L05_003DB2D0(u8 *);

void func_L05_003DB580(s32 arg0) {
    if (func_L01_00447490(arg0, -1, 0) != 0) {
        func_L05_003DB2D0((u8 *)arg0);
    }
}
/* localdecomp:end func_L05_003DB580 */

/* localdecomp:start func_L05_003DB5C0 */
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, f32, s32, s32, f32, f32, f32);

void func_L05_003DB5C0(u8 *moby) {
    vu0_v4 offset, axis, random, scaled;
    s32 *state = *(s32 **)(moby + 0x68);
    s32 i = 0;
    f32 angle = func_00382538();
    f32 radius = func_003824E0(0.0f, 0.5f);
    qzero(&offset);
    offset.x = func_0038D098(angle) * radius;
    offset.z = func_0038D0B0(angle) * radius;
    *(vu0_q *)&axis = 0;
    axis.x = 1.0f;
    do {
        func_00382580(&random, 0.020000001f, 0.040000003f);
        func_0038CE20(&scaled, &axis, 0.10000001f);
        vec_add_ab(&random, &scaled, &random);
        func_L02_003E2E38(moby, &offset, 0.0f, &random, func_00382498(3, 6), 0.0f, i & 1, 0, 1.5f, 15.0f, 1.0f);
        i++;
    } while (i < 2);
    state[0] = (func_00382498(90, 180) * 5 + 2) / 6;
}
/* localdecomp:end func_L05_003DB5C0 */
