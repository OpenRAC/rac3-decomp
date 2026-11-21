/* functional: medium. Written from the PAL asm (no draft): the main update of a character moby, a 27-way state switch on m[0x20] (jump table jtbl_002BEB20 read from the level ELF, states 2..28; 3, 13, 14, 22-26 and out-of-range go straight to the common tail) with shared exits written as gotos (chk5c = retail L00332920, timer = L0033292C, a88 = L00333A88, tail = L00333C2C). Callees with fewer parameters than retail passes ($8-$10 left over) follow their matched definitions in the file. The vt "react" sequence (vt+8 with a 1/15 chance, else vt+0xC) is repeated inline as in retail. Verified case by case against the asm; not byte-checked beyond compiling (1423 words differ). Needs Vt00335B98 from the file prelude and "vu0.h" is not required. */
/* localdecomp:start func_L01_003326A8 */
#include "vu0.h"
typedef s32 (*VtPred_003326A8)(u8 *);
typedef void (*VtCall_003326A8)(u8 *, s32, s32);
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003326A8;
extern u8 *D_L01_001E001C;
extern s32 D_L01_001D6694;
extern s32 D_001D545C;
extern u8 D_001CCFD0[];
void func_L01_003326A8(u8 *m)
{
    extern Vt00335B98 *func_L01_0043B568(s32, s32, s32);
    extern s32 func_L01_00333D80(u8 *);
    extern void func_L01_00333F18(u8 *);
    extern s32 func_L01_004561B8(void *);
    extern s32 func_0038CAD0(u8 *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern void func_L01_00445188(u8 *, u8);
    extern s32 func_L01_00335150(u8 *, s32, u8 *, u8 *, s32, u8 *);
    extern s32 func_L01_00335670(u8 *, u8 *, u8 *, u8 *, s32, u8 *, u8 *);
    extern s32 func_L01_00334250(u8 *, u8 *, u8 *, u8 *, s32, u8 *);
    extern s32 func_L01_003352B8(void *, u8 *, u8 *, u8 *);
    extern s32 func_L01_003357C8(u8 *, u8 *, u8 *, u8 *, s32, u8 *, u8 *);
    extern s32 func_L01_00335338(u8 *, u8 *, u8 *, s32, s32, u8 *);
    extern s32 func_L01_00335418(u8 *, u8 *, u8 *, u8 *, s32, u8 *);
    extern s32 func_L01_00335AD0(u8 *, u8 *, u8 *, u8 *, s32, u8 *, void *);
    extern s32 func_L01_00335950(u8 *, u8 *, u8 *, u8 *, s32, u8 *, u8 *);
    extern s32 func_L01_00335D60(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
    extern s32 func_L01_003355B8(u8 *, u8 *, u8 *, u8 *, s32, u8 *);
    extern s32 func_L01_00335C58(u8 *, u8 *, u8 *, u8 *, s32);
    extern int func_L01_00335EC0(u8 *, int);
    extern s32 func_L01_00335EF8(u8 *);
    extern s32 func_L01_00334868(u8 *, u8 *, u8 *, u8 *, void *, u8 *, u8 *);
    extern void func_L01_0032A0C8(void *, u8 *, s32);
    extern void func_L01_0032A118(void *, u8 *, s32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_L01_00456208(u8 *);
    extern void func_L01_00456BD0(void *, s32);
    extern void func_L01_0045A9F0(void *);
    extern void func_L01_0045A898(u8 *, void *, f32);
    extern void func_003A2B68(s32, s32);
    extern void func_003A1798(void);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    Vt00335B98 *vtt;
    u8 *vt, *p, *tgt, *work, *fp, *cfg, *tobj, *cfg2;
    s32 r, st, go, s18, s21, s23, idx, mode;
    f32 d, ang;
    V4_003326A8 sp0, sp1;

    if (func_L01_00333D80(m) != 0) return;
    p = *(u8 **)(m + 0x68);
    vtt = func_L01_0043B568(*(s32 *)(p + 0x40), 4, 0x9C);
    vt = (u8 *)vtt;
    idx = *(s32 *)(p + 0x50);
    if (idx == -1) tgt = 0;
    else tgt = D_L01_001E001C + (idx << 8);
    work = 0;
    if (tgt != 0) work = vtt->fn(tgt);
    s18 = -1;
    if ((s8)p[0x5C] == -1) {
        fp = *(u8 **)(m + 0xB8);
    } else {
        if (*(u8 *)(*(u8 **)(*(u8 **)(m + 0xB8) + 0x68) + 0x98) != 0) func_L01_00333F18(m);
        if ((s8)p[0x5C] != -1) {
            idx = *(s32 *)(p + 0x4C);
            if (idx == -1) fp = 0;
            else fp = D_L01_001E001C + (idx << 8);
        } else {
            fp = *(u8 **)(m + 0xB8);
        }
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
        if ((s8)p[0x5C] != -1) func_L01_00333F18(m);
        goto tail;
    case 4:
        if (func_L01_004561B8(m) != 0) *(s32 *)(p + 0x6C) = *(s16 *)(cfg + 0x8C);
        go = 0;
        if (func_0038CAD0(p + 0x6C) != 0) func_L01_004450F0(m, 0, -1);
        goto tail;
    case 5:
    case 6:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) func_L01_00335150(m, (s32)p, tgt, work, (s32)fp, cfg);
        if (m[0xBC] == 0) func_L01_00335670(m, p, tgt, work, (s32)fp, cfg, vt);
        goto chk5c;
    case 7:
        s21 = 0;
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) {
            m[0xBC] = 0;
            s21 = 1;
        }
        s18 = func_L01_00334250(m, p, tgt, work, (s32)fp, cfg);
        if (*(s32 *)(work + 0x440) != *(s32 *)(work + 0xC0)) func_L01_00445188(m, 0);
        tobj = *(u8 **)(work + 0xC0);
        if (tobj == 0 || tobj[0x20] == 0xFE || tobj[0x20] == 0xFD) s18 = 0;
        if (s18 == 1) {
            if (m[0xBC] == 0) {
                func_L01_003352B8(m, p, tgt, work);
                func_L01_00445188(m, 1);
            } else if (m[0xBC] == 1) {
                func_L01_003357C8(m, p, tgt, work, (s32)fp, cfg, vt);
                if (func_0038CF38(tgt + 0x10, work + 0x400) < 5.0f) func_L01_00445188(m, 2);
            } else if (m[0xBC] == 2) {
                if (*(s32 *)(vt + 0x40) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0x40))(tgt, 1, 8);
                    if (7.0f < func_0038CF38(tgt + 0x10, work + 0x400)) func_L01_00445188(m, 1);
                }
            }
        } else if (s18 == 2 && m[0xBC] == 1) {
            func_L01_003357C8(m, p, tgt, work, (s32)fp, cfg, vt);
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
        if (s18 != 1) goto timer;
        if (p[0x5D] == 0) goto tail;
        goto timer;
    case 8:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) {
            if (cfg[0x13] == 5) func_L01_00335418(m, p, tgt, work, (s32)fp, cfg);
            else func_L01_00335338(m, p, tgt, (s32)work, (s32)fp, cfg);
            *(s32 *)(p + 0x60) = func_00382498(0x3C, 0xB4);
        }
        if (m[0xBC] == 0) {
            if (cfg[0x13] == 5) func_L01_00335AD0(m, p, tgt, work, (s32)fp, cfg, vt);
            else func_L01_00335950(m, p, tgt, work, (s32)fp, cfg, vt);
            goto chk5c;
        }
        if (m[0xBC] == 1) {
            if (*(s32 *)(vt + 0x8) != 0) (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 0, 0x11);
            func_L01_0045A9F0(tgt);
            if (func_0038CAD0(p + 0x60) == 0) goto chk5c;
            if (p[0x5E] != 0) {
                func_L01_004450F0(m, 8, -1);
                goto chk5c;
            }
            m[0xBC] = 0;
            *(s32 *)(p + 0x60) = func_00382498(0x3C, 0xB4);
        }
        goto chk5c;
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
        goto chk5c;
    case 10:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        s21 = 1;
        s18 = func_L01_004561B8(m) != 0 ? 1 : 0;
        s23 = func_L01_00334250(m, p, tgt, work, (s32)fp, cfg);
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
        if (s23 != 1) goto timer;
        if (p[0x5D] == 0) goto tail;
        goto timer;
    case 11:
        s21 = 0;
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) {
            m[0xBC] = 0;
            s21 = 1;
        }
        s18 = func_L01_00334250(m, p, tgt, work, (s32)fp, cfg);
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
        if (s18 != 1) goto timer;
        if (p[0x5D] == 0) goto tail;
        goto timer;
    case 12:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) {
            func_L01_00445188(m, 0);
            func_L01_003355B8(m, p, tgt, work, (s32)fp, cfg);
        }
        s18 = m[0xBC];
        s23 = 1;
        if (s18 == 0) {
            if (func_L01_00456208(m) != 0 || p[0x5D] != 0) {
                if (*(s32 *)(vt + 0x8) != 0 && func_00382468(0xF) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 1, 8);
                } else if (*(s32 *)(vt + 0xC) != 0) {
                    (*(VtCall_003326A8 *)(vt + 0xC))(tgt, 1, 8);
                }
            }
            func_L01_003355B8(m, p, tgt, work, (s32)fp, cfg);
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
            s21 = func_L01_003357C8(m, p, tgt, work, (s32)fp, cfg, vt);
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
            if (func_L01_003357C8(m, p, tgt, work, (s32)fp, cfg, vt) != 2) func_L01_00445188(m, 0);
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (p[0x5D] == 0) goto tail;
        goto timer;
    case 15:
        s21 = 0;
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
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
        goto timer;
    case 16:
        s21 = 0;
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        s18 = 0x14;
        if (func_L01_004561B8(m) != 0) {
            m[0xBC] = 0;
            s18 = 0xA;
        }
        if (m[0xBC] == 0) {
            cfg2 = *(u8 **)(*(u8 **)(m + 0xB8) + 0x68);
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
        goto timer;
    case 17:
        s21 = 0;
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        go = 0;
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(p + 0x6C) = 0;
            m[0xBC] = 0;
        } else if (p[0x78] == 0) {
            m[0xBC] = 2;
        }
        st = m[0xBC];
        s18 = 1;
        if (st == 0) {
            if (*(s32 *)(vt + 0x8) != 0) (*(VtCall_003326A8 *)(vt + 0x8))(tgt, 0, 2);
            if (*(s32 *)(p + 0x6C) != 0) {
                if (func_0038CAD0(p + 0x6C) != 0) m[0xBC] = 1;
            }
            *(V4_003326A8 *)(tgt + 0x10) = *(V4_003326A8 *)(m + 0x10);
            go = 1;
        } else if (st == s18) {
            *(s32 *)(work + 0x1C8) |= 1;
            if (*(s32 *)(vt + 0x24) != 0) (*(VtCall_003326A8 *)(vt + 0x24))(tgt, 0, 8);
            sp1.x = func_0038D098(*(f32 *)(work + 0x484));
            sp1.y = func_0038D0B0(*(f32 *)(work + 0x484));
            sp1.z = 0.0f;
            func_0038CE20(&sp0, &sp1, 10.0f);
            sp0.x = sp0.x + *(f32 *)(tgt + 0x10);
            sp0.y = sp0.y + *(f32 *)(tgt + 0x14);
            sp0.z = sp0.z + *(f32 *)(tgt + 0x18);
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
            s21 = s18;
            if (p[0x5D] == 0) s21 = 0;
        }
        if (s21 != 0) func_L01_0032A0C8(fp, m, 7);
        else func_L01_0032A118(fp, m, 7);
        goto chk5c;
    case 18:
        if (*(s32 *)(vt + 0x6C) != 0 && (*(VtPred_003326A8 *)(vt + 0x6C))(tgt) != 0 && p[0x5D] == 0) goto tail;
        if (func_L01_004561B8(m) != 0) {
            if (*(s32 *)(cfg + 0x64) != -1) m[0xBC] = 0;
            else if (*(s32 *)(cfg + 0x60) == *(s32 *)(cfg + 0x64)) m[0xBC] = 1;
            else m[0xBC] = 0;
        }
        if (m[0xBC] == 0) {
            if (func_L01_00335C58(tgt, work, cfg, vt, 0xA) == 0) m[0xBC] = 1;
        } else if (m[0xBC] == 1) {
            if (*(s32 *)(vt + 0x44) != 0) (*(VtCall_003326A8 *)(vt + 0x44))(tgt, 1, 8);
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (m[0xBC] != 1) goto timer;
        if (p[0x5D] == 0) goto tail;
        goto timer;
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
        if (*(s32 *)(p + 0x40) == 0x1AE6) func_L01_00334250(m, p, tgt, work, (s32)fp, cfg);
        if ((s8)p[0x5C] == -1) goto tail;
        if (func_0038CAD0(p + 0x7C) == 0) goto tail;
        if (p[0x5D] != 0) goto a88;
        (*(VtCall_003326A8 *)(vt + 0x84))(tgt, 1, 8);
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
            else if (*(s32 *)(cfg + 0x60) == *(s32 *)(cfg + 0x64)) m[0xBC] = 1;
            else m[0xBC] = 0;
        }
        if (m[0xBC] == 0) {
            if (func_L01_00335C58(tgt, work, cfg, vt, 0xA) == 0) m[0xBC] = 1;
        } else if (m[0xBC] == 1) {
            if (*(s32 *)(vt + 0x18) != 0) (*(VtCall_003326A8 *)(vt + 0x18))(tgt, 1, 8);
        }
        if ((s8)p[0x5C] == -1) goto tail;
        if (m[0xBC] == 1 && p[0x5D] == 0) goto tail;
        if (func_0038CAD0(p + 0x7C) == 0) goto tail;
        go = 0;
        func_L01_00333F18(m);
        goto tail;
    default:
        goto tail;
    }
chk5c:
    if ((s8)p[0x5C] == -1) goto tail;
timer:
    if (func_0038CAD0(p + 0x7C) == 0) goto tail;
a88:
    go = 0;
    func_L01_00333F18(m);
tail:
    mode = m[0x95];
    if (mode == 1) {
        if (*(s32 *)(D_001CCFD0 + 0x6C) == 0) {
            if (*(s32 *)(D_001CCFD0 + 0x24) == -1) {
                if (*(s32 *)(D_001CCFD0 + 0x94) == 0) {
                    func_003A2B68(*(s32 *)(p + 0x70) + 0x7D0, (s32)m);
                }
            }
        }
        if (*(s16 *)(D_001CCFD0 + 0x76) == 0 && *(s16 *)(D_001CCFD0 + 0x9E) == 3 &&
            *(s16 *)(D_001CCFD0 + 0x98) < 0x1B58) {
            func_003A1798();
            m[0x95] = 2;
        }
    } else if (mode == 2) {
        if (*(s32 *)(D_001CCFD0 + 0x6C) == 0 && *(s32 *)(D_001CCFD0 + 0x24) == -1 &&
            *(s32 *)(D_001CCFD0 + 0x94) == 0) {
            m[0x95] = 0;
        }
    }
    if (tgt != 0) {
        if (cfg != 0 && cfg[0x92] != 0) func_L01_00456BD0(tgt, 1);
    }
    if (go != 0) func_L01_00334868(m, p, tgt, work, fp, cfg, vt);
    if (tgt != 0) *(V4_003326A8 *)(m + 0x10) = *(V4_003326A8 *)(tgt + 0x10);
}
/* localdecomp:end func_L01_003326A8 */
