#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003ECC40 */
typedef int u128_t_3ECC40 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; u8 *p10; u8 pad14[0x170 - 0x14]; u8 *p170; } T_3ECC40;
extern T_3ECC40 D_L04_0021FC18;
extern void func_00382580(void *, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L04_003ECC40(void *self, void *pos, void *off) {
    vu0_v4 c;
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 *pv;
    vu0_v4 *pw;
    vu0_v4 *pv2;
    vu0_v4 *pw2;
    u8 *p;
    s32 i;

    vec_add_ab(&c, pos, off);
    for (i = 0; i < 15; i++) {
        pv2 = &v;
        pw2 = &w;
        pv = &v;
        pw = &w;
        func_00382580(pv2, 0.3f, 1.5f);
        v.y = -fabs_asm(v.y);
        func_0038D000(pv2, pv2, (u8 *)self + 0xC0);
        *(u128_t_3ECC40 *)&w = *(u128_t_3ECC40 *)&v;
        func_0038CF68(pw2, pw2, func_003824E0(0.75f, 1.5f) * 0.020000001f);
        vec_add_ab(&v, &v, &c);
        p = func_L01_00475C60(pv2, pw2, 0x25, func_00382498(-2, 2), 0x7F202B31, 0x202B31, 315000.0f, 420000.0f, -1.5f, 0);
        if (p != 0) {
            p[2] = D_L04_0021FC18.p10[0];
        }
        func_0038CF68(pw, pw, func_003824E0(3.0f, 5.0f) * 0.020000001f);
        p = func_L01_00475C60(pv, pw, 0x25, func_00382498(-2, 2), 0x7F171F23, 0x171F23, 42000.0f, 42000.0f, 20.0f, 0);
        if (p != 0) {
            p[2] = D_L04_0021FC18.p170[1];
        }
    }
}
/* localdecomp:end func_L04_003ECC40 */

/* localdecomp:start func_L04_003ECE58 */
typedef int u128_3ECE58 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3ECE58;

extern u8 D_L04_001D66B0[8];
__asm__(".extern D_L04_001D66B0, 16");
extern f32 D_001DF400_sda;
__asm__(".extern D_001DF400_sda, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern s32 func_L01_00452460(void *, s32, s32);
extern void func_L04_003ECC40(void *, void *, void *);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L04_003ECE58(u8 *self) {
    V4_3ECE58 tmp;
    V4_3ECE58 src;
    if (func_L01_00447490(self, -1, 0) != 0) {
        func_003A52A0(0, 0, self);
        func_L01_00451FE0(self, 0x1F, D_L04_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 2.0f, 4.0f, 2.0f, 5.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00452460(self, 0x1F22, 0);
        *(u128_3ECE58 *)&src = 0;
        src.z = D_001DF400_sda;
        tmp = src;
        func_L04_003ECC40(self, self + 0x10, &tmp);
        func_L01_00451E78(self, 1, 0.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L04_003ECE58 */

/* localdecomp:start func_L04_003ECF50 */
typedef int u128_t_3ECF50 __attribute__((mode(TI)));
extern T_3ECC40 D_L04_0021FC18;
__asm__(".extern D_L04_001DF404, 4");
__asm__(".extern D_L04_001DF408, 4");
__asm__(".extern D_L04_001DF40C, 4");
extern f32 D_L04_001DF404;
extern f32 D_L04_001DF408;
extern f32 D_L04_001DF40C;
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L04_003ECF50(void *self, void *pos, void *off) {
    vu0_v4 c;
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 *pw;
    u8 *p;
    f32 s;
    s32 i;

    vec_add_ab(&c, pos, off);
    for (i = 0; i < 15; i++) {
        pw = &w;
        s = *(f32 *)((u8 *)self + 0x2C) / 0.080859996f;
        func_00382580(&v, D_L04_001DF404 * s * 0.2f, D_L04_001DF404 * s);
        *(u128_t_3ECF50 *)&w = *(u128_t_3ECF50 *)&v;
        func_0038CF68(&w, &w, func_003824E0(s * D_L04_001DF408 * 0.5f, s * D_L04_001DF408) * 0.020000001f);
        vec_add_ab(&v, &v, &c);
        p = func_L01_00475C60(&v, pw, 0x36, func_00382498(-2, 2), 0x7F202B31, 0x202B31, 315000.0f, 420000.0f, -1.5f, 0);
        if (p != 0) {
            p[2] = D_L04_0021FC18.p10[0];
            p[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
        }
        func_0038CF68(&w, &w, func_003824E0(s * D_L04_001DF40C * 0.6f, s * D_L04_001DF40C) * 0.020000001f);
        p = func_L01_00475C60(&v, &w, 0x25, func_00382498(-2, 2), 0x7F171F23, 0x171F23, 42000.0f, 42000.0f, 20.0f, 0);
        if (p != 0) {
            p[2] = D_L04_0021FC18.p170[1];
            p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L04_003ECF50 */

/* localdecomp:start func_L04_003ED190 */
extern u8 D_L04_001D66B0[8];
__asm__(".extern D_L04_001D66B0, 16");
extern f32 D_001DF410_sda;
__asm__(".extern D_001DF410_sda, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_L04_003ECF50(void *, void *, void *);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_ED190;
typedef int u128_t __attribute__((mode(TI)));

void func_L04_003ED190(void *o) {
    V4_ED190 dst;
    V4_ED190 src;
    if (func_L01_00447490(o, -1, 0) != 0) {
        func_003A52A0(0, 0, o);
        func_L01_00451FE0(o, 31, D_L04_001D66B0, 255, 180, 0, 0, 35, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        *(u128_t *)&src = 0;
        src.z = D_001DF410_sda;
        dst = src;
        func_L04_003ECF50(o, (u8 *)o + 0x10, &dst);
        func_L01_00451E78(o, 1, 0.0f);
        func_003C2880(o);
    }
}
/* localdecomp:end func_L04_003ED190 */
