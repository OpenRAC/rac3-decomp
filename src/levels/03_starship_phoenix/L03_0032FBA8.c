#include "common.h"

typedef struct S_0032FD50 {
    f32 f00;
    s16 f04;
    u8 pad06;
    u8 f07;
    u8 f08;
    u8 f09;
    u8 pad0A[0x34 - 0x0A];
    u16 f34;
    s16 pad36;
    s16 f38;
    u8 pad3A[0x7F - 0x3A];
    u8 f7F;
    u8 pad80[0x98 - 0x80];
    s32 f98;
    u8 pad9C[0xD8 - 0x9C];
    s32 fD8;
} S_0032FD50;

typedef struct S_00330A58 {
    u8 pad[0xF8];
    f32 f0F8;
} S_00330A58;

/* localdecomp:start func_L03_0032FBA8 */
typedef struct S_0032FBA8b { u8 pad00[0xC8]; s32 fC8; } S_0032FBA8b;
typedef struct S_0032FBA8 { u8 pad00[0x20]; u8 f20; u8 pad21[0x68 - 0x21]; S_0032FBA8b *f68; } S_0032FBA8;
s32 func_L03_0032FBA8(S_0032FBA8 *a) {
    S_0032FBA8b *p = a->f68;
    if (a->f20 == 9) {
        return -1;
    }
    return p->fC8;
}
/* localdecomp:end func_L03_0032FBA8 */

INCLUDE_ASM("asm/levels", func_L03_0032FBC8);

/* localdecomp:start func_L03_0032FD50 */
extern void *func_L01_0045B958(void *);
extern void *func_00382348(void *);
extern void *func_L01_00448FF0(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L03_0032F600(void *);
extern void *func_L03_0032F6A8(void *);
extern void func_L03_0032DA08(void *);
extern void func_L03_0032D640(s32, void *);

void func_L03_0032FD50(S_0032FD50 *p) {
    void *u;
    S_0032FD50 *r;
    S_0032FD50 *s;

    p->f7F = 0;
    ((S_0032FD50 *)func_L01_0045B958(p))->fD8 = -1;
    r = func_00382348(p);
    r->f00 = (f32)r->f04;
    s = func_L01_00448FF0(p);
    s->f38 = 0;
    s->f07 = 0;
    s->f09 = 0;
    s->f08 = 0;
    p->f98 = 0;
    p->f34 = (p->f34 | 0x41) & 0xEFFF;
    func_L01_004AA7E8(p, 1);
    p->f34 = p->f34 | 6;
    func_L03_0032F600(p);
    u = func_L03_0032F6A8(p);
    func_L03_0032DA08(p);
    func_L03_0032D640(((s32 *)u)[0], p);
}
/* localdecomp:end func_L03_0032FD50 */

INCLUDE_ASM("asm/levels", func_L03_0032FE10);

INCLUDE_ASM("asm/levels", func_L03_0032FE70);

INCLUDE_ASM("asm/levels", func_L03_003300A0);

INCLUDE_ASM("asm/levels", func_L03_00330140);

INCLUDE_ASM("asm/levels", func_L03_003302D0);

/* localdecomp:start func_L03_00330380 */
extern u8 D_L03_002AE4D0[];
extern u8 D_L03_001DD150[];
extern u8 D_L03_001DD158[];
extern u8 D_L03_001E1218[4];
extern u8 D_L03_001E1228[4];
extern s32 func_00381FF0(s32);
extern void func_L03_0032FAB8(s32, s32 *, s32 *);
extern void func_0011B2E8();

void func_L03_00330380(u8 *arg0) {
    s32 a;
    s32 b;
    u8 *s1;
    u8 *p;

    s1 = *(u8 **)(arg0 + 0x68);
    p = D_L03_002AE4D0 + s1[0xF1] * 0x28;
    func_0011B2E8(D_L03_001E1218, D_L03_001DD150, s1[0xF0] + 1, *(s16 *)p);
    if (*(s32 *)(p + 0x14) != -1) {
        func_L03_0032FAB8(*(s32 *)(s1 + 0xEC), &a, &b);
        func_0011B2E8(D_L03_001E1228, D_L03_001DD158, a, b);
    } else {
        func_0011B2E8(D_L03_001E1228, func_00381FF0(0x1921));
    }
}
/* localdecomp:end func_L03_00330380 */

INCLUDE_ASM("asm/levels", func_L03_00330438);

INCLUDE_ASM("asm/levels", func_L03_00330530);

INCLUDE_ASM("asm/levels", func_L03_003307D0);

/* localdecomp:start func_L03_00330A58 */
extern void func_L03_00330B18(void *p, s32 n, f32 a, f32 b);

void func_L03_00330A58(void *arg0) {
    u8 *q;
    f32 x;
    f32 y;
    f32 t;

    q = *(u8 **)((u8 *)arg0 + 0x68);
    if (1.0f < ((S_00330A58 *)q)->f0F8) {
        x = 6.0f;
    } else {
        x = ((S_00330A58 *)q)->f0F8 * 6.0f;
    }
    t = 2.0f - ((S_00330A58 *)q)->f0F8;
    if (1.0f < t) {
        y = 1.0f;
    } else {
        y = t;
    }
    func_L03_00330B18(arg0, 0, x, y);
    func_L03_00330B18(arg0, 1, x, y);
}
/* localdecomp:end func_L03_00330A58 */

INCLUDE_ASM("asm/levels", func_L03_00330B18);

INCLUDE_ASM("asm/levels", func_L03_00330CD0);

INCLUDE_ASM("asm/levels", func_L03_00330DC0);

INCLUDE_ASM("asm/levels", func_L03_00330EC8);
