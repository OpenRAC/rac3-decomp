#include "common.h"

/* NTSC-U counterpart of func_L01_004E7CB8 (src/levels/shared/L01_004E7338.c): 75 -> 90 */
/* localdecomp:start func_L01_004E3EF0 */
extern u8 D_001A4BE0[];
extern s32 D_00142668[];
extern u8 D_00142CAD[];
extern void func_0038CBA0(void *p, s32 n);
extern void func_L01_004E3EC0(void);
extern void func_L01_004DC1C0(s32 damage);
extern void func_L01_004FC518(s32 state, s32 flag);

/* hero_floor_material: reacts to the ground's collision material (the ground probe's
   s16 at hero+0x1470): 1 lava, 3 quicksand, 4 slide, 7, 11, 13, 14 puddle, 0 water, 17
   hazard; sets the surface flags the hero's states read, and changes state when the
   material says so. */
void func_L01_004E3EF0(void) {
    u8 *hero = D_001A4BE0;
    s32 material = *(s16 *)(hero + 0x1470);
    u8 keep = hero[0x147F];
    s32 landed;
    s32 state;
    f32 pz;
    f32 water;
    f32 depth;

    /* clear the material's flags; the material and the byte at 0x147F are kept */
    func_0038CBA0(hero + 0x1470, 16);
    hero[0x147F] = keep;
    *(s16 *)(hero + 0x1470) = material;
    hero[0x25EA] = 0; /* wading */
    *(s16 *)(hero + 0x368) = 0;
    if (hero[0x25EE] != 0) {
        return;
    }
    /* landed: on the ground this frame, or a landing from state 128 */
    landed = 0;
    if (*(s32 *)(hero + 0x360) != 0 || (*(s32 *)(hero + 0x25C4) == 0x80 && *(f32 *)(hero + 0x33C) < 0.4f)) {
        landed = 1;
    }
    if (material == -1) {
        return;
    }

    /* materials 2, 0x11, 0x12: walking slow in some cases */
    if (material == 2 || material == 0x11 || material == 0x12) {
        u8 *h = D_001A4BE0;
        if (*(s16 *)(h + 0x1DE) == 0 && (*(s16 *)(h + 0x36C) == 0 || *(f32 *)(h + 0x33C) < 2.5f)) {
            h[0x1479] = 1;
            if (h[0x25E4] == 0 && D_00142CAD[0] != 0) {
                *(s16 *)(h + 0x368) = 1;
            }
        }
    }

    /* material 17: a hazard hurts him, once per 90 frames, and holds him (state 177) */
    if (material == 0x11) {
        u8 *h = D_001A4BE0;
        if (*(s16 *)(h + 0x1DC) == 0 && *(s16 *)(h + 0x36C) == 0 && *(s32 *)(h + 0x25CC) != 7) {
            func_L01_004DC1C0(D_00142668[0] / 8);
            *(s16 *)(h + 0x1DC) = 90;
            func_L01_004FC518(0xB1, 1);
        }
    }

    /* material 14: a puddle, 0.2 u deep */
    if (material == 0xE) {
        u8 *h = D_001A4BE0;
        h[0x1476] = 1;
        *(f32 *)(h + 0x2848) = 0.2f;
        *(f32 *)(h + 0x350) = *(f32 *)(h + 0x338) + 0.2f;
    }

    /* material 0: water; wading when it is 0.25 to 0.85 u deep */
    if (material == 0) {
        u8 *h = D_001A4BE0;
        depth = *(f32 *)(h + 0x350) - *(f32 *)(h + 0x338);
        *(f32 *)(h + 0x2848) = depth;
        if (depth < 0.85f && 0.25f < depth) {
            h[0x25EA] = 1;
        }
        D_001A4BE0[0x1476] = 1;
    }

    if (material == 3) {
        u8 *h = D_001A4BE0;
        h[0x1478] = 1;
    }
    if (material == 0xB) {
        u8 *h = D_001A4BE0;
        h[0x147D] = 1;
    }
    if (material == 4) {
        u8 *h = D_001A4BE0;
        h[0x1475] = 1;
    }
    if (material == 7) {
        u8 *h = D_001A4BE0;
        h[0x1474] = 1;
    }
    if (material == 0xD) {
        u8 *h = D_001A4BE0;
        h[0x147E] = 1;
    }
    if (material == 1) {
        u8 *h = D_001A4BE0;
        h[0x1477] = material;
    }
    if (material == 8 || material == 0x12) {
        u8 *h = D_001A4BE0;
        h[0x147C] = 1;
    }
    if (material == 0xC) {
        u8 *h = D_001A4BE0;
        h[0x147C] = 1;
    }

    /* material 4: the slide, unless he is in a state that can't slide */
    if (D_001A4BE0[0x1475] != 0 && landed) {
        s32 type = *(s32 *)(D_001A4BE0 + 0x25CC);
        if (type != 0x10 && type != 0x14 && type != 7) {
            func_L01_004FC518(0x30, 1);
            return;
        }
    }

    /* lava */
    if (D_001A4BE0[0x1477] != 0 && landed) {
        u8 *h = D_001A4BE0;
        if (h[0x25E4] == 1 && *(s32 *)(h + 0x25C4) != 0x7F) {
            func_L01_004FC518(0x7F, 1);
            return;
        }
    }
    if (D_001A4BE0[0x1477] != 0 && landed) {
        u8 *h = D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) != 0x38 || h[0x46E] != 0) {
            func_L01_004E3EC0();
            if (*(s32 *)(h + 0x2850) != 0) {
                func_L01_004FC518(0x38, 1);
                return;
            }
            if (*(s32 *)(*(u8 **)(*(u8 **)(h + 0x25C0) + 0x24) + 0x1A8) != 0) {
                func_L01_004FC518(0x7E, 1);
                return;
            }
            func_L01_004FC518(0x39, 1);
            return;
        }
    }

    if (D_001A4BE0[0x25E4] == 1) {
        /* critter mode: 0x50 */
        u8 *h = D_001A4BE0;
        if (h[0x147E] != 0 && *(s32 *)(h + 0x25C4) != 0x50) {
            pz = *(f32 *)(h + 0x88);
            water = *(f32 *)(h + 0x350);
            if (__builtin_fabsf(water - (pz + 0.15f)) < 0.5f && 0.0f < water - pz) {
                if (*(f32 *)(h + 0x118) < 0.0f || *(s32 *)(h + 0x25C4) == 0x80) {
                    func_L01_004FC518(0x50, 1);
                    return;
                }
            }
        }
    } else {
        /* other: 0x81 */
        u8 *h = D_001A4BE0;
        if (h[0x147E] != 0 && *(s32 *)(h + 0x25C4) != 0x81) {
            pz = *(f32 *)(h + 0x88);
            water = *(f32 *)(h + 0x350);
            if (__builtin_fabsf(water - (pz + 0.25f)) < 1.0f && 0.0f < water - pz) {
                if (*(f32 *)(h + 0x118) < 0.0f || *(s32 *)(h + 0x25C4) == 0x80) {
                    func_L01_004E3EC0();
                    func_L01_004FC518(0x81, 1);
                    return;
                }
            }
        }
    }

    /* quicksand: state 106, or 125 when health is gone (two whole calls: retail merges their
       tails and keeps one `jal`) */
    if (D_001A4BE0[0x1478] != 0 && *(s32 *)(D_001A4BE0 + 0x25C4) != 0x6A && *(s32 *)(D_001A4BE0 + 0x25C4) != 0x7D) {
        u8 *h = D_001A4BE0;
        pz = *(f32 *)(h + 0x88);
        water = *(f32 *)(h + 0x354);
        if (__builtin_fabsf(water - (pz + 0.25f)) < 1.0f && 0.0f < water - pz) {
            if (*(s32 *)(h + 0x25C4) != 0x6B || h[0x46E] != 0) {
                if (*(f32 *)(h + 0x118) < 0.0f || *(s32 *)(h + 0x25C4) == 0x80) {
                    func_L01_004E3EC0();
                    if (*(s32 *)(h + 0x2850) == 0) {
                        func_L01_004FC518(0x7D, 1);
                    } else {
                        func_L01_004FC518(0x6A, 1);
                    }
                    return;
                }
            }
        }
    }

    /* material 11: sink in quicksand */
    if (D_001A4BE0[0x147D] != 0) {
        u8 *h = D_001A4BE0;
        state = *(s32 *)(h + 0x25C4);
        if (state != 0x7D && state != 0x79) {
            pz = *(f32 *)(h + 0x88);
            water = *(f32 *)(h + 0x354);
            if (__builtin_fabsf(water - (pz + 0.25f)) < 1.0f && 0.0f < water - pz) {
                if (*(f32 *)(h + 0x118) < 0.0f || state == 0x80) {
                    func_L01_004E3EC0();
                    func_L01_004FC518(0x7D, 1);
                }
            }
        }
    }
}
/* localdecomp:end func_L01_004E3EF0 */
