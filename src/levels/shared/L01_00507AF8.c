#include "common.h"

typedef struct {
    u8 pad0[4848];
    u8 *p4848;
    u8 *p4852;
    u8 pad1[4884 - 4856];
    s32 mode;
    u8 pad2[9676 - 4888];
    s32 action;
    s32 state;
} S_0050F4C0;

INCLUDE_ASM("asm/levels", func_L01_00507AF8);

/* localdecomp:start func_L01_0050F368 */
extern u8 D_001A4BE0[];
extern s32 func_L01_0050F620(s32, s32 *, s32 *);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L01_0050F368(void)
{
    u8 *p = D_001A4BE0;
    u8 *s0;
    u8 *s1;
    s32 buf[2];

    s0 = *(u8 **)(p + 4848);
    s1 = *(u8 **)(p + 4852);

    if (s0 == 0)
        return;
    if (s1 == 0)
        return;
    if (s0[67] != 1)
        return;
    if (func_L01_0050F620(0, buf, buf + 1) == 0)
        return;
    func_003C3A10(s0, buf[0], 0, 6);
    func_003C3A10(s1, buf[1], 0, 6);
}
/* localdecomp:end func_L01_0050F368 */

/* localdecomp:start func_L01_0050F3F0 */
typedef struct {
    s16 h;
    u8 b;
    u8 pad;
} E_0050B448;
extern E_0050B448 D_L01_001DBDD8;
extern E_0050B448 D_L01_001DBDC0;
extern E_0050B448 D_L01_001DBDF0;
extern s32 func_L01_004E9238(s32);
s32 func_L01_0050F3F0(s32 a0, s32 *a1) {
    E_0050B448 *p;
    p = 0;
    if (func_L01_004E9238(3) == 2) {
        p = &D_L01_001DBDD8;
    } else if (func_L01_004E9238(3) == 3) {
        p = &D_L01_001DBDC0;
    } else if (func_L01_004E9238(3) == 4) {
        p = &D_L01_001DBDF0;
    }
    if (p != 0) {
        s32 i = 0;
        while (p[i].h != -1) {
            if (a0 == p[i].b) {
                *a1 = p[i].h;
                return 1;
            }
            i++;
        }
    }
    *a1 = 0;
    return 0;
}
/* localdecomp:end func_L01_0050F3F0 */

/* localdecomp:start func_L01_0050F4C0 */
extern S_0050F4C0 D_1A4BE0;
extern s32 func_L01_0050F620(s32, s32 *, s32 *);
extern s32 func_L01_0050F3F0(s32, s32 *);
extern s32 func_L01_004E9238(s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L01_0050F4C0(s32 a0, s32 a1, f32 f12)
{
    u8 *p1;
    u8 *p2;
    s32 out0;
    s32 out1;
    s32 flag;
    s32 s0;
    f32 f20 = f12;

    if (D_1A4BE0.mode != 2)
        return;
    p1 = D_1A4BE0.p4848;
    p2 = D_1A4BE0.p4852;
    if (p1 == 0)
        return;
    if (p2 == 0)
        return;

    if (func_L01_0050F620(a0, &out0, &out1) != 0 && a0 != 0) {
        if (p1[0x43] != out0) {
            s0 = (s32)f20;
            func_003C3A10(p1, out0, a1, s0);
            func_003C3A10(p2, out1, a1, s0);
        }
        return;
    }

    flag = 1;
    if (D_1A4BE0.action == 0) {
        if (func_L01_0050F3F0(p1[0x43], &a0) != 0 && a0 == 0)
            flag = 0;
    }
    if (flag == 0)
        return;

    s0 = 6;
    if (D_1A4BE0.state == 8) {
        if (func_L01_004E9238(3) == 2)
            s0 = 0x10;
    }
    if (p1[0x43] != 1)
        func_003C3A10(p1, 1, 0, s0);
    if (p2[0x43] != 1)
        func_003C3A10(p2, 1, 0, s0);
}
/* localdecomp:end func_L01_0050F4C0 */

/* localdecomp:start func_L01_0050F620 */
typedef struct {
    short key;
    unsigned char a;
    unsigned char b;
} Elem;
extern int func_L01_004DFE80(int);
extern int func_L01_004E9238(int);
extern int func_00382498(int, int);

/* from rac2-decomp's func_L00_002D1DA0, renamed */
int func_L01_0050F620(int a0, int *a1, int *a2)
{
    int buf[20];
    Elem *table;
    int count = 0;
    int idx;
    int key;
    key = func_L01_004DFE80(a0);
    if (func_L01_004E9238(3) == 2) {
        table = &D_L01_001DBDD8;
    } else if (func_L01_004E9238(3) == 3) {
        table = &D_L01_001DBDC0;
    } else if ((func_L01_004E9238(3) ^ 4) != 0) {
        table = 0;
    } else {
        table = &D_L01_001DBDF0;
    }
    if (table != 0) {
        for (idx = 0; table[idx].key != -1; idx++) {
            if (key == table[idx].key) {
                buf[count] = idx;
                count++;
            }
        }
    }
    idx = count - 1;
    if (count != 0) {
        int n = func_00382498(0, idx);
        *a1 = table[buf[n]].a;
        *a2 = table[buf[n]].b;
        return 1;
    }
    *a1 = 1;
    return 0;
}
/* localdecomp:end func_L01_0050F620 */

/* localdecomp:start func_L01_0050F758 */
extern u8 D_001A4BE0[];
extern s32 func_L01_0050F620(s32, s32 *, s32 *);

void func_L01_0050F758(void)
{
    u8 *p = D_001A4BE0;
    s32 a[2];
    u8 *o;

    if (p[9700] == 0 && *(s32 *)(p + 4884) == 2) {
        if (func_L01_0050F620((*(u8 **)(p + 9664))[67], &a[0], &a[1])) {
            o = *(u8 **)(p + 4848);
            if (o != 0) {
                *(f32 *)(o + 72) = *(f32 *)(p + 3072);
            }
            o = *(u8 **)(p + 4852);
            if (o != 0) {
                *(f32 *)(o + 72) = *(f32 *)(p + 3072);
            }
        }
    }
}
/* localdecomp:end func_L01_0050F758 */

/* localdecomp:start func_L01_0050F7E0 */
extern u8 D_001A4BE0[];
typedef struct { u8 pad[10240]; s32 a; s32 b; } S_0050B838;
void func_L01_0050F7E0(void) {
    (*(S_0050B838 *)&D_001A4BE0).a = 0;
    (*(S_0050B838 *)&D_001A4BE0).b = 0;
}
/* localdecomp:end func_L01_0050F7E0 */

/* localdecomp:start func_L01_0050F7F8 */
typedef struct {
    s16 key;
    s16 val;
} S_50B850;

extern S_50B850 *D_001A73E4[];

s32 func_L01_0050F7F8(s32 key, s32 *out) {
    S_50B850 *p = D_001A73E4[0];
    s32 i;
    if (p == 0) {
        return 0;
    }
    for (i = 0; p[i].key != -1; i++) {
        if (key == p[i].key) {
            *out = p[i].val;
            return 1;
        }
    }
    *out = 0;
    return 0;
}
/* localdecomp:end func_L01_0050F7F8 */

/* localdecomp:start func_L01_0050F858 */
extern u8 D_001A4BE0[];
extern s32 func_L01_0050F7F8(s32 key, s32 *out);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L01_0050F858(s32 a0, s32 a1, f32 f12)
{
    u8 *base = D_001A4BE0;
    s32 out;

    if (*(s32 *)(base + 0x2800) == 0)
        return;
    if (*(s32 *)(base + 0x2804) == 0)
        return;
    if (func_L01_0050F7F8(a0, &out) != 0) {
        func_003C3A10(*(u8 **)(base + 0x2800), out, a1, (s32)f12);
    } else if (*(*(u8 **)(base + 0x2800) + 0x43) != 0) {
        func_003C3A10(*(u8 **)(base + 0x2800), 0, 0, 6);
    }
}
/* localdecomp:end func_L01_0050F858 */

/* localdecomp:start func_L01_0050F8F0 */
extern s32 func_L01_0050F7F8(s32 key, s32 *out);
extern u8 D_001A4BE0[];
typedef struct {
    u8 pad0[3072];
    f32 f3072;
    u8 pad1[9664 - 3076];
    u8 *p9664;
    u8 pad2[10240 - 9668];
    u8 *p10240;
    s32 f10244;
} S_1A4BE0;


void func_L01_0050F8F0(void) {
    u8 buf[16];
    S_1A4BE0 *s = &(*(S_1A4BE0 *)&D_001A4BE0);
    if (s->p10240 != 0 && s->f10244 != 0) {
        if (((s32 (*)(s32, void *))func_L01_0050F7F8)(s->p9664[67], buf) != 0) {
            *(f32 *)(s->p10240 + 72) = s->f3072;
        }
    }
}
/* localdecomp:end func_L01_0050F8F0 */

INCLUDE_ASM("asm/levels", func_L01_0050F950);
