#include "common.h"

typedef int u128_452E70 __attribute__((mode(TI)));
typedef struct Obj_452E70 {
    u8 pad0[16];
    u128_452E70 q10;
    u8 pad20[16];
    u8 b30;
    u8 b31;
    u16 h32;
    u8 pad34[4];
    unsigned long d38;
    u8 pad40[120];
    struct Obj_452E70 *pB8;
    u8 padBC[52];
    u128_452E70 qF0;
} Obj_452E70;
typedef struct { u8 pad[190]; u8 flags; } S452;
typedef struct {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    u8 pad18[0xAA - 0x18];
    s16 h170;
    u8 padAC[0xF8 - 0xAC];
    f32 f248;
} M_453408;
typedef struct {
    u8 pad0[0x2F];
    u8 b47;
} V_453408;

typedef struct {
    u8 pad0[0x10];
    s16 n10;
    s16 n12;
    s16 n14;
    s16 n16;
    u8 pad18[4];
    s32 *list1C;
    s32 *list20;
    s32 *list24;
    s32 *list28;
} Rec_00456500;

INCLUDE_ASM("asm/levels", func_L01_00454728);

INCLUDE_ASM("asm/levels", func_L01_00455550);

INCLUDE_ASM("asm/levels", func_L01_00455E18);

LINKER_REMNANT("asm/levels", func_L01_00456130);

/* localdecomp:start func_L01_00456160 */
extern void func_003C7C38(Obj_452E70 *);
void func_L01_00456160(Obj_452E70 *a0, Obj_452E70 *a1) {
    a0->b30 = 255;
    a0->h32 = 255;
    a0->b31 = 1;
    if (a1 != 0) {
        a0->pB8 = a1;
        a0->q10 = a1->q10;
        a0->qF0 = a1->qF0;
        a0->d38 = a1->d38;
        func_003C7C38(a0);
    }
}
/* localdecomp:end func_L01_00456160 */

/* localdecomp:start func_L01_004561B8 */
/* from rac2-decomp's func_002B3868, renamed */
s32 func_L01_004561B8(u8 *a0) {
 u8 flags=a0[0xbe];
 if(((flags^1)&1)!=0) {a0[0xbe]=flags|1;return 1;}
 return 0;
}
/* localdecomp:end func_L01_004561B8 */

/* localdecomp:start func_L01_004561E0 */
int func_L01_004561E0(unsigned char *a0)
{
    if (!(a0[190] & 2)) {
        a0[190] |= 2;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004561E0 */

/* localdecomp:start func_L01_00456208 */
int func_L01_00456208(unsigned char *a0)
{
    if (!(a0[190] & 0x20)) {
        a0[190] |= 0x20;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00456208 */

/* localdecomp:start func_L01_00456230 */
void func_L01_00456230(S452 *p, s32 on) {
    if (on) p->flags |= 4;
    else p->flags &= ~4;
}
/* localdecomp:end func_L01_00456230 */

/* localdecomp:start func_L01_00456250 */
s32 func_L01_00456250(u8 *a0) {
    return a0[190] & 4;
}
/* localdecomp:end func_L01_00456250 */

LINKER_REMNANT("asm/levels", func_L01_00456268);

INCLUDE_ASM("asm/levels", func_L01_00456270);

/* localdecomp:start func_L01_00456500 */
extern char *D_L01_001DFC4C;
extern s32 *D_L01_0021F6C0[];
extern s32 func_L01_0040E590(void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_0044C078(void *, s32);
extern s32 func_L01_0044BFC8(void *, s32);
extern s32 func_L01_004463F8(void *, s32 *, s32);

s32 func_L01_00456500(void *pos, s32 index) {
    char *base;
    Rec_00456500 *rec;
    s32 off;
    s32 i;
    s32 *p;

    if (index < 0)
        return 0;
    base = D_L01_001DFC4C;
    if (index >= *(s32 *)base)
        return 0;
    off = index * 0x30 + 0x20;
    if (func_L01_0040E590(pos, base + off) == 0)
        return 0;
    rec = (Rec_00456500 *)(D_L01_001DFC4C + off);
    for (i = 0; i < rec->n12; i++) {
        if (func_00382380(pos, rec->list20[i], 0) != 0)
            return 1;
    }
    for (i = 0; i < rec->n14; i++) {
        if (func_L01_0044C078(pos, rec->list24[i]) != 0)
            return 1;
    }
    for (i = 0; i < rec->n16; i++) {
        if (func_L01_0044BFC8(pos, rec->list28[i]) != 0)
            return 1;
    }
    for (i = 0; i < rec->n10; i++) {
        p = D_L01_0021F6C0[rec->list1C[i]];
        if (func_L01_004463F8(pos, p + 4, *p) != 0)
            return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00456500 */

INCLUDE_ASM("asm/levels", func_L01_004566A8);

/* localdecomp:start func_L01_004566F8 */


extern s32 D_L01_001D673C_004566F8;
extern M_453408 *D_001A71A0[];
extern f32 func_0038CF38(void *a, void *b);
extern f32 func_0038CF00(void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_0038DBA0(f32 a, f32 b);
extern V_453408 *func_00382348(M_453408 *m);
extern s32 func_003D3CB0(void *a, void *b, s32 c, M_453408 *m, s32 e);

f32 func_L01_004566F8(M_453408 *a, M_453408 *b, s32 c, s32 d, s32 e, s32 g, f32 scale) {
    f32 dist;
    f32 r;
    V_453408 *v;

    r = func_0038CF38(&a->x, &b->x);
    if (D_L01_001D673C_004566F8 != 0) {
        r = func_0038CF00(&a->x, &b->x);
    }
    dist = r;
    if (D_L01_001D673C_004566F8 == 0) {
        dist += func_0038DBA0(func_0038D160(b->x - a->x, b->y - a->y), a->f248) * dist * scale;
    }
    if (b == D_001A71A0[0]) {
        v = func_00382348(a);
        if (c != 0) {
            dist = 9999999.0f;
        } else if ((v != 0 && v->b47 != 0) || d != 0) {
            dist = 999999.0f;
        } else {
            if (!(a->h170 >= 6503 && a->h170 <= 6505) && g == 0) {
                dist -= 20.0f;
                if (dist < 0.0f) {
                    dist = 0.0f;
                }
            }
        }
        if (a->h170 == 6598) {
            dist += 900.0f;
        }
    }
    if (e != 0 && func_003D3CB0(&a->x, &b->x, 2, a, 0) != 0) {
        dist = 999999.0f;
    }
    if (b->h170 == 6598 && a->h170 == b->h170) {
        dist += 10000.0f;
    }
    return dist;
}
/* localdecomp:end func_L01_004566F8 */

INCLUDE_ASM("asm/levels", func_L01_00456910);

/* localdecomp:start func_L01_00456B40 */
int func_L01_00456B40(u8 *p, u8 *q, f32 f12, f32 f13) {
    f32 v = func_0038CF38(q, p + 0x10);
    s32 r = 1;

    if (!(v < f12)) {
        r = 0;
    } else if (!(__builtin_fabsf(*(f32 *)(q + 8) - *(f32 *)(p + 0x18)) < f13)) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L01_00456B40 */

LINKER_REMNANT("asm/levels", func_L01_00456BC8);

/* localdecomp:start func_L01_00456BD0 */
typedef void (*fn_t)(int);
extern int D_L01_001D6778[] __attribute__((section(".sdata")));
extern fn_t D_L01_001F00E8[];
extern int D_L01_001F01E8[];

/* from rac2-decomp's func_0027CDC8, renamed */
void func_L01_00456BD0(fn_t first, int second) {
    int index = D_L01_001D6778[0];
    if (index < 64) {
        D_L01_001F00E8[index] = first;
        D_L01_001F01E8[index] = second;
        D_L01_001D6778[0] = index + 1;
    }
}
/* localdecomp:end func_L01_00456BD0 */

/* localdecomp:start func_L01_00456C20 */
/* the roster: up to 64 {moby, team}, signed up each frame by enemy_roster_add */
extern s32 D_L01_001DFB40;                     /* the frame counter */
extern s32 D_L01_001D677C;                     /* the frame of the last swap */
extern s32 D_L01_001D6778_00456C20;            /* mobys signed up this frame */
extern s32 D_L01_001D6774;                     /* mobys in the roster */
extern void *D_L01_001EFFE8[];                 /* the roster's mobys */
extern void *D_L01_001F00E8_00456C20[];        /* the mobys signed up this frame */

/* enemy_roster_swap: once a frame (from the hero's update), the mobys signed up become the
 * roster the target finder reads, and signing up starts again. */
void func_L01_00456C20(void) {
    s32 signed_up;
    s32 i;

    if (D_L01_001DFB40 == D_L01_001D677C) return;
    signed_up = D_L01_001D6778_00456C20;
    D_L01_001D677C = D_L01_001DFB40;
    D_L01_001D6774 = 0;
    for (i = 0; i < signed_up; i++) {
        D_L01_001EFFE8[D_L01_001D6774] = D_L01_001F00E8_00456C20[D_L01_001D6774];
        D_L01_001D6774++;
    }
    D_L01_001D6778_00456C20 = 0;
}
/* localdecomp:end func_L01_00456C20 */

INCLUDE_ASM("asm/levels", func_L01_00456C98);

INCLUDE_ASM("asm/levels", func_L01_004572B0);

/* localdecomp:start func_L01_00457410 */
s32 func_L01_00457410(s32 n) {
    s32 a = 16;
    if (n % a != 0) {
        n = ((s32)((f32)n / (f32)a) + 1) * a;
    }
    return n;
}
/* localdecomp:end func_L01_00457410 */

/* localdecomp:start func_L01_00457458 */
typedef struct {
    int reserved;
    int value;
    char remainder[0xA428];
} Record_2B4038;
extern Record_2B4038 D_L01_002D16D0[];

/* from rac2-decomp's func_002B4038, renamed */
int func_L01_00457458(int value, int index) {
    return D_L01_002D16D0[index].value == value;
}
/* localdecomp:end func_L01_00457458 */

INCLUDE_ASM("asm/levels", func_L01_00457480);

INCLUDE_ASM("asm/levels", func_L01_004574B0);

/* localdecomp:start func_L01_004574E0 */
extern s32 D_L01_001D6780;

void func_L01_004574E0(void) {
    u8 *current = (u8 *)D_L01_002D16D0;
    u8 *end = current + 0x14860;

    D_L01_001D6780 = 0;
    do {
        *(s32 *)(current + 4) = -1;
        *(s32 *)current = 0;
        current += 0xA430;
    } while ((s32)current < (s32)end);
}
/* localdecomp:end func_L01_004574E0 */

INCLUDE_ASM("asm/levels", func_L01_00457528);

INCLUDE_ASM("asm/levels", func_L01_00457558);

INCLUDE_ASM("asm/levels", func_L01_00457588);

LINKER_REMNANT("asm/levels", func_L01_00457628);

INCLUDE_ASM("asm/levels", func_L01_00457638);

LINKER_REMNANT("asm/levels", func_L01_00457730);
