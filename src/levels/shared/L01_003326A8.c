#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[148];
    u8 *(*fn)(u8 *);
} Vt00335B98;
typedef void (*Fn_335C70)(u8 *);
typedef struct {
    u8 pad[0x1E];
    u16 flags;
} Obj_003378A0;

/* localdecomp:start func_L01_003326A8 */
#include "vu0.h"

typedef s32 (*VtPred_003326A8)(u8 *);
typedef void (*VtCall_003326A8)(u8 *, s32, s32);
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003326A8;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x6C - 0x28];
    s32 f6C;
    u8 pad70[0x76 - 0x70];
    s16 f76;
    u8 pad78[0x94 - 0x78];
    s32 f94;
    s16 f98;
    u8 pad9A[0x9E - 0x9A];
    s16 f9E;
} S_1CCFD0_003326A8;
extern u8 *D_L01_001E001C;
extern s32 D_L01_001D6694;
extern s32 D_001D545C;
extern S_1CCFD0_003326A8 D_001CCFD0;
void func_L01_003326A8(u8 *m)
{
    extern Vt00335B98 *func_L01_0043B568(s32, s32, s32);
    extern s32 func_L01_00333D80(u8 *);
    extern void func_L01_00333F18(u8 *);
    extern s32 func_L01_004561B8(void *);
    extern s32 func_0038CAD0(u8 *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern void func_L01_00445188(u8 *, u8);
    extern s32 func_L01_00335150(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_00335670(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_00334250(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_003352B8(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_003357C8(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_00335338(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_00335418(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_00335AD0(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_00335950(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_00335D60(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_003355B8(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_00335C58(u8 *, u8 *, u8 *, u8 *, s32);
    extern s32 func_L01_00335EC0(u8 *, s32);
    extern s32 func_L01_00335EF8(u8 *);
    extern s32 func_L01_00334868(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern void func_L01_0032A0C8(void *, u8 *, s32);
    extern void func_L01_0032A118(void *, u8 *, s32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_L01_00456208(u8 *);
    extern void func_L01_00456BD0(void *, s32);
    extern s32 func_L01_0045A9F0(void *);
    extern void func_L01_0045A898(u8 *, void *, f32);
    extern void func_003A2B68(s32, u8 *);
    extern s32 func_003A1798(void);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    u8 *vt, *p, *tgt, *work, *fp, *cfg;
    s32 st, go, s18, s21, s23, idx;
    f32 d, ang;
    V4_003326A8 sp0, sp1;

    if (func_L01_00333D80(m) != 0) return;
    p = *(u8 **)(m + 0x68);
    vt = (u8 *)func_L01_0043B568(*(s32 *)(p + 0x40), 4, 0x9C);
    idx = *(s32 *)(p + 0x50);
    if (idx != -1) tgt = D_L01_001E001C + (idx << 8);
    else tgt = 0;
    work = 0;
    if (tgt != 0) work = ((Vt00335B98 *)vt)->fn(tgt);

    if ((s8)p[0x5C] != -1) {
        if (*(u8 *)(*(u8 **)(*(u8 **)(m + 0xB8) + 0x68) + 0x98) != 0) func_L01_00333F18(m);
    }
    if ((s8)p[0x5C] == -1) {
        fp = *(u8 **)(m + 0xB8);
    } else {
        s32 idx2 = *(s32 *)(p + 0x4C);
        if (idx2 != -1) fp = D_L01_001E001C + (idx2 << 8);
        else fp = 0;
    }
    cfg = 0;
    if (fp != 0) cfg = *(u8 **)(fp + 0x68);
    if (tgt != 0) {
        if (*(s32 *)(vt + 0x70) != 0 && (*(VtPred_003326A8 *)(vt + 0x70))(tgt) != 0) return;
    }
    if (D_L01_001D6694 == 2) return;
    if (D_L01_001D6694 == 6 && D_001D545C == 9 && *(s16 *)(tgt + 0xAA) == 0x1AE6 &&
        (u16)(*(u16 *)(m + 0xB2) - 0x3D9) < 2) return;
    go = 1;
    switch (m[0x20]) {
    case 2:
        go = 0;
        if ((s8)p[0x5C] == -1) goto tail;
        func_L01_00333F18(m);
        goto tail;
    case 4:
        if (func_L01_004561B8(m) != 0) *(s32 *)(p + 0x6C) = *(s16 *)(cfg + 0x8C);
        go = 0;
        if (func_0038CAD0(p + 0x6C) != 0) func_L01_004450F0(m, 0, -1);
        goto tail;
    case 5:
    case 6:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) func_L01_00335150(m, p, tgt, work, fp, cfg);
        if (m[0xBC] == 0) func_L01_00335670(m, p, tgt, work, fp, cfg, vt);
    chk5c:
        if ((s8)p[0x5C] == -1) goto tail;
    timer:
        if (func_0038CAD0(p + 0x7C) == 0) goto tail;
        goto a88;
    case 7:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        s21 = 0;
        if (func_L01_004561B8(m) != 0) {
            m[0xBC] = 0;
            s21 = 1;
        }
        s18 = func_L01_00334250(m, p, tgt, work, fp, cfg, vt);
        if (*(s32 *)(work + 0x440) != *(s32 *)(work + 0xC0)) func_L01_00445188(m, 0);
        {
            u8 *tobj = *(u8 **)(work + 0xC0);
            if (tobj == 0 || tobj[0x20] == 0xFE || tobj[0x20] == 0xFD) s18 = 0;
        }
        if (s18 == 1) {
            if (m[0xBC] == 0) {
                func_L01_003352B8(m, p, tgt, work, fp, cfg);
                func_L01_00445188(m, 1);
            } else if (m[0xBC] == 1) {
                func_L01_003357C8(m, p, tgt, work, fp, cfg, vt);
                if (func_0038CF38(tgt + 0x10, work + 0x400) < 5.0f) func_L01_00445188(m, 2);
            } else if (m[0xBC] == 2) {
                if (*(s32 *)(vt + 0x40) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0x40))(tgt, 1, 8);
                    if (7.0f < func_0038CF38(tgt + 0x10, work + 0x400)) func_L01_00445188(m, 1);
                }
            }
        } else if (s18 == 2 && m[0xBC] == 1) {
            func_L01_003357C8(m, p, tgt, work, fp, cfg, vt);
            if (7.0f < func_0038CF38(tgt + 0x10, work + 0x400)) func_L01_00445188(m, 0);
        } else {
            if (s21 == 0 && p[0x5D] == 0) {
                m[0xBC] = 0;
            } else {
                if (*(s32 *)(vt + 0x8) != 0 && func_00382468(0xF) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 1, 8);
                } else if (*(s32 *)(vt + 0xC) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0xC))(tgt, 1, 8);
                }
                m[0xBC] = 0;
            }
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (s18 != 1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
        if (p[0x5D] == 0) goto tail;
        { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
    case 8:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) {
            if (cfg[0x13] == 5) func_L01_00335418(m, p, tgt, work, fp, cfg);
            else func_L01_00335338(m, p, tgt, work, fp, cfg);
            *(s32 *)(p + 0x60) = func_00382498(0x3C, 0xB4);
        }
        if (m[0xBC] == 0) {
            if (cfg[0x13] == 5) func_L01_00335AD0(m, p, tgt, work, fp, cfg, vt);
            else func_L01_00335950(m, p, tgt, work, fp, cfg, vt);
            { if ((s8)p[0x5C] != -1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } } goto tail; }
        }
        if (m[0xBC] == 1) {
            if (*(s32 *)(vt + 0x8) != 0) (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 0, 0x11);
            func_L01_0045A9F0(tgt);
            if (func_0038CAD0(p + 0x60) == 0) { if ((s8)p[0x5C] != -1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } } goto tail; }
            if (p[0x5E] != 0) {
                func_L01_004450F0(m, 8, -1);
                { if ((s8)p[0x5C] != -1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } } goto tail; }
            }
            m[0xBC] = 0;
            *(s32 *)(p + 0x60) = func_00382498(0x3C, 0xB4);
        }
        { if ((s8)p[0x5C] != -1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } } goto tail; }
    case 9:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0 || p[0x5D] != 0) {
            if (*(s32 *)(vt + 0x8) != 0 && func_00382468(0xF) != 0) {
                (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 1, 8);
            } else if (*(s32 *)(vt + 0xC) != 0) {
                (*(VtCall_003326A8 *)(vt + 0xC))(tgt, 1, 8);
            }
        }
        func_L01_0045A9F0(tgt);
        { if ((s8)p[0x5C] != -1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } } goto tail; }
    case 10:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        s21 = 1;
        s18 = func_L01_004561B8(m) != 0 ? s21 : 0;
        s23 = func_L01_00334250(m, p, tgt, work, fp, cfg, vt);
        if (*(s32 *)(vt + 0x40) != 0 && s23 == s21) {
            (*(VtCall_003326A8 *)(vt + 0x40))(tgt, 1, 8);
        } else if (p[0x5D] != 0 || s18 != 0) {
            if (*(s32 *)(vt + 0x8) != 0 && func_00382468(0xF) != 0) {
                (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 1, 8);
            } else if (*(s32 *)(vt + 0xC) != 0) {
                (*(VtCall_003326A8 *)(vt + 0xC))(tgt, 1, 8);
            }
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (s23 != 1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
        if (p[0x5D] == 0) goto tail;
        { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
    case 11:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        s21 = 0;
        if (func_L01_004561B8(m) != 0) {
            m[0xBC] = 0;
            s21 = 1;
        }
        s18 = func_L01_00334250(m, p, tgt, work, fp, cfg, vt);
        if (s18 == 1) {
            func_L01_00335D60(m, p, tgt, work, cfg, vt);
        } else if (p[0x5D] != 0 || s21 != 0) {
            if (*(s32 *)(vt + 0x8) != 0 && func_00382468(0xF) != 0) {
                (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 1, 8);
            } else if (*(s32 *)(vt + 0xC) != 0) {
                (*(VtCall_003326A8 *)(vt + 0xC))(tgt, 1, 8);
            }
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (s18 != 1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
        if (p[0x5D] == 0) goto tail;
        { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
    case 12:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) {
            func_L01_00445188(m, 0);
            func_L01_003355B8(m, p, tgt, work, fp, cfg);
        }
        s18 = m[0xBC];
        if (s18 == 0) {
            if (func_L01_00456208(m) != 0 || p[0x5D] != 0) {
                if (*(s32 *)(vt + 0x8) != 0 && func_00382468(0xF) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 1, 8);
                } else if (*(s32 *)(vt + 0xC) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0xC))(tgt, 1, 8);
                }
            }
            func_L01_003355B8(m, p, tgt, work, fp, cfg);
            d = func_0038CF38(tgt + 0x10, work + 0x400);
            if (7.0f < d) {
                func_L01_00445188(m, 2);
            } else {
                ang = func_0038D160(*(f32 *)(work + 0x4A0) - *(f32 *)(tgt + 0x10),
                                    *(f32 *)(work + 0x4A4) - *(f32 *)(tgt + 0x14));
                ang = func_0038DBA0(*(f32 *)(tgt + 0xF8), ang);
                if (1.3089969f < ang) func_L01_00445188(m, 1);
            }
        } else if (s18 == 1) {
            if (func_L01_00335C58(tgt, work, cfg, vt, 8) == 0) func_L01_00445188(m, 0);
        } else if (s18 == 2) {
            s21 = func_L01_003357C8(m, p, tgt, work, fp, cfg, vt);
            if (func_0038CF38(tgt + 0x10, work + 0x400) < 5.0f) func_L01_00445188(m, 0);
            if (s21 == 1) func_L01_00445188(m, 3);
            else if (s21 == 2) func_L01_00445188(m, 4);
        } else if (s18 == 3) {
            if (*(s32 *)(vt + 0x44) != 0) (*(VtCall_003326A8 *)(vt + 0x44))(tgt, 1, 8);
            if (func_L01_00456208(m) == 0 && p[0x5D] != 0) func_L01_00445188(m, 0);
        } else if (s18 == 4) {
            if (func_L01_00456208(m) != 0 || p[0x5D] != 0) {
                if (*(s32 *)(vt + 0x8) != 0 && func_00382468(0xF) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 1, 8);
                } else if (*(s32 *)(vt + 0xC) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0xC))(tgt, 1, 8);
                }
            }
            if (func_L01_003357C8(m, p, tgt, work, fp, cfg, vt) != 2) func_L01_00445188(m, 0);
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (p[0x5D] == 0) goto tail;
        { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
    case 15:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        s21 = 0;
        s18 = 0x14;
        if (func_L01_004561B8(m) != 0) {
            m[0xBC] = 0;
            s18 = 0xA;
        }
        if (m[0xBC] == 0) {
            if (func_L01_00335C58(tgt, work, cfg, vt, s18) == 0) {
                func_L01_00335EC0(m, *(s32 *)(cfg + 0x78));
                m[0xBC] = 1;
            }
        } else if (m[0xBC] == 1) {
            if (*(s32 *)(vt + 0x14) != 0) (*(VtCall_003326A8 *)(vt + 0x14))(tgt, 0, (s18 * 5 + 2) / 6);
            func_L01_0045A9F0(tgt);
            if (func_L01_00335EF8(m) != 0 || p[0x5D] != 0) {
                s21 = 1;
                m[0xBC] = 2;
                p[0x5D] = s21;
            }
        } else {
            s21 = 1;
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (s21 == 0) goto tail;
        { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
    case 16:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        s21 = 0;
        s18 = 0x14;
        if (func_L01_004561B8(m) != 0) {
            m[0xBC] = 0;
            s18 = 0xA;
        }
        if (m[0xBC] == 0) {
            u8 *cfg2 = *(u8 **)(*(u8 **)(m + 0xB8) + 0x68);
            if (func_L01_00335C58(tgt, work, cfg2[0x8F] == 0 ? cfg : cfg2, vt, s18) == 0) m[0xBC] = 1;
        } else if (m[0xBC] == 1) {
            if (*(s32 *)(vt + 0x10) != 0) (*(VtCall_003326A8 *)(vt + 0x10))(tgt, 1, (s18 * 5 + 2) / 6);
            func_L01_0045A9F0(tgt);
            if (p[0x5D] != 0) {
                s21 = 1;
                m[0xBC] = 2;
            }
        } else {
            s21 = 1;
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (s21 == 0) goto tail;
        { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
    case 17:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        s21 = 0;
        go = 0;
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(p + 0x6C) = 0;
            m[0xBC] = 0;
        } else if (p[0x78] == 0) {
            m[0xBC] = 2;
        }
        st = m[0xBC];
        if (st == 0) {
            if (*(s32 *)(vt + 0x8) != 0) (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 0, 2);
            if (*(s32 *)(p + 0x6C) != 0) {
                if (func_0038CAD0(p + 0x6C) != 0) m[0xBC] = 1;
            }
            *(V4_003326A8 *)(tgt + 0x10) = *(V4_003326A8 *)(m + 0x10);
            go = 1;
        } else {
        s18 = 1;
        if (st == s18) {
            do { *(s32 *)(work + 0x1C8) |= 1; } while (0);
            if (*(s32 *)(vt + 0x24) != 0) (*(VtCall_003326A8 *)(vt + 0x24))(tgt, 0, 8);
            sp1.x = func_0038D098(*(f32 *)(work + 0x484));
            sp1.y = func_0038D0B0(*(f32 *)(work + 0x484));
            sp1.z = 0.0f;
            func_0038CE20(&sp0, &sp1, 10.0f);
            vec_add_ab(&sp0, &sp0, tgt + 0x10);
            func_L01_0045A898(tgt, &sp0, *(f32 *)(work + 0x484));
            d = sp1.x * *(f32 *)(tgt + 0x10) + sp1.y * *(f32 *)(tgt + 0x14);
            if (*(f32 *)(work + 0x480) < d) {
                if (15.0f < *(f32 *)(tgt + 0x18) - *(f32 *)(work + 0x220)) m[0xBC] = 2;
            }
        } else if (st == 2) {
            if (*(s32 *)(vt + 0x48) != 0) (*(VtCall_003326A8 *)(vt + 0x48))(tgt, 1, 2);
            if (p[0x5D] != 0) {
                *(s32 *)(p + 0x6C) = 0;
                m[0xBC] = 3;
            }
        } else if (st == 3) {
            if (*(s32 *)(vt + 0x4C) != 0) (*(VtCall_003326A8 *)(vt + 0x4C))(tgt, 0, 2);
            if (*(s32 *)(p + 0x6C) != 0 && func_0038CAD0(p + 0x6C) != 0) {
                m[0xBC] = 4;
            } else if (*(f32 *)(tgt + 0x18) - *(f32 *)(work + 0x220) < 24.0f) {
                *(s32 *)(p + 0x6C) = func_00382498(1, 10);
            }
        } else if (st == 4) {
            if (*(s32 *)(vt + 0x50) != 0) (*(VtCall_003326A8 *)(vt + 0x50))(tgt, 1, 2);
            if (p[0x5D] != 0) m[0xBC] = 5;
        } else if (st == 5) {
            if (*(s32 *)(vt + 0x54) != 0) (*(VtCall_003326A8 *)(vt + 0x54))(tgt, 0, 2);
            if (*(f32 *)(tgt + 0x18) - *(f32 *)(work + 0x220) < 0.5f) m[0xBC] = 6;
        } else if (st == 6) {
            if (*(s32 *)(vt + 0x58) != 0) (*(VtCall_003326A8 *)(vt + 0x58))(tgt, 1, 2);
            if (p[0x5D]) s21 = s18;
        }
        }
        if (s21 != 0) func_L01_0032A0C8(fp, m, 7);
        else func_L01_0032A118(fp, m, 7);
        { if ((s8)p[0x5C] != -1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } } goto tail; }
    case 18:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) {
            if (*(s32 *)(cfg + 0x64) != -1 || *(s32 *)(cfg + 0x60) != *(s32 *)(cfg + 0x64)) m[0xBC] = 0;
            else m[0xBC] = 1;
        }
        if (m[0xBC] == 0) {
            if (func_L01_00335C58(tgt, work, cfg, vt, 0xA) == 0) m[0xBC] = 1;
        } else if (m[0xBC] == 1) {
            if (*(s32 *)(vt + 0x44) != 0) (*(VtCall_003326A8 *)(vt + 0x44))(tgt, 1, 8);
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (m[0xBC] != 1) { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
        if (p[0x5D] == 0) goto tail;
        { if (func_0038CAD0(p + 0x7C) != 0) { func_L01_00333F18(m); go = 0; } goto tail; }
    case 19:
        if (func_L01_004561B8(m) != 0) (*(VtCall_003326A8 *)(vt + 0x7C))(tgt, 0, 8);
        if ((s8)p[0x5C] == -1) goto tail;
        if (func_0038CAD0(p + 0x7C) == 0) goto tail;
        if (p[0x5D] != 0) goto a88;
        (*(VtCall_003326A8 *)(vt + 0x7C))(tgt, 1, 8);
        goto tail;
    case 20:
        if (func_L01_004561B8(m) != 0) (*(VtCall_003326A8 *)(vt + 0x80))(tgt, 0, 8);
        if ((s8)p[0x5C] == -1) goto tail;
        if (func_0038CAD0(p + 0x7C) == 0) goto tail;
        if (p[0x5D] != 0) goto a88;
        (*(VtCall_003326A8 *)(vt + 0x80))(tgt, 1, 8);
        goto tail;
    case 21:
        if (func_L01_004561B8(m) != 0) (*(VtCall_003326A8 *)(vt + 0x84))(tgt, 0, 8);
        if (*(s32 *)(p + 0x40) == 0x1AE6) func_L01_00334250(m, p, tgt, work, fp, cfg, vt);
        if ((s8)p[0x5C] == -1) goto tail;
        if (func_0038CAD0(p + 0x7C) == 0) goto tail;
        if (p[0x5D] != 0) goto a88;
        (*(VtCall_003326A8 *)(vt + 0x84))(tgt, 1, 8);
        goto tail;
    a88:
        func_L01_00333F18(m);
        go = 0;
        goto tail;
    case 27:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        go = 0;
        if (func_L01_00335C58(tgt, work, cfg, vt, 8) == 0) func_L01_0032A0C8(fp, m, 7);
        else func_L01_0032A118(fp, m, 7);
        if ((s8)p[0x5C] == -1) goto tail;
        if (func_0038CAD0(p + 0x7C) == 0) goto tail;
        func_L01_00333F18(m);
        goto tail;
    case 28:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) {
            if (*(s32 *)(cfg + 0x64) != -1) m[0xBC] = 0;
            else if (*(s32 *)(cfg + 0x60) != *(s32 *)(cfg + 0x64)) m[0xBC] = 0;
            else m[0xBC] = 1;
        }
        if (m[0xBC] == 0) {
            if (func_L01_00335C58(tgt, work, cfg, vt, 0xA) == 0) m[0xBC] = 1;
        } else if (m[0xBC] == 1) {
            if (*(s32 *)(vt + 0x18) != 0) (*(VtCall_003326A8 *)(vt + 0x18))(tgt, 1, 8);
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (m[0xBC] == 1 && p[0x5D] == 0) goto tail;
        if (func_0038CAD0(p + 0x7C) == 0) goto tail;
        func_L01_00333F18(m); go = 0;
        goto tail;
    }
tail:
    switch (m[0x95]) {
    case 1:
        if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0) {
            func_003A2B68(*(s32 *)(p + 0x70) + 0x7D0, m);
        }
        if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 0x1B58) {
            func_003A1798();
            m[0x95] = 2;
        }
        break;
    case 2:
        if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0) {
            m[0x95] = 0;
        }
        break;
    }
    if (tgt != 0) {
        if (cfg != 0 && cfg[0x92] != 0) func_L01_00456BD0(tgt, 1);
    }
    if (go != 0) func_L01_00334868(m, p, tgt, work, fp, cfg, vt);
    if (tgt != 0) *(V4_003326A8 *)(m + 0x10) = *(V4_003326A8 *)(tgt + 0x10);
}
/* localdecomp:end func_L01_003326A8 */

/* localdecomp:start func_L01_00333D80 */
extern u8 *D_L01_001E001C;
s32 func_L01_00333D80(u8 *m)
{
    extern void func_L01_003362B0(u8 *,s32);
    extern void func_L01_004450F0(u8 *,s32,s32);
    extern Vt00335B98 *func_L01_0043B568(s32,s32,s32);
    extern void func_L01_00329F00(u8 *,u8 *);
    u8 *vars;
    u8 *table;
    u8 *child;
    u8 *parent;
    if (m[0x20]==0) {
        u8 *init;
        init=*(u8 **)(m+0x68);
        *(u8 **)(init+0x2C)=init+0x30;
        *(s32 *)(init+0x50)=-1;
        *(s32 *)(init+0x60)=0;
        *(s32 *)(init+0x64)=0;
        *(s32 *)(init+0x68)=0;
        *(s32 *)(init+0x54)=0;
        *(s32 *)(init+0x58)=0;
        ((s8 *)init)[0x5C]=-1;
        init[0x5D]=0;
        init[0x5E]=0;
        init[0x5F]=0;
        if (*(s32 *)(init+0x30)>0) {
            *(s32 *)(init+0x30)=-1;
            init[0x3E]=3;
            func_L01_003362B0(m,0);
        } else {
            func_L01_004450F0(m,1,-1);
        }
        return 1;
    } else if (m[0x20]==1) {
        u8 *base;
        vars=*(u8 **)(m+0x68);
        table=(u8 *)func_L01_0043B568(*(s32 *)(vars+0x40),4,156);
        *(u8 **)(m+0xB8)=D_L01_001E001C+(*(s32 *)(vars+0x44)<<8);
        child=(*(u8 *(**)(u8 *))table)(m);
        base=D_L01_001E001C;
        *(s32 *)(vars+0x50)=(child-base)>>8;
        func_L01_00329F00(base+(*(s32 *)(vars+0x44)<<8),m);
        *(s32 *)(vars+0x4C)=-1;
        parent=*(u8 **)(m+0xB8);
        if (parent!=0 && child!=0) {
            u8 *pv=*(u8 **)(parent+0x68);
            if (pv[0x90]!=0 && *(void (**)(u8 *))(table+0x90)!=0) {
                (*(void (**)(u8 *))(table+0x90))(child);
            }
            *(u16 *)(vars+0x7A)=*(u16 *)((*(u8 *(**)(u8 *))(table+0x94))(child)+0x34);
        }
        func_L01_004450F0(m,2,-1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00333D80 */
