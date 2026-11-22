#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 w8;
} S_1A1ED0;
typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} S_1CFEC0;

INCLUDE_ASM("asm/levels", func_L01_0037EFC8);

/* localdecomp:start func_L01_0037F860 */
typedef int Q_0037F860 __attribute__((mode(TI)));
typedef struct {f32 x,y,z,w;} __attribute__((aligned(16))) V_0037F860;
extern s32 D_L01_001E1DC0;
extern f32 D_L01_001DDB84;
extern f32 D_L01_001E1DD0;
extern Q_0037F860 D_L01_0028F5A0[];
extern s32 D_L01_001DDBE8,D_L01_001DDBF0,D_L01_001DDBF4;
extern s32 D_L01_001E1DD4;
extern s32 D_L01_001E1E84;
extern u8 D_L01_001E1E80[3] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E80, 16");
extern Q_0037F860 D_L01_001E1E10[3] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1E10, 48");
__asm__(".extern D_L01_001DDB84, 4");
__asm__(".extern D_L01_001E1DD0, 4");
__asm__(".extern D_L01_001DDBE8, 4");
__asm__(".extern D_L01_001DDBF0, 4");
__asm__(".extern D_L01_001DDBF4, 4");
__asm__(".extern D_L01_001E1DC0, 16");
__asm__(".extern D_L01_001E1DD4, 16");
__asm__(".extern D_L01_001E1E84, 16");
void func_L01_0037F860(u8 *m) {
 extern void func_0038CE20(Q_0037F860 *,Q_0037F860 *,f32);
 V_0037F860 step;
 Q_0037F860 *v=*(Q_0037F860 **)(m+0x68);
 s32 i,j;
 Q_0037F860 *p;
 if(D_L01_001E1DC0) {
  D_L01_001E1DC0=0;
  D_L01_001E1DD0=D_L01_001DDB84/12.0f;
  func_0038CE20((Q_0037F860 *)&step,(Q_0037F860 *)(m+0xC0),-D_L01_001E1DD0);
  D_L01_0028F5A0[0]=v[0];
  p=D_L01_0028F5A0+1;
  i=10;
  do {
   __asm__ __volatile__("lqc2 vf2,%0\n\tlqc2 vf1,%1\n\tvadd.xyz vf2,vf2,vf1" : : "m"(p[-1]), "m"(step) : "vf1","vf2");
   i--;
   __asm__ __volatile__("sqc2 vf2,%0" : "=m"(p[0]) : : "vf2");
   p++;
  } while(i>=0);
  D_L01_001DDBE8=0;D_L01_001DDBF0=0;D_L01_001DDBF4=0;
  D_L01_001E1DD4=0;D_L01_001E1E84=0;
  for(j=0;j<3;j++) {
   D_L01_001E1E10[j]=*(Q_0037F860 *)&step;
   D_L01_001E1E80[j]=0;
  }
 }
}
/* localdecomp:end func_L01_0037F860 */

INCLUDE_ASM("asm/levels", func_L01_0037F948);

INCLUDE_ASM("asm/levels", func_L01_00380880);

INCLUDE_ASM("asm/levels", func_L01_00380CE0);

INCLUDE_ASM("asm/levels", func_L01_003812B0);

INCLUDE_ASM("asm/levels", func_L01_00381500);

INCLUDE_ASM("asm/levels", func_L01_00381720);

/* localdecomp:start func_L01_00382500 */
#include "vu0.h"
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00382578(s32 a0, s32 a1, s32 alpha);
extern u8 D_L01_001DDCE0[8];
__asm__(".extern D_L01_001DDCE0, 8");
extern s32 D_L01_001E1E94;

void func_L01_00382500(u8 *a0) {
    vu0_v4 v;

    func_0038D000(&v, D_L01_001DDCE0, a0 + 0xC0);
    vec_add_ab(&v, a0 + 0x10, &v);
    ((void (*)(void *, s32, s32, f32, f32, f32, f32))func_L01_00382578)(&v, 0x78, D_L01_001E1E94 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00382500 */

/* localdecomp:start func_L01_00382578 */


__asm__(".extern D_L01_001DDCF0, 4");
__asm__(".extern D_L01_001DDCF8, 4");
__asm__(".extern D_L01_001DDCFC, 4");
__asm__(".extern D_L01_001DDD00, 4");
__asm__(".extern D_L01_001DDD04, 4");
__asm__(".extern D_L01_001DDD08, 4");
__asm__(".extern D_L01_001DDD0C, 4");
__asm__(".extern D_L01_001DDD10, 4");
__asm__(".extern D_L01_001DDD14, 4");
__asm__(".extern D_L01_001DDD18, 4");
__asm__(".extern D_L01_001DDD1C, 4");
__asm__(".extern D_L01_001DDD20, 4");
__asm__(".extern D_L01_001DDD24, 4");
__asm__(".extern D_L01_001DDD28, 4");
extern S_1A1ED0 D_001A1ED0[];
extern S_1CFEC0 D_001CFEC0[];
extern s32 D_L01_001DDCF0;
extern s32 D_L01_001DDCF8;
extern s32 D_L01_001DDCFC;
extern s32 D_L01_001DDD00;
extern s32 D_L01_001DDD04;
extern s32 D_L01_001DDD08;
extern s32 D_L01_001DDD0C;
extern s32 D_L01_001DDD10;
extern s32 D_L01_001DDD14;
extern s32 D_L01_001DDD18;
extern s32 D_L01_001DDD1C;
extern s32 D_L01_001DDD20;
extern s32 D_L01_001DDD24;
extern s32 D_L01_001DDD28;

extern void func_L01_004C5E28(void);
extern void func_003A9440(s32 reg, long value);
extern void func_003D1030(void);
extern long func_00389598(s32);
extern void func_0038B4D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, long c, long d);

void func_L01_00382578(s32 a0, s32 a1, s32 alpha) {
    S_1A1ED0 *z;
    S_1CFEC0 *s;
    s32 color;
    long tex;

    func_L01_004C5E28();
    z = D_001A1ED0;
    func_003A9440(0x4E, (long)(z->w8 >> 13) | 0x1000000 | 0x100000000L);
    func_003A9440(0x42, (long)D_L01_001DDCFC | ((long)D_L01_001DDD00 << 2) | ((long)D_L01_001DDD04 << 4)
                  | ((long)D_L01_001DDD08 << 6) | (0x80L << 32));
    func_003D1030();
    tex = func_00389598(D_L01_001DDCF0);
    s = D_001CFEC0;
    color = (alpha << 24) | 0x7F7F7F;
    func_0038B4D0(0, 0, (s32)(s->h150 * 0.5f), (s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_0038B4D0(s->h150, 0, -(s32)(s->h150 * 0.5f), (s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_0038B4D0(0, s->h152, (s32)(s->h150 * 0.5f), -(s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_0038B4D0(s->h150, s->h152, -(s32)(s->h150 * 0.5f), -(s32)(s->h152 * 0.5f), 0, 0, 255, 255, color, tex);
    func_003A9440(0x42, (long)D_L01_001DDCFC | ((long)D_L01_001DDD00 << 2) | ((long)D_L01_001DDD04 << 4)
                  | ((long)D_L01_001DDD08 << 6) | (0x80L << 32));
    func_003A9440(0x42, (long)D_L01_001DDD0C | ((long)D_L01_001DDD10 << 2) | ((long)D_L01_001DDD14 << 4)
                  | ((long)D_L01_001DDD18 << 6) | (0x80L << 32));
    func_0038B4D0(0, 0, s->h150, s->h152, D_L01_001DDD1C, D_L01_001DDD20, D_L01_001DDD24, D_L01_001DDD28, D_L01_001DDCF8, func_00389598(-7));
    func_003A9440(0x4E, 0x1000000 | (long)(z->w8 >> 13));
}
/* localdecomp:end func_L01_00382578 */

LINKER_REMNANT("asm/levels", func_L01_00382888);

INCLUDE_ASM("asm/levels", func_L01_00382890);

INCLUDE_ASM("asm/levels", func_L01_00382CF8);

/* localdecomp:start func_L01_003837A8 */
void func_L01_003837A8(u8 *a) {
    a[0x20] = 1;
}
/* localdecomp:end func_L01_003837A8 */

INCLUDE_ASM("asm/levels", func_L01_003837B8);

/* localdecomp:start func_L01_003839C8 */
#include "structs/weapon.h"
#include "structs/moby.h"

typedef int u128_3839C8 __attribute__((mode(TI)));
typedef struct {
    u128_3839C8 start;      /* 0x00 */
    void *owner;            /* 0x10 */
    f32 speed;              /* 0x14 */
    u8 pad_18[8];
    f32 drag;               /* 0x20 */
    s32 unk_24;
    s32 unk_28;
    s32 flags;              /* 0x2C */
    u8 pad_30[4];
    s32 kind;               /* 0x34 */
    s32 shadow;             /* 0x38 */
    s32 target;             /* 0x3C */
} SuckShot_3839C8;
typedef struct {
    u8 pad_0[0x10];
    u128_3839C8 position;
    u8 state;
    u8 pad_21[3];
    struct MobyClass *pclass;
    u8 pad_28[4];
    f32 scale;
    u8 b30;
    u8 b31;
    s16 draw_dist;
    long d38;
    u8 pad_40[0x68 - 0x40];
    SuckShot_3839C8 *pvar;
    u8 pad_6C[0x98 - 0x6C];
    void *coll_record;
    u8 pad_9C[0xAA - 0x9C];
    s16 oclass;
    u8 pad_AC[0xF0 - 0xAC];
    u128_3839C8 rotation;
} MobyQ_3839C8;
typedef struct {
    u8 pad_0[0x25C0];
    MobyQ_3839C8 *hero_moby;
} H_3839C8;

typedef struct {
    s32 w[0x2900 / 4];
} Hw_3839C8;
extern Hw_3839C8 D_001A4BE0;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern MobyQ_3839C8 *func_003C24B0(s32 oclass, s32 a1);
extern s32 func_L01_00445F40(void *moby, s32 target);
extern f32 func_0038CEA8(void *pvar);
extern void func_L01_004CAC78(void *out, void *from, f32 speed, f32 range, f32 max_angle);
extern s32 func_L01_004C85C8(void *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_003C7C38(void *moby);

/* suck_shot_spawn: spawns the Suck Cannon's shot, class 0x1872 given the model of what it took in at 0.7 of its class's scale */
MobyQ_3839C8 *func_L01_003839C8(f32 speed, void *owner, u128_3839C8 *start, u128_3839C8 *position, u128_3839C8 *rotation, s32 target, s32 kind) {
    MobyQ_3839C8 *m;
    SuckShot_3839C8 *shot;

    m = func_003C24B0(0x1872, 0x80);
    if (m != 0) {
        m->b30 = 0xFF;
        m->draw_dist = 0xFF;
        m->b31 = 1;
        m->state = 0;
        shot = m->pvar;
        m->d38 = ((MobyQ_3839C8 *)D_001A4BE0.w[0x25C0 / 4])->d38;
        m->position = *position;
        m->rotation = *rotation;
        func_L01_00445F40(m, target);
        shot->target = target;
        m->oclass = 0x1872;
        m->scale = m->pclass->scale * 0.7f;
        shot->start = *start;
        shot->owner = owner;
        shot->speed = speed;
        shot->drag = 0.15f;
        shot->kind = kind;
        if ((D_L01_002C5600 + D_001425C0[0x87])->level >= 2) {
            shot->flags = 0x110000;
        } else {
            shot->flags = 0x10000;
        }
        if (D_001A4BE0.w[0x16B0 / 4] != 0) {
            func_L01_004CAC78(shot, position, func_0038CEA8(shot), 30.0f, 0.34906584f);
        }
        shot->shadow = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
        shot->unk_24 = 0;
        func_003C7C38(m);
    }
    m->coll_record = 0;
    return m;
}
/* localdecomp:end func_L01_003839C8 */

INCLUDE_ASM("asm/levels", func_L01_00383BA0);

INCLUDE_ASM("asm/levels", func_L01_00383FB8);

LINKER_REMNANT("asm/levels", func_L01_00384510);

INCLUDE_ASM("asm/levels", func_L01_00384518);

/* localdecomp:start func_L01_00384E68 */
#include "structs/weapon.h"

typedef int u128_384E68 __attribute__((mode(TI)));
typedef struct {
    u8 pad_0[0x10];
    u128_384E68 position;
} Moby_384E68;

extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern u8 D_L01_001EEA80[];
extern void func_0038CE20(u128_384E68 *out, u128_384E68 *in, f32 scale);
extern s32 func_003D4D00(void *centre, f32 radius, s32 kinds, void *skip, s32 extra);
extern void func_L01_00447718(void *source, void *centre, void *mobys, s32 count, void *skip,
                              s32 flags, s32 a6, s32 a7, s32 a8, f32 damage, f32 push_out, f32 push_up);

/* ryno_missile_blast: the RY3NO V1 missile's blast: every moby within 4 u but the one it hit
   takes the row's splash damage (+0x70), pushed 4 out and 6 up */
void func_L01_00384E68(Moby_384E68 *missile, u128_384E68 *dir, void *hit) {
    u128_384E68 back;
    u128_384E68 centre;
    f32 splash;
    s32 count;

    func_0038CE20(&back, dir, -3.0f);
    /* item 0x97's current row: the RY3NO's */
    splash = (D_L01_002C5600 + D_001425C0[0x97])->damage_more[0];
    count = func_003D4D00(&missile->position, 4.0f, 0x10, missile, 0);
    centre = missile->position;
    func_L01_00447718(missile, &centre, D_L01_001EEA80, count, hit, 0x1010000, 3, 1, -1, splash, 4.0f, 6.0f);
}
/* localdecomp:end func_L01_00384E68 */

LINKER_REMNANT("asm/levels", func_L01_00384F40);

INCLUDE_ASM("asm/levels", func_L01_00384F48);

/* localdecomp:start func_L01_00385188 */
#include "vu0.h"
extern void func_0038D000(void *, void *, void *);
extern f32 D_L01_001DDD88;
__asm__(".extern D_L01_001DDD88, 4");

void func_L01_00385188(s32 a0, void *a1) {
    vu0_v4 r;
    vu0_v4 v;

    *(vu0_q *)&v = 0;
    v.x = D_L01_001DDD88;
    v.w = 1.0f;
    *(vu0_q *)&r = *(vu0_q *)&v;
    func_0038D000(&r, &r, (u8 *)a0 + 0xC0);
    vec_add_ba(a1, &r, (u8 *)a0 + 0x10);
}
/* localdecomp:end func_L01_00385188 */

/* localdecomp:start func_L01_003851F8 */
__asm__(".extern D_L01_001DDD8C, 4");
extern s32 D_L01_001DDD8C;
extern void func_L01_00385188(s32, void *);
extern void func_L01_00409B08(void *, s32, s32);

void func_L01_003851F8(s32 a0) {
    s32 buf[4];
    func_L01_00385188(a0, buf);
    func_L01_00409B08(buf, D_L01_001DDD8C, 0);
}
/* localdecomp:end func_L01_003851F8 */

INCLUDE_ASM("asm/levels", func_L01_00385228);

INCLUDE_ASM("asm/levels", func_L01_003854F8);

/* localdecomp:start func_L01_00385EA0 */
extern void func_L01_004C8668(int);
extern void func_003C2880(void *);
void func_L01_00385EA0(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_L01_004C8668(*(int *)(v + 48));
    }
    func_003C2880(m);
}
/* localdecomp:end func_L01_00385EA0 */

/* localdecomp:start func_L01_00385EE0 */
#include "structs/moby.h"

typedef int u128_385EE0 __attribute__((mode(TI)));
/* an N90 bullet's pvars: what its tail keeps */
typedef struct {
    s32 slot;                      /* 0x00: the bullet's row in the tail table */
    u8 pad_04[0x10 - 0x4];
    s32 points;                    /* 0x10: points kept, up to 40 */
    s32 key_b;                     /* 0x14 */
    s32 key_a;                     /* 0x18 */
    u8 pad_1C[0x30 - 0x1C];
    s32 glow;                      /* 0x30 */
    s32 fade;                      /* 0x34: frames left of the fade once the bullet ends */
} Bullet_385EE0;

__asm__(".extern D_L01_001DDD94, 4");
extern f32 D_L01_001DDD94;
extern u128_385EE0 **func_L01_00457480(s32 a, s32 b);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_00386148(void *points, s32 a1, s32 a2, s32 count, s32 colour_end, s32 colour_start, f32 f0, f32 f1, f32 scroll);

/* n90_bullet_tail_record: keeps where the N90 bullet was over its last 20 frames, for its tail */
void func_L01_00385EE0(struct Moby *m) {
    Bullet_385EE0 *b;
    u128_385EE0 **table;
    u128_385EE0 *row;
    s32 slot;
    s32 i;
    s32 j;
    s32 count;
    s32 tail;
    s32 head;
    s32 pts;
    f32 scroll;
    f32 fade;

    b = m->pvar;
    if (m == 0) return;
    if ((u8)m->state == 0xFE) return;
    if ((u8)m->state == 0xFD) return;
    if (b == 0) return;
    slot = b->slot;
    table = func_L01_00457480(b->key_a, b->key_b);
    if (table == 0) {
        func_L01_004C8668(b->glow);
        func_003C2880(m);
        return;
    }
    for (i = 0; i < b->points; i++) {
        func_L01_004CAB30(table[slot] + i, table[slot] + i);
    }
    if ((u8)m->state == 0) {
        b->points++;
        if (b->points >= 40) b->points = 40;
        for (j = b->points - 1; j > 0; j--) {
            table[slot][j] = table[slot][j - 1];
        }
        table[slot][0] = *(u128_385EE0 *)&m->position;
        ((f32 *)table[slot])[3] = 0.05f;
    }
    scroll = D_L01_001DDD94 - 0.1f;
    D_L01_001DDD94 = scroll;
    if (scroll <= -7.0f) {
        D_L01_001DDD94 = scroll + 7.0f;
    }
    pts = b->points;
    if (pts < 2) return;
    count = 20;
    if (pts <= count - 1) {
        count = pts;
    }
    tail = 0x40;
    head = 0xFF;
    if ((u8)m->state == 1) {
        fade = (f32)b->fade / 5.0f;
        head = (s32)(head * fade);
        tail = (s32)(tail * fade);
    }
    func_L01_00386148(table[slot], 0x17, 0xE, count, (head << 24) | 0xFFFFFF, (tail << 24) | 0x707070, 0.0f, 4.0f, D_L01_001DDD94);
}
/* localdecomp:end func_L01_00385EE0 */

INCLUDE_ASM("asm/levels", func_L01_00386148);

INCLUDE_ASM("asm/levels", func_L01_00386410);

INCLUDE_ASM("asm/levels", func_L01_003868A0);

/* localdecomp:start func_L01_00386AD8 */
extern s32 func_003C4B50(s32);
extern f32 *func_00382348(s32);

s32 func_L01_00386AD8(s32 a0) {
    f32 *p;

    if (func_003C4B50(a0)) return 0;
    p = func_00382348(a0);
    if (p == 0) return 0;
    if (*p > 0.0f) return 0;
    return 1;
}
/* localdecomp:end func_L01_00386AD8 */
