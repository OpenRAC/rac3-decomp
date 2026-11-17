/* PAL near miss (nm/b8-s6): 0 diff words at level 01 (MATCH). MATCH at level 01 only (needs divs_nops row 'func_L01_003AE0E8 2' and the file flag -mvu0-use-vf0-vf2 is not needed); a false fold: level 03's place (0039DE58) reads other $gp slots (0x1af0, 0x1b04, 0x1b08 instead of 0x1bf0, 0x1c00, 0x1c04), so it needs a split_places.tsv row (catalogue change) before this C can land
 */
#include "common.h"
/* localdecomp:start func_L01_003AE0E8 */
extern s32 func_0038CAD0(void *);
extern void func_L01_004AAC98(s32, s32, u8 *, s32);
extern s32 func_0038DBD8(f32, s32, s32);
__asm__(".extern D_001DE4A0_sda, 4");
__asm__(".extern D_001DE4B0_sda, 4");
__asm__(".extern D_001DE4B4_sda, 4");
extern s32 D_001DE4A0_sda;
extern s32 D_001DE4B0_sda;
extern s32 D_001DE4B4_sda;
void func_L01_003AE0E8(u8 *m) {
    u8 *pv;
    pv = *(u8 **)(m + 104);
    if (func_0038CAD0(pv + 16)) {
        *(s32 *)(pv + 16) = (D_001DE4A0_sda * 5 + 2) / 6;
        func_L01_004AAC98(0, 0, m, 6496);
    }
    *(s32 *)(m + 120) = func_0038DBD8((f32)*(s32 *)(pv + 16) / (f32)((D_001DE4A0_sda * 5 + 2) / 6), D_001DE4B0_sda, D_001DE4B4_sda);
}
/* localdecomp:end func_L01_003AE0E8 */
