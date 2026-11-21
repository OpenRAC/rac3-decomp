#include "common.h"

/* NTSC-U counterpart of func_L24_0034FE28 (src/levels/24_insomniac_museum/L24_0034F040.c) */
#include "vu0.h"
#include "vu0.h"
extern vu0_q D_L24_001E8F60_0034EF08;
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_003886E8(f32 *, void *, f32);
#include "vu0.h"
#include "vu0.h"
extern f32 func_00388800(void *, void *);
#include "vu0.h"
extern void func_003BDA38(void *, s32, void *);
#include "vu0.h"
extern void func_003886E8(f32 *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
#include "vu0.h"
extern void func_003BDA38(void *, s32, void *);
extern void func_003886E8(f32 *, void *, f32);

/* localdecomp:start func_L24_0034EF08 */
#include "vu0.h"
extern void func_003BD9A0(void *, s32, void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_00443648(void *, void *, f32, s32, f32, f32, s32, s32, s32);
extern s32 func_L24_0034EDD8(u8 *, void *, void *, void *, s32, s32, s32, f32, f32);
extern f32 func_00388800(void *, void *);
extern u8 *func_L01_00461960(void *, void *, f32, u8);
extern void func_003886E8(f32 *, void *, f32);
extern void func_003BF6A8(f32 *, f32);
extern f32 func_0037E250(f32, f32);
extern vu0_q D_L24_001E8F60_0034EF08;
extern u8 D_L24_001D66B0_0034EF08;
__asm__(".extern D_L24_001D66B0_0034EF08, 16");
__asm__(".extern D_L24_001DD4F4_0034EF08, 4");
__asm__(".extern D_L24_001DD504, 4");
__asm__(".extern D_L24_001DD508_0034EF08, 4");
__asm__(".extern D_L24_001DD50C_0034EF08, 4");
extern f32 D_L24_001DD4F4_0034EF08;
extern f32 D_L24_001DD504;
extern s32 D_L24_001DD508_0034EF08;
extern f32 D_L24_001DD50C_0034EF08;


void func_L24_0034EF08(void *o) {
    u8 *obj = (u8 *)o;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 m[16];
    f32 d[4];
    f32 p[4];
    f32 a[4];
    f32 b[4];
    f32 e[4];
    f32 c[4];
    f32 t[4];
    f32 len;
    f32 k;
    u8 *q;
    u8 *fx;
    s32 i;
    vu0_q acc;

    func_003BD9A0(obj, 2, m);
    *(vu0_q *)d = *(vu0_q *)m;
    func_003BDA38(obj, 2, p);
    func_00388830(a, d, D_L24_001DD50C_0034EF08);
    len = D_L24_001DD50C_0034EF08;
    func_00388830(b, d, D_L24_001DD504 * 0.016666668f);
    vec_add_ba(b, b, s + 0x100);
    func_L01_00443648(obj, p, 0.3f, 0x8110000, D_L24_001DD4F4_0034EF08, 1.0f, 9, 1, 0);
    vec_add_ab(e, a, p);
    func_L01_00443648(obj, e, 0.6f, 0x8110000, D_L24_001DD4F4_0034EF08, 1.0f, 9, 1, 0);
    if (((s32 (*)(u8 *, void *, void *, s32, s32, s32, s32, f32, f32))func_L24_0034EDD8)(obj, p, e, 0x8110000, 9, 1, 0, D_L24_001DD4F4_0034EF08, 1.0f) != 0) {
        *(vu0_q *)a = D_L24_001E8F60_0034EF08;
        len = func_00388800(p, a);
        fx = func_L01_00461960(a, &D_L24_001D66B0_0034EF08, 0.2f, 0);
        if (fx != 0) {
            *(f32 *)(fx + 0xC) *= 4.0f;
        }
    }
    func_003886E8(c, b, 1.0f / (f32)D_L24_001DD508_0034EF08);
    for (i = 0; i < D_L24_001DD508_0034EF08; i++) {
        func_003BF6A8(p, (f32)i * 0.02f);
        q = func_L01_00461960(p, b, len, i);
        if (q != 0) {
            *(s16 *)(q + 0xA) = (s32)(len / (D_L24_001DD504 * 0.016666668f)) + 7;
            q[0x3D] = q[0xA];
        }
        {
            vu0_q tmp;
            __asm__("lqc2 %0, %1" : "=j"(tmp) : "m"(*(vu0_v4 *)c));
            __asm__("lqc2 %0, %1" : "=j"(acc) : "m"(*(vu0_v4 *)p));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(acc) : "j"(acc), "j"(tmp));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)p) : "j"(acc));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)t) : "j"(acc));
        }
        k = func_0037E250(0.1f, 0.9f);
        func_003886E8(e, a, k);
        {
            vu0_q tmp;
            __asm__("lqc2 %0, %1" : "=j"(acc) : "m"(*(vu0_v4 *)e));
            __asm__("lqc2 %0, %1" : "=j"(tmp) : "m"(*(vu0_v4 *)p));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(acc) : "j"(acc), "j"(tmp));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)e) : "j"(acc));
        }
        {
            f32 size = 0.3f;
            size *= k + 1.0f;
            func_L01_00443648(obj, e, size, 0x8110000, D_L24_001DD4F4_0034EF08, 1.0f, 9, 1, 0);
        }
    }
}
/* localdecomp:end func_L24_0034EF08 */
