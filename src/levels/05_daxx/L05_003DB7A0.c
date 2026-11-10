#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003DB7A0);

/* localdecomp:start func_L05_003DB9B8 */
s32 func_L01_00447490(s32, s32, s32);
void func_L05_003DB7A0(s32);

void func_L05_003DB9B8(s32 arg0) {
    if (func_L01_00447490(arg0, -1, 0) != 0) {
        func_L05_003DB7A0(arg0);
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
extern void func_L02_003E2E38(S_3DB9F8 *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

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
