/* NEAR MISS (hero_walk_anim, func_L01_005063E8): ck prints 159 diff lines raw, but only ~45 of 270
   words differ after alignment (al.py). Frame, saved registers, control flow, constants, the
   boolean `below`, the switch dispatch and the shared clamp tails all match. What still differs:
   (1) prologue/mode arms: retail copies the lui into $s1 before the critter_mode load (lbu into $v0)
       and, in the mode==3 arm, loads the $gp scale first and speed last (delay slot); ours loads speed first.
   (2) inner `if (below)`: retail is a plain `beqz $a0` reached unthreaded from `bnez $a0`, and the
       B-fail branch is `bc1fl` with the walk pointer in its delay slot; `below == 1` (the only wording
       that stops gcc threading it) gives `li $v0,1; bne` instead.
   (3) the up loop is strength-reduced here (addiu 0x10 pointer) but not in retail (sll/addu each pass),
       and the final `sw substate` goes through $a1 (live pointer) in retail, a rebuilt address here.
   (4) key block: new substate in $a3 here vs $a2 in retail (swaps a2/a3, a1/v1 roles in the key maths).
   Needs `func_L01_005063E8 2` in config/levels/divs_nops.txt (appended). */
__asm__(".extern D_001DBD50_sda, 4");
__asm__(".extern D_001DBE00_sda, 4");
__asm__(".extern D_001DBE20_sda, 4");
extern f32 D_001DBD50_sda;
extern f32 D_001DBE00_sda[] __attribute__((section(".sdata")));
extern s32 D_001DBE20_sda[2][2] __attribute__((section(".sdata")));
extern u8 D_001A4BE0[];
extern f32 D_001DBE04[];
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);

typedef struct {
    u8 pad0[0x10];
    u8 keyframes;
} Seq_5063E8;

typedef struct {
    u8 pad0[0x24];
    u8 *pclass;
    u8 pad28[0x41 - 0x28];
    u8 keyframe;
    u8 pad42[0x43 - 0x42];
    u8 sequence;
} Moby_5063E8;

typedef struct {
    u8 pad0[0x170];
    f32 speed_own_a;
    u8 pad174[0x1B4 - 0x174];
    f32 speed;
    u8 pad1B8[0x1C0 - 0x1B8];
    s32 unk_1C0;
    u8 pad1C4[0x3EE - 0x1C4];
    u8 frozen;
    u8 pad3EF[0xC00 - 0x3EF];
    f32 anim_rate;
    u8 pad_C04[0x1434 - 0xC04];
    s16 lockon_strafing;
    u8 lockon_strafe_back;
    u8 pad1437[0x16B0 - 0x1437];
    s32 camera_mode;
    u8 pad16B4[0x25C0 - 0x16B4];
    Moby_5063E8 *moby;
    s32 state;
    s32 substate;
    u8 pad25CC[0x25E4 - 0x25CC];
    u8 critter_mode;
} H_5063E8;

/* hero_walk_anim */
void func_L01_005063E8(void) {
    H_5063E8 *hero = (H_5063E8 *)D_001A4BE0;
    f32 scale;
    f32 floor;
    f32 rate;
    f32 ceiling;
    f32 cur;
    H_5063E8 *walk;

    if (hero->critter_mode == 3) {
        rate = hero->speed_own_a;
        scale = D_001DBD50_sda;
        floor = 0.7f;
    } else if (hero->critter_mode == 1) {
        rate = hero->speed_own_a;
        scale = 75.0f;
        floor = 0.5f;
    } else {
        goto rest;
    }
    rate *= scale;
    hero->anim_rate = rate;
    if (rate < floor) {
        hero->anim_rate = floor;
    }
    return;
rest:
    if (hero->lockon_strafing != 0 || (hero->camera_mode == 3 && func_L01_004606E8(0x28, 2, 0, 0) != 0)) {
        if (hero->lockon_strafe_back != 0) {
            if (hero->moby->sequence != 20) {
                func_L01_0050FB40(20, 0, 9.0f);
            }
            rate = hero->speed * 5.0f / 6.0f * 25.0f;
            hero->anim_rate = rate;
            if (rate < 0.7f) {
                hero->anim_rate = 0.7f;
            }
            if (2.2f < hero->anim_rate) {
                hero->anim_rate = 2.2f;
            }
            return;
        }
    }
    if (((H_5063E8 *)D_001A4BE0)->moby->sequence == 20) {
        func_L01_0050FB40(((H_5063E8 *)D_001A4BE0)->substate + 3, 0, 6.0f);
    } else if (((H_5063E8 *)D_001A4BE0)->unk_1C0 >= 4 && ((H_5063E8 *)D_001A4BE0)->frozen == 0) {
        s32 c0 = ((H_5063E8 *)D_001A4BE0)->substate;
        s32 c;
        s32 below;
        f32 lo;
        lo = D_001DBE00_sda[c0 * 4] * 0.020000001f;
        below = ((H_5063E8 *)D_001A4BE0)->speed < lo;
        if (below || D_001DBE04[c0 * 4] * 0.020000001f < ((H_5063E8 *)D_001A4BE0)->speed) {
            if (below == 1) {
                while (((H_5063E8 *)D_001A4BE0)->speed < D_001DBE00_sda[((H_5063E8 *)D_001A4BE0)->substate * 4] * 0.020000001f) {
                    ((H_5063E8 *)D_001A4BE0)->substate--;
                }
            } else if (D_001DBE04[c0 * 4] * 0.020000001f < ((H_5063E8 *)D_001A4BE0)->speed) {
                c = c0;
                do {
                    c++;
                } while (D_001DBE04[c * 4] * 0.020000001f < ((H_5063E8 *)D_001A4BE0)->speed);
                ((H_5063E8 *)D_001A4BE0)->substate = c;
            }
        }
        if (((H_5063E8 *)D_001A4BE0)->substate < 0) {
            ((H_5063E8 *)D_001A4BE0)->substate = 0;
        }
        if (((H_5063E8 *)D_001A4BE0)->substate >= 2) {
            ((H_5063E8 *)D_001A4BE0)->substate = 1;
        }
        if (((H_5063E8 *)D_001A4BE0)->substate != c0) {
            Moby_5063E8 *m = ((H_5063E8 *)D_001A4BE0)->moby;
            Seq_5063E8 **seqs = (Seq_5063E8 **)(m->pclass + 0x48);
            s32 new_id = ((H_5063E8 *)D_001A4BE0)->substate + 3;
            s32 old_id = c0 + 3;
            Seq_5063E8 *new_seq = seqs[new_id];
            Seq_5063E8 *old_seq = seqs[old_id];
            s32 key = (m->keyframe * new_seq->keyframes / old_seq->keyframes + D_001DBE20_sda[c0][((H_5063E8 *)D_001A4BE0)->substate]) % new_seq->keyframes;
            func_L01_0050FB40(new_id, key, 7.0f);
        }
    }
    walk = (H_5063E8 *)D_001A4BE0;
    walk = (H_5063E8 *)D_001A4BE0;
    switch (walk->substate) {
    case 0:
        rate = walk->speed;
        scale = 130.83333f;
        floor = 0.6f;
        rate *= scale;
        walk->anim_rate = rate;
        if (rate < floor) {
            walk->anim_rate = floor;
        }
        ceiling = 4.0f;
        cur = walk->anim_rate;
        break;
    case 1:
        rate = walk->speed;
        scale = 10.833333f;
        floor = 0.6f;
        rate *= scale;
        walk->anim_rate = rate;
        if (rate < floor) {
            walk->anim_rate = floor;
        }
        cur = walk->anim_rate;
        ceiling = 2.2f;
        break;
    default:
        return;
    }
    if (ceiling < cur) {
        walk->anim_rate = ceiling;
    }
}
