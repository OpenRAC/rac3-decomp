/* NEAR MISS: func_L01_0050FF00 / hero_anim_update. check.py prints MATCH for this file (L01 and
   level 21, 2026-11-22, r13_b/z10.c), but only because the keyframe-snap branch (hero.c28 != 0)
   stores `m->key_time = zero` twice, around the key_next store. That duplicate is a statement
   with no effect of its own (flow deletes the first store as dead), so by the matching rules it
   is a trick, not a match: the maintainer decides. Needs the config/levels/divs_nops.txt row
   `func_L01_0050FF00 1` (appended 2026-11-22; it also gives the nop retail has after the
   trigger loop's `b`).
   Why it works: retail's `mtc1 $zero,$f22` is a 0.0 pseudo that loop.c hoisted. With one use,
   loop.c's single-use rule puts the constant into the store (`sw $zero`) and deletes the set;
   with two uses in the same block (gcse cprop only propagates across blocks) the set is
   movable and its lifetime passes the threshold (a use 1 insn after the set is "not
   desirable", -dL). The second store must come after the key_next store: both stores before
   it, f22/f23 swap with rate_kf (4 words); the rate store between them, 9-10 words.
   Without the duplicate the best is 13 words (r13_b/a1.c): one literal 0.0 store; every
   placement of a single `zero` gets folded (r10_a: before the loop and at the top of the body
   gcse cprop, in the block loop.c, in both places combine). Also closed in round 13: old_frame
   computed after new_frame gives retail's mul.s order and $a1/$a2/$t2 (31 -> 13 words).
   Same bytes: a `while` loop instead of if + do/while; D_L01_001DC02C read in the block (as
   `const` it is hoisted, the same as the rate_kf local); two literal 0.0f stores (direct sw). */
typedef struct {
    u8 pad0[0x10];
    u8 frames;                     /* 0x10: keyframes (the frame pointers follow at 0x1C) */
    u8 sound;                      /* 0x11 */
    u8 triggers;                   /* 0x12: trigger entries, after the frame pointers */
    u8 pad13[0x1C - 0x13];
} Seq_50FF00;
typedef struct {
    u8 pad0[0x48];
    Seq_50FF00 *anims[1];
} Cls_50FF00;
typedef struct M_50FF00 {
    u8 pad0[0x24];
    Cls_50FF00 *cls;               /* 0x24 */
    u8 pad28[0x40 - 0x28];
    u8 key;                        /* 0x40: current keyframe */
    u8 key_next;                   /* 0x41: the keyframe after it */
    u8 seq;                        /* 0x42: sequence playing */
    u8 seq_want;                   /* 0x43: sequence asked for */
    f32 key_time;                  /* 0x44: time through the keyframe, 0..1 */
    u8 pad48[0x58 - 0x48];
    Buf *pose_cur;                 /* 0x58: keyframe data at key */
    s32 pose_next;                 /* 0x5C: keyframe data at key_next */
    u8 pad60[0x6C - 0x60];
    u8 slot_last;                  /* 0x6C */
    u8 slot;                       /* 0x6D: row of D_001A30B0, 0xFF none */
    u8 triggers;                   /* 0x6E: the sequence's trigger count */
} M_50FF00;
typedef struct {
    u8 pad0[0xC00];
    f32 anim_rate;                 /* 0xC00 */
    f32 anim_key_rate;             /* 0xC04: 1 / the keyframe's ticks */
    s32 anim_flags;                /* 0xC08 */
    s32 anim_changing;             /* 0xC0C */
    s32 blend_count;               /* 0xC10: -1 none */
    s32 blend_index;               /* 0xC14 */
    f32 anim_frame;                /* 0xC18 */
    f32 anim_step;                 /* 0xC1C */
    union { s32 w; u8 b; } c20;    /* 0xC20 */
    union { s32 w; u8 b; } c24;    /* 0xC24 */
    s32 c28;                       /* 0xC28 */
    u8 pad_C2C[0x1228 - 0xC2C];
    s32 held_item;                 /* 0x1228 */
    u8 pad122C[0x25C0 - 0x122C];
    M_50FF00 *hero_moby;           /* 0x25C0 */
    s32 state;                     /* 0x25C4 */
} H_50FF00;

extern Buf D_L01_00252E80[];
extern u8 D_001A30B0[];
extern f32 D_L01_001DC02C[];
extern f32 D_L01_002F6460[][25];
extern void func_0038CC88(void *, void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_0050F758(void);
extern void func_L01_0050F8F0(void);
extern void func_L01_0050F950(void);
extern f32 func_L01_004395E0(void *);

/* hero_anim_update: advances the hero's keyframe time by his rate each frame (x1.2 for PAL),
   steps to the next keyframe at 1, and fires the sequence's triggers that the frame passes. */
void func_L01_0050FF00(void) {
    M_50FF00 *m = (*(H_50FF00 *)&D_001A4BE0).hero_moby;
    s32 prev_key;
    s32 same;
    f32 entry_time;
    f32 step;

    func_L01_0050F7E0();
    (*(H_50FF00 *)&D_001A4BE0).anim_flags &= ~3;
    prev_key = m->key;
    same = m->seq == m->seq_want;
    entry_time = m->key_time;

    if (m->seq == m->seq_want) {
        m->key_time = entry_time + (*(H_50FF00 *)&D_001A4BE0).anim_rate * ((*(H_50FF00 *)&D_001A4BE0).anim_key_rate * 1.2f);
    } else if ((*(H_50FF00 *)&D_001A4BE0).blend_count >= 0) {
        s32 bi = (*(H_50FF00 *)&D_001A4BE0).blend_index;

        m->key_time = D_L01_002F6460[(*(H_50FF00 *)&D_001A4BE0).blend_count][bi];
        (*(H_50FF00 *)&D_001A4BE0).blend_index = bi + 1;
    } else {
        m->key_time = entry_time + (*(H_50FF00 *)&D_001A4BE0).anim_key_rate * 1.2f;
    }

    if (0.99f < m->key_time && m->key_time < 1.01f) {
        m->key_time = 1.0f;
    }
    if (-0.01f < m->key_time && m->key_time < 0.01f) {
        m->key_time = 0.0f;
    }
    step = m->key_time - entry_time;

    if (1.0f <= m->key_time) {
        f32 rate_kf = D_L01_001DC02C[0];


        do {
            if (m->seq != m->seq_want) {
                m->seq = m->seq_want;
                m->triggers = m->cls->anims[m->seq]->triggers;
            }
            (*(H_50FF00 *)&D_001A4BE0).blend_count = -1;
            (*(H_50FF00 *)&D_001A4BE0).anim_flags |= 1;
            m->pose_cur = &D_L01_00252880[0];
            m->key = m->key_next;
            func_0038CC88(&D_L01_00252880[0], &D_L01_00252880[1], 0x600);
            m->key_next++;

            if ((*(H_50FF00 *)&D_001A4BE0).c28 != 0) {
                f32 zero = 0.0f;

                (*(H_50FF00 *)&D_001A4BE0).c28 = 0;
                (*(H_50FF00 *)&D_001A4BE0).anim_key_rate = rate_kf;
                m->key_time = zero;
                m->key_next = (*(H_50FF00 *)&D_001A4BE0).c24.b;
                m->key_time = zero;
                m->pose_next = func_L01_004DFCC8((Moby *)m, m->seq_want, m->key_next, &D_L01_00252880[1]);
                func_L01_0050FED0();
                func_L01_0050F950();
            } else if ((*(H_50FF00 *)&D_001A4BE0).c20.w != -1 && (*(H_50FF00 *)&D_001A4BE0).c24.w < m->key_next) {
                (*(H_50FF00 *)&D_001A4BE0).anim_key_rate = 0.33333334f;
                m->key_time = 0.0f;
                m->key_next = (*(H_50FF00 *)&D_001A4BE0).c20.b;
                m->pose_next = func_L01_004DFCC8((Moby *)m, m->seq_want, m->key_next, &D_L01_00252880[1]);
                func_L01_0050F950();
            } else {
                Seq_50FF00 *anim = m->cls->anims[m->seq_want];

                if (m->key_next >= anim->frames) {
                    m->key_next = 0;
                    (*(H_50FF00 *)&D_001A4BE0).anim_flags |= 2;
                }
                m->pose_next = func_L01_004DFCC8((Moby *)m, m->seq_want, m->key_next, &D_L01_00252E80[0]);
                m->key_time = m->key_time - 1.0f;
                m->key_time = m->key_time / (*(H_50FF00 *)&D_001A4BE0).anim_key_rate;
                (*(H_50FF00 *)&D_001A4BE0).anim_key_rate = ((f32 *)m->pose_cur)[0];
                m->key_time = m->key_time * (*(H_50FF00 *)&D_001A4BE0).anim_key_rate;
            }
        } while (1.0f <= m->key_time);
    }

    if (same && m->triggers != 0) {
        Seq_50FF00 *anim = m->cls->anims[m->seq];
        s32 new_frame = ((s32)m->key << 4) + (s32)(m->key_time * 16.0f);
        s32 old_frame = (prev_key << 4) + (s32)(entry_time * 16.0f);
        s32 *trig = (s32 *)((u8 *)anim + 0x1C + anim->frames * 4);
        s32 i;

        for (i = 0; i < anim->triggers; i++, trig++) {
            s32 entry = *trig;
            s32 stamp = entry >> 16;

            if (old_frame < stamp && stamp <= new_frame) {
                if ((*(H_50FF00 *)&D_001A4BE0).held_item != 0x7F || (u32)((*(H_50FF00 *)&D_001A4BE0).state - 19) >= 2) {
                    func_003A52A0((u16)entry, 0, m);
                }
                break;
            }
        }
    }

    if (m->slot != 0xFF) {
        u8 *row = D_001A30B0 + (m->slot << 7);

        if (*(M_50FF00 **)(row + 0xDC) != m) {
            m->slot = 0xFF;
        } else if (*(s16 *)(row + 0xCA) != m->slot_last) {
            func_003A4F28(m->slot);
            m->slot = 0xFF;
        }
    } else if (m->slot_last != 0xFF) {
        m->slot = func_003A52A0(m->slot_last, 4, m);
    }

    func_L01_0050F758();
    func_L01_0050F8F0();
    {
        f32 frame_old = (*(H_50FF00 *)&D_001A4BE0).anim_frame;
        f32 frame_new = func_L01_004395E0(m);

        (*(H_50FF00 *)&D_001A4BE0).anim_frame = frame_new;
        if (frame_old <= frame_new) {
            (*(H_50FF00 *)&D_001A4BE0).anim_step = frame_new - frame_old;
        } else {
            (*(H_50FF00 *)&D_001A4BE0).anim_step = step;
        }
    }
    (*(H_50FF00 *)&D_001A4BE0).anim_changing = m->seq != m->seq_want;
}
