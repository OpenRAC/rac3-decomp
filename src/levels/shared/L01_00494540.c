#include "common.h"

typedef struct Obj_4917A0 Obj_4917A0;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_4917A0 *);
} Vt_4917A0;
struct Obj_4917A0 {
    s32 pad;
    Vt_4917A0 *vt;
};
typedef struct S_492AF0 S_492AF0;
typedef struct { u8 pad[0xC]; void (*fC)(S_492AF0 *); } V_492AF0;
struct S_492AF0 { s32 f0; V_492AF0 *vt; };
typedef struct Obj_492EE8 Obj_492EE8;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj_492EE8 *);
} Vt_492EE8;
struct Obj_492EE8 {
    s32 pad;
    Vt_492EE8 *vt;
};

/* localdecomp:start func_L01_00494540 */
typedef struct {
    char _p0[0xC];
    s32 fC;
    s32 f10;
} S_494540;

/* from rac4-decomp's func_L00_0062A688 */
s32 func_L01_00494540(S_494540 *arg0) {
    s32 value = arg0->f10;
    if (value != 0) {
        return value;
    }
    return arg0->fC;
}
/* localdecomp:end func_L01_00494540 */

/* localdecomp:start func_L01_00494560 */
s32 func_L01_00494560(void) {
    return 1;
}
/* localdecomp:end func_L01_00494560 */

/* localdecomp:start func_L01_00494568 */
s32 func_L01_00494568(void) {
    return 2;
}
/* localdecomp:end func_L01_00494568 */

/* localdecomp:start func_L01_00494570 */
s32 func_L01_00494570(void) {
    return 0;
}
/* localdecomp:end func_L01_00494570 */

/* localdecomp:start func_L01_00494578 */
s32 func_L01_00494578(void) {
    return 1;
}
/* localdecomp:end func_L01_00494578 */

INCLUDE_ASM("asm/levels", func_L01_00494580);

/* localdecomp:start func_L01_00494590 */
s32 func_L01_00494590(void) {
    return 1;
}
/* localdecomp:end func_L01_00494590 */

/* localdecomp:start func_L01_00494598 */
s32 func_L01_00494598(void) {
    return 0;
}
/* localdecomp:end func_L01_00494598 */

/* localdecomp:start func_L01_004945A0 */
s32 func_L01_004945A0(void) {
    return 0;
}
/* localdecomp:end func_L01_004945A0 */

/* localdecomp:start func_L01_004945A8 */
s32 func_L01_004945A8(void) {
    return 0;
}
/* localdecomp:end func_L01_004945A8 */

/* localdecomp:start func_L01_004945B0 */
s32 func_L01_004945B0(void) {
    return 1;
}
/* localdecomp:end func_L01_004945B0 */

/* localdecomp:start func_L01_004945B8 */
/* localdecomp:start func_L01_004945B8 */
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0_004945B8(s32, s32, s32);
extern void func_L01_00516B90_004945B8(s32, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00518110_004945B8(s32, s32, s32, s32);

void func_L01_004945B8(s32 menu, f32 *rect)
{
    f32 x = rect[0] + (rect[2] - rect[3]) * 0.5f + 0.0078125f;

    func_003E9138(0x1A0015, 0x706EC8FF, 0xED26, x, rect[1],
                  rect[3] - 0.0234375f, rect[3] - 0.012019231f);
    func_003E8FE8(0x1A0016, 0, 0x8066CCFF, x - rect[3] * 0.5f, rect[1], 1.0f, 1.0f);
    func_L01_00516AA0_004945B8(0x1A0016, 0x40, 1);
    func_L01_00516B90_004945B8(0x1A0016, 2, 3);
    func_003E8FE8(0x1A0017, func_00381FF0(0xCA7), 0x8066CCFF, rect[0] - rect[2] * 0.5f,
                  rect[1], 1.0f, 1.0f);
    func_L01_00516AA0_004945B8(0x1A0017, 0x40, 1);
    func_L01_00516B90_004945B8(0x1A0017, 1, 3);
    func_L01_00518110_004945B8(menu, 0x1A0015, 0x1A0016, 0x1A0017);
}
/* localdecomp:end func_L01_004945B8 */
/* localdecomp:end func_L01_004945B8 */

/* localdecomp:start func_L01_00494748 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_494748_00494748;
typedef struct {
    u8 pad[0x58];
    s32 (*f58)(void);
    void (*f5C)(void);
    s32 (*f60)(void);
    void (*f64)(void);
} Obj_494748_00494748;

extern void *func_L01_0043B548_00494748(s32, s32);
extern void func_L01_0047DE68_00494748(void);
extern s32 func_L01_0047DAE0_00494748(void);
extern s32 func_003BB118(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BA340();
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_L01_004986A8_00494748(void *, s32);
extern S_494748_00494748 D_L01_002EB8E8_00494748;
extern s32 D_L01_001D8FC8_00494748;
extern f32 D_L01_001D8FA8_00494748;
extern f32 D_L01_001D8FB8_00494748[] __attribute__((section(".sdata")));
extern f32 D_L01_001D8FB0_00494748;
extern f32 D_L01_001D8FB4_00494748;
__asm__(".extern D_L01_001D8FC8_00494748, 4");
__asm__(".extern D_L01_001D8FA8_00494748, 4");
__asm__(".extern D_L01_001D8FB8_00494748, 4");

void func_L01_00494748(void) {
    Obj_494748_00494748 *obj;
    s32 v;
    s32 lim;
    f32 off;
    s32 *t;

    obj = func_L01_0043B548_00494748(0x19E1, 0x6C);
    v = obj->f58();
    D_L01_002EB8E8_00494748.fC = v;
    lim = D_L01_001D8FC8_00494748;
    D_L01_002EB8E8_00494748.f10 = lim;
    if (v < lim) {
        D_L01_002EB8E8_00494748.f10 = v;
    }
    func_L01_0047DE68_00494748();
    off = 0.0035f;
    D_L01_002EB8E8_00494748.f0 = func_L01_0047DAE0_00494748();
    D_L01_002EB8E8_00494748.f4 = func_003BB118(0);
    func_003B9C68(func_003B9BD0(0), &D_L01_002EB8E8_00494748);
    func_003BA340(func_003B9BD0(0), 0x8066CCFF, 0x805F5F5F, 0x666690CC, 0x80FFFFFF);
    func_003BABB0(func_003B9BD0(0), D_L01_001D8FA8_00494748, D_L01_001D8FB0_00494748 - off, D_L01_001D8FB4_00494748, 0.0425f, 0.35f, 0);
    func_003BABD0(func_003B9BD0(0), D_L01_001D8FB8_00494748[0], D_L01_001D8FB8_00494748[1], D_L01_001D8FB8_00494748[2] - off, D_L01_001D8FB8_00494748[3] - 0.006f);
    obj->f5C();
    t = func_003B9BD0(0);
    func_L01_004986A8_00494748(t, obj->f60());
    obj->f64();
}
/* localdecomp:end func_L01_00494748 */

/* localdecomp:start func_L01_004948E8 */
/* localdecomp:start func_L01_004948E8 */
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_4948E8_004948E8;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_4948E8_004948E8;
typedef struct { u8 pad[8]; VT_4948E8_004948E8 *vt; u8 padC[0x44]; void *f50; } O_4948E8_004948E8;
extern f32 D_L01_001D8FD0_004948E8;
__asm__(".extern D_L01_001D8FD0_004948E8, 4");
extern f32 D_L01_001D8FE0_004948E8;
__asm__(".extern D_L01_001D8FE0_004948E8, 4");
extern f32 D_L01_001D8FF0_004948E8;
__asm__(".extern D_L01_001D8FF0_004948E8, 4");
extern f32 D_L01_001D9010_004948E8;
__asm__(".extern D_L01_001D9010_004948E8, 4");
extern f32 D_L01_001D9020_004948E8;
__asm__(".extern D_L01_001D9020_004948E8, 4");
extern f32 D_L01_001D8FD4_004948E8;
extern f32 D_L01_001D8FDC_004948E8;
extern f32 D_L01_001D8FE4_004948E8;
extern f32 D_L01_001D8FE8_004948E8;
extern f32 D_L01_001D8FEC_004948E8;
extern f32 D_L01_001D8FF4_004948E8;
extern f32 D_L01_001D8FF8_004948E8;
extern f32 D_L01_001D8FFC_004948E8;
extern f32 D_L01_001D9014_004948E8;
extern f32 D_L01_001D9018_004948E8;
extern f32 D_L01_001D901C_004948E8;
extern f32 D_L01_001D9000_004948E8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9000_004948E8, 8");
extern s32 D_L01_001D8F90_004948E8;
__asm__(".extern D_L01_001D8F90_004948E8, 4");
extern s32 D_L01_001D8F94_004948E8;
__asm__(".extern D_L01_001D8F94_004948E8, 4");
extern s32 D_L01_001DC1B0_004948E8;
__asm__(".extern D_L01_001DC1B0_004948E8, 4");
typedef struct { u8 pad[0x4954]; s32 f4954; u8 pad4958[0x6878 - 0x4958]; u8 f6878[1]; } S_160C40_4948E8_004948E8;
extern S_160C40_4948E8_004948E8 D_00160C40;
extern S_4948E8_004948E8 D_L01_001E15E0_004948E8;
extern s32 func_00381FF0(s32);
extern void func_L01_004980C0_004948E8(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0_004948E8(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern void func_L01_00518D40_004948E8(s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_L01_00518010_004948E8(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern void func_L01_00517BF8_004948E8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8_004948E8(s32, s32, s32, f32);
extern void func_L01_004945B8_004948E8(s32, f32 *);
extern s32 func_003E8348(s32, s32);
extern void func_L01_00494748_004948E8(void);
extern s32 func_003BB3A8(s32);
extern s32 func_003BB530(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern s32 func_003E87B8(s32, s32, s32);

void func_L01_004948E8(void)
{
    s32 buf;
    s32 size;
    void *base;
    S_4948E8_004948E8 *q;
    O_4948E8_004948E8 *o;

    func_L01_004980C0_004948E8(0xD, 8.5f, 0x1A0000, 0x1A0001, 0x1A0002, 0x1A0003, 0x1A0004, 0x1A0005,
                      0x1A0006, 0xD0008, func_00381FF0(0x15E1), 0x1A0007, 0x1A0008);
    func_003E8FE8(0x1A0009, func_00381FF0(0xC96), 0x8066CCFF, 0.5f, 0.93f, 1.0f, 1.0f);
    func_L01_00516AA0_004948E8(0x1A0009, 0x40, 1);
    func_003E8630(0x1A0000, 0x1A0009);
    func_L01_00518D40_004948E8(0x1A000A);
    func_L01_00518D40_004948E8(0x1A000B);
    func_003E8EF0(0x1A000D, 0x3B, 0x332299DE, D_L01_001D9010_004948E8, D_L01_001D9014_004948E8, D_L01_001D9018_004948E8,
                  D_L01_001D901C_004948E8, 0.0f);
    func_003E8630(0x1A000B, 0x1A000D);
    func_003E8630(0x1A000A, 0x1A000B);
    func_003E8FE8(0x1A000F, 0, 0x8066CCFF, D_L01_001D8FD0_004948E8, D_L01_001D8FD4_004948E8 - D_L01_001D8FDC_004948E8 * 0.25f,
                  1.0f, 1.0f);
    func_L01_00516AA0_004948E8(0x1A000F, 0x40, 1);
    func_003E8FE8(0x1A0010, 0, 0x8066CCFF, D_L01_001D8FD0_004948E8, D_L01_001D8FD4_004948E8 + D_L01_001D8FDC_004948E8 * 0.25f,
                  1.0f, 1.0f);
    func_L01_00516AA0_004948E8(0x1A0010, 0x40, 1);
    func_003E8898(0x1A0010, 0.39f, 0.6f);
    func_L01_00518010_004948E8(0x1A0010, 1);
    func_003E8A08(0x1A000A, 0x1A000F, 0x1A0010);
    func_003E9138(0x1A0012, 0x332299DE, 0, D_L01_001D8FE0_004948E8, D_L01_001D9020_004948E8,
                  D_L01_001D8FE8_004948E8 + 0.0234375f, 0.006667f);
    func_003E9358(0x1A0011, 0, 0x8066CCFF, D_L01_001D8FE0_004948E8, D_L01_001D8FE4_004948E8, D_L01_001D8FE8_004948E8,
                  D_L01_001D8FEC_004948E8, 1.0f);
    func_003E7F20(0x1A0011, 1);
    func_L01_00517BF8_004948E8(0x1A0011, 1, 1, 0, 0, 1);
    func_L01_00517DB8_004948E8(0x1A0011, 0x28, 0, 0.0005f);
    func_L01_00516AA0_004948E8(0x1A0011, 0x40, 1);
    func_003E8A08(0x1A000A, 0x1A0012, 0x1A0011);
    func_003E9138(0x1A0014, 0x80808080, 0, D_L01_001D8FF0_004948E8, D_L01_001D8FF4_004948E8, D_L01_001D8FF8_004948E8,
                  D_L01_001D8FFC_004948E8);
    func_003E8630(0x1A000A, 0x1A0014);
    func_L01_00518D40_004948E8(0x1A0013);
    func_L01_004945B8_004948E8(0x1A0013, D_L01_001D9000_004948E8);
    func_003E8630(0x1A000A, 0x1A0013);
    func_003E8348(0xE, 0x1A000A);
    func_L01_00494748_004948E8();
    buf = func_003BB3A8(1);
    size = func_003BB530(buf);
    D_L01_001D8F90_004948E8 = buf;
    D_L01_001D8F94_004948E8 = (buf + size / 2 + 0xF) & 0xFFFFFFF0;
    func_003B4528(func_003B42F8(0), D_L01_001D8F94_004948E8, D_L01_001D8F90_004948E8,
                  D_00160C40.f4954, (s32)D_00160C40.f6878);
    q = &D_L01_001E15E0_004948E8;
    if (q->f4 != 0) {
        base = q;
    } else {
        base = func_003E6C08(q);
    }
    o = (O_4948E8_004948E8 *)func_003E6378(func_003E6DE8(base), 0x1A0014);
    if (o == 0 || o->vt->isA(o, D_L01_001DC1B0_004948E8) == 0) {
        o = 0;
    }
    o->f50 = func_003B42F8(0);
    func_003E87B8(0x1A0014, 1, 8);
}
/* localdecomp:end func_L01_004948E8 */
/* localdecomp:end func_L01_004948E8 */
