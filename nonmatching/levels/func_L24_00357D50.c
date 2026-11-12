/* func_L24_00357D50: 31 differences reported (level 24, file L24_00356100.c, -mvu0-use-vf0-vf2 @ps2as), which are one
   shifted instruction pair: every instruction of the 4-iteration spark loop matches except the last argument of
   func_L01_0046B458. Retail computes `r ? r : r - 1` as `move $v1,$v0; addiu $t0,$v1,-1; movn $t0,$v0,$v1` (a second
   pseudo for the same value), this C gives `addiu $t0,$zero,-1; movn $t0,$v0,$v0`. `r ? r : -1`, `r - 1`, a copy `q = r`
   and `r == 0 ? -1 : r` all give the same wrong form. The file needed -mvu0-use-vf0-vf2 for include/vu0.h's vec_add_ab
   (flag change kept the six C functions already in it matching; not committed with this near miss). */
#include "common.h"
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_L24_00357D50(u8 *obj) {
    f32 d[4];
    f32 a[4];
    f32 c[4];
    f32 f;
    s32 n;
    s32 r;

    n = 3;
    do {
        func_003C2F58(obj, 7, a);
        n--;
        a[0] += func_003824E0(-0.15f, 0.15f);
        a[1] += func_003824E0(-0.15f, 0.15f);
        a[2] += func_003824E0(-0.15f, 0.15f);
        *(vu0_q *)c = *(vu0_q *)(obj + 0xC0);
        func_0038CF68(c, c, 0.5f);
        vec_add_ab(a, a, c);
        *(vu0_q *)d = *(vu0_q *)(obj + 0xC0);
        d[0] += func_003824E0(-0.07f, 0.07f);
        d[1] += func_003824E0(-0.07f, 0.07f);
        d[2] += func_003824E0(0.0f, 0.3f);
        func_0038CF68(d, d, func_003824E0(0.05f, 0.2f));
        f = func_003824E0(0.15f, 0.3f);
        r = func_00382468(2);
        func_L01_0046B458(a, 0x96, 0x7F007FFF, 0, r != 0 ? r : -1, d, f * 0.1f, f, 0.0028800003f, 0);
    } while (n >= 0);
}
