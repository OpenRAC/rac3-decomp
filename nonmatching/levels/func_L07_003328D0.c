/* near miss (level 7, Annihilation Nation): 11 differences: the three hoisted table addresses are built in another order and other registers (retail 0x2B first, in the beqz delay slot); tried locals, pointer walks and temporaries (8 wordings) */
#include "common.h"

/* localdecomp:start func_L07_003328D0 */
typedef struct { s32 idx; s32 x; } E_003328D0;
extern E_003328D0 D_L07_002B0EB0[];
extern s32 D_L07_001E0CD0[];
extern s32 D_001427F0[];
void func_L07_003328D0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 i;
    if (p[0xBF] != 0) {
        for (i = 0; i < 16; i++) {
            s32 k = D_L07_002B0EB0[i].idx;
            D_001427F0[k] = D_L07_001E0CD0[i];
        }
        p[0xBF] = 0;
    }
}
/* localdecomp:end func_L07_003328D0 */
