/* PAL near miss (Codex wave 6): near miss: 15 words differ with the file's flags.
 * Worker's note: PAL two-array copy draft; 15 differing instruction positions from register allocation; stopped after three different wordings produced the same wrong bytes (checks 3-5); no linked build.
 */
#include "common.h"
/* localdecomp:start func_L40_00414BE0 */
extern s32 D_001DE038_sda;
typedef struct { s32 a[12]; s32 b[12]; s32 count; } Vars_00414BE0;
__asm__(".extern D_001DE038_sda, 4");
extern s32 D_L40_002496E8[12];
extern s32 D_L40_00249718[12];
void func_L40_00414BE0(u8 *self) {
    s32 i = 0;
    Vars_00414BE0 *vars = *(Vars_00414BE0 **)(self + 0x68);
    if ((D_001DE038_sda = vars->count) > 0) {
        do {
            D_L40_002496E8[i] = vars->a[i];
            D_L40_00249718[i] = vars->b[i];
            i++;
        } while (i < vars->count);
    }
}
/* localdecomp:end func_L40_00414BE0 */
