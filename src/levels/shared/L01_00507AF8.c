#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00507AF8);

INCLUDE_ASM("asm/levels", func_L01_0050F368);

/* localdecomp:start func_L01_0050F3F0 */
typedef struct {
    s16 h;
    u8 b;
    u8 pad;
} E_0050B448;
extern E_0050B448 D_L01_001DBDD8;
extern E_0050B448 D_L01_001DBDC0;
extern E_0050B448 D_L01_001DBDF0;
extern s32 func_L01_004E9238(s32);
s32 func_L01_0050F3F0(s32 a0, s32 *a1) {
    E_0050B448 *p;
    p = 0;
    if (func_L01_004E9238(3) == 2) {
        p = &D_L01_001DBDD8;
    } else if (func_L01_004E9238(3) == 3) {
        p = &D_L01_001DBDC0;
    } else if (func_L01_004E9238(3) == 4) {
        p = &D_L01_001DBDF0;
    }
    if (p != 0) {
        s32 i = 0;
        while (p[i].h != -1) {
            if (a0 == p[i].b) {
                *a1 = p[i].h;
                return 1;
            }
            i++;
        }
    }
    *a1 = 0;
    return 0;
}
/* localdecomp:end func_L01_0050F3F0 */

INCLUDE_ASM("asm/levels", func_L01_0050F4C0);

INCLUDE_ASM("asm/levels", func_L01_0050F620);

/* localdecomp:start func_L01_0050F758 */
extern u8 D_001A4BE0[];
extern s32 func_L01_0050F620(s32, s32 *, s32 *);

void func_L01_0050F758(void)
{
    u8 *p = D_001A4BE0;
    s32 a[2];
    u8 *o;

    if (p[9700] == 0 && *(s32 *)(p + 4884) == 2) {
        if (func_L01_0050F620((*(u8 **)(p + 9664))[67], &a[0], &a[1])) {
            o = *(u8 **)(p + 4848);
            if (o != 0) {
                *(f32 *)(o + 72) = *(f32 *)(p + 3072);
            }
            o = *(u8 **)(p + 4852);
            if (o != 0) {
                *(f32 *)(o + 72) = *(f32 *)(p + 3072);
            }
        }
    }
}
/* localdecomp:end func_L01_0050F758 */

/* localdecomp:start func_L01_0050F7E0 */
extern u8 D_001A4BE0[];
typedef struct { u8 pad[10240]; s32 a; s32 b; } S_0050B838;
void func_L01_0050F7E0(void) {
    (*(S_0050B838 *)&D_001A4BE0).a = 0;
    (*(S_0050B838 *)&D_001A4BE0).b = 0;
}
/* localdecomp:end func_L01_0050F7E0 */

/* localdecomp:start func_L01_0050F7F8 */
typedef struct {
    s16 key;
    s16 val;
} S_50B850;

extern S_50B850 *D_001A73E4[];

s32 func_L01_0050F7F8(s32 key, s32 *out) {
    S_50B850 *p = D_001A73E4[0];
    s32 i;
    if (p == 0) {
        return 0;
    }
    for (i = 0; p[i].key != -1; i++) {
        if (key == p[i].key) {
            *out = p[i].val;
            return 1;
        }
    }
    *out = 0;
    return 0;
}
/* localdecomp:end func_L01_0050F7F8 */

INCLUDE_ASM("asm/levels", func_L01_0050F858);

/* localdecomp:start func_L01_0050F8F0 */
extern s32 func_L01_0050F7F8(s32 key, s32 *out);
extern u8 D_001A4BE0[];
typedef struct {
    u8 pad0[3072];
    f32 f3072;
    u8 pad1[9664 - 3076];
    u8 *p9664;
    u8 pad2[10240 - 9668];
    u8 *p10240;
    s32 f10244;
} S_1A4BE0;


void func_L01_0050F8F0(void) {
    u8 buf[16];
    S_1A4BE0 *s = &(*(S_1A4BE0 *)&D_001A4BE0);
    if (s->p10240 != 0 && s->f10244 != 0) {
        if (((s32 (*)(s32, void *))func_L01_0050F7F8)(s->p9664[67], buf) != 0) {
            *(f32 *)(s->p10240 + 72) = s->f3072;
        }
    }
}
/* localdecomp:end func_L01_0050F8F0 */

INCLUDE_ASM("asm/levels", func_L01_0050F950);
