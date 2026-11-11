/* NEAR MISS (not a MATCH): func_L01_005138F8 xp_level_check, 178 differing lines at level_01 (was 318 in hero3).
   Structure agrees with retail except the points below; the rest of the diff is register numbers
   that follow from them.
   1. In the not-in-hand path retail builds ok = (is_weapon && level >= 2) as a branchy value (u8, a join at
      L24, so the row/base/240 are recomputed after it, with lui+mtlo+madd and a hoisted 240 in $fp), and it
      keeps a second test of is_weapon right after the `if (is_weapon == 0) continue;` guard. Here gcc
      deletes that second test (CSE) and turns the rest into sltiu+movn, so no join, and the later blocks
      reuse the first block's 240/base instead.
   2. `D_L01_001DFD38 = 0` ends the item-0x7F/9 else-arm: gcc puts the sw in the `b`'s delay slot, where the
      assembler turns it into a $gp store; retail has lui $at/sw before the branch and the loop's item++ in
      the slot.
   3. Loop prologue: gcc also hoists &D_001D4C40 (retail does not) and lacks retail's hoisted 240 ($fp).
   4. The top: nano/max/health registers are shifted by one ($a2/$a3/$v1 against retail's $a1/$a2/$a3).
   Found: `lv = D_001A7498; f(lv, lv - 1, ...)` gives the addiu $a1,$a0,-4; the item loop wants no row
   pointer, `tier`/`xp` pointer inductions and the row spelled out at each use; `u8 nano` read into an
   s32 with (u8) casts gives the andi; `if (nano >= missing)` first arm; `item != 0x7F && item != 9`
   with the 4c94c0 arm first. */
/* NOT A MATCH (skipped): best attempt, 318 differing lines at level_01 (check.py).
   Still wrong: the start (&D_001A7498 - 1 is folded into a second lui/addiu, retail uses
   addiu from the first), register allocation throughout, and the item loop's branch shape.
   Gates: the frame counter reads lui/lw in the prologue but $gp (0x3290) for the >= 11 test,
   so that one uses D_001DFB40_sda with a .extern hint; the cooldown is at -0x828($gp)
   (0x1DC088), D_001DC088_sda. */
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
    W_5138F8 *row;
    Vec4 velocity;
    s32 frame = D_L01_001DFB40;
    s32 *lv;
    u8 *tier;
    s32 *xp;

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
            s32 missing = ((P_5138F8 *)&D_00142660)->max_health - ((H_5138F8 *)&D_001A4BE0)->health;

            if ((u8)nano >= missing) {
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
    for (item = 0, tier = D_001425C0, xp = D_00142DE0; item < 156; item++, xp++, tier++) {
        level_cap = func_L01_00418D48(item);
        if (func_L01_0041A4F0() == 0) {
            if (level_cap >= 5) {
                level_cap = 4;
            }
        }
        if (((W_5138F8 *)D_L01_002C5600)[*tier].is_weapon != 0 && ((W_5138F8 *)D_L01_002C5600)[*tier].level == level_cap) {
            continue;
        }
        if (func_L01_0041A4F0() != 0 && ((W_5138F8 *)D_L01_002C5600)[*tier].level == 7) {
            continue;
        }
        if (func_L01_00418D48(item) <= 0) {
            continue;
        }
        if (D_001DC088_sda != 0) {
            continue;
        }
        if ((*xp >> 5) < ((W_5138F8 *)D_L01_002C5600)[*tier].xp_next) {
            continue;
        }
        if (((W_5138F8 *)D_L01_002C5600)[*tier].xp_next <= 0) {
            continue;
        }
        if (item == 9) {
            continue;
        }
        if (((H_5138F8 *)&D_001A4BE0)->held_item == item) {
            if (((H_5138F8 *)&D_001A4BE0)->ground_frames == 0) {
                continue;
            }
            if (D_001D4C40[((W_5138F8 *)D_L01_002C5600)[*tier].slot] != item) {
                continue;
            }
            if (item != 0x7F && item != 9) {
                D_L01_001DFD38 = 1;
                func_L01_004C94C0(item, ((W_5138F8 *)D_L01_002C5600)[*tier].next_row);
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
            if (((W_5138F8 *)D_L01_002C5600)[*tier].is_weapon == 0) {
                continue;
            }
            ok = ((W_5138F8 *)D_L01_002C5600)[*tier].is_weapon != 0 && ((W_5138F8 *)D_L01_002C5600)[*tier].level >= 2;
            if (!ok && ((W_5138F8 *)D_L01_002C5600)[*tier].level >= 4) {
                continue;
            }
            ok = ((W_5138F8 *)D_L01_002C5600)[*tier].is_weapon != 0 && func_L01_00418D48(item) >= 2;
            if (!ok) {
                continue;
            }
        }
        func_L01_00418C90(item, 0);
        func_L01_00419318(item);
        D_001DC088_sda = 50;
    }
}
