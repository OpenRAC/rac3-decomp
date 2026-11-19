#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_003002A8 */

typedef struct {
    s128 v;
    f32 f10;
    f32 f14;
    u8 pad18[4];
    s32 f1C;
    f32 f20;
    s32 f24;
    f32 f28;
    f32 f2C;
} State_L01_00300250;

typedef struct {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    f32 z;
    u8 pad1C[4];
    u8 b20;
    u8 pad21[0x0B];
    f32 f2C;
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[0x68 - 0x36];
    State_L01_00300250 *f68;
    u8 pad6C[0xBC - 0x6C];
    u8 bBC;
    u8 padBD[0xD0 - 0xBD];
    f32 vD0[4];
    u8 padE0[0xF0 - 0xE0];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} Obj_L01_00300250;

extern s32 D_L01_001DC458;
extern f32 D_L01_001DC454;
__asm__(".extern D_L01_001DC458, 4");
__asm__(".extern D_L01_001DC454, 4");

extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);

Obj_L01_00300250 *func_L01_003002A8(s32 unused, s128 *pos, f32 *vel) {
    Obj_L01_00300250 *obj;
    State_L01_00300250 *st;

    obj = (Obj_L01_00300250 *)func_003C24B0(0x1AC, 0x80);
    if (obj != 0) {
        obj->b30 = 0x40;
        obj->h32 = 0x20;
        obj->b31 = 1;
        obj->h34 |= 0x1000;
        obj->b20 = 0;
        obj->bBC = 0;
        *(s128 *)&obj->x = *pos;
        st = obj->f68;
        obj->z += func_003824E0(0.2f, 0.7f);
        obj->x += vel[0] * 3.0f;
        obj->y += vel[1] * 3.0f;
        *(s128 *)st = *(s128 *)vel;
        obj->fF4 = func_L01_00443A18(0.17453292f, 0.523598790f);
        obj->fF0 = func_003824E0(0.17453292f, 0.785398185f);
        st->f2C = func_003824E0(200.0f, 370.0f) * 0.0174532924f * 0.020000001f;
        st->f24 = -1;
        if (func_0013D3E0() & 1) {
            st->f24 = 1;
            obj->fF4 = -obj->fF4;
        }
        obj->fF8 = func_00382538();
        st->f28 = -(func_003824E0(200.0f, 550.0f) * 0.0174532924f * 0.020000001f);
        st->f10 = func_00382538();
        st->f14 = func_00382538();
        st->f1C = func_00382498((s32)((f32)D_L01_001DC458 * 0.7f), (s32)((f32)D_L01_001DC458 * 1.2f));
        st->f1C = (st->f1C * 5 + 2) / 6;
        obj->f2C = obj->f2C * D_L01_001DC454;
        st->f20 = func_003824E0(-1.2f, -0.4f) * 0.020000001f;
        func_0038CE20(obj->vD0, obj->vD0, 0.5f);
        func_003C7C38((u8 *)obj);
        func_L01_0043B9E8((u8 *)obj, 0x90, 0x90, 0);
    }
    return obj;
}
/* localdecomp:end func_L01_003002A8 */

/* localdecomp:start func_L01_00300550 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00300550;
typedef struct {
    f32 x0;
    f32 x4;
    f32 f8;
    u8 padC[0x1C - 0xC];
    s32 w1C;
    f32 f20;
    s32 w24;
    f32 f28;
    f32 f2C;
} G_00300550;
typedef struct {
    u8 pad0[0x10];
    V_00300550 pos;
    u8 pad20[3];
    u8 b23;
    u8 pad24[0x31 - 0x24];
    u8 b31;
    u8 pad32[0x68 - 0x32];
    G_00300550 *x68;
    u8 pad6C[0xF0 - 0x6C];
    f32 fF0;
    u8 padF4[4];
    f32 fF8;
} O_00300550;

extern f32 D_L01_001DC45C;
__asm__(".extern D_L01_001DC45C, 4");
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0040E020(void *);
extern void func_003C2880(u8 *);

void func_L01_00300550(O_00300550 *o) {
    G_00300550 *g = o->x68;
    f32 t;

    vec_add_ab(&o->pos, &o->pos, g);
    g->f8 = g->f8 - 0.004f;
    g->x0 = g->x0 * D_L01_001DC45C;
    g->x4 = g->x4 * D_L01_001DC45C;
    if (g->f8 < g->f20) {
        g->f8 = g->f20;
    }
    o->fF8 = func_0038DAB8(o->fF8, g->f28);
    t = func_0038DAB8(o->fF0, g->f2C * (f32)g->w24);
    o->fF0 = t;
    if (0.7853982f < fabs_asm(t)) {
        g->w24 = -g->w24;
    }
    if (func_0038CAD0(&g->w1C) != 0 || o->b31 == 0) {
        func_003C2880((u8 *)o);
        return;
    }
    if (g->w1C < 25 && func_L01_0040E020(&o->b23) != 0) {
        func_003C2880((u8 *)o);
    }
}
/* localdecomp:end func_L01_00300550 */

INCLUDE_ASM("asm/levels", func_L01_00300678);

/* localdecomp:start func_L01_003006C0 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(u8 *);
extern void func_003C7C38(u8 *);
u8 *func_L01_003006C0(u8 *src, u128_t *pos, s32 arg, u128_t *alt) {
    u8 *m;
    u8 *pv;
    m = func_003C24B0(639, 128);
    if (m != 0) {
        m[48] = 255;
        m[49] = 1;
        *(u16 *)(m + 52) |= 1;
        m[32] = 0;
        m[188] = 0;
        pv = *(u8 **)(m + 104);
        *(u128_t *)(m + 16) = *pos;
        if (alt != 0)
            *(u128_t *)pv = *alt;
        else
            *(u128_t *)pv = *(u128_t *)src;
        *(s32 *)(pv + 32) = arg;
        *(s16 *)(m + 50) = src[60];
        pv[36] = src[16];
        pv[37] = src[17];
        pv[38] = src[18];
        pv[39] = src[19];
        pv[40] = src[20];
        pv[41] = src[21];
        pv[104] = src[61];
        *(u16 *)(pv + 108) = *(u16 *)(src + 64);
        pv[42] = src[22];
        pv[43] = src[23];
        pv[44] = src[24];
        pv[45] = src[25];
        pv[46] = src[26];
        pv[105] = src[62];
        *(u16 *)(pv + 110) = *(u16 *)(src + 66);
        pv[47] = src[27];
        pv[48] = src[28];
        pv[49] = src[29];
        pv[50] = src[30];
        pv[51] = src[31];
        pv[106] = src[63];
        *(u16 *)(pv + 112) = *(u16 *)(src + 68);
        *(f32 *)(pv + 52) = *(f32 *)(src + 32);
        *(f32 *)(pv + 56) = *(f32 *)(src + 36);
        *(f32 *)(pv + 60) = *(f32 *)(src + 40);
        *(f32 *)(pv + 64) = *(f32 *)(src + 44);
        *(f32 *)(pv + 68) = *(f32 *)(src + 48);
        pv[107] = src[72];
        *(u16 *)(pv + 114) = *(u16 *)(src + 70);
        *(s32 *)(pv + 72) = *(s32 *)(src + 52);
        *(s32 *)(pv + 76) = *(s32 *)(src + 56);
        pv[28] = src[73];
        *(s32 *)(pv + 100) = -1;
        func_003C7C38(m);
        func_L01_0044A7D0(m);
    }
    return m;
}
/* localdecomp:end func_L01_003006C0 */

INCLUDE_ASM("asm/levels", func_L01_00300890);

/* localdecomp:start func_L01_00301558 */

extern s32 D_L01_001D673C_00301558;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern f32 func_00382538(void);
extern void func_003C5180(u8 *, Vec4 *, s32);
extern void func_L01_004515D8(u8 *, Vec4 *, Vec4 *);
extern void func_003C48A8(u8 *, u8 *);
extern void func_003C7C38(u8 *);

u8 *func_L01_00301558(Vec4 *pos, Vec4 *dir, u8 type, f32 scale, f32 f13) {
    Vec4 v;
    Vec4 mt[3];
    u8 *m;
    u8 *pv;

    m = func_003C24B0(775, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        func_L01_0044A7D0(m);
        func_L01_0043B9E8(m, 40, 40, 70);
        m[48] = 255;
        *(s16 *)(m + 50) = 64;
        *(f32 *)(m + 44) *= scale;
        *(f32 *)pv = f13;
        pv[4] = type;
        *(u128_t *)(m + 16) = pos->q;
        *(f32 *)(m + 248) = func_00382538();
        if (dir->f[0] != 0.0f && dir->f[1] != 0.0f && dir->f[2] != 0.0f) {
            *(u128_t *)(m + 240) = dir->q;
        } else if (D_L01_001D673C_00301558 != 0) {
            func_003C5180(m + 16, &v, 0);
            func_L01_004515D8(m + 192, &v, mt);
            func_003C48A8(m + 192, m + 240);
        }
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L01_00301558 */

/* localdecomp:start func_L01_003016B0 */
extern u8 *func_L01_00301558(Vec4 *pos, Vec4 *dir, u8 type, f32 scale, f32 f13);
extern u8 D_L01_001D66B0[];


void func_L01_003016B0(s32 a0, u8 a1) {
    ((void (*)(s32 a0, u8 *a1, u8 a2))func_L01_00301558)(a0, D_L01_001D66B0, a1);
}
/* localdecomp:end func_L01_003016B0 */

/* localdecomp:start func_L01_003016D8 */
extern s32 D_L01_001D673C[];
extern void func_003C2880(u8 *);

void func_L01_003016D8(u8 *obj) {
    s32 d;
    u8 *a;
    u8 *p;
    Vec4 v;
    Vec4 mt[3];
    f32 f;
    s32 c;

    d = D_L01_001D673C[0];
    a = *(u8 **)(obj + 0x68);
    f = *(f32 *)(obj + 0x2C) * *(f32 *)a;
    *(f32 *)(obj + 0x2C) = f;
    if (d != 0) {
        p = obj + 0xC0;
        func_003C5180(obj + 0x10, &v, 0);
        func_L01_004515D8(p, &v, &mt[0]);
        func_003C48A8(p, obj + 0xF0);
    }
    c = obj[0x23] - a[4];
    obj[0x23] = c;
    if (!(a[4] < (u8)c)) {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003016D8 */

/* localdecomp:start func_L01_00301788 */
s32 func_L01_00301788(u8 *obj) {
    return obj[32] == 1;
}
/* localdecomp:end func_L01_00301788 */

INCLUDE_ASM("asm/levels", func_L01_00301798);

LINKER_REMNANT("asm/levels", func_L01_003018B0);

INCLUDE_ASM("asm/levels", func_L01_003018B8);
