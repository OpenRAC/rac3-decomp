#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0044E130);

LINKER_REMNANT("asm/levels", func_L01_0044E1A8);

INCLUDE_ASM("asm/levels", func_L01_0044E1B8);

LINKER_REMNANT("asm/levels", func_L01_0044E290);

/* localdecomp:start func_L01_0044E298 */
extern void func_0038D328(f32 *a0, f32 *a1);
extern void func_0038D640(f32 *a0, f32 *a1, f32 *a2);
extern void func_003C48A8(f32 *a0, f32 *a1);

void func_L01_0044E298(u8 *moby, f32 x, f32 y, f32 z) {
    f32 v[4];
    f32 m1[16];
    f32 m2[16];

    v[0] = x;
    v[1] = y;
    v[2] = z;
    func_0038D328(m1, v);
    func_0038D328(m2, (f32 *)(moby + 240));
    func_0038D640(m2, m2, m1);
    func_003C48A8(m2, (f32 *)(moby + 240));
}
/* localdecomp:end func_L01_0044E298 */

INCLUDE_ASM("asm/levels", func_L01_0044E318);

/* localdecomp:start func_L01_0044E340 */
typedef struct {
    u8 p0[0x23];
    u8 b35;
    u8 p24[0xC];
    u8 b48;
    u8 b49;
    u16 h50;
    u16 h52;
    u8 p36[2];
    unsigned long d56;
    u8 p40[0x38];
    s32 w120;
    u16 h124;
    u8 p7E[0x1A];
    s32 w152;
    u8 p9C[0xE];
    s16 h170;
} M_44B0B8;

typedef struct {
    u8 p0[0x2C];
    f32 f44;
} F_44B0B8;

typedef struct {
    u8 p0[0x100];
    s32 a256[4];
    s32 a272[4];
    M_44B0B8 *a288[4];
    f32 a304[4];
    u8 p140[4];
    M_44B0B8 *parent;
    s32 count;
} O_44B0B8;

extern M_44B0B8 *func_003C24B0(s32 oClass, s32 flags);

void func_L01_0044E340(O_44B0B8 *o, s32 a, s32 b, f32 f) {
    M_44B0B8 *m;

    if (o->count == 4 || b >= 9) {
        return;
    }
    m = func_003C24B0(o->parent->h170, 128);
    if (m == 0) {
        return;
    }
    m->h124 = o->parent->h124;
    m->h50 = o->parent->h50;
    m->d56 = o->parent->d56;
    ((F_44B0B8 *)m)->f44 = ((F_44B0B8 *)o->parent)->f44;
    m->w120 = o->parent->w120;
    m->b49 = 1;
    m->h52 = 0x80A;
    m->b48 = 0;
    m->h52 = (o->parent->h52 & 0x8000) | 0x80A;
    m->w152 = 0;
    m->b35 = a;
    o->a272[o->count] = b;
    o->a256[o->count] = a;
    o->a304[o->count] = f;
    o->a288[o->count] = m;
    o->count++;
}
/* localdecomp:end func_L01_0044E340 */

INCLUDE_ASM("asm/levels", func_L01_0044E468);

/* localdecomp:start func_L01_0044E740 */
typedef struct {
    u8 pad[288];
    void *items[10];
    s32 count;
    s32 active;
} S_44B4B8;

extern void func_003C2880(void *);

void func_L01_0044E740(S_44B4B8 *p) {
    s32 i;

    if (p->active != 0) {
        for (i = 0; i < p->count; i++) {
            if (p->items[i] != 0) {
                func_003C2880(p->items[i]);
                p->items[i] = 0;
            }
        }
        p->active = 0;
    }
}
/* localdecomp:end func_L01_0044E740 */

LINKER_REMNANT("asm/levels", func_L01_0044E7C0);

/* localdecomp:start func_L01_0044E7D8 */
extern void func_003C6FB0(s32, u32 *, u32 *, u32 *);

u32 func_L01_0044E7D8(s32 a0) {
    u32 r, g, b;
    func_003C6FB0(a0, &r, &g, &b);
    return 0x80000000 | (b << 16) | (g << 8) | r;
}
/* localdecomp:end func_L01_0044E7D8 */

/* localdecomp:start func_L01_0044E820 */
extern void func_L01_0043B9E8(s32, u8, u8, u8);

void func_L01_0044E820(s32 a0, s32 a1) {
    u8 c = a1 >> 16;
    u8 b = a1 >> 8;
    func_L01_0043B9E8(a0, a1, b, c);
}
/* localdecomp:end func_L01_0044E820 */

INCLUDE_ASM("asm/levels", func_L01_0044E850);

INCLUDE_ASM("asm/levels", func_L01_0044EA78);

INCLUDE_ASM("asm/levels", func_L01_0044EAE0);

LINKER_REMNANT("asm/levels", func_L01_0044EB98);

/* localdecomp:start func_L01_0044EBA0 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038DAB8(f32, f32);

void func_L01_0044EBA0(u8 *obj, f32 *a, f32 *b, f32 scale, f32 da, f32 db) {
    *(f32 *)(obj + 240) = scale * func_0038D0B0(*a) * func_0038D0B0(*b);
    *(f32 *)(obj + 244) = scale * func_0038D0B0(*a) * func_0038D098(*b);
    *a = func_0038DAB8(*a, da);
    *b = func_0038DAB8(*b, db);
}
/* localdecomp:end func_L01_0044EBA0 */

LINKER_REMNANT("asm/levels", func_L01_0044EC68);

/* localdecomp:start func_L01_0044EC78 */
typedef int s128_44B9F8 __attribute__((mode(TI)));

extern f32 func_0038CF00(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D590(void *, void *);

int func_L01_0044EC78(int unused, u8 *list, int n, s128_44B9F8 *a, s128_44B9F8 *b, s128_44B9F8 *outPos, void *outMat) {
    s128_44B9F8 tmp[2];
    s128_44B9F8 mat[4];
    f32 best = 9999.0f;
    int bestIdx = 0;
    int i;
    u8 *p;
    s128_44B9F8 *pt = tmp;
    s128_44B9F8 *pm = mat;

    tmp[0] = *a;
    tmp[1] = *b;
    for (i = 0; i < n; i++) {
        f32 d = func_0038CF00(pt, list + i * 64 + 48);
        if (d < best) {
            best = d;
            bestIdx = i;
        }
    }
    p = list + bestIdx * 64;
    func_0038D5B0(pm, p);
    func_0038D590(outMat, pm);
    *outPos = *(s128_44B9F8 *)(p + 48);
    return bestIdx;
}
/* localdecomp:end func_L01_0044EC78 */

INCLUDE_ASM("asm/levels", func_L01_0044ED88);

INCLUDE_ASM("asm/levels", func_L01_0044F280);

/* localdecomp:start func_L01_0044F368 */
typedef int s128_44C0E8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x40]; void *p40; u8 pad44[0x4C - 0x44]; u8 b4C; } M_44C0E8;
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D308(void *, void *);
void func_L01_0044F368(M_44C0E8 *m, void *a, void *out) {
    s128_44C0E8 t[3];
    s128_44C0E8 u[3];
    if (m->p40 == 0) {
        func_0038D5F0(out, a, m);
        return;
    }
    func_0038D308(t, m->p40);
    switch (m->b4C & 0xC0) {
    case 0x40:
        func_0038D5F0(u, t, m);
        func_0038D5F0(out, a, u);
        break;
    case 0x80:
        func_0038D5F0(u, m, t);
        func_0038D5F0(out, a, u);
        break;
    default:
        func_0038D5F0(u, a, m);
        func_0038D5F0(out, t, u);
        break;
    }
}
/* localdecomp:end func_L01_0044F368 */

INCLUDE_ASM("asm/levels", func_L01_0044F450);

INCLUDE_ASM("asm/levels", func_L01_0044F888);

/* localdecomp:start func_L01_0044F8D8 */
extern void func_003C2880(void *);
typedef struct {
    u8 pad0[0x48];
    s16 h48;
    u8 b4A;
    u8 pad4B;
    u8 b4C;
    u8 pad4D[3];
} S_44C658;

extern u8 *D_L01_001E001C[];
extern u8 *D_L01_001E0ED4[];
extern u8 *D_L01_001E0DC8[];
extern void func_L01_004AA7E8(u8 *, s32);

void func_L01_0044F8D8(S_44C658 *p, s32 a1) {
    u8 *o;
    do {
        switch (p->b4C & 3) {
        case 0:
            o = D_L01_001E001C[0] + (p->h48 << 8);
            if (a1 != 0) {
                ((void (*)(u8 *))func_003C2880)(o);
            } else {
                *(s32 *)(o + 0x98) = 0;
                *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
                func_L01_004AA7E8(o, 1);
                *(u16 *)(o + 0x34) |= 2;
            }
            break;
        case 1:
            (D_L01_001E0ED4[0] + (p->h48 << 5))[0x1C] = 0;
            break;
        case 2:
            (D_L01_001E0DC8[0] + (p->h48 << 5))[0x16] |= 1;
            break;
        }
    } while ((p++)->b4A != 1);
}
/* localdecomp:end func_L01_0044F8D8 */

/* localdecomp:start func_L01_0044F9F8 */
extern u8 *D_L01_001E0DC8[];
extern u8 *D_L01_001E0ED4[];
extern u8 *D_L01_001E001C[];
typedef struct {
    u8 pad0[72];
    s16 index;
    u8 last;
    u8 pad75;
    u8 type;
    u8 pad77[3];
} E_0044C778;

extern s32 func_L01_0044C108(void *a);

void func_L01_0044F9F8(E_0044C778 *e, s32 val, s32 force) {
    u8 *p;
    u8 *q;
    s32 f;

    do {
        switch (e->type & 3) {
        case 0:
            p = (*(u8 * *)&D_L01_001E001C) + e->index * 256;
            f = *(u16 *)(p + 52) & 0xFFBE;
            *(u16 *)(p + 52) = f;
            q = *(u8 **)(p + 36);
            f |= *(u16 *)(q + 68) & 0x1000;
            *(u16 *)(p + 52) = f;
            f &= 0xFFFD;
            *(s32 *)(p + 152) = *(s32 *)(q + 16);
            *(u16 *)(p + 52) = f;
            *(u16 *)(p + 50) = val;
            if (force != 0 || func_L01_0044C108(p + 16) != 0) {
                *(u16 *)(p + 52) &= 0xFF7F;
            } else {
                *(u16 *)(p + 52) |= 0x80;
            }
            break;
        case 1:
            p = (*(u8 * *)&D_L01_001E0ED4) + e->index * 32;
            p[28] = val;
            if (force != 0 || func_L01_0044C108(p) != 0) {
                p[30] &= 0xFB;
            } else {
                p[30] |= 4;
            }
            break;
        case 2:
            p = (*(u8 * *)&D_L01_001E0DC8) + e->index * 32;
            if (force != 0 || func_L01_0044C108(p) != 0) {
                p[22] &= 0xFE;
            } else {
                p[22] |= 1;
            }
            break;
        }
    } while ((e++)->last != 1);
}
/* localdecomp:end func_L01_0044F9F8 */

INCLUDE_ASM("asm/levels", func_L01_0044FB80);

/* localdecomp:start func_L01_0044FBC8 */
extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
extern void func_003860A8(f32 *, void *);

void func_L01_0044FBC8(void *a0, s32 *x, s32 *y) {
    f32 v[4];

    func_003860A8(v, a0);
    *x = (v[0] - (f32)D_001D4BD0[0]) * 0.0625f;
    *y = (v[1] - (f32)D_001D4BD4[0]) * 0.0625f;
}
/* localdecomp:end func_L01_0044FBC8 */

INCLUDE_ASM("asm/levels", func_L01_0044FC48);

LINKER_REMNANT("asm/levels", func_L01_0044FD80);

/* localdecomp:start func_L01_0044FD88 */
typedef int s128_44CB08 __attribute__((mode(TI)));

extern void func_003C2EC0(u8 *, int, s128_44CB08 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C6FE0(u8 *);
extern void func_003C7C38(u8 *);
extern void func_0038D590(void *, void *);
extern void func_L01_00448E10(void *);
extern void func_003C7DD8(u8 *);

void func_L01_0044FD88(u8 *src, u8 *m, int arg, int flags) {
    s128_44CB08 mat[4];

    func_003C2EC0(src, arg, mat);
    *(s128_44CB08 *)(m + 0x10) = mat[3];
    if (flags & 1) {
        func_0038CE20(&mat[0], &mat[0], -1.0f);
    }
    if (flags & 2) {
        func_0038CE20(&mat[1], &mat[1], -1.0f);
    }
    if (flags & 4) {
        func_0038CE20(&mat[2], &mat[2], -1.0f);
    }
    func_003C6FE0(m);
    if (!(*(u16 *)(m + 0x34) & 4)) {
        func_003C7C38(m);
    }
    func_0038D590(m + 0xC0, mat);
    func_L01_00448E10(m + 0xC0);
    func_003C7DD8(m);
    if (*(u16 *)(src + 0x34) & 1) {
        *(u16 *)(m + 0x34) |= 0x41;
    } else {
        *(u16 *)(m + 0x34) &= ~0x41;
    }
    *(u16 *)(m + 0x34) |= 6;
}
/* localdecomp:end func_L01_0044FD88 */

/* localdecomp:start func_L01_0044FE98 */
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_003C4B50(f32 *);

f32 func_L01_0044FE98(f32 *a0, f32 *a1, s32 *a2, f32 f12, f32 f13, f32 f14, f32 f15) {
    f32 dist;
    f32 yaw;
    f32 pitch;
    f32 r;
    *a2 = 0;
    dist = ((f32 (*)(f32 *, f32 *))func_0038CF00)(a0, a1 + 4);
    if (f13 < dist) {
        *a2 = 1;
    }
    yaw = func_0038DBA0(func_0038D160(a1[4] - a0[0], a1[5] - a0[1]), f12);
    pitch = func_0038DBA0(func_0038D160(func_0038CF38(a0, a1 + 4), a1[6] - a0[2]), 0.0f);
    if (0.0f < f14 && f14 < yaw) {
        *a2 = 1;
    }
    if (0.0f < f15 && f15 < pitch) {
        *a2 = 1;
    }
    r = dist + yaw * dist;
    if (func_003C4B50(a1)) {
        r += 8.0f;
    }
    return r;
}
/* localdecomp:end func_L01_0044FE98 */

INCLUDE_ASM("asm/levels", func_L01_00450010);

INCLUDE_ASM("asm/levels", func_L01_004501E8);

INCLUDE_ASM("asm/levels", func_L01_00450BB0);

INCLUDE_ASM("asm/levels", func_L01_00450D20);

INCLUDE_ASM("asm/levels", func_L01_00450DE8);

LINKER_REMNANT("asm/levels", func_L01_00450E40);

INCLUDE_ASM("asm/levels", func_L01_00450E48);
