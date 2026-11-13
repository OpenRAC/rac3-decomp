#include "common.h"
#include "vu0.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct {
    u8 pad0[208];
    s32 table[35];
    s32 index;
} Obj329158;

INCLUDE_ASM("asm/levels", func_L05_00328BF8);

/* localdecomp:start func_L05_00328E98 */

void func_L05_00328E98(u8 *obj, Vec4 a, Vec4 b) {
    *(Vec4 *)(obj + 432) = a;
    *(Vec4 *)(obj + 448) = b;
}
/* localdecomp:end func_L05_00328E98 */

/* localdecomp:start func_L05_00328EC0 */

extern void func_L05_00328E98(u8 *obj, Vec4 a, Vec4 b);

void func_L05_00328EC0(u8 *obj, u8 *target, Vec4 a, Vec4 b) {
    *(Vec4 *)(obj + 16) = a;
    *(Vec4 *)(obj + 240) = b;
    func_L05_00328E98(target, a, b);
}
/* localdecomp:end func_L05_00328EC0 */

/* localdecomp:start func_L05_00328F00 */
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_0043B510(s32);
extern void func_L05_00329618(s32, u8 *);
extern u8 D_001A4C60[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;

void func_L05_00328F00(u8 *o, u8 *s) {
    s32 t = *(s32 *)(s + 0x78);
    if (t == -1 || (D_001BBC40[t + D_001D545C * 16] & 0x80) == 0) {
        if (*(s32 *)(s + 0x74) == -1) {
            return;
        }
        if (func_00382380(D_001A4C60, *(s32 *)(s + 0x74), 0) == 0) {
            return;
        }
    }
    *(s32 *)(s + 0x70) = 1;
    *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
    *(u16 *)(o + 0x34) &= ~1;
    if (*(s32 *)(s + 0x74) != -1 && *(s32 *)(s + 0x78) != -1 && (D_001BBC40[*(s32 *)(s + 0x78) + D_001D545C * 16] & 0x80) == 0) {
        func_L01_0043B510(*(s32 *)(s + 0x78));
    }
    func_L05_00329618((s32)o, s);
}
/* localdecomp:end func_L05_00328F00 */

/* localdecomp:start func_L05_00328FF8 */
extern u8 D_001A4BE0[];

/* from rac2-decomp's func_L00_00324120, renamed, constants adapted */
s32 func_L05_00328FF8(s32 a0) {
    u8 *b = D_001A4BE0;
    if (*(s32 *)(b + 0x25cc) == 3 || *(s32 *)(b + 0x25c4) == 0x1B) {
        if (*(s32 *)(b + 0x538) != a0)
            goto Lzero;
        return 1;
    }
    if (*(short *)(b + 0x36e) != 0)
        goto Lzero;
    if (*(s32 *)(b + 0x35c) == a0) {
        return 1;
    }
Lzero:
    return 0;
}
/* localdecomp:end func_L05_00328FF8 */

/* localdecomp:start func_L05_00329050 */
extern s32 *D_L05_0021ED80[];
extern u8 *D_L05_001DFC80;
extern f32 func_0038CF00(void *, void *);

s32 func_L05_00329050(u8 *a0, u8 *a1, s32 a2) {
    s32 best = -1;
    f32 bd = 9999.0f;
    s32 *tab = D_L05_0021ED80[a2];
    s32 i;
    f32 d;
    for (i = 0; i < 4; i++) {
        s32 t = *(s32 *)(a1 + 0x90 + i * 4);
        if (t != -1) {
            d = func_0038CF00((u8 *)tab + tab[0] * 16, D_L05_001DFC80 + (t << 7) + 0x30);
            if (d < bd) {
                bd = d;
                best = i;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L05_00329050 */

INCLUDE_ASM("asm/levels", func_L05_00329120);

INCLUDE_ASM("asm/levels", func_L05_003293B0);

/* localdecomp:start func_L05_00329618 */
extern s32 func_L01_00470150(void *, s32, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);
extern u8 D_L05_002B2100[];

void func_L05_00329618(s32 a0, u8 *a1) {
    u8 *e = D_L05_002B2100;
    s32 *slot = (s32 *)(a1 + 0x130);
    s32 i;
    for (i = 0; i < 8; i++) {
        if (*slot == 0) {
            if (*(s32 *)(a1 + 0x84) != 0 || *(s32 *)(e + 0x30) != 0) {
                *slot = func_L01_00470150(e + 0x10, a0, *(s32 *)(e + 0x28), -1, *(s32 *)e, -1,
                                          *(f32 *)(e + 0x24) * 210000.0f, *(f32 *)(e + 0x20), *(s32 *)(e + 0x2C), -1, 1.0f, 0, 0);
            }
        }
        slot++;
        e += 0x40;
    }
}
/* localdecomp:end func_L05_00329618 */

INCLUDE_ASM("asm/levels", func_L05_003296F8);

INCLUDE_ASM("asm/levels", func_L05_003298C0);

/* localdecomp:start func_L05_00329A78 */

extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
__asm__(".extern D_L05_001DC8A0, 8");
extern s32 D_L05_001DC8A0[2];

void func_L05_00329A78(s32 a0, Obj329158 *obj) {
    func_L01_00452560(0, 9, D_L05_001DC8A0[obj->table[obj->index]], 1, 0, 0, 0);
}
/* localdecomp:end func_L05_00329A78 */

/* localdecomp:start func_L05_00329AD0 */
extern s32 D_L05_002D3FB0[];
extern u8 *D_001D52FC;

s32 func_L05_00329AD0(void) {
    s32 r = 0;
    if (D_L05_002D3FB0[0] == 9) {
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) r = 1;
    }
    return r;
}
/* localdecomp:end func_L05_00329AD0 */

/* localdecomp:start func_L05_00329B00 */
extern void func_0038D000(void *, void *, void *);
extern s32 *D_L05_0021ED80[];
extern vu0_v4 D_L05_002B2090[];

void func_L05_00329B00(s32 a0, char *a1) {
    u8 *m = (u8 *)a0;
    vu0_v4 *dst = (vu0_v4 *)(D_L05_0021ED80[*(s32 *)(a1 + 0x7C)] + 4);
    vu0_v4 *src = D_L05_002B2090;
    s32 i;
    for (i = 0; i < 7; i++) {
        func_0038D000(dst, src, m + 0xC0);
        vec_add_ab(dst, dst, m + 0x10);
        dst++;
        src++;
    }
}
/* localdecomp:end func_L05_00329B00 */

/* localdecomp:start func_L05_00329B98 */
extern u16 D_001A7466[];
extern void func_L05_00329B00(s32, char *);
void func_L05_00329B98(s32 a0, char *a1) {
    func_L05_00329B00(a0, a1);
    D_001A7466[0] = *(u16 *)(a1 + 124);
}
/* localdecomp:end func_L05_00329B98 */

/* localdecomp:start func_L05_00329BC8 */
extern u8 D_001A4BE0[];
extern s32 *D_L05_0021ED80[];
extern void func_L05_00329B98(s32, char *);
extern void func_L05_00329C88(s32, u8 *);

void func_L05_00329BC8(s32 a0, u8 *a1) {
    u8 *h = D_001A4BE0;
    *(s16 *)(h + 0x212) = 5;
    *(s16 *)(h + 0x214) = 10;
    func_L05_00329B98(a0, (char *)a1);
    if ((s32)*(f32 *)(a1 + 0x164) >= *D_L05_0021ED80[*(s32 *)(a1 + 0x160)] - 2) {
        func_L05_00329C88(a0, a1);
    }
}
/* localdecomp:end func_L05_00329BC8 */

/* localdecomp:start func_L05_00329C58 */
void func_L05_00329C58(s32 arg0, void *arg1) {
    *(s32 *)((u8 *)arg1 + 0x80) = 1;
}
/* localdecomp:end func_L05_00329C58 */

/* localdecomp:start func_L05_00329C68 */
extern void func_L05_00329C88(s32, u8 *);
void func_L05_00329C68(s32 a0, u8 *a1) {
    *(s32 *)(a1 + 128) = 0;
    func_L05_00329C88(a0, a1);
}
/* localdecomp:end func_L05_00329C68 */

/* localdecomp:start func_L05_00329C88 */
/* from rac4-decomp's func_01EFDCD4 */
void func_L05_00329C88(s32 a0, u8 *a1) {
    if (*(s32 *)(a1 + 0x8C) != 0) {
        *(s32 *)(a1 + 0x8C) = 0;
    }
}
/* localdecomp:end func_L05_00329C88 */

INCLUDE_ASM("asm/levels", func_L05_00329CA0);

/* localdecomp:start func_L05_00329DA8 */
typedef struct { s32 e[4]; } S_329DA8;
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern u8 D_001A4C60[];
extern u8 *D_L05_001DFC80;

s32 func_L05_00329DA8(u8 *a0, u8 *a1) {
    s32 *p = (s32 *)(a1 + 0xC0);
    s32 *q = p;
    s32 i;
    s32 best;
    f32 bd;
    for (i = 0; i < 4; i++) {
        if (*q != -1) {
            if (func_00382380(D_001A4C60, *q, 0) != 0) {
                return i;
            }
        }
        q++;
    }
    bd = 9999.0f;
    best = -1;
    for (i = 0; i < 4; i++) {
        s32 t = *(s32 *)(a1 + 0x90 + i * 4);
        if (t != -1) {
            f32 d = func_0038CF00(D_001A4C60, D_L05_001DFC80 + (t << 7) + 0x30);
            if (d < bd) {
                bd = d;
                best = i;
            }
        }
    }
    if (((S_329DA8 *)p)->e[best] != -1) {
        return *(s32 *)(a1 + 0x15C);
    }
    return best;
}
/* localdecomp:end func_L05_00329DA8 */

INCLUDE_ASM("asm/levels", func_L05_00329ED0);

INCLUDE_ASM("asm/levels", func_L05_0032A0B0);

INCLUDE_ASM("asm/levels", func_L05_0032A238);

INCLUDE_ASM("asm/levels", func_L05_0032A360);
