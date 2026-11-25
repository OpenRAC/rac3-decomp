/* Round 30 (W16): with the file's current flag line (-mvu0-use-vf0-vf2 ... @ps2as) check.py's aligned diff is
   7 rows (+3 trailing padding rows). `if ((pressed & 3) != 0) locked = 1;` instead of `locked = (pressed & 3) != 0`
   fixed `andi $v0` / `sltu $s0, $zero, $v0` (2 rows). The 7 left are the three reorg spots below. All three lie
   between the jump to the epilogue in the b28C9 return block and the next barrier, and every retail choice
   there is what resource.c's mark_target_live_regs gives when find_basic_block() fails (all registers live):
   retail's label after that barrier was not a flow2 basic-block head at dbr time, ours is. Tried without a
   change: 9 shapes of the wrench condition, 4 of the two return blocks (opus-b44-w16-findings.md). */
/* NEAR MISS (r11, hero_item_switch, func_L01_004EC600, 2952 bytes). check.py: 657 diff by
   position, but only 17 words differ structurally (scratch/match/r10_a/sdiff.py): 735 of retail's
   738 instructions, with every register right except one temporary. The position count is high
   because three missing instructions shift everything after the first one (at +0x144).
   Still differs, all delay-slot choices made by reorg:
   - after the call to func_L01_004606E8, retail leaves a nop in the `bnez $v0` delay slot. This
     draft puts the next block's hero `addiu` there;
   - in the Circle/R1 test, retail has `bnel` with the hero `addiu` annulled (two places) and
     `beqz $s0` with the `lui %hi(D_00142660)` taken from the target. This draft has `bnez` and
     `addiu`. Also `andi $s0` against retail's `andi $v0` before the `sltu $s0`;
   - in slot 1's 0xE block, retail has `beql $v1,$zero` with `lbu 0x1479` annulled, and its
     `li 0xE` after the D_001D4C40[1] load. This draft moves the `li 0xE` into the `beqz` slot.
   All three look like reorg treating a register as live at the branch target in retail, where
   this draft has it dead.
   What brought it from 341 structural words (hero4's near.c) down to 17:
   - each slot is accessed as ((HS *)(D_001A4BE0 + slot * 0x50))->field, with fields at 0x1200+,
     as func_L01_004EC468 does, instead of hero->slot[slot].field;
   - `item[slot]`, not `item[0]`, inside the slot == 0 gadget block, so the address folds against
     D_001A5DF9 (0x13FB($s3));
   - a switch with a body for every case (0x27/0x37 and 0x3F/0x4F written separately), so
     cross-jumping merges them as retail does and only the default reloads the hero;
   - block-local temporaries, plus `req` and `held` locals, in place of one shared `v`;
   - an if/else with two stores for the 3/2 request and for the 0xCC remembered item;
   - `unsigned long flag_bits` with `== 1` for the lock-on bit (dsrl, no truncation);
   - store order: the order retail shows comes from statements written in reverse (prev before
     req in slot 3; 0x2888, 0x288C, 0x288A in the guise block), with changed = 1 after the stores.
   What did not change the bytes: a `pressed` local for func_L01_004606E8; the Circle condition
   inverted into an if/else; a local pad pointer; a separate `busy` variable; D_001D4C40[slot] or
   request[slot] in the 0xE block; and three wordings of the 0xE block's remembered item (a
   ternary gives movz; if/else in either order gives the same bytes). */
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern u8 D_001425C0[];
extern Def_004EA7D8 D_L01_002C5600[];
extern s32 D_001D4C40[2];
extern s32 D_001D4C48[2];
extern u8 D_00142660[];
extern u8 D_00142A60[];
extern u8 D_00142CAD[];
extern u8 D_00142CAE[];
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L01_004E9308(void);
extern s32 func_L01_00513EF0(void);
extern s32 func_00381CB0(void);
extern s32 func_L01_004EC598(void);
extern void func_L01_004EC540(s32 a0);
extern void func_L01_004EAA80(void);
extern void func_L01_004E67C0(void);
extern s32 func_00382498();
extern s32 func_L01_0040E020(void *);
extern s32 func_0039AC08(s32);
extern void func_0039AA38(s32);
extern void func_L01_003415F8(s32);
extern void func_003C3A10(u8 *, s32, s32, s32);

/* One of the hero's seven item slots (0 the hand, 1..6 the back, suit, boots and others) */
typedef struct {
    u8 *moby;
    u8 *back_moby;
    u8 pad8[0x19 - 0x8];
    u8 b19;
    u8 b1A;
    u8 pad1B;
    u8 b1C;
    u8 b1D;
    u8 pad1E[2];
    s32 held_frames;
    s32 hand_state;
    s32 item;
    u8 pad2C[0x50 - 0x2C];
} Slot_4EC600;
/* The hero's block seen from slot i's own place, D_001A4BE0 + i * 0x50 */
typedef struct {
    u8 pad0[0x1200];
    u8 *moby;
    u8 *back_moby;
    u8 pad1208[0x1219 - 0x1208];
    u8 b19;
    u8 b1A;
    u8 pad121B;
    u8 b1C;
    u8 b1D;
    u8 pad121E[2];
    s32 held_frames;
    s32 hand_state;
    s32 item;
} HS_4EC600;
typedef struct {
    u8 pad0[0x368];
    s16 h368;
    u8 pad36A[0x69C - 0x36A];
    s32 zip_found;
    u8 pad6A0[0xE70 - 0x6A0];
    u8 *hold_layer[2];
    u8 padE78[0x1180 - 0xE78];
    s32 idle_timer;
    u8 pad1184[0x1200 - 0x1184];
    Slot_4EC600 slot[7];
    u8 pad1430[0x1479 - 0x1430];
    u8 walk_slow_flag;
    u8 pad147A[0x1660 - 0x147A];
    f32 look_cam_range;
    u8 pad1664[0x25C4 - 0x1664];
    s32 state;
    u8 pad25C8[4];
    s32 state_type;
    u8 pad25D0[0x25E6 - 0x25D0];
    u8 wrench_request;
    u8 gun_request;
    u8 b25E8;
    u8 firing;
    u8 pad25EA[2];
    u8 hold_type;
    u8 no_firing;
    u8 pad25EE[0x25F8 - 0x25EE];
    s32 request[7];
    s32 item[7];
    s32 remembered[7];
    s32 restore[7];
    s32 pending_gadget;
    u8 pad266C[0x2878 - 0x266C];
    u8 b2878;
    u8 pad2879[0x2888 - 0x2879];
    s16 h2888;
    s16 h288A;
    s16 guise_timer;
    u8 pad288E[0x28C9 - 0x288E];
    u8 b28C9;
    u8 b28CA;
} H_4EC600;
typedef struct {
    u8 pad0[0x30];
    u8 wrench_out;
    u8 b31;
    u8 pad32[0x40 - 0x32];
    s16 h40;
    u8 pad42[0x4C - 0x42];
    s16 h4C;
} G_4EC600;
typedef struct {
    u8 pad0;
    u8 b1;
    u8 pad2[0x10 - 0x2];
    s32 gadget;
    u8 pad14[0x18 - 0x14];
    s32 hold_type;
    u8 pad1C[0x20 - 0x1C];
    s32 w20;
    u8 pad24[0xF0 - 0x24];
} Row_4EC600;
typedef struct {
    u8 pad0[0x1A0];
    s32 held;
    s32 pressed;
} Pad_4EC600;
typedef struct {
    u8 pad0[0x24];
    u8 *cls;
} Moby_4EC600;

/* hero_item_switch: brings out the item asked for in slot `slot`: Square the wrench, Circle the
   equipped gun, L2+R2 with the wrench out the gun when its lock-on mod is set; then the
   requests, the slot's change and the per-gun camera range. */
void func_L01_004EC600(s32 slot)
{
    s32 changed;
    s32 locked;
    s32 forced;
    s32 v;
    s32 req;
    s32 busy;
    s32 held;
    unsigned long flag_bits;

    if (slot == 0) {
        if (((H_4EC600 *)D_001A4BE0)->b25E8 != 0 && ((H_4EC600 *)D_001A4BE0)->slot[0].item != 9) {
            ((H_4EC600 *)D_001A4BE0)->gun_request = 0;
            ((H_4EC600 *)D_001A4BE0)->wrench_request = 1;
        }
    }
    if (slot == 0) {
        if (((H_4EC600 *)D_001A4BE0)->b25E8 != 0 && ((H_4EC600 *)D_001A4BE0)->slot[0].item == 9) {
            if (((H_4EC600 *)D_001A4BE0)->state == 0xB0) {
                ((H_4EC600 *)D_001A4BE0)->request[0] = 0;
            }
            if (((H_4EC600 *)D_001A4BE0)->request[0] == 0x16) {
                func_L01_003415F8(((Row_4EC600 *)D_L01_002C5600)[D_001425C0[0x16]].b1);
                ((H_4EC600 *)D_001A4BE0)->request[0] = 0;
            }
        }
    }
    if (((H_4EC600 *)D_001A4BE0)->no_firing != 0 && slot == 0
        && (((H_4EC600 *)D_001A4BE0)->wrench_request == 0 || ((H_4EC600 *)D_001A4BE0)->slot[0].item == 9)) {
        ((H_4EC600 *)D_001A4BE0)->wrench_request = 0;
        return;
    }
    changed = 0;
    if (((H_4EC600 *)D_001A4BE0)->b28C9 != 0 && slot == 0
        && (((H_4EC600 *)D_001A4BE0)->wrench_request == 0 || ((H_4EC600 *)D_001A4BE0)->slot[0].item == 9)) {
        ((H_4EC600 *)D_001A4BE0)->wrench_request = 0;
        return;
    }
    /* Square: the wrench */
    if (func_L01_004606E8(0x80, 3, 0, 0) != 0 || ((H_4EC600 *)D_001A4BE0)->wrench_request != 0) {
        if (slot == 0 && ((H_4EC600 *)D_001A4BE0)->slot[0].item != 9 && ((H_4EC600 *)D_001A4BE0)->b28CA == 0) {
            if (((H_4EC600 *)D_001A4BE0)->wrench_request != 0) {
                s32 gun = ((H_4EC600 *)D_001A4BE0)->slot[0].item;

                if (gun != 0 && gun != 0x1E && gun != 0x16) {
                    ((H_4EC600 *)D_001A4BE0)->remembered[0] = gun;
                }
            }
            ((H_4EC600 *)D_001A4BE0)->item[slot] = 9;
            changed = 1;
        }
    }
    ((H_4EC600 *)D_001A4BE0)->b28CA = 0;
    if (((H_4EC600 *)D_001A4BE0)->gun_request != 0) {
        s32 gun = ((H_4EC600 *)D_001A4BE0)->slot[0].item;

        if (gun != 0xB && ((H_4EC600 *)D_001A4BE0)->item[0] != 0xB) {
            if (gun != 0) {
                ((H_4EC600 *)D_001A4BE0)->remembered[0] = gun;
            }
            ((H_4EC600 *)D_001A4BE0)->item[0] = 0xB;
            changed = 1;
        }
    }
    if (((H_4EC600 *)D_001A4BE0)->item[slot] == 9 && changed != 0 && ((H_4EC600 *)D_001A4BE0)->zip_found != 0
        && ((H_4EC600 *)D_001A4BE0)->slot[0].item != 0 && ((H_4EC600 *)D_001A4BE0)->slot[0].item != 9) {
        ((H_4EC600 *)D_001A4BE0)->remembered[0] = ((H_4EC600 *)D_001A4BE0)->slot[0].item;
    }
    /* Circle (or R1): the equipped gun; L2+R2 with the lock-on mod */
    if (slot == 0) {
        locked = 0;
        if (((H_4EC600 *)D_001A4BE0)->slot[0].item == 9 && D_001D4C40[0] != 0
            && (((flag_bits = D_00142A60[D_001D4C40[0]]) >> 5) & 1) == 1
            && (((Pad_4EC600 *)D_001D52FC)->held & 3) == 3) {
            if ((((Pad_4EC600 *)D_001D52FC)->pressed & 3) != 0) {
                locked = 1;
            }
        }
        if ((((Pad_4EC600 *)D_001D52FC)->pressed & 0x20) != 0
            || ((((Pad_4EC600 *)D_001D52FC)->pressed & 8) != 0 && func_L01_00513EF0() != 0) || locked != 0) {
            if (((H_4EC600 *)D_001A4BE0)->b25E8 == 0 && ((H_4EC600 *)D_001A4BE0)->gun_request == 0
                && ((H_4EC600 *)D_001A4BE0)->slot[0].item != D_001D4C40[slot] && D_001D4C40[slot] != 0) {
                changed = 1;
                ((H_4EC600 *)D_001A4BE0)->item[slot] = D_001D4C40[slot];
            }
        }
    }
    busy = 0;
    if (((G_4EC600 *)D_00142660)->h40 == 4 || func_00381CB0() > 0) {
        busy = 1;
    }
    if (slot == 1 && busy == 0) {
        if (((H_4EC600 *)D_001A4BE0)->state_type == 0xF && D_00142CAE[0] != 0
            && (D_001D4C40[1] != 0xE || ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->item == 0)) {
            ((H_4EC600 *)D_001A4BE0)->request[1] = 0xE;
            if (((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->item == 0) {
                ((H_4EC600 *)D_001A4BE0)->remembered[slot] = 0xCC;
            } else {
                ((H_4EC600 *)D_001A4BE0)->remembered[slot] = ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->item;
            }
        }
        if (((H_4EC600 *)D_001A4BE0)->walk_slow_flag != 0 && D_00142CAD[0] != 0
            && (D_001D4C40[1] != 0xD || ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->item == 0)) {
            ((H_4EC600 *)D_001A4BE0)->request[1] = 0xD;
            if (((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->item != 0) {
                ((H_4EC600 *)D_001A4BE0)->remembered[slot] = ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->item;
            } else {
                ((H_4EC600 *)D_001A4BE0)->remembered[slot] = 0xCC;
            }
        }
    }
    if (slot == 2) {
        u8 *moby = ((H_4EC600 *)D_001A4BE0)->slot[2].moby;

        if (moby != 0) {
            if (((H_4EC600 *)D_001A4BE0)->state_type == 0x11 || ((H_4EC600 *)D_001A4BE0)->state == 0x78
                || ((H_4EC600 *)D_001A4BE0)->state == 0x6C || ((H_4EC600 *)D_001A4BE0)->state == 0x84
                || ((H_4EC600 *)D_001A4BE0)->b2878 != 0) {
                *(s16 *)(((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->moby + 0x7C) = 1;
            } else {
                *(s16 *)(moby + 0x7C) = 0;
            }
        }
    }
    forced = 0;
    if (slot == 3) {
        if (func_L01_004E9308() != 0 || ((H_4EC600 *)D_001A4BE0)->state == 0x12) {
            if (D_001D4C48[1] != 4 && ((H_4EC600 *)D_001A4BE0)->slot[3].item != 4) {
                ((H_4EC600 *)D_001A4BE0)->remembered[3] = ((H_4EC600 *)D_001A4BE0)->slot[3].item;
                forced = 1;
                ((H_4EC600 *)D_001A4BE0)->request[3] = 4;
            }
        } else if (((H_4EC600 *)D_001A4BE0)->slot[3].item == 4 && ((H_4EC600 *)D_001A4BE0)->remembered[3] != 0) {
            ((H_4EC600 *)D_001A4BE0)->restore[3] = 1;
        }
        if (((H_4EC600 *)D_001A4BE0)->state == 8 && D_001D4C40[slot] == 4) {
            if (((G_4EC600 *)D_00142660)->b31 != 0) {
                ((H_4EC600 *)D_001A4BE0)->request[slot] = 3;
            } else {
                ((H_4EC600 *)D_001A4BE0)->request[slot] = 2;
            }
        }
    }
    /* Put back the remembered item */
    if (((H_4EC600 *)D_001A4BE0)->restore[slot] != 0) {
        ((H_4EC600 *)D_001A4BE0)->restore[slot] = 0;
        v = ((H_4EC600 *)D_001A4BE0)->remembered[slot];
        if (v != 0 && v != ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->item) {
            s32 item = v;

            if (v == 0xCC) {
                item = 0;
            }

            if (v != 9) {
                D_001D4C40[slot] = item;
            }
            ((H_4EC600 *)D_001A4BE0)->item[slot] = item;
            ((H_4EC600 *)D_001A4BE0)->remembered[slot] = 0;
            if (slot == 0) {
                ((Row_4EC600 *)D_L01_002C5600)[D_001425C0[((H_4EC600 *)D_001A4BE0)->item[0]]].w20 = 0x20;
            }
            changed = 1;
        }
    }
    if (((H_4EC600 *)D_001A4BE0)->request[slot] == 0x1E) {
        if (func_L01_004EC598() != 0) {
            if (((H_4EC600 *)D_001A4BE0)->guise_timer == 0) {
                ((H_4EC600 *)D_001A4BE0)->h2888 = 1;
                ((H_4EC600 *)D_001A4BE0)->guise_timer = 0x12;
                ((H_4EC600 *)D_001A4BE0)->h288A = 1;
            }
            changed = 1;
        }
        ((H_4EC600 *)D_001A4BE0)->request[slot] = 0;
    }
    if (((H_4EC600 *)D_001A4BE0)->request[slot] == 0x16) {
        func_L01_003415F8(((Row_4EC600 *)D_L01_002C5600)[D_001425C0[0x16]].b1);
        ((H_4EC600 *)D_001A4BE0)->request[slot] = 0;
    }
    if (((H_4EC600 *)D_001A4BE0)->request[slot] != 0) {
        if (((H_4EC600 *)D_001A4BE0)->request[slot] != ((H_4EC600 *)D_001A4BE0)->item[slot]) {
            if (slot == 1
                && (((H_4EC600 *)D_001A4BE0)->h368 == 0 || ((H_4EC600 *)D_001A4BE0)->request[1] == 0xD)
                && ((H_4EC600 *)D_001A4BE0)->remembered[1] == 0) {
                ((G_4EC600 *)D_00142660)->h4C = ((H_4EC600 *)D_001A4BE0)->request[1];
                if (((G_4EC600 *)D_00142660)->h4C == 0xCC) {
                    ((G_4EC600 *)D_00142660)->h4C = 0;
                }
            }
            req = ((H_4EC600 *)D_001A4BE0)->request[slot];
            if (req == 0xCC) {
                ((H_4EC600 *)D_001A4BE0)->item[slot] = 0;
                D_001D4C40[slot] = 0;
            } else {
                ((H_4EC600 *)D_001A4BE0)->item[slot] = req;
                if (forced == 0 || req != 4) {
                    D_001D4C40[slot] = req;
                }
                if (slot == 0) {
                    ((Row_4EC600 *)D_L01_002C5600)[D_001425C0[((H_4EC600 *)D_001A4BE0)->item[0]]].w20 = 0x20;
                }
            }
            changed = 1;
        } else {
            ((H_4EC600 *)D_001A4BE0)->request[slot] = 0;
        }
    }
    if (((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->b1C == 2) {
        changed = 0;
    }
    if (((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->b1C == 1 && ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->b19 == 0) {
        ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->b19 = ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->b1D;
    }
    if (func_L01_0040E020(&((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->b19) == 0) {
        changed = 0;
    }
    /* A gadget waits until its class has streamed in */
    if (slot == 0) {
        if (changed != 0) {
            ((H_4EC600 *)D_001A4BE0)->pending_gadget = ((H_4EC600 *)D_001A4BE0)->item[slot];
            changed = 0;
        }
        if (((H_4EC600 *)D_001A4BE0)->pending_gadget != 0) {
            s32 gadget = ((Row_4EC600 *)D_L01_002C5600)[D_001425C0[((H_4EC600 *)D_001A4BE0)->pending_gadget]].gadget;

            if (func_0039AC08(gadget) == 0) {
                func_0039AA38(gadget);
            } else {
                changed = 1;
                ((H_4EC600 *)D_001A4BE0)->item[slot] = ((H_4EC600 *)D_001A4BE0)->pending_gadget;
                ((H_4EC600 *)D_001A4BE0)->pending_gadget = 0;
            }
        }
    }
    if (changed != 0) {
        ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->held_frames = 3;
        func_L01_004E67C0();
        ((H_4EC600 *)D_001A4BE0)->idle_timer = func_00382498(0x2A, 0x4B);
        func_L01_004EC540(((H_4EC600 *)D_001A4BE0)->item[slot]);
        if (((H_4EC600 *)D_001A4BE0)->firing != 0) {
            func_L01_004EAA80();
        }
        if (slot == 0) {
            if (((H_4EC600 *)D_001A4BE0)->item[0] == 9) {
                ((G_4EC600 *)D_00142660)->wrench_out = 1;
            } else {
                ((G_4EC600 *)D_00142660)->wrench_out = 0;
                switch (((H_4EC600 *)D_001A4BE0)->item[0]) {
                case 0x6F:
                    ((H_4EC600 *)D_001A4BE0)->look_cam_range = 120.0f;
                    break;
                case 0x2F:
                    ((H_4EC600 *)D_001A4BE0)->look_cam_range = 33.0f;
                    break;
                case 0x27:
                    ((H_4EC600 *)D_001A4BE0)->look_cam_range = 20.0f;
                    break;
                case 0x37:
                    ((H_4EC600 *)D_001A4BE0)->look_cam_range = 20.0f;
                    break;
                case 0x3F:
                    ((H_4EC600 *)D_001A4BE0)->look_cam_range = 80.0f;
                    break;
                case 0x4F:
                    ((H_4EC600 *)D_001A4BE0)->look_cam_range = 80.0f;
                    break;
                case 0x87:
                    ((H_4EC600 *)D_001A4BE0)->look_cam_range = 40.0f;
                    break;
                case 0x97:
                    ((H_4EC600 *)D_001A4BE0)->look_cam_range = 60.0f;
                    break;
                default:
                    ((H_4EC600 *)D_001A4BE0)->look_cam_range = 60.0f;
                    break;
                }
            }
        }
        if (slot == 3) {
            if (((H_4EC600 *)D_001A4BE0)->slot[3].item == 3) {
                ((G_4EC600 *)D_00142660)->b31 = 1;
            } else {
                ((G_4EC600 *)D_00142660)->b31 = 0;
            }
        }
        ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->b1A = 0;
        ((H_4EC600 *)D_001A4BE0)->request[slot] = 0;
        ((H_4EC600 *)D_001A4BE0)->wrench_request = 0;
        ((H_4EC600 *)D_001A4BE0)->gun_request = 0;
        held = ((H_4EC600 *)D_001A4BE0)->item[slot];
        if (slot == 0
            && ((Row_4EC600 *)D_L01_002C5600)[D_001425C0[held]].hold_type
                   != ((H_4EC600 *)D_001A4BE0)->hold_type) {
            if (((H_4EC600 *)D_001A4BE0)->hold_layer[0] != 0) {
                *(s32 *)(((H_4EC600 *)D_001A4BE0)->hold_layer[0] + 0x34) = 1;
            }
            if (((H_4EC600 *)D_001A4BE0)->hold_layer[1] != 0) {
                *(s32 *)(((H_4EC600 *)D_001A4BE0)->hold_layer[1] + 0x34) = 1;
            }
        }
        if (((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->moby != 0
            && ((Moby_4EC600 *)((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->moby)->cls[0xC] >= 3) {
            func_003C3A10(((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->moby, 2, 0, 2);
        }
        if (((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->back_moby != 0 && slot != 3
            && ((Moby_4EC600 *)((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->back_moby)->cls[0xC] >= 3) {
            func_003C3A10(((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->back_moby, 2, 0, 2);
        }
        ((HS_4EC600 *)(D_001A4BE0 + slot * 0x50))->hand_state = 3;
    }
    if (slot == 2 && D_001D4C48[0] == 0 && ((H_4EC600 *)D_001A4BE0)->slot[2].moby == 0) {
        ((H_4EC600 *)D_001A4BE0)->request[2] = 0x17;
    }
}
