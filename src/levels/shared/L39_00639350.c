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

INCLUDE_ASM("asm/levels", func_L39_0063A1E8);

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

INCLUDE_ASM("asm/levels", func_L39_0063AC60);

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

INCLUDE_ASM("asm/levels", func_L39_0063D0F0);

INCLUDE_ASM("asm/levels", func_L39_0063D0F8);

INCLUDE_ASM("asm/levels", func_L39_0063D240);

INCLUDE_ASM("asm/levels", func_L39_0063D2A8);

INCLUDE_ASM("asm/levels", func_L39_0063E3D0);
