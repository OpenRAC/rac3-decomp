#include "common.h"

/* declared by functions of L01_00374630.c, which this file was cut from */
typedef struct { s32 w[0x2900 / 4]; } Hw_374790;
typedef struct S_3738B0 S_3738B0;
typedef struct {
    u8 pad0[0x54];
    S_3738B0 *w54;
} S_3738B0m;
struct S_3738B0 {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0x68 - 0x20];
    S_3738B0m *p68;
};
extern S_3738B0 *D_L01_001E10E0;

/* localdecomp:start func_L01_003778D0 */
void func_L01_003778D0(S_3738B0 *a0) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if ((&D_L01_001E10E0)[i] == 0) {
            (&D_L01_001E10E0)[i] = a0;
            return;
        }
    }
}
/* localdecomp:end func_L01_003778D0 */

/* localdecomp:start func_L01_00377908 */
extern S_3738B0 *D_L01_001E10E0;
s32 func_L01_00377908(void) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (((s32 *)&D_L01_001E10E0)[i] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00377908 */

/* localdecomp:start func_L01_00377940 */
extern S_3738B0 *D_L01_001E10E0;
extern s32 func_00382468(s32 a0);
s32 func_L01_00377940(void) {
    s32 i;
    u8 *e;
    i = func_00382468(4);
    e = ((u8 * *)&D_L01_001E10E0)[i];
    if (e != 0) {
        e[32] = 3;
        ((u8 * *)&D_L01_001E10E0)[i] = 0;
        return 1;
    }
    for (i = 0; i < 6; i++) {
        e = ((u8 * *)&D_L01_001E10E0)[i];
        if (e != 0) {
            e[32] = 3;
            ((u8 * *)&D_L01_001E10E0)[i] = 0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00377940 */

/* localdecomp:start func_L01_003779C8 */
extern S_3738B0 *D_L01_001E10E0;
int func_L01_003779C8(int a)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (((int *)&D_L01_001E10E0)[i] == a) {
            ((int *)&D_L01_001E10E0)[i] = 0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003779C8 */

LINKER_REMNANT("asm/levels", func_L01_00377A08);

/* localdecomp:start func_L01_00377A10 */
typedef int u128_377A10 __attribute__((mode(TI)));

typedef struct {
    u128_377A10 dir_pos;   /* 0x00 */
    f32 f10;
    s32 x14;
    f32 width;        /* 0x18 */
    f32 height;       /* 0x1C */
    s32 x20;
    s16 s24;
    s16 life;         /* 0x26 */
    s32 x28;
    f32 size;         /* 0x2C */
    s32 x30;
    u8 pad34[0x54 - 0x34];
    s32 x54;
    void *owner;      /* 0x58 */
    s32 x5c;
    s32 x60;
    s32 x64;
} P_377A10;

typedef struct {
    u8 pad0[0x24];
    f32 scale;
} C_377A10;

typedef struct {
    u8 pad0[0x10];
    u128_377A10 pos;       /* 0x10 */
    u8 x20;
    u8 pad21[2];
    u8 alpha;         /* 0x23 */
    C_377A10 *cls;    /* 0x24 */
    u8 pad28[4];
    f32 scale;        /* 0x2C */
    u8 x30;
    u8 pad31;
    s16 x32;
    u16 flags;        /* 0x34 */
    u8 pad36[0x68 - 0x36];
    P_377A10 *state;  /* 0x68 */
    u8 pad6c[0x98 - 0x6C];
    s32 x98;
    u8 pad9c[0xC0 - 0x9C];
    u128_377A10 rows[4];   /* 0xC0 */
} M_377A10;

extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern void func_0038CF68(f32, void *, void *);
extern s32 func_L01_004C85C8(void *, f32, f32, f32, s32);
extern s32 D_001D60EC;
extern s32 D_001D545C;
extern f32 D_L01_002F16F0[];
extern u8 D_001425C0[];
extern Hw_374790 D_001A4BE0; /* the hero, as rift_spawn above declares it */

/* holo_shield_spawn: make the shield (class 0x186D) as it leaves the glove */
M_377A10 *func_L01_00377A10(void *owner, u128_377A10 *pos, u128_377A10 *dir, f32 size) {
    M_377A10 *m = (M_377A10 *)func_003C24B0(0x186D, 0x900);
    P_377A10 *p;
    u128_377A10 *up;

    if (m != 0) {
        m->x20 = 0;
        m->x32 = 0xFF;
        m->x30 = 0xFF;
        p = m->state;
        m->pos = *pos;
        p->dir_pos = *dir;
        p->f10 = func_00382538();
        p->x28 = -1;
        p->size = size;
        p->x30 = 25;
        p->x14 = 0;
        p->width = 0.05f;
        p->height = 0.05f;
        if (D_001425C0[0xD2] != 0) {
            p->life = (s16)((f32)D_001D60EC * 0.75f * D_L01_002F16F0[D_001D545C]);
        } else {
            p->life = (s16)((f32)D_001D60EC * 0.75f);
        }
        p->x54 = 1;
        if (p->life == 0) {
            p->life = 4;
        }
        p->owner = owner;
        p->x20 = 0x25;
        p->x64 = 150;
        p->s24 = 0;
        up = &m->rows[2];
        m->scale = m->cls->scale * 3.25f;
        m->alpha = 0x14;
        m->flags |= 0x100;
        m->rows[3] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xF0);
        m->rows[0] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xC0);
        m->rows[1] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xD0);
        m->rows[2] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xE0);
        func_0038CF68(p->width, &m->rows[1], &m->rows[1]);
        func_0038CF68(p->height, up, up);
        p->x60 = func_L01_004C85C8(m, 1.0f, 1.0f, 1.0f, 0);
        m->x98 = 0;
        m->flags |= 4;
    }
    return m;
}
/* localdecomp:end func_L01_00377A10 */
