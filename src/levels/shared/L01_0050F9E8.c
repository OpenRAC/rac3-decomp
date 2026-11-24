#include "common.h"

typedef struct {
    char pad0[0x10];
    u8 count;
} Anim;
typedef struct {
    char pad0[0x48];
    Anim *anims[1];
} Class;
typedef struct {
    char pad0[0x24];
    Class *cls;
    char pad28[0x40 - 0x28];
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    s32 unk44;
    char pad48[0x58 - 0x48];
    s32 unk58;
    s32 unk5C;
} Moby;
typedef struct {
    char data[0x600];
} Buf;
typedef struct {
    u8 pad0[0xC20];
    s32 xC20;
    s32 xC24;
    s32 xC28;
} D_001A4BE0_t;
typedef struct {
    u8 pad0[0x20];
    u8 b32;
    u8 pad21[0x34 - 0x21];
    u16 h52;
    u8 pad36[0xAA - 0x36];
    s16 h170;
} M_50C8E8;
typedef struct {
    M_50C8E8 *p[3];
    u8 padC[0x28 - 0xC];
    s32 w40;
    u8 pad2C[0x50 - 0x2C];
} E_50C8E8;
typedef struct {
    u8 pad0[0xBF8];
    M_50C8E8 *p3064;
    u8 padBFC[0x1200 - 0xBFC];
    E_50C8E8 e[1];
    u8 pad1250[0x12FC - 0x1250];
    M_50C8E8 *p4860;
    u8 pad1300[0x1A24 - 0x1300];
    M_50C8E8 *p6692;
    u8 pad1A28[0x25E4 - 0x1A28];
    u8 b9700;
} G_50C8E8;
typedef struct {
    u8 pad0[0x44];
    s16 h68;
    u8 pad46[0x1A0 - 0x46];
    M_50C8E8 *arr[1];
} H_50C8E8;
typedef struct {
    u8 pad0[0x20];
    s16 h32;
} K_50C8E8;
typedef struct {
    f32 m[16];
} M_0050D430;
typedef struct {
    f32 v[4];
} V_0050D430;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_50D4D8;
typedef struct {
    u8 pad0[64];
    Vec4_50D4D8 m;
    u8 pad50[9636];
    u8 b25F4;
} G_50D4D8;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D530;
typedef struct {
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x25F4 - 0x80];
    u8 mode;
} Cam50D5B0;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_00511618;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D870;
typedef struct {
    u8 pad[138];
    u16 h8A;
    u8 pad2[240 - 140];
} S_50D8F8;
typedef struct {
    u8 pad0[0x8A];
    u16 h8A;
    u8 pad8C[0xF0 - 0x8C];
} S_50DA08;
typedef struct {
    u8 arr[0x40];
} S_50DA08a;
typedef struct {
    s32 arr[0x40];
} S_50DA08b;
typedef struct {
    u8 pad0[52];
    s32 x34;
} G_0050F828;

typedef struct {
    u8 pad0[0x78];
    s32 color78;
} Node_005124D8;
typedef struct {
    u8 pad0[0x1340];
    Node_005124D8 *p1340;
    Node_005124D8 *p1344;
    Node_005124D8 *p1348;
    u8 pad134C[0x1390 - 0x134C];
    Node_005124D8 *p1390;
    u8 pad1394[0x2890 - 0x1394];
    f32 f2890;
    f32 f2894;
    f32 f2898;
    f32 f289C;
} Glob_005124D8;

typedef struct Manip_00512A30 {
    u8 pad0;
    u8 initialized;
    u8 pad2[0x1E];
    f32 scale[3];
    u8 pad2C[0x14];
} Manip_00512A30;

/* localdecomp:start func_L01_0050F9E8 */
extern Moby *D_001A71A0[];
s32 func_L01_0050F9E8(s32 anim) {
    s32 id = *(s16 *)((u8 *)D_001A71A0[0] + 0xAA);
    if (id == 0x1a4e) {
        switch (anim) {
        case 1: return 0;
        case 2: return 1;
        case 4: return 3;
        case 5: return 4;
        case 6: return 11;
        case 7: return 12;
        case 8: return 13;
        case 9: return 14;
        case 10: return 15;
        case 11: return 16;
        case 12: return 17;
        case 13: return 18;
        case 14: return 19;
        case 15: return 20;
        case 16: return 21;
        case 17: return 22;
        case 18: return 23;
        case 20: return 9;
        case 19: return 27;
        case 3: return 25;
        case 21: return 24;
        case 22: return 26;
        }
    }
    else if (id == 0x173b) {
        switch (anim) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        case 5: return 5;
        case 18: return 6;
        case 20: return 8;
        case 19: return 7;
        case 21: return 9;
        case 22: return 10;
        }
    }
    return anim;
}
/* localdecomp:end func_L01_0050F9E8 */

/* localdecomp:start func_L01_0050FB40 */
/* hero_anim_set (open-rac-engine's name, NTSC-U 0x50BB98; docs/research/hero-controller.md):
 * starts a hero animation. The pose he is in is kept while the sequence's keyframe
 * `start_key` plays in over `blend` ticks; a negative blend is a curve index (-1 is 11 ticks,
 * -2 is 16: the curve table D_L01_001DBE50, read through $gp). */
typedef struct {
    u8 pad0[0x11];
    u8 count;
} A_50FB40;
typedef struct {
    u8 pad0[0x24];
    Class *cls;
    u8 pad28[0x40 - 0x28];
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    f32 f44;
    u8 pad48[0x58 - 0x48];
    s32 w58;
    s32 w5C;
    u8 pad60[0x6C - 0x60];
    u8 b6C;
    u8 pad6D[0xA9 - 0x6D];
    u8 bA9;
} M_50FB40;
typedef struct {
    u8 pad0[0xC00];
    f32 anim_rate;
    f32 anim_key_rate;
    s32 anim_flags;
    s32 anim_blend;
    s32 curve_index;
    s32 curve_pos;
    u8 padC18[0x25C0 - 0xC18];
    Moby *hero_moby;
    u8 pad25C4[0x25E4 - 0x25C4];
    u8 critter_mode;
    u8 pad25E5[0x25E9 - 0x25E5];
    u8 firing;
    u8 pad25EA[0x25EB - 0x25EA];
    u8 firing_held;
    u8 pad25EC[0x2800 - 0x25EC];
    s32 w2800;
    u8 pad2804[0x2830 - 0x2804];
    s32 fire_sequence;
    u8 pad2834[0x2884 - 0x2834];
    s16 h2884;
} H_50FB40;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_50FB40;

extern D_001A4BE0_t D_001A4BE0;
extern u8 D_001D5469;
extern Buf D_L01_00252880[];
extern Buf D_L01_00252E80[];
extern Vec4_50FB40 D_L01_001FCB40[];
__asm__(".extern D_L01_001DBE50, 0");
extern s32 D_L01_001DBE50[] __attribute__((section(".sdata")));
extern s32 func_L01_0050F9E8(s32);
extern void func_L01_0050FED0(void);
extern void func_L01_0050F4C0(s32, s32, f32);
extern void func_L01_0050F7E0(void);
extern void func_L01_0050F858(s32, s32, f32);
extern s32 func_003C2D30(Moby *);
extern void func_003C29B0(Moby *);
extern void func_003C8B18(Moby *, s32);
extern void func_003C6EA0(Moby *, s32, u16);
extern void func_0011F0A0(s32);
extern s32 func_L01_004DFCC8(Moby *, s32, s32, Buf *);

void func_L01_0050FB40(s32 sequence, s32 start_key, f32 blend) {
    Moby *moby = (*(H_50FB40 *)&D_001A4BE0).hero_moby;
    M_50FB40 *m = (M_50FB40 *)moby;
    s32 r;

    if ((*(H_50FB40 *)&D_001A4BE0).critter_mode == 3) {
        sequence = func_L01_0050F9E8(sequence);
    }
    /* anim_flags & 2 (the sequence's end flag, per the research): the keyframe time restarts */
    if ((*(H_50FB40 *)&D_001A4BE0).anim_flags & 2) {
        *(s32 *)&m->f44 = 0;
    }
    /* a flag at 0x1D5469 swaps sequences 44 and 45 */
    if (D_001D5469) {
        if (sequence == 44) {
            sequence = 45;
        } else if (sequence == 45) {
            sequence = 44;
        }
    }
    /* keyframes 1 to 11 also go to func_003C6EA0 (not named yet) */
    if ((u32)(start_key - 1) < 11) {
        func_003C6EA0((*(H_50FB40 *)&D_001A4BE0).hero_moby, sequence, (u16)start_key);
    }
    r = func_003C2D30(moby);
    if (r >= 0) {
        func_003C8B18(moby, r | 0x300);
        func_0011F0A0(0);
        D_L01_001FCB40[r] = *(Vec4_50FB40 *)moby;
        if (m->b42 != 0xFF) {
            m->bA9 = m->b42;
        }
        /* the moby's 16 bytes at 0x80 are what the entry keeps */
        D_L01_001FCB40[r] = *(Vec4_50FB40 *)((u8 *)moby + 0x80);
        m->b42 = 0xFF;
        m->b40 = r;
    }
    m->b41 = start_key;
    m->b43 = sequence;
    func_003C29B0(moby);
    if (m->b42 != 0xFF) {
        m->w58 = func_L01_004DFCC8(moby, m->b42, m->b40, D_L01_00252880);
    }
    m->w5C = func_L01_004DFCC8(moby, m->b43, m->b41, D_L01_00252E80);

    (*(H_50FB40 *)&D_001A4BE0).anim_rate = 1.0f;
    if (blend > 0.0f) {
        (*(H_50FB40 *)&D_001A4BE0).anim_key_rate = 1.0f / blend;
        m->f44 = 0.0f;
        (*(H_50FB40 *)&D_001A4BE0).curve_index = -1;
    } else {
        (*(H_50FB40 *)&D_001A4BE0).anim_key_rate = 1.0f;
        (*(H_50FB40 *)&D_001A4BE0).curve_pos = 0;
        (*(H_50FB40 *)&D_001A4BE0).curve_index = (s32)(-blend) - 1;
        m->f44 = 0.0f;
    }

    func_L01_0050FED0();
    m->b6C = ((A_50FB40 *)m->cls->anims[sequence])->count;
    (*(H_50FB40 *)&D_001A4BE0).anim_blend = 1;
    if (blend < 0.0f) {
        blend = (f32)D_L01_001DBE50[(*(H_50FB40 *)&D_001A4BE0).curve_index];
    }

    if ((*(H_50FB40 *)&D_001A4BE0).critter_mode == 0) {
        if ((*(H_50FB40 *)&D_001A4BE0).h2884 == 0) {
            func_L01_0050F4C0(sequence, start_key, blend);
        }
        if ((*(H_50FB40 *)&D_001A4BE0).critter_mode == 0
            && (*(H_50FB40 *)&D_001A4BE0).firing_held == 0
            && sequence != (*(H_50FB40 *)&D_001A4BE0).fire_sequence) {
            (*(H_50FB40 *)&D_001A4BE0).firing = 0;
        }
    }
    func_L01_0050F7E0();
    if ((*(H_50FB40 *)&D_001A4BE0).w2800 != 0) {
        func_L01_0050F858(sequence, start_key, blend);
    }
}
/* localdecomp:end func_L01_0050FB40 */

/* localdecomp:start func_L01_0050FDD8 */




extern Moby *D_001A71A0[];
extern Buf D_L01_00252880[];
extern void func_003C29B0(Moby *);
extern s32 func_L01_004DFCC8(Moby *, s32, s32, Buf *);

void func_L01_0050FDD8(s32 a, s32 b) {
    Moby *m = D_001A71A0[0];
    s32 max;

    m->unk41 = b + 1;
    m->unk40 = b;
    max = m->cls->anims[a]->count - 1;
    if (max < m->unk41) {
        m->unk41 = max;
    }
    m->unk44 = 0;
    m->unk42 = a;
    m->unk43 = a;
    func_003C29B0(m);
    m->unk58 = func_L01_004DFCC8(m, m->unk42, m->unk40, &D_L01_00252880[0]);
    m->unk5C = func_L01_004DFCC8(m, m->unk43, m->unk41, &D_L01_00252880[1]);
}
/* localdecomp:end func_L01_0050FDD8 */

/* localdecomp:start func_L01_0050FE88 */
extern D_001A4BE0_t D_001A4BE0;
void func_L01_0050FE88(s32 a, s32 b) {
    if (a >= 0) {
        Moby *m = ((H_50FB40 *)&D_001A4BE0)->hero_moby;
        if (b < m->cls->anims[m->unk43]->count) {
            D_001A4BE0.xC20 = a;
            D_001A4BE0.xC24 = b;
        }
    }
}
/* localdecomp:end func_L01_0050FE88 */

/* localdecomp:start func_L01_0050FED0 */
extern D_001A4BE0_t D_001A4BE0;

void func_L01_0050FED0(void) {
    D_001A4BE0.xC20 = -1;
    D_001A4BE0.xC28 = 0;
}
/* localdecomp:end func_L01_0050FED0 */

/* localdecomp:start func_L01_0050FEE8 */
extern s32 D_001A5808[];
void func_L01_0050FEE8(s32 a0) {
    if (a0 == -1) a0 = 4;
    D_001A5808[0] = a0;
}
/* localdecomp:end func_L01_0050FEE8 */

/* localdecomp:start func_L01_0050FF00 */
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
                /* key_time is reset on both sides of the key_next store: retail keeps 0.0 in a
                   register hoisted out of the loop, which gcc does only for a value used twice. */
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
/* localdecomp:end func_L01_0050FF00 */

INCLUDE_ASM("asm/levels", func_L01_00510478);

/* localdecomp:start func_L01_005108C0 */
extern D_001A4BE0_t D_001A4BE0;





extern H_50C8E8 D_L01_001E6D80;
extern K_50C8E8 D_0016C580;
extern s32 D_L01_001D6694;
extern s32 func_L01_00513EF0(void);

void func_L01_005108C0(s32 a0) {
    s32 i;
    s32 j;
    s32 mode;
    s32 found;
    M_50C8E8 *q;
    G_50C8E8 *g;
    G_50C8E8 *base;

    (*(G_50C8E8 *)&D_001A4BE0).p3064->h52 |= 1;
    for (i = 0; i < 7; i++) {
        if (i == 0 && func_L01_00513EF0() == 2 && a0 == 0) {
            continue;
        }
        mode = D_L01_001D6694;
        if (mode == 2) {
            found = 0;
            for (j = 0; j < D_L01_001E6D80.h68; j++) {
                if (D_L01_001E6D80.arr[j] != 0 && D_L01_001E6D80.arr[j]->h170 == 0) {
                    found = 1;
                }
            }
            if (found) {
                continue;
            }
        }
        if (mode == 6 && (D_0016C580.h32 == 0 || D_0016C580.h32 == 3) && (i == 1 || i == 2)) {
            continue;
        }
        base = &(*(G_50C8E8 *)&D_001A4BE0);
        base = &(*(G_50C8E8 *)&D_001A4BE0);
        g = (G_50C8E8 *)((u8 *)base + i * 80);
        if (g->e[0].p[0] != 0) {
            g->e[0].p[0]->h52 |= 1;
        }
        if (g->e[0].p[1] != 0) {
            g->e[0].p[1]->h52 |= 1;
        }
        if (g->e[0].p[2] != 0) {
            g->e[0].p[2]->h52 |= 1;
        }
    }
    if ((*(G_50C8E8 *)&D_001A4BE0).p4860 != 0) {
        (*(G_50C8E8 *)&D_001A4BE0).p4860->h52 |= 1;
    }
    if ((*(G_50C8E8 *)&D_001A4BE0).b9700 == 1 && (*(G_50C8E8 *)&D_001A4BE0).p6692 != 0) {
        (*(G_50C8E8 *)&D_001A4BE0).p6692->h52 |= 1;
    }
    if ((*(G_50C8E8 *)&D_001A4BE0).e[0].w40 == 9) {
        q = (*(G_50C8E8 *)&D_001A4BE0).e[0].p[0];
        if (q != 0 && D_L01_001D6694 == 0 && q->b32 != 0) {
            q->h52 &= ~0x41;
        }
    }
}
/* localdecomp:end func_L01_005108C0 */

/* localdecomp:start func_L01_00510AD0 */
void func_L01_00510AD0(void)
{
    char *b = (char *)&D_001A4BE0;
    char *p;
    int i;

    p = *(char **)(b + 3064);
    *(unsigned short *)(p + 52) &= 0xFFFE;

    for (i = 0; i < 7; i++) {
        p = *(char **)(b + 4608 + i * 80);
        if (p != 0)
            *(unsigned short *)(p + 52) &= 0xFFFE;
        p = *(char **)(b + 4612 + i * 80);
        if (p != 0)
            *(unsigned short *)(p + 52) &= 0xFFFE;
        p = *(char **)(b + 4616 + i * 80);
        if (p != 0)
            *(unsigned short *)(p + 52) &= 0xFFFE;
    }

    if (1) {
        char *c = (char *)&D_001A4BE0;
        p = *(char **)(c + 4860);
        if (p != 0)
            *(unsigned short *)(p + 52) &= 0xFFFE;
    }

    if (1) {
        char *c = (char *)&D_001A4BE0;
        if (*(unsigned char *)(c + 9700) == 1) {
            c = (char *)&D_001A4BE0;
            p = *(char **)(c + 6692);
            if (p != 0)
                *(unsigned short *)(p + 52) &= 0xFFFE;
        }
    }

    if (1) {
        char *c = (char *)&D_001A4BE0;
        if (*(short *)(c + 10372) != 0) {
            c = (char *)&D_001A4BE0;
            p = *(char **)(c + 4848);
            if (p != 0)
                *(unsigned short *)(p + 52) |= 0x41;
            c = (char *)&D_001A4BE0;
            p = *(char **)(c + 4852);
            if (p != 0)
                *(unsigned short *)(p + 52) |= 0x41;
            c = (char *)&D_001A4BE0;
            p = *(char **)(c + 4860);
            if (p != 0)
                *(unsigned short *)(p + 52) |= 0x41;
        }
    }

    if (1) {
        char *c = (char *)&D_001A4BE0;
        if ((*(unsigned char *)(c + 9711) != 0 && *(int *)(c + 4648) == 9) ||
            *(unsigned char *)(c + 9712) != 0) {
            char *d = (char *)&D_001A4BE0;
            p = *(char **)(d + 4608);
            if (p != 0)
                *(unsigned short *)(p + 52) |= 0x41;
        }
    }
}
/* localdecomp:end func_L01_00510AD0 */

/* localdecomp:start func_L01_00510C28 */
void func_L01_00510C28(void) {
    char *c = (char *)&D_001A4BE0;
    char *p = *(char **)(c + 0x25C0);
    char *q;

    *(u16 *)(p + 0x34) |= 1;
    q = *(char **)(c + 0x1A20);
    if (q != 0) {
        *(u16 *)(q + 0x34) |= 1;
    }
}
/* localdecomp:end func_L01_00510C28 */

/* localdecomp:start func_L01_00510C60 */
void func_L01_00510C60(void) {
    u8 *base = (u8 *)&D_001A4BE0;
    u8 *a = *(u8 **)(base + 0x25C0);
    u8 *b;

    *(u16 *)(a + 0x34) &= 0xFFFE;
    b = *(u8 **)(base + 0x1A20);
    if (b != 0) {
        *(u16 *)(b + 0x34) &= 0xFFFE;
    }
}
/* localdecomp:end func_L01_00510C60 */

LINKER_REMNANT("asm/levels", func_L01_00510C98);

/* localdecomp:start func_L01_00510CA0 */
extern D_001A4BE0_t D_001A4BE0;
void func_L01_00510CA0(s16 a0, u8 a1, u8 a2, u8 a3, f32 f12, f32 f13) {
    u8 *p = ((u8 *)&(*(G_50C8E8 *)&D_001A4BE0));
    *(s32 *)(p + 5144) = a0;
    *(u16 *)(p + 5148) = a1;
    *(u16 *)(p + 5150) = (*(u16 *)(p + 5150) & ~a3) | a2;
    *(f32 *)(p + 5136) = f12;
    *(f32 *)(p + 5140) = f13;
}
/* localdecomp:end func_L01_00510CA0 */

/* localdecomp:start func_L01_00510CE8 */
#include "vu0.h"
extern D_001A4BE0_t D_001A4BE0;
f32 func_L01_00510CE8(void) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D328(M_0050D430 *, u8 *);
    extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
    M_0050D430 matrix;
    V_0050D430 direction;
    Vec4 zrot;
    Vec4 yrot;
    Vec4 velocity;
    u8 *hero;
    direction.v[0] = func_0038D098(0.0f);
    direction.v[1] = func_0038D0B0(0.0f);
    direction.v[2] = 0.0f;
    func_0038D328(&matrix, (u8 *)&D_001A4BE0 + 0x90);
    func_0038D028(&direction, &direction, &matrix);
    hero = (u8 *)&D_001A4BE0;
    if (*(f32 *)(hero + 0x2C0) != 0.0f ||
        *(f32 *)(hero + 0x2C4) != 0.0f) {
        velocity.q = *(u128_t *)(hero + 0x2C0);
        qzero(&zrot.q);
        qzero(&yrot.q);
        zrot.f[2] = -func_0038D160(*(f32 *)(hero + 0x2C0), *(f32 *)(hero + 0x2C4));
        func_0038D328(&matrix, (u8 *)&zrot);
        func_0038D028(&direction, &direction, &matrix);
        func_0038D028((V_0050D430 *)&velocity, (V_0050D430 *)&velocity, &matrix);
        yrot.f[1] = -func_0038D160(velocity.f[2], velocity.f[0]);
        func_0038D328(&matrix, (u8 *)&yrot);
        func_0038D028(&direction, &direction, &matrix);
        zrot.f[2] = -zrot.f[2];
        func_0038D328(&matrix, (u8 *)&zrot);
        func_0038D028(&direction, &direction, &matrix);
    }
    return func_0038D160(direction.v[0], direction.v[1]);
}
/* localdecomp:end func_L01_00510CE8 */

/* localdecomp:start func_L01_00510E40 */
typedef struct {
    u8 p0[0x218];
    s16 h218;
    u8 p21A[0x368 - 0x21A];
    s16 h368;
    u8 p36A[0x36E - 0x36A];
    s16 h36E;
    u8 p370[0x1479 - 0x370];
    u8 b1479;
    u8 p147A[2];
    u8 b147C;
    u8 p147D[0x25C4 - 0x147D];
    s32 state;
} H_510E40;
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6740;
__asm__(".extern D_L01_001D6740, 4");
extern u8 D_00142CAD[];

s32 func_L01_00510E40(void) {
    s32 r = (*(H_510E40 *)&D_001A4BE0).h368;
    if (D_L01_001D673C != 0 && D_L01_001D6740 == 0) {
        r = 2;
    }
    if (D_L01_001D6740 != 0 || (*(H_510E40 *)&D_001A4BE0).state == 0x3B || ((*(H_510E40 *)&D_001A4BE0).state == 0x73 && (*(H_510E40 *)&D_001A4BE0).b147C == 0) || (*(H_510E40 *)&D_001A4BE0).state == 0x72 ||
        (*(H_510E40 *)&D_001A4BE0).h218 != 0 || ((*(H_510E40 *)&D_001A4BE0).b1479 != 0 && D_00142CAD[0] != 0 && (*(H_510E40 *)&D_001A4BE0).state == 0 && (*(H_510E40 *)&D_001A4BE0).h36E < 3)) {
        r = 1;
    }
    if (r == 1 && (*(H_510E40 *)&D_001A4BE0).b147C != 0 && (*(H_510E40 *)&D_001A4BE0).b1479 == 0) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L01_00510E40 */
