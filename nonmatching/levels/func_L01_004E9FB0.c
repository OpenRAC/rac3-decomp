/* NEAR MISS: func_L01_004E9FB0 (hero_hold_layers_update).
 * Level 01: 415 words against retail's 417, check.py reports 305 differing (positional) words;
 * with the listings aligned by text, about 67 words differ. Structure, branch layout, stack
 * layout and callee-saved registers (hero in $fp, i in $s7, layer $s1, ...) match. What differs:
 *   - the temp register names in a few spots ($a0/$v1 for the two lui halves at the top, the
 *     layer pointer in the no_hold block, the spring base $a1 vs $v0, kind in $v1 vs $a0);
 *   - the k-loops (both arms): retail's counter is $t0 and the 0x600 pointer $a3, ours swapped;
 *     retail also has an alignment nop before each k-loop that follows once sizes agree;
 *   - the changed-block's hero base: retail rematerialises it ($a2, lui/addiu in the delay slot
 *     of the beqz); ours reads it from $fp (making it a rematerialised direct
 *     ((H *)D_001A4BE0) loses the $fp allocation to the &layer->anim pointer);
 *   - `sltu $s2` in ours, `sltu $v0; move $s2,$v0` in retail (one word);
 *   - spill slots: ours i+1 at 4($sp), retail anim pointer at 4, i+1 at 8, low pointer at 0xC.
 * New externs vs the src file: func_003C4138 (core f32 step function), func_L01_004DFE80,
 * D_001A5A50, D_L01_002F4540, D_L01_00254080, D_L01_00257080 (all unique to this function).
 * D_L01_001FD180 and D_L01_001FDBD0 agree with the file's lines 1092-1093. */
__asm__(".extern D_L01_001DBD48, 8");
__asm__(".extern D_L01_001DBDA0, 8");
extern s32 D_L01_001DBD48[2];
extern s32 D_L01_001DBDA0[2];
extern u8 D_001A4BE0[];
extern u8 D_L01_001FDBD0[];
extern u8 *D_L01_001FD180[];
extern u8 D_L01_00254080[];
extern u8 D_L01_00257080[];
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_L01_004DFE80(s32);
extern u8 *func_L01_00439CB8(void *, s32, s32, s32);
extern void func_L01_00439D70(M004E9888 *, s32 *);
extern void func_L01_00439E10(u8 *, u8 *);
extern s32 func_L01_004E9358(u8 *, s32);
extern s32 func_L01_004E9370(s32, f32 *);

typedef struct {
    u8 pad0[0x40];
    u8 keyframe[2];               /* 0x40: the previous keyframe, then the keyframe it plays */
    u8 sequence[2];               /* 0x42: [1] is the sequence it plays */
    f32 time;                     /* 0x44 */
} M_4E9FB0;

typedef struct {
    u8 pad0[6];
    u8 low[2];                    /* 0x06: 1 while the side's sequence is below 23 */
    f32 weight;                   /* 0x08: the side's weight, approached to its target */
    u8 pad0C[0x18 - 0x0C];
    u8 *hold_class;               /* 0x18 */
    u8 pad1C[0x20 - 0x1C];
    u8 keyframe[2];               /* 0x20: from, to */
    u8 sequence[2];               /* 0x22: from, to */
    f32 time;                     /* 0x24 */
    f32 blend;                    /* 0x28 */
    f32 blend_rate;               /* 0x2C */
    s16 changing;                 /* 0x30 */
    u8 blending;                  /* 0x32 */
    u8 set_seq;                   /* 0x33 */
    s32 leaving;                  /* 0x34 */
    u8 *anim[2];                  /* 0x38 */
} L_4E9FB0;

typedef struct {
    u8 pad0[0xC0C];
    s32 unk_C0C;
    u8 padC10[0xE78 - 0xC10];
    s32 fire_layer;               /* 0xE78 */
    u8 padE7C[0xE84 - 0xE7C];
    s32 fire_fade;                /* 0xE84 */
    u8 padE88[0x25C0 - 0xE88];
    M_4E9FB0 *moby;               /* 0x25C0 */
    u8 pad25C4[0x25EC - 0x25C4];
    u8 hold_type;                 /* 0x25EC */
    u8 pad25ED[0x25F0 - 0x25ED];
    u8 no_hold;                   /* 0x25F0 */
} H_4E9FB0;

typedef struct {
    u8 pad0[0x5E4];
    f32 other_target_y;           /* 0x5E4 */
    u8 pad5E8[0x624 - 0x5E8];
    f32 other_gain;               /* 0x624 */
    f32 other_damping;            /* 0x628 */
    u8 pad62C[0x694 - 0x62C];
    f32 gun_target_y;             /* 0x694 */
    u8 pad698[0x6D4 - 0x698];
    f32 gun_gain;                 /* 0x6D4 */
    f32 gun_damping;              /* 0x6D8 */
} Springs_4E9FB0;

extern L_4E9FB0 *D_001A5A50[];
extern Springs_4E9FB0 D_L01_002F4540;

/* hero_hold_layers_update: the two arm hold layers, one frame of them (the Rust's HoldLayer::step). */
void func_L01_004E9FB0(void)
{
    L_4E9FB0 *layer;
    s32 i;
    s32 j;
    s32 k;
    s32 want;
    s32 changed;
    s32 changing;
    s32 kind;
    f32 offset;
    H_4E9FB0 *hero = (H_4E9FB0 *)D_001A4BE0;

    for (i = 0; i < 2; i++) {
        if (D_001A5A50[i] != 0 && D_001A5A50[i]->leaving != 0) {
            if (func_003C4138(&D_001A5A50[i]->weight, 0.0f, 0.120000005f) == 0.0f) {
                func_L01_00439D70((M004E9888 *)hero->moby, (s32 *)&D_001A5A50[i]);
            }
        } else {
            want = 0;
            if (hero->hold_type != 0 && (i == 0 || hero->hold_type == 2)) {
                want = 1;
            }
            if (((H_4E9FB0 *)D_001A4BE0)->no_hold != 0) {
                if (D_001A5A50[i] != 0) {
                    D_001A5A50[i]->leaving = 1;
                }
                want = 0;
            }
            if (want != 0) {
                H_4E9FB0 *p = (H_4E9FB0 *)D_001A4BE0;

                if (D_001A5A50[i] == 0) {
                    D_001A5A50[i] = (L_4E9FB0 *)func_L01_00439CB8(p->moby, D_L01_001DBD48[i], D_L01_001DBDA0[i], 0x3C0);
                    D_001A5A50[i]->weight = 0.0f;
                    D_001A5A50[i]->hold_class = D_L01_001FD180[D_L01_001FDBD0[i + 1]];
                }
            } else {
                H_4E9FB0 *p = (H_4E9FB0 *)D_001A4BE0;

                if (D_001A5A50[i] == 0) {
                    continue;
                }
                if (func_003C4138(&D_001A5A50[i]->weight, 0.0f, 0.18f) == 0.0f) {
                    func_L01_00439D70((M004E9888 *)p->moby, (s32 *)&D_001A5A50[i]);
                }
            }
        }
        layer = D_001A5A50[i];
        if (layer == 0) {
            continue;
        }

        {
            H_4E9FB0 *pd = hero;

            changed = (pd->moby->sequence[0] ^ pd->moby->sequence[1]) != 0;
            if (pd->fire_layer != 0 && pd->fire_fade == 0) {
                func_003C4138(&layer->weight, 0.0f, 0.18f);
            } else if (layer->leaving == 0) {
                func_003C4138(&layer->weight, 1.0f, 0.3f);
            }
        }

        changing = 0;
        if (changed != 0) {
            H_4E9FB0 *pe = (H_4E9FB0 *)D_001A4BE0;

            if (pe->unk_C0C != 0) {
                if (func_L01_004DFE80(layer->sequence[1]) != func_L01_004DFE80(pe->moby->sequence[1])) {
                    changing = (layer->sequence[0] ^ layer->sequence[1]) != 0;
                }
            }
        }
        layer->changing = changing;

        kind = func_L01_004E9370(hero->moby->sequence[1], &offset);
        if (kind != 0 || layer->blending != 0) {
            if (offset != 0.0f) {
                f32 gain = 0.072000004f;
                f32 damping = 0.43200004f;

                D_L01_002F4540.other_target_y = offset;
                D_L01_002F4540.gun_gain = gain;
                D_L01_002F4540.gun_damping = damping;
                D_L01_002F4540.gun_target_y = offset;
                D_L01_002F4540.other_gain = gain;
                D_L01_002F4540.other_damping = damping;
            }
            if (kind != 0) {
                if (layer->blending == 0 || layer->sequence[1] != 0) {
                    if (layer->sequence[0] == layer->sequence[1] || layer->time > 0.5f) {
                        layer->sequence[0] = layer->sequence[1];
                        layer->keyframe[0] = layer->keyframe[1];
                    }
                    layer->blending = 1;
                    layer->blend_rate = 0.083333336f;
                    layer->time = 0.0f;
                    layer->sequence[1] = 0;
                    layer->keyframe[1] = 0;
                    layer->blend = 1.0f;
                    layer->set_seq = 0;
                }
            }
            if (kind == 0) {
                if (layer->set_seq == 0) {
                    layer->sequence[1] = func_L01_004E9358((u8 *)hero->moby, hero->moby->sequence[1]);
                    layer->set_seq = 1;
                    layer->keyframe[1] = 0;
                    layer->time = 0.0f;
                    layer->blend = 0.0f;
                } else {
                    layer->time = layer->time + 0.120000005f;
                    if (1.0f < layer->time) {
                        layer->time = 1.0f;
                    }
                    if (layer->time == 1.0f) {
                        layer->blending = 0;
                    }
                }
            } else {
                layer->blend = 1.0f;
            }
            for (k = 0; k < 2; k++) {
                if (layer->sequence[k] < 0x17) {
                    layer->low[k] = 1;
                    layer->anim[k] = D_L01_00257080 + (i * 2 + k) * 0x400;
                } else {
                    layer->low[k] = 0;
                    layer->anim[k] = D_L01_00254080 + (i * 2 + k) * 0x600;
                }
            }
            func_L01_00439E10((u8 *)hero->moby, (u8 *)layer);
        } else {
            if (layer->changing == 0) {
                for (j = 0; j < 2; j++) {
                    if (changed != 0 && j != 1) {
                        continue;
                    }
                    layer->sequence[j] = func_L01_004E9358((u8 *)((H_4E9FB0 *)D_001A4BE0)->moby, ((H_4E9FB0 *)D_001A4BE0)->moby->sequence[j]);
                }
                if (layer->changing == 0) {
                    goto copy;
                }
            }
            layer->time = layer->time + 0.180000007f;
            if (1.0f <= layer->time) {
                layer->sequence[0] = layer->sequence[1];
                layer->keyframe[0] = layer->keyframe[1];
                layer->changing = 0;
            }
            goto static_tail;
copy:
            if (changed == 0) {
                layer->keyframe[0] = hero->moby->keyframe[0];
            }
            layer->keyframe[1] = hero->moby->keyframe[1];
            layer->time = hero->moby->time;
static_tail:
            for (k = 0; k < 2; k++) {
                if (layer->sequence[k] < 0x17) {
                    layer->low[k] = 1;
                    layer->anim[k] = D_L01_00257080 + (i * 2 + k) * 0x400;
                } else {
                    layer->low[k] = 0;
                    layer->anim[k] = D_L01_00254080 + (i * 2 + k) * 0x600;
                }
            }
            func_L01_00439E10((u8 *)hero->moby, (u8 *)layer);
        }
    }
}
