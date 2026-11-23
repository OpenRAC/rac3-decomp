/* NEAR MISS: func_L01_004E9FB0 (hero_hold_layers_update).
 * 2026-11-22 (r13): 300 words positionally (check.py), 60 structurally, 21 ignoring register
 * names (scratch/match/r13_a/sd.py), from 305/65/31. What closed the gap:
 *   - the file split left L01_004E8EE0.c without D_L01_002F4540: declared here as u8[] (the
 *     springs are still written through Springs_4E9FB0);
 *   - `u8 **anim = layer->anim;` at the top of the static (not-blending) arm, so retail's spill
 *     slots come out: anim pointer at 4($sp), i+1 at 8, low pointer at 0xC. Making `low` a
 *     local too gives anim, low, i+1 (39 words); a `seq` local alone is 83;
 *   - `want = 0` before the `leaving = 1` store in the no_hold block (retail's delay slot);
 *   - the static arm as if/else on `changing` instead of the gotos (same bytes, plainer).
 * Still differs:
 *   - temp registers in the want block (the two lui halves, i+1 in $v1 after the hero address)
 *     and in the no_hold block (the layer in $v1, the 1 in $v0);
 *   - the changed block: retail rematerialises the hero base in $a2 (lui/addiu in the beqz
 *     delay slot) for moby/fire_layer/fire_fade, ours reads them through $fp; a direct
 *     ((H_4E9FB0 *)D_001A4BE0) there is 67 words;
 *   - `sltu $v0; move $s2,$v0` in retail for changing, `sltu $s2` here;
 *   - the springs stores: retail 5E4 6D4 6D8 694 624 628 (source order), ours puts both
 *     $f0 stores (5E4, 694) first in every source order tried;
 *   - the static arm computes layer+6 before layer+0x38 in retail ($a1 then $v1);
 *   - the loop-head lui of D_001A5A50 is $a0 in retail, $v1 here.
 * Same bytes (don't repeat): a local for D_001A5A50[i] (or layer) in the no_hold block;
 * `changing` as s16, as a `!=` of the two bytes, or through a block temporary; the anim local
 * also in the blending arm; three other orders of the springs stores (all worse or equal).
 * Older notes (r10): structure, branch layout, stack layout and callee-saved registers (hero in
 * $fp, i in $s7, layer $s1) match; the k-loops' counter/pointer registers were swapped.
 * Externs not in the src file: func_003C4138 (core f32 step function), func_L01_004DFE80,
 * D_001A5A50, D_L01_002F4540, D_L01_00254080, D_L01_00257080 (all unique to this function). */
__asm__(".extern D_L01_001DBD48, 8");
__asm__(".extern D_L01_001DBDA0, 8");
extern s32 D_L01_001DBD48[2];
extern s32 D_L01_001DBDA0[2];
extern u8 D_001A4BE0[];
extern u8 D_L01_001FDBD0[];
extern u8 *D_L01_001FD180[];
extern u8 D_L01_002F4540[];
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
                want = 0;
                if (D_001A5A50[i] != 0) {
                    D_001A5A50[i]->leaving = 1;
                }
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

                ((Springs_4E9FB0 *)&D_L01_002F4540)->other_target_y = offset;
                ((Springs_4E9FB0 *)&D_L01_002F4540)->gun_gain = gain;
                ((Springs_4E9FB0 *)&D_L01_002F4540)->gun_damping = damping;
                ((Springs_4E9FB0 *)&D_L01_002F4540)->gun_target_y = offset;
                ((Springs_4E9FB0 *)&D_L01_002F4540)->other_gain = gain;
                ((Springs_4E9FB0 *)&D_L01_002F4540)->other_damping = damping;
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
            u8 **anim = layer->anim;

            if (layer->changing == 0) {
                for (j = 0; j < 2; j++) {
                    if (changed != 0 && j != 1) {
                        continue;
                    }
                    layer->sequence[j] = func_L01_004E9358((u8 *)((H_4E9FB0 *)D_001A4BE0)->moby, ((H_4E9FB0 *)D_001A4BE0)->moby->sequence[j]);
                }
            }
            if (layer->changing != 0) {
                layer->time = layer->time + 0.180000007f;
                if (1.0f <= layer->time) {
                    layer->sequence[0] = layer->sequence[1];
                    layer->keyframe[0] = layer->keyframe[1];
                    layer->changing = 0;
                }
            } else {
                if (changed == 0) {
                    layer->keyframe[0] = hero->moby->keyframe[0];
                }
                layer->keyframe[1] = hero->moby->keyframe[1];
                layer->time = hero->moby->time;
            }
            for (k = 0; k < 2; k++) {
                if (layer->sequence[k] < 0x17) {
                    layer->low[k] = 1;
                    anim[k] = D_L01_00257080 + (i * 2 + k) * 0x400;
                } else {
                    layer->low[k] = 0;
                    anim[k] = D_L01_00254080 + (i * 2 + k) * 0x600;
                }
            }
            func_L01_00439E10((u8 *)hero->moby, (u8 *)layer);
        }
    }
}
