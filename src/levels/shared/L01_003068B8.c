#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003068B8);

INCLUDE_ASM("asm/levels", func_L01_00306A98);

/* localdecomp:start func_L01_00307058 */
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    f32 r[4][4];
    f32 rot[4];
} S_35A8A0;

extern void func_L01_00305C50(S_35A8A0 *);
extern long func_00389598(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern void func_0038D328(f32 *, f32 *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_003D2DA0(S_35A8A0 *, f32 *, s32);

void func_L01_00307058(s32 unused, f32 *pos, f32 *dir, s32 color, f32 scale) {
    S_35A8A0 s;

    func_L01_00305C50(&s);
    s.x50 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.x54 = 0;
    s.x58 = 0;
    s.x64 = 0;
    s.x78 = func_00389598(11);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x70 = 0;
    s.c4C = color;
    s.c48 = color;
    s.c44 = color;
    s.c40 = color;
    s.rot[3] = 0.0f;
    s.rot[2] = func_0038D160(dir[0], dir[1]);
    s.rot[1] = -func_0038D160(func_0038CED8(dir), dir[2]);
    s.rot[0] = 0.0f;
    func_0038D328(s.r[0], s.rot);
    s.r[3][3] = 1.0f;
    s.r[3][0] = pos[0];
    s.r[3][1] = pos[1];
    s.r[3][2] = pos[2];
    func_0038CE20(s.m[0], s.m[0], scale);
    func_0038CE20(s.m[1], s.m[1], scale);
    func_0038CE20(s.m[2], s.m[2], scale);
    func_0038CE20(s.m[3], s.m[3], scale);
    func_003D2DA0(&s, s.r[0], 0);
}
/* localdecomp:end func_L01_00307058 */

INCLUDE_ASM("asm/levels", func_L01_003071C8);

INCLUDE_ASM("asm/levels", func_L01_00307858);

INCLUDE_ASM("asm/levels", func_L01_00308238);

INCLUDE_ASM("asm/levels", func_L01_003082D0);

/* localdecomp:start func_L01_003083E8 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_003083E8(s32 a0, f32 *e, s32 n)
{
    s32 i;
    f32 *p;

    for (i = 0; i < n; i++) {
        p = &e[i * 32];
        p[0] = func_0038DAB8(p[0], p[3]);
        p[1] = func_0038DAB8(p[1], p[4]);
        p[2] = func_0038DAB8(p[2], p[5]);
        p[9] = func_0038DAB8(p[9], p[12]);
        p[10] = func_0038DAB8(p[10], p[13]);
        p[11] = func_0038DAB8(p[11], p[14]);
        p[20] = func_0038D098(p[0]) * p[6];
        p[21] = func_0038D0B0(p[1]) * p[7];
        p[22] = -func_0038D0B0(p[2]) * p[8];
        p[24] = func_0038D098(p[9]) * p[15];
        p[25] = func_0038D0B0(p[10]) * p[16];
        p[26] = -func_0038D0B0(p[11]) * p[17];
    }
}
/* localdecomp:end func_L01_003083E8 */

INCLUDE_ASM("asm/levels", func_L01_00308508);

LINKER_REMNANT("asm/levels", func_L01_003086C8);

INCLUDE_ASM("asm/levels", func_L01_003086D0);

INCLUDE_ASM("asm/levels", func_L01_00308808);

/* localdecomp:start func_L01_00308848 */
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(s32, s32, s32, s32, f32, f32, f32);

void func_L01_00308848(s32 unused, s32 target, u32 color, s32 n, f32 scale) {
    f32 size;
    color |= func_00382498(n >> 1, n) << 24;
    size = func_003824E0(scale * 0.75f, scale);
    size = size + size;
    func_003D9508(target, 44, color, 1, size, 0.08f, func_00382538());
}
/* localdecomp:end func_L01_00308848 */

INCLUDE_ASM("asm/levels", func_L01_003088D8);

/* localdecomp:start func_L01_00308D50 */
typedef struct {
    f32 v[4][4];
    u8 pad40[0x10];
    f32 w[4][2];
    unsigned long d70;
    u8 pad78[8];
    unsigned long d80;
} Obj317488;

void func_L01_00308D50(Obj317488 *o) {
    o->d80 = 0xFF9000000260;
    o->d70 = 0;
    o->w[0][0] = 0;
    o->w[1][0] = 0;
    o->w[2][0] = 1.0f;
    o->w[3][0] = 1.0f;
    o->w[0][1] = 0;
    o->w[1][1] = 1.0f;
    o->w[2][1] = 0;
    o->w[3][1] = 1.0f;
    o->v[0][2] = -2.0f;
    o->v[1][2] = 2.0f;
    o->v[2][2] = -2.0f;
    o->v[3][2] = 2.0f;
    o->v[0][1] = -2.0f;
    o->v[1][1] = -2.0f;
    o->v[2][1] = 2.0f;
    o->v[3][1] = 2.0f;
    o->v[0][0] = 0;
    o->v[1][0] = 0;
    o->v[2][0] = 0;
    o->v[3][0] = 0;
    o->v[0][3] = 1.0f;
    o->v[1][3] = 1.0f;
    o->v[2][3] = 1.0f;
    o->v[3][3] = 1.0f;
}
/* localdecomp:end func_L01_00308D50 */

INCLUDE_ASM("asm/levels", func_L01_00308DE0);

INCLUDE_ASM("asm/levels", func_L01_00308E88);

INCLUDE_ASM("asm/levels", func_L01_003090E0);

INCLUDE_ASM("asm/levels", func_L01_003091A8);

INCLUDE_ASM("asm/levels", func_L01_003094A0);

/* localdecomp:start func_L01_00309628 */
extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_003F2A50(s32, s32);
extern void func_L01_003F2AF8(s32, s32);
extern void func_L01_003094A0(u8 *);

void func_L01_00309628(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 104);
    if (func_00382380(D_001A4C60, p[0], 0) != 0 && p[10] == 0) {
        if (func_L01_00445AD0(p[16], -1, 0) != 0) {
            p[11] = func_L01_003F2A50(0, 5);
            p[10] = 1;
            func_L01_003094A0(a0);
            return;
        }
    }
    if (p[10] != 0) {
        if (func_00382380(D_001A4C60, p[0], 0) == 0 || func_L01_00445AD0(p[16], -1, 0) == 0) {
            func_L01_003F2AF8(0, p[11]);
            p[10] = 0;
        }
    }
}
/* localdecomp:end func_L01_00309628 */

INCLUDE_ASM("asm/levels", func_L01_00309708);

/* localdecomp:start func_L01_00309B70 */
void func_L01_00309B70(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_00309B70 */

INCLUDE_ASM("asm/levels", func_L01_00309B80);

INCLUDE_ASM("asm/levels", func_L01_00309D28);

INCLUDE_ASM("asm/levels", func_L01_0030A130);

/* localdecomp:start func_L01_0030A140 */
typedef struct {
    u8 pad0[140];
    s32 a;
    u8 pad1[16];
} A00309EA0;

typedef struct {
    u8 pad0[160];
    s32 a;
    u8 pad1[12];
} B00309EA0;

extern A00309EA0 D_L01_0026FD30[30];
extern B00309EA0 D_L01_00270FF0[16];
extern s32 D_L01_001DC630;

void func_L01_0030A140(void) {
    s32 i;
    for (i = 29; i >= 0; i--) {
        D_L01_0026FD30[i].a = 0;
    }
    for (i = 15; i >= 0; i--) {
        D_L01_00270FF0[i].a = 0;
    }
    D_L01_001DC630 = 0;
}
/* localdecomp:end func_L01_0030A140 */

/* localdecomp:start func_L01_0030A198 */
extern void func_003D9508(s32, s32, s32, s32, f32, f32, f32);
extern void func_003A9440(int, long);
extern int func_00382498(int, int);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_L01_0030AA38(void *);
extern void func_L01_0030B818(void *);

void func_L01_0030A198(u8 *m) {
    u8 *p = *(u8 **)(m + 104);

    func_003A9440(71, 0x53001);
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 44, (func_00382498(128, 200) << 24) | 0x72FF, 1,
                  func_003824E0(0.38500002f, 0.415f) * *(f32 *)(p + 76), -0.01f, func_00382538());
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 45, (func_00382498(4, 40) << 24) | 0xDDB973, 1,
                  *(f32 *)(p + 76) * 1.225f, 0.0f, func_00382538());
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 41, (func_00382498(4, 40) << 24) | 0xDDB973, 1,
                  *(f32 *)(p + 76) * 0.6f, 0.0f, func_00382538());
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 42, (func_00382498(4, 45) << 24) | 0xDDB973, 1,
                  func_003824E0(0.975f, 1.025f) * *(f32 *)(p + 76), 0.0f, func_00382538());
    ((void (*)(void *, int, int, int, f32, f32, f32))func_003D9508)(m + 16, 42, (func_00382498(4, 45) << 24) | 0xDDB973, 1,
                  func_003824E0(0.975f, 1.025f) * *(f32 *)(p + 76), 0.0f, func_00382538());
    func_L01_0030AA38(m);
    func_L01_0030B818(m);
    func_003A9440(71, 0x5360B);
}
/* localdecomp:end func_L01_0030A198 */

INCLUDE_ASM("asm/levels", func_L01_0030A3E8);

INCLUDE_ASM("asm/levels", func_L01_0030A670);

INCLUDE_ASM("asm/levels", func_L01_0030AA38);

/* localdecomp:start func_L01_0030AB70 */
void func_L01_0030AB70(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0030AB70 */

INCLUDE_ASM("asm/levels", func_L01_0030ABF8);

INCLUDE_ASM("asm/levels", func_L01_0030AD10);

INCLUDE_ASM("asm/levels", func_L01_0030AED8);

INCLUDE_ASM("asm/levels", func_L01_0030AF18);

INCLUDE_ASM("asm/levels", func_L01_0030B400);

INCLUDE_ASM("asm/levels", func_L01_0030B670);

INCLUDE_ASM("asm/levels", func_L01_0030B818);

INCLUDE_ASM("asm/levels", func_L01_0030B880);

INCLUDE_ASM("asm/levels", func_L01_0030B9C8);

INCLUDE_ASM("asm/levels", func_L01_0030BF20);

INCLUDE_ASM("asm/levels", func_L01_0030C1B8);

/* localdecomp:start func_L01_0030C860 */
void func_L01_0030C860(u8 *a) {
    a[32] = 4;
}
/* localdecomp:end func_L01_0030C860 */

LINKER_REMNANT("asm/levels", func_L01_0030C870);

INCLUDE_ASM("asm/levels", func_L01_0030C878);

INCLUDE_ASM("asm/levels", func_L01_0030CB20);

/* localdecomp:start func_L01_0030CEB8 */
extern u8 *D_L01_001E1724;
extern void func_L01_0030DF88(u8 *, u8 *);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_0030DAD0(u8 *, s32, s32, s32, s32, f32, f32);

void func_L01_0030CEB8(u8 *m) {
    s32 off = 0;
    s32 i = 11;
    u8 *e;
    s32 a;

    do {
        e = (u8 *)(off + (s32)D_L01_001E1724);
        i--;
        off += 160;
        if (*(u8 **)(e + 140) == m) {
            func_L01_0030DF88(m, e);
            if (*(s32 *)(e + 148) == 0) {
                a = func_00382498(80, 96);
                func_L01_0030DAD0(e + 48, 0x103080, a, 49, 2, 0.5f, func_00382538());
                a = func_00382498(80, 96);
                func_L01_0030DAD0(e + 48, 0xFFFFFF, a, 49, 2, 0.3f, func_00382538());
            }
        }
    } while (i >= 0);
}
/* localdecomp:end func_L01_0030CEB8 */

/* localdecomp:start func_L01_0030CFC0 */
typedef struct {
    f32 v[4];
    s32 w16;
    f32 f20;
    s32 w24;
    s32 w28;
    f32 f32_;
    s32 w36;
    f32 f40;
    f32 f44;
} S_0030CD20;
extern S_0030CD20 *D_L01_001E1720;
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
void func_L01_0030CFC0(s32 a0) {
    S_0030CD20 *p;
    s32 i;
    s32 v;
    for (i = 0; i < 64; i++) {
        p = &D_L01_001E1720[i];
        if (p->w16 == 0) {
            p->v[0] = func_003824E0(-1.0f, 1.0f);
            p->v[1] = func_003824E0(-1.0f, 1.0f);
            p->v[2] = func_003824E0(-1.0f, 1.0f);
            func_0038CF68(p, p, p->f20);
            v = func_00382498(20, 50);
            p->w24 = v;
            p->w28 = v;
            p->f32_ = func_003824E0(-1.0f, 1.0f);
            p->w16 = a0;
            p->w36 = 0;
            p->f40 = (func_0013D3E0() & 1) ? -1.0f : 1.0f;
            p->f44 = 1.0f;
            p->f20 = func_003824E0(0.7f, 0.9f);
            return;
        }
    }
}
/* localdecomp:end func_L01_0030CFC0 */

INCLUDE_ASM("asm/levels", func_L01_0030D0D8);

INCLUDE_ASM("asm/levels", func_L01_0030D258);

INCLUDE_ASM("asm/levels", func_L01_0030D288);

INCLUDE_ASM("asm/levels", func_L01_0030D408);

INCLUDE_ASM("asm/levels", func_L01_0030D678);

/* localdecomp:start func_L01_0030D688 */
extern s32 D_L01_00271AF0[];
extern s32 D_L01_001DC650;
void func_L01_0030D688(void) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        D_L01_00271AF0[i * 4] = 0;
    }
    D_L01_001DC650 = 0;
}
/* localdecomp:end func_L01_0030D688 */

INCLUDE_ASM("asm/levels", func_L01_0030D6B8);

/* localdecomp:start func_L01_0030D720 */
void func_L01_0030D720(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0030D720 */

INCLUDE_ASM("asm/levels", func_L01_0030D7A8);

/* localdecomp:start func_L01_0030D8C0 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_0030D8C0(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_0030D8C0 */

/* localdecomp:start func_L01_0030D928 */
extern void func_L01_0030DAD0(u8 *, s32, s32, s32, s32, f32, f32);
extern void func_L01_0030CEB8(u8 *m);
extern void func_003A9440(int, long);
extern void func_L01_0030D288(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);

void func_L01_0030D928(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    u8 *q;
    f32 s;

    if (p == 0) {
        return;
    }
    ((void (*)(s32, unsigned long))func_003A9440)(71, 0x53001);
    ((void (*)(void *))func_L01_0030CEB8)(a0);
    func_L01_0030D288(a0);
    q = a0 + 16;
    s = *(f32 *)(p + 24);
    s *= 0.5f;
    ((void (*)(void *, s32, f32, s32, f32, s32, s32))func_L01_0030DAD0)(q, 0x103080, s, func_00382498(80, 96), func_00382538(), 49, 2);
    s = *(f32 *)(p + 24);
    s *= 0.3f;
    ((void (*)(void *, s32, f32, s32, f32, s32, s32))func_L01_0030DAD0)(q, 0xFFFFFF, s, func_00382498(80, 96), func_00382538(), 49, 2);
    s = *(f32 *)(p + 24);
    s *= 0.7f;
    ((void (*)(void *, s32, f32, s32, f32, s32, s32))func_L01_0030DAD0)(q, 0x803010, s, func_00382498(8, 22), func_00382538(), 11, 2);
    s = *(f32 *)(p + 24);
    s *= 0.45f;
    ((void (*)(void *, s32, f32, s32, f32, s32, s32))func_L01_0030DAD0)(q, 0x803010, s, func_00382498(32, 64), func_00382538(), 11, 2);
    ((void (*)(s32, unsigned long))func_003A9440)(71, 0x5360B);
}
/* localdecomp:end func_L01_0030D928 */

INCLUDE_ASM("asm/levels", func_L01_0030DAD0);

INCLUDE_ASM("asm/levels", func_L01_0030DC38);

INCLUDE_ASM("asm/levels", func_L01_0030DF88);

INCLUDE_ASM("asm/levels", func_L01_0030E158);

INCLUDE_ASM("asm/levels", func_L01_0030E198);
