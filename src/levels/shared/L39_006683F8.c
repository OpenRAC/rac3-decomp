#include "common.h"

typedef struct { u8 pad[0x2D8]; s32 x2D8; s32 x2DC; u8 pad2E0[0x2F8 - 0x2E0]; s32 x2F8; } X_006683F8;
typedef struct { u8 pad[0x2528]; X_006683F8 *x2528; u8 pad2[0x254C - 0x252C]; s32 x254C; } P_006683F8;

/* declared by functions of L39_00666F88.c, which this file was cut from */
extern s32 D_L39_002461F8;
extern char D_L39_00337700[];

/* localdecomp:start func_L39_006683F8 */
extern s32 D_001A5CD8[];

void func_L39_006683F8(P_006683F8 *p, s32 a1) {
    X_006683F8 *x;
    s32 v;

    a1 = a1 + 1;
    if (a1 >= 8) a1 = 0;
    x = p->x2528;
    if (x == 0) return;
    v = p->x254C;
    if (v == 5 || v == 3) {
        x->x2D8 = 0;
        if (D_001A5CD8[0] == a1) {
            p->x2528->x2F8 |= 4;
            p->x2528->x2F8 |= 2;
            p->x2528->x2F8 &= 0xFFFFFFDF;
        }
    } else if (v == 6 || v == 4) {
        x->x2DC = 0;
    }
    p->x2528 = 0;
    p->x254C = 0;
}
/* localdecomp:end func_L39_006683F8 */

/* localdecomp:start func_L39_006684A0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_006684A0;

typedef struct {
    f32 pos[3];
    f32 dir[3];
    s32 w18;
    s32 id;
    u8 flags;
} Msg_006684A0;

typedef struct {
    u8 pad0[0x10];
    V4_006684A0 pos;
} Mob_006684A0;

typedef struct {
    u8 pad0[0x1F0];
    V4_006684A0 v1F0;
    V4_006684A0 v200;
    u8 pad210[0x10];
    V4_006684A0 v220;
    u8 pad230[0x80];
    V4_006684A0 v2B0;
    V4_006684A0 v2C0;
    Mob_006684A0 *w2D0;
    u8 pad2D4[0xC];
    s32 w2E0;
    s32 w2E4;
    u8 pad2E8[0x10];
    s32 w2F8;
    u8 pad2FC[5];
    u8 b301;
    u8 pad302[0x16];
    s32 w318;
} E_006684A0;

/* func_L39_006685D8 is defined later in this file, returning a pointer to a typedef of its own
 * block (E_665D00), so it cannot be prototyped here under its name: an alias of it. */
extern void *func_L39_006685D8_006684A0(s32);

static __inline__ void Set_006684A0(V4_006684A0 *d, f32 *s) {
    d->x = s[0];
    d->y = s[1];
    d->z = s[2];
    d->w = 0.0f;
}

void func_L39_006684A0(void *a0) {
    Msg_006684A0 *msg = a0;
    E_006684A0 *e = (E_006684A0 *)func_L39_006685D8_006684A0(msg->id);
    u8 f;
    s32 t;

    if (e == 0) {
        return;
    }
    f = msg->flags;
    if (f & 4) {
        Set_006684A0(&e->v220, msg->dir);
        e->w2E4 = msg->w18;
        return;
    }
    if (f & 8) {
        e->b301 = 1;
    } else {
        e->b301 = 0;
    }
    Set_006684A0(&e->v1F0, msg->pos);
    Set_006684A0(&e->v200, msg->dir);
    t = e->w2F8;
    e->w2E0 = msg->w18;
    e->w2F8 = t | 1;
    if (msg->flags & 1) {
        e->w2F8 = t | 0x11;
    } else if (msg->flags & 2) {
        e->w318 = 0x19;
        e->v2B0 = e->w2D0->pos;
        __asm__ __volatile__(
            "lqc2 $vf2, 0x10(%0)\n"
            "lqc2 $vf1, 0x1F0(%1)\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0x2C0(%1)\n"
            : : "r"(e->w2D0), "r"(e) : "memory");
        e->w2F8 |= 2;
    } else {
        e->w2F8 = t | 1;
    }
}
/* localdecomp:end func_L39_006684A0 */

/* localdecomp:start func_L39_006685D8 */
extern char D_L39_00337700[];
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D00;
extern s32 D_L39_002461F8;
E_665D00 *func_L39_006685D8(s32 a0) {
    s32 i;
    for (i = 0; i < D_L39_002461F8; i++) {
        if (((E_665D00 *)&D_L39_00337700)[i].id == a0) return &((E_665D00 *)&D_L39_00337700)[i];
    }
    return 0;
}
/* localdecomp:end func_L39_006685D8 */
