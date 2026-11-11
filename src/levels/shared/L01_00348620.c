#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x2];
    s16 active;
    char pad14[0x18 - 0x14];
    f32 unk18;
    f32 unk1C;
    char pad20[0x40 - 0x20];
} Entry;
typedef struct {
    char pad0[0x1A];
    s16 unk1A;
} Vars;
typedef struct {
    char pad0[0x68];
    Vars *vars;
} Moby;
typedef struct {
    s32 unk0;
    s32 offset;
} Info;
typedef struct {
    u8 pad0[24];
    s32 x18;
    u8 pad1[20];
} S_27F600;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    u8 f10[16];
} Src_0034C508;
typedef struct {
    u8 pad0[24];
    Src_0034C508 *src;
    u8 pad1C[20];
} Ent_0034C508;
typedef struct {
    u8 pad0[124];
    s32 f124;
    u8 pad128[8];
    s32 f136;
    u8 pad140[20];
} Sub_0034CC80;
typedef struct {
    u8 pad0[48];
    Sub_0034CC80 sub;
} Entry_0034CC80;
typedef int s128 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_00348620);

INCLUDE_ASM("asm/levels", func_L01_00348A98);

INCLUDE_ASM("asm/levels", func_L01_00348C88);

INCLUDE_ASM("asm/levels", func_L01_00348E30);

/* localdecomp:start func_L01_003493C8 */
typedef struct {
    f32 pos[4];
    s16 life;     /* 0x10: frames */
    s16 active;   /* 0x12 */
    f32 per_tick; /* 0x14: 1 / life */
    f32 roll;     /* 0x18 */
    f32 spin;     /* 0x1C: radians a frame */
    f32 size_a;   /* 0x20 */
    f32 grow_a;   /* 0x24 */
    f32 size_b;   /* 0x28 */
    f32 grow_b;   /* 0x2C */
    s32 age;      /* 0x30 */
    f32 swing;    /* 0x34: radians a frame */
    f32 x38;
    u8 pad3C[4];
} Sprite_003493C8;

__asm__(".extern D_L01_001DD398, 4");
__asm__(".extern D_L01_001DD39C, 4");
__asm__(".extern D_L01_001DD3A0, 4");
__asm__(".extern D_L01_001DD3A4, 4");
__asm__(".extern D_L01_001DD3A8, 4");
__asm__(".extern D_L01_001DD3AC, 4");
__asm__(".extern D_L01_001DD3B0, 4");
__asm__(".extern D_L01_001DD3B4, 4");
__asm__(".extern D_L01_001DD3C8, 4");
__asm__(".extern D_L01_001DD3CC, 4");
__asm__(".extern D_L01_001DD3D0, 4");
__asm__(".extern D_L01_001DD3D4, 4");
extern s32 D_L01_001DD398;
extern s32 D_L01_001DD39C;
extern f32 D_L01_001DD3A0;
extern f32 D_L01_001DD3A4;
extern f32 D_L01_001DD3A8;
extern f32 D_L01_001DD3AC;
extern f32 D_L01_001DD3B0;
extern f32 D_L01_001DD3B4;
extern f32 D_L01_001DD3C8;
extern f32 D_L01_001DD3CC;
extern f32 D_L01_001DD3D0;
extern f32 D_L01_001DD3D4;
extern char *func_L01_00457480(s32, s32);
extern Info *func_L01_004574B0(s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);

/* flux_trail_sprite_add: lays one of the Flux Rifle shot's trail sprites (twice a frame from
   V3) at pos, in the first free of the gun's 120: a life of 45-60 frames (D_L01_001DD398,
   D_L01_001DD39C) x 5/6 for PAL's 50 Hz, rounded; a random roll, a spin of 1-4 degrees a
   frame either way, sizes 0.3-0.5 growing 0.75-1.25, a swing of 1-2 degrees a frame and
   0.1-0.25 at 0x38. */
void func_L01_003493C8(Moby *shot, s128 *pos)
{
    Vars *vars = shot->vars;
    Sprite_003493C8 *sprite;
    s32 i;

    sprite = (Sprite_003493C8 *)(func_L01_00457480(0xC04, vars->unk1A)
                                 + func_L01_004574B0(0xC04, vars->unk1A)->offset);
    for (i = 0; i < 120; i++, sprite++) {
        if (sprite->active == 0) {
            sprite->active = 1;
            *(s128 *)sprite->pos = *pos;
            /* (n * 5 + 2) / 6: n x 50/60, rounded */
            sprite->life = (func_00382498(D_L01_001DD398, D_L01_001DD39C) * 5 + 2) / 6;
            sprite->per_tick = 1.0f / sprite->life;
            sprite->roll = func_00382538();
            sprite->spin = func_L01_00443A18(D_L01_001DD3A0, D_L01_001DD3A4) * 0.017453292f;
            sprite->size_a = func_003824E0(D_L01_001DD3A8, D_L01_001DD3AC);
            sprite->grow_a = func_003824E0(D_L01_001DD3B0, D_L01_001DD3B4);
            sprite->size_b = func_003824E0(D_L01_001DD3A8, D_L01_001DD3AC);
            sprite->grow_b = func_003824E0(D_L01_001DD3B0, D_L01_001DD3B4);
            sprite->age = 0;
            sprite->swing = func_003824E0(D_L01_001DD3C8, D_L01_001DD3CC) * 0.017453292f;
            sprite->x38 = func_003824E0(D_L01_001DD3D0, D_L01_001DD3D4);
            return;
        }
    }
}
/* localdecomp:end func_L01_003493C8 */

/* localdecomp:start func_L01_00349538 */




extern char *func_L01_00457480(s32, s32);
extern Info *func_L01_004574B0(s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038DAB8(f32, f32);

s32 func_L01_00349538(Moby *m) {
    Vars *v = m->vars;
    Entry *e;
    s32 i;
    s32 count = 0;

    e = (Entry *)(func_L01_00457480(3076, v->unk1A) + func_L01_004574B0(3076, v->unk1A)->offset);
    for (i = 0; i < 120; i++) {
        if (e[i].active != 0) {
            if (func_0038CB00(e[i].pos) != 0) {
                e[i].active = 0;
            } else {
                count++;
                e[i].unk18 = func_0038DAB8(e[i].unk18, e[i].unk1C);
            }
        }
    }
    return count;
}
/* localdecomp:end func_L01_00349538 */

INCLUDE_ASM("asm/levels", func_L01_003495F0);

INCLUDE_ASM("asm/levels", func_L01_00349998);

INCLUDE_ASM("asm/levels", func_L01_00349C58);

INCLUDE_ASM("asm/levels", func_L01_0034A3C8);

INCLUDE_ASM("asm/levels", func_L01_0034ACD8);

INCLUDE_ASM("asm/levels", func_L01_0034C300);

INCLUDE_ASM("asm/levels", func_L01_0034C378);

/* localdecomp:start func_L01_0034C4E0 */
void func_L01_0034C4E0(void) {

}
/* localdecomp:end func_L01_0034C4E0 */

INCLUDE_ASM("asm/levels", func_L01_0034C4E8);

/* localdecomp:start func_L01_0034C910 */
extern void func_L01_0043B9E8(void *, s32, s32, s32);

void func_L01_0034C910(u8 *s) {
    u8 *m;

    func_L01_0043B9E8(*(u8 **)(s + 0x18), s[4], s[5], s[6]);
    m = *(u8 **)(s + 0x18);
    if (*(u16 *)(m + 0x34) & 0x20) {
        u8 *p = *(u8 **)(*(u8 **)(m + 0x68) + 0x10);
        if (p != 0 && *(s16 *)p != 0) {
            p[4] = s[4];
            p[5] = *(s32 *)(s + 4) >> 8;
            p[6] = *(s32 *)(s + 4) >> 16;
        }
    }
}
/* localdecomp:end func_L01_0034C910 */

/* localdecomp:start func_L01_0034C990 */

extern S_27F600 D_L01_0027F580[];

s32 func_L01_0034C990(s32 id) {
    s32 r = -1;
    s32 i;

    for (i = 0; i < 30; i++) {
        if (D_L01_0027F580[i].x18 == id) {
            r = i;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L01_0034C990 */

INCLUDE_ASM("asm/levels", func_L01_0034C9F0);

/* localdecomp:start func_L01_0034CE70 */
/* func_L01_0034CE70: first draft, adapted from the rac2 donor */
__asm__(".extern D_L01_001DD3D8, 4");
extern s32 D_L01_001DD3D8;
extern u8 *func_003C24B0(s32, s32);

void *func_L01_0034CE70(void) {
    u8 *p = func_003C24B0(4406, 128);

    if (p != 0) {
        s32 v = 0xFF;

        D_L01_001DD3D8 = (s32)p;
        p[0x20] = 1;
        *(u16 *)(p + 0x32) = v;
        p[0x30] = v;
    }
    return p;
}
/* localdecomp:end func_L01_0034CE70 */

/* localdecomp:start func_L01_0034CEB8 */
typedef struct {
    f32 damage;     /* taken at once on the hit */
    f32 arc_damage; /* each arc's */
    s32 seconds;    /* how long the target keeps arcing */
    f32 interval;   /* seconds between arcs */
} ShockRow_0034CEB8;

__asm__(".extern D_L01_001DD3D8, 4");
extern s32 D_L01_001DD3D8;
extern S_27F600 D_L01_0027F580[];
extern void *func_L01_0034CE70(void);
/* the per-item tables: bank 0, then bank 1 (the gun at V3 or V4) */
extern ShockRow_0034CEB8 D_L01_00282220[][204];

/* shock_mod_tables_init: at the level start, empties the shock slots and fills the shock
   mod's per-item tables in two banks; only the Miniturret Glove (0x15, 0xA2) has numbers. */
void func_L01_0034CEB8(void)
{
    s32 i;

    for (i = 29; i >= 0; i--) {
        D_L01_0027F580[i].x18 = 0;
    }
    D_L01_001DD3D8 = 0;
    /* its moby (class 0x1136), which D_L01_001DD3D8 keeps; called with a 0 it ignores */
    ((void *(*)(s32))func_L01_0034CE70)(0);
    for (i = 0; i < 204; i++) {
        D_L01_00282220[0][i].interval = 1.0f;
        D_L01_00282220[1][i].interval = 1.0f;
    }
    /* the Miniturret Glove: 1 at once, arcs of 2, for 3 s (bank 1: 2, 4, 3 s) */
    D_L01_00282220[0][0x15].damage = 1.0f;
    D_L01_00282220[0][0x15].arc_damage = 2.0f;
    D_L01_00282220[0][0x15].seconds = 3;
    D_L01_00282220[0][0xA2].damage = 1.0f;
    D_L01_00282220[0][0xA2].arc_damage = 2.0f;
    D_L01_00282220[0][0xA2].seconds = 3;
    D_L01_00282220[1][0x15].damage = 2.0f;
    D_L01_00282220[1][0x15].arc_damage = 4.0f;
    D_L01_00282220[1][0x15].seconds = 3;
    D_L01_00282220[1][0xA2].damage = 2.0f;
    D_L01_00282220[1][0xA2].arc_damage = 4.0f;
    D_L01_00282220[1][0xA2].seconds = 3;
}
/* localdecomp:end func_L01_0034CEB8 */

/* localdecomp:start func_L01_0034CF88 */
extern S_27F600 D_L01_0027F580[];
extern void func_003C5180(void *, f32 *, s32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_L01_0034D700(s32);
void func_L01_0034CF88(s32 a) {
    f32 v[4];
    Ent_0034C508 *p;
    s32 i;
    f32 k1;
    f32 k2;
    p = ((Ent_0034C508 *)&D_L01_0027F580);
    k1 = 0.000976499985f;
    k2 = 0.850000024f;
    for (i = 0; i < 30; i++, p++) {
        if (p->src != 0) {
            func_003C5180(p->src->f10, v, 1);
            func_0038CE20(v, v, p->src->fC * k1 * k2);
            v[0] += p->src->f0 * k1;
            v[1] += p->src->f4 * k1;
            v[2] += p->src->f8 * k1;
        }
    }
    func_L01_0034D700(a);
}
/* localdecomp:end func_L01_0034CF88 */

INCLUDE_ASM("asm/levels", func_L01_0034D078);

INCLUDE_ASM("asm/levels", func_L01_0034D2F0);

/* localdecomp:start func_L01_0034D700 */


extern Entry_0034CC80 D_L01_0027FB20[];
extern void func_L01_0034D9E0(s32, Entry_0034CC80 *);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_0034D700(s32 arg0) {
    s32 i;
    Entry_0034CC80 *e;
    Sub_0034CC80 *s;

    for (i = 47; i >= 0; i--) {
        e = &D_L01_0027FB20[47 - i];
        s = &e->sub;
        if (s->f124 == arg0) {
            func_L01_0034D9E0(arg0, e);
            if (s->f136 == 0) {
                func_003D9508(s, 49, (func_00382498(80, 96) << 24) | 0x103080, 1, 0.5f, 0.1f, func_00382538());
                func_003D9508(s, 49, (func_00382498(80, 96) << 24) | 0xFFFFFF, 1, 0.5f, 0.1f, func_00382538());
            }
        }
    }
}
/* localdecomp:end func_L01_0034D700 */

/* localdecomp:start func_L01_0034D840 */
void func_L01_0034D840(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0034D840 */

INCLUDE_ASM("asm/levels", func_L01_0034D8C8);

INCLUDE_ASM("asm/levels", func_L01_0034D9E0);

INCLUDE_ASM("asm/levels", func_L01_0034DBA8);

INCLUDE_ASM("asm/levels", func_L01_0034DBE8);

INCLUDE_ASM("asm/levels", func_L01_0034E080);

INCLUDE_ASM("asm/levels", func_L01_0034E558);

INCLUDE_ASM("asm/levels", func_L01_0034E808);

/* localdecomp:start func_L01_0034E9E0 */
void func_L01_0034E9E0(char *object)
{
    char *state = *(char **)(object + 0x68);
    int i;

    for (i = 0; i < 10; i++) {
        *(int *)(*(char **)(state + 0) + i * 16 + 0) = 0;
        *(int *)(*(char **)(state + 0) + i * 16 + 4) = 0;
        *(int *)(*(char **)(state + 0) + i * 16 + 8) = 0;
        *(float *)(*(char **)(state + 0) + i * 16 + 12) = 1.0f;
    }

    for (i = 0; i < 20; i++) {
        *(int *)(*(char **)(state + 4) + i * 16 + 0) = 0;
        *(int *)(*(char **)(state + 4) + i * 16 + 4) = 0;
        *(int *)(*(char **)(state + 4) + i * 16 + 8) = 0;
        *(float *)(*(char **)(state + 4) + i * 16 + 12) = 1.0f;
    }

    *(int *)(state + 0xC) = 0;
    *(short *)(state + 0x1C) = 5;
    *(int *)(state + 0x10) = 0;
    *(int *)(state + 0x14) = 0;
    *(int *)(state + 0x8) = 0;
}
/* localdecomp:end func_L01_0034E9E0 */

INCLUDE_ASM("asm/levels", func_L01_0034EAA0);

/* localdecomp:start func_L01_0034F0B0 */
__asm__(".extern D_L01_001DD438, 4");
__asm__(".extern D_L01_001DD43C, 4");
__asm__(".extern D_L01_001DD440, 4");
__asm__(".extern D_L01_001DD444, 4");
__asm__(".extern D_L01_001DD448, 4");
extern s32 D_L01_001DD438;
extern s32 D_L01_001DD43C;
extern s32 D_L01_001DD440;
extern s32 D_L01_001DD444;
extern f32 D_L01_001DD448;
extern void func_003A9440(s32, unsigned long);
extern void func_L01_0034F168(u8 *bolt, s32 line, s32 core_alpha, s32 glow_alpha, s32 points);

/* lightning_bolt_draw: scrolls the ribbons' u, then draws each of the bolt's two lines as
   two added ribbons, a core and a glow in the bolt's colour. */
void func_L01_0034F0B0(u8 *bolt)
{
    u8 *vars = *(u8 **)(bolt + 0x68);
    f32 u;

    /* u scrolls 0.2 a frame (D_L01_001DD448), x 1.2 for PAL's 50 Hz, wrapping by 8 */
    u = *(f32 *)(vars + 0x14) - D_L01_001DD448 * 1.2f;
    *(f32 *)(vars + 0x14) = u;
    if (u <= -8.0f) {
        *(f32 *)(vars + 0x14) = u + 8.0f;
    }
    func_003A9440(0x47, 0x51001);
    /* the core at alpha 0x80, the glow at 0x40; the first line of 10 points, the second of 20 */
    func_L01_0034F168(bolt, *(s32 *)vars, D_L01_001DD438, D_L01_001DD440, 10);
    func_L01_0034F168(bolt, *(s32 *)(vars + 4), D_L01_001DD43C, D_L01_001DD444, 20);
}
/* localdecomp:end func_L01_0034F0B0 */

INCLUDE_ASM("asm/levels", func_L01_0034F168);

/* localdecomp:start func_L01_0034F7E8 */
void func_L01_0034F7E8(void) {

}
/* localdecomp:end func_L01_0034F7E8 */

/* localdecomp:start func_L01_0034F7F0 */
extern s32 D_L01_001E2EC4[];
extern f32 D_L01_001E2EC8[];
extern s32 D_L01_001E1A0C;
extern s32 D_001D545C;
extern s128 D_L01_002B2AB0[];
extern void func_L01_0034FA00(u8 *);
extern f32 func_L01_0034F908(u8 *);
extern void func_L01_0034FC28(void);
extern void func_L01_00404808(void (*)(void), u8 *);
void func_L01_0034F7F0(u8 *m) {
    s128 *v = *(s128 **)(m + 104);
    s32 t;
    s32 i;
    switch (m[32]) {
    case 0:
        m[48] = 255;
        m[32] = 1;
        D_L01_001E2EC4[0] = 0;
        t = D_001D545C;
        i = 0;
        if (t == 1) {
            D_L01_001E1A0C = 100;
        } else if (t == 2) {
            D_L01_001E1A0C = 101;
            i = 1;
        } else if (t == 5) {
            D_L01_001E1A0C = 105;
            i = 2;
        } else if (t == 16) {
            D_L01_001E1A0C = 100;
            i = 3;
        } else if (t == 26) {
            D_L01_001E1A0C = 100;
            i = 5;
        }
        *v = D_L01_002B2AB0[i];
        func_L01_0034FA00(m);
        break;
    case 1:
        D_L01_001E2EC8[0] = func_L01_0034F908(m);
        func_L01_00404808(func_L01_0034FC28, m);
        break;
    }
}
/* localdecomp:end func_L01_0034F7F0 */

INCLUDE_ASM("asm/levels", func_L01_0034F908);

INCLUDE_ASM("asm/levels", func_L01_0034FA00);

INCLUDE_ASM("asm/levels", func_L01_0034FC28);

/* localdecomp:start func_L01_0034FFE8 */
extern void func_003C2880(char *object);

/* from rac2-decomp's func_L00_0040DF00, renamed */
void func_L01_0034FFE8(char *object)
{
    char *handle = *(char **)(object + 104);
    if (func_0038CB00(handle) == 0)
        func_0038CB00(handle + 4);
    else
        func_003C2880(object);
}
/* localdecomp:end func_L01_0034FFE8 */
