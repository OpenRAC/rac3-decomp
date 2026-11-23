/* func_L03_003AAD60: Opus handoff (prep by Sonnet worker w8, 2026-11-08); made to compile by Promises
 * (task 2812, 2026-11-22); VU0 code, tail and float constants restored by Promises (task 2910).
 * Size: 6916 bytes, places: 6 levels (03, 05, 08, 13, 22, 24), file: src/levels/shared/L03_003AAD60.c,
 * flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * One function (one prologue addiu sp,-0xD0), 1729 instructions, 189 jal (81 distinct), a 20-entry jump
 * table on the byte at a0+0x20. No twin (rac2 or another level). It is the Starship Phoenix (L03)
 * enemy/object update.
 * Near miss: 1677 differences (tools/check.py), level 03 (1675 at levels 05, 08, 13, 22 and 24; 1677
 * with --no-context). Ours is now 33 instructions LONGER than retail (1762 against 1729), so the
 * positional count understates it: aligned by opcode, 1444 of retail's 1729 instructions line up
 * (1194 before task 2910).
 * Where the 63 missing instructions were (task 2910, 2026-11-22): the previous draft was 63 short
 * because m2c had dropped every VU0 sequence and 128-bit copy. Measured by jump-table case
 * (retail's table jtbl_002BE270 against ours), the gap sat in case 16 (37 short), case 6 (28) and
 * case 14 (16). They are now written with the vu0.h helpers: vec_sub_ba/vec_add_ab/vec_add_ba on
 * the stack vectors sp0..sp40 (now vu0_v4, their x/y/z fields where m2c had f32 slots), the
 * quadword copies of D_L03_001E24C0 and of arg0+0x10, and qzero(&sp20) (retail's sq $0, 0x20($sp)).
 * Task 2910 also:
 * - moves the common tail (the D_L03_001DF4C0 % 359 angle, func_L01_0044E850, the
 *   func_L03_0043F5D0 colour and the counter at +0x96) after the switch, reached by break, as
 *   retail lays it out (66 instructions at the end, as retail); each state change is
 *   func_L01_004450F0(arg0, N, -1); break; and the compiler merges them as retail does;
 * - passes the float constants m2c gave as integer bit patterns (0x3D30F27C ...) as floats, and
 *   func_L01_0044E850 retail's 0.0432f/0.432f; func_L01_00448690 is declared (void *, s32, f32, f32);
 * - declares D_001BBE90, D_L03_00235A00 and D_L03_002C49C0 as u8[] (m2c's s32 scaled their byte
 *   offsets by 4) and offsets D_001A4BE0/D_001A4C60 in bytes; case 14 keeps &D_001A4BE0 in a local,
 *   as retail keeps it in $s1.
 * The frame is now retail's 0xD0. Left: ours saves $f21 as well as $f20 (retail only $f20); by case,
 * ours is still 9 long in case 14, 7 in case 5, 6 in case 16, 4 in case 2, 3 in cases 10 and 13, and
 * 5 short in case 6; register allocation differs throughout; m2c's spilled locals (sp50..sp60) and
 * gotos remain in case 10 and elsewhere.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003AAD60 */
extern s32 D_001D545C;
extern u8 D_L03_001DE610[];
extern u8 D_L03_001DE620[];
extern u8 *D_001D52FC;
extern s32 D_001A71D8;
extern u16 D_00143954;
extern u8 D_00142CB4;
extern s32 D_L03_001DE5C0;
extern s32 D_L03_001DE5C4;
extern s32 D_L03_001DE5D4;
extern f32 D_L03_001DE5DC;
extern f32 D_L03_001DE600;
extern s32 D_L03_001DF4C0;
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_0038CF68(void *, void *, f32);
extern s32 func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_0039AA38(s32);
extern s32 func_0039AC08(s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, s32);
extern s32 func_003A0F98(s32, s32);
extern s32 func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_003C2880(void *);
extern s32 func_003C2F58(void *, s32, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_003C4BB0(void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_0013C1A0(s32);
extern s32 func_0013C1D0(s32);
extern s32 func_0013D3D0(s32);
extern s32 func_L01_003EB350(s32, void *);
extern s32 func_L01_003EB3C0(s32, void *);
extern s32 func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern s32 func_L01_003EB5E0(s32, s32);
extern s32 func_L01_003F1740(void *);
extern s32 func_L01_00404808(void *, void *);
extern s32 func_L01_004048D0(void *, void *);
extern s32 func_L01_0041A5B0(s32, s32);
extern s32 func_L01_0041A6E0(void);
extern s32 func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00448690(void *, s32, f32, f32);
extern s32 func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00456230(void *, s32);
extern s32 func_L01_0045F1E8(s32, s32);
extern s32 func_L01_004606A8(s32);
extern s32 func_L01_00479200(s32);
extern s32 func_L01_00479280(void);
extern s32 func_L01_0047B3D8();
extern s32 func_L01_0047B420(void);
extern s32 func_L01_0047B948(void *);
extern s32 func_L01_0047B990(void);
extern s32 func_L01_005003D0(s32, s32);
extern s32 func_L01_00504E38(s32);
extern s32 func_L01_0050FB40(s32, s32, f32);
extern s32 func_L01_00511A40(void *, s32, f32);
extern s32 func_L01_00511A98(void);
extern u8 * func_L03_00348B88(void *);
extern s32 func_L03_00348C18(void *, void *, void *, s32, s32, s32);
extern u8 * func_L03_003AC868(u8 *, f32);
extern u8 * func_L03_003AC998(u8 *, void *, s32);
extern u8 * func_L03_003ACAD0(u8 *, u8 *);
extern s32 func_L03_003ACB68(u8 *);
extern s32 func_L03_003AD098(u8 *);
extern s32 func_L03_003AD580(void);
extern s32 func_L03_003AD740(s32);
extern s32 func_L03_003AD8C8(u8 *, s32);
extern s32 func_L03_003AD910(u8 *, s32, s32, s32);
extern s32 func_L03_003ADA98(u8 *);
extern s32 func_L03_003ADB80(u8 *);
extern s32 func_L03_003ADBC8(u8 *);
extern s32 func_L03_003ADC00(u8 *);
extern s32 func_L03_003ADC48(void);
extern s32 func_L03_003ADCD8(u8 *);
extern s32 func_L03_003ADDA0(u8 *);
extern s32 func_L03_003ADE98(u8 *, s32, s32);
extern s32 func_L03_003ADF58(u8 *);
extern s32 func_L03_003AE480(s32);
extern s32 func_L03_003AE4C0(s32);
extern s32 func_L03_003AE5F0(s32);
extern s32 func_L03_003AE810(u8 *);
extern s32 func_L03_003AE880(u8 *);
extern s32 func_L03_003AE9A0(u8 *);
extern s32 func_L03_003AEA48(u8 *);
extern s32 func_L03_003AEB98(u8 *);
extern s32 func_L03_0043F5D0(s32, s32, f32);
extern s32 D_001425C0;
extern s32 D_001A30B0;
extern s32 D_001A4BE0;
extern f32 D_001A4C60;
extern s32 D_001A7E18;
extern u8 D_001BBE90[];
extern s32 D_001CCFD0;
extern s32 D_L03_001DE630;
extern s32 D_L03_001DE640;
extern s32 D_L03_001DE650;
extern s32 D_L03_001DE668;
extern s32 D_L03_001DE678;
extern s32 D_L03_001DE688;
extern s32 D_L03_001DE698;
extern s32 D_L03_001DE6A8;
extern s32 D_L03_001DE6B8;
extern s32 D_L03_001DE6C8;
extern s32 D_L03_001DE6D8;
extern s32 D_L03_001DE6E8;
extern s32 D_L03_001DE6F8;
extern s32 D_L03_001DE708;
extern f32 D_L03_001DF2D0;
extern u8 D_L03_001DF364;
extern u8 D_L03_001DF365;
extern u8 D_L03_001DF366;
extern f32 D_L03_001DF370;
extern f32 D_L03_001DF374;
extern s32 D_L03_001DF4C0;
extern s32 D_L03_001E24C0;
extern f32 D_L03_001E28E4;
extern s32 D_L03_001E9220;
extern u8 D_L03_00235A00[];
extern u8 D_L03_002C49C0[];
extern s32 D_L03_002E52F0;
extern s32 func_L03_003AE8E0;
extern s32 func_L03_003AEB30;
extern s32 func_L03_003AEC58;

void func_L03_003AAD60(void *arg0) {
    vu0_v4 sp0;
    vu0_v4 sp10;
    vu0_v4 sp20;
    vu0_v4 sp30;
    vu0_v4 sp40;
    s32 sp50;
    s32 *sp54;
    s32 *sp58;
    s32 *sp5C;
    s32 *sp60;
    s32 *var_4_3;
    s32 var_5_4;
    f32 *temp_2_3;
    f32 temp_f12;
    s16 var_2_3;
    s32 *temp_5_10;
    s32 *temp_5_5;
    s32 *temp_5_6;
    s32 *temp_5_7;
    s32 *temp_5_8;
    s32 *temp_5_9;
    s32 *var_16;
    s32 *var_17;
    s32 *var_20;
    s32 *var_21;
    s32 *var_22;
    s32 *var_23;
    s32 *var_fp;
    s32 temp_2;
    s32 temp_2_10;
    s32 temp_2_11;
    s32 temp_2_13;
    s32 temp_2_18;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_9;
    s32 temp_4_2;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 temp_4_7;
    s32 temp_4_8;
    s32 temp_5;
    s32 temp_5_4;
    s32 temp_6;
    s32 temp_6_2;
    s32 temp_8;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_lo;
    s32 var_3_2;
    s32 var_3_4;
    s32 var_5_3;
    u16 temp_2_12;
    u16 temp_3_10;
    u16 temp_3_6;
    u16 temp_4;
    u16 var_5;
    u8 *var_4_2;
    u8 temp_2_2;
    u8 temp_2_4;
    u8 temp_2_5;
    u8 temp_3;
    u8 temp_3_12;
    u8 temp_3_4;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_5_2;
    u8 temp_6_3;
    u8 var_2;
    u8 var_4;
    void *temp_16;
    void *temp_16_2;
    void *temp_18;
    void *temp_2_14;
    void *temp_2_15;
    void *temp_2_16;
    void *temp_2_17;
    void *temp_2_8;
    void *temp_2_9;
    void *temp_3_11;
    void *temp_3_5;
    void *temp_4_10;
    void *temp_4_3;
    void *temp_4_6;
    void *temp_4_9;
    void *temp_5_3;
    void *temp_7;
    void *var_2_2;
    void *var_3_3;

    temp_3 = *(u8 *)((u8 *)(arg0) + 0x20);
    temp_18 = *(void **)((u8 *)(arg0) + 0x68);
    switch (temp_3) {
    case 0:
        *(s32 *)((u8 *)(temp_18) + 0x48) = 0;
        func_L03_003ADC00(arg0);
        var_5 = *(u16 *)((u8 *)(arg0) + 0xB2);
        temp_6 = var_5 << 0x10;
        if (*(u8 *)((u8 *)((D_L03_00235A00 + (s16) var_5)) + 0x464) == 0) {
            temp_2 = temp_6 >> 0x11;
            var_5 &= 1;
            temp_2_2 = *(temp_2 + (D_001D545C << 0xA) + D_001BBE90);
            if (var_5 != 0) {
                if (!(((s32) temp_2_2 >> 4) & 7)) {

                } else {
                    goto block_7;
                }
            } else if (temp_2_2 & 7) {
                goto block_7;
            }
        } else {
block_7:
            func_L03_003ADA98(arg0);
        }
        func_L03_003AEB98(arg0);
        *(vu0_q *)&sp0 = (*(vu0_q *)&sp10 = *(vu0_q *)((u8 *)arg0 + 0x10));
        sp10.z += 1.0f;
        sp0.z -= 1.0f;
        if (func_003D3CB0(&sp10, &sp0, 2, arg0, 0) != 0) {
            *(f32 *)((u8 *)(arg0) + 0x18) = (f32) *(f32 *)((u8 *)(&D_L03_001E9220) + 8);
        }
        *(s32 *)((u8 *)(temp_18) + 0x2C) = 0;
        *(s32 *)((u8 *)(temp_18) + 0x18) = -1;
        if (*(s32 *)((u8 *)(temp_18) + 0x24) == -1) {
            *(s32 *)((u8 *)(temp_18) + 0x24) = func_00382468(0x3E8);
        }
        *(s32 *)((u8 *)(temp_18) + 0x834) = 0;
        func_L01_004450F0(arg0, 1, -1);
        break;
    case 1:
        temp_2_3 = (f32 *)((u8 *)&D_001A4C60 - 0x80);
        if ((func_0038CF38(&D_001A4C60, arg0 + 0x10) <= 2.5f) && (func_0038DBA0(*(f32 *)((u8 *)(arg0) + 0xF8), func_0038D160(*(f32 *)((u8 *)(temp_2_3) + 0x80) - *(f32 *)((u8 *)(arg0) + 0x10), *(f32 *)((u8 *)(temp_2_3) + 0x84) - *(f32 *)((u8 *)(arg0) + 0x14))) < 1.5707964f) && (D_00142CB4 != 0)) {
            temp_4 = *(u16 *)((u8 *)(arg0) + 0xB2);
            if (*(u8 *)((u8 *)((D_L03_00235A00 + (s16) temp_4)) + 0x464) == 0) {
                temp_4_2 = D_001D545C;
                temp_2_4 = *(((s32) (temp_4 << 0x10) >> 0x11) + (temp_4_2 << 0xA) + D_001BBE90);
                if (temp_4 & 1) {
                    var_5_3 = temp_4 << 0x10;
                    if (!(((s32) temp_2_4 >> 4) & 7)) {
                        goto block_30;
                    }
                    goto block_21;
                }
                var_5_3 = temp_4 << 0x10;
                if (temp_2_4 & 7) {
block_21:
                    if (*(u8 *)((u8 *)((D_L03_00235A00 + (var_5_3 >> 0x10))) + 0x464) == 0) {
                        temp_2_5 = *((var_5_3 >> 0x11) + (temp_4_2 << 0xA) + D_001BBE90);
                        if (temp_4 & 1) {
                            if (!(((s32) temp_2_5 >> 4) & 7)) {
                                var_3_2 = D_001D545C;
                                goto block_28;
                            }
                            goto block_26;
                        }
                        if (temp_2_5 & 7) {
                            goto block_26;
                        }
                        goto block_27;
                    }
                    goto block_26;
                }
                goto block_30;
            }
block_26:
            if (!(*(s32 *)((u8 *)(D_001D52FC) + 0x1A0) & 8)) {
block_27:
                var_3_2 = D_001D545C;
block_28:
                if (var_3_2 == 0x18) {
                    if (*(s32 *)((u8 *)(temp_18) + 0x68) == 1) {
block_30:
                        goto block_31;
                    }
                }
            } else {
block_31:
                func_L01_00452560(0, 0xD, 0x87A, 1, 0, 0, 0);
                if ((D_001D545C == 0x18) && (*(s32 *)((u8 *)(temp_18) + 0x64) == 1)) {
                    func_L01_004048D0(&func_L03_003AE8E0, arg0);
                }
                temp_4_3 = D_001D52FC;
                if (func_0039AC08(*(s32 *)((u8 *)(((*(u8 *)((u8 *)(&D_001425C0) + 0x14) * 0xF0) + D_L03_002C49C0)) + 0x10)) == 0) {
                    func_0039AA38(*(s32 *)((u8 *)(((*(u8 *)((u8 *)(&D_001425C0) + 0x14) * 0xF0) + D_L03_002C49C0)) + 0x10));
                    func_L01_0047B948(0);
                } else {
                    temp_3_2 = D_001D545C;
                    if (*(s32 *)((u8 *)(temp_4_3) + 0x1A4) & 0x10) {
                        if (temp_3_2 == 0x18) {
                            *(s32 *)((u8 *)(temp_18) + 0x838) = 0;
                        } else if (*(s32 *)((u8 *)(temp_4_3) + 0x1A0) & 8) {
                            *(s32 *)((u8 *)(temp_18) + 0x838) = 0;
                        } else {
                            *(s32 *)((u8 *)(temp_18) + 0x838) = 1;
                        }
                        *(s32 *)((u8 *)(temp_18) + 0x4C) = (s32) *(s32 *)((u8 *)(&D_001A4BE0) + 0x1228);
                        *(s32 *)((u8 *)(&D_001A4BE0) + 0x25F8) = 0x14;
                        func_L01_0047B948(temp_4_3);
                        *(s32 *)((u8 *)(&D_001A4BE0) + 0x238) = 0x25;
                        func_L01_004450F0(arg0, 0xD, -1);
                        break;
                    }
                    if (temp_3_2 == 0x18) {
                        temp_3_3 = *(s32 *)((u8 *)(temp_4_3) + 0x1A0);
                        if ((temp_3_3 & 1) && (temp_3_3 & 2)) {
                            if (*(s32 *)((u8 *)(temp_18) + 0x64) == 1) {
                                func_L01_004450F0(arg0, 0xA, -1);
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        break;
    case 4:
        temp_16 = temp_18 + ((*(s32 *)((u8 *)(temp_18) + 0x2C) << 5) + 0x1F0);
        var_3_3 = D_001D52FC;
        if (func_L01_004561B8(arg0) != 0) {
            *(s32 *)((u8 *)(temp_16) + 8) = (s32) *(s32 *)((u8 *)(temp_16) + 0x10);
            *(f32 *)((u8 *)(temp_16) + 0xC) = (f32) *(f32 *)((u8 *)(temp_16) + 0);
            var_3_3 = *(void **)0x1D52FC;
        }
        if (!(*(s32 *)((u8 *)(var_3_3) + 0x1A4) & 0x800)) {
            temp_4_4 = *(s32 *)((u8 *)(temp_18) + 0x24);
            temp_5 = *(s32 *)((u8 *)(temp_18) + 0x2C);
            temp_2_6 = *(s32 *)((u8 *)(temp_16) + 4);
            temp_6_2 = ~temp_2_6;
            temp_4_5 = temp_4_4 + temp_5 + (*(s32 *)((u8 *)(temp_18) + 0x54) * temp_4_4);
            func_0013D3D0((temp_6_2 != 0) ? (temp_4_5 + temp_2_6) : temp_4_5);
            temp_4_6 = *(void **)((u8 *)(temp_18) + 0);
            *(u16 *)((u8 *)(temp_4_6) + 0x34) = (u16) (*(u16 *)((u8 *)(temp_4_6) + 0x34) & 0xFF7F);
            if (*(s32 *)((u8 *)(D_001D52FC) + 0x1A4) & 0x10) {
                func_L01_004450F0(arg0, 9, -1);
                break;
            }
            temp_5_2 = *(u8 *)((u8 *)(temp_16) + 0x17);
            if (temp_5_2 != 0) {
                temp_4_7 = *(s32 *)((u8 *)(temp_18) + 0x54);
                if (temp_5_2 == 1) {
                    if ((temp_4_7 % (s32) *(s32 *)((u8 *)(temp_16) + 0x10)) == temp_5_2) {
                        temp_6_3 = *(u8 *)((u8 *)(temp_16) + 0x18);
                        temp_lo = temp_4_7 / (s32) *(s32 *)((u8 *)(temp_16) + 0x1C);
                        if ((s32) temp_6_3 >= temp_lo) {
                            temp_3_4 = *(u8 *)((u8 *)(temp_16) + 0x19);
                            var_4 = (temp_lo < (s32) temp_3_4) ? temp_3_4 : (u8) temp_lo;
                        } else {
                            var_4 = temp_6_3;
                        }
                        func_L03_003AD910(arg0, func_00382498(var_4 - 1, var_4), *(u8 *)((u8 *)(temp_16) + 0x14), *(u8 *)((u8 *)(temp_16) + 0x15));
                    }
                } else {
                    goto block_67;
                }
            } else {
block_67:
                if ((*(s32 *)((u8 *)(temp_18) + 0x54) % (s32) *(s32 *)((u8 *)(temp_16) + 8)) == 1) {
                    func_L03_003AD910(arg0, func_00382498(*(u8 *)((u8 *)(temp_16) + 0x19), *(u8 *)((u8 *)(temp_16) + 0x18)), *(u8 *)((u8 *)(temp_16) + 0x14), *(u8 *)((u8 *)(temp_16) + 0x15));
                }
                if (((s32) *(s32 *)((u8 *)(temp_18) + 0x54) % (s32) *(s32 *)((u8 *)(temp_16) + 0x1C)) == 1) {
                    temp_2_7 = *(s32 *)((u8 *)(temp_16) + 8) - 0x14;
                    *(s32 *)((u8 *)(temp_16) + 8) = temp_2_7;
                    if (temp_2_7 < 0x3C) {
                        *(s32 *)((u8 *)(temp_16) + 8) = 0x3C;
                    }
                }
            }
            if ((*(s32 *)((u8 *)(*(void **)((u8 *)(*(void **)((u8 *)(temp_18) + 0)) + 0x68)) + 8) == 4) || (func_L03_003AD098(arg0) != 0)) {
                func_L03_003ACB68(arg0);
            }
            func_L03_003AD8C8(*(void **)((u8 *)(temp_18) + 0x1C), *(s32 *)((u8 *)(temp_18) + 0x2C));
            func_L03_003AD580();
            func_L03_003ADE98(arg0, 0x604040, 0x403030);
            *(s32 *)((u8 *)(temp_18) + 0x54) = (s32) (*(s32 *)((u8 *)(temp_18) + 0x54) + 1);
            func_L03_003AE9A0(arg0);
            if (*(s32 *)((u8 *)(temp_18) + 0x50) >= (s32) *(u8 *)((u8 *)(temp_16) + 0x1A)) {
                func_L01_004450F0(arg0, 5, -1);
                break;
            }
        } else {
            func_L03_003ADCD8(arg0);
        }
        break;
    case 16:
        if (func_L01_004561B8(arg0) != 0) {
            func_L03_003AE480(0);
            temp_2_8 = func_L03_003AC868(arg0, (f32) (D_L03_001DE5D4 * 2));
            *(void **)((u8 *)(temp_18) + 0x38) = temp_2_8;
            *(void **)((u8 *)(temp_18) + 0x40) = func_L03_003ACAD0(arg0, temp_2_8);
            *(void **)((u8 *)(temp_18) + 0x3C) = func_L03_003AC998(arg0, *(void **)((u8 *)(temp_18) + 0x38), *(s32 *)((u8 *)(temp_18) + 4));
            *(s32 *)((u8 *)(temp_18) + 0x44) = 0x55200000;
            *(s32 *)((u8 *)(temp_18) + 4) = 0x20;
            func_L03_003AD740(0);
        }
        func_003C2F58(*(void **)((u8 *)(temp_18) + 0x38), 0x42, &sp10);
        *(vu0_q *)&sp0 = *(vu0_q *)&D_L03_001E24C0;
        func_0038CF68(&sp20, *(void **)((u8 *)(temp_18) + 0x38) + 0xC0, (f32) D_L03_001DE5D4);
        vec_add_ab(&sp0, &sp20, &sp0);
        temp_f12 = D_L03_001DE5DC;
        if (func_0038CF00(&sp10, &sp0) <= 0.5f) {
            func_003C2880(*(void **)((u8 *)(temp_18) + 0));
            func_003C2880(*(void **)((u8 *)(temp_18) + 0x30));
            func_003C2880(*(void **)((u8 *)(temp_18) + 0x1C));
            temp_5_3 = *(void **)((u8 *)(temp_18) + 0x3C);
            temp_2_9 = *(void **)((u8 *)(temp_18) + 0x38);
            temp_3_5 = *(void **)((u8 *)(temp_18) + 0x40);
            *(void **)((u8 *)(temp_18) + 0x38) = 0;
            *(void **)((u8 *)(temp_18) + 0x40) = 0;
            *(void **)((u8 *)(temp_18) + 0x3C) = 0;
            *(s32 *)((u8 *)(temp_18) + 0x54) = 0;
            *(s32 *)((u8 *)(temp_18) + 0x50) = 0;
            *(void **)((u8 *)(temp_18) + 0x1C) = temp_5_3;
            *(void **)((u8 *)(temp_18) + 0) = temp_2_9;
            *(void **)((u8 *)(temp_18) + 0x30) = temp_3_5;
            func_L03_003AE810(arg0);
            func_L03_003AE480(1);
            func_L01_004450F0(arg0, 4, -1);
            break;
        }
        vec_sub_ba(&sp30, &sp0, &sp10);
        func_0038CF68(&sp30, &sp30, temp_f12 * 0.020000001f);
        func_0038CF68(&sp40, &sp30, (D_L03_001DE5DC + 2.0f) * 0.020000001f);
        temp_2_14 = *(void **)((u8 *)(temp_18) + 0);
        vec_add_ba((u8 *)temp_2_14 + 0x10, (u8 *)temp_2_14 + 0x10, &sp40);
        temp_2_14 = *(void **)((u8 *)(temp_18) + 0x38);
        vec_add_ba((u8 *)temp_2_14 + 0x10, (u8 *)temp_2_14 + 0x10, &sp30);
        temp_2_14 = *(void **)((u8 *)(temp_18) + 0x30);
        vec_add_ba((u8 *)temp_2_14 + 0x10, (u8 *)temp_2_14 + 0x10, &sp40);
        temp_2_14 = *(void **)((u8 *)(temp_18) + 0x40);
        vec_add_ba((u8 *)temp_2_14 + 0x10, (u8 *)temp_2_14 + 0x10, &sp30);
        temp_2_14 = *(void **)((u8 *)(temp_18) + 0x1C);
        vec_add_ba((u8 *)temp_2_14 + 0x10, (u8 *)temp_2_14 + 0x10, &sp40);
        temp_2_14 = *(void **)((u8 *)(temp_18) + 0x3C);
        vec_add_ba((u8 *)temp_2_14 + 0x10, (u8 *)temp_2_14 + 0x10, &sp30);
        func_L03_003AD8C8(*(void **)((u8 *)(temp_18) + 0x1C), *(s32 *)((u8 *)(temp_18) + 0x2C) - 1);
        func_L03_003AD8C8(*(void **)((u8 *)(temp_18) + 0x3C), *(s32 *)((u8 *)(temp_18) + 0x2C));
        func_L03_003AD580();
        break;
    case 5:
        if (func_L01_004561B8(arg0) != 0) {
            func_003A52A0(8, 0, arg0);
            func_L01_00456230(*(void **)((u8 *)(temp_18) + 0x30), 1);
            func_L03_003ADC48();
            *(s32 *)((u8 *)(temp_18) + 0x2C) = (s32) (*(s32 *)((u8 *)(temp_18) + 0x2C) + 1);
            func_L03_003AE880(arg0);
            if (*(s32 *)((u8 *)(temp_18) + 0x2C) < *(s32 *)((u8 *)(temp_18) + 0x28)) {
                if (*(s32 *)((u8 *)(temp_18) + 0x838) == 1) {
                    *(s32 *)((u8 *)(temp_18) + 0x834) = 0;
                }
                var_5_4 = 0x10;
            } else {
                temp_3_6 = *(u16 *)((u8 *)(arg0) + 0xB2);
                temp_4_8 = D_001D545C;
                if (temp_3_6 & 1) {
                    var_4_2 = ((s32) (temp_3_6 << 0x10) >> 0x11) + (temp_4_8 << 0xA) + D_001BBE90;
                    temp_3_7 = *var_4_2;
                    var_2 = temp_3_7 + 0x10;
                    if (((temp_3_7 >> 4) & 7) != 7) {
                        goto block_90;
                    }
                } else {
                    var_4_2 = ((s32) (temp_3_6 << 0x10) >> 0x11) + (temp_4_8 << 0xA) + D_001BBE90;
                    temp_3_8 = *var_4_2;
                    var_2 = temp_3_8 + 1;
                    if ((temp_3_8 & 7) != 7) {
block_90:
                        *var_4_2 = var_2;
                    }
                }
                func_L03_003ADA98(arg0);
                var_5_4 = 6;
            }
            func_L01_004450F0(arg0, var_5_4, -1);
            return;
        }
        if (*(s32 *)((u8 *)(D_001D52FC) + 0x1A4) & 0x10) {
            func_L01_004450F0(arg0, 9, -1);
            break;
        }
        func_L03_003AD8C8(*(void **)((u8 *)(temp_18) + 0x1C), *(s32 *)((u8 *)(temp_18) + 0x2C));
        func_L03_003AD580();
block_104:
        func_L03_003ADE98(arg0, 0x406040, 0x304030);
        break;
    case 6:
        if (func_L01_004561B8(arg0) != 0) {
            func_L03_003AE480(0);
            func_L03_003AD740(0);
        }
        func_003C2F58(*(void **)((u8 *)(temp_18) + 0), 0x40, &sp10);
        *(vu0_q *)&sp0 = *(vu0_q *)&D_L03_001E24C0;
        if (func_0038CF00(&sp10, &sp0) <= 0.5f) {
            func_L01_004450F0(arg0, 9, -1);
        } else {
            vec_sub_ba(&sp20, &sp0, &sp10);
            func_0038CF68(&sp20, &sp20, 2.0f * D_L03_001DE5DC * 0.020000001f);
            temp_2_14 = *(void **)((u8 *)(temp_18) + 0);
            vec_add_ba((u8 *)temp_2_14 + 0x10, (u8 *)temp_2_14 + 0x10, &sp20);
            temp_2_14 = *(void **)((u8 *)(temp_18) + 0x30);
            vec_add_ba((u8 *)temp_2_14 + 0x10, (u8 *)temp_2_14 + 0x10, &sp20);
            temp_2_14 = *(void **)((u8 *)(temp_18) + 0x1C);
            vec_add_ba((u8 *)temp_2_14 + 0x10, (u8 *)temp_2_14 + 0x10, &sp20);
            func_L03_003AD580();
        }
        goto block_104;
    case 19:
        if (func_L01_004561B8(arg0) != 0) {
            func_L03_003AEA48(arg0);
        }
        func_003C2F58(*(void **)((u8 *)(temp_18) + 0), 0x41, &sp0);
        func_L01_00404808(&func_L03_003AEB30, arg0);
        break;
    case 7:
        if (func_L01_004561B8(arg0) != 0) {
            func_003A52A0(9, 0, arg0);
            func_L03_003AE4C0(1);
            var_3_4 = D_001D545C;
            if (*(s32 *)((u8 *)(temp_18) + 0x838) == 1) {
                temp_3_9 = *(s32 *)((u8 *)(temp_18) + 0x834) + 0xA;
                *(s32 *)((u8 *)(temp_18) + 0x834) = temp_3_9;
                if (temp_3_9 >= 0x33) {
                    *(s32 *)((u8 *)(temp_18) + 0x834) = 0x32;
                } else if (temp_3_9 < 0) {
                    *(s32 *)((u8 *)(temp_18) + 0x834) = 0;
                }
                var_3_4 = D_001D545C;
            }
            var_2_2 = D_001D52FC;
            if (var_3_4 == 3) {
                if (D_L03_001DE5C4 >= 3) {
                    func_L01_0041A5B0(0x10A9, 0xE6);
                    D_L03_001DF2D0 = 0.5f;
                    func_L03_003AE5F0(1);
                    D_L03_001DE5C4 = 0;
                    goto block_120;
                }
                var_2_2 = D_001D52FC;
                if (D_L03_001DE5C0 >= 3) {
                    func_L01_0041A5B0(0x10A8, 0xE5);
                    D_L03_001DF2D0 = 0.5f;
                    func_L03_003AE5F0(1);
                    D_L03_001DE5C0 = 0;
                    goto block_120;
                }
            }
        } else {
block_120:
            var_2_2 = D_001D52FC;
        }
        temp_2_10 = *(s32 *)((u8 *)(var_2_2) + 0x1A4);
        if (temp_2_10 & 0x10) {
            func_L01_0041A6E0();
            func_L01_004450F0(arg0, 9, -1);
            break;
        }
        if (!(temp_2_10 & 0x40)) {
            func_L03_003AD8C8(*(void **)((u8 *)(temp_18) + 0x1C), *(s32 *)((u8 *)(temp_18) + 0x2C));
            func_L03_003AD580();
            func_L01_00404808(&func_L03_003AEC58, arg0);
            func_L03_003ADE98(arg0, 0x202060, 0x202040);
        } else {
            func_L01_0041A6E0();
            func_L03_003AE5F0(0);
            D_L03_001DF2D0 = 0;
            func_L03_003AD740(0);
            func_L03_003ADB80(arg0);
            temp_16_2 = *(void **)((u8 *)(*(void **)((u8 *)(temp_18) + 0)) + 0x68);
            *(s32 *)((u8 *)(temp_16_2) + 8) = func_00382468(2);
            func_L01_004606A8(D_001D52FC);
            func_L03_003AE4C0(0);
            func_L01_004450F0(arg0, 8, -1);
            break;
        }
        break;
    case 8:
        if (func_L03_003AD098(arg0) != 0) {
            func_003C4138(temp_18 + 0x14, 1.0f, D_L03_001DE600 * 0.020000001f);
            D_L03_001DF2D0 = *(f32 *)((u8 *)(temp_18) + 0x14);
            if (*(f32 *)((u8 *)(temp_18) + 0x14) >= 1.0f) {
                func_L03_003ADBC8(arg0);
                func_L01_004450F0(arg0, 3, -1);
            }
        }
        func_L03_003AD8C8(*(void **)((u8 *)(temp_18) + 0x1C), *(s32 *)((u8 *)(temp_18) + 0x2C));
        func_L03_003AD580();
        func_L03_003ADE98(arg0, 0x604040, 0x403030);
        break;
    case 9:
        func_L03_003ADC00(arg0);
        *(s8 *)((u8 *)(arg0) + 0x30) = 0x40;
        D_L03_001DF370 = *(f32 *)((u8 *)(temp_18) + 0x58);
        D_L03_001DF374 = *(f32 *)((u8 *)(temp_18) + 0x5C);
        D_L03_001DF364 = *(u8 *)((u8 *)(temp_18) + 0x60);
        D_L03_001DF365 = *(u8 *)((u8 *)(temp_18) + 0x61);
        D_L03_001DF366 = *(u8 *)((u8 *)(temp_18) + 0x62);
        *(s32 *)((u8 *)(temp_18) + 0x2C) = 0;
        func_L03_003AE880(arg0);
        func_L03_003AD740(1);
        func_L01_00504E38(0);
        func_003C2F58(arg0, 0, &D_001A4C60);
        if (*(s32 *)((u8 *)(temp_18) + 0x18) >= 0x34) {
            *(s32 *)((u8 *)(temp_18) + 0x18) = -1;
        }
        temp_5_4 = *(s32 *)((u8 *)(temp_18) + 0x18);
        if (temp_5_4 != -1) {
            temp_4_9 = (temp_5_4 << 7) + &D_001A30B0;
            if ((*(s32 *)((u8 *)(temp_4_9) + 0xDC) == arg0) && (*(u8 *)((u8 *)(temp_4_9) + 0xD0) != 0)) {
                func_003A4F28(temp_5_4);
            }
        }
        *(s32 *)((u8 *)(temp_18) + 0x18) = -1;
        func_003C2880(*(void **)((u8 *)(temp_18) + 0));
        func_003C2880(*(void **)((u8 *)(temp_18) + 0x1C));
        func_003C2880(*(void **)((u8 *)(temp_18) + 0x30));
        D_L03_001DE5C4 = 0;
        D_001A71D8 = *(s32 *)((u8 *)(temp_18) + 0x4C);
        D_L03_001DE5C0 = 0;
        func_L01_003F1740(arg0);
        func_L01_0045F1E8(*(s32 *)((u8 *)(temp_18) + 0x848), *(s32 *)((u8 *)(temp_18) + 0x844));
        func_0013C1D0(0x4D);
        func_L01_004450F0(arg0, 0xB, -1);
        break;
    case 11:
        func_003A0F98(0, 0);
        func_L01_0047B420();
        func_L01_0047B990();
        func_L01_00479280();
        func_L01_004450F0(arg0, 1, -1);
            break;
    case 13:
        *(s32 *)((u8 *)(&D_001A4BE0) + 0x238) = 0x25;
        if (func_L01_004561B8(arg0) != 0) {
            func_0038D000(&sp0, &D_L03_001DE610, arg0 + 0xC0);
            /* VU0, lost by m2c (with its lqc2/sqc2): vadd.xyz $vf2, $vf2, $vf1 */
            func_L01_00511A40(&sp0, 0, func_0038DAB8(*(f32 *)((u8 *)(arg0) + 0xF8), 3.1415927f));
        }
        temp_2_11 = func_L01_00511A98();
        if (temp_2_11 != 2) {
            goto block_152;
        }
        if (*(u8 *)((u8 *)(*(void **)((u8 *)(&D_001A4BE0) + 0x25C0)) + 0x42) != *(u8 *)((u8 *)(*(void **)((u8 *)(&D_001A4BE0) + 0x25C0)) + 0x43)) {
block_152:
            *(u16 *)((u8 *)(arg0) + 0x96) = (u16) (*(u16 *)((u8 *)(arg0) + 0x96) + 1);
            if (*(u16 *)((u8 *)(arg0) + 0x96) >= 0xFBU) {
                func_L01_00504E38(0);
                *(s32 *)((u8 *)(&D_001A4BE0) + 0x25F8) = (s32) *(s32 *)((u8 *)(temp_18) + 0x4C);
                func_L01_004450F0(arg0, 1, -1);
                break;
            }
            if (temp_2_11 == 0) {
                *(s32 *)((u8 *)(&D_001A4BE0) + 0x25F8) = (s32) *(s32 *)((u8 *)(temp_18) + 0x4C);
                func_L01_004450F0(arg0, 1, -1);
                break;
            }
        } else {
            if (func_0039AC08(*(s32 *)((u8 *)(((*(u8 *)((u8 *)(&D_001425C0) + 0x14) * 0xF0) + D_L03_002C49C0)) + 0x10)) == 0) {
                func_0039AA38(*(s32 *)((u8 *)(((*(u8 *)((u8 *)(&D_001425C0) + 0x14) * 0xF0) + D_L03_002C49C0)) + 0x10));
            }
            *(s32 *)((u8 *)(&D_001A4BE0) + 0x25F8) = 0x14;
            func_L01_0047B948(0);
            func_L01_004450F0(arg0, 0xE, -1);
            break;
        }
        break;
    case 14:
        var_4_2 = (u8 *)&D_001A4BE0;
        *(s32 *)(var_4_2 + 0x238) = 0x25;
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00479200(&sp0);
            func_L01_0047B948(0);
            func_L01_0047B3D8();
            func_L01_005003D0(0x74, 1);
            func_L01_0050FB40(0x4B, 0, 0);
            vec_sub_ba(&sp0, &D_L03_001E24C0, var_4_2 + 0x80);
            func_0038D000(&sp0, &sp0, var_4_2 + 0x40);
            func_L01_003EB438(0, &D_L03_001E24C0, &D_L03_001E24C0, 3, 0x64, 0);
            func_003A52A0(0xC, 0, arg0);
            *(f32 *)((u8 *)(temp_18) + 0x14) = 0.0f;
        }
        func_0038D000(&sp0, &D_L03_001DE610, arg0 + 0xC0);
        vec_add_ab(&sp0, &sp0, (u8 *)arg0 + 0x10);
        vec_sub_ba(var_4_2 + 0x100, &sp0, var_4_2 + 0x80);
        *(s32 *)(var_4_2 + 0x108) = 0;
        func_003C4BB0(var_4_2 + 0x100, 0.015f);
        func_L01_00448690(var_4_2 + 0x98, 0, func_0038DAB8(*(f32 *)((u8 *)(arg0) + 0xF8), 3.1415927f), 0.020943953f);
        *(s16 *)(var_4_2 + 0x222) = 3;
        if (*(s32 *)(var_4_2 + 0xC08) & 2) {
            func_L01_0050FB40(0x4C, 0, 6.0f);
        }
        if (*(s32 *)(var_4_2 + 0x25C4) != 0x74) {
            func_L01_003EB5E0(0, 3);
            *(s32 *)(var_4_2 + 0x25F8) = (s32) *(s32 *)((u8 *)(temp_18) + 0x4C);
            func_L01_004450F0(arg0, 1, -1);
        }
        func_0038D000(&sp10, &D_L03_001DE620, var_4_2);
        vec_add_ba(&sp10, &sp10, var_4_2 + 0x80);
        qzero(&sp20);
        func_003C2F58(arg0, 1, &sp30);
        sp20.z = func_0038D160(sp30.x - sp10.x, sp30.y - sp10.y);
        sp20.y = -func_0038D160(func_0038CF38(&sp10, &sp30), sp30.z - sp10.z);
        func_L01_003EB350(0, &sp10);
        func_L01_003EB3C0(0, &sp20);
        temp_2_12 = *(u16 *)((u8 *)(arg0) + 0x96);
        *(u16 *)((u8 *)(arg0) + 0x96) = (u16) (temp_2_12 + 1);
        if (temp_2_12 >= 0x33U) {
            func_L01_004450F0(arg0, 0xF, -1);
            break;
        }
        break;
        break;
    case 15:
        *(s32 *)((u8 *)(&D_001A4BE0) + 0x238) = 0x25;
        func_003C2F58(arg0, 0, &sp0);
        if (*(s32 *)((u8 *)(&D_001A4BE0) + 0xC08) & 2) {
            func_L01_0050FB40(0x4C, 0, 0);
        }
        if (func_L01_004561B8(arg0) != 0) {
            D_L03_001E28E4 = 0.017453292f;
            func_00382810(0, 0x21, 1, 0.017453292f, 0.005f, 0.2f, 0.0f);
        }
        *(s16 *)((u8 *)(&D_001A4BE0) + 0x222) = 3;
        temp_3_10 = *(u16 *)((u8 *)(arg0) + 0x96);
        *(u16 *)((u8 *)(arg0) + 0x96) = (u16) (temp_3_10 + 1);
        if (temp_3_10 >= 0x12U) {
            func_003C4138(temp_18 + 0x14, 1.0f, 0.14000002f);
            D_L03_001DF2D0 = *(f32 *)((u8 *)(temp_18) + 0x14);
            if ((u16) *(u16 *)((u8 *)(arg0) + 0x96) >= 0x22U) {
                D_L03_001E28E4 = 1.1100293f;
                func_00382810(0, 1, 0, 1.1100293f, 0.005f, 0.2f, 0.0f);
                func_L01_003EB5E0(0, 3);
                func_L01_004450F0(arg0, 2, -1);
                break;
            }
        } else {
            break;
        }
        break;
    case 3:
        if (func_L01_004561B8(arg0) != 0) {
            *(s32 *)((u8 *)(temp_18) + 0x830) = 0;
            if ((u32) (*(u16 *)((u8 *)(&D_001CCFD0) + 0x76) - 6) >= 2U) {
                *(u16 *)((u8 *)(&D_001CCFD0) + 0x76) = 5U;
            }
            if ((u32) (*(u16 *)((u8 *)(&D_001CCFD0) + 0x9E) - 6) >= 2U) {
                *(u16 *)((u8 *)(&D_001CCFD0) + 0x9E) = 5U;
            }
            func_L01_0041A6E0();
        }
        temp_7 = *(void **)((u8 *)(temp_18) + 0);
        *(u16 *)((u8 *)(temp_7) + 0x34) = (u16) (*(u16 *)((u8 *)(temp_7) + 0x34) & 0xFF7F);
        temp_3_11 = *(void **)((u8 *)(temp_18) + 0x1C);
        *(u16 *)((u8 *)(temp_3_11) + 0x34) = (u16) (*(u16 *)((u8 *)(temp_3_11) + 0x34) & 0xFF7F);
        func_L03_003ADE98(arg0, 0x604040, 0x403030);
        func_L03_003AD8C8(*(void **)((u8 *)(temp_18) + 0x1C), *(s32 *)((u8 *)(temp_18) + 0x2C));
        func_L03_003AD580();
        func_003C4138(temp_18 + 0x14, 0, D_L03_001DE600 * 0.020000001f);
        D_L03_001DF2D0 = *(f32 *)((u8 *)(temp_18) + 0x14);
        if (*(f32 *)((u8 *)(temp_18) + 0x14) == 0.0f) {
            if (D_001D545C == 3) {
                if (*(u16 *)((u8 *)(&D_001A7E18) + 0xE04) == 0) {
                    if (D_00143954 != 0) {
                        if (func_L01_0041A5B0(0x15D6, 0x12B) != 0) {
                            if (*(u16 *)((u8 *)(&D_001A7E18) + 0x10608) == 0) {
                                *(u16 *)((u8 *)(&D_001A7E18) + 0x10608) = 1U;
                            }
                            func_L03_003AE5F0(1);
                            func_L01_004450F0(arg0, 0x11, -1);
                            break;
                        }
                        temp_2_13 = *(s32 *)((u8 *)(temp_18) + 0x830) + 1;
                        *(s32 *)((u8 *)(temp_18) + 0x830) = temp_2_13;
                        if (temp_2_13 >= 0x1A) {
                            func_L01_004450F0(arg0, 4, -1);
                            break;
                        }
                        break;
                    }
                    goto block_188;
                }
                func_L01_004450F0(arg0, 4, -1);
                break;
            }
block_188:
            func_L01_004450F0(arg0, 4, -1);
            break;
        }
        break;
        break;
    case 17:
        var_4_3 = &D_L03_002E52F0;
        if (((*(s32 *)((u8 *)(&D_L03_002E52F0) + 0) == 0) && (*(s32 *)((u8 *)(&D_L03_002E52F0) + 0x24) == -1)) || ((*(unsigned long *)(D_001D52FC + 0x1A0) & 0xF000000000UL) != 0)) {
            func_L01_0041A6E0();
            func_L01_004606A8(D_001D52FC);
            func_L03_003AE5F0(0);
            D_L03_001DF2D0 = 0.0f;
            func_L01_004450F0(arg0, 4, -1);
            break;
        }
        break;
    case 2:
        if (func_003A0EC0(7, 1, arg0, 4, 0) != 0) {
            D_L03_001DF2D0 = 0;
            func_L01_004450F0(arg0, 1, -1);
            break;
        }
        *(s8 *)((u8 *)(arg0) + 0x30) = 0xFF;
        *(u16 *)((u8 *)(arg0) + 0x34) = (u16) (*(u16 *)((u8 *)(arg0) + 0x34) & 0xFF7F);
        temp_2_14 = func_L03_003AC868(arg0, (f32) D_L03_001DE5D4);
        *(void **)((u8 *)(temp_18) + 0) = temp_2_14;
        temp_2_15 = func_L03_003ACAD0(arg0, temp_2_14);
        *(s32 *)((u8 *)(temp_18) + 4) = 0x20;
        *(void **)((u8 *)(temp_18) + 0x30) = temp_2_15;
        temp_2_16 = func_L03_003AC998(arg0, *(void **)((u8 *)(temp_18) + 0), 0x20);
        *(f32 *)((u8 *)(temp_18) + 0x58) = (f32) D_L03_001DF370;
        *(f32 *)((u8 *)(temp_18) + 0x5C) = (f32) D_L03_001DF374;
        *(void **)((u8 *)(temp_18) + 0x1C) = temp_2_16;
        D_L03_001DF370 = 100.0f;
        D_L03_001DF374 = 255.0f;
        *(u8 *)((u8 *)(temp_18) + 0x60) = (u8) D_L03_001DF364;
        *(u8 *)((u8 *)(temp_18) + 0x61) = (u8) D_L03_001DF365;
        *(u8 *)((u8 *)(temp_18) + 0x62) = (u8) D_L03_001DF366;
        D_L03_001DF364 = 0x3C;
        D_L03_001DF365 = 0x3F;
        D_L03_001DF366 = 0x41;
        func_L03_003ADF58(arg0);
        if (*(s16 *)((u8 *)(&D_001CCFD0) + 0x3C) == -1) {
            var_2_3 = *(s16 *)((u8 *)(&D_001CCFD0) + 0x48);
        } else {
            var_2_3 = *(s16 *)((u8 *)(&D_001CCFD0) + 0x3C);
        }
        *(s32 *)((u8 *)(temp_18) + 0x848) = (s32) var_2_3;
        func_L01_0045F1E8(*(s32 *)((u8 *)(temp_18) + 0x840), *(s32 *)((u8 *)(temp_18) + 0x844));
        func_0013C1A0(0x4D);
        func_L01_004450F0(arg0, 3, -1);
        break;
    case 18:
        if (*(s32 *)((u8 *)(D_001D52FC) + 0x1A4) & 0x800) {
            func_L03_003ADDA0(arg0);
        }
        break;
    case 10:
        if (func_L01_004561B8(arg0) != 0) {
            var_fp = temp_18 + 0x207;
            temp_2_17 = func_L03_00348B88(arg0);
            var_23 = temp_18 + 0x206;
            *(void **)((u8 *)(temp_18) + 0x34) = temp_2_17;
            var_22 = temp_18 + 0x205;
            func_L03_00348C18(temp_2_17, temp_18 + 0x24, &D_L03_001DE630, 0, 1, 0xF4240);
            var_21 = temp_18 + 0x204;
            var_20 = temp_18 + 0x1F4;
            func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), temp_18 + 0x28, &D_L03_001DE640, 0, 1, 4);
            var_16 = temp_18 + 0x200;
            sp54 = temp_18 + 0x20C;
            var_17 = temp_18 + 0x1F0;
            sp58 = temp_18 + 0x20A;
            sp5C = temp_18 + 0x209;
            sp60 = temp_18 + 0x208;
            sp50 = 3;
            do {
                temp_8 = *var_16;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), var_16, &D_L03_001DE650, 4, temp_8, temp_8);
                temp_5_5 = var_17;
                temp_2_18 = sp50 - 1;
                sp50 = temp_2_18;
                var_17 += 0x20;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), temp_5_5, &D_L03_001DE668, 1, 1, 4);
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), var_20, &D_L03_001DE678, 0, -1, 0xF4240);
                var_20 += 0x20;
                temp_5_6 = var_16;
                var_16 += 0x20;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), temp_5_6, &D_L03_001DE688, 0, 1, 0x3E8);
                temp_5_7 = var_21;
                var_21 += 0x20;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), temp_5_7, &D_L03_001DE698, 2, 0, 0x64);
                temp_5_8 = var_22;
                var_22 += 0x20;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), temp_5_8, &D_L03_001DE6A8, 2, 0xA, 0x64);
                temp_5_9 = var_23;
                var_23 += 0x20;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), temp_5_9, &D_L03_001DE6B8, 2, 0, 0x64);
                temp_5_10 = var_fp;
                var_fp += 0x20;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), temp_5_10, &D_L03_001DE6C8, 2, 0, 1);
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), sp60, &D_L03_001DE6D8, 2, 1, 8);
                sp60 += 0x20;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), sp5C, &D_L03_001DE6E8, 2, 0, 7);
                sp5C += 0x20;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), sp58, &D_L03_001DE6F8, 2, 0, 0x64);
                sp58 += 0x20;
                func_L03_00348C18(*(void **)((u8 *)(temp_18) + 0x34), sp54, &D_L03_001DE708, 0, 0, 0x3E8);
                sp54 += 0x20;
            } while (temp_2_18 >= 0);
        }
        func_L01_00452560(0, 1, 0, 1, 0, 0, 0);
        temp_4_10 = *(void **)((u8 *)(temp_18) + 0x34);
        if ((temp_4_10 == 0) || (*(s16 *)((u8 *)(temp_4_10) + 0xAA) != 0x118A) || (temp_3_12 = *(u8 *)((u8 *)(temp_4_10) + 0x20), (temp_3_12 == 0xFE)) || (temp_3_12 == 0xFD)) {
            func_L01_004450F0(arg0, 1, -1);
            break;
        }
        break;
    }
    temp_hi = D_L03_001DF4C0 % 359;
    *(f32 *)((u8 *)(temp_18) + 0xD0) = (f32) temp_hi * 0.017453292f;
    func_L01_0044E850(arg0, temp_18 + 0x70, 3, 0.0432f, 0.432f);
    if (*(u8 *)((u8 *)(arg0) + 0x31) != 0) {
        temp_hi_2 = D_L03_001DF4C0 % 100;
        *(s32 *)((u8 *)(arg0) + 0x78) = func_L03_0043F5D0(0x404040, 0x202020, (f32) temp_hi_2 * 6.2831855f / (f32) 100 - 3.1415927f);
    }
    *(u16 *)((u8 *)(arg0) + 0x96) = (u16) (*(u16 *)((u8 *)(arg0) + 0x96) + 1);
}
/* localdecomp:end func_L03_003AAD60 */
