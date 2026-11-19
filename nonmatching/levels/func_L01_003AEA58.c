/* PAL near miss (nm/b8-s6): 4 diff words in check.py at level 01. only the registers of the 3rd and 4th arguments are swapped (retail keeps the int in s2 and the quad pointer in s3), plus the two lq/sq pairs' order; the 64-bit copy needs long, not u128_t. Level 03 place not checked
 */
#include "common.h"
/* localdecomp:start func_L01_003AEA58 */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(u8 *a0, u8 *a1);
u8 *func_L01_003AEA58(u8 *par, u128_t *a5, u128_t *a6, s32 a7, f32 f12) {
    u8 *m;
    u8 *pv;
    m = func_003C24B0(6543, 128);
    if (m != 0) {
        m[48] = 255;
        if (par != 0)
            *(u16 *)(m + 50) = *(u16 *)(par + 50);
        else
            *(u16 *)(m + 50) = 255;
        m[32] = 0;
        m[49] = 1;
        if (par != 0)
            *(long *)(m + 56) = *(long *)(par + 56);
        *(u128_t *)(m + 16) = *a6;
        pv = *(u8 **)(m + 104);
        *(u128_t *)pv = *a5;
        *(f32 *)(pv + 20) = f12;
        *(u8 **)(pv + 16) = par;
        *(u16 *)(m + 52) |= 520;
        *(f32 *)(pv + 12) = (f32)a7;
        *(s32 *)(m + 240) = 0;
        *(s32 *)(m + 248) = 0;
        if (par != 0) {
            *(u128_t *)(m + 240) = *(u128_t *)(par + 240);
            func_0038D308(m + 192, m + 240);
        }
        *(u16 *)(m + 52) |= 256;
        m[35] = 128;
        *(s32 *)(pv + 24) = 0;
    }
    return m;
}
/* localdecomp:end func_L01_003AEA58 */
