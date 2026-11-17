#include "common.h"

INCLUDE_ASM("asm/levels", func_L13_003AF7F0);

/* localdecomp:start func_L13_003AF8C0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4_003AF8C0;
typedef struct { char p0[0x10]; s32 f10; char p1[0x10]; f32 f24; char p2[0x1c]; u16 f44; } C_003AF8C0;
typedef struct Q_003AF8C0 {
    char p0[0x23];
    u8 b23;
    C_003AF8C0 *f24;
    char p28[4];
    f32 f2c;
    char p30[4];
    u16 f34;
    char p36[0x32];
    struct P_003AF8C0 *f68;
    char p6c[0x2c];
    s32 f98;
} Q_003AF8C0;
typedef struct { char p0[0x10]; W4_003AF8C0 f10; char p1[0xa0]; W4_003AF8C0 fC0; char p2[0x20]; W4_003AF8C0 fF0; } R_003AF8C0;
typedef struct P_003AF8C0 {
    char p0[0x200];
    f32 f200;
    char p1[0x3D8 - 0x204];
    s32 f3D8;
    f32 f3DC;
} P_003AF8C0;

extern f32 D_L13_001DE6F0;
__asm__(".extern D_L13_001DE6F0, 4");
extern f32 D_L13_001DE6F4;
__asm__(".extern D_L13_001DE6F4, 4");
extern f32 D_L13_001DE6FC;
__asm__(".extern D_L13_001DE6FC, 4");
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L13_003AF8C0(Q_003AF8C0 *a0, W4_003AF8C0 *a1, f32 f, s32 a2) {
    W4_003AF8C0 v;
    P_003AF8C0 *p;

    qzero(&v);
    p = (P_003AF8C0 *)a0->f68;
    v.z = f;
    ((R_003AF8C0 *)a0)->f10 = *a1;
    ((R_003AF8C0 *)a0)->fF0 = v;
    func_0038D308((char *)a0 + 0xC0, &v);
    a0->f34 = (a0->f34 & 0xFFBE);
    a0->f34 |= a0->f24->f44 & 0x1000;
    a0->f98 = a0->f24->f10;
    p->f3DC = D_L13_001DE6F4;
    a0->f2c = a0->f24->f24 * p->f3DC;
    p->f3D8 = a2;
    func_0038CE20((char *)p + 0x1F0, (char *)a0 + 0xC0, D_L13_001DE6F0 * 0.020000001f);
    p->f200 = D_L13_001DE6F0 * 0.020000001f;
    a0->b23 = (s32)(D_L13_001DE6FC * 0.020000001f * 127.0f);
    a0->f34 |= 0x2800;
    func_L01_004450F0(a0, 0x26, 0);
}
/* localdecomp:end func_L13_003AF8C0 */
