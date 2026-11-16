/* NTSC-U draft (Claude wave C4): C of func_L07_003A3FC0, the NTSC-U twin of func_L07_003A5780, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -fno-sched-interblock @ps2as") (NTSC-U twin "func_L07_003A3FC0", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH, first compile) only with the extra @ps2as; its PAL counterpart file src/levels/07_annihilation_nation/L07_003A46C8.c has '-O2 -G8 -fopt-stack -mno-check-zero-division' only (275 diff with its flags: retail builds the ...
 */
#include "common.h"

/* localdecomp:start func_L07_003A3FC0 */
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L07_003A48E8(u8 *, f32, f32);
extern void func_L07_003DA3A0(void *, s32);
extern void func_L07_003A4C18(u8 *);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00441FB8(u8 *, s32, s32);

void func_L07_003A3FC0(u8 *obj, s32 state) {
    u8 *s = *(u8 **)(obj + 0x68);

    switch (state) {
    case 1:
        break;
    case 2:
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 0);
        }
        break;
    case 4:
        *(u16 *)(obj + 0x34) |= 0x5000;
        func_L07_003A48E8(obj, 6.0f * 0.016666668f, 9.0f / 3600.0f);
        if (obj[0x43] != 5) {
            func_003BE4F0(obj, 5, 0, 4);
        }
        break;
    case 6:
        *(s32 *)(s + 0x188) &= ~0x10;
        if (obj[0x43] != 0) {
            func_003BE4F0(obj, 0, 0, 8);
        }
        func_L07_003DA3A0(*(void **)(s + 0x498), 0);
        break;
    case 7:
        func_L07_003A48E8(obj, 6.0f * 0.016666668f, 9.0f / 3600.0f);
        *(f32 *)(s + 0x170) = 9.0f / 3600.0f;
        *(f32 *)(s + 0x174) = 9.0f / 3600.0f;
        *(f32 *)(s + 0x178) = 6.0f * 0.016666668f;
        if (obj[0x43] != 5) {
            func_003BE4F0(obj, 5, 0, 8);
        }
        break;
    case 8:
        *(s32 *)(s + 0x188) &= ~0x10;
        func_L07_003A48E8(obj, 2.2f * 0.016666668f, 5.0f / 3600.0f);
        if (obj[0x43] != 4) {
            func_003BE4F0(obj, 4, 0, 8);
        }
        break;
    case 9:
        *(s16 *)(s + 0x492) = 0x14;
        if (obj[0x43] != 3) {
            func_003BE4F0(obj, 3, 0, 0xC);
        }
        break;
    case 10:
        *(s32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x170) = 20.0f / 3600.0f;
        *(f32 *)(s + 0x174) = 20.0f / 3600.0f;
        *(f32 *)(s + 0x178) = 2.0f * 0.016666668f;
        if (obj[0x43] != 7) {
            func_003BE4F0(obj, 7, 0, 6);
        }
        break;
    case 11:
        *(s32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x170) = 20.0f / 3600.0f;
        *(f32 *)(s + 0x174) = 20.0f / 3600.0f;
        *(f32 *)(s + 0x178) = 2.0f * 0.016666668f;
        if (obj[0x43] != 6) {
            func_003BE4F0(obj, 6, 0, 6);
        }
        break;
    case 12:
        if (obj[0x43] != 0xC) {
            func_003BE4F0(obj, 0xC, 0, 5);
        }
        break;
    case 13:
        *(s16 *)(s + 0x492) = 5;
        if (obj[0x43] != 0xD) {
            func_003BE4F0(obj, 0xD, 0, 3);
        }
        break;
    case 14:
        func_L07_003A48E8(obj, 0.75f * 0.016666668f, 1.0f / 3600.0f);
        *(f32 *)(s + 0x200) = *(f32 *)(s + 0x178);
        func_L07_003DA3A0(*(void **)(s + 0x498), 1);
        if (obj[0x43] != 0xF) {
            func_003BE4F0(obj, 0xF, 0, 3);
        }
        *(f32 *)(obj + 0x48) = 0.75f;
        break;
    case 15:
        if (obj[0x43] != 8) {
            func_003BE4F0(obj, 8, 0, 5);
        }
        break;
    case 16:
        *(s16 *)(s + 0x492) = 5;
        if (obj[0x43] != 9) {
            func_003BE4F0(obj, 9, 0, 3);
        }
        break;
    case 17:
        func_L07_003A48E8(obj, 0.75f * 0.016666668f, 1.0f / 3600.0f);
        *(f32 *)(s + 0x200) = *(f32 *)(s + 0x178);
        func_L07_003A4C18(obj);
        if (obj[0x43] != 0xA) {
            func_003BE4F0(obj, 0xA, 0, 3);
        }
        break;
    case 18:
        *(f32 *)(s + 0x49C) = func_0037E250(6.0f, 7.5f);
        *(s32 *)(s + 0x188) &= ~0x10;
        func_L07_003A48E8(obj, 2.2f * 0.016666668f, 5.0f / 3600.0f);
        if (obj[0x43] != 4) {
            func_003BE4F0(obj, 4, 0, 6);
        }
        break;
    case 19:
        *(f32 *)(s + 0x49C) = func_0037E250(6.0f, 7.5f);
        *(s32 *)(s + 0x188) &= ~0x10;
        func_L07_003A48E8(obj, 6.0f * 0.016666668f, 9.0f / 3600.0f);
        if (obj[0x43] != 5) {
            func_003BE4F0(obj, 5, 0, 8);
        }
        break;
    case 20:
        *(s32 *)(s + 0x188) |= 0x10;
        func_L07_003A48E8(obj, 2.0f * 0.016666668f, 20.0f / 3600.0f);
        if (obj[0x43] != 7) {
            func_003BE4F0(obj, 7, 0, 6);
        }
        break;
    case 21:
        *(s32 *)(s + 0x188) |= 0x10;
        func_L07_003A48E8(obj, 2.0f * 0.016666668f, 20.0f / 3600.0f);
        if (obj[0x43] != 6) {
            func_003BE4F0(obj, 6, 0, 6);
        }
        break;
    }
    func_L01_00441FB8(obj, state, -1);
}
/* localdecomp:end func_L07_003A3FC0 */
