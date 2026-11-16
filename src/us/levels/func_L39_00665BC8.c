#include "common.h"

/* NTSC-U counterpart of func_L39_006684A0 (src/levels/shared/L39_006683F8.c) */
/* localdecomp:start func_L39_00665BC8 */
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
extern void *func_L39_00665D00_00665BC8(s32);

static __inline__ void Set_006684A0(V4_006684A0 *d, f32 *s) {
    d->x = s[0];
    d->y = s[1];
    d->z = s[2];
    d->w = 0.0f;
}

void func_L39_00665BC8(void *a0) {
    Msg_006684A0 *msg = a0;
    E_006684A0 *e = (E_006684A0 *)func_L39_00665D00_00665BC8(msg->id);
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
        e->w318 = 0x1E;
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
/* localdecomp:end func_L39_00665BC8 */
