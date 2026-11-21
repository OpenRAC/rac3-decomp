#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L07_003D48D0);

/* localdecomp:start func_L07_003D4DB8 */
typedef struct { s32 id; u8 pad4[4]; u8 stage; u8 pad9[0x24 - 9]; s32 index; f32 progress; } Vars_003D4DB8;
extern u8 *D_L07_001DF41C_003D4DB8[] __attribute__((section(".sdata")));
extern void func_L07_003D5008(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00456230(u8 *, s32);
extern s32 func_L07_00334868(s32);
extern void func_L07_003D51D8(u8 *);

void func_L07_003D4DB8(u8 *moby) {
    Vars_003D4DB8 *vars;
    func_L07_003D5008(moby);
    vars = *(Vars_003D4DB8 **)(moby + 0x68);
    switch (moby[0x20]) {
    case 1:
        if (vars->stage >= 2) func_L01_004450F0(moby, 4, -1);
        break;
    case 2:
        if (vars->stage >= 3) func_L01_004450F0(moby, 6, -1);
        if (vars->stage < 2) func_L01_004450F0(moby, 5, -1);
        break;
    case 3:
        if (func_L01_004561B8(moby)) func_L01_00456230(D_L07_001DF41C_003D4DB8[0] + (vars->index << 8), 1);
        if (func_L07_00334868(vars->id) != 4) func_L01_00456230(D_L07_001DF41C_003D4DB8[0] + (vars->index << 8), 0);
        if (vars->stage < 3) {
            func_L01_00456230(D_L07_001DF41C_003D4DB8[0] + (vars->index << 8), 0);
            func_L01_004450F0(moby, 7, -1);
        }
        break;
    case 4:
        vars->progress += 0.012f;
        if (vars->progress >= 1.0f) {
            vars->progress = 1.0f;
            func_L01_004450F0(moby, 2, -1);
        }
        func_L07_003D51D8(moby);
        break;
    case 5:
        vars->progress -= 0.012f;
        if (vars->progress <= 0.0f) {
            vars->progress = 0.0f;
            func_L01_004450F0(moby, 1, -1);
        }
        func_L07_003D51D8(moby);
        break;
    case 6:
        vars->progress += 0.012f;
        if (vars->progress >= 2.0f) {
            vars->progress = 2.0f;
            func_L01_004450F0(moby, 3, -1);
        }
        func_L07_003D51D8(moby);
        break;
    case 7:
        vars->progress -= 0.012f;
        if (vars->progress <= 1.0f) {
            vars->progress = 1.0f;
            func_L01_004450F0(moby, 2, -1);
        }
        func_L07_003D51D8(moby);
        break;
    }
}
/* localdecomp:end func_L07_003D4DB8 */
