#include "common.h"

typedef struct Ent_00573C58 {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_00573C58;

/* localdecomp:start func_L39_00573208 */
typedef struct {
    u8 pad0[0x7E];
    s16 h7E;
    u8 pad80[6];
    s16 h86;
    u8 pad88[0xC];
    s32 w94;
} Obj_00573208;

typedef struct {
    u8 pad0[0xFC];
    s32 wFC;
    s32 w100;
    s32 w104;
} Sub_00573208;

typedef struct {
    u8 pad0[0x150];
    Sub_00573208 sub;
    u8 pad25C[0x2A3 - 0x150 - 0x108];
    u8 b2A3;
    u8 pad2A4[0x2B8 - 0x2A4];
    f32 f2B8;
    u8 pad2BC[0x2C8 - 0x2BC];
    f32 f2C8;
    u8 pad2CC[0x458 - 0x2CC];
    s32 w458;
    u8 pad45C[4];
} Cam_00573208;

extern Cam_00573208 D_L39_0024DE80[];
extern s32 D_L39_00241128;
extern s32 D_L39_00242910;
extern f32 D_L39_0024B790;
extern f32 D_L39_0024B794;
__asm__(".extern D_L39_0024B790, 4");
__asm__(".extern D_L39_0024B794, 4");

void func_L39_00573208(Obj_00573208 *self) {
    Cam_00573208 *e = &D_L39_0024DE80[self->w94];
    Sub_00573208 *s = &e->sub;
    if (s->wFC == self->h86 && D_L39_00241128 == 0 &&
        (D_L39_00242910 == 0 || D_L39_00242910 == -2)) return;
    if (s->wFC != 4 && s->wFC != 0x51) {
        e->b2A3 = 0;
        if (s->w104 == 0x1C) self->h7E = 3; else self->h7E = 2;
        (D_L39_0024DE80 + self->w94)->f2C8 = D_L39_0024B794;
        D_L39_0024DE80[self->w94].f2B8 = D_L39_0024B790;
    } else {
        e->w458 = 2;
        self->h7E = 1;
    }
}
/* localdecomp:end func_L39_00573208 */

/* localdecomp:start func_L39_005732E0 */
typedef int Q_005732E0 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x84];
    s16 h84;
    u8 pad86[0x94 - 0x86];
    s32 w94;
} Obj_005732E0;

typedef struct {
    u8 pad0[0x1C];
    u8 *p1C;
    u8 pad20[0x20 - 0x20];
} Slot_005732E0;

typedef struct {
    u8 pad0[0x20];
    s32 arr[9];
    u8 pad44[0x44 - 0x44];
    s16 h44;
    s16 h46;
    s16 h48;
} Sub_005732E0;

extern Slot_005732E0 *D_L39_0024B850;
extern u8 *D_L39_0024C000;
extern s32 func_L39_005B43C8(s32 a, s32 b);
extern void func_0038CC88(void *, void *, s32);

void func_L39_005732E0(Obj_005732E0 *self) {
    Sub_005732E0 *o;
    s32 *arr;
    u8 *q;
    u8 *src;
    s32 cnt;
    s32 i;
    if (self->w94 > 0) return;
    o = (Sub_005732E0 *)D_L39_0024B850[self->h84].p1C;
    arr = o->arr;
    cnt = 0;
    q = (u8 *)self + 0x74;
    for (i = 0; i < 9; i++) {
        if (arr[i] != -1) cnt++;
    }
    if (cnt == 1) {
        i = 0;
    } else {
        i = func_L39_005B43C8(0, cnt - 1);
    }
    if (*(s32 *)((u8 *)arr + (i << 2)) == -1) i = 0;
    if (*(s32 *)((u8 *)arr + (i << 2)) != -1) {
        src = D_L39_0024C000 + (*(s32 *)((u8 *)arr + (i << 2)) << 7);
        *(Q_005732E0 *)((u8 *)self + 0x30) = *(Q_005732E0 *)(src + 0x30);
        *(Q_005732E0 *)((u8 *)self + 0x40) = *(Q_005732E0 *)(src + 0x70);
        func_0038CC88(self, src, 0x30);
    }
    *(s16 *)(q + 0xA) = 0;
    o->h44 = 0x19;
    o->h48 = 0;
    o->h46 = 0;
}
/* localdecomp:end func_L39_005732E0 */

/* localdecomp:start func_L39_005733F8 */
typedef struct { u8 p0[0x46]; s16 h46; } Info_005733F8;
extern u8 *func_L01_003F34E0(s32, s32);
void func_L39_005733F8(void) {
    u8 *o = func_L01_003F34E0(0, 0x21);
    ((Info_005733F8 *)D_L39_0024B850[*(s16 *)(o + 0x84)].p1C)->h46 = 0x19;
}
/* localdecomp:end func_L39_005733F8 */

/* localdecomp:start func_L39_00573438 */
typedef struct {
    u8 pad00[0x46];
    s16 f46;
    s16 f48;
} Info_00573438;
extern u8 *func_L01_003F34E0(s32, s32);

s32 func_L39_00573438(s32 a0) {
    Info_00573438 *p = (Info_00573438 *)D_L39_0024B850[*(s16 *)(func_L01_003F34E0(0, 0x21) + 0x84)].p1C;
    s32 r = 0;
    if (a0 != 0 ? p->f48 >= 0x7E : (p->f48 >= 0x7E && p->f46 <= 0)) r = 1;
    return r;
}
/* localdecomp:end func_L39_00573438 */

INCLUDE_ASM("asm/levels", func_L39_005734C0);

INCLUDE_ASM("asm/levels", func_L39_00573580);

INCLUDE_ASM("asm/levels", func_L39_00573948);

/* localdecomp:start func_L39_00573C58 */
extern u8 D_L39_0024DE00[];
extern Ent_00573C58 *D_L39_0024BB6C;
extern u8 D_001FE020[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
extern s32 func_L39_005B4398(s32);
extern void func_L39_005F3088(s32);

void func_L39_00573C58(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    f32 distance;
    s32 flags;
    u8 *slot;
    s32 four = 4;
    if (sub[5] == 0) return;
    if (sub[0] < 0) return;
    distance = func_0038CF00(D_L39_0024DE00, self + 0x40);
    if (distance < *(f32 *)(self + 0xC)) {
        flags = 0;
        if (D_L39_0024BB6C[sub[0]].f18) flags |= 4;
        slot = D_001FE020 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) == self && slot[0xD0]) return;
        if (func_0038CAD0(sub + 3)) {
            sub[4] = func_L39_005F35D8(sub[0], flags, self, 0x400);
            if (sub[2] > 0) {
                sub[3] = (s32)((sub[1] + func_L39_005B4398(sub[2] - sub[1])) * 50.0f);
            }
        }
    } else if (*(f32 *)(self + 0xC) + 1.0f < distance) {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_001FE020 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) func_L39_005F3088(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L39_00573C58 */
