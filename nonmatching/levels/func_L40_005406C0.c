/* PAL near miss (Codex wave 6): near miss: 9 words differ with the file's flags.
 * Worker's note: Best 9 word diff, 124 vs 128 bytes; w279/func_L40_005406C0.base.log. Missing intermediate return-value move and sltu destination differs. Inline local return and all-long return forms identical; mixed long/s32 emits extra sign-extension, not retail.
 */
#include "common.h"
/* localdecomp:start func_L40_005406C0 */
extern s32 D_001DE2E4_sda;
static __inline__ s32 active_005406C0(u8 *p) {
    extern s32 func_L40_005416F0(u8 *);
    return func_L40_005416F0(p) != 0;
}
static __inline__ s32 test_005406C0(s32 id) {
    extern u8 *func_L39_0061D7B0(s32);
    extern s32 func_L40_005416F0(u8 *);
    u8 *p = func_L39_0061D7B0(id);
    return p != 0 && func_L40_005416F0(p) != 0;
}
s32 func_L40_005406C0(s32 id) {
    extern u8 *func_L39_0061D7B0(s32);
    extern s32 func_L40_005416F0(u8 *);
    u8 *p = func_L39_0061D7B0(id);
    if (p != 0 && (p[3] & 15) == 7 && p[0x2C] != 0)
        return *(s32 *)(p + 4) == D_001DE2E4_sda;
    return test_005406C0(id);
}
/* localdecomp:end func_L40_005406C0 */
