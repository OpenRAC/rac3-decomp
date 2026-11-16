/* NTSC-U draft (Claude wave C2): C of func_L13_003ADAD8, the NTSC-U twin of func_L13_003AF8C0, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L13_003ADAD8", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (0 diff) only with @ps2as (inline lui/ori/mtc1 constants 1/60 = 0.0166666675f, 127.0f; qzero via vu0.h); its PAL file L13_003ABD48.c has no @ps2as: 50 diff with the PAL flags (constants from the gp pool). Template PAL C func_L01_003569A0 ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L13_003AF8C0 (src/levels/shared/L13_003AF7F0.c) */
/* localdecomp:start func_L13_003ADAD8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4_003ADAD8;
typedef struct { char p0[0x10]; s32 f10; char p1[0x10]; f32 f24; char p2[0x1c]; u16 f44; } C_003ADAD8;
typedef struct Q_003ADAD8 {
    char p0[0x23];
    u8 b23;
    C_003ADAD8 *f24;
    char p28[4];
    f32 f2c;
    char p30[4];
    u16 f34;
    char p36[0x32];
    struct P_003ADAD8 *f68;
    char p6c[0x2c];
    s32 f98;
} Q_003ADAD8;
typedef struct { char p0[0x10]; W4_003ADAD8 f10; char p1[0xa0]; W4_003ADAD8 fC0; char p2[0x20]; W4_003ADAD8 fF0; } R_003ADAD8;
typedef struct P_003ADAD8 {
    char p0[0x200];
    f32 f200;
    char p1[0x3D8 - 0x204];
    s32 f3D8;
    f32 f3DC;
} P_003ADAD8;

extern f32 D_001DE720_sda;
__asm__(".extern D_001DE720_sda, 4");
extern f32 D_001DE724_sda;
__asm__(".extern D_001DE724_sda, 4");
extern f32 D_001DE72C_sda;
__asm__(".extern D_001DE72C_sda, 4");
extern void func_00388BD0(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L13_003ADAD8(Q_003ADAD8 *a0, W4_003ADAD8 *a1, f32 f, s32 a2) {
    W4_003ADAD8 v;
    P_003ADAD8 *p;

    qzero(&v);
    p = (P_003ADAD8 *)a0->f68;
    v.z = f;
    ((R_003ADAD8 *)a0)->f10 = *a1;
    ((R_003ADAD8 *)a0)->fF0 = v;
    func_00388BD0((char *)a0 + 0xC0, &v);
    a0->f34 = (a0->f34 & 0xFFBE);
    a0->f34 |= a0->f24->f44 & 0x1000;
    a0->f98 = a0->f24->f10;
    p->f3DC = D_001DE724_sda;
    a0->f2c = a0->f24->f24 * p->f3DC;
    p->f3D8 = a2;
    func_003886E8((char *)p + 0x1F0, (char *)a0 + 0xC0, D_001DE720_sda * 0.0166666675f);
    p->f200 = D_001DE720_sda * 0.0166666675f;
    a0->b23 = (s32)(D_001DE72C_sda * 0.0166666675f * 127.0f);
    a0->f34 |= 0x2800;
    func_L01_00441FB8(a0, 0x26, 0);
}
/* localdecomp:end func_L13_003ADAD8 */
