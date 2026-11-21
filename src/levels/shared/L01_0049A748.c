#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x5628 - 0x4958];
    u8 fX[1];
} S_func_00496AB0;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} E_496DC0;
typedef struct {
    s32 id;
    s32 pad[3];
} Ent_497BC8;
typedef struct { s32 a; s32 b; s32 c; s32 d; } Ent_00497C30;

/* declared by functions of L01_00499C80.c, which this file was cut from */
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(int);
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00517190(s32, s32);

/* localdecomp:start func_L01_0049A748 */
extern s32 func_0038E548(u8 *str, s32 len, f32 scale);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_L01_001DC0E8;

void func_L01_0049A748(s32 id, f32 *scale, f32 *size) {
    f32 s = 1.2f;
    f32 minw = 0.0f;
    f32 maxw = 0.49f;
    f32 r;
    f32 w;
    f32 lo;
    f32 hi;

    w = (f32)func_0038E548((u8 *)func_00381FF0(id), -1, s) / D_L01_001DC0E8;
    r = s;
    lo = 6.0f;
    hi = 11.0f;
    if (maxw < w) {
        r = maxw * s / w;
        w = maxw;
    }
    *size = func_003C4088(lo, hi, (w - minw) / (maxw - minw));
    if (*size > hi) {
        *size = hi;
    } else if (*size < lo) {
        *size = lo;
    }
    *scale = r;
}
/* localdecomp:end func_L01_0049A748 */

/* localdecomp:start func_L01_0049A868 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_0049A868;
typedef struct { u8 pad[8]; VT_0049A868 *vt; u8 padC[0x44]; void *f50; } O_0049A868;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } Q_0049A868;
typedef struct { u8 pad[0x694]; s32 f694; u8 pad698[0x1278 - 0x698]; u8 f1278[1]; } S_160C40_0049A868;
extern S_160C40_0049A868 D_00160C40_0049A868;
extern Q_0049A868 D_L01_001E15E0_0049A868;
extern f32 D_L01_001D93E0;
__asm__(".extern D_L01_001D93E0, 4");
extern f32 D_L01_001D93E4;
extern f32 D_L01_001D93E8;
extern f32 D_L01_001D93EC;
extern f32 D_L01_001D93F0;
__asm__(".extern D_L01_001D93F0, 4");
extern f32 D_L01_001D93F4;
extern f32 D_L01_001D93F8;
extern f32 D_L01_001D93FC;
extern s32 D_L01_001D9340[] __attribute__((section(".sdata")));
extern s32 D_L01_001D937C;
__asm__(".extern D_L01_001D937C, 4");
extern s32 D_L01_001D9380;
__asm__(".extern D_L01_001D9380, 4");
extern s32 D_L01_001D9384;
__asm__(".extern D_L01_001D9384, 4");
extern s32 D_L01_001DC1B0;
__asm__(".extern D_L01_001DC1B0, 4");
extern s32 func_00381FF0(s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_L01_00518D40_0049A868(s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E8A58(s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern s32 func_L01_0049B490(s32);

void func_L01_0049A868(void)
{
    s32 i;
    Q_0049A868 *q;
    void *base;
    O_0049A868 *o;

    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005,
                  0xD0008, func_00381FF0(0x1652), 0xD0006, 0xE62, 0xD0007, 0xE63, 5.0f);
    func_L01_00518D40_0049A868(0x4D0000);
    func_003E8FE8(0x4D0001, func_00381FF0(0xCD5), 0x8066CCFF, 0.5f, 0.93f, 1.0f, 1.0f);
    func_L01_00516AA0(0x4D0001, 0x40, 1);
    func_003E8630(0x4D0000, 0x4D0001);
    func_003E8FE8(0xD0009, func_00381FF0(0x1B99), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD0009, 1);
    func_003E8FE8(0xD000A, func_00381FF0(0x1B9A), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD000A, 1);
    func_003E8A08(0x4D0000, 0xD0009, 0xD000A);
    func_003E9270(0x4D0002, 0x332299DE, D_L01_001D93E0, D_L01_001D93E4, D_L01_001D93E8, D_L01_001D93EC, 0.0035f, 0.006f);
    func_003E8FE8(0x4D0003, func_00381FF0(0xCD5), 0x8066CCFF, D_L01_001D93E0, D_L01_001D93E4, 1.0f, 1.0f);
    func_L01_00516AA0(0x4D0003, 0x40, 1);
    func_003E9138(0x4D0005, 0x80808080, D_L01_001D93F0, D_L01_001D93F4, D_L01_001D93F8 - 0.0035f, D_L01_001D93FC - 0.006f, 0);
    func_003E9270(0x4D0004, 0x332299DE, D_L01_001D93F0, D_L01_001D93F4, D_L01_001D93F8, D_L01_001D93FC, 0.0035f, 0.006f);
    func_003E8A58(0x4D0000, 0x4D0003, 0x4D0002, 0x4D0005, 0x4D0004);
    func_003E8348(0x11, 0x4D0000);
    D_L01_001D937C = ((s32)func_003BB3A8(1) + 0xF) & 0xFFFFFFF0;
    func_003B4528(func_003B42F8(0), D_L01_001D937C, 0, D_00160C40_0049A868.f694, (s32)D_00160C40_0049A868.f1278);
    q = &D_L01_001E15E0_0049A868;
    if (q->f4 != 0) {
        base = q;
    } else {
        base = func_003E6C08(q);
    }
    o = (O_0049A868 *)func_003E6378(func_003E6DE8(base), 0x4D0005);
    if (o == 0 || o->vt->isA(o, D_L01_001DC1B0) == 0) {
        o = 0;
    }
    o->f50 = func_003B42F8(0);
    func_L01_00517190(0x4D0005, 1);
    for (i = 14; i >= 0; i--) {
        D_L01_001D9340[i] = 0;
    }
    D_L01_001D9380 = -1;
    if (D_L01_001D9384 == -1) {
        D_L01_001D9384 = func_L01_0049B490(-1);
    }
}
/* localdecomp:end func_L01_0049A868 */

INCLUDE_ASM("asm/levels", func_L01_0049AC88);
