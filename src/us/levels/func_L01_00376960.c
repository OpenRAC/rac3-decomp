#include "common.h"

/* NTSC-U counterpart of func_L01_00377A10 (src/levels/shared/L01_00374630.c): 25 -> 30; 37 -> 45; 150 -> 180 */
extern f32 func_0037E2A8(void);
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E2A8(void);
extern void func_00388830(f32, void *, void *);
extern s32 func_L01_004C4A18(void *, f32, f32, f32, s32);
typedef struct { s32 w[0x2900 / 4]; } Hw_374790;
extern Hw_374790 D_001A4BE0;
extern f32 func_0037E2A8(void);

/* localdecomp:start func_L01_00376960 */
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

extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E2A8(void);
extern void func_00388830(f32, void *, void *);
extern s32 func_L01_004C4A18(void *, f32, f32, f32, s32);
extern s32 D_L01_001D60EC;
extern s32 D_001D545C;
extern f32 D_L01_002F1730[];
extern u8 D_001425C0[];
extern Hw_374790 D_001A4BE0; /* the hero, as rift_spawn above declares it */

/* holo_shield_spawn: make the shield (class 0x186D) as it leaves the glove */
M_377A10 *func_L01_00376960(void *owner, u128_377A10 *pos, u128_377A10 *dir, f32 size) {
    M_377A10 *m = (M_377A10 *)func_003BCFB0(0x186D, 0x900);
    P_377A10 *p;
    u128_377A10 *up;

    if (m != 0) {
        m->x20 = 0;
        m->x32 = 0xFF;
        m->x30 = 0xFF;
        p = m->state;
        m->pos = *pos;
        p->dir_pos = *dir;
        p->f10 = func_0037E2A8();
        p->x28 = -1;
        p->size = size;
        p->x30 = 30;
        p->x14 = 0;
        p->width = 0.05f;
        p->height = 0.05f;
        if (D_001425C0[0xD2] != 0) {
            p->life = (s16)((f32)D_L01_001D60EC * 0.75f * D_L01_002F1730[D_001D545C]);
        } else {
            p->life = (s16)((f32)D_L01_001D60EC * 0.75f);
        }
        p->x54 = 1;
        if (p->life == 0) {
            p->life = 4;
        }
        p->owner = owner;
        p->x20 = 0x2D;
        p->x64 = 180;
        p->s24 = 0;
        up = &m->rows[2];
        m->scale = m->cls->scale * 3.25f;
        m->alpha = 0x14;
        m->flags |= 0x100;
        m->rows[3] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xF0);
        m->rows[0] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xC0);
        m->rows[1] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xD0);
        m->rows[2] = *(u128_377A10 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xE0);
        func_00388830(p->width, &m->rows[1], &m->rows[1]);
        func_00388830(p->height, up, up);
        p->x60 = func_L01_004C4A18(m, 1.0f, 1.0f, 1.0f, 0);
        m->x98 = 0;
        m->flags |= 4;
    }
    return m;
}
/* localdecomp:end func_L01_00376960 */
