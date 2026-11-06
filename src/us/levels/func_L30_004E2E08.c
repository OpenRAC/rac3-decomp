#include "common.h"

typedef struct {
    u8 pad0[0x43];
    u8 kind;
} Part_L30_004E2E08;

typedef struct {
    u8 pad0[0xC08];
    s32 flags;
    u8 pad1[0x1AC0 - 0xC0C];
    s32 active;
    u8 pad2[0x25C0 - 0x1AC4];
    Part_L30_004E2E08 *part;
    s32 mode;
    u8 pad3[0x25CC - 0x25C8];
    s32 pending;
    u8 pad4[0x25E9 - 0x25D0];
    u8 changed;
    u8 pad5[0x25EB - 0x25EA];
    u8 disabled;
} Global_L30_004E2E08;

/* localdecomp:start func_L30_004E2E08 */
extern Global_L30_004E2E08 D_001A4BE0;
extern void func_L30_004DC648(s32, s32, f32);

void func_L30_004E2E08(void) {
    if (((*(Global_L30_004E2E08 *)&D_001A4BE0).flags & 2) != 0 &&
        (*(Global_L30_004E2E08 *)&D_001A4BE0).disabled == 0) {
        s32 kind = (*(Global_L30_004E2E08 *)&D_001A4BE0).part->kind;
        if (kind == 19 || kind == 22 || kind == 25 || kind == 28 || kind == 31) {
            func_L30_004DC648((*(Global_L30_004E2E08 *)&D_001A4BE0).part->kind - 2, 0, 4.0f);
        }
        (*(Global_L30_004E2E08 *)&D_001A4BE0).changed = 0;
    }
    if ((*(Global_L30_004E2E08 *)&D_001A4BE0).pending != 0) {
        if ((*(Global_L30_004E2E08 *)&D_001A4BE0).active == 0) {
            (*(Global_L30_004E2E08 *)&D_001A4BE0).changed = 0;
        }
    }
}
/* localdecomp:end func_L30_004E2E08 */
