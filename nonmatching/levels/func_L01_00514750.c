/* PAL near miss (Codex wave 6): near miss: 5 words differ with the file's flags.
 * Worker's note: Improved 6 to 5 instruction differences: inline address helper preserves separate hero-base la and +0x25F8. Remaining prologue scheduling puts previous-pointer la before fallback constant/destination addition. Loop helper, fallback parameter and address-only ...
 */
#include "common.h"
/* localdecomp:start func_L01_00514750 */
static __inline__ s32 *button_addr_00514750(D_001A4BE0_t *hero) {
    return (s32 *)((u8 *)hero + 0x25F8);
}
s32 func_L01_00514750(s32 *input) {
    s32 changed=0;
    s32 *dest=button_addr_00514750(&D_001A4BE0);
    s32 *previous=&D_001D4C40;
    s32 i;
    for(i=3;i>=0;i--) {
        if(*previous!=*input) {
            changed=1;
            *dest=*input ? *input : 0xCC;
        }
        dest++;input++;previous++;
    }
    return changed;
}
/* localdecomp:end func_L01_00514750 */
