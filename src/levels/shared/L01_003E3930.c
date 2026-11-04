#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[1120];
} Ent1120;
typedef int q128 __attribute__((mode(TI)));
typedef struct { u8 pad[0x120]; f32 x120[3]; } V_3E3730;
typedef struct { u8 pad[0x70]; V_3E3730 *x70; } O_3E3730;
typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6CA8;
typedef struct {
    u8 pad[28];
    u8 *p1C;
} M_3E6CA8;
typedef struct {
    u8 pad[80];
    u8 *p;
    u8 pad2[1120 - 84];
} S_003E7430;
typedef struct {
    u8 pad[588];
    s32 v;
    u8 pad2[1120 - 592];
} Unk003E8810;
typedef int s128_003E8C50 __attribute__((mode(TI)));
typedef struct {
    u8 pad[512];
    u8 data[48];
    s128_003E8C50 q;
    u8 pad2[1120 - 576];
} Slot_003E8C50;
typedef struct {
    u8 pad[56];
    u8 a38[4];
    u8 a3C[4];
} Base_003E8C50;
typedef struct {
    u8 pad[28];
    Base_003E8C50 *p;
} Ent_003E8C50;
typedef struct {
    u8 pad[48];
    s128_003E8C50 q30;
    u8 pad2[112 - 64];
    s32 *f70;
    u8 pad3[10];
    s16 h7E;
    u8 pad4[4];
    s16 h84;
    u8 pad5[14];
    s32 f94;
} Obj_003E8C50;
typedef int u128_3E8D18 __attribute__((mode(TI)));
typedef struct { u8 pad[0x200]; u8 x200[0x30]; u128_3E8D18 x230; u8 pad240[0x2A0 - 0x240]; s16 x2A0; u8 pad2A2[0x2C0 - 0x2A2]; f32 x2C0; u8 pad2C4[1120 - 0x2C4]; } E_3E8D18;
typedef struct { u8 pad[0x25E5]; u8 x25E5; } G_3E8D18;
typedef struct { u8 pad[0x30]; u128_3E8D18 x30; u8 pad40[0x94 - 0x40]; s32 x94; } O_3E8D18;
typedef struct {
    u8 pad0[292];
    s32 w124;
    u8 pad128[672 - 296];
    s16 h2A0;
    u8 b2A2;
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Entry_3E92A8;
typedef int u128_003E94A0 __attribute__((mode(TI)));
typedef struct { u8 pad[80]; u8 *o; u8 pad2[1036]; } Slot_003E94A0;
typedef int u128_003E9510 __attribute__((mode(TI)));
typedef struct { u8 pad[80]; u8 *o; u8 pad2[1036]; } Slot_003E9510;

typedef struct {
    u8 pad[0x70];
    u8 *x70;
    u8 pad2[0x86 - 0x74];
    s16 h86;
} Q_003E8F20;

typedef struct {
    u8 pad00[0x10];
    u32 flags;
    f32 f14;
    u8 pad18[4];
    f32 f1C;
    u8 pad20[4];
    f32 f24;
} Input_003E92F8;
typedef struct {
    u8 pad00[0x134];
    f32 *p134;
} Ent_003E92F8;
typedef struct {
    u8 pad00[0x60];
    u16 count;
    u8 pad62[2];
    u32 best;
    u32 flags;
} Counter_003E92F8;
typedef struct {
    s32 v;
    u8 pad[0x1C];
} Pad_003E92F8;

typedef struct {
    u8 pad0[0x24C];
    s32 x24C;
    u8 pad1[0x2A0 - 0x250];
    s16 h2A0;
    u8 pad2[0x2A3 - 0x2A2];
    u8 b2A3;
    u8 pad3[0x2B8 - 0x2A4];
    f32 f2B8;
    f32 f2BC;
    f32 f2C0;
    f32 f2C4;
    f32 f2C8;
    f32 f2CC;
    u8 pad4[1120 - 0x2D0];
} Ent_003EB200;

LINKER_REMNANT("asm/levels", func_L01_003E3930);

INCLUDE_ASM("asm/levels", func_L01_003E3938);

INCLUDE_ASM("asm/levels", func_L01_003E3F08);

/* localdecomp:start func_L01_003E4008 */
extern void func_003C2880_003E4008();
 
void func_L01_003E4008(void) {
    func_003C2880_003E4008();
}
/* localdecomp:end func_L01_003E4008 */

/* localdecomp:start func_L01_003E4028 */
extern Ent1120 D_L01_001E2BD0[];

void func_L01_003E4028(u8 *obj, u128_t *out) {
    *out = *(u128_t *)&D_L01_001E2BD0[*(s32 *)(obj + 148)];
}
/* localdecomp:end func_L01_003E4028 */

INCLUDE_ASM("asm/levels", func_L01_003E4050);

/* localdecomp:start func_L01_003E4168 */
extern s32 func_L01_003F7350(q128 *, f32);

s32 func_L01_003E4168(q128 *a0) {
    q128 v = *a0;
    return func_L01_003F7350(&v, 0.0f) != 0;
}
/* localdecomp:end func_L01_003E4168 */

INCLUDE_ASM("asm/levels", func_L01_003E4198);

INCLUDE_ASM("asm/levels", func_L01_003E42E8);

INCLUDE_ASM("asm/levels", func_L01_003E4428);

INCLUDE_ASM("asm/levels", func_L01_003E4580);

INCLUDE_ASM("asm/levels", func_L01_003E4828);

INCLUDE_ASM("asm/levels", func_L01_003E48D8);

INCLUDE_ASM("asm/levels", func_L01_003E4F20);

/* localdecomp:start func_L01_003E5578 */
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
void func_L01_003E5578(O_3E3730 *a0, f32 *a1, f32 *a2, f32 b, f32 c, f32 d) {
    V_3E3730 *v = a0->x70;
    a1[0] = func_00382BC8(&v->x120[0], a1[0], a2[0], b, c, d);
    a1[1] = func_00382BC8(&v->x120[1], a1[1], a2[1], b, c, d);
    a1[2] = func_00382BC8(&v->x120[2], a1[2], a2[2], b, c, d);
}
/* localdecomp:end func_L01_003E5578 */

INCLUDE_ASM("asm/levels", func_L01_003E5638);

/* localdecomp:start func_L01_003E5700 */
extern void func_L01_003E5578(O_3E3730 *a0, f32 *a1, f32 *a2, f32 b, f32 c, f32 d);
extern s32 func_0038CB00(u8 *);
extern void func_L01_003E5638(u8 *, s32, void *, s32);

void func_L01_003E5700(u8 *a0, s32 a1) {
    u8 buf[16];
    u8 *q;
    u8 *s;
    f32 scale;
    f32 x;
    f32 y;
    u8 t;

    q = *(u8 **)(a0 + 0x70);
    s = q + 0x60;
    if (func_0038CB00(q + 0x146) != 0) {
        s[0xE5] = s[0xE4];
    }
    scale = (f32)*(s16 *)(s + 0xE6) * *(f32 *)(s + 0xE8);
    func_L01_003E5638(a0, a1, buf, s[0xE4]);
    t = s[0xE4];
    if (t == 3 || t == 5 || t == 6 || t == 7 || t == 1) {
        x = scale * -0.049999997f + 0.0599999987f;
        y = scale * -0.200000003f + 0.400000006f;
    } else {
        x = 0.00999999978f;
        y = 0.200000003f;
    }
    ((void (*)(u8 *, u8 *, void *, f32, f32, f32))func_L01_003E5578)(a0, s + 0xB0, buf, x, y, 0.0f);
}
/* localdecomp:end func_L01_003E5700 */

INCLUDE_ASM("asm/levels", func_L01_003E5828);

INCLUDE_ASM("asm/levels", func_L01_003E5E50);

INCLUDE_ASM("asm/levels", func_L01_003E6120);

INCLUDE_ASM("asm/levels", func_L01_003E6DA0);

INCLUDE_ASM("asm/levels", func_L01_003E7000);

INCLUDE_ASM("asm/levels", func_L01_003E7138);

INCLUDE_ASM("asm/levels", func_L01_003E75A8);

INCLUDE_ASM("asm/levels", func_L01_003E77B0);

/* localdecomp:start func_L01_003E7AA0 */
s32 func_L01_003E7AA0(void) {
    u8 buf[80];
    return 0;
}
/* localdecomp:end func_L01_003E7AA0 */

INCLUDE_ASM("asm/levels", func_L01_003E7AB0);

INCLUDE_ASM("asm/levels", func_L01_003E7B80);

INCLUDE_ASM("asm/levels", func_L01_003E7F48);

INCLUDE_ASM("asm/levels", func_L01_003E7FA8);

INCLUDE_ASM("asm/levels", func_L01_003E8360);

/* localdecomp:start func_L01_003E8AD8 */
extern Entry_3E6C58 D_L01_001E2A40[];
s32 func_L01_003E8AD8(u8 *a0) {
    Entry_3E6C58 *e = D_L01_001E2A40;
    u8 *p = e[*(s32 *)(a0 + 148)].p50;
    if (*(s16 *)(p + 134)) {
        return -1;
    }
    p = *(u8 **)(p + 112);
    if (*(u8 **)(p + 608) == a0) {
        *(s32 *)(p + 608) = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003E8AD8 */

/* localdecomp:start func_L01_003E8B28 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern M_3E6CA8 *D_L01_001DF804;
s32 func_L01_003E8B28(u8 *a0) {
    Entry_3E6CA8 *e = ((Entry_3E6CA8 *)&D_L01_001E2A40);
    u8 *q = e[*(s32 *)(a0 + 148)].p50;
    u8 *p;
    u8 *cur;
    if (*(s16 *)(q + 134)) {
        return -1;
    }
    p = *(u8 **)(q + 112);
    cur = *(u8 **)(p + 608);
    if (cur == 0) {
        *(u8 **)(p + 608) = a0;
        return 1;
    }
    if (cur == a0) {
        return 1;
    }
    if (D_L01_001DF804[*(s16 *)(cur + 132)].p1C[28] < D_L01_001DF804[*(s16 *)(a0 + 132)].p1C[28]) {
        *(u8 **)(p + 608) = a0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003E8B28 */

INCLUDE_ASM("asm/levels", func_L01_003E8BD0);

INCLUDE_ASM("asm/levels", func_L01_003E8C28);

/* localdecomp:start func_L01_003E8C70 */
extern u8 D_L01_001E50D0[];

void func_L01_003E8C70(s32 idx, s32 flag, f32 a, f32 b)
{
    u8 *e = (u8 *)D_L01_001E2A40 + idx * 0x460;
    u8 *p = *(u8 **)(e + 0x50);

    if (*(s16 *)(p + 134) == 0) {
        u8 *q = *(u8 **)(p + 112);
        u8 *r = q + 0x60;

        *(s16 *)(r + 0xFA) = 1;
        *(f32 *)(r + 0xD8) = b;
        if (flag) {
            u8 *f = (u8 *)D_L01_001E50D0 + idx * 0xB0;
            u8 *s = *(u8 **)(f + 0x70);
            *(f32 *)(r + 0xD4) = *(f32 *)(s + 0x130) + a;
        } else {
            *(f32 *)(r + 0xD4) = a;
        }
    }
}
/* localdecomp:end func_L01_003E8C70 */

/* localdecomp:start func_L01_003E8CE0 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8CE0(s32 a0, f32 a, f32 b, f32 c) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + a0 * 1120;
    u8 *p = *(u8 **)(e + 80);
    if (*(s16 *)(p + 134) == 0) {
        u8 *q = *(u8 **)(p + 112);
        u8 *r = q + 32;

        *(f32 *)(r + 44) = a;
        *(f32 *)(r + 52) = b * 0.0174532925f * 0.0004000000189f;
        *(f32 *)(r + 56) = c * 0.0174532925f * 0.0004000000189f;
    }
}
/* localdecomp:end func_L01_003E8CE0 */

INCLUDE_ASM("asm/levels", func_L01_003E8D48);

INCLUDE_ASM("asm/levels", func_L01_003E8D80);

/* localdecomp:start func_L01_003E8DB8 */
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003E8DB8(s32 a0, f32 a, f32 b) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + a0 * 1120;
    u8 *o = *(u8 **)(e + 80);
    u8 *p;
    if (*(s16 *)(o + 134) != 0) {
        return;
    }
    p = *(u8 **)(o + 112) + 0x60;
    if (a != 0.0f) {
        *(f32 *)(p + 0xFC) = a;
    }
    if (b != 0.0f) {
        *(f32 *)(p + 0x100) = b;
    }
}
/* localdecomp:end func_L01_003E8DB8 */

INCLUDE_ASM("asm/levels", func_L01_003E8E10);

INCLUDE_ASM("asm/levels", func_L01_003E8E70);

INCLUDE_ASM("asm/levels", func_L01_003E8EA8);

INCLUDE_ASM("asm/levels", func_L01_003E8EE8);

/* localdecomp:start func_L01_003E8F20 */
void func_L01_003E8F20(s32 idx, f32 x, f32 y, f32 z) {
    Entry_3E6C58 *e = (Entry_3E6C58 *)((u8 *)D_L01_001E2A40 + idx * 1120);
    Q_003E8F20 *q = (Q_003E8F20 *)e->p50;
    u8 *p;

    if (q->h86 != 0) {
        return;
    }
    p = q->x70 + 0x210;
    if (x != -1.0f) {
        *(f32 *)(p + 0x3C) = x;
    }
    if (y != -1.0f) {
        *(f32 *)(p + 0x40) = y;
    }
    if (z != -1.0f) {
        *(f32 *)(p + 0x44) = z;
    }
}
/* localdecomp:end func_L01_003E8F20 */

INCLUDE_ASM("asm/levels", func_L01_003E8F90);

INCLUDE_ASM("asm/levels", func_L01_003E8FE8);

INCLUDE_ASM("asm/levels", func_L01_003E9218);

/* localdecomp:start func_L01_003E9250 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern void func_L01_003E8FE8(u8 *a0, f32 f12);
void func_L01_003E9250(s32 a0, f32 a, f32 b) {
    u8 *e = ((u8 *)&D_L01_001E2A40) + a0 * 1120; u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0 && a != 0.0f) {
        *(f32 *)(*(u8 **)(o + 112) + 500) = a;
        func_L01_003E8FE8(o, b);
    }
}
/* localdecomp:end func_L01_003E9250 */

/* localdecomp:start func_L01_003E92B0 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern void func_L01_003E9218(u8 *, f32);
void func_L01_003E92B0(s32 i, f32 a, f32 b) {
    u8 *p = (((S_003E7430 *)&D_L01_001E2A40) + i)->p;
    if (*(s16 *)(p + 134) == 0) {
        *(f32 *)(*(u8 **)(p + 112) + 500) = a;
        func_L01_003E9218(p, b);
    }
}
/* localdecomp:end func_L01_003E92B0 */

/* localdecomp:start func_L01_003E92F8 */
extern u8 D_L01_001E2B90[];
extern f32 D_L01_001D5FF0[2];
extern Pad_003E92F8 D_143A70[];
extern s32 D_143A10[][8];
extern u8 D_1439F4[];
extern s32 D_001D4C38;
extern s32 D_001D545C;
extern Counter_003E92F8 D_1A7C10;
__asm__(".extern D_L01_001DF674, 4");
__asm__(".extern D_L01_001DF678, 4");
extern s32 D_L01_001DF674;
extern s32 D_L01_001DF678;

void func_L01_003E92F8(u8 *obj, f32 *x, f32 *y)
{
    Input_003E92F8 *t = (Input_003E92F8 *)(*(u8 **)(obj + 0x70) + 0x1E0);
    Ent_003E92F8 *e = (Ent_003E92F8 *)(D_L01_001E2B90 + *(s32 *)(obj + 0x94) * 0x460);
    Counter_003E92F8 *c;
    u32 n;
    s32 cnt;
    s32 k = 0;

    if (t->flags & 1) {
        *x = 0.0f;
    } else {
        *x = e->p134[0x100 / 4];
        if (D_143A70[D_1439F4[0]].v == 0)
            *x = -*x;
    }
    if (*x == 0.0f) {
        D_L01_001DF674 = 0;
        D_L01_001DF678 = 0;
        if (t->f1C != 0.0f)
            *x = t->f1C;
    } else {
        cnt = D_L01_001DF674 + 1;
        t->f14 = D_L01_001D5FF0[*(s32 *)(obj + 0x94)];
        D_L01_001DF674 = cnt;
        if (D_L01_001DF678 == 0 && cnt > 0xC) {
            c = &D_1A7C10;
            if (c->count < 0xFFFF)
                c->count++;
            n = (D_001D4C38 * 5 + 2) / 6;
            if (c->best < n)
                c->best = n;
            c->flags = (c->flags | (1 << D_001D545C)) | 0x80000000;
            D_L01_001DF678 = 1;
        }
    }
    if (t->flags & 2) {
        *y = 0.0f;
        *y = t->f24 / 0.6981317f;
    } else {
        f32 v = e->p134[0x104 / 4];
        *y = -v;
        if (D_143A10[D_1439F4[0]][k] == 0)
            *y = v;
        if (*y == 0.0f)
            *y = t->f24 / 0.6981317f;
    }
}
/* localdecomp:end func_L01_003E92F8 */

/* localdecomp:start func_L01_003E9500 */
extern u8 D_L01_001E2AA0[];
extern f32 D_L01_001DF6C8[2];
extern s32 D_001D52F4;
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
extern void func_0038D890(f32 *, f32 *, f32 *, f32);
extern f32 func_0038CE68(f32 *, f32 *);
extern f32 func_0038CEA8(f32 *);
extern void func_0038CE90(f32 *, f32 *, f32 *);
extern void func_0038CF68(f32 *, f32 *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L01_003E9500(u8 *moby, f32 a, f32 b)
{
    f32 v[4];
    u8 *m;
    u8 *p;
    u8 *q;
    u8 *t;
    f32 *w;
    f32 zero;
    f32 lim;
    f32 ang;
    f32 x;
    f32 f2;

    zero = 0.0f;
    m = *(u8 **)(moby + 112);
    q = m + 480;
    p = m + 384;
    t = D_L01_001E2AA0 + *(s32 *)(moby + 148) * 1120;
    x = *(f32 *)(q + 20);
    *(f32 *)(m + 480) = func_00382BC8((f32 *)(m + 484), *(f32 *)(m + 480), a, 2.0f, 4.0f, zero);
    x = x * *(f32 *)(m + 480);
    *(f32 *)(p + 52) = x;
    if (b < -0.3f) {
        b = (b + 0.3f) * 1.4285715f;
    } else if (0.3f < b) {
        b = (b - 0.3f) * 1.4285715f;
    } else {
        b = zero;
    }
    if (b == 0.0f || (f2 = *(f32 *)(q + 8), __builtin_fabsf(b) < __builtin_fabsf(f2) && ((0.0f < b && 0.0f < f2) || (b < 0.0f && f2 < 0.0f)))) {
        lim = 0.01f;
    } else {
        lim = 0.02f;
    }
    *(f32 *)(q + 8) = func_00382BC8((f32 *)(q + 12), *(f32 *)(q + 8), b, 2.0f, 4.0f, lim);
    ang = *(f32 *)(q + 8) * 0.6981317f;
    if (a == 0.0f) {
        func_0038D890((f32 *)p, (f32 *)p, (f32 *)(t + 32), *(f32 *)(q + 32));
        w = (f32 *)(t + 32);
    } else {
        w = (f32 *)(t + 32);
        func_0038D890((f32 *)p, (f32 *)p, w, *(f32 *)(p + 52));
    }
    b = func_0038CE68((f32 *)p, w);
    x = func_0038CEA8((f32 *)p);
    func_0038CE90(v, w, (f32 *)p);
    func_0038CF68(v, v, 1.0f);
    x = func_0038D160(x, b);
    if (__builtin_fabsf(x) < __builtin_fabsf(ang) && lim == 0.01f) {
        *(f32 *)(q + 8) = x / 0.6981317f;
    }
    if (x < ang) {
        if (ang < func_0038DAB8(x, D_L01_001DF6C8[D_001D52F4])) {
            *(f32 *)(p + 56) = func_0038DB00(ang, x);
        } else {
            *(f32 *)(p + 56) = D_L01_001DF6C8[D_001D52F4];
        }
    } else if (ang < x) {
        if (*(s16 *)(*(u8 **)(moby + 112) + 584) < 0) {
            *(f32 *)(p + 56) = 0.0f;
        } else if (func_0038DAB8(x, -D_L01_001DF6C8[D_001D52F4]) < ang) {
            *(f32 *)(p + 56) = func_0038DB00(ang, x);
        } else {
            *(f32 *)(p + 56) = -D_L01_001DF6C8[D_001D52F4];
        }
    } else {
        *(f32 *)(p + 56) = 0.0f;
    }
    if (ang < 0.0f) {
        *(s16 *)(*(u8 **)(moby + 112) + 34) = 1;
    }
    func_0038D890((f32 *)p, (f32 *)p, v, *(f32 *)(p + 56));
}
/* localdecomp:end func_L01_003E9500 */

INCLUDE_ASM("asm/levels", func_L01_003E9908);

INCLUDE_ASM("asm/levels", func_L01_003E99E8);

INCLUDE_ASM("asm/levels", func_L01_003E9F40);

INCLUDE_ASM("asm/levels", func_L01_003EA190);

/* localdecomp:start func_L01_003EA648 */
extern void func_L01_003E9908(u8 *);
extern void func_L01_003E92F8(u8 *, f32 *, f32 *);
extern void func_L01_003E9500(u8 *, f32, f32);
extern void func_L01_003E8360(u8 *);
extern void func_L01_003EA190(u8 *);
extern void func_L01_003E99E8(u8 *);

void func_L01_003EA648(u8 *a0) {
    f32 v[2];

    func_L01_003E9908(a0);
    func_L01_003E92F8(a0, &v[0], &v[1]);
    func_L01_003E9500(a0, v[0], v[1]);
    func_L01_003E8360(a0);
    func_L01_003EA190(a0);
    func_L01_003E99E8(a0);
}
/* localdecomp:end func_L01_003EA648 */

/* localdecomp:start func_L01_003EA6A8 */
extern Entry_3E6C58 D_L01_001E2A40[];


s32 func_L01_003EA6A8(u8 *a0) {
    Unk003E8810 *p = &((Unk003E8810 *)&D_L01_001E2A40)[*(s32 *)(a0 + 148)];
    switch (p->v) {
    case 4:
    case 81:
        return -1;
    }
    return 0;
}
/* localdecomp:end func_L01_003EA6A8 */

INCLUDE_ASM("asm/levels", func_L01_003EA6E8);

/* localdecomp:start func_L01_003EA9B8 */
void func_L01_003EA9B8(void) {

}
/* localdecomp:end func_L01_003EA9B8 */

LINKER_REMNANT("asm/levels", func_L01_003EA9C0);

INCLUDE_ASM("asm/levels", func_L01_003EA9C8);

/* localdecomp:start func_L01_003EAAE8 */
extern M_3E6CA8 *D_L01_001DF804;
extern Entry_3E6C58 D_L01_001E2A40[];





extern void func_0038CC88(Obj_003E8C50 *, void *, s32);
extern void func_L01_003EA9C8(Obj_003E8C50 *);

void func_L01_003EAAE8(Obj_003E8C50 *obj) {
    Slot_003E8C50 *s = (Slot_003E8C50 *)(obj->f94 * 1120 + (u8 *)((Slot_003E8C50 *)&D_L01_001E2A40));
    Base_003E8C50 *base = (*(Ent_003E8C50 * *)&D_L01_001DF804)[obj->h84].p;
    if (base->a3C[obj->f94]) {
        base->a3C[obj->f94] = 0;
        obj->q30 = s->q;
        func_0038CC88(obj, s->data, 48);
    } else {
        s32 *z = obj->f70;
        z[0] = 0;
        z[2] = 0;
        z[1] = 0;
        z[3] = 0;
        z[4] = 0;
        z[5] = 0;
        z[6] = 0;
        func_L01_003EA9C8(obj);
    }
    base->a38[obj->f94] = 0;
    obj->h7E = 0;
}
/* localdecomp:end func_L01_003EAAE8 */

/* localdecomp:start func_L01_003EABB0 */
extern void func_0038CC88(Obj_003E8C50 *, void *, s32);
extern Entry_3E6C58 D_L01_001E2A40[];
extern G_3E8D18 D_001A4BE0;
extern u8 D_001A71C5[];
void func_L01_003EABB0(O_3E8D18 *a0) {
    E_3E8D18 *e = &((E_3E8D18 *)&D_L01_001E2A40)[a0->x94];
    a0->x30 = e->x230;
    ((void (*)(O_3E8D18 *, void *, s32))func_0038CC88)(a0, e->x200, 48);
    if (e->x2A0 == 3 && e->x2C0 >= 0.5f) {
        if (D_001A4BE0.x25E5 == 0) {
            D_001A4BE0.x25E5 = 1;
        } else {
            e->x2C0 = 1.0f;
        }
    } else if (e->x2A0 == 0) {
        D_001A71C5[0] = 1;
    }
}
/* localdecomp:end func_L01_003EABB0 */

INCLUDE_ASM("asm/levels", func_L01_003EAC70);

/* localdecomp:start func_L01_003EB158 */
extern void func_L01_003EAAE8(Obj_003E8C50 *obj);
extern Entry_3E6C58 D_L01_001E2A40[];
extern void func_003A52A0(s32, s32, s32);
void func_L01_003EB158(u8 *a0) {
    Entry_3E92A8 *e = &((Entry_3E92A8 *)&D_L01_001E2A40)[*(s32 *)(a0 + 148)];
    if (e->h2A0 != 0) {
        e->h2A0 = 2;
    } else {
        e->h2A0 = 1;
    }
    e->b2A3 = 0;
    (((Entry_3E92A8 *)&D_L01_001E2A40) + *(s32 *)(a0 + 148))->f2C8 = 0.075f;
    ((Entry_3E92A8 *)&D_L01_001E2A40)[*(s32 *)(a0 + 148)].f2B8 = 0.075f;
    ((void (*)(u8 *))func_L01_003EAAE8)(a0);
    if (e->w124) {
        func_003A52A0(0, 0, e->w124);
    }
}
/* localdecomp:end func_L01_003EB158 */

/* localdecomp:start func_L01_003EB200 */
extern Entry_3E6C58 D_L01_001E2A40[];

void func_L01_003EB200(Obj_003E8C50 *obj) {
    Ent_003EB200 *e = &((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94];
    s32 st = e->x24C;
    if (st == 0x51 || st == 4) {
        return;
    }
    if (e->h2A0 == 0) {
        e->b2A3 = 0;
        obj->h7E = 2;
        ((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94].f2C8 = 0.018f;
        ((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94].f2B8 = 0.018f;
        ((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94].f2CC = 0.25f;
        ((Ent_003EB200 *)&D_L01_001E2A40)[obj->f94].f2BC = 0.25f;
        e->f2C0 = 0.5f;
        return;
    }
    e->h2A0 = 0;
    obj->h7E = 4;
}
/* localdecomp:end func_L01_003EB200 */

INCLUDE_ASM("asm/levels", func_L01_003EB2C0);

INCLUDE_ASM("asm/levels", func_L01_003EB2D8);

/* localdecomp:start func_L01_003EB350 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern u8 *func_L01_003F34E0(s32, s32);
void func_L01_003EB350(s32 a0, u128_003E94A0 *a1) {
    u8 *o = (&((Slot_003E94A0 *)&D_L01_001E2A40)[a0])->o;
    u8 *r;
    if (*(s16 *)(o + 134) != 5) {
        r = func_L01_003F34E0(a0, 5);
    } else {
        r = o;
    }
    *(u128_003E94A0 *)(*(u8 **)(r + 112) + 128) = *a1;
}
/* localdecomp:end func_L01_003EB350 */

/* localdecomp:start func_L01_003EB3C0 */
extern Entry_3E6C58 D_L01_001E2A40[];
extern u8 *func_L01_003F34E0(s32, s32);
void func_L01_003EB3C0(s32 a0, u128_003E9510 *a1) {
    u8 *o = (&((Slot_003E9510 *)&D_L01_001E2A40)[a0])->o;
    u8 *r;
    if (*(s16 *)(o + 134) != 5) {
        r = func_L01_003F34E0(a0, 5);
    } else {
        r = o;
    }
    *(u128_003E9510 *)(*(u8 **)(r + 112) + 144) = *a1;
}
/* localdecomp:end func_L01_003EB3C0 */

LINKER_REMNANT("asm/levels", func_L01_003EB430);

INCLUDE_ASM("asm/levels", func_L01_003EB438);

INCLUDE_ASM("asm/levels", func_L01_003EB5E0);

LINKER_REMNANT("asm/levels", func_L01_003EB748);

INCLUDE_ASM("asm/levels", func_L01_003EB750);
