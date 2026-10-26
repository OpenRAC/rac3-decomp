/* Adapted from nonmatching/boot_elf/func_003C19B8.c, NTSC decomp
 * commit 13cf5c5 draft. Native symbols verified from the current map and retail.
 * Uses the inherited default assembler, without the old per-function override. */
#include "common.h"

/* localdecomp:start func_U_003C18B0 */
typedef struct {
    u8 name0[0x10];
    u8 name1[0x10];
    u8 name2[0x10];
    s32 field30, field34, field38, field3C, field40;
    s32 field44, field48, field4C, field50;
    u8 reserved54[0xC];
    s8 field60;
} State_C18B0;
typedef struct {
    u8 reserved0[0x1AF8];
    s32 field1AF8;
    u8 reserved1AFC[0x18];
    s32 field1B14, field1B18, field1B1C;
} Settings_C18B0;
extern State_C18B0 D_U_002D20E0[];
extern Settings_C18B0 D_001A4BE0[];
extern u8 D_U_001D90B8;
extern s32 func_U_003823F0(s32);
extern void func_U_003BBCE8(s32, s32);
extern void func_U_003BC6E8(s32, s32);
extern s32 func_0011B754(void *, s32);

s32 func_U_003C18B0(s32 value, s32 enabled) {
    State_C18B0 *state = D_U_002D20E0;
    Settings_C18B0 *settings;
    func_0011B754(state->name0, func_U_003823F0(0x1645));
    func_0011B754(state->name1, func_U_003823F0(0x1646));
    func_0011B754(state->name2, func_U_003823F0(0xF07));
    state->field30 = 0;
    settings = D_001A4BE0;
    state->field34 = settings->field1B14;
    state->field38 = settings->field1B1C;
    state->field3C = settings->field1B18;
    state->field40 = enabled;
    if (enabled != 0 && settings->field1AF8 != 0) {
        state->field40 = 0;
    }
    D_U_002D20E0->field44 = value;
    D_U_002D20E0->field60 = 0;
    func_U_003BBCE8(0, 0);
    if (D_U_002D20E0->field40 == 0) {
        D_U_002D20E0->field48 = 0;
        D_U_002D20E0->field4C = 0x3C;
        D_U_002D20E0->field50 = 0;
        *(s32 *)0x001D4B4C = 0;
    } else {
        D_U_002D20E0->field48 = 0;
        D_U_002D20E0->field4C = 0x3C;
        func_U_003BC6E8(3, (s32)&D_U_001D90B8);
    }
    return 1;
}
/* localdecomp:end func_U_003C18B0 */
