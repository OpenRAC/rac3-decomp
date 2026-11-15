#include "common.h"

/* localdecomp:start func_L20_003E3ED0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003E3ED0;

typedef struct {
    u8 pad_0[0x10];
    V_003E3ED0 pos;         /* 0x10 */
    u8 state;               /* 0x20 */
    u8 pad_21[2];
    u8 opacity;             /* 0x23 */
    struct M_003E3ED0_c *pclass; /* 0x24 */
    u8 pad_28[4];
    f32 scale;              /* 0x2C */
    u8 pad_30[4];
    u16 mode;               /* 0x34 */
    u8 pad_36[0x40 - 0x36];
    u8 prev_key;            /* 0x40 */
    u8 pad_41;
    u8 prev_seq;            /* 0x42 */
    u8 cur_seq;             /* 0x43 */
    u8 pad_44[4];
    f32 anim_speed;         /* 0x48 */
    u8 pad_4C[0x60 - 0x4C];
    u8 anim_flags;          /* 0x60 */
    u8 pad_61[7];
    struct P_003E3ED0 *pvar; /* 0x68 */
    u8 pad_6C[0x96 - 0x6C];
    u16 timer;              /* 0x96 */
    u8 pad_98[0xB8 - 0x98];
    void *parent;           /* 0xB8 */
    u8 bc;                  /* 0xBC */
    u8 pad_BD[3];
    V_003E3ED0 matrix[3];   /* 0xC0 */
    V_003E3ED0 rot;         /* 0xF0 */
} M_003E3ED0;

struct M_003E3ED0_c {
    u8 pad_0[0x24];
    f32 scale;
};

struct P_003E3ED0 {
    u8 pad_0[0x1C];
    void *p1C;              /* 0x1C */
    u8 pad_20[0x10];
    s32 v30;                /* 0x30 */
    f32 f34;                /* 0x34 */
    f32 f38;                /* 0x38 */
    f32 f3C;                /* 0x3C */
    f32 f40;                /* 0x40 */
    u8 pad_44[0x5C - 0x44];
    f32 f5C;                /* 0x5C */
    f32 f60;                /* 0x60 */
    u8 pad_64[4];
    s32 flags;              /* 0x68 */
    s32 v6C;                /* 0x6C */
    u8 pad_70[0x120 - 0x70];
    M_003E3ED0 *child;      /* 0x120 */
    f32 angle;              /* 0x124 */
    s32 sound;              /* 0x128 */
};

typedef struct {
    u8 pad_0[0x80];
    f32 x;                  /* 0x80 */
    f32 y;                  /* 0x84 */
    u8 pad_88[0x2808 - 0x88];
    void *hero;             /* 0x2808 */
} G_003E3ED0;

extern G_003E3ED0 D_001A4BE0;

extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern s32 func_L01_0044E7D8(void *);
extern void func_L01_0044E820(void *, s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_L01_004395E0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0045A748(void *, void *);
extern u8 *func_00382348(void *);
extern void func_L01_00446780(void *, void *, f32, s32, f32, f32, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C3938(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_003C7C38(void *);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C2880(void *);

void func_L20_003E3ED0(M_003E3ED0 *moby) {
    struct P_003E3ED0 *pv = moby->pvar;
    V_003E3ED0 a;
    V_003E3ED0 pos;
    V_003E3ED0 b;
    f32 dist;
    f32 size;
    u32 c;

    if (moby->state == 0) {
        func_L01_004450F0(moby, 1, -1);
        moby->mode |= 0x20;
        pv->v30 = 0;
        pv->v6C = -1;
        pv->f34 = 0.5f;
        pv->f38 = 0.5f;
        pv->f3C = 1.0f;
        pv->f40 = 0.7853982f;
        pv->f60 = 0.34906584f;
        pv->f5C = 0.010000001f;
        pv->p1C = &pv->v30;
        pv->flags |= 3;
        func_L01_0045BD78(moby, 0.4f, 2.0000002f, 0.0050265486f, 0.12566371f);
        pv->child = (M_003E3ED0 *)func_003C24B0(0x1CAF, 0x130);
        func_L01_00456160((u8 *)pv->child, (u8 *)moby);
        pv->child->mode |= 2;
    }

    c = func_L01_0044E7D8(moby);
    func_L01_0044E820(moby, (c >> 24 << 24) | 0xDF0000);
    moby->opacity = (s32)func_L01_00443A18(20.0f, 30.0f) + 0x46;
    moby->mode |= 0x2000;

    if (moby->prev_seq == 0 && (moby->anim_flags & 2) && moby->cur_seq != 1) {
        func_003C3A10(moby, 1, 0, 1);
    }
    if ((moby->bc != 0 || moby->timer >= 7) && moby->cur_seq != 2) {
        func_003C3A10(moby, 2, 1, 4);
    }
    if (moby->cur_seq == 1) {
        moby->timer++;
    }

    dist = func_L01_004395E0(moby);
    if (112.0f < dist && dist < 118.0f) {
        if (moby->prev_seq == 2 || moby->prev_seq == 3) {
            moby->anim_speed = 0.8f;
            func_0038CF68(&a, moby->matrix, 40.0f);
            size = 15.0f;
            vec_add_ab(&a, &a, &moby->pos);
            func_L01_0045A748(moby, &a);
            if (moby->parent != 0) {
                u8 *p = func_00382348(moby->parent);
                if (p != 0) {
                    size = p[0x14];
                }
            }
            pos = moby->pos;
            pos.z += 1.0f;
            func_0038CF68(&b, moby->matrix, 1.0f);
            vec_add_ab(&pos, &b, &pos);
            func_L01_00446780(moby, &pos, 1.0f, 1, size, 2.0f, 0, 1, 0);
            pos.z += 2.0f;
            func_L01_00446780(moby, &pos, 1.0f, 1, size, 2.0f, 0, 1, 0);
        }
    }

    if (moby->prev_seq == 0 && dist < 127.0f) {
        func_L01_0045BD10(moby, func_0038D160(D_001A4BE0.x - moby->pos.x, D_001A4BE0.y - moby->pos.y));
    }

    if (pv->child != 0) {
        pv->angle = func_0038DAB8(pv->angle, 0.017453292f);
        pv->child->pos = moby->pos;
        pv->child->rot = moby->rot;
        pv->child->scale = pv->child->pclass->scale * 1.03f;
        if (moby->prev_seq == moby->cur_seq) {
            func_003C3938(pv->child, moby->prev_seq, moby->prev_key);
        }
        c = func_L01_0044E7D8(moby);
        func_L01_0044E820(pv->child, (c >> 24 << 24) | ((((s32)c >> 16 & 0xFF) + 0x7F) << 16) | 0x7F7F);
        pv->child->opacity = func_00382498(-9, 9) + 0x28;
        pv->child->mode |= 0x200;
        pv->child->mode |= 0x800;
        func_003C7C38(pv->child);
    }

    if (D_001A4BE0.hero == moby && pv->sound == 0) {
        func_L01_004AAC98(0xF, 0, (s32)moby, 0x1AFD);
        pv->sound = 1;
    }

    if ((moby->prev_seq == 2 || moby->prev_seq == 3) && func_L01_0044E1B8(moby, 127.0f)) {
        if (pv->child != 0) {
            func_003C2880(pv->child);
            pv->child = 0;
        }
        func_003C2880(moby);
    } else if (moby->prev_seq == 2 && (moby->anim_flags & 2)) {
        if (pv->child != 0) {
            func_003C2880(pv->child);
            pv->child = 0;
        }
        func_003C2880(moby);
    }
}
/* localdecomp:end func_L20_003E3ED0 */
