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

INCLUDE_ASM("asm/levels", func_L01_004561B8);

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

INCLUDE_ASM("asm/levels", func_L01_00456500);

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

INCLUDE_ASM("asm/levels", func_L01_00456B40);

LINKER_REMNANT("asm/levels", func_L01_00456BC8);

INCLUDE_ASM("asm/levels", func_L01_00456BD0);

INCLUDE_ASM("asm/levels", func_L01_00456C20);

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

INCLUDE_ASM("asm/levels", func_L01_00457458);

INCLUDE_ASM("asm/levels", func_L01_00457480);

INCLUDE_ASM("asm/levels", func_L01_004574B0);

INCLUDE_ASM("asm/levels", func_L01_004574E0);

INCLUDE_ASM("asm/levels", func_L01_00457528);

INCLUDE_ASM("asm/levels", func_L01_00457558);

INCLUDE_ASM("asm/levels", func_L01_00457588);

LINKER_REMNANT("asm/levels", func_L01_00457628);

INCLUDE_ASM("asm/levels", func_L01_00457638);

LINKER_REMNANT("asm/levels", func_L01_00457730);
