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

/* localdecomp:start func_L05_00329120 */
extern u8 D_001A30B0[];
extern u8 D_L05_001FEEB6_00329120[];
extern s32 func_L01_004AA710_00329120(void *, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_004AAC98_00329120(s32, s32, void *, s32);

void func_L05_00329120(u8 *m, u8 *v) {
    if (*(s16 *)(m + 0xAA) == 0x1C82) {
        if (m[0x20] == 3 && *(f32 *)(v + 0x168) > 0.0f) {
            if (func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                s32 idx = *(s32 *)(v + 0x16C);
                u8 *e = D_001A30B0 + idx * 128;

                if (*(s16 *)(e + 0xCA) == 0) {
                    if (idx != -1) {
                        if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                            func_003A4F28(idx);
                        }
                    }
                    *(s32 *)(v + 0x16C) = -1;
                }
            }
            if (!func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                s32 idx = *(s32 *)(v + 0x16C);

                if (idx != -1) {
                    u8 *e = D_001A30B0 + idx * 128;

                    if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                        return;
                    }
                }
                *(s32 *)(v + 0x16C) = func_003A52A0(1, 4, m);
            }
        } else {
            if (func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                s32 idx = *(s32 *)(v + 0x16C);
                u8 *e = D_001A30B0 + idx * 128;

                if (*(s16 *)(e + 0xCA) == 1) {
                    if (idx != -1) {
                        if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                            func_003A4F28(idx);
                        }
                    }
                    *(s32 *)(v + 0x16C) = -1;
                }
            }
            if (!func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                s32 idx = *(s32 *)(v + 0x16C);

                if (idx != -1) {
                    u8 *e = D_001A30B0 + idx * 128;

                    if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                        return;
                    }
                }
                *(s32 *)(v + 0x16C) = func_003A52A0(0, 4, m);
            }
        }
    } else {
        if (m[0x20] == 3 && *(f32 *)(v + 0x168) > 0.0f) {
            if (!func_L01_004AA710_00329120(m, *(s32 *)(v + 0x16C))) {
                if (D_L05_001FEEB6_00329120[0] != 0xFF) {
                    *(s32 *)(v + 0x16C) = func_L01_004AAC98_00329120(0, 4, m, 0x1626);
                }
            }
        } else {
            s32 idx = *(s32 *)(v + 0x16C);

            if (idx != -1) {
                u8 *e = D_001A30B0 + idx * 128;

                if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            *(s32 *)(v + 0x16C) = -1;
        }
    }
}
/* localdecomp:end func_L05_00329120 */

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

/* localdecomp:start func_L05_003296F8 */
extern s32 *D_L05_0021ED80[];
extern u8 D_L05_002B2100[];
__asm__(".extern D_L05_001DC8D8, 4");
extern s32 D_L05_001DC8D8;
__asm__(".extern D_L05_001DC8DC, 4");
extern s32 D_L05_001DC8DC;
__asm__(".extern D_L05_001DC8E0, 4");
extern s32 D_L05_001DC8E0;
__asm__(".extern D_L05_001DC8E4, 4");
extern f32 D_L05_001DC8E4;

void func_L05_003296F8(u8 *o, u8 *s) {
    s32 old = *(s32 *)(s + 0x88);
    s32 t;
    s32 st;
    s32 i;
    s32 v;
    f32 g;
    u8 *e;
    u8 **slot;
    u8 *x;

    if (*(s32 *)(s + 0x84) != 0) {
        *(s32 *)(s + 0x88) = 2;
    } else {
        *(s32 *)(s + 0x88) = 1;
    }
    t = o[0x20];
    if (t == 2) {
        *(s32 *)(s + 0x88) = 3;
    } else if (t == 3) {
        if (!((s32)*(f32 *)(s + 0x164) < *D_L05_0021ED80[*(s32 *)(s + 0x160)] - 2)) {
            *(s32 *)(s + 0x88) = 3;
        }
    }
    st = *(s32 *)(s + 0x88);
    if (st == old) {
        return;
    }
    switch (st) {
    case 1:
        v = D_L05_001DC8E0;
        e = D_L05_002B2100;
        slot = (u8 **)(s + 0x130);
        for (i = 0; i < 8; i++) {
            if (*(s32 *)(e + 0x30) != 0) {
                x = *slot;
                *(s32 *)(x + 4) = v;
                *(f32 *)(x + 0xC) = *(f32 *)(e + 0x24) * 210000.0f;
            }
            slot++;
            e += 0x40;
        }
        break;
    case 2:
        v = D_L05_001DC8D8;
        e = D_L05_002B2100;
        slot = (u8 **)(s + 0x130);
        for (i = 0; i < 8; i++) {
            if (*(s32 *)(e + 0x30) != 0) {
                x = *slot;
                *(s32 *)(x + 4) = v;
                *(f32 *)(x + 0xC) = *(f32 *)(e + 0x24) * 210000.0f;
            }
            slot++;
            e += 0x40;
        }
        break;
    case 3:
        v = D_L05_001DC8DC;
        g = D_L05_001DC8E4;
        e = D_L05_002B2100;
        slot = (u8 **)(s + 0x130);
        for (i = 0; i < 8; i++) {
            if (*(s32 *)(e + 0x30) != 0) {
                x = *slot;
                *(s32 *)(x + 4) = v;
                *(f32 *)(x + 0xC) = *(f32 *)(e + 0x24) * g * 210000.0f;
            }
            slot++;
            e += 0x40;
        }
        break;
    }
}
/* localdecomp:end func_L05_003296F8 */

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

/* localdecomp:start func_L05_00329CA0 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);

void func_L05_00329CA0(void *a0, u8 *a1, f32 *a2, f32 *a3, f32 *a4) {
    f32 r = func_0038DAB8(*(f32 *)(a1 + 0x150), 0.0418879054f);
    *(f32 *)(a1 + 0x150) = r;
    *a2 = func_0038D0B0(r) * 0.2f;
    *a3 = func_0038D0B0(*(f32 *)(a1 + 0x154)) * 0.0785398185f * func_0038D0B0(*(f32 *)(a1 + 0x158));
    *a4 = func_0038D0B0(*(f32 *)(a1 + 0x154)) * 0.0785398185f * func_0038D098(*(f32 *)(a1 + 0x158));
    *(f32 *)(a1 + 0x154) = func_0038DAB8(*(f32 *)(a1 + 0x154), 0.0244346112f);
    *(f32 *)(a1 + 0x158) = func_0038DAB8(*(f32 *)(a1 + 0x158), 0.0349065885f);
}
/* localdecomp:end func_L05_00329CA0 */

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

/* localdecomp:start func_L05_0032A0B0 */
extern s32 *D_L05_0021ED80[];
extern u8 *D_L05_001DFC80;
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
__asm__(".extern D_L05_001DC8BC, 4");
extern f32 D_L05_001DC8BC;

void func_L05_0032A0B0(u8 *a0, u8 *a1, s32 a2, s32 a3) {
    s32 *tab;
    f32 d;
    s32 off;

    *(s32 *)(a1 + 0x168) = 0;
    qzero(a1 + 0x170);
    *(s32 *)(a1 + 0x160) = a2;
    tab = D_L05_0021ED80[a2];
    if (func_0038CF00(a0 + 0x10, tab + 4) < 0.01f) {
        *(s32 *)(a1 + 0x164) = 0;
        *(vu0_q *)(a1 + 0x180) = *(vu0_q *)(tab + 4);
        *(f32 *)(a1 + 0x18C) = -1.0f;
    } else {
        *(f32 *)(a1 + 0x164) = -1.0f;
        *(vu0_q *)(a1 + 0x180) = *(vu0_q *)(a0 + 0x10);
        *(f32 *)(a1 + 0x18C) = func_0038CF00(a0 + 0x10, tab + 4);
    }
    off = a3 << 7;
    *(vu0_q *)(a1 + 0x190) = *(vu0_q *)((u8 *)(off + (s32)D_L05_001DFC80) + 0x30);
    d = func_0038CF00(D_L05_001DFC80 + off + 0x30, (u8 *)tab + tab[0] * 16);
    {
        f32 c = D_L05_001DC8BC;
        u8 *p = D_L05_001DFC80 + off;
        *(f32 *)((u8 *)tab + ((tab[0] - 1) << 4) + 0x1C) = d;
        func_0038CF68(a1 + 0x1A0, p, c);
    }
    vec_add_ab(a1 + 0x1A0, a1 + 0x1A0, (u8 *)(off + (s32)D_L05_001DFC80) + 0x30);
    d = func_0038CF00(a1 + 0x1A0, D_L05_001DFC80 + off + 0x30);
    {
        f32 t = D_L05_001DC8BC;
        *(f32 *)(a1 + 0x19C) = d;
        *(f32 *)(a1 + 0x1AC) = t;
    }
}
/* localdecomp:end func_L05_0032A0B0 */

INCLUDE_ASM("asm/levels", func_L05_0032A238);

INCLUDE_ASM("asm/levels", func_L05_0032A360);
