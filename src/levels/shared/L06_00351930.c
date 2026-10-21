#include "common.h"

/* localdecomp:start func_L06_00351930 */
extern void func_003C3A10(u8 *, s32, s32, s32);
void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 a4) {
    if (a0[67] != a2) {
        func_003C3A10(a0, a2, a3, a4);
        func_003C3A10(*(u8 **)(a1 + 608), a2, a3, a4);
    }
}
/* localdecomp:end func_L06_00351930 */

/* localdecomp:start func_L06_003519A0 */
extern void func_003C3A10(u8 *, s32, s32, s32);
void func_L06_003519A0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    if (a0[67] != a2) {
        func_003C3A10(a0, a2, a3, a4);
    }
}
/* localdecomp:end func_L06_003519A0 */

/* localdecomp:start func_L06_003519D0 */
extern void func_003C3A10(u8 *o, s32 a, s32 b, s32 c);

void func_L06_003519D0(s32 unused, u8 *b, s32 x, s32 y, s32 z) {
    u8 *o = *(u8 **)(b + 608);
    if (o[67] != x) {
        func_003C3A10(o, x, y, z);
    }
}
/* localdecomp:end func_L06_003519D0 */

/* localdecomp:start func_L06_00351A08 */
extern void func_003C3A10(u8 *o, s32 a, s32 b, s32 c);
typedef struct { u8 pad[0x10]; u8 x10; } M_350D10;
typedef struct { u8 pad[0x48]; M_350D10 *x48[1]; } L_350D10;
typedef struct { u8 pad[0x24]; L_350D10 *x24; u8 pad28[0x41 - 0x28]; u8 x41; u8 x42; u8 x43; } A_350D10;
typedef struct { u8 pad[0x260]; A_350D10 *x260; } B_350D10;
void func_L06_00351A08(A_350D10 *a, B_350D10 *b, s32 c) {
    A_350D10 *t = b->x260;
    s32 idx = t->x43;
    if (a->x43 != idx) {
        ((void (*)(A_350D10 *, s32, s32, s32))func_003C3A10)(a, idx, (t->x41 + c / 10) % a->x24->x48[idx]->x10, c);
    }
}
/* localdecomp:end func_L06_00351A08 */

INCLUDE_ASM("asm/levels", func_L06_00351A68);

INCLUDE_ASM("asm/levels", func_L06_00351BB8);

INCLUDE_ASM("asm/levels", func_L06_00351C48);

INCLUDE_ASM("asm/levels", func_L06_00352110);

/* localdecomp:start func_L06_00352370 */
extern s32 func_00382498(s32, s32);

void func_L06_00352370(void *self, u8 *obj) {
    s32 v;
    *(s32 *)(obj + 896) = -1;
    v = func_00382498(4, 6) * 2;
    *(s32 *)(obj + 860) = v;
    *(s32 *)(obj + 908) = v;
}
/* localdecomp:end func_L06_00352370 */

/* localdecomp:start func_L06_003523B0 */
extern s32 func_00382498(s32, s32);
void func_L06_003523B0(s32 a0, char *a1) {
    *(s32 *)(a1 + 904) = func_00382498(90, 120);
}
/* localdecomp:end func_L06_003523B0 */

INCLUDE_ASM("asm/levels", func_L06_003523E0);

/* localdecomp:start func_L06_003523F0 */
s32 func_L06_003523F0(s32 a0, u8 *a1) {
    s32 r = 0;
    if (*(s32 *)(a1 + 904) <= 0) {
        r = *(s32 *)(a1 + 860) < 1;
    }
    return r;
}
/* localdecomp:end func_L06_003523F0 */

INCLUDE_ASM("asm/levels", func_L06_00352410);

INCLUDE_ASM("asm/levels", func_L06_00352500);

INCLUDE_ASM("asm/levels", func_L06_003525E0);

INCLUDE_ASM("asm/levels", func_L06_00352648);

/* localdecomp:start func_L06_00352810 */
typedef struct {
    u8 pad0[148];
    u8 unk94;
} P351B10;

typedef struct {
    u8 pad0[816];
    s32 unk330;
    u8 pad334[860 - 820];
    s32 unk35C;
    u8 pad360[896 - 864];
    s32 unk380;
} O351B10;

extern s32 func_0038CAD0(s32 *);
extern void func_L06_00352648(P351B10 *, O351B10 *, s32);

s32 func_L06_00352810(P351B10 *p, O351B10 *o) {
    if (o->unk35C != 0) {
        if (func_0038CAD0(&o->unk330) == 0) {
            return 0;
        }
        if (o->unk380 == 0) {
            func_L06_00352648(p, o, 1);
            o->unk380 = 1;
        } else {
            func_L06_00352648(p, o, 0);
            o->unk380 = 0;
        }
        if (p->unk94 == 24) {
            o->unk330 = 12;
        } else {
            o->unk330 = 20;
        }
        o->unk35C--;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00352810 */

INCLUDE_ASM("asm/levels", func_L06_003528B8);

INCLUDE_ASM("asm/levels", func_L06_00352AA0);

INCLUDE_ASM("asm/levels", func_L06_00352CA0);

/* localdecomp:start func_L06_00352E08 */
void func_L06_00352E08(s32 a0, u8 *a1) {
    *(s32 *)(a1 + 0x380) = -1;
    *(s32 *)(a1 + 0x35C) = -1;
    *(s32 *)(a1 + 0x38C) = -1;
}
/* localdecomp:end func_L06_00352E08 */

INCLUDE_ASM("asm/levels", func_L06_00352E20);

INCLUDE_ASM("asm/levels", func_L06_00352FB0);

INCLUDE_ASM("asm/levels", func_L06_00353160);

/* localdecomp:start func_L06_00353208 */
void func_L06_00353208(s32 a0, u8 *obj, f32 v) {
    *(f32 *)(obj + 844) = v;
}
/* localdecomp:end func_L06_00353208 */

INCLUDE_ASM("asm/levels", func_L06_00353210);

INCLUDE_ASM("asm/levels", func_L06_003532B8);

INCLUDE_ASM("asm/levels", func_L06_00353480);

INCLUDE_ASM("asm/levels", func_L06_00353610);

INCLUDE_ASM("asm/levels", func_L06_003536C0);

INCLUDE_ASM("asm/levels", func_L06_00353AC8);

INCLUDE_ASM("asm/levels", func_L06_00353B90);

INCLUDE_ASM("asm/levels", func_L06_00353CB8);

INCLUDE_ASM("asm/levels", func_L06_00354118);

/* localdecomp:start func_L06_003541C8 */
typedef struct {
    u8 pad0[832];
    s32 unk340;
    u8 pad344[856 - 836];
    s32 *unk358;
} O3534C8;

typedef struct {
    s32 unk0;
    O3534C8 *unk4;
    s32 unk8;
    s32 unkC;
} S3534C8;

typedef struct {
    u8 pad0[16];
    s32 unk10;
    f32 unk14;
} T3534C8;

extern void func_L06_00354118(S3534C8 *, s32);

s32 func_L06_003541C8(s32 flags, S3534C8 *s, s32 arg, T3534C8 *a, T3534C8 *b, f32 f) {
    if (flags == 0) {
        func_L06_00354118(s, arg);
        return 0;
    }
    if (s->unk4->unk340 != 0) {
        if ((flags ^ 1) & 1) {
            a->unk10 = s->unkC;
            a->unk14 = f;
        }
        if (!(flags & 2)) {
            b->unk10 = s->unkC;
            b->unk14 = f;
        }
    } else {
        if ((flags ^ 1) & 1) {
            a->unk10 = 0;
            a->unk14 = 0.0f;
        }
        if (!(flags & 2)) {
            b->unk10 = s->unk4->unk358[0] - 1;
            b->unk14 = 0.0f;
        }
    }
    return 1;
}
/* localdecomp:end func_L06_003541C8 */

INCLUDE_ASM("asm/levels", func_L06_00354270);

INCLUDE_ASM("asm/levels", func_L06_00354828);

INCLUDE_ASM("asm/levels", func_L06_00354A40);

INCLUDE_ASM("asm/levels", func_L06_00354B08);

INCLUDE_ASM("asm/levels", func_L06_00354C28);

/* localdecomp:start func_L06_00354D48 */
extern void func_L06_00354A40(u8 *a0, u8 *a1);
extern void func_L06_00354C28(u8 *a0, u8 *a1);
extern void func_L06_00354B08(u8 *a0, u8 *a1);

void func_L06_00354D48(u8 *a0, u8 *a1) {
    if (*(s32 *)(a1 + 864) != 0) {
        if (a0[67] == 7) {
            func_L06_00354A40(a0, a1);
        } else {
            func_L06_00354C28(a0, a1);
            *(s32 *)(a1 + 864) = 0;
        }
    } else if (a0[67] == 7) {
        func_L06_00354B08(a0, a1);
        *(s32 *)(a1 + 864) = 1;
    }
}
/* localdecomp:end func_L06_00354D48 */

/* localdecomp:start func_L06_00354DC0 */
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 a4);
extern s32 func_L06_00351390(u8 *a0, s32 a1);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
s32 func_L06_00354DC0(u8 *a0) {
    s32 s1 = *(s32 *)(a0 + 104);
    if (func_L06_00351390(a0, s1) != 0 || a0[32] == 2) {
        func_L01_004450F0(a0, 1, 1);
        ((void (*)(u8 *a0, s32 a1, s32 a2, s32 a3, s32 t0))func_L06_00351930)(a0, s1, 1, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00354DC0 */

INCLUDE_ASM("asm/levels", func_L06_00354E38);
