/* NEAR MISS (not MATCH). ck: 780 differing lines (almost all register-allocation fallout), but
 * 786 of retail's 829 instruction lines agree once registers and branch targets are ignored
 * (nd.py / norm.py in this folder): the control flow, constants, switch tree, cmov forms and the
 * two copies of the chain code are right.  What still differs:
 *  - the hero base: retail has three short-lived bases ($a0 until the giant_clank test, then a
 *    fresh `addiu $s1,$s3,0x4be0` just before `start_timer`, the rest rematerialised); mine keeps
 *    one base in $s1 from the second gate on, because gcc's cse follows the skipped blocks of the
 *    D_001439F4/giant_clank tests where retail's does not.  That also makes mine drop the
 *    critter_mode re-read in case 0x1E that retail keeps (3 words), and shifts every register;
 *  - the apex threshold (0.1 / 0.57): retail keeps both li.s arms and a shared compare tail, gcc
 *    folds them to `x = 0.57; if (!c) x = 0.1` (several wordings give the same bytes);
 *  - the clamp of n to 12: retail `movz $a1,$t1,..` in the argument register, mine `movn` from a temp;
 *  - row pointer in $s1 in the gun copy (retail: $s0);
 *  - the held_item load is scheduled after the D_001439F4 lbu (retail: before).
 * Declarations: D_001D4C44 is an unsized array (lui form in retail, $gp for D_001D4C40);
 * D_001DBCFC needs `.extern D_001DBCFC, 4` to get the $gp form retail has. */
/* hero_attack_start (open-rac-engine: hero_attack_start, NTSC-U 0x501678): runs before
 * hero_transitions' switch. Starts the wrench combo (state 19), the jump attack (20) or the
 * throw (21) on a buffered press, chains the combo, and starts the whip and gun states.
 * Returns 1 when the state timer has run back (a state change was made). */

extern u8 D_001439F4;
extern u8 D_00142CBD;
extern s32 D_001D4C40;
extern s32 D_001D4C44[];
__asm__(".extern D_001DBCFC, 4");
extern s32 D_001DBCFC;

extern S_00502368 *D_001D52FC;
extern u8 D_002F62D0[];
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_003A3BB8(s32, s32);
extern s32 func_L01_004EC598(void);
extern s32 func_L01_004EDFA8(void *);
extern void func_L01_004EA7D8(s32);
extern void func_L01_004F5810(void);
extern void func_L01_004F5AE8(void);
extern void func_L01_005003D0(s32, s32);
extern s32 func_0038CAD0(void *);

typedef int D_5055A0 __attribute__((mode(DI)));

typedef struct {
    u8 pad_0[0x20];
    u8 b20;
    u8 pad_21[0xAA - 0x21];
    s16 hAA;
} Moby_5055A0;

typedef struct {
    u8 pad_0[0xC];
    s32 buffer_from;
    s32 chain_from;
    u8 pad_14[0x2C - 0x14];
} Row_5055A0;

typedef struct {
    u8 pad_0[0x1A0];
    s32 w1A0;
    s32 w1A4;
} Pad_5055A0;

typedef struct {
    u8 pad_0[0x1B8];
    s32 state_timer;   /* 0x1B8 */
    u8 pad_1BC[0x24];
    s16 land_lockout;   /* 0x1E0 */
    u8 pad_1E2[0x24];
    s16 h206;   /* 0x206 */
    u8 pad_208[0x8];
    D_5055A0 x210;   /* 0x210 */
    u8 pad_218[0x1C];
    s32 giant_clank;   /* 0x234 */
    u8 pad_238[0x104];
    f32 height_above_ground;   /* 0x33C */
    u8 pad_340[0x20];
    s32 ground_frames;   /* 0x360 */
    u8 pad_364[0x4];
    s16 h368;   /* 0x368 */
    u8 pad_36A[0x102];
    u8 jump_landed;   /* 0x46C */
    u8 pad_46D[0x1];
    u8 jump_past_apex;   /* 0x46E */
    u8 pad_46F[0x35];
    s32 flip_side;   /* 0x4A4 */
    u8 pad_4A8[0x1F4];
    s32 zip_found;   /* 0x69C */
    u8 pad_6A0[0x388];
    s32 wA28;   /* 0xA28 */
    u8 pad_A2C[0x18];
    f32 fA44;   /* 0xA44 */
    u8 pad_A48[0x10];
    f32 fA58;   /* 0xA58 */
    u8 pad_A5C[0x2];
    s16 hA5E;   /* 0xA5E */
    u8 pad_A60[0x34];
    s32 wA94;   /* 0xA94 */
    u8 pad_A98[0x2C];
    s32 wAC4;   /* 0xAC4 */
    u8 pad_AC8[0x4];
    s32 wACC;   /* 0xACC */
    u8 pad_AD0[0x10C];
    s16 attack_row;   /* 0xBDC */
    u8 pad_BDE[0x2E];
    s32 wC0C;   /* 0xC0C */
    u8 pad_C10[0x8];
    f32 anim_frame;   /* 0xC18 */
    u8 pad_C1C[0x5E4];
    Moby_5055A0 *hand_moby;   /* 0x1200 */
    u8 pad_1204[0xC];
    s32 fire_button;   /* 0x1210 */
    u8 pad_1214[0x6];
    u8 wrench_thrown;   /* 0x121A */
    u8 pad_121B[0x5];
    s32 hand_ticks;   /* 0x1220 */
    s32 hand_state;   /* 0x1224 */
    s32 held_item;   /* 0x1228 */
    u8 pad_122C[0x250];
    u8 b147C;   /* 0x147C */
    u8 pad_147D[0x233];
    s32 camera_mode;   /* 0x16B0 */
    u8 pad_16B4[0xF10];
    s32 state;   /* 0x25C4 */
    u8 pad_25C8[0x4];
    s32 state_type;   /* 0x25CC */
    u8 pad_25D0[0x14];
    u8 critter_mode;   /* 0x25E4 */
    u8 pad_25E5[0x8];
    u8 no_firing;   /* 0x25ED */
    u8 pad_25EE[0x29A];
    s16 h2888;   /* 0x2888 */
    s16 h288A;   /* 0x288A */
    s16 h288C;   /* 0x288C */
} H_5055A0;

s32 func_L01_005055A0(void) {
    Row_5055A0 *row;
    Moby_5055A0 *hm;
    s32 buttons;
    s32 held_item;
    s32 start_timer;
    s32 st;
    s32 n;
    s32 m;
    s32 w;
    s32 win;
    s32 side;
    s32 ago[2];
    f32 height;
    f32 thr;

    if (((H_5055A0 *)&D_001A4BE0)->no_firing != 0) {
        if (((H_5055A0 *)&D_001A4BE0)->held_item != 9) {
            return 0;
        }
        if (((H_5055A0 *)&D_001A4BE0)->h368 != 1) {
            return 0;
        }
    }
    if (((H_5055A0 *)&D_001A4BE0)->critter_mode != 0) {
        return 0;
    }
    if (((H_5055A0 *)&D_001A4BE0)->hand_moby == 0) {
        return 0;
    }
    if (((H_5055A0 *)&D_001A4BE0)->wrench_thrown != 0) {
        return 0;
    }
    if (((H_5055A0 *)&D_001A4BE0)->hand_state != 2) {
        return 0;
    }
    held_item = ((H_5055A0 *)&D_001A4BE0)->held_item;
    buttons = ((H_5055A0 *)&D_001A4BE0)->fire_button;
    if (D_001439F4 != 0) {
        if (buttons & 0x20) {
            buttons |= 8;
        }
    }
    if (((H_5055A0 *)&D_001A4BE0)->giant_clank != 0) {
        if (buttons & 0x80) {
            buttons |= 0x20;
        }
    }
    start_timer = ((H_5055A0 *)&D_001A4BE0)->state_timer;
    switch (held_item) {
    case 9:
        if (((H_5055A0 *)&D_001A4BE0)->b147C != 0 || ((H_5055A0 *)&D_001A4BE0)->land_lockout != 0) {
            break;
        }
        if (((H_5055A0 *)&D_001A4BE0)->state_type < 2U || (((H_5055A0 *)&D_001A4BE0)->state_type == 4 && ((H_5055A0 *)&D_001A4BE0)->jump_landed != 0)) {
            if (func_L01_004606E8(buttons, 8, (s32)&ago[0], 0) == 0) {
                break;
            }
            hm = ((H_5055A0 *)&D_001A4BE0)->hand_moby;
            if (hm == 0 || func_L01_004EDFA8(hm) == 0 || hm->b20 != 0) {
                break;
            }
            w = ((Pad_5055A0 *)D_001D52FC)->w1A0;
            if (((H_5055A0 *)&D_001A4BE0)->camera_mode == 0) {
                m = w & func_003A3BB8(8, 0);
            } else {
                m = w & 0xA;
            }
            if (m == 0 && ((((H_5055A0 *)&D_001A4BE0)->state != 1 && ((H_5055A0 *)&D_001A4BE0)->state != 0x1D) || ((H_5055A0 *)&D_001A4BE0)->state_timer < 0x12)) {
                func_L01_005003D0(0x13, 1);
            } else if ((((H_5055A0 *)&D_001A4BE0)->state != 1 && ((H_5055A0 *)&D_001A4BE0)->state != 0x1D) || ((H_5055A0 *)&D_001A4BE0)->state_timer < 0x12) {
                func_L01_005003D0(0x15, 1);
            } else {
                func_L01_004F5810();
            }
            break;
        }
        st = ((H_5055A0 *)&D_001A4BE0)->state;
        if (st == 7 || st == 9 || st == 0xF || st == 0xA || st == 0xD || st == 8 || st == 6
            || (st == 0xE && 32.0f < ((H_5055A0 *)&D_001A4BE0)->anim_frame)
            || (st == 0xB && ((side = ((H_5055A0 *)&D_001A4BE0)->flip_side) != 3 && 18.0f < ((H_5055A0 *)&D_001A4BE0)->anim_frame || side == 3 && 20.0f < ((H_5055A0 *)&D_001A4BE0)->anim_frame))
            || ((H_5055A0 *)&D_001A4BE0)->state == 0x2C || ((H_5055A0 *)&D_001A4BE0)->state == 0x11) {
            if (((H_5055A0 *)&D_001A4BE0)->state_timer >= 9) {
                n = 12;
                if (((H_5055A0 *)&D_001A4BE0)->state == 0xB || ((H_5055A0 *)&D_001A4BE0)->state == 0xE) {
                    n = 15;
                }
                if (func_L01_004606E8(buttons, n, 0, 0) == 0) {
                    break;
                }
                height = ((H_5055A0 *)&D_001A4BE0)->height_above_ground;
                if (((H_5055A0 *)&D_001A4BE0)->jump_past_apex == 0) {
                    if (0.1f < height) {
                        goto za;
                    }
                } else if (0.57f < height) {
                    goto za;
                }
                if (((H_5055A0 *)&D_001A4BE0)->state != 8) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
                if (!(0.57f < ((H_5055A0 *)&D_001A4BE0)->height_above_ground)) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
za:
                if (((H_5055A0 *)&D_001A4BE0)->zip_found == 0) {
                    func_L01_005003D0(0x14, 1);
                }
                break;
            }
        }
        if (((H_5055A0 *)&D_001A4BE0)->state_type != 6) {
            break;
        }
        row = (Row_5055A0 *)(D_002F62D0 + ((H_5055A0 *)&D_001A4BE0)->attack_row * 0x2C);
        if (((H_5055A0 *)&D_001A4BE0)->state == 0x15 && ((H_5055A0 *)&D_001A4BE0)->state_timer >= 0x1A && ((H_5055A0 *)&D_001A4BE0)->wrench_thrown == 0) {
            if (((H_5055A0 *)&D_001A4BE0)->wC0C != 0) {
                break;
            }
            if ((f32)row->chain_from <= ((H_5055A0 *)&D_001A4BE0)->anim_frame) {
                w = ((Pad_5055A0 *)D_001D52FC)->w1A0;
                if ((((H_5055A0 *)&D_001A4BE0)->camera_mode == 0 ? (w & func_003A3BB8(8, 0)) : (w & 0xA)) != 0
                    && func_L01_004606E8(buttons, 12, 0, 0) != 0) {
                    func_L01_005003D0(0x15, 1);
                    break;
                }
            }
        }
        if (((H_5055A0 *)&D_001A4BE0)->wC0C != 0 || ((H_5055A0 *)&D_001A4BE0)->wrench_thrown != 0 || !((f32)row->chain_from <= ((H_5055A0 *)&D_001A4BE0)->anim_frame)) {
            break;
        }
        win = ((s32)((H_5055A0 *)&D_001A4BE0)->anim_frame - row->buffer_from) * 2;
        n = (win > 0) ? win : 1;
        if (n >= 13) {
            n = 12;
        }
        if (func_L01_004606E8(buttons, n, 0, 0) == 0) {
            break;
        }
        w = ((Pad_5055A0 *)D_001D52FC)->w1A0;
        if ((((H_5055A0 *)&D_001A4BE0)->camera_mode == 0 ? (w & func_003A3BB8(8, 0)) : (w & 0xA)) != 0) {
            func_L01_005003D0(0x15, 1);
        } else {
            func_L01_005003D0(0x13, 1);
        }
        break;
    case 0x7F:
    if (((H_5055A0 *)&D_001A4BE0)->b147C != 0) {
        break;
    }
    if (((H_5055A0 *)&D_001A4BE0)->state_type < 2U || (((H_5055A0 *)&D_001A4BE0)->state_type == 4 && ((H_5055A0 *)&D_001A4BE0)->jump_landed != 0)) {
        if (func_L01_004606E8(buttons, 8, (s32)&ago[1], 0) == 0) {
            break;
        }
        hm = ((H_5055A0 *)&D_001A4BE0)->hand_moby;
        if (hm == 0 || func_L01_004EDFA8(hm) == 0 || hm->b20 != 0) {
            break;
        }
        m = ((Pad_5055A0 *)D_001D52FC)->w1A0 & func_003A3BB8(8, 0);
        if (m == 0 && ((((H_5055A0 *)&D_001A4BE0)->state != 1 && ((H_5055A0 *)&D_001A4BE0)->state != 0x1D) || ((H_5055A0 *)&D_001A4BE0)->state_timer < 0x12)) {
            func_L01_005003D0(0x13, 1);
        } else if ((((H_5055A0 *)&D_001A4BE0)->state != 1 && ((H_5055A0 *)&D_001A4BE0)->state != 0x1D) || ((H_5055A0 *)&D_001A4BE0)->state_timer < 0x12) {
            func_L01_005003D0(0x15, 1);
        } else {
            func_L01_004F5AE8();
        }
        break;
    }
    st = ((H_5055A0 *)&D_001A4BE0)->state;
    if (st == 7 || st == 9 || st == 8 || st == 6
        || (st == 0xE && 32.0f < ((H_5055A0 *)&D_001A4BE0)->anim_frame)
        || (st == 0xB && ((side = ((H_5055A0 *)&D_001A4BE0)->flip_side) != 3 && 18.0f < ((H_5055A0 *)&D_001A4BE0)->anim_frame || side == 3 && 20.0f < ((H_5055A0 *)&D_001A4BE0)->anim_frame))
        || ((H_5055A0 *)&D_001A4BE0)->state == 0x2C || ((H_5055A0 *)&D_001A4BE0)->state == 0x11) {
        if (((H_5055A0 *)&D_001A4BE0)->state_timer >= 9) {
            n = 12;
                if (((H_5055A0 *)&D_001A4BE0)->state == 0xB || ((H_5055A0 *)&D_001A4BE0)->state == 0xE) {
                    n = 15;
                }
            if (func_L01_004606E8(buttons, n, 0, 0) == 0) {
                break;
            }
            height = ((H_5055A0 *)&D_001A4BE0)->height_above_ground;
            if (((H_5055A0 *)&D_001A4BE0)->jump_past_apex == 0) {
                    if (0.1f < height) {
                        goto zb;
                    }
                } else if (0.57f < height) {
                    goto zb;
                }
                if (((H_5055A0 *)&D_001A4BE0)->state != 8) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
                if (!(0.57f < ((H_5055A0 *)&D_001A4BE0)->height_above_ground)) {
                    func_L01_005003D0(0x13, 1);
                    break;
                }
zb:
                if (((H_5055A0 *)&D_001A4BE0)->zip_found == 0) {
                    func_L01_005003D0(0x14, 1);
                }
                break;
        }
    }
    if (((H_5055A0 *)&D_001A4BE0)->state_type != 6) {
        break;
    }
    row = (Row_5055A0 *)(D_002F62D0 + ((H_5055A0 *)&D_001A4BE0)->attack_row * 0x2C);
    if (((H_5055A0 *)&D_001A4BE0)->state == 0x15 && ((H_5055A0 *)&D_001A4BE0)->state_timer >= 0x1A && ((H_5055A0 *)&D_001A4BE0)->wrench_thrown == 0) {
        if (((H_5055A0 *)&D_001A4BE0)->wC0C != 0) {
            break;
        }
        if ((f32)row->chain_from <= ((H_5055A0 *)&D_001A4BE0)->anim_frame) {
            if ((((Pad_5055A0 *)D_001D52FC)->w1A0 & func_003A3BB8(8, 0)) != 0 && func_L01_004606E8(buttons, 12, 0, 0) != 0) {
                func_L01_005003D0(0x15, 1);
                break;
            }
        }
    }
    if (((H_5055A0 *)&D_001A4BE0)->wC0C != 0 || ((H_5055A0 *)&D_001A4BE0)->wrench_thrown != 0 || !((f32)row->chain_from <= ((H_5055A0 *)&D_001A4BE0)->anim_frame)) {
        break;
    }
    win = ((s32)((H_5055A0 *)&D_001A4BE0)->anim_frame - row->buffer_from) * 2;
    n = (win > 0) ? win : 1;
    if (n >= 13) {
        n = 12;
    }
    if (func_L01_004606E8(buttons, n, 0, 0) == 0) {
        break;
    }
    if ((((Pad_5055A0 *)D_001D52FC)->w1A0 & func_003A3BB8(8, 0)) != 0) {
        func_L01_005003D0(0x15, 1);
    } else {
        func_L01_005003D0(0x13, 1);
    }
    break;

    case 0xB:
    win = 14;
    if (((H_5055A0 *)&D_001A4BE0)->state == 0x27) {
        if (((H_5055A0 *)&D_001A4BE0)->hA5E != 0 || ((H_5055A0 *)&D_001A4BE0)->wA28 != 0) {
            if (func_L01_004606E8(buttons, win, 0, 0) != 0) {
                func_L01_005003D0(0x28, 1);
                break;
            }
            if ((((Pad_5055A0 *)D_001D52FC)->w1A0 & buttons) != 0 && ((H_5055A0 *)&D_001A4BE0)->hand_ticks >= 13) {
                func_L01_005003D0(0x28, 1);
                break;
            }
        }
    }
    st = ((H_5055A0 *)&D_001A4BE0)->state_type;
    if (st < 2U || st == 0xC || st == 4 || st == 2 || st == 0x1E || st == 5
        || (((H_5055A0 *)&D_001A4BE0)->state == 0x28 && ((H_5055A0 *)&D_001A4BE0)->state_timer >= 5) || ((H_5055A0 *)&D_001A4BE0)->state == 0x1D) {
        if (func_L01_004606E8(buttons, win, 0, 0) != 0
            || ((((Pad_5055A0 *)D_001D52FC)->w1A4 & buttons) != 0 && ((H_5055A0 *)&D_001A4BE0)->hand_ticks >= 13)) {
            if (((H_5055A0 *)&D_001A4BE0)->hA5E != 0) {
                if (((H_5055A0 *)&D_001A4BE0)->wA28 != 0) {
                    if (((H_5055A0 *)&D_001A4BE0)->fA58 < ((H_5055A0 *)&D_001A4BE0)->fA44) {
                        ((H_5055A0 *)&D_001A4BE0)->wA28 = 0;
                    } else {
                        ((H_5055A0 *)&D_001A4BE0)->hA5E = 0;
                    }
                }
                if (((H_5055A0 *)&D_001A4BE0)->hA5E != 0 && ((H_5055A0 *)&D_001A4BE0)->h206 == 0 && ((H_5055A0 *)&D_001A4BE0)->state != 0x2B) {
                    func_L01_005003D0(0x2B, 1);
                    break;
                }
            }
            if (((H_5055A0 *)&D_001A4BE0)->wA28 != 0 && ((H_5055A0 *)&D_001A4BE0)->h206 == 0) {
                func_L01_005003D0(0x23, 1);
            } else if (((H_5055A0 *)&D_001A4BE0)->wA94 != 0) {
                func_L01_005003D0(0x8F, 1);
            } else if (((H_5055A0 *)&D_001A4BE0)->wAC4 != 0) {
                ((H_5055A0 *)&D_001A4BE0)->wACC = 1;
                func_L01_004EA7D8(0x12);
            }
        }
    }
    break;

    case 0x1E:
    if (((H_5055A0 *)&D_001A4BE0)->critter_mode != 0) {
        break;
    }
    if (func_L01_004EC598() == 0) {
        break;
    }
    if (func_L01_004606E8(buttons, 6, 0, 0) == 0) {
        break;
    }
    if (D_001D4C40 != held_item) {
        break;
    }
    if (((H_5055A0 *)&D_001A4BE0)->hand_moby->hAA == 0x1D7E && ((H_5055A0 *)&D_001A4BE0)->h288C == 0) {
        ((H_5055A0 *)&D_001A4BE0)->h288A = 1;
        ((H_5055A0 *)&D_001A4BE0)->h288C = 0x12;
        ((H_5055A0 *)&D_001A4BE0)->h2888 = 1;
    }

    }
    if (((H_5055A0 *)&D_001A4BE0)->state_timer == start_timer) {
        if (D_00142CBD != 0) {
            if (D_001D4C44[0] == 0x1D) {
                if (((H_5055A0 *)&D_001A4BE0)->state != 0x1D && ((H_5055A0 *)&D_001A4BE0)->state != 1 && (((H_5055A0 *)&D_001A4BE0)->x210 & (D_5055A0)0xFFFFFFFF00000000ULL) == 0) {
                    func_0038CAD0(&D_001DBCFC);
                    if (D_001DBCFC != 0) {
                        st = ((H_5055A0 *)&D_001A4BE0)->state_type;
                        if (st < 2U || st == 0xC || ((st == 2 || st == 4) && ((H_5055A0 *)&D_001A4BE0)->ground_frames != 0)) {
                            if ((((Pad_5055A0 *)D_001D52FC)->w1A0 & func_003A3BB8(8, 0)) != 0) {
                                if ((((Pad_5055A0 *)D_001D52FC)->w1A4 & func_003A3BB8(8, 0)) != 0) {
                                    func_L01_005003D0(0x80, 1);
                                }
                            }
                        }
                    }
                    if ((((Pad_5055A0 *)D_001D52FC)->w1A4 & func_003A3BB8(8, 0)) != 0) {
                        D_001DBCFC = 12;
                    }
                }
            }
        }
    }
    return ((H_5055A0 *)&D_001A4BE0)->state_timer < start_timer;
}
