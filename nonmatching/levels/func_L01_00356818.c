/* Level 01. 1 instruction off (76 diff reported because it shifts the rest): retail starts with a bare "sq $zero,0x0($sp)" for the zeroed stack quadword; plain C gives "por $v0,$zero,$zero" + "sq $v0". Default flags. */
#include "common.h"
#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4;
typedef struct { char p0[0x10]; s32 f10; char p1[0x10]; f32 f24; char p2[0x1c]; u16 f44; } C;
typedef struct Q { char p0[0x24]; C *f24; char p28[4]; f32 f2c; char p30[4]; u16 f34; char p36[0x32]; struct P *f68; char p6c[0x2c]; s32 f98; } Q;
typedef struct { char p0[0x10]; W4 f10; char p1[0xa0]; W4 fC0; char p2[0x20]; W4 fF0; } R;
typedef struct P { char p0[0xF8]; s32 f0F8; s32 f0FC; s32 f100; char p1[0x14]; f32 f118; char p2[4]; f32 f120; char p3[0x24]; s32 f148; char p4[0x208]; s32 f354; f32 f358; Q *f35C; Q *f360; } P;
extern f32 D_001DD5D0_sda; __asm__(".extern D_001DD5D0_sda, 4");
extern s32 D_001DD61C_sda; __asm__(".extern D_001DD61C_sda, 4");
extern f32 D_001DD5C0_sda; __asm__(".extern D_001DD5C0_sda, 4");
extern f32 D_001DD5C4_sda; __asm__(".extern D_001DD5C4_sda, 4");
extern f32 D_001DD5B4_sda; __asm__(".extern D_001DD5B4_sda, 4");
extern s32 D_001DD5B0_sda; __asm__(".extern D_001DD5B0_sda, 4");
extern void func_0040EB68(void *a, void *b);
extern void func_0044FD88(void *o, void *c, s32 a, s32 b);
extern void func_0040E3C0(f32 f, void *a, void *b);
extern void func_L01_004450F0(void *o, s32 a, s32 b);
extern void func_00444CB8(void *o, s32 a, s32 b);

void func_L01_00356818(Q *a0, W4 *a1, f32 f, s32 a2) {
    W4 v = {0};
    P *p;
    p = a0->f68;
    v.z = f;
    ((R *)a0)->f10 = *a1;
    ((R *)a0)->fF0 = v;
    func_0040EB68((char *)a0 + 0xC0, &v);
    a0->f34 = (a0->f34 & 0xFFBE);
    a0->f34 |= a0->f24->f44 & 0x1000;
    a0->f98 = a0->f24->f10;
    p->f358 = D_001DD5D0_sda;
    a0->f2c = a0->f24->f24 * p->f358;
    if (p->f360) {
        func_0044FD88(a0, p->f360, 1, D_001DD61C_sda);
        p->f360->f34 &= 0xFFBE;
        p->f360->f34 |= p->f360->f24->f44 & 0x1000;
        p->f360->f98 = p->f360->f24->f10;
        p->f360->f2c = p->f360->f24->f24 * p->f358;
    }
    p->f354 = a2;
    func_0040E3C0(D_001DD5C0_sda, (char *)p + 0x110, (char *)a0 + 0xC0);
    p->f100 = 0;
    p->f0F8 = 0;
    p->f0FC = 0;
    p->f120 = D_001DD5C0_sda;
    p->f148 = -1;
    p->f118 = D_001DD5C4_sda;
    func_L01_004450F0(a0, 0x19, 4);
    func_00444CB8(a0, D_001DD5B0_sda, (s32)D_001DD5B4_sda);
}
