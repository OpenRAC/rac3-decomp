/* PAL near miss (nm/b8-s6): 3 diff words in check.py at level 01. the second func_0038DAB8 call's $gp load (D_001DE4AC_sda) is scheduled after the first result's store in C but before it in retail. Needs the file flag -mvu0-use-vf0-vf2 (already set) and the file's declaration of func_L01_003ADFC0 changed to (u8 *) with the call passing o (func_L01_003ADEC8 still matches); the level 03 place is not checked
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_003ADFC0 */
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_003AE1A0(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
__asm__(".extern D_001DE4A8_sda, 4");
__asm__(".extern D_001DE4AC_sda, 4");
__asm__(".extern D_001DE4A4_sda, 4");
extern f32 D_001DE4A8_sda;
extern f32 D_001DE4AC_sda;
extern s32 D_001DE4A4_sda;
void func_L01_003ADFC0(u8 *m) {
    vu0_q v;
    u8 *pv;
    pv = *(u8 **)(m + 104);
    v = *(vu0_q *)(m + 16);
    vec_add_ba(m + 16, pv, m + 16);
    {
    f32 t = D_001DE4A8_sda * 0.0174532924f * 0.0200000014f;
    *(f32 *)(pv + 8) -= 0.00392000005f;
    *(f32 *)(m + 244) = func_0038DAB8(*(f32 *)(m + 244), t);
    }
    {
    f32 u = D_001DE4AC_sda * 0.0174532924f * 0.0200000014f;
    *(f32 *)(m + 248) = func_0038DAB8(*(f32 *)(m + 248), u);
    }
    if (func_0038CAD0(pv + 20) || func_003D3CB0(&v, m + 16, 0, 0, 0)) {
        func_L01_003AE1A0(m);
        *(s32 *)(pv + 20) = (D_001DE4A4_sda * 5 + 2) / 6;
        func_L01_004450F0(m, 2, -1);
    }
}
/* localdecomp:end func_L01_003ADFC0 */
