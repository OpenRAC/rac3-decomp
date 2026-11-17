#include "common.h"

/* localdecomp:start func_L39_0066C808 */
s32 func_L39_0066C808(void) {
    return 0;
}
/* localdecomp:end func_L39_0066C808 */

/* localdecomp:start func_L39_0066C810 */
void func_L39_0066C810(void) {

}
/* localdecomp:end func_L39_0066C810 */

/* localdecomp:start func_L39_0066C818 */
void func_L39_0066C818(void) {

}
/* localdecomp:end func_L39_0066C818 */

/* localdecomp:start func_L39_0066C820 */
s32 func_L39_0066C820(void) {
    return 0;
}
/* localdecomp:end func_L39_0066C820 */

/* localdecomp:start func_L39_0066C828 */
/* Per-function alias prototypes: the C names differ from the later declarations in this file,
   the assembly symbols are the same. */
extern u32 D_L39_0024BF60[];
extern void *func_L39_0066C880_0066C828(void *) __asm__("func_L39_0066C880");
extern void *func_L39_005C1018_0066C828(void *) __asm__("func_L39_005C1018");

s32 func_L39_0066C828(void *src) {
    if ((u32)src < D_L39_0024BF60[0]) {
        return (s32)func_L39_0066C880_0066C828(src);
    }
    return (*(s32 (**)(void *))((u8 *)func_L39_005C1018_0066C828(src) + 4))(src);
}
/* localdecomp:end func_L39_0066C828 */

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

/* localdecomp:start func_L39_0066C928 */
extern u8 *D_L39_00246330;
extern u32 *func_L39_006625A8(s32, s32, s32, s32);
extern void func_L39_00662AA0(void *, void *, s32);
extern s32 func_L39_0061D3F0(s32, s32);

s32 func_L39_0066C928(s32 a0, s32 *a1, u32 *a2) {
    s32 buf[3];
    s32 id;
    u32 v;
    u32 *s;

    id = func_L39_0061D3F0(7, -1);
    s = func_L39_006625A8((*(s32 *)&D_L39_00246330), 0, 0, 250);
    v = 0xFFFFFFFF;
    if (a2 != 0) {
        v = *a2;
    }
    buf[0] = id;
    func_L39_00662AA0(s, &buf[0], 4);
    buf[1] = a0;
    func_L39_00662AA0(s, &buf[1], 4);
    buf[2] = v;
    func_L39_00662AA0(s, &buf[2], 4);
    if (a1 != 0) {
        *a1 = (s32)s;
    }
    return id;
}
/* localdecomp:end func_L39_0066C928 */

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

/* localdecomp:start func_L39_0066CA98 */
typedef struct {
    u8 p0[0x18];
    s32 w18;
    u8 p1c[0x10];
    u8 b2C;
    u8 p2d[3];
    s32 w30;
    s32 w34;
    s32 w38;
    s32 w3C;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    u8 b50;
    u8 b51;
} S_0066CA98;

typedef struct {
    u8 pad0[4];
    S_0066CA98 *(*create)(void *);
} V_0066CA98;

extern s32 func_L39_0061D540(S_0066CA98 *);
extern void func_003C2880(void *);

void func_L39_0066CA98(u8 *a)
{
    S_0066CA98 *o = ((V_0066CA98 * (*)(void *))func_L39_005C1018)(a)->create(a);

    if (o != 0) {
        o->w18 = 0;
        func_L39_0061D540(o);
        o->b51 = 1;
        o->b2C = 0;
        o->w30 = 0;
        o->w34 = -1;
        o->w48 = -1;
        o->w38 = -1;
        o->w44 = -1;
        o->w3C = -1;
        o->w40 = -1;
        o->b50 = 0;
        o->w4C = -1;
    }
    func_003C2880(a);
}
/* localdecomp:end func_L39_0066CA98 */

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
extern u8 *D_L39_00246330;
void func_L39_0066CDA0(void) {
    u8 *v = ((u8 * (*)(s32, s32, s32))func_L39_0061D2D8)(7, D_L39_0024D75C[0], -2);
    D_L39_00246330 = v;
    v[44] = 0;
}
/* localdecomp:end func_L39_0066CDA0 */
