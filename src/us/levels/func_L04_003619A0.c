#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L04_003629A8 (src/levels/shared/L04_00362568.c) */
extern void func_00388BD0(void *, void *);
extern void func_L01_0044CB08(void *, void *, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE418(void *, s32, s32);

/* localdecomp:start func_L04_003619A0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4_3619A0;
typedef struct { char p0[0x10]; s32 f10; char p1[0x10]; f32 f24; char p2[0x1c]; u16 f44; } C_3619A0;
typedef struct Q_3619A0 { char p0[0x20]; u8 f20[3]; C_3619A0 *f24; char p28[4]; f32 f2c; char p30[4]; u16 f34; char p36[0x32]; struct P_3619A0 *f68; char p6c[0x2c]; s32 f98; } Q_3619A0;
typedef struct { char p0[0x10]; W4_3619A0 f10; char p1[0xa0]; W4_3619A0 fC0; char p2[0x20]; W4_3619A0 fF0; } R_3619A0;
typedef struct P_3619A0 { char p0[0xF8]; s32 f0F8; s32 f0FC; s32 f100; char p1[0x14]; f32 f118; char p2[4]; f32 f120; char p3[0x24]; s32 f148; char p4[0x1B0]; Q_3619A0 *f2FC; char p5[0x78]; s32 f378; f32 f37C; } P_3619A0;
extern f32 D_001DD790_sda; __asm__(".extern D_001DD790_sda, 4");
extern f32 D_001DD788_sda; __asm__(".extern D_001DD788_sda, 4");
extern f32 D_001DD78C_sda; __asm__(".extern D_001DD78C_sda, 4");
extern f32 D_001DD7A0_sda; __asm__(".extern D_001DD7A0_sda, 4");
extern f32 D_001DD77C_sda; __asm__(".extern D_001DD77C_sda, 4");
extern s32 D_001DD778_sda; __asm__(".extern D_001DD778_sda, 4");

void func_L04_003619A0(Q_3619A0 *a0, W4_3619A0 *a1, f32 f, s32 a2) {
    W4_3619A0 v;
    P_3619A0 *p;
    s32 c;
    qzero(&v);
    p = a0->f68;
    v.z = f;
    ((R_3619A0 *)a0)->f10 = *a1;
    ((R_3619A0 *)a0)->fF0 = v;
    func_00388BD0((char *)a0 + 0xC0, &v);
    a0->f34 = (a0->f34 & 0xFFBE);
    a0->f34 |= a0->f24->f44 & 0x1000;
    a0->f98 = a0->f24->f10;
    p->f37C = D_001DD790_sda;
    a0->f2c = a0->f24->f24 * p->f37C;
    if (p->f2FC) {
        func_L01_0044CB08(a0, p->f2FC, 0, 0);
        p->f2FC->f34 &= 0xFFBE;
        p->f2FC->f34 |= p->f2FC->f24->f44 & 0x1000;
        p->f2FC->f98 = p->f2FC->f24->f10;
        p->f2FC->f2c = p->f2FC->f24->f24 * p->f37C;
    }
    p->f378 = a2;
    func_003886E8((char *)p + 0x110, (char *)a0 + 0xC0, D_001DD788_sda * 0.016666668f);
    p->f120 = D_001DD788_sda * 0.016666668f;
    p->f118 = D_001DD78C_sda * 0.016666668f;
    p->f148 = -1;
    p->f100 = 0;
    p->f0F8 = 0;
    p->f0FC = 0;
    qzero((char *)p + 0xC0);
    c = (s32)(D_001DD7A0_sda * 0.016666668f * 127.0f);
    *(u8 *)((char *)a0 + 0x23) = c;
    a0->f34 |= 0x2800;
    if (p->f2FC) {
        *(u8 *)((char *)p->f2FC + 0x23) = c;
        p->f2FC->f34 |= 0x2800;
    }
    func_L01_00441FB8(a0, 0x1B, 8);
    func_003BE418(a0, D_001DD778_sda, (s32)D_001DD77C_sda);
}
/* localdecomp:end func_L04_003619A0 */
