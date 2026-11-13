#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00639350);

INCLUDE_ASM("asm/levels", func_L39_00639740);

INCLUDE_ASM("asm/levels", func_L39_00639B70);

INCLUDE_ASM("asm/levels", func_L39_00639D90);

/* localdecomp:start func_L39_0063A030 */
extern void func_L39_005F33E0(s32, s32, s32);

void func_L39_0063A030(u8 *a0, s32 a1, s32 a2) {
    func_L39_005F33E0(a1, a2, *(s32 *)(a0 + 9508));
}
/* localdecomp:end func_L39_0063A030 */

/* localdecomp:start func_L39_0063A058 */
extern void func_L39_005F33E0(s32, s32, s32);
typedef struct {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    s32 wDC;
} S_637810_Ent;

typedef struct {
    u8 pad0[0x80];
} S_637810_Slot;

typedef struct {
    u8 pad0[0x2400];
    s32 handles[9];
    s32 keys[9];
} S_637810;

extern S_637810_Slot D_L39_001FE020[];

void func_L39_0063A058(S_637810 *self, s32 i, s32 key, s32 arg) {
    s32 h = self->handles[i];
    if (h != -1) {
        S_637810_Ent *e = (S_637810_Ent *)&D_L39_001FE020[h];
        if (e->wDC == key && e->bD0 != 0) {
            goto done;
        }
    }
    self->handles[i] = ((s32 (*)(s32, s32, s32))func_L39_005F33E0)(arg, 4, key);
done:
    self->keys[i] = key;
}
/* localdecomp:end func_L39_0063A058 */

INCLUDE_ASM("asm/levels", func_L39_0063A0F0);

/* localdecomp:start func_L39_0063A1E8 */
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Type1;
/* from rac4-decomp's func_0051FD70 */
void func_L39_0063A1E8(char *a, s32 b, s32 c, s32 d)
{
    Type1 *p = (Type1 *)(a + 0x23F0);
    s32 i = 0;
    do {
        i++;
        if (!p->f0) {
            p->f0 = 1;
            p->f6 = d;
            p->f4 = c;
            p->f2 = b;
            return;
        }
        p++;
    } while (i < 2);
}
/* localdecomp:end func_L39_0063A1E8 */

/* localdecomp:start func_L39_0063A230 */
extern void func_L39_0063A4E0(u8 *p, s32 a, s32 b, s32 en, s32 t);
extern void func_L39_0063A030(u8 *a0, s32 a1, s32 a2);
typedef struct {
    s16 active;
    s16 type;
    s16 timer;
    s16 arg;
} Slot_6379E8;

typedef struct {
    u8 pad0[891];
    u8 b891;
    u8 pad1[9200 - 892];
    Slot_6379E8 slots[2];
} Self_6379E8;

extern s32 func_0038CB00(s16 *timer);

void func_L39_0063A230(Self_6379E8 *self) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (func_0038CB00(&self->slots[i].timer) == 2) {
            self->slots[i].active = 0;
            if (self->slots[i].type == 28) {
                ((void (*)(Self_6379E8 *self, s32 a, s32 b, s32 c, s32 d))func_L39_0063A4E0)(self, self->b891, 1, 1, 50);
            } else {
                ((void (*)(Self_6379E8 *self, s32 type, s32 arg))func_L39_0063A030)(self, self->slots[i].type, self->slots[i].arg);
            }
        }
    }
}
/* localdecomp:end func_L39_0063A230 */

INCLUDE_ASM("asm/levels", func_L39_0063A2E8);

INCLUDE_ASM("asm/levels", func_L39_0063A330);

/* localdecomp:start func_L39_0063A4E0 */
extern void func_L39_005F3668(s32, s32, s32, s32, s32, s32);
void func_L39_0063A4E0(u8 *p, s32 a, s32 b, s32 en, s32 t) {
    s32 f;
    if (en) {
        f = 0;
        if (*(s32 *)(p + 0x4A0)) {
            f = *(s32 *)(p + 0x4C8) == 14;
        }
        t = (t << 10) / 30;
        func_L39_005F3668(a, b, f, 0, *(s32 *)(p + 0x2524), t);
    }
}
/* localdecomp:end func_L39_0063A4E0 */

INCLUDE_ASM("asm/levels", func_L39_0063A540);

INCLUDE_ASM("asm/levels", func_L39_0063A888);

/* localdecomp:start func_L39_0063AC60 */
typedef union Buf_0063AC60 {
    u8 b[8];
    u32 w[2];
} Buf_0063AC60;

typedef struct VT_0063AC60 {
    u8 pad0[0x34];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_0063AC60;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;
extern void func_L39_0062B718(void *);
extern void func_L39_0063B0A8(void *);
extern void func_003C6FB0(s32, void *, void *, void *);

static inline void Prep_0063AC60(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline void ClrSet_0063AC60(u8 *q) {
    Buf_0063AC60 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0063AC60(q);
    key = ((u32 *)D_L39_004997E0)[((u32)q * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

void func_L39_0063AC60(u8 *g) {
    *(f32 *)(g + 0x1E0) = 0.8f;
    *(f32 *)(g + 0x1E4) = 0.7f;
    *(f32 *)(g + 0x1F4) = 0.45f;
    *(f32 *)(g + 0x1E8) = *(f32 *)(g + 0x1E0);
    *(f32 *)(g + 0x1EC) = *(f32 *)(g + 0x1E4);
    *(s32 *)(g + 0x18D8) = 0;
    ClrSet_0063AC60(g + 0x19E4);
    *(f32 *)(g + 0x614) = 1.0f;
    func_L39_0062B718(g);
    (*(VT_0063AC60 **)(g + 0x14))->f34(g, 0, 1, 0, 1);
    *(f32 *)(g + 0xF0) = 1.0f;
    *(f32 *)(g + 0xF4) = 1.0f;
    *(f32 *)(g + 0xF8) = 1.0f;
    g[0x1A13] = 0;
    func_L39_0063B0A8(g);
    func_003C6FB0(*(s32 *)(g + 0x2524), g + 0x24DC, g + 0x24E0, g + 0x24E4);
}
/* localdecomp:end func_L39_0063AC60 */

INCLUDE_ASM("asm/levels", func_L39_0063AE10);

INCLUDE_ASM("asm/levels", func_L39_0063B0A8);

INCLUDE_ASM("asm/levels", func_L39_0063B5E0);

INCLUDE_ASM("asm/levels", func_L39_0063B970);

INCLUDE_ASM("asm/levels", func_L39_0063BA40);

/* localdecomp:start func_L39_0063BDE0 */
typedef struct { u8 pad[0xAA]; s16 t; } S639;
s32 func_L39_0063BDE0(s32 unused, S639 *p) {
    if (p == 0) return 0;
    return p->t == 0x18AB;
}
/* localdecomp:end func_L39_0063BDE0 */

INCLUDE_ASM("asm/levels", func_L39_0063BE00);

/* localdecomp:start func_L39_0063BF40 */
extern s32 func_0038CB00(s16 *timer);
typedef struct {
    char pad0[452];
    int a;
    int b;
} Pad006396F8;

typedef struct {
    char pad0[996];
    unsigned short count;
    char pad3E6[9524 - 998];
    Pad006396F8 *pad;
} Obj006396F8;

extern int func_L39_00639D90(Obj006396F8 *);

void func_L39_0063BF40(Obj006396F8 *o)
{
    if (func_L39_00639D90(o)) {
        ((void (*)(unsigned short *))func_0038CB00)(&o->count);
        return;
    }
    if (o->pad->a & 3) {
        if (o->pad->a & 2)
            o->count++;
        if (o->pad->a & 1)
            o->count++;
    }
    if (o->pad->b & 3) {
        if (o->pad->b & 2)
            ((void (*)(unsigned short *))func_0038CB00)(&o->count);
        if (o->pad->b & 1)
            ((void (*)(unsigned short *))func_0038CB00)(&o->count);
    }
}
/* localdecomp:end func_L39_0063BF40 */

INCLUDE_ASM("asm/levels", func_L39_0063C000);

INCLUDE_ASM("asm/levels", func_L39_0063C468);

INCLUDE_ASM("asm/levels", func_L39_0063C840);

/* localdecomp:start func_L39_0063D0F0 */
s32 func_L39_0063D0F0(s32 arg0, s32 arg1) {
    return arg1;
}
/* localdecomp:end func_L39_0063D0F0 */

INCLUDE_ASM("asm/levels", func_L39_0063D0F8);

/* localdecomp:start func_L39_0063D240 */
void func_L39_006770F8(u8);

void func_L39_0063D240(void *arg0, s32 arg1) {
    if ((((*(u8 *)((u8 *)arg0 + 0x1A14)) != 0) || (arg1 != 0)) && ((*(s32 *)((u8 *)arg0 + 0x251C)) != 0)) {
        *(s32 *)((u8 *)arg0 + 0x251C) = 0;
        *(s8 *)((u8 *)arg0 + 0x24AA) = 1;
        func_L39_006770F8((*(u8 *)((u8 *)arg0 + 0x24C9)));
        if ((*(s16 *)((u8 *)arg0 + 0x24A8)) == 0) {
            *(s16 *)((u8 *)arg0 + 0x24A8) = 0x11;
        }
    }
}
/* localdecomp:end func_L39_0063D240 */

INCLUDE_ASM("asm/levels", func_L39_0063D2A8);

INCLUDE_ASM("asm/levels", func_L39_0063E3D0);
