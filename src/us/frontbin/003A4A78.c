#include "common.h"

/* NTSC-U counterpart of func_003A9FC8 (frontbin). */
extern u8 D_U_001D8060;

/* localdecomp:start func_U_003A4A78 */
/* from the NTSC decomp's (OpenRAC games/rac3/ntsc) func_003A4A78 */
typedef struct { s16 n; u8 p2[4]; s16 bone; u8 p8[8]; } E_003A9FC8;
typedef struct { s16 n; u8 p2[6]; s16 h8; u8 pA[2]; f32 fC; void *e10; u8 p14[0x10]; s32 f24; } O_003A9FC8;
typedef struct { u8 p0[0xB0]; f32 fB0; f32 fB4; } S_003A9FC8;
__asm__(".extern D_U_001D8060, 1");
extern u8 D_U_001D8060;
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern S_003A9FC8 D_U_00225980_003A4A78;
extern void func_U_00388468(void *, s32);
extern void func_U_00388B68(void *);
extern void func_U_003A4860(O_003A9FC8 *, void *, f32);
extern void func_U_00388948_003A4A78(void *, long);
extern void func_U_003888F0_003A4A78(void *, void *, void *);
extern void func_U_00388698_003A4A78(void *, void *, void *);
extern void func_U_00388680_003A4A78(void *, void *, void *);

void func_U_003A4A78(O_003A9FC8 *a, f32 *ow, f32 *oh, f32 sx, f32 sy, f32 t) {
    f32 m[16];
    f32 mn[4];
    f32 mx[4];
    f32 v[4];
    f32 v2[4];
    u8 *spr;

    if (D_U_001D8060 != 0) {
        sx *= a->fC * 1.18f;
        sy *= a->fC * 1.126f;
    } else {
        sx *= a->fC;
        sy *= a->fC;
    }
    func_U_00388468(m, 0x40);
    spr = (u8 *)0x70002000;
    m[0] = ((f32)(D_001D4BC0 >> 1) / D_U_00225980_003A4A78.fB0) * sx;
    m[9] = -((f32)(D_001D4BC4 >> 1) / D_U_00225980_003A4A78.fB4) * sy;
    func_U_00388B68((void *)0x70001FC0);
    if (a->h8 != 0) {
        func_U_003A4860(a, (void *)0x70002000, t);
    }
    mn[0] = 100000.0f;
    mn[1] = 1000000.0f;
    mx[0] = -100000.0f;
    mx[1] = -1000000.0f;
    if (a->f24 == 0) {
        E_003A9FC8 *p = a->e10;
        s32 i;
        for (i = 0; i < a->n; i++) {
            func_U_00388948_003A4A78(v, *(long *)p);
            v[3] = 1.0f;
            func_U_003888F0_003A4A78(v, v, spr + p->bone * 64);
            func_U_003888F0_003A4A78(v, v, m);
            func_U_00388698_003A4A78(mn, mn, v);
            func_U_00388680_003A4A78(mx, mx, v);
            p++;
        }
    } else {
        s32 *p = a->e10;
        s32 i;
        for (i = 0; i < a->n; i++) {
            s32 j;
            ((s32 *)v)[0] = (*p << 18) >> 16;
            ((s32 *)v)[1] = (*p << 4) >> 16;
            j = *p >> 28;
            func_U_00388948_003A4A78(v2, *(long *)v);
            v2[3] = 1.0f;
            func_U_003888F0_003A4A78(v2, v2, spr + j * 64);
            func_U_003888F0_003A4A78(v2, v2, m);
            func_U_00388698_003A4A78(mn, mn, v2);
            func_U_00388680_003A4A78(mx, mx, v2);
            p++;
        }
    }
    *ow = (mx[0] - mn[0]) * 0.0625f;
    *oh = (mx[1] - mn[1]) * 0.0625f;
}
/* localdecomp:end func_U_003A4A78 */
