/* NTSC-U draft (Claude wave K): C of func_L03_00399368, the NTSC-U twin of func_L03_0039AA48, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 19 words differ on NTSC-U with "@ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L03_00399368", whose code is not the PAL one).
 * Worker's note: first draft (was skip): 19 aligned diff with 265 = 265 words (flags: entry line lacks @ps2as, so a MATCH would be flags). 7-state arm controller (switch o[0x20]=1..7 -> blocks in code order; case labels guessed in ascending order, 8 = default): func_003BEC60 ...
 */
#include "common.h"

/* NTSC-U counterpart of the L03 turret-arm state machine (src/levels/03_starship_phoenix) */

/* localdecomp:start func_L03_00399368 */
extern f32 D_001DE394_sda;
__asm__(".extern D_001DE394_sda, 4");
extern f32 D_001DE398_sda;
__asm__(".extern D_001DE398_sda, 4");
extern f32 D_001DE39C_sda;
__asm__(".extern D_001DE39C_sda, 4");
extern f32 D_001DE3A0_sda;
__asm__(".extern D_001DE3A0_sda, 4");
extern f32 D_001DE3A4_sda;
__asm__(".extern D_001DE3A4_sda, 4");
extern f32 D_001DE3A8_sda;
__asm__(".extern D_001DE3A8_sda, 4");
extern f32 D_001DE3AC_sda;
__asm__(".extern D_001DE3AC_sda, 4");
extern f32 D_001DE3B0_sda;
__asm__(".extern D_001DE3B0_sda, 4");

extern void func_L03_00399790(void *);
extern void func_L01_0044C1D0(void *, void *);
extern void func_003BEC60(void *, void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L03_003998B0(void *);
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

typedef struct T_00399368 {
    u8 p0[0x4B0];
    f32 f4B0;
    u8 p4B4[0x1C];
    f32 f4D0;
    u8 p4D4[0x10];
    f32 f4E4;
    f32 f4E8;
    u8 p4EC[0x10];
    f32 f4FC;
    u8 p500[8];
    f32 f508;
} T_00399368;

void func_L03_00399368(u8 *o) {
    T_00399368 *t;
    f32 s;
    f32 w;

    t = *(T_00399368 **)(o + 0x68);
    func_L03_00399790(o);
    func_L01_0044C1D0(o, t);
    switch (o[0x20]) {
    case 1:
        func_003BEC60(o + 0x18, (u8 *)t + 0x500, D_001DE39C_sda, D_001DE398_sda * 0.00027777778f, D_001DE398_sda * 0.00027777778f, D_001DE394_sda * 0.016666668f);
        if (*(f32 *)(o + 0x18) <= D_001DE39C_sda) {
            func_L01_00441FB8(o, 3, -1);
        }
        if (func_L03_003998B0(o) != 0) {
            return;
        }
        func_L01_00441FB8(o, 8, -1);
        return;
    case 2:
        func_L01_00445758(&t->f4B0, (u8 *)t + 0x504, 0, D_001DE3A8_sda * 0.017453292f, D_001DE3A4_sda * 0.017453292f * 0.00027777778f, D_001DE3A4_sda * 0.017453292f * 0.00027777778f, D_001DE3A0_sda * 0.017453292f * 0.016666668f);
        t->f4D0 = t->f4B0;
        if (t->f4B0 == D_001DE3A8_sda * 0.017453292f) {
            func_L01_00441FB8(o, 4, -1);
        }
        if (func_L03_003998B0(o) != 0) {
            return;
        }
        func_L01_00441FB8(o, 7, -1);
        return;
    case 3:
        t->f508 = t->f508 + D_001DE3B0_sda;
        if (1.0f <= t->f508) {
            t->f508 = 1.0f;
            func_L01_00441FB8(o, 5, -1);
        }
        s = (1.0f - func_00388960(t->f508 * 3.1415927f)) * 0.5f;
        t->f4E4 = -D_001DE3AC_sda * func_00388978(t->f4D0) * s;
        t->f4E8 = D_001DE3AC_sda * func_00388960(t->f4D0) * s;
        if (func_L03_003998B0(o) != 0) {
            return;
        }
        func_L01_00441FB8(o, 6, -1);
        return;
    case 4:
        if (func_L03_003998B0(o) != 0) {
            return;
        }
        func_L01_00441FB8(o, 6, -1);
        return;
    case 5:
        t->f508 = t->f508 - D_001DE3B0_sda;
        if (t->f508 <= 0.0f) {
            t->f508 = 0.0f;
            func_L01_00441FB8(o, 7, -1);
        }
        w = (1.0f - func_00388960(t->f508 * 3.1415927f)) * 0.5f;
        t->f4E4 = -D_001DE3AC_sda * func_00388978(t->f4D0) * w;
        t->f4E8 = D_001DE3AC_sda * func_00388960(t->f4D0) * w;
        if (func_L03_003998B0(o) == 0) {
            return;
        }
        func_L01_00441FB8(o, 4, -1);
        return;
    case 6:
        func_L01_00445758(&t->f4B0, (u8 *)t + 0x504, 0, 0.0f, D_001DE3A4_sda * 0.017453292f * 0.00027777778f, D_001DE3A4_sda * 0.017453292f * 0.00027777778f, D_001DE3A0_sda * 0.017453292f * 0.016666668f);
        t->f4D0 = t->f4B0;
        if (t->f4B0 == 0.0f) {
            func_L01_00441FB8(o, 8, -1);
        }
        if (func_L03_003998B0(o) == 0) {
            return;
        }
        func_L01_00441FB8(o, 3, -1);
        return;
    case 7:
        func_003BEC60(o + 0x18, (u8 *)t + 0x500, t->f4FC, D_001DE398_sda * 0.00027777778f, D_001DE398_sda * 0.00027777778f, D_001DE394_sda * 0.016666668f);
        if (t->f4FC <= *(f32 *)(o + 0x18)) {
            func_L01_00441FB8(o, 1, -1);
        }
        if (func_L03_003998B0(o) != 0) {
            func_L01_00441FB8(o, 2, -1);
        }
        return;
    }
}
/* localdecomp:end func_L03_00399368 */
