/* NEAR MISS: func_L01_005138F8 / xp_level_check (src file L01_00512DF8.c since the master split;
   D_001425C0 and D_L01_002C5600 declared here now). 2026-11-22 (round 13, r13_b/x27.c): 178 words
   positional, 76 structural, 41 ignoring registers (round 10: 178 / 88 / 70).
   What closed the gap this round:
   - the item loop indexes D_001425C0[item] and D_00142DE0[item] instead of walking tier/xp
     pointers: loop.c makes the pointers itself, with fresh lui/addiu for both bases after the
     call to func_0040DFC0 as retail has (the prologue now agrees but for one nop);
   - the two "is a gun at level n" tests of the not-in-hand path as
     `if (row.is_weapon == 0 || x < 2) t = 0; else t = 1; ok = t;` with an s32 t and a u8 ok:
     that is retail's branchy value and its `andi 0xff` after the join, and the row recomputed
     after it with lui + mtlo/madd and the 240 hoisted into $fp. The D test now agrees.
     `ok = a && b` (u8 or s32), a ternary, or `ok = t` with `t = a && b` all give movn/movz;
   - `if ((u8)nano >= (missing = max - health))` gives retail's andi-before-subu order.
   Still differs:
   1. The first test (level >= 2): retail keeps `beql $3,$0` on is_weapon right after the
      `is_weapon == 0 -> continue` guard, so the value has two jumps into its join. Here cse1
      knows is_weapon != 0 from the guard (record_jump_equiv) and deletes the test (-ds dump),
      so jump.c turns the rest into sltiu + movz, there is no join, and the later madd sites
      reuse the first tier load instead of reloading it. Same bytes: the guard after the
      value, a saved func_L01_0041A4F0() result tested twice (threaded before cse), a
      do { } while (0) around the value (cse still follows it), D_001425C0[item] in the value
      only (another load, not reduced to the pointer).
   2. The nano block's registers: nano is a user variable and is allocated before health/max
      ($v1 against retail's $a3, the others shift by one). Same bytes: missing declared at
      function scope or before nano, nano block-local. Testing the byte in memory first: 44.
   3. Reorg: the 40-particle loop's bgez has a nop where retail moves the next addiu in; the
      ground_frames test is beqz with the D_001D4C40 lui in its slot (retail: beql with item++,
      the lui later into $a0). `extern s32 D_L01_001DFD38[]` (not small data) keeps its `= 0`
      store out of the b's delay slot as retail has, but moves `move $a0` there instead (46).
   Older notes (hero3/round 10): `lv = D_001A7498; f(lv, lv - 1, ...)` gives the addiu
   $a1,$a0,-4; `u8 nano` read into an s32 with (u8) casts gives the andi; `if (nano >= missing)`
   first arm; `item != 0x7F && item != 9` with the 4c94c0 arm first. The frame counter reads
   lui/lw in the prologue but $gp (0x3290) for the >= 11 test, so that one is D_001DFB40_sda
   with a .extern hint; the cooldown is at -0x828($gp) (0x1DC088), D_001DC088_sda. */
typedef struct {
    u8 pad0[0x8];
    s32 max_health;                /* 0x08: 0x142668, 10 on a new game */
} P_5138F8;
typedef struct {
    u8 is_weapon;                  /* 0x00 */
    u8 level;                      /* 0x01: 0-7, V1 ... Omega */
    u8 pad02[0x08 - 0x02];
    s32 slot;                      /* 0x08: 0 hand, 1 feet, 3 back, 4 body */
    u8 pad0C[0x46 - 0x0C];
    s16 next_row;                  /* 0x46 */
    u8 pad48[0x68 - 0x48];
    s32 xp_next;                   /* 0x68: total XP (1/32 points) to leave the level */
    u8 pad6C[0xF0 - 0x6C];
} W_5138F8;
typedef struct {
    u8 pad0[0x360];
    s32 ground_frames;             /* 0x360: 0 in the air */
    u8 pad364[0x1228 - 0x364];
    s32 held_item;                 /* 0x1228 */
    u8 pad122C[0x2850 - 0x122C];
    s32 health;                    /* 0x2850 */
} H_5138F8;
extern s32 D_L01_001DFB40;
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern s32 D_001DFB40_sda;
extern s32 D_001DC088_sda;
__asm__(".extern D_001DC088_sda, 4");
extern s32 D_L01_001DFD38;
__asm__(".extern D_001DFB40_sda, 4");
extern s32 D_001A7498[];
extern u8 D_001426B0[];
extern u8 D_001426E0[];
extern u16 D_001A7E18[];
extern s32 D_001D4C40[];
extern s32 D_00142DE0[];
extern Vec4 D_001A4CC0;
extern s32 func_L01_00418D48(s32 item);
extern void func_L01_00418C90(s32 item, s32 show);
extern void func_L01_00419318(s32 item);
extern void func_L01_004C94C0(s32 item, s32 next_row);
extern void func_L01_00451F60(s32 msg, s32 frames, s32 line);
extern void func_L01_0041BE28(s32 msg, s32 help);
extern void func_L01_00318408(void);
extern void func_L01_00391610(void);
extern void func_L01_0047B470(s32 a0);
extern void func_0047B388(s32 frames);
extern void func_004AAD58(s32 a0, s32 a1, s32 a2);
extern void func_0040DFC0(s32 *timer);
extern void func_00443C30(f32 *v, f32 a, f32 b);
extern s32 func_00443948(s32 n);
extern void func_L01_0046C470(Vec4 *pos, f32 *velocity, s32 colour, s32 life, u8 roll, s32 t1, s32 t2,
                              s32 t3, f32 size);

/* xp_level_check: each frame but one in sixteen, the hero's max health (10, plus the flags
   at D_001426B0, plus the levels his XP reaches), the Nano-pak's refill below a tenth of it,
   and each gun's level-up by XP: in hand and on the ground through weapon_upgrade_start, else
   at once with weapon_level_message. Sixty frames between (level_up_cooldown). */
void func_L01_005138F8(void) {
    s32 max_health;
    s32 i;
    s32 item;
    s32 level_cap;
    s32 k;
    s32 nano;
    u8 ok;
    s32 t;
    W_5138F8 *row;
    Vec4 velocity;
    s32 frame = D_L01_001DFB40;
    s32 *lv;

    if ((frame & 0xF) == 1 && frame != 1) {
        return;
    }
    lv = D_001A7498;
    max_health = 10;
    func_L01_00513800(lv, lv - 1, &max_health);
    for (i = 0; i < 10; i++) {
        if (D_001426B0[i] != 0) {
            max_health++;
        }
    }
    if (((P_5138F8 *)&D_00142660)->max_health != max_health) {
        if (D_001DFB40_sda >= 11 && ((P_5138F8 *)&D_00142660)->max_health < max_health) {
            if (D_001A7E18[0] == 0) {
                func_L01_0041BE28(0x7AF, 0);
            }
            func_L01_00318408();
            func_0047B388(300);
            func_004AAD58(6, 0, 0);
            if (max_health == 200) {
                func_L01_00451F60(0x12B2, -1, 0);
            } else {
                func_L01_00451F60(0x6C8, -1, 0);
            }
        }
        ((P_5138F8 *)&D_00142660)->max_health = max_health;
        if (D_001426E0[0xBB] == 0 && max_health >= 200) {
            func_L01_00451F60(0x12B2, -1, 0);
            D_001426E0[0xBB] = 1;
        }
    }

    /* the Nano-pak: below a tenth of max health, it refills him from its reserve */
    if (((H_5138F8 *)&D_001A4BE0)->health <= (s32)((f32)((P_5138F8 *)&D_00142660)->max_health * 0.1f)) {
        nano = D_001426E0[0xD3];
        if (nano != 0) {
            s32 missing;

            if ((u8)nano >= (missing = ((P_5138F8 *)&D_00142660)->max_health - ((H_5138F8 *)&D_001A4BE0)->health)) {
                ((H_5138F8 *)&D_001A4BE0)->health = ((P_5138F8 *)&D_00142660)->max_health;
                D_001426E0[0xD3] = nano - missing;
            } else {
                D_001426E0[0xD3] = 0;
                ((H_5138F8 *)&D_001A4BE0)->health = ((H_5138F8 *)&D_001A4BE0)->health + (u8)nano;
            }
            func_L01_0047B470(0);
            for (k = 39; k >= 0; k--) {
                func_00443C30(velocity.f, 0.020000001f, 0.040000003f);
                func_L01_0046C470(&D_001A4CC0, velocity.f, 0x50804040, 60,
                                  (u8)func_00443948(0xFF), 1, 64, 0, 0.5f);
                func_L01_0046C470(&D_001A4CC0, velocity.f, 0x407F7F7F, 60,
                                  (u8)func_00443948(0xFF), 1, 64, 0, 0.25f);
            }
        }
    }

    /* the wrench's row (item 9) follows max health */
    if ((u32)(((P_5138F8 *)&D_00142660)->max_health - 15) < 25) {
        D_001425C0[9] = 0xA4;
    } else if ((u32)(((P_5138F8 *)&D_00142660)->max_health - 40) < 20) {
        D_001425C0[9] = 0xA5;
    } else if ((u32)(((P_5138F8 *)&D_00142660)->max_health - 60) < 20) {
        D_001425C0[9] = 0xC6;
    } else if ((u32)(((P_5138F8 *)&D_00142660)->max_health - 80) < 25) {
        D_001425C0[9] = 0xC7;
    } else if ((u32)(((P_5138F8 *)&D_00142660)->max_health - 105) < 35) {
        D_001425C0[9] = 0xC8;
    } else if ((u32)(((P_5138F8 *)&D_00142660)->max_health - 140) < 40) {
        D_001425C0[9] = 0xC9;
    } else if (((P_5138F8 *)&D_00142660)->max_health >= 180) {
        D_001425C0[9] = 0xCA;
    }

    func_0040DFC0(&D_001DC088_sda);
    for (item = 0; item < 156; item++) {
        level_cap = func_L01_00418D48(item);
        if (func_L01_0041A4F0() == 0) {
            if (level_cap >= 5) {
                level_cap = 4;
            }
        }
        if (((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].is_weapon != 0 && ((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].level == level_cap) {
            continue;
        }
        if (func_L01_0041A4F0() != 0 && ((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].level == 7) {
            continue;
        }
        if (func_L01_00418D48(item) <= 0) {
            continue;
        }
        if (D_001DC088_sda != 0) {
            continue;
        }
        if ((D_00142DE0[item] >> 5) < ((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].xp_next) {
            continue;
        }
        if (((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].xp_next <= 0) {
            continue;
        }
        if (item == 9) {
            continue;
        }
        if (((H_5138F8 *)&D_001A4BE0)->held_item == item) {
            if (((H_5138F8 *)&D_001A4BE0)->ground_frames == 0) {
                continue;
            }
            if (D_001D4C40[((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].slot] != item) {
                continue;
            }
            if (item != 0x7F && item != 9) {
                D_L01_001DFD38 = 1;
                func_L01_004C94C0(item, ((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].next_row);
                D_001DC088_sda = 50;
                D_L01_001DFD38 = 0;
            } else {
                func_L01_00418C90(item, 0);
                func_L01_00419318(item);
                D_001DC088_sda = 50;
                func_L01_00391610();
            }
            continue;
        }
        if (func_L01_0041A4F0() != 0) {
            if (((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].is_weapon == 0) {
                continue;
            }
            if (((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].is_weapon == 0 || ((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].level < 2) {
                t = 0;
            } else {
                t = 1;
            }
            ok = t;
            if (!ok && ((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].level >= 4) {
                continue;
            }
            if (((W_5138F8 *)D_L01_002C5600)[D_001425C0[item]].is_weapon == 0 || func_L01_00418D48(item) < 2) {
                t = 0;
            } else {
                t = 1;
            }
            ok = t;
            if (!ok) {
                continue;
            }
        }
        func_L01_00418C90(item, 0);
        func_L01_00419318(item);
        D_001DC088_sda = 50;
    }
}
