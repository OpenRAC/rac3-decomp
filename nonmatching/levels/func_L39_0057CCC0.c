/* NTSC-U draft (Claude wave K): C of func_L39_0057BD18, the NTSC-U twin of func_L39_0057CCC0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 81 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_0057BD18", whose code is not the PAL one).
 * Worker's note: 81 diff (52 words); read n6 before the calls via pointer local; loop pointer/index split and 192-count loop shape differ
 */
#include "common.h"

/* localdecomp:start func_L39_0057BD18 */
typedef struct R_0057BD18 {
    s32 a;
    s32 b;
} R_0057BD18;

typedef struct G_0057BD18 {
    u8 pad00[4];
    s16 n4;
    s16 n6;
    s32 w8;
    s32 wC;
    R_0057BD18 B[50];
    R_0057BD18 A[1];
} G_0057BD18;

typedef struct T_0057BD18 {
    u8 pad00[0x28];
    s32 w28;
    s32 w2C;
} T_0057BD18;

extern G_0057BD18 D_L39_00480E38;
extern T_0057BD18 D_L39_0025F780;
extern u8 D_L39_0049C950[];
extern u8 D_L39_002403C8[];
extern u8 D_L39_00228880[];
extern s32 D_001A6C00[];
extern s32 D_L39_002425B4;

extern void func_00129E18(void *, s32, s32, void *, s32, void *, s32, s32, s32);
extern void func_00388550(void *, void *, s32);

void func_L39_0057BD18(void) {
    u8 buf[0x10];
    s32 i;
    s32 n;
    s32 j;
    G_0057BD18 *g = &D_L39_00480E38;

    i = g->n6;
    func_00129E18(D_L39_002403C8, 5, 0, buf, 0x10, g, 0x1A0, 0, 0);
    func_00388550(D_L39_00228880, g, 0x330);
    g->A[i].a = (s32)D_L39_0049C950;
    g->A[i].b = (s32)D_L39_0049C950 + 0xC80;
    i++;
    g->A[i].a = D_L39_0025F780.w28;
    g->A[i].b = D_L39_0025F780.w2C;
    i++;
    g->n6 = i;
    g->wC = 0;
    for (j = 0; j < g->n6; j++) {
        g->A[j].a = (g->A[j].a + 3) & ~3;
        g->A[j].b = g->A[j].b & ~3;
        g->wC += g->A[j].b - g->A[j].a;
    }
    D_L39_00480E38.w8 = 0;
    for (j = 0; j < D_L39_00480E38.n4; j++) {
        D_L39_00480E38.B[j].a = (D_L39_00480E38.B[j].a + 3) & ~3;
        D_L39_00480E38.B[j].b = D_L39_00480E38.B[j].b & ~3;
        D_L39_00480E38.w8 += D_L39_00480E38.B[j].b - D_L39_00480E38.B[j].a;
    }
    D_L39_002425B4 = 0;
    for (n = 0; n < 192; n++) {
        if (D_001A6C00[3 + n] != 0) {
            D_L39_002425B4++;
        }
    }
}
/* localdecomp:end func_L39_0057BD18 */
