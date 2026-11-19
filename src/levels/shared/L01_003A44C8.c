#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003A44C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4_003A2D80;
typedef struct { char p0[0x10]; s32 f10; char p1[0x10]; f32 f24; char p2[0x1c]; u16 f44; } C_003A2D80;
typedef struct Q_003A2D80 {
    char p0[0x10];
    W4_003A2D80 f10;
    char p20[4];
    C_003A2D80 *f24;
    char p28[4];
    f32 f2c;
    char p30[4];
    u16 f34;
    char p36[0x32];
    struct P_003A2D80 *f68;
    char p6c[0x24];
    s32 f90;
    char p94[4];
    s32 f98;
    char p9c[0x24];
    W4_003A2D80 fC0;
    char pD0[0x20];
    W4_003A2D80 fF0;
} Q_003A2D80;
typedef struct P_003A2D80 {
    char p0[0xC0];
    W4_003A2D80 fC0;
    char pD0[0x28];
    s32 fF8;
    s32 fFC;
    s32 f100;
    char p104[0xC];
    char f110[8];
    f32 f118;
    char p11C[4];
    f32 f120;
    char p124[0x24];
    s32 f148;
    char p14C[0x26C];
    s32 f3B8;
    f32 f3BC;
} P_003A2D80;
extern f32 D_L01_001DE264_3A44C8;
__asm__(".extern D_L01_001DE264_3A44C8, 4");
extern f32 D_L01_001DE25C_3A44C8;
__asm__(".extern D_L01_001DE25C_3A44C8, 4");
extern f32 D_L01_001DE260_3A44C8;
__asm__(".extern D_L01_001DE260_3A44C8, 4");
extern s32 D_L01_001DE248_3A44C8;
__asm__(".extern D_L01_001DE248_3A44C8, 4");
extern s32 D_L01_001DE24C_3A44C8;
__asm__(".extern D_L01_001DE24C_3A44C8, 4");
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3938(void *, s32, s32);

void func_L01_003A44C8(Q_003A2D80 *a0, W4_003A2D80 *a1, s32 a2, f32 f) {
    W4_003A2D80 v;
    P_003A2D80 *p;

    qzero(&v);
    p = a0->f68;
    v.z = f;
    a0->f10 = *a1;
    a0->fF0 = v;
    func_0038D308((char *)a0 + 0xC0, &v);
    a0->f34 = (a0->f34 & 0xFFBE);
    a0->f34 |= a0->f24->f44 & 0x1000;
    a0->f98 = a0->f24->f10;
    p->f3BC = D_L01_001DE264_3A44C8;
    a0->f2c = a0->f24->f24 * p->f3BC;
    p->f3B8 = a2;
    func_0038CE20((char *)p + 0x110, (char *)a0 + 0xC0, D_L01_001DE25C_3A44C8 * 0.020000001f);
    p->f120 = D_L01_001DE25C_3A44C8 * 0.020000001f;
    p->f118 = D_L01_001DE260_3A44C8 * 0.020000001f;
    p->f148 = -1;
    p->f100 = 0;
    p->fF8 = 0;
    p->fFC = 0;
    qzero((char *)p + 0xC0);
    func_L01_004450F0(a0, 0x11, 7);
    func_003C3938(a0, D_L01_001DE248_3A44C8, D_L01_001DE24C_3A44C8);
}
/* localdecomp:end func_L01_003A44C8 */
