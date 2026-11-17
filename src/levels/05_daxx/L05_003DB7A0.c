#include "common.h"

/* localdecomp:start func_L05_003DB7A0 */
#include "vu0.h"
typedef int q_3DB7A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DB7A0;

extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");
extern f32 D_L05_001DF158;
__asm__(".extern D_L05_001DF158, 4");
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L05_003DB7A0(u8 *o) {
    V4_3DB7A0 b;
    V4_3DB7A0 v;
    q_3DB7A0 z;
    u8 *m;

    func_L01_00451FE0(o, 0x1FF, D_L05_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    m = func_L01_00452460(o, 0x1E51, 0);
    *(s32 *)(o + 0x98) = 0;
    o[0x31] = 0;
    *(u16 *)(o + 0x34) |= 1;
    if (m != 0) {
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    }
    z = 0;
    *(q_3DB7A0 *)&v = z;
    v.z = D_L05_001DF158;
    b = v;
    *(q_3DB7A0 *)&v = z;
    v.z = -0.140000015f;
    func_L02_003E2E38(o, &b, 0.100000001f, &v, 0x50, 3, 0, 0.180000007f, 2.5f, 20.0f, 1.0f);
    vec_add_ba(&b, &b, o + 0x10);
    func_L01_003303B8(&b, 0, 0, 0, 0, 2, 5, 0, 1.0f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0);
    func_L01_00451E78(o, 1, 0.0f);
    func_003C2880(o);
}
/* localdecomp:end func_L05_003DB7A0 */

/* localdecomp:start func_L05_003DB9B8 */
s32 func_L01_00447490(s32, s32, s32);
void func_L05_003DB7A0(u8 *o);

void func_L05_003DB9B8(s32 arg0) {
    if (func_L01_00447490(arg0, -1, 0) != 0) {
        func_L05_003DB7A0((u8 *)arg0);
    }
}
/* localdecomp:end func_L05_003DB9B8 */

/* localdecomp:start func_L05_003DB9F8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DB9F8;

typedef struct S_3DB9F8 {
    u8 pad0[0x68];
    s32 *f68;
} S_3DB9F8;

extern f32 D_001DF15C_sda;
__asm__(".extern D_001DF15C_sda, 4");

extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

void func_L05_003DB9F8(S_3DB9F8 *a0) {
    V4_3DB9F8 b;
    V4_3DB9F8 v;
    u128_t z;
    s32 *p;
    s32 r;
    u8 *c;

    p = a0->f68;
    c = (u8 *)a0 + 0xC0;
    z = 0;
    *(u128_t *)&v = z;
    v.z = D_001DF15C_sda;
    b = v;
    *(u128_t *)&v = z;
    v.x = 0.040000003f;
    v.z = -0.040000003f;
    func_0038D000(&v, &v, c);
    r = func_00382498(3, 6);
    func_L02_003E2E38(a0, &b, 0.0f, &v, r, 0, 0, 0.040000003f, 1.5f, 15.0f, 1.0f);
    v.x = -0.040000003f;
    v.z = -0.048000004f;
    func_0038D000(&v, &v, c);
    r = func_00382498(3, 6);
    func_L02_003E2E38(a0, &b, 0.0f, &v, r, 1, 0, 0.040000003f, 1.5f, 15.0f, 1.0f);
    r = func_00382498(0x5A, 0xB4);
    *p = (r * 5 + 2) / 6;
}
/* localdecomp:end func_L05_003DB9F8 */
