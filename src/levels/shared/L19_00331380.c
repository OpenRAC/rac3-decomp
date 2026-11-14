#include "common.h"

typedef struct { u8 pad[0x330]; s32 ids[8]; } Grp_003345D0;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} Obj_003347B0;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} GroupState_00334958;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} Obj_00334B10;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) t1v;
typedef t1v t0v;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00332360;
typedef struct {
    u8 pad0[0x350];
    s32 w350;
    u8 pad354[4];
    u8 *p358;
    u8 pad35C[4];
    s32 w360;
} St_00332360;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0xF];
    unsigned long d30;
    u8 pad38[0x30];
    St_00332360 *p68;
    u8 pad6C[0x29];
    u8 b95;
    u8 pad96[2];
    s32 w98;
    u8 pad9C[0xE];
    s16 hAA;
} Obj_00332360;
typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
    u8 pad25C4[0x286C - 0x25C4];
    s32 w286C;
} Hero_00332360;

INCLUDE_ASM("asm/levels", func_L19_00331380);

INCLUDE_ASM("asm/levels", func_L19_00332948);

/* localdecomp:start func_L19_00332D38 */
/* PAL port of the NTSC-U match src/us/levels/func_L19_00332360.c */


extern Hero_00332360 D_1A4BE0;
extern s32 D_L19_001E8E58_00332360[];
extern f32 func_L01_0040E570(u8 *, u8 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *func_L19_003345D0(u8 *);
extern u8 *func_L19_003347B0(u8 *a0);
extern u8 *func_L19_00334958(u8 *arg0);
extern u8 *func_L19_00334B10(u8 *a0);
extern s32 func_L19_00335130(u8 *a0);
extern void func_L19_00335330(u8 *obj);

void func_L19_00332D38(Obj_00332360 *a) {
    St_00332360 *s;
    s32 mode;
    f32 d;
    u8 *r;
    V4_00332360 va;
    V4_00332360 vb;

    mode = D_1A4BE0.w286C;
    s = a->p68;
    if (mode == 0) {
        return;
    }
    if (a->b20 == 0xC) {
        return;
    }
    if (a->b95 == 7) {
        return;
    }
    if ((a->d30 & 0x104100000000ul) == 0x4100000000ul) {
        if (a->w98 == 0) {
            return;
        }
    }
    if (s->w360 != 0) {
        return;
    }
    if (a->b95 == 4 && mode != 6) {
        return;
    }
    if (a->b95 == 5 && mode != 5) {
        return;
    }
    if (a->b20 == 1) {
        if (s->w350 == 0) {
            return;
        }
        if (mode != 1) {
            return;
        }
        d = func_L01_0040E570((u8 *)&D_1A4BE0 + 0x80, (u8 *)a + 0x10);
        if (d < 144.0f) {
            va = *(V4_00332360 *)((u8 *)a + 0x10);
            vb = *(V4_00332360 *)((u8 *)&D_1A4BE0 + 0x80);
            va.z = va.z + 1.0f;
            vb.z = vb.z + 1.0f;
            if (func_003D3CB0(&va, &vb, 0, a, 0) == 0 || D_L19_001E8E58_00332360[0] == D_1A4BE0.w25C0) {
                func_L01_004450F0(a, 4, 1);
            }
        }
        return;
    }
    switch (mode) {
    case 1:
        if (a->b95 != 1) {
            func_L01_004450F0(a, 3, 1);
        } else if (a->b20 != 3) {
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 3:
        if (a->b95 != 2 && a->hAA == 0x964) {
            func_L01_004450F0(a, 10, 2);
        }
        break;
    case 2:
        if (a->b95 != 0) {
            func_L01_004450F0(a, 2, 0);
        }
        break;
    case 4:
        if (a->hAA == 0x964) {
            s->w360 = 25;
            if (a->b95 != 3) {
                r = func_L19_003345D0(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_004450F0(a, 11, 3);
                }
            }
        }
        break;
    case 6:
        if (a->hAA == 0x940) {
            s->w360 = 25;
            if (a->b95 != 4) {
                r = func_L19_003347B0(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_004450F0(a, 13, 4);
                }
            } else if (a->b20 == 0xD) {
                func_L01_004450F0(a, 4, 1);
            } else if (a->b20 == 0xF) {
                if (func_L19_00335130(a) == 0) {
                    func_L19_00335330(a);
                }
            }
        }
        break;
    case 5:
        if (a->hAA == 0x93C) {
            s->w360 = 25;
            if (a->b95 != 5) {
                r = func_L19_00334958(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_004450F0(a, 17, 5);
                }
            } else if (a->b20 != 0x12) {
                func_L01_00456230(s->p358, 0);
                s->p358 = 0;
                func_L01_004450F0(a, 4, 1);
            }
        }
        break;
    case 7:
        if (a->hAA == 0xA59) {
            s->w360 = 25;
            if (a->b95 != 6) {
                r = func_L19_00334B10(a);
                s->p358 = r;
                if (r != 0) {
                    func_L01_004450F0(a, 19, 6);
                }
            } else if (a->b20 != 0x14) {
                func_L01_00456230(s->p358, 0);
                s->p358 = 0;
                func_L01_004450F0(a, 4, 1);
            }
        }
        break;
    case 8:
        if (a->hAA == 0x964) {
            if (a->b95 != 1) {
                func_L01_004450F0(a, 4, 1);
            }
        } else {
            func_L01_004450F0(a, 6, 1);
        }
        break;
    }
}
/* localdecomp:end func_L19_00332D38 */

INCLUDE_ASM("asm/levels", func_L19_00333160);

INCLUDE_ASM("asm/levels", func_L19_00333468);

/* localdecomp:start func_L19_00333580 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_00332BA8;

extern s32 func_00382380(void *, s32, s32);
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
extern u8 *D_L19_001DF800;
extern s32 D_L19_001DF758 __attribute__((section(".sdata")));

void func_L19_00333580(u8 *arg0, Vec4_00332BA8 v) {
    u8 *s2;
    u16 *s1;
    s32 idx;
    s32 start;
    u8 *ent;
    u8 *s0;
    u8 *m;

    s2 = *(u8 **)(arg0 + 104);
    *(Vec4_00332BA8 *)(s2 + 960) = v;
    start = *(s32 *)(s2 + 912);
    if (start < 0) {
        return;
    }
    for (s1 = D_L19_0021C260[start];
         (idx = *(s32 *)(s2 + 912), (idx & 0xFF) != 255) && D_L19_001DF758 >= idx && s1 != 0 &&
         ((s16)s1[-1] >= 0 || s1 == D_L19_0021C260[idx]);
         s1++) {
        ent = D_L19_001DF71C + ((*s1 & 0x7FFF) << 8);
        if (ent == 0) {
            return;
        }
        s0 = *(u8 **)(ent + 104);
        if (func_00382380(s2 + 960, *(s32 *)s0, 0) != 0) {
            if (*(s32 *)(s0 + 8) < 0 || func_00382380(arg0 + 16, *(s32 *)(s0 + 8), 0) != 0) {
                m = (u8 *)((*(s32 *)(s0 + 4) << 7) + (s32)D_L19_001DF800);
                if (__builtin_fabsf(*(f32 *)(m + 56) - *(f32 *)(arg0 + 24)) < 2.5f) {
                    *(u128_t *)(s2 + 960) = *(u128_t *)(m + 48);
                    return;
                }
            }
        }
    }
}
/* localdecomp:end func_L19_00333580 */

INCLUDE_ASM("asm/levels", func_L19_003336E0);

INCLUDE_ASM("asm/levels", func_L19_003337D8);

INCLUDE_ASM("asm/levels", func_L19_00333A80);

/* localdecomp:start func_L19_00333C60 */
extern s32 func_L01_0045A9F0(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_L19_00333A80(void *, void *);
extern s32 D_001A4CC0[];

void func_L19_00333C60(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    func_L01_0045A9F0(a0);
    if (a0[0x31] == 0) {
        return;
    }
    if (func_0038CAD0(s0 + 0x374) != 0) {
        if (a0[0x95] == 2) {
            *(f32 *)(s0 + 0x378) = func_L01_00443A18(0.08726646f, 1.0471976f);
            *(f32 *)(s0 + 0x37C) = func_003824E0(-0.34906584f, 0.0f);
            *(s32 *)(s0 + 0x374) = func_00382498(25, 37);
            *(s32 *)(s0 + 0x380) = 0;
        } else if (func_00382468(4) == 0) {
            *(s32 *)(s0 + 0x380) = 1;
            *(s32 *)(s0 + 0x374) = func_00382498(150, 250);
        } else {
            *(f32 *)(s0 + 0x378) = func_L01_00443A18(0.08726646f, 0.34906584f);
            *(f32 *)(s0 + 0x37C) = func_003824E0(-0.2617994f, 0.08726646f);
            *(s32 *)(s0 + 0x374) = func_00382498(50, 100);
            *(s32 *)(s0 + 0x380) = 0;
        }
    }
    if (*(s32 *)(s0 + 0x380) != 0) {
        func_L19_00333A80(a0, D_001A4CC0);
    } else {
        f32 u = *(f32 *)(s0 + 0x37C);
        f32 v = *(f32 *)(s0 + 0x378);
        *(f32 *)(s0 + 0x314) = u;
        *(f32 *)(s0 + 0x318) = v;
        *(f32 *)(s0 + 0x294) = u;
        *(f32 *)(s0 + 0x298) = v;
    }
}
/* localdecomp:end func_L19_00333C60 */

INCLUDE_ASM("asm/levels", func_L19_00333DC0);

/* localdecomp:start func_L19_00333FC0 */
extern void func_L01_0044ABD0(void *a, void *b);
extern s32 func_0038CAD0(void *a);
extern void func_L19_003340A0(void *a);
extern void func_L01_0044E850(void *a, void *b, s32 c, f32 d, f32 e);
extern u8 D_001D5470;
__asm__(".extern D_001D5470, 16");

void func_L19_00333FC0(u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    func_L01_0044ABD0(obj, st + 0x70);
    if (*(u16 *)(obj + 0x96) < 0xFFFF) {
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    }
    func_0038CAD0(st + 0x360);
    func_L19_003340A0(obj);
    if (D_001D5470 != 0 && obj[0x20] != 1) {
        *(f32 *)(st + 0x2A0) = 1.75f;
    }
    func_L01_0044E850(obj, st + 0x230, 1, 0.0432f, 0.43200004f);
    func_L01_0044E850(obj, st + 0x2B0, 0, 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L19_00333FC0 */

INCLUDE_ASM("asm/levels", func_L19_003340A0);

INCLUDE_ASM("asm/levels", func_L19_003343A8);

/* localdecomp:start func_L19_003345D0 */
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
extern s32 D_L19_001DF758 __attribute__((section(".sdata")));
extern s32 func_L19_003556B0(u8 *);
extern f32 func_L01_0040E570(u8 *, u8 *);

u8 *func_L19_003345D0(u8 *a0) {
    Grp_003345D0 *o = *(Grp_003345D0 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *best = 0;
    f32 bestd = 225.0f;
    f32 d;
    s32 i;

    for (i = 0; i < 8; i++) {
        for (q = D_L19_0021C260[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (__builtin_fabsf(*(f32 *)(a0 + 0x18) - *(f32 *)(e + 0x18)) < 2.0f) {
                if (*(s16 *)(e + 0xAA) == 0xEF9) {
                    if (func_L19_003556B0(e)) {
                        d = func_L01_0040E570(a0 + 0x10, e + 0x10);
                        if (d < bestd) {
                            bestd = d;
                            best = e;
                        }
                    }
                }
            }
        }
    }
    return best;
}
/* localdecomp:end func_L19_003345D0 */

/* localdecomp:start func_L19_003347B0 */
extern s32 func_L19_0030D8F8(u8 *, u8 *);
extern u8 D_1A4C60[];


u8 *func_L19_003347B0(u8 *a0) {
    Obj_003347B0 *o = *(Obj_003347B0 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    s32 i = 0;

    while (i < 8) {
        u16 **tbl = D_L19_0021C260;
        for (q = tbl[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF &&
             o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == tbl[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (*(s16 *)(e + 0xAA) == 0x97A) {
                if (func_L19_0030D8F8(e, a0 + 0x10))
                    return e;
                if (func_L19_0030D8F8(e, D_1A4C60))
                    return e;
            }
        }
        i++;
    }
    return 0;
}
/* localdecomp:end func_L19_003347B0 */

/* localdecomp:start func_L19_00334958 */
extern s32 func_L07_003BEAB0(void *);
extern f32 func_L01_0040E570(u8 *, u8 *);
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
extern s32 D_L19_001DF758 __attribute__((section(".sdata")));


u8 *func_L19_00334958(u8 *arg0) {
    GroupState_00334958 *o = *(GroupState_00334958 **)(arg0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *best = 0;
    f32 bestd = 196.0f;
    f32 d;
    s32 i;

    for (i = 0; i < 8; i++) {
        for (q = D_L19_0021C260[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (*(u16 *)(e + 0xAA) == 0xE87 || *(u16 *)(e + 0xAA) == 0xE88) {
                if (func_L07_003BEAB0(e)) {
                    d = func_L01_0040E570(arg0 + 0x10, e + 0x10);
                    if (d < bestd) {
                        bestd = d;
                        best = e;
                    }
                }
            }
        }
    }
    return best;
}
/* localdecomp:end func_L19_00334958 */

/* localdecomp:start func_L19_00334B10 */
extern s32 func_L07_003BCDC0(void *);
extern f32 func_L01_0040E570(u8 *, u8 *);


u8 *func_L19_00334B10(u8 *a0) {
    Obj_00334B10 *o = *(Obj_00334B10 **)(a0 + 0x68);
    u16 *q;
    u8 *e;
    u8 *best = 0;
    f32 bestd = 100.0f;
    f32 d;
    s32 c;
    s32 i;

    for (i = 0; i < 8; i++) {
        for (q = D_L19_0021C260[o->ids[i]];
             (o->ids[i] & 0xFF) != 0xFF && o->ids[i] <= D_L19_001DF758 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260[o->ids[i]]);
             q++) {
            e = D_L19_001DF71C + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (e[0x20] == 0xFE)
                continue;
            if (e[0x20] == 0xFD)
                continue;
            c = *(s16 *)(e + 0xAA);
            if (c == 0xB10 || c == 0xF4D) {
                if (c == 0xF4D && func_L07_003BCDC0(e) == 0)
                    continue;
                d = func_L01_0040E570(a0 + 0x10, e + 0x10);
                if (d < bestd) {
                    bestd = d;
                    best = e;
                }
            }
        }
    }
    return best;
}
/* localdecomp:end func_L19_00334B10 */

INCLUDE_ASM("asm/levels", func_L19_00334CF0);

INCLUDE_ASM("asm/levels", func_L19_00334F80);

/* localdecomp:start func_L19_00335130 */
extern s32 D_001A4F3C[];

s32 func_L19_00335130(u8 *a0) {
    u8 *s;
    u16 *p;
    u8 *e;

    if (D_001A4F3C[0] == *(s32 *)(*(u8 **)(a0 + 0x68) + 0x358))
        return 1;
    s = *(u8 **)(a0 + 0x68);
    if (a0[0x21] == 0xFF)
        return 0;
    for (p = D_L19_0021C260[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758 && p != 0 &&
         ((p != 0 && (s16)p[-1] >= 0) || p == D_L19_0021C260[a0[0x21]]);
         p++) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s32 *)(*(u8 **)(e + 0x68) + 0x1C8) == *(s32 *)(s + 0x358))
            return 1;
    }
    return 0;
}
/* localdecomp:end func_L19_00335130 */

/* localdecomp:start func_L19_00335210 */
extern f32 func_L01_0040E570(u8 *, u8 *);
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
extern s32 D_L19_001DF758 __attribute__((section(".sdata")));

int func_L19_00335210(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 d;
    u16 *p;
    u8 *e;

    d = func_L01_0040E570(a0 + 0x10, a1);
    for (p = D_L19_0021C260[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758 && p != 0 &&
         ((p != 0 && (s16)p[-1] >= 0) || p == D_L19_0021C260[a0[0x21]]);
         p++) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 1;
        if (e == a0)
            continue;
        if (*(s32 *)(*(u8 **)(e + 0x68) + 0x358) == *(s32 *)(s + 0x358) &&
            func_L01_0040E570(e + 0x10, a1) < d)
            return 0;
    }
    return 1;
}
/* localdecomp:end func_L19_00335210 */

/* localdecomp:start func_L19_00335330 */
extern void func_L19_0030D9A8(void *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern char D_001A4C60[];


void func_L19_00335330(u8 *obj) {
    t0v t0;
    t1v t1;
    u8 *vars = *(u8 **)(obj + 0x68);
    func_L19_0030D9A8(*(void **)(vars + 0x358), D_001A4C60, &t0);
    t1 = t0;
    t1.z += *(f32 *)(vars + 0x140) + *(f32 *)(vars + 0x144);
    if (func_L01_003FB640(&t1, 0, obj, *(f32 *)(vars + 0x140)) == 0) {
        *(t0v *)(vars + 0x3C0) = t0;
        func_L01_00456230(*(void **)(vars + 0x358), 0);
        *(s32 *)(vars + 0x358) = 0;
        *(s32 *)(obj + 0x98) = (*(s32 **)(obj + 0x24))[4];
        func_L01_004450F0(obj, 0x10, 4);
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 0x11);
        }
    }
}
/* localdecomp:end func_L19_00335330 */
