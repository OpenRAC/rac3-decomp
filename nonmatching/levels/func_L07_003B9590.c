/* PAL near miss (Codex wave 6): near miss: 51 words differ with the file's flags.
 * Worker's note: PAL state handler; retained check-4 source. One extra nop at offset 0xBC shifts the remainder by four bytes (51 differing positions). Checks 4-6 give the same wrong bytes; stopped after three wordings; no linked build.
 */
#include "common.h"
/* localdecomp:start func_L07_003B9590 */
typedef int Q_003B9590 __attribute__((mode(TI)));
extern Q_003B9590 D_001A4C60[];
typedef struct { s32 mask; u8 pad4[0x30-4]; s32 active[4]; s32 handle[4]; u8 pad50[0x10]; s32 gate; } Vars_003B9590;
void func_L07_003B9590(u8 *self) {
    extern void func_L07_003B98E0(void *);
    extern s32 func_00382380(void *, s32, s32);
    extern s32 func_L01_00445AD0(s32, s32, s32);
    extern s32 func_L01_003F2A50(s32, s32);
    extern void func_L07_003B96F8(void *, s32);
    extern void func_L01_003F2AF8(s32, s32);
    Q_003B9590 params = D_001A4C60[0];
    Vars_003B9590 *vars = *(Vars_003B9590 **)(self + 0x68);
    s32 i = 0;
    switch (self[0x20]) {
    case 0:
        func_L07_003B98E0(self);
        break;
    case 1:
        break;
    case 2:
        for (; i < 1; i++) {
            if (func_00382380(&params, vars->mask, 0) && vars->active[i] == 0 &&
                (vars->gate == -1 || func_L01_00445AD0(vars->gate, -1, 0))) {
                s32 handle = func_L01_003F2A50(0, 5);
                vars->active[i] = 1;
                vars->handle[i] = handle;
                func_L07_003B96F8(self, 0);
                return;
            }
            if (vars->active[i]) {
                if (!func_00382380(&params, vars->mask, 0) ||
                    (vars->gate != -1 && !func_L01_00445AD0(vars->gate, -1, 0))) {
                    func_L01_003F2AF8(0, vars->handle[i]);
                    vars->active[i] = 0;
                }
            }
            return;
        }
        break;
    }
}
/* localdecomp:end func_L07_003B9590 */
