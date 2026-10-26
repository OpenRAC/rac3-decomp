/* Adapted from nonmatching/frontbin/func_003C1600.c, NTSC decomp draft
 * at commit 13cf5c5; native symbols and extent verified against NTSC retail. */
#include "common.h"

/* localdecomp:start func_U_003BC0F0 */
typedef struct {
    u8 text0[0x10], text1[0x10], text2[0x10];
    s32 state, value34, value38, value3C, enabled, argument, timer, duration, value50;
    u8 padding54[0xC];
    s8 flag;
} State_003BC0F0;
typedef struct {
    u8 padding0[0x1AF8];
    s32 unavailable;
    u8 padding1AFC[0x18];
    s32 value1B14, value1B18, value1B1C;
} Settings_003BC0F0;
extern State_003BC0F0 D_U_002CE0E0[];
extern Settings_003BC0F0 D_001A4BE0[];
extern u8 D_U_001D90B8;
extern s32 func_U_0037DF98(s32);
extern s32 func_0011B754(void *, s32);
extern void func_U_003B6528(s32, s32);
extern void func_U_003B6F28(s32, void *);

s32 func_U_003BC0F0(s32 argument, s32 enabled) {
    State_003BC0F0 *state = D_U_002CE0E0;
    Settings_003BC0F0 *settings;
    func_0011B754(state->text0, func_U_0037DF98(0x1645));
    func_0011B754(state->text1, func_U_0037DF98(0x1646));
    func_0011B754(state->text2, func_U_0037DF98(0xF07));
    state->state = 0;
    settings = D_001A4BE0;
    state->value34 = settings->value1B14;
    state->value38 = settings->value1B1C;
    state->value3C = settings->value1B18;
    state->enabled = enabled;
    if (enabled != 0 && settings->unavailable != 0) {
        state->enabled = 0;
    }
    D_U_002CE0E0->argument = argument;
    D_U_002CE0E0->flag = 0;
    func_U_003B6528(0, 0);
    if (D_U_002CE0E0->enabled == 0) {
        D_U_002CE0E0->timer = 0;
        D_U_002CE0E0->duration = 0x3C;
        D_U_002CE0E0->value50 = 0;
        *(s32 *)0x001D4B4C = 0;
    } else {
        D_U_002CE0E0->timer = 0;
        D_U_002CE0E0->duration = 0x3C;
        func_U_003B6F28(3, &D_U_001D90B8);
    }
    return 1;
}
/* localdecomp:end func_U_003BC0F0 */
