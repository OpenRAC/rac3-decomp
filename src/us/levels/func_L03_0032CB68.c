#include "common.h"

typedef struct {
    u8 pad0[0xF2];
    u16 timer;
    u8 mode;
    u8 padF5[0x108 - 0xF5];
    s32 state;
} Vars_L03_0032CB68;

/* localdecomp:start func_L03_0032CB68 */
extern u8 D_001426E0[];
extern s32 D_00142848[];
extern u8 D_001A74A9[];
extern s32 func_L03_004949C8(s32, s32, s32, s32);
extern void func_L03_0042F238(s32, s32, s32);
extern void func_L03_003AD838(void);

void func_L03_0032CB68(u8 *object) {
    Vars_L03_0032CB68 *vars = *(Vars_L03_0032CB68 **)(object + 0x68);
    u8 *base;
    s32 value;
    u32 count;
    if (vars->mode != 0) {
        func_L03_004949C8(8, 0, (s32)object, 0x1936);
    } else {
        vars->state = 0;
        func_L03_004949C8(9, 0, (s32)object, 0x1936);
    }
    base = D_001426E0;
    value = base[0xE3];
    count = value;
    if (value != 0) {
        s32 *destination = D_00142848;
        value = 0;
        base[0xE3] = 0;
        do {
            *destination = count - 1;
        } while (0);
    }
    D_001A74A9[0] = 0;
    func_L03_003AD838();
    vars->timer = 0xF0;
    func_L03_0042F238((s32)object, 9, -1);
}
/* localdecomp:end func_L03_0032CB68 */
