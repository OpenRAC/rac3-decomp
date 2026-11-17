/* func_L19_003BACA0: 66 diff with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division). Loop, calls and float args match; the diff is register numbering: retail keeps the table base in $s5, 0x60000000 in $s6, and two separate 0xB0 constants ($fp for p, $s7 for q), while gcc CSEs the two i*0xB0 and reuses one. Tried: base as local, p/q computed twice, struct-typed table with stride 0xB0; none moved the count. */
#include "common.h"

typedef struct { u8 pad[0xB0]; } S_L19_003BACA0;
extern S_L19_003BACA0 D_L19_002A4E30[];
extern s32 D_L19_001DE740;
extern s32 D_L19_001DE790;
extern f32 D_L19_001DE794;
extern f32 D_L19_001DE798;
extern void func_L01_0040C948(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, f32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L19_003BACA0(void) {
    s32 i;
    for (i = 0; i < 3; i++) {
        u8 *p = (u8 *)&D_L19_002A4E30[i];
        u8 *q = (u8 *)&D_L19_002A4E30[i];
        s32 j = 1;
        func_L01_0040C948(p, &D_L19_001DE740);
        do {
            f32 f20;
            f32 fA, fB, fC;
            s32 t;
            j--;
            fA = func_003824E0(0.0f, 1.0f);
            t = func_0038DBD8(*(s32 *)(p + 0x20), fA, *(s32 *)(p + 0x28)) | 0x60000000;
            fB = func_003824E0(0.75f, 1.25f);
            f20 = D_L19_001DE798 * fB;
            fC = func_00382538();
            func_003D9508(q, D_L19_001DE790, t, 1, f20, D_L19_001DE794, fC);
            q += 0x10;
        } while (j >= 0);
    }
}

INCLUDE_ASM("asm/levels", func_L19_003BACA0);
