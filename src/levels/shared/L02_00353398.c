#include "common.h"

typedef struct S_L02_003532F0 {
    f32 x;
    f32 y;
    u8 pad08[0xC];
    s32 state;
    f32 t18;
    f32 t1C;
} S_L02_003532F0;
typedef struct T_L02_003532F0 {
    f32 thr;
    f32 pad[6];
} T_L02_003532F0;
typedef struct O_L02_003532F0 {
    u8 pad00[0x20];
    s32 count;
    u8 pad24[0xC];
    f32 vx;
    f32 vy;
} O_L02_003532F0;

typedef struct B_L02_00352C80 {
    s32 id;
    u8 pad04[0x1C];
    s32 cnt20;
    s32 a24;
    s32 a28;
    s32 r2C;
    u8 pad30[0x10];
    s32 cnt40;
    s32 a44;
    s32 a48;
    s32 r4C;
    s32 flag50;
    f32 f54;
    f32 f58;
} B_L02_00352C80;
typedef struct A_L02_00352C80 {
    u8 pad00[0x20];
    u8 b20;
    u8 pad21[0x47];
    B_L02_00352C80 *sub;
} A_L02_00352C80;

/* declared by functions of L02_00352C80.c, which this file was cut from */
extern s32 func_00382498(s32, s32);
extern s32 func_L02_00353398(A_L02_00352C80 *, B_L02_00352C80 *);

/* localdecomp:start func_L02_00353398 */
/* from the NTSC-U draft nonmatching/levels/func_L02_00353398.c (func_L02_00352288), with PAL names */
__asm__(".extern D_L02_001DCF90, 4");
__asm__(".extern D_L02_001DCF94, 4");
__asm__(".extern D_L02_001DCF98, 4");
__asm__(".extern D_L02_001DCF9C, 4");
extern s32 D_L02_001DCF90;
extern s32 D_L02_001DCF94;
extern f32 D_L02_001DCF98;
extern f32 D_L02_001DCF9C;
extern s32 func_L02_00352F60(A_L02_00352C80 *, B_L02_00352C80 *, void *, f32);
extern void *func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382498(s32, s32);
extern void func_00382760(void *, f32, f32, f32);

s32 func_L02_00353398(A_L02_00352C80 *a0, B_L02_00352C80 *a1) {
    f32 v[4];
    f32 w[4];
    s32 r;
    f32 f21;
    f32 f20;
    void *o;

    r = func_L02_00352F60(a0, a1, v, 0.8f);
    if (r == 0) {
        return 0;
    }
    if (r == -1) {
        return 1;
    }
    f21 = func_003824E0(0.7853982f, 1.5707964f);
    f20 = func_00382538();
    func_00382760(w, func_003824E0(D_L02_001DCF98, D_L02_001DCF9C) * 0.020000001f, f20, f21);
    v[2] = v[2] + 0.1f;
    o = func_L01_002FB660(v, w, func_00382498((D_L02_001DCF90 * 5 + 2) / 6, (D_L02_001DCF94 * 5 + 2) / 6), 2, 0, 0);
    if (o != 0) {
        func_L01_0043B9E8(o, 0x7F, 0x40, 0x20);
    }
    return 1;
}
/* localdecomp:end func_L02_00353398 */

INCLUDE_ASM("asm/levels", func_L02_003534D8);
