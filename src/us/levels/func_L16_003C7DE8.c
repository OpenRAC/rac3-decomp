#include "common.h"

/* NTSC-U counterpart of func_L16_003C9768 (src/levels/16_kerwan/L16_003C9768.c) */
#include "vu0.h"
typedef struct { u8 pad0[0x80]; vu0_v4 pos; } H_003C9768;

/* localdecomp:start func_L16_003C7DE8 */
/* func_L16_003C7DE8: Kerwan boss/enemy state machine (7348 bytes, level 16), matched by c5 from the
   retail asm state by state. Needs "-mvu0-use-vf0-vf2 ... @ps2as" on the file and the
   config/levels/divs_nops.txt line "func_L16_003C7DE8 1 0 0 1 0". Notes: the per-case locals
   (e5, ang8/ang8a, k, pp11/pp12) keep each case's own pseudo (lesson 3); the path-node lookups
   are a per-arm macro (NODE) or inline pointer helpers so the base is added first; "cur" is an
   unsigned long so the 0x218/0x214 compare loads with lwu. */
#include "vu0.h"
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388770(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_00452EC8(u8 *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_00448E90(void *);
extern s32 func_L01_00452F60(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_003BDA38(u8 *, s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00452F40(u8 *, s32);
extern s32 func_L01_00400570(void *);
extern f32 func_L01_00436500(void *);
extern s32 func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_L16_003C9AA0(void *);
extern void func_L16_003CA270(u8 *a0);
extern s32  func_L16_003CA308(void *, void *, f32, s32);
extern void func_L16_003CA5C8(void *, f32 *, void *, f32 *, f32);
extern s32 func_L16_003CA720(void *);
extern s32 func_L16_003CA7C8(void *, f32 *);
extern s32 func_L16_003CA820(void *);
extern void *func_L16_003E4D28(void *, f32 *, f32, f32);
extern s32 func_L16_003E5350(void *, f32 *, void *, s32);
extern s32  func_L16_003E53D0(void *, f32, f32 *, void *);
extern s32 func_L16_003E6638(void *, f32 *, f32 *, void *, f32, f32);

extern H_003C9768 D_001A4BE0;
extern s32 D_001A7430[];
extern s32 D_001A73E8[];
extern s16 D_001A4DBC[];
extern u8 D_1A4C60[];
extern s32 D_L16_001DFC40_003C7DE8;
extern u8 *D_L16_001E015C_003C7DE8;
extern f32 D_L16_001DE95C_003C7DE8;
__asm__(".extern D_L16_001DE95C_003C7DE8, 4");
extern f32 D_L16_001DE96C;
__asm__(".extern D_L16_001DE96C, 4");
extern f32 D_L16_001DE970;
__asm__(".extern D_L16_001DE970, 4");
extern f32 D_L16_001DE974;
__asm__(".extern D_L16_001DE974, 4");
extern f32 D_L16_001DE978;
__asm__(".extern D_L16_001DE978, 4");
extern f32 D_L16_001DE97C;
__asm__(".extern D_L16_001DE97C, 4");
extern f32 D_L16_001DE980;
__asm__(".extern D_L16_001DE980, 4");
extern f32 D_L16_001DE984;
__asm__(".extern D_L16_001DE984, 4");
extern f32 D_L16_001DE988;
__asm__(".extern D_L16_001DE988, 4");
extern f32 D_L16_001DE98C;
__asm__(".extern D_L16_001DE98C, 4");
extern s32 D_L16_001DE990;
__asm__(".extern D_L16_001DE990, 4");
extern s32 D_L16_001DE994;
__asm__(".extern D_L16_001DE994, 4");
extern s32 D_L16_001DE998;
__asm__(".extern D_L16_001DE998, 4");
extern s32 D_L16_001DE99C;
__asm__(".extern D_L16_001DE99C, 4");
extern f32 D_L16_001DE9A0;
__asm__(".extern D_L16_001DE9A0, 4");

#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define U32(p, o) (((struct { u8 _p[o]; u32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)
#define P8(p, o) (((struct { u8 _p[o]; u8 *v; } *)(p))->v)
static inline s32 *path_of(u8 *st) { return (s32 *)st + S16(st, 0x21A); }
static inline s32 *path2_of(u8 *st) { return (s32 *)st + (2 - S16(st, 0x212)); }
static inline s32 *ent(u8 *p, s32 i) { return (s32 *)p + i; }
#define NODE(st, s, i) (S16(st, s) != 0 ? D_L16_001E015C_003C7DE8 + (*ent((st) + 0x1FC, S16(st, i)) << 8) \
                                        : D_L16_001E015C_003C7DE8 + (*ent((st) + 0x1F0, S16(st, i)) << 8))

void func_L16_003C7DE8(u8 *arg0) {
    u8 *st;
    u8 *m;
    s32 i, k;
    s32 ok;
    s32 near, go, hit, turn, r, fire, adv, again;
    f32 d, d2, lo, hi, tm, t, tt, ang, spd;
    f32 ang8, rad8, ang8a, rad8a, d5, d52, d9;
    unsigned long cur;
    u8 *e, *e5, *pos;
    void **pp, **pp11, **pp12;
    s32 i11, i12;
    vu0_v4 v0, v10, v20, v30;
    if (func_L01_00448E90(arg0 + 0x10) == 0) {
        return;
    }
    st = P8(arg0, 0x68);
    func_L16_003C9AA0(arg0);
    switch (U8(arg0, 0x95)) {
    case 0:
        break;
    case 1:
        if (func_L01_00452EF0(arg0) != 0) {
            S32(st, 0x220) = D_001A7430[0];
            S32(st, 0x224) = 0;
        }
        break;
    case 2:
        m = P8(arg0, 0x24);
        *(u16 *)(arg0 + 0x34) &= ~0x41;
        *(u16 *)(arg0 + 0x34) |= *(u16 *)(m + 0x44) & 0x1000;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(m + 0x10);
        *(u16 *)(arg0 + 0x34) &= ~0x80;
        break;
    }
    switch (U8(arg0, 0x20)) {
    case 2:
        if (func_L01_00452EC8(arg0) != 0) {
            if (S32(st, 0x1BC) == 2) {
                F32(st, 0x198) = D_L16_001DE95C_003C7DE8;
                if (U8(arg0, 0x43) != 6) {
                    func_003BE4F0(arg0, 6, 0, 12);
                }
            } else if (U8(arg0, 0x43) != 0) {
                func_003BE4F0(arg0, 0, 0, 12);
            }
        }
        func_L16_003CA308(arg0, arg0 + 0x10, F32(arg0, 0xF8), -1);
        func_L01_00441FB8(arg0, 10, 2);
        break;
    case 3:
        if (func_L01_00452EC8(arg0) != 0) {
            if (S32(st, 0x1BC) != 2) {
                if (U8(arg0, 0x43) != 5) {
                    func_003BE4F0(arg0, 5, 0, 20);
                }
                F32(arg0, 0x48) = D_L16_001DE984;
            } else if (U8(arg0, 0x43) != 6) {
                func_003BE4F0(arg0, 6, 0, 12);
            }
        }
        if (U8(arg0, 0x43) == 5) {
            if (func_L01_0044AF40(arg0, D_L16_001DE980) != 0) {
                F32(arg0, 0x48) = D_L16_001DE988;
                S32(st, 0x1BC) = 2;
                S32(st, 0x198) = 0;
            } else if ((U8(arg0, 0x60) & 2) && U8(arg0, 0x42) == U8(arg0, 0x43) && U8(arg0, 0x42) != 6) {
                func_003BE4F0(arg0, 6, 0, 0);
            }
        }
        func_L16_003CA308(arg0, arg0 + 0x10, F32(arg0, 0xF8), -1);
        if (U8(arg0, 0x43) == 6 && U8(arg0, 0x42) == U8(arg0, 0x43)) {
            func_L01_00441FB8(arg0, U8(arg0, 0x94), -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(arg0) != 0) {
            if (S32(st, 0x1BC) != 2 && U8(arg0, 0x43) != 0) {
                func_003BE4F0(arg0, 0, func_0037E1D8(U8(P8(P8(arg0, 0x24), 0x48), 0x10)), 12);
            }
        }
        ok = 0;
        if (S32(st, 0x1BC) == 2 && func_L01_0040C040(arg0 + 0x10, st + 0x260) < 1.0f) {
            ok = 1;
        }
        if (ok) {
            if (U8(arg0, 0x43) != 10) {
                func_003BE4F0(arg0, 10, 0, 12);
            }
            F32(arg0, 0x48) = D_L16_001DE98C;
            S32(st, 0x1BC) = 0;
        }
        if (S32(st, 0x1BC) == 2) {
            func_L16_003CA308(arg0, st + 0x260, func_00388A28(D_001A4BE0.pos.x - F32(arg0, 0x10), D_001A4BE0.pos.y - F32(arg0, 0x14)), -1);
        } else {
            func_L16_003CA308(arg0, arg0 + 0x10, func_00388A28(D_001A4BE0.pos.x - F32(arg0, 0x10), D_001A4BE0.pos.y - F32(arg0, 0x14)), -1);
        }
        if (U8(arg0, 0x43) == 10 && (U8(arg0, 0x60) & 2) && U8(arg0, 0x42) == U8(arg0, 0x43)) {
            func_003BE4F0(arg0, 0, func_0037E1D8(U8(P8(P8(arg0, 0x24), 0x48), 0x10)), 12);
        }
        if (U8(arg0, 0x43) == 0 && U8(arg0, 0x42) == 0) {
            func_L01_00441FB8(arg0, U8(arg0, 0x94), -1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(arg0) != 0) {
            S32(st, 0x198) = 0;
            S32(st, 0x1BC) = 2;
            if (U8(arg0, 0x43) != 6) {
                func_003BE4F0(arg0, 6, 0, 10);
            }
            S32(st, 0x250) = 0;
            F32(st, 0x258) = 1.618f;
            S32(st, 0x254) = 0;
        }
        if (S16(st, 0x218) != 0) {
            e = D_L16_001E015C_003C7DE8 + (S32(path_of(st), 0x1FC) << 8);
        } else {
            e = D_L16_001E015C_003C7DE8 + (S32(path_of(st), 0x1F0) << 8);
        }
        func_003888C8(st + 0x260, st + 0x250, e + 0xC0);
        vec_add_ba(st + 0x260, st + 0x260, e + 0x10);
        func_L16_003CA308(arg0, st + 0x260, func_00388A28(D_001A4BE0.pos.x - F32(arg0, 0x10), D_001A4BE0.pos.y - F32(arg0, 0x14)), -1);
        if (func_L01_0040C040(arg0 + 0x10, st + 0x260) < 5.0f) {
            func_L01_00441FB8(arg0, 7, 2);
        }
        break;
    case 7:
        if (func_L01_00452EC8(arg0) != 0) {
            if (S32(st, 0x1BC) == 2) {
                F32(st, 0x198) = D_L16_001DE95C_003C7DE8;
                if (U8(arg0, 0x43) != 6) {
                    func_003BE4F0(arg0, 6, 0, 12);
                }
            } else if ((S32(st, 0x1B8) == 2 && S32(st, 0x1D4) >= 0x79) || (S32(st, 0x1B8) == 1 && S32(st, 0x1D8) >= 0x79)
                       || S32(st, 0x1B0) != 0) {
                if (U8(arg0, 0x43) != 1) {
                    func_003BE4F0(arg0, 1, 0, 12);
                }
            } else if (U8(arg0, 0x43) != 0) {
                func_003BE4F0(arg0, 0, 0, 12);
            }
        }
        if (U8(arg0, 0x42) == U8(arg0, 0x43) && U8(arg0, 0x42) == 1 && (U8(arg0, 0x60) & 2)) {
            func_003BE4F0(arg0, 0, 0, 12);
            S32(st, 0x1B0) = 0;
        }
        if (S32(st, 0x1B8) == 0) {
            S32(st, 0x1B8) = 2;
        }
        ang = func_00388A28(D_001A4BE0.pos.x - F32(arg0, 0x10), D_001A4BE0.pos.y - F32(arg0, 0x14));
        if (S32(st, 0x1BC) == 2) {
            func_L16_003CA308(arg0, st + 0x260, ang, -1);
        } else {
            func_L16_003CA308(arg0, arg0 + 0x10, ang, -1);
        }
        near = 0;
        if (S32(st, 0x1BC) == 2 && func_L01_0040C040(arg0 + 0x10, st + 0x260) < 1.0f) {
            near = 1;
        }
        go = 0;
        if (S32(st, 0x1B0) == 0) {
            cur = U32(st, 0x218);
            if (cur == U32(st, 0x214) || D_L16_001DE99C < S32(st, 0x1AC)) {
                go = 1;
            }
            if (S32(st, 0x1B8) == 2 && U8(arg0, 0x94) != 5) {
                if (S16(st, 0x216) == 1) {
                    d = func_L01_0040C040(&D_001A4BE0.pos, (S16(st, 0x218) != 0 ? D_L16_001E015C_003C7DE8 + (S32(path_of(st), 0x1FC) << 8)
                                                                                 : D_L16_001E015C_003C7DE8 + (S32(path_of(st), 0x1F0) << 8)) + 0x10);
                    d2 = func_L01_0040C040(&D_001A4BE0.pos, (S16(st, 0x210) == 0 ? D_L16_001E015C_003C7DE8 + (S32(path2_of(st), 0x1F0) << 8)
                                                                                  : D_L16_001E015C_003C7DE8 + (S32(path2_of(st), 0x1FC) << 8)) + 0x10);
                    if (d < d2) {
                        go = 1;
                    }
                } else if (S16(st, 0x212) != 2 - S16(st, 0x216)) {
                    go = 1;
                }
            }
            if (S32(st, 0x190) == 2 && S32(st, 0x1B0) == 0) {
                if ((near && U8(arg0, 0x94) != 5) || S32(st, 0x1BC) == 0) {
                    go = 1;
                }
            }
        }
        hit = 0;
        if (go == 0) {
            if ((S32(st, 0x190) == 1 && near) || (S32(st, 0x190) == 3 && near && func_0037E1D8(2) != 0)) {
                hit = 1;
            }
            if (S32(st, 0x1B0) != 0 && near) {
                hit = 1;
            }
        }
        turn = 0;
        if (go == 0 && hit == 0 && S32(st, 0x1B0) == 0) {
            if (S32(st, 0x1B8) == 2) {
                turn = S32(st, 0x1D4) < 1;
            }
            if (S32(st, 0x1B8) == 1 && S32(st, 0x1D8) <= 0) {
                turn = 1;
            }
            if (func_00389468(ang, F32(arg0, 0xF8)) > 0.017453292f) {
                turn = 0;
            }
            if (S32(st, 0x1BC) == 2) {
                if (S32(st, 0x190) == 1) {
                    turn = 0;
                }
                if (!near && S32(st, 0x1B8) == 2) {
                    turn = 0;
                }
            }
        }
        if (S32(st, 0x224) != 0) {
            func_L01_00441FB8(arg0, 10, -1);
        } else if (hit) {
            func_L01_00441FB8(arg0, 4, -1);
        } else if (go) {
            func_L01_00441FB8(arg0, 5, -1);
        } else if (turn) {
            if (S32(st, 0x1B8) == 2) {
                func_L01_00441FB8(arg0, 8, -1);
            } else if (S32(st, 0x1B8) == 1) {
                func_L01_00441FB8(arg0, 9, -1);
            }
        }
        break;
    case 8:
        if (S32(st, 0x1E0) == 0) {
            r = 0;
            if (S32(st, 0x190) == 3) {
                r = func_0037E1D8(2) != 0;
            }
            S32(st, 0x1DC) = 1;
            S32(st, 0x1E0) = r ? 2 : 3;
            S32(st, 0x1D0) = r;
        }
        if (func_L01_00452EC8(arg0) != 0) {
            if (S32(st, 0x1BC) == 2) {
                if (U8(arg0, 0x43) != 8) {
                    func_003BE4F0(arg0, 8, 0, 12);
                }
            } else if (U8(arg0, 0x43) != 12) {
                func_003BE4F0(arg0, 12, 0, 12);
            }
        }
        if (U8(arg0, 0x42) == U8(arg0, 0x43)) {
            if (S32(st, 0x1C0) == 0 && S32(st, 0x1C4) == 0 && S32(st, 0x1C8) == 0 && S32(st, 0x1CC) == 0) {
                if (func_L01_0044AF40(arg0, S32(st, 0x1BC) == 2 ? 14.0f : 5.0f) != 0) {
                    F32(arg0, 0x48) = S32(st, 0x1D0) != 0 ? D_L16_001DE970 : D_L16_001DE96C;
                    func_003BDA38(arg0, 4, &v10);
                    func_003BDA38(arg0, 5, &v20);
                    vec_add_ab(&v0, &v10, &v20);
                    func_003886E8(&v0, &v0, 0.5f);
                    if (S32(st, 0x1D0) != 0) {
                        P8(st, 0x1C0) = func_L16_003E4D28(arg0, (f32 *)&v0, 0.333f, U8(st, 0x56));
                        P8(st, 0x1C4) = func_L16_003E4D28(arg0, (f32 *)&v0, 0.333f, U8(st, 0x56));
                        P8(st, 0x1C8) = func_L16_003E4D28(arg0, (f32 *)&v0, 0.333f, U8(st, 0x56));
                        P8(st, 0x1CC) = func_L16_003E4D28(arg0, (f32 *)&v0, 0.333f, U8(st, 0x56));
                    } else {
                        P8(st, 0x1C0) = func_L16_003E4D28(arg0, (f32 *)&v0, 1.0f, U8(st, 0x55));
                        P8(st, 0x1C4) = 0;
                        P8(st, 0x1C8) = 0;
                        P8(st, 0x1CC) = 0;
                    }
                } else if (func_L01_0044AF40(arg0, 35.0f) != 0) {
                    if (--S32(st, 0x1E0) == 0) {
                        S32(st, 0x1D4) = D_L16_001DE998;
                        S32(st, 0x1D8) = *(s32 *)(st + 0x1D8) > 0x3B ? *(s32 *)(st + 0x1D8) : 0x3C;
                        S32(st, 0x1B8) = 1;
                        S32(st, 0x1B0) = 1;
                    } else {
                        S32(st, 0x1D4) = 0x3C;
                    }
                    if (F32(st, 0x1A0) < 0.0f) {
                        F32(st, 0x1A0) = 0.0f;
                    }
                    func_L01_00441FB8(arg0, 7, -1);
                }
            } else {
                if (func_L01_0044AF40(arg0, S32(st, 0x1BC) == 2 ? 15.0f : 7.0f) != 0) {
                    func_0039FE80(0, 0, arg0);
                }
                lo = S32(st, 0x1BC) == 2 ? 14.0f : 5.0f;
                hi = S32(st, 0x1BC) == 2 ? 21.0f : 15.0f;
                t = (func_L01_00436500(arg0) - lo) / (hi - lo);
                if (t > 1.0f) {
                    t = 1.0f;
                } else if (t < 0.0f) {
                    t = 0.0f;
                }
                func_003BDA38(arg0, 4, &v10);
                func_003BDA38(arg0, 5, &v20);
                vec_add_ab(&v0, &v10, &v20);
                func_003886E8(&v0, &v0, 0.5f);
                pp = (void **)(st + 0x1C0);
                for (i = 0; i < 4; i++) {
                    if (pp[i] != 0) {
                        func_L16_003E53D0(pp[i], t, (f32 *)&v0, st + 0x240);
                    }
                }
                if (t >= 1.0f || S32(st, 0x1D0) != 0) {
                    for (k = 0; k < (S32(st, 0x1D0) != 0 ? 4 : 1); k++) {
                        if (S32(st, 0x1D0) != 0) {
                            tt = (t - 0.5f) + (t - 0.5f);
                            if (tt < 0.0f || (s32)(tt * 3.0f + 0.1f) < k) {
                                continue;
                            }
                        }
                        if (pp[k] != 0) {
                            func_L16_003E53D0(pp[k], 1.0f, (f32 *)&v0, st + 0x240);
                            vec_sub_ab(&v20, arg0 + 0x10, &D_001A4BE0.pos);
                            if (S32(st, 0x1D0) != 0) {
                                func_00388830(&v20, &v20, func_00388770(&v20) * 0.5f < D_L16_001DE978 ? func_00388770(&v20) * 0.5f : D_L16_001DE978);
                                ang8a = func_0037E2A8();
                                rad8a = func_0037E250(0.0f, D_L16_001DE978);
                                v30.x = func_00388960(ang8a) * rad8a;
                                v30.y = func_00388978(ang8a) * rad8a;
                                v30.z = 0.0f;
                                vec_add_ab(&v20, &v20, &v30);
                            } else {
                                func_00388830(&v20, &v20, func_00388770(&v20) * 0.5f < D_L16_001DE978 ? func_00388770(&v20) * 0.5f : D_L16_001DE978);
                            }
                            vec_add_ab(&v10, &D_001A4BE0.pos, &v20);
                            spd = D_L16_001DE974;
                            if (S32(st, 0x1D0) != 0) {
                                spd *= func_0037E250(0.8f, 1.4f);
                            }
                            tm = func_00388800((u8 *)pp[k] + 0x10, &v10) / spd;
                            func_L16_003CA5C8(arg0, (f32 *)&v10, st + 0x240, (f32 *)&v10, tm);
                            v10.z = F32(NODE(st, 0x214, 0x216), 0x18) + 2.618f;
                            ang8 = func_00388A28(v10.x - F32(arg0, 0x10), v10.y - F32(arg0, 0x14));
                            rad8 = func_00388800((u8 *)pp[k] + 0x10, &v10) / tm;
                            v20.x = func_00388960(ang8) * rad8;
                            v20.y = func_00388978(ang8) * rad8;
                            *(s32 *)&v20.z = 0;
                            v20.z = -fabs_asm(F32(pp[k], 0x18) - v10.z) / tm;
                            vec_add_ab(&v20, &v20, st + 0x240);
                            func_L16_003E5350(pp[k], (f32 *)&v20, st + 0x240, NODE(st, 0x214, 0x216));
                            pp[k] = 0;
                            if (S32(st, 0x1D0) == 0 || k == 3) {
                                F32(arg0, 0x48) = 1.0f;
                            }
                        }
                    }
                }
            }
        }
        func_L16_003CA308(arg0, arg0 + 0x10, F32(arg0, 0xF8), -1);
        break;
    case 9:
        if (S32(st, 0x1E0) == 0) {
            S32(st, 0x1DC) = 0;
            S32(st, 0x1E0) = 4;
        }
        if (S32(st, 0x1DC) == 0) {
            func_L16_003CA720(arg0);
            S32(st, 0x1DC) = 20;
            F32(st, 0x1EC) = D_L16_001DE97C;
        }
        if (func_L01_00452EC8(arg0) != 0) {
            if (S32(st, 0x1BC) == 2) {
                if (U8(arg0, 0x43) != 7) {
                    func_003BE4F0(arg0, 7, 0, 12);
                }
            } else if (U8(arg0, 0x43) != 11) {
                func_003BE4F0(arg0, 11, 0, 12);
            }
            F32(arg0, 0x48) = D_L16_001DE9A0;
        }
        pos = arg0 + 0x10;
        *(vu0_q *)&v0 = *(vu0_q *)pos;
        v0.z += 5.0f;
        F32(st, 0x354) = F32(st, 0x2D4) = -func_00388A28(func_00388800(&v0, &D_001A4BE0.pos), D_001A4BE0.pos.z - v0.z);
        if (S32(st, 0x1BC) == 2) {
            pos = st + 0x260;
            func_L16_003CA308(arg0, pos, func_00388A28(D_001A4BE0.pos.x - F32(arg0, 0x10), D_001A4BE0.pos.y - F32(arg0, 0x14)), -1);
        } else {
            func_L16_003CA308(arg0, pos, F32(arg0, 0xF8), -1);
        }
        fire = 0;
        if (U8(arg0, 0x42) == U8(arg0, 0x43)) {
            if (func_L01_0044AF40(arg0, S32(st, 0x1BC) == 2 ? 8.0f : 6.5f) != 0) {
                func_003BDA38(arg0, 2, &v0);
                fire = 1;
            } else if (func_L01_0044AF40(arg0, 0.5f) != 0) {
                func_003BDA38(arg0, 3, &v0);
                fire = 1;
            }
        }
        if (fire) {
            func_L16_003CA7C8(arg0, (f32 *)&v20);
            vec_sub_ba(&v30, arg0 + 0x10, &v20);
            func_00388830(&v30, &v30, F32(st, 0x1EC));
            vec_add_ab(&v20, &v20, &v30);
            d9 = func_00388800(&v0, &v20) / 0.666666687f;
            func_L16_003CA5C8(arg0, (f32 *)&v20, st + 0x240, (f32 *)&v10, d9);
            func_L16_003E6638(arg0, (f32 *)&v0, (f32 *)&v10, st + 0x240, 0.5f, U8(st, 0x54));
            F32(st, 0x1EC) -= 1.0f;
            if (--S32(st, 0x1DC) == 0) {
                if (--S32(st, 0x1E0) == 0) {
                    S32(st, 0x1D8) = D_L16_001DE994;
                    S32(st, 0x1B8) = 2;
                    S32(st, 0x1D4) = *(s32 *)(st + 0x1D4) > 0x3B ? *(s32 *)(st + 0x1D4) : 0x3C;
                    S32(st, 0x1B0) = 1;
                } else {
                    S32(st, 0x1D8) = 0x5A;
                }
                if (F32(st, 0x1A0) < 0.0f) {
                    F32(st, 0x1A0) = 0.0f;
                }
                func_L01_00441FB8(arg0, 7, -1);
            }
        }
        break;
    case 5:
        adv = 0;
        if (func_L01_00452EC8(arg0) != 0) {
            if (U8(arg0, 0x94) == 4) {
                func_L01_00441FB8(arg0, 7, -1);
            } else if (S32(st, 0x1BC) != 2) {
                func_L01_00441FB8(arg0, 3, -1);
            } else {
                cur = U32(st, 0x210);
                if (cur == U32(st, 0x214)
                    || (S16(st, 0x210) != S16(st, 0x214) && abs_asm(S16(st, 0x212) - S16(st, 0x216)) == 2)
                    || U8(arg0, 0x94) == 3 || U8(arg0, 0x94) == 7) {
                    adv = 1;
                }
                if (U8(arg0, 0x43) != 6) {
                    func_003BE4F0(arg0, 6, func_0037E1D8(U8(P8(P8(arg0, 0x24), 0x60), 0x10)), 12);
                }
            }
        }
        if (S32(st, 0x1B8) == 2) {
            if (adv) {
                if (S32(st, 0x1E8) != 0) {
                    S16(st, 0x218) = 1 - U16(st, 0x214);
                } else {
                    S16(st, 0x218) = U16(st, 0x210);
                }
                if (S16(st, 0x216) == 1) {
                    d5 = func_L01_0040C040(&D_001A4BE0.pos, D_L16_001E015C_003C7DE8 + ((S16(st, 0x218) == 0 ? S32(st, 0x1F0) : S32(st, 0x1FC)) << 8) + 0x10);
                    d52 = func_L01_0040C040(&D_001A4BE0.pos, D_L16_001E015C_003C7DE8 + ((S16(st, 0x218) == 0 ? S32(st, 0x1F8) : S32(st, 0x204)) << 8) + 0x10);
                    S16(st, 0x21A) = d5 < d52 ? 2 : 0;
                } else {
                    S16(st, 0x21A) = 2 - U16(st, 0x216);
                }
                F32(st, 0x250) = S16(st, 0x21A) < S16(st, 0x216) ? 6.0f : -6.0f;
                F32(st, 0x258) = 1.618f;
                S32(st, 0x254) = 0;
                if (S16(st, 0x218) != 0) {
                    e5 = D_L16_001E015C_003C7DE8 + (S32(path_of(st), 0x1FC) << 8);
                } else {
                    e5 = D_L16_001E015C_003C7DE8 + (S32(path_of(st), 0x1F0) << 8);
                }
                func_003888C8(st + 0x260, st + 0x250, e5 + 0xC0);
                vec_add_ba(st + 0x260, st + 0x260, e5 + 0x10);
            }
        } else {
            if (adv) {
                do {
                    S16(st, 0x218) = S32(st, 0x1E8) != 0 ? func_0037E208(0, 1) : 0;
                    S16(st, 0x21A) = func_0037E208(0, 2);
                    F32(st, 0x250) = func_0037E250(-6.0f, 6.0f);
                    F32(st, 0x258) = 1.618f;
                    S32(st, 0x254) = 0;
                    again = 0;
                    if (NODE(st, 0x218, 0x21A) == NODE(st, 0x210, 0x212) || NODE(st, 0x218, 0x21A) == NODE(st, 0x214, 0x216)) {
                        again = 1;
                    }
                    adv = again;
                } while (adv);
            }
            if (S16(st, 0x218) != 0) {
                e5 = D_L16_001E015C_003C7DE8 + (S32(path_of(st), 0x1FC) << 8);
            } else {
                e5 = D_L16_001E015C_003C7DE8 + (S32(path_of(st), 0x1F0) << 8);
            }
            func_003888C8(st + 0x260, st + 0x250, e5 + 0xC0);
            vec_add_ba(st + 0x260, st + 0x260, e5 + 0x10);
        }
        if (S32(st, 0x1BC) == 2) {
            func_L16_003CA308(arg0, st + 0x260, func_00388A28(D_001A4BE0.pos.x - F32(arg0, 0x10), D_001A4BE0.pos.y - F32(arg0, 0x14)), -1);
            if (S32(st, 0x190) != 1 && S32(st, 0x1B8) == 1) {
                func_L01_00441FB8(arg0, 7, -1);
            } else if (func_L01_0040C040(arg0 + 0x10, st + 0x260) < 1.0f) {
                if (S32(st, 0x190) == 1 || (S32(st, 0x190) == 3 && func_0037E1D8(2) != 0)) {
                    func_L01_00441FB8(arg0, 4, -1);
                } else {
                    func_L01_00441FB8(arg0, 7, -1);
                }
            }
        } else {
            func_L16_003CA308(arg0, arg0 + 0x10, F32(arg0, 0xF8), -1);
        }
        break;
    case 10:
        if (func_L01_00452EC8(arg0) != 0) {
            if (S32(st, 0x1BC) == 2) {
                func_L01_00441FB8(arg0, 4, -1);
            } else {
                if (U8(arg0, 0x43) != 2) {
                    func_003BE4F0(arg0, 2, 0, 12);
                }
                S32(st, 0x224) = 0;
                S32(st, 0x1B0) = 0;
                S32(st, 0x1E4) = D_L16_001DE990;
                D_001A73E8[0] = 0;
            }
        }
        if (U8(arg0, 0x43) == 2 && U8(arg0, 0x42) == U8(arg0, 0x43) && (U8(arg0, 0x60) & 2)) {
            func_L01_00441FB8(arg0, 7, -1);
        }
        func_L16_003CA308(arg0, arg0 + 0x10, F32(arg0, 0xF8), -1);
        break;
    case 11:
        if (func_L01_00452EC8(arg0) != 0) {
            pp11 = (void **)(st + 0x1C0);
            for (i11 = 0; i11 < 4; i11++) {
                if (*pp11 != 0) {
                    func_L01_00400570(*pp11);
                    *pp11 = 0;
                }
                pp11++;
            }
            if (S32(st, 0x1BC) == 2) {
                if (U8(arg0, 0x43) != 9) {
                    func_003BE4F0(arg0, 9, 0, 8);
                }
            } else if (U8(arg0, 0x43) != 13) {
                func_003BE4F0(arg0, 13, 0, 8);
            }
        }
        S32(st, 0x19C) = D_L16_001DFC40_003C7DE8 + 2;
        if ((U8(arg0, 0x43) == 9 && func_L01_0044AF40(arg0, 32.0f) != 0)
            || (U8(arg0, 0x43) == 13 && func_L01_0044AF40(arg0, 25.0f) != 0)) {
            switch (U8(arg0, 0x95)) {
            case 1:
                func_L01_00441FB8(arg0, 2, -1);
            case 2:
                func_L01_00441FB8(arg0, 5, -1);
            }
        }
        func_L16_003CA308(arg0, arg0 + 0x10, F32(arg0, 0xF8), -1);
        break;
    case 12:
        if (func_L01_00452EC8(arg0) != 0) {
            pp12 = (void **)(st + 0x1C0);
            for (i12 = 0; i12 < 4; i12++) {
                if (*pp12 != 0) {
                    func_L01_00400570(*pp12);
                    *pp12 = 0;
                }
                pp12++;
            }
            if (U8(arg0, 0x43) != 14) {
                func_003BE4F0(arg0, 14, 0, 12);
            }
        }
        if (func_L01_00452F60(arg0) == 0) {
            D_001A4DBC[0] = 3;
        }
        if ((U8(arg0, 0x60) & 2) && U8(arg0, 0x42) == U8(arg0, 0x43)) {
            S32(arg0, 0x48) = 0;
            func_L01_00452F40(arg0, 1);
        }
        func_L16_003CA308(arg0, arg0 + 0x10, F32(arg0, 0xF8), -1);
        break;
    case 1:
        break;
    }
    func_L16_003CA820(arg0);
    func_L16_003CA270(arg0);
}
/* localdecomp:end func_L16_003C7DE8 */
