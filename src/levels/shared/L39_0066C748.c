#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0066C748);

INCLUDE_ASM("asm/levels", func_L39_0066C780);

INCLUDE_ASM("asm/levels", func_L39_0066C788);

INCLUDE_ASM("asm/levels", func_L39_0066C7D8);

/* localdecomp:start func_L39_0066C808 */
s32 func_L39_0066C808(void) {
    return 0;
}
/* localdecomp:end func_L39_0066C808 */

INCLUDE_ASM("asm/levels", func_L39_0066C810);

INCLUDE_ASM("asm/levels", func_L39_0066C818);

/* localdecomp:start func_L39_0066C820 */
s32 func_L39_0066C820(void) {
    return 0;
}
/* localdecomp:end func_L39_0066C820 */

INCLUDE_ASM("asm/levels", func_L39_0066C828);

/* localdecomp:start func_L39_0066C880 */
typedef struct {
    u8 pad0[52];
    u16 unk34;
} Src669F78;

typedef struct {
    u8 pad0[8];
    s32 unk8;
} Info669F78;

typedef struct {
    u8 pad0[24];
    Src669F78 *unk18;
    u16 unk1C;
    u8 pad1E[2];
    s32 unk20;
    u8 pad24[8];
    u8 unk2C;
} Obj669F78;

extern Obj669F78 *func_L39_0061D2D8(s32, s32, s32);
extern Info669F78 *func_L39_005C1018(Src669F78 *);
extern void func_L39_0061D7F8(Obj669F78 *, Src669F78 *);
extern u32 D_L39_0024BF60[];
extern s32 D_L39_0024D758[];

Obj669F78 *func_L39_0066C880(Src669F78 *src, s32 id, s32 b) {
    Obj669F78 *o;

    if ((u32)src >= D_L39_0024BF60[0]) {
        return 0;
    }
    {
        s32 t = D_L39_0024D758[0];
        if (~id != 0) {
            t = id;
        }
        o = func_L39_0061D2D8(7, t, -1);
    }
    if (o != 0) {
        o->unk18 = src;
        o->unk1C = src->unk34;
        o->unk20 = func_L39_005C1018(src)->unk8;
        func_L39_0061D7F8(o, src);
        o->unk2C = b;
    }
    return o;
}
/* localdecomp:end func_L39_0066C880 */

INCLUDE_ASM("asm/levels", func_L39_0066C928);

/* localdecomp:start func_L39_0066C9F8 */
extern void func_L39_0061D7F8(Obj669F78 *, Src669F78 *);
extern Info669F78 *func_L39_005C1018(Src669F78 *);
typedef struct {
    char pad0[0x34];
    unsigned short h34;
} Unk66A0F0Obj;

typedef struct {
    char pad0[0x18];
    Unk66A0F0Obj *obj;
    unsigned short h1C;
    int w20;
    char pad24[0x8];
    unsigned char b2C;
} Unk66A0F0;

extern Unk66A0F0 *func_L39_0061D470(int, int);
extern Unk66A0F0Obj *func_003C24B0(int, int);
extern void func_L01_00456160(Unk66A0F0Obj *, int);

Unk66A0F0 *func_L39_0066C9F8(int a0, int a1, int a2, int a3) {
    Unk66A0F0 *s = func_L39_0061D470(a1, -1);
    if (s != 0) {
        s->obj = func_003C24B0(a0, 128);
        func_L01_00456160(s->obj, a2);
        s->h1C = s->obj->h34;
        s->w20 = ((int * (*)(Unk66A0F0Obj *))func_L39_005C1018)(s->obj)[2];
        ((void (*)(Unk66A0F0 *, Unk66A0F0Obj *))func_L39_0061D7F8)(s, s->obj);
        s->b2C = a3;
    }
    return s;
}
/* localdecomp:end func_L39_0066C9F8 */

INCLUDE_ASM("asm/levels", func_L39_0066CA98);

/* localdecomp:start func_L39_0066CB28 */
typedef struct {
    u8 p0[0x18]; s32 w18; s16 h1C; u8 p1e[2]; s32 w20; s32 w24; s32 w28; u8 b2C; u8 p2d[3];
    s32 w30; s32 w34; s32 w38; s32 w3C; s32 w40; s32 w44; s32 w48; s32 w4C; u8 b50; u8 b51;
} S_66A220;
void func_L39_0066CB28(S_66A220 *s) {
    s->b51 = 1;
    s->w18 = 0;
    s->w20 = 0;
    s->h1C = 0;
    s->w24 = -1;
    s->w28 = -1;
    s->b2C = 0;
    s->w30 = 0;
    s->w34 = -1;
    s->w48 = -1;
    s->w38 = -1;
    s->w44 = -1;
    s->w3C = -1;
    s->w40 = -1;
    s->b50 = 0;
    s->w4C = -1;
}
/* localdecomp:end func_L39_0066CB28 */

INCLUDE_ASM("asm/levels", func_L39_0066CB78);

/* localdecomp:start func_L39_0066CDA0 */
extern Obj669F78 *func_L39_0061D2D8(s32, s32, s32);
extern s32 D_L39_0024D75C[];
extern u8 *D_L39_001DAC20;
void func_L39_0066CDA0(void) {
    u8 *v = ((u8 * (*)(s32, s32, s32))func_L39_0061D2D8)(7, D_L39_0024D75C[0], -2);
    D_L39_001DAC20 = v;
    v[44] = 0;
}
/* localdecomp:end func_L39_0066CDA0 */

INCLUDE_ASM("asm/levels", func_L39_0066CDD0);

INCLUDE_ASM("asm/levels", func_L39_0066D028);

/* localdecomp:start func_L39_0066D348 */
extern Info669F78 *func_L39_005C1018(Src669F78 *);
extern u8 *D_L39_001DAC20;
typedef struct { u8 pad[0x1C]; void (*fn)(s32, s32); } V_66AA40;
typedef struct { u8 pad[0x18]; s32 x18; } A_66AA40;
extern void func_L39_0066D580(void);
void func_L39_0066D348(A_66AA40 *a, s32 b) {
    if (a == (*(A_66AA40 * *)&D_L39_001DAC20)) {
        func_L39_0066D580();
    } else {
        ((V_66AA40 * (*)(s32))func_L39_005C1018)(a->x18)->fn(a->x18, b);
    }
}
/* localdecomp:end func_L39_0066D348 */

INCLUDE_ASM("asm/levels", func_L39_0066D3A8);

INCLUDE_ASM("asm/levels", func_L39_0066D580);

/* localdecomp:start func_L39_0066D888 */
typedef struct {
    char pad0[0x44];
    union {
        u8 b;
        s32 w;
    } team;
    char pad48[0x50 - 0x48];
    u8 unk50;
} Obj;

extern s32 func_L39_0061CF78(s32);

s32 func_L39_0066D888(Obj *o, u8 b, u8 c) {
    s32 ret = 0;
    s32 same = 1;

    if (c != o->team.b) {
        same = 0;
        if (func_L39_0061CF78(c) != 0) {
            o->team.w = c;
            ret = 1;
        }
    }
    if (same) {
        if (o->unk50 < b) {
            ret = 1;
        } else if (o->unk50 >= 193 && b <= 63) {
            ret = 1;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_0066D888 */

INCLUDE_ASM("asm/levels", func_L39_0066D938);

INCLUDE_ASM("asm/levels", func_L39_0066D9A8);

INCLUDE_ASM("asm/levels", func_L39_0066DA10);

/* localdecomp:start func_L39_0066DA90 */
extern u8 *D_L39_001DAC20;
extern u32 *func_L39_006625A8(s32, s32, s32, s32);
extern void func_L39_00662AA0(void *, void *, s32);

void func_L39_0066DA90(s32 *a0, s32 a1, u8 a2, u8 a3) {
    u8 b[2];
    s32 w;
    u32 *s;

    s = func_L39_006625A8((*(s32 *)&D_L39_001DAC20), 1, 0, 0);
    s[20] = a1;
    w = *a0;
    func_L39_00662AA0(s, &w, 4);
    b[0] = a2;
    func_L39_00662AA0(s, b, 1);
    b[0] = a3;
    func_L39_00662AA0(s, b, 1);
    a0[12] = s[1] + (s[0] >> 13);
}
/* localdecomp:end func_L39_0066DA90 */

INCLUDE_ASM("asm/levels", func_L39_0066DB50);

/* localdecomp:start func_L39_0066DC28 */
extern void func_L39_00662AA0(void *, void *, s32);
extern u32 *func_L39_006625A8(s32, s32, s32, s32);
extern u8 *D_L39_001DAC20;
void func_L39_0066DC28(s32 *a, u8 b, u8 c) {
    u8 tmp[16];
    s32 w[4];
    s32 m = ((s32 (*)(s32, s32, s32, s32))func_L39_006625A8)((*(s32 *)&D_L39_001DAC20), 2, 0, 0);
    *(s32 *)(m + 80) = a[18];
    w[0] = a[0];
    ((void (*)(s32, void *, s32))func_L39_00662AA0)(m, w, 4);
    tmp[0] = b;
    ((void (*)(s32, void *, s32))func_L39_00662AA0)(m, tmp, 1);
    tmp[0] = c;
    ((void (*)(s32, void *, s32))func_L39_00662AA0)(m, tmp, 1);
}
/* localdecomp:end func_L39_0066DC28 */

/* localdecomp:start func_L39_0066DCC8 */
extern u32 *func_L39_006625A8(s32, s32, s32, s32);
extern s32 func_L39_0061D7B0(s32);
s32 func_L39_0066DCC8(s32 x, s32 a, s32 b, s32 c) {
    s32 p = func_L39_0061D7B0(x);
    s32 r;
    if (p == 0) {
        r = 0;
    } else {
        r = ((s32 (*)(s32, s32, s32, s32))func_L39_006625A8)(p, a, b, c);
    }
    return r;
}
/* localdecomp:end func_L39_0066DCC8 */
