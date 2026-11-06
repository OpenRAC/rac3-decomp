#include "common.h"

/* localdecomp:start func_L01_004DF068 */
typedef struct {
    u8 reserved0[0x600];
    s32 field600;
    u8 reserved604[0x4C];
    f32 value650;
    u8 reserved654[8];
    s16 field65C;
    u8 reserved65E[0x25C0 - 0x65E];
    u8 *target25C0;
    s32 mode25C4;
} State_L01_004DF068;

extern State_L01_004DF068 D_001A4BE0;
extern void func_L01_0044B920(u8 *, f32 *, f32 *, f32, f32, f32);

void func_L01_004DF068(void) {
    if ((*(State_L01_004DF068 *)&D_001A4BE0).mode25C4 == 0x81 ||
        (*(State_L01_004DF068 *)&D_001A4BE0).mode25C4 == 0x50) {
        func_L01_0044B920((*(State_L01_004DF068 *)&D_001A4BE0).target25C0,
                           (f32 *)((u8 *)&D_001A4BE0 + 0x740),
                           (f32 *)((u8 *)&D_001A4BE0 + 0x744), 0.1745329252f,
                           0.02617994137f, 0.03490658849f);
    }
    if ((*(State_L01_004DF068 *)&D_001A4BE0).field65C == 0) {
        return;
    }
    if ((*(State_L01_004DF068 *)&D_001A4BE0).field600 != 0) {
        return;
    }
    *(f32 *)((*(State_L01_004DF068 *)&D_001A4BE0).target25C0 + 0xF4) =
        (*(State_L01_004DF068 *)&D_001A4BE0).value650;
}
/* localdecomp:end func_L01_004DF068 */
