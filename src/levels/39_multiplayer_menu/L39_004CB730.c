#include "common.h"

/* localdecomp:start func_L39_004CB730 */
typedef struct S2_004CB730 {
    u8 pad0[0x1C];
    void *f1C;
    u8 pad20[0x38 - 0x20];
    unsigned long f38;
} S2_004CB730;

typedef struct S1_004CB730 {
    s32 f0;
    u8 pad4[0x44 - 0x4];
    s32 f44;
    u8 f48[0x68 - 0x48];
    s32 f68;
    u8 f6C[0xA0 - 0x6C];
    unsigned long fA0;
} S1_004CB730;

typedef struct S0_004CB730 {
    s32 f0;
    u8 pad4[0x8C - 0x4];
    s32 f8C;
    u8 f90[0xB0 - 0x90];
    S1_004CB730 *fB0;
    u8 padB4[0xDC - 0xB4];
    S2_004CB730 *fDC;
} S0_004CB730;

extern void *func_L39_004CB698(void);
extern unsigned long func_L39_004EC7D8(S0_004CB730 *);
extern void func_L39_004CBB38();
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004E5090(void);
extern void func_L39_004E4FC8(s32, void *, s32);
extern s32 func_L39_004BECC0(s32, s32, char *, s32);
extern s32 func_L39_004BCDE0(void *, S1_004CB730 *);
extern void func_11D380(void *, void *, s32);
extern char D_L39_00475EE8[];

s32 func_L39_004CB730(S0_004CB730 *a0, s32 a1)
{
    S1_004CB730 *s;
    unsigned long v;
    s32 x;
    s32 r;

    s = func_L39_004CB698();
    if (s == 0) {
        return 0;
    }
    v = a0->fDC->f38;
    if (v != 0) {
        s->fA0 = v;
    } else {
        s->fA0 = func_L39_004EC7D8(a0);
    }
    if (a0->fB0 != 0) {
        func_L39_004CBB38(a0->fB0);
        a0->fB0 = 0;
    }
    if (a1 != 0) {
                if (a0->f0 == 2) {
            s->f0 = a0->f0;
            s->f44 = 0x10;
        } else if (a0->f0 == 0x300) {
            s->f0 = a0->f0;
            s->f44 = 0x20;
        } else if (a0->f0 == 0x301) {
            s->f0 = a0->f0;
            s->f44 = 0x20;
        } else {
            func_L39_004BC6C8(0x14, 0xB5, 0x103, 0, 0);
            func_L39_004CBB38(s);
            return 0;
        }
        do {
            func_L39_004E4FC8(func_L39_004E5090(), s->f48, s->f44);
            func_L39_004BECC0(5, 0xC, D_L39_00475EE8, 0x87);
            r = func_L39_004BCDE0(a0->fDC->f1C, s);
            func_L39_004BECC0(6, 0xC, D_L39_00475EE8, 0x8A);
        } while (r != 0);
    } else {
        s->f44 = 0;
    }
    func_11D380(s->f6C, a0->f90, a0->f8C);
    s->f68 = a0->f8C;
    a0->fB0 = s;
    s->f0 = a0->f0;
    return 1;
}
/* localdecomp:end func_L39_004CB730 */

INCLUDE_ASM("asm/levels", func_L39_004CB8D0);

/* localdecomp:start func_L39_004CBA18 */
typedef struct S_004CBA18 {
    char pad0[0x44];
    s32 f44;
} S_004CBA18;

extern char D_L39_00475EE8[];
extern s32 func_L39_004BECC0(s32, s32, char *, s32);
extern s32 func_L39_004CBAA8(void *, void *);

s32 func_L39_004CBA18(void *arg0, void *arg1_) {
    S_004CBA18 *arg1 = arg1_;
    s32 result;
    char *base;
    if (arg1 != 0 && arg1->f44 != 0) {
        base = D_L39_00475EE8;
        func_L39_004BECC0(9, 0xC, base, 0x14B);
        result = func_L39_004CBAA8(arg0, arg1);
        func_L39_004BECC0(0xA, 0xC, base, 0x14D);
    } else {
        result = 0;
    }
    return result;
}
/* localdecomp:end func_L39_004CBA18 */

/* localdecomp:start func_L39_004CBAA8 */
typedef struct S_004CBAA8_Item { u8 pad[0x8C]; s32 f8C; } S_004CBAA8_Item;
typedef struct S_004CBAA8_Obj {
    u8 pad[0x1C];
    s32 f1C;
    u8 pad20[0x24];
    void (*f44)(struct S_004CBAA8_Obj *, S_004CBAA8_Item *);
} S_004CBAA8_Obj;
struct S_004CBE68;
extern S_004CBAA8_Item *func_L39_004BCD28(s32);
extern void func_L39_004CBE68(struct S_004CBE68 *, struct S_004CBE68 *);
extern void func_L39_004CBB38();

s32 func_L39_004CBAA8(void *obj_, void *node) {
    S_004CBAA8_Obj *obj = obj_;
    s32 result = 0;
    S_004CBAA8_Item *item = func_L39_004BCD28(obj->f1C);

    if (item != 0) {
        result = 1;
        func_L39_004CBE68(obj_, node);
    }
    if (result != 0) {
        item->f8C = 1;
        if (obj->f44 != 0) {
            obj->f44(obj, item);
        }
        func_L39_004CBB38(item);
    }
    return result;
}
/* localdecomp:end func_L39_004CBAA8 */

INCLUDE_ASM("asm/levels", func_L39_004CBB38);

/* localdecomp:start func_L39_004CBCF0 */
extern s32 func_L39_004E5108(void);
extern void func_L39_004E5210(s32 *, s32, s32, s32);
extern void func_L39_004E4C68(s32);
extern void func_L39_004E5168(s32);
extern s32 func_L39_004BECC0(s32, s32, char *, s32);
extern void func_L39_004BCE40(void *, void *, void *);
extern s32 D_L39_00475F00[];
extern char D_L39_00475EE8[];
extern s32 D_L39_004CBC38[];

typedef struct S_004CBCF0 {
    s32 pad[7];
    s64 *f1C;
} S_004CBCF0;

typedef struct F_004CBCF0 {
    S_004CBCF0 *a;
    s32 b;
    s64 *c;
} F_004CBCF0;

void func_L39_004CBCF0(S_004CBCF0 *arg0, s32 arg1) {
    F_004CBCF0 fr;
    s64 saved;

    fr.a = arg0;
    fr.b = func_L39_004E5108();
    fr.c = arg0->f1C;
    if (fr.c != 0) {
        if (arg1 == 0) {
            func_L39_004E5210(D_L39_00475F00, 0x11, 2, fr.b);
        } else {
            func_L39_004E4C68(fr.b);
        }
        func_L39_004BECC0(9, 0xC, D_L39_00475EE8, 0x235);
        saved = fr.c[5];
        fr.c[5] = 0;
        func_L39_004BCE40(fr.c, D_L39_004CBC38, &fr);
        fr.c[5] = saved;
        func_L39_004BECC0(0xA, 0xC, D_L39_00475EE8, 0x23A);
        func_L39_004E5168(fr.b);
    }
}
/* localdecomp:end func_L39_004CBCF0 */

/* localdecomp:start func_L39_004CBDC0 */
extern s32 func_L39_004C4EE0();
extern s32 func_L39_004CBA18(void *, void *);

s32 func_L39_004CBDC0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0xB0) != 0 && !(*(s32 *)(arg0 + 0x2C) & 1)
        && (func_L39_004C4EE0() & 0x3000) != func_L39_004C4EE0(arg0)
        && !(func_L39_004C4EE0(arg0) & 0x4000)
        && func_L39_004C4EE0(arg0) != 3) {
        *(s32 *)(*(u8 **)(arg0 + 0xB0) + 0x8C) = 1;
        func_L39_004CBA18(*(void **)(arg0 + 0xDC), *(void **)(arg0 + 0xB0));
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_004CBDC0 */
