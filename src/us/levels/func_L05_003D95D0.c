#include "common.h"

/* NTSC-U counterpart of func_L05_003DB9F8 (src/levels/05_daxx/L05_003DB7A0.c) */
/* localdecomp:start func_L05_003D95D0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DB9F8;

typedef struct S_3DB9F8 {
    u8 pad0[0x68];
    s32 *f68;
} S_3DB9F8;

extern f32 D_001DF19C_sda;
__asm__(".extern D_001DF19C_sda, 4");

extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(S_3DB9F8 *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

void func_L05_003D95D0(S_3DB9F8 *a0) {
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
    v.z = D_001DF19C_sda;
    b = v;
    *(u128_t *)&v = z;
    v.x = 0.033333335f;
    v.z = -0.033333335f;
    func_003888C8(&v, &v, c);
    r = func_0037E208(3, 6);
    func_L02_003E0520(a0, &b, 0.0f, &v, r, 0, 0, 0.033333335f, 1.5f, 15.0f, 1.0f);
    v.x = -0.033333335f;
    v.z = -0.040000003f;
    func_003888C8(&v, &v, c);
    r = func_0037E208(3, 6);
    func_L02_003E0520(a0, &b, 0.0f, &v, r, 1, 0, 0.033333335f, 1.5f, 15.0f, 1.0f);
    r = func_0037E208(0x5A, 0xB4);
    *p = r;
}
/* localdecomp:end func_L05_003D95D0 */
