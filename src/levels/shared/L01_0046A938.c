#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct {
    f32 unk00;
    f32 unk04;
    s32 unk08;
    f32 unk0C;
    f32 unk10;
    s32 unk14;
} S_467288_Sub;
typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    s32 unk04;
    u8 unk08;
    u8 unk09;
    s16 unk0A;
    f32 unk0C;
    Vec4 unk10;
    S_467288_Sub sub;
} S_467288;
typedef int s128_467510 __attribute__((mode(TI)));
typedef struct {
    s128_467510 q0;
    f32 f10;
    f32 f14;
    int f18;
} P_467510;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 pos[3];
    s32 unk0C;
    f32 off[3];
    s32 unk1C;
} S_468DC0_Sub;
typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    s32 unk04;
    u8 unk08;
    u8 unk09;
    s16 unk0A;
    f32 unk0C;
    Vec4 unk10;
    S_468DC0_Sub sub;
} S_468DC0;
typedef int u128_469BA0 __attribute__((mode(TI)));
typedef struct {
    f32 f0;
    f32 f4;
    s32 x8;
    f32 fC;
    f32 f10;
} Q_469BA0;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_469BA0 v10;
    Q_469BA0 q;
} P_469BA0;
typedef struct {
    f32 v[3];
    s32 x0C;
    f32 x10;
    f32 x14;
    s16 x18;
    s16 x1A;
    s16 x1C;
} S_469D90_Q;
typedef struct {
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    s32 x4;
    u8 x8;
    u8 x9;
    s16 xA;
    f32 xC;
    s128 x10;
    S_469D90_Q q;
} S_469D90;
typedef struct {
    f32 *p;
    f32 radius;
    f32 angle;
    f32 speed;
    f32 rise;
    u8 step;
} Orbit_0046E408;
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[3];
    f32 f12;
    f32 f16;
    f32 pad20;
    f32 f24;
    f32 pad28;
    Orbit_0046E408 o;
} Obj_0046E408;

/* localdecomp:start func_L01_0046A938 */



extern u8 *D_L01_0022114C[];
extern S_467288 *func_L01_004618E0(s32 size);
extern s32 func_00382468(s32);
extern s32 func_0013D3E0(void);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

S_467288 *func_L01_0046A938(Vec4 *a0, s32 a1, s32 a2, f32 f12, f32 f13) {
    S_467288 *p = func_L01_004618E0(45);
    if (p != 0) {
        S_467288_Sub *q;
        f32 ang;
        f32 r;
        s32 c;

        p->unk10 = *a0;
        if (a2 == -1) {
            c = ((func_00382468(6) + 20) << 24) | 0x808080;
        } else {
            c = a2;
        }
        p->unk04 = c;
        p->unk09 = 33;
        p->unk03 = 72;
        p->unk01 = 1;
        q = &p->sub;
        p->unk02 = *D_L01_0022114C[0];
        p->unk08 = func_0013D3E0();
        p->unk0A = 4;
        p->unk0C = f12 * 210000.0f;
        ang = func_00382538();
        r = func_003824E0(0.0015f, 0.0025f);
        p->sub.unk00 = func_0038D098(ang) * r;
        q->unk04 = func_0038D0B0(ang) * r;
        q->unk14 = a1;
        q->unk10 = f13;
        q->unk08 = 0;
    }
    return p;
}
/* localdecomp:end func_L01_0046A938 */

INCLUDE_ASM("asm/levels", func_L01_0046AA88);

/* localdecomp:start func_L01_0046ABC0 */
extern S_467288 *func_L01_004618E0(s32 size);


extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern u8 *D_L01_00221150[];

u8 *func_L01_0046ABC0(s128_467510 *pos, s128_467510 *dir, int life, f32 scale, f32 g) {
    u8 *m = ((u8 * (*)(s32))func_L01_004618E0)(46);
    P_467510 *p;

    if (m != 0) {
        *(s128_467510 *)(m + 0x10) = *pos;
        p = (P_467510 *)(m + 0x20);
        *(u32 *)(m + 4) = ((func_00382468(10) + 38) << 24) | 0x808080;
        m[9] = 33;
        m[3] = 72;
        m[1] = 1;
        m[2] = *D_L01_00221150[0];
        *(s16 *)(m + 10) = 5;
        *(f32 *)(m + 12) = scale * 210000.0f;
        p->q0 = *dir;
        p->f10 = func_003824E0(0.0f, 256.0f);
        m[8] = (int)p->f10;
        p->f14 = g;
        p->f18 = life;
    }
    return m;
}
/* localdecomp:end func_L01_0046ABC0 */

INCLUDE_ASM("asm/levels", func_L01_0046ACD0);

/* localdecomp:start func_L01_0046ADE0 */
extern S_467288 *func_L01_004618E0(s32 size);

extern u8 *D_L01_00221154[];
extern s32 func_00382468(s32);

u8 *func_L01_0046ADE0(u128_t *a, u128_t *b, f32 size) {
    u8 *r;

    r = ((u8 * (*)(s32))func_L01_004618E0)(47);
    if (r != 0) {
        *(u128_t *)(r + 16) = *a;
        *(u32 *)(r + 4) = ((func_00382468(8) + 40) << 24) | 0x808080;
        r[9] = 34;
        r[3] = 72;
        r[1] = 0;
        r[2] = *D_L01_00221154[0];
        *(f32 *)(r + 12) = size;
        *(u128_t *)(r + 32) = *b;
        r[8] = func_00382468(256);
    }
    return r;
}
/* localdecomp:end func_L01_0046ADE0 */

INCLUDE_ASM("asm/levels", func_L01_0046AE98);

LINKER_REMNANT("asm/levels", func_L01_0046AF30);

INCLUDE_ASM("asm/levels", func_L01_0046AF38);

LINKER_REMNANT("asm/levels", func_L01_0046AFD0);

INCLUDE_ASM("asm/levels", func_L01_0046AFD8);

INCLUDE_ASM("asm/levels", func_L01_0046B0B8);

LINKER_REMNANT("asm/levels", func_L01_0046B190);

INCLUDE_ASM("asm/levels", func_L01_0046B198);

INCLUDE_ASM("asm/levels", func_L01_0046B288);

/* localdecomp:start func_L01_0046B3A8 */


extern s32 func_0038CB00(s16 *);
extern void func_003CD250(Obj *);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L01_0046B3A8(Obj *o) {
    Sub *s;
    f32 t;

    if (func_0038CB00(&o->timer) != 0) {
        func_003CD250(o);
        return;
    }
    s = &o->sub;
    func_L01_004CAB30(o->vec, o->vec);
    t = o->timer * s->scale;
    o->result = func_0038DBD8(s->a, s->b, t);
    o->out = ((o->sub.target - s->base) * t + s->base) * 210000.0f;
}
/* localdecomp:end func_L01_0046B3A8 */

/* localdecomp:start func_L01_0046B458 */
extern S_467288 *func_L01_004618E0(s32 size);

extern u8 *D_L01_0022116C[];
extern s32 func_00382468(s32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

u8 *func_L01_0046B458(s128 *pos, s32 id, s32 color, s32 mode, s32 b, f32 *v, s32 n, f32 sx, f32 sy, f32 z) {
    u8 *o;
    u8 *p;
    f32 *q;
    u8 t;

    o = ((u8 * (*)(s32))func_L01_004618E0)(53);
    if (o != 0) {
        p = o + 32;
        *(s128 *)(o + 16) = *pos;
        F32(o, 28) = (f32)n;
        F32(o, 24) += 0.05f;
        U8(o, 3) = 72;
        S32(o, 4) = color;
        U8(o, 9) = 32;
        U8(o, 1) = 0;
        t = *D_L01_0022116C[0];
        S16(o, 10) = id;
        U8(o, 2) = t;
        F32(o, 12) = sx * 210000.0f;
        if (mode == 0) {
            U8(o, 8) = 0;
        } else if (mode == 1) {
            U8(o, 8) = 32;
        } else {
            U8(o, 8) = func_00382468(255);
        }
        F32(p, 0) = F32(o, 12);
        S16(p, 8) = id;
        F32(p, 4) = sy * 210000.0f;
        U8(p, 10) = b;
        U8(p, 11) = color >> 24;
        F32(p, 24) = z;
        q = (f32 *)(p + 12);
        q[0] = v[0];
        q[1] = v[1];
        q[2] = v[2];
    }
    return o;
}
/* localdecomp:end func_L01_0046B458 */

INCLUDE_ASM("asm/levels", func_L01_0046B5F0);

LINKER_REMNANT("asm/levels", func_L01_0046B890);

INCLUDE_ASM("asm/levels", func_L01_0046B898);

INCLUDE_ASM("asm/levels", func_L01_0046B9E8);

INCLUDE_ASM("asm/levels", func_L01_0046BAE0);

LINKER_REMNANT("asm/levels", func_L01_0046BC10);

INCLUDE_ASM("asm/levels", func_L01_0046BC18);

INCLUDE_ASM("asm/levels", func_L01_0046BCB0);

INCLUDE_ASM("asm/levels", func_L01_0046BD88);

INCLUDE_ASM("asm/levels", func_L01_0046BF78);

INCLUDE_ASM("asm/levels", func_L01_0046C2E8);

INCLUDE_ASM("asm/levels", func_L01_0046C418);

/* localdecomp:start func_L01_0046C470 */
extern S_467288 *func_L01_004618E0(s32 size);



extern Vec4 D_001A4C60;
extern u8 *D_L01_0022116C[];

S_468DC0 *func_L01_0046C470(Vec4 *a0, f32 *a1, s32 a2, s32 a3, u8 t0, s32 t1, s32 t2, s32 t3, f32 f12) {
    S_468DC0 *p = ((S_468DC0 * (*)(s32 size))func_L01_004618E0)(60);
    if (p != 0) {
        S_468DC0_Sub *q = &p->sub;
        p->unk10 = *a0;
        q->pos[0] = a1[0];
        q->pos[1] = a1[1];
        q->pos[2] = a1[2];
        q->unk0C = t3;
        q->unk1C = t1;
        if (t1 == 1) {
            Vec4 v = D_001A4C60;
            q->off[0] = p->unk10.x - v.x;
            q->off[1] = p->unk10.y - v.y;
            q->off[2] = p->unk10.z - v.z;
        }
        p->unk04 = a2;
        p->unk09 = ((t2 >> 5) << 4) + 1;
        p->unk03 = 72;
        p->unk0C = f12 * 210000.0f;
        p->unk08 = t0;
        p->unk01 = 0;
        p->unk02 = *D_L01_0022116C[0];
        p->unk0A = a3;
    }
    return p;
}
/* localdecomp:end func_L01_0046C470 */

INCLUDE_ASM("asm/levels", func_L01_0046C5C8);

LINKER_REMNANT("asm/levels", func_L01_0046C788);

INCLUDE_ASM("asm/levels", func_L01_0046C790);

INCLUDE_ASM("asm/levels", func_L01_0046CA28);

INCLUDE_ASM("asm/levels", func_L01_0046CB28);

LINKER_REMNANT("asm/levels", func_L01_0046CC18);

/* localdecomp:start func_L01_0046CC20 */
extern void func_003CD250(Obj *);
extern s32 func_0038CB00(s16 *);
void func_L01_0046CC20(u8 *a0) {
    if (((s32 (*)(u8 *))func_0038CB00)(a0 + 10)) {
        ((void (*)(u8 *))func_003CD250)(a0);
    }
}
/* localdecomp:end func_L01_0046CC20 */

INCLUDE_ASM("asm/levels", func_L01_0046CC58);

INCLUDE_ASM("asm/levels", func_L01_0046CDA8);

INCLUDE_ASM("asm/levels", func_L01_0046CFD8);

/* localdecomp:start func_L01_0046D250 */
extern S_467288 *func_L01_004618E0(s32 size);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_0013D3E0(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *D_L01_002211A0[];

P_469BA0 *func_L01_0046D250(u128_469BA0 *a, s32 color, f32 scale, f32 z) {
    P_469BA0 *p = ((void * (*)(s32))func_L01_004618E0)(66);
    Q_469BA0 *q;
    f32 ang;
    f32 r;
    s32 c;

    if (p != 0) {
        p->v10 = *a;
        if (color == -1) {
            c = ((func_00382468(6) + 20) << 24) | 0x808080;
        } else {
            c = color;
        }
        p->x4 = c;
        p->b9 = 33;
        p->b3 = 72;
        p->b1 = 1;
        if (func_00382468(256) & 1) {
            p->b2 = D_L01_002211A0[0][0];
        } else {
            p->b2 = D_L01_002211A0[0][1];
        }
        p->b8 = func_0013D3E0();
        q = &p->q;
        p->hA = 4;
        p->fC = scale * 210000.0f;
        ang = func_00382538();
        r = func_003824E0(0.0015f, 0.0025f);
        q->f0 = func_0038D098(ang) * r;
        q->f4 = func_0038D0B0(ang) * r;
        q->x8 = 0;
        q->f10 = z;
    }
    return p;
}
/* localdecomp:end func_L01_0046D250 */

INCLUDE_ASM("asm/levels", func_L01_0046D3B0);

/* localdecomp:start func_L01_0046D440 */
extern S_467288 *func_L01_004618E0(s32 size);
extern u8 *D_L01_002211A4[];
extern s32 func_00382468(s32);
S_469D90 *func_L01_0046D440(s32 a0, void *pos, s32 life, s32 mode, s32 color, f32 *vel, f32 f12, f32 f13) {
    S_469D90 *p;
    S_469D90_Q *q;
    p = ((S_469D90 * (*)(s32))func_L01_004618E0)(67);
    if (p) {
        p->x10 = *(s128 *)pos;
        q = &p->q;
        q->x0C = a0;
        q->x10 = f12;
        q->x14 = f13;
        p->x1 = 0;
        p->x4 = color | 0x409B9B00;
        p->x9 = 68;
        p->x3 = 72;
        p->xC = 52500.0f;
        p->x8 = func_00382468(255);
        q->x1C = mode;
        q->x18 = 0;
        if (mode == 0) {
            p->x2 = D_L01_002211A4[0][0];
        } else {
            p->x2 = D_L01_002211A4[0][1];
        }
        if (mode == 0) {
            q->x1A = 127.0f / (f32)life;
        }
        if (vel) {
            q->v[0] = vel[0];
            q->v[1] = vel[1];
            q->v[2] = vel[2];
        }
        p->xA = life;
    }
    return p;
}
/* localdecomp:end func_L01_0046D440 */

INCLUDE_ASM("asm/levels", func_L01_0046D5A8);

LINKER_REMNANT("asm/levels", func_L01_0046D848);

INCLUDE_ASM("asm/levels", func_L01_0046D850);

LINKER_REMNANT("asm/levels", func_L01_0046D978);

INCLUDE_ASM("asm/levels", func_L01_0046D980);

/* localdecomp:start func_L01_0046DBE8 */
extern void func_003CD250(Obj *);
void func_L01_0046DBE8(u8 *a0) {
    if (--*(s16 *)(a0 + 10) == 0) { *(s16 *)(a0 + 10) = 2; *(s32 *)(a0 + 4) += 0xFF000000; }
    if ((*(u32 *)(a0 + 4) & 0xFF000000) == 0) {
        ((void (*)(u8 *a0))func_003CD250)(a0);
    }
}
/* localdecomp:end func_L01_0046DBE8 */

LINKER_REMNANT("asm/levels", func_L01_0046DC48);

INCLUDE_ASM("asm/levels", func_L01_0046DC50);

LINKER_REMNANT("asm/levels", func_L01_0046DF88);

INCLUDE_ASM("asm/levels", func_L01_0046DF90);

INCLUDE_ASM("asm/levels", func_L01_0046DFD0);

INCLUDE_ASM("asm/levels", func_L01_0046E078);

INCLUDE_ASM("asm/levels", func_L01_0046E1B8);

LINKER_REMNANT("asm/levels", func_L01_0046E378);

INCLUDE_ASM("asm/levels", func_L01_0046E380);

INCLUDE_ASM("asm/levels", func_L01_0046E4A0);

LINKER_REMNANT("asm/levels", func_L01_0046E4E8);

INCLUDE_ASM("asm/levels", func_L01_0046E4F0);

/* localdecomp:start func_L01_0046E5A8 */
extern S_467288 *func_L01_004618E0(s32 size);

extern u8 *D_L01_002211D0[];
extern s32 func_00382468(s32);
extern u8 *func_00382348(s32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

u8 *func_L01_0046E5A8(s128 *a0, s32 a1, s32 a2, s32 a3, s32 t0, f32 *t1, s32 t2, f32 f12, f32 f13) {
    u8 *p = ((u8 * (*)(s32))func_L01_004618E0)(78);
    u8 *q;
    u8 *r;
    f32 *v;
    if (p != 0) {
        *(s128 *)(p + 16) = *a0;
        U8(p, 3) = 72;
        U8(p, 9) = 36;
        q = p + 32;
        S32(p, 4) = a2;
        U8(p, 1) = 0;
        U8(p, 2) = *D_L01_002211D0[0];
        S16(p, 10) = a1;
        F32(p, 12) = f12 * 210000.0f;
        if (a3 == 0) {
            U8(p, 8) = 0;
        } else if (a3 == 1) {
            U8(p, 8) = 32;
        } else {
            U8(p, 8) = func_00382468(255);
        }
        F32(q, 0) = F32(p, 12);
        F32(q, 4) = f13 * 210000.0f;
        S16(q, 8) = a1;
        U8(q, 10) = t0;
        U8(q, 11) = a2 >> 24;
        S32(q, 24) = t2;
        S32(q, 28) = 0;
        if (t2 != 0) {
            r = func_00382348(t2);
            if (r != 0) {
                F32(q, 28) = F32(r, 16);
            }
        }
        v = (f32 *)(q + 12);
        v[0] = t1[0];
        v[1] = t1[1];
        v[2] = t1[2];
    }
    return p;
}
/* localdecomp:end func_L01_0046E5A8 */

INCLUDE_ASM("asm/levels", func_L01_0046E720);

INCLUDE_ASM("asm/levels", func_L01_0046EA10);

INCLUDE_ASM("asm/levels", func_L01_0046EB58);

INCLUDE_ASM("asm/levels", func_L01_0046ECB8);

INCLUDE_ASM("asm/levels", func_L01_0046EEA0);

INCLUDE_ASM("asm/levels", func_L01_0046F148);

INCLUDE_ASM("asm/levels", func_L01_0046F2B8);

LINKER_REMNANT("asm/levels", func_L01_0046F930);

INCLUDE_ASM("asm/levels", func_L01_0046F938);

LINKER_REMNANT("asm/levels", func_L01_0046FA80);

INCLUDE_ASM("asm/levels", func_L01_0046FA88);

INCLUDE_ASM("asm/levels", func_L01_0046FB40);

INCLUDE_ASM("asm/levels", func_L01_0046FD18);

LINKER_REMNANT("asm/levels", func_L01_0046FE58);

INCLUDE_ASM("asm/levels", func_L01_0046FE60);

LINKER_REMNANT("asm/levels", func_L01_0046FFF8);

INCLUDE_ASM("asm/levels", func_L01_00470000);

LINKER_REMNANT("asm/levels", func_L01_00470148);

INCLUDE_ASM("asm/levels", func_L01_00470150);

INCLUDE_ASM("asm/levels", func_L01_004702E0);

INCLUDE_ASM("asm/levels", func_L01_00470668);

INCLUDE_ASM("asm/levels", func_L01_00470770);

INCLUDE_ASM("asm/levels", func_L01_004708C8);

INCLUDE_ASM("asm/levels", func_L01_00470A28);

INCLUDE_ASM("asm/levels", func_L01_00470C78);

INCLUDE_ASM("asm/levels", func_L01_00470E48);

LINKER_REMNANT("asm/levels", func_L01_004710E8);

INCLUDE_ASM("asm/levels", func_L01_004710F8);

INCLUDE_ASM("asm/levels", func_L01_004711C0);

LINKER_REMNANT("asm/levels", func_L01_004712D8);

INCLUDE_ASM("asm/levels", func_L01_004712E0);

INCLUDE_ASM("asm/levels", func_L01_004713C8);

INCLUDE_ASM("asm/levels", func_L01_00471530);

LINKER_REMNANT("asm/levels", func_L01_00471668);

INCLUDE_ASM("asm/levels", func_L01_00471670);

LINKER_REMNANT("asm/levels", func_L01_00471740);

INCLUDE_ASM("asm/levels", func_L01_00471748);

INCLUDE_ASM("asm/levels", func_L01_00471A30);

/* localdecomp:start func_L01_00471B20 */
extern void func_003CD250(Obj *);


extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DBA0(f32, f32);

void func_L01_00471B20(Obj_0046E408 *m) {
    Orbit_0046E408 *o = &m->o;

    m->b8 += o->step;
    o->angle = func_0038DAB8(o->angle, o->speed);
    m->f12 += o->rise;
    m->f16 = m->o.p[0] + o->radius * func_0038D098(o->angle);
    m->f24 = m->o.p[2] + o->radius * func_0038D0B0(o->angle);
    if (func_0038DBA0(o->angle, m->o.p[4]) < __builtin_fabsf(o->speed + o->speed)) {
        ((void (*)(Obj_0046E408 *))func_003CD250)(m);
    }
}
/* localdecomp:end func_L01_00471B20 */

INCLUDE_ASM("asm/levels", func_L01_00471BF0);

INCLUDE_ASM("asm/levels", func_L01_00471D88);

LINKER_REMNANT("asm/levels", func_L01_00471F70);

/* localdecomp:start func_L01_00471F78 */
extern void func_003CD250(Obj *);
extern s32 func_0038CB00(s16 *);
void func_L01_00471F78(u8 *a0) {
    if (((s32 (*)(u8 *))func_0038CB00)(a0 + 10)) {
        ((void (*)(u8 *))func_003CD250)(a0);
    }
}
/* localdecomp:end func_L01_00471F78 */

INCLUDE_ASM("asm/levels", func_L01_00471FB0);

LINKER_REMNANT("asm/levels", func_L01_00472150);

INCLUDE_ASM("asm/levels", func_L01_00472158);

INCLUDE_ASM("asm/levels", func_L01_00472238);

INCLUDE_ASM("asm/levels", func_L01_004723B0);

INCLUDE_ASM("asm/levels", func_L01_00472560);

INCLUDE_ASM("asm/levels", func_L01_00472758);
