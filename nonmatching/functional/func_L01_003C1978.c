/* functional: medium. Hand-translated from the PAL asm block by block (target revalidation, new-target search, level-dependent attack spawn, wobble/angle upkeep, joint drives); every jal appears in retail order with the same args (checked by jal sequence against the compile; 888 words differ in scheduling/duplicated branch tails: retail repeats the b==2/b==3 angle code per branch, C merges it). Register passthrough made explicit (func_L01_004C81F0/004C8258 a1 = target, 3C3830 void). Unsure: func_L01_004501E8 prototype (stack int args 1,-1,0 then 5 float args), and the 20-byte blob copied from D_L01_001DEBF8 to the stack. */
#include "common.h"
/* localdecomp:start func_L01_003C1978 */
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DD6E8;
extern s32 D_L01_001E2200[];
extern s32 D_L01_001E2230;
__asm__(".extern D_L01_001E2230, 4");
extern u8 *D_L01_001EAA18;
extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];
extern u8 D_001A30B0[];
extern u8 D_001A4BE0[];
extern u8 D_L01_001DEBF8[];
typedef struct { u8 b[20]; } Blob20_003C1978;
extern s32 func_L01_003BEA60(void *);
extern s32 func_L01_003BEAA0(void);
extern void func_L01_003C3830(void);
extern void func_L01_004471A8(void *, f32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_004C84D8(void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void *func_L01_003968F8(void *, s32, void *, void *, s32, s32);
extern void func_L01_003C39A8(u8 *);
extern u8 *func_L01_004501E8(void *, void *, void *, s32, s32, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L01_00450010(void *, s32, f32, f32, f32, f32);
extern s32 func_L01_004C8258(void *, void *);
extern void func_L01_004C81F0(void *, void *, s32);
extern s32 func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003A4F28(s32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_003C3748(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_004CB128(void *, void *, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void *func_L01_0035E638(void *, void *, void *, s32, f32);
extern void *func_L01_00344A88(void *, void *, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_003C35A0(void *);
extern s32 func_L01_004AA710(void *, s32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
static __inline__ s32 tgt_ok_003C1978(u8 *t) {
    s32 h;
    if (*(u16 *)(t + 0x34) & 2) return 0;
    if (t[0x20] == 0xFE) return 0;
    if (t[0x20] == 0xFD) return 0;
    if (t[0x31] == 0) return 0;
    if (*(u8 **)(t + 0x24) == 0) return 0;
    if ((*(u8 **)(t + 0x24))[0x46] != 5) return 0;
    h = *(s16 *)(t + 0xAA);
    if (h == 0x1A17 || h == 0x1B27 || h == 0x1AE6 || h == 0x107E || h == 0x1D87) return 0;
    return 1;
}
static __inline__ s32 tgt_atk_003C1978(u8 *m, u8 *t) {
    s32 h;
    if (*(u16 *)(t + 0x34) & 2) return 0;
    if (t[0x20] == 0xFE || t[0x20] == 0xFD) return 0;
    if (m[0x20] == 6) return 0;
    h = *(s16 *)(t + 0xAA);
    if (h == 0x1A17 || h == 0x1AE6 || h == 0x107E || h == 0x1D87) return 0;
    return 1;
}
s32 func_L01_003C1978(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *hero;
    u8 *t;
    u8 *p;
    u8 *o;
    f32 *w;
    s32 lvl, st, b, idx, h;
    vu0_v4 q, q3, q4, dv, out70;
    f32 ang;
    if (v == 0) {
        return 1;
    }
    if (D_L01_001DFB40 < 6) {
        func_L01_003C3830();
    }
    if (!func_L01_003BEA60(m) && !func_L01_003BEAA0()) {
        func_L01_004471A8(m, 0.3f);
    }
    if (func_L01_004CB2D8()) {
        D_L01_001DD6E8 = 0;
        func_L01_004CAB30(m + 0x10, m + 0x10);
    }
    hero = *(u8 **)(D_001A4BE0 + 0x25C0);
    func_L01_004C84D8(hero);
    /* revalidate the stored target and, when it is the shared target, finish it */
    if (*(u8 **)(v + 0x140) != 0) {
        if (!tgt_ok_003C1978(*(u8 **)(v + 0x140))) {
            *(u8 **)(v + 0x140) = 0;
        }
        if (*(u8 **)(v + 0x140) != 0) {
            q = *(vu0_v4 *)(m + 0x10);
            q.z += 0.3f;
            if (func_L01_003FB640(&q, 1, m, 1.0f) && D_L01_001EAA18 == *(u8 **)(v + 0x140) &&
                *(s16 *)(D_L01_001EAA18 + 0xAA) != 0x1A17) {
                h = *(s16 *)(v + 0x15C);
                if (h != -1) {
                    D_L01_001E2200[h] = 0;
                }
                lvl = D_L01_002C5600[D_001425C0[0x57]].unk1;
                if (lvl != 0 && lvl < 4) {
                    o = func_L01_003968F8(m, *(s32 *)(v + 0x308), m + 0x10, hero + 0xC0, 1, 0);
                    if (o != 0) {
                        *(s32 *)(o + 0xB8) = *(s32 *)(m + 0xB8);
                    }
                }
                func_L01_003C39A8(m);
                return 1;
            }
        }
    }
    st = m[0x20];
    if (st == 5 || st == 0xF || st == 0xD) {
        goto blockD;
    }
    if (st == 0xB || *(s32 *)(v + 0x13C) != 0) {
        goto blockD;
    }
    /* look for a new target */
    if (func_L01_003BEAA0() || func_L01_003BEA60(m)) {
        Blob20_003C1978 blob = *(Blob20_003C1978 *)D_L01_001DEBF8;
        *(u8 **)(v + 0x140) = func_L01_004501E8(m + 0x10, m + 0xC0, &out70, 0, 0, 0, 0, &blob, 1, -1, 0,
                                                6.2831855f, 6.2831855f, 20.0f, 0.0f, 0.0f);
    } else {
        q = *(vu0_v4 *)(m + 0x10);
        *(u8 **)(v + 0x140) = func_L01_00450010(&q, 1, 0.34906584f, 30.0f, -1.0f, 0.0872664601f);
    }
    t = *(u8 **)(v + 0x140);
    if (t == 0) {
        goto blockE;
    }
    p = *(u8 **)(t + 0x24);
    if (p == 0 || p[0x46] != 5) {
        goto blockD;
    }
    if (!func_L01_004C8258(hero, t)) {
        goto blockD;
    }
    t = *(u8 **)(v + 0x140);
    if (*(u16 *)(t + 0x34) & 2) {
        goto blockD;
    }
    if (t[0x20] == 0xFE || t[0x20] == 0xFD || m[0x20] == 0xA || m[0x20] == 9 || m[0x20] == 0xB) {
        goto blockD;
    }
    if (*(s16 *)(t + 0xAA) == 0x18AD) {
        goto blockD;
    }
    func_L01_004C81F0(hero, t, 60);
    *(u8 **)(v + 0x1D0) = *(u8 **)(v + 0x140);
    if (func_L01_003BEAA0()) {
        func_L01_004450F0(m, 0xF, -1);
        *(s32 *)(v + 0x340) = 0xFA;
    } else if (func_L01_003BEA60(m)) {
        func_L01_004450F0(m, 0xD, -1);
        *(s32 *)(v + 0x340) = 0xFA;
    } else {
        func_L01_004450F0(m, 5, -1);
        *(s32 *)(v + 0x344) = 0x15E;
    }
    func_003C3A10(m, 3, 0, 8);
    *(f32 *)(m + 0x48) = 3.0f;
blockD:
    t = *(u8 **)(v + 0x140);
    if (t != 0 && !tgt_ok_003C1978(t)) {
        *(u8 **)(v + 0x140) = 0;
    }
blockE:
    if (*(s32 *)(v + 0x13C) == 0) {
        if (m[0x42] == 2 || m[0x20] == 0) {
            *(f32 *)(m + 0x48) = 1.0f;
        } else {
            *(f32 *)(m + 0x48) = 2.0f;
        }
        idx = *(s32 *)(v + 0x318);
        if (idx != -1) {
            u8 *e = D_001A30B0 + idx * 128;
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(v + 0x318) = -1;
    }
    func_L01_00404808(func_L01_003C3748, m);
    lvl = D_L01_002C5600[D_001425C0[0x57]].unk1;
    w = (f32 *)&D_L01_002C5600[D_001425C0[0x57]];
    if ((u32)(lvl - 1) < 3 && (*(s16 *)(v + 0x15E) > 0 || D_L01_001E2230 > 0)) {
        q = *(vu0_v4 *)(m + 0x10);
        *(u8 **)(v + 0x300) = func_L01_00450010(&q, 1, 1.5707964f, 25.0f, -1.0f, -1.0f);
        t = *(u8 **)(v + 0x300);
        if (t == 0 || !func_0038CAD0(v + 0x158)) {
            goto blockF;
        }
        t = *(u8 **)(v + 0x300);
        if (t == 0 || *(u8 **)(t + 0x24) == 0 || (*(u8 **)(t + 0x24))[0x46] != 5 || !tgt_atk_003C1978(m, t)) {
            goto blockF;
        }
        func_003C2F58(m, 8, &q);
        q3 = *(vu0_v4 *)(*(u8 **)(v + 0x300) + 0x10);
        func_L01_004CB128(&q3, *(u8 **)(v + 0x300), 0);
        q3.x += func_003824E0(-0.05f, 0.05f);
        q3.y += func_003824E0(-0.05f, 0.05f);
        q3.z += func_003824E0(-0.05f, 0.05f);
        *(s32 *)(m + 0x98) = 0;
        if (func_003D3CB0(&q, &q3, 0, *(u8 **)(v + 0x300), 0) == 0) {
            dv.x = q3.x - q.x;
            dv.y = q3.y - q.y;
            dv.z = q3.z - q.z;
            func_0038CF68(&dv, &dv, 0.5000001f);
            func_003A52A0(7, 0, m);
            o = func_L01_0035E638(m, &q, &dv, 0x10000, w[0x6C / 4] * 0.0299999993f);
            if (o != 0) {
                *(s32 *)(o + 0xB8) = *(s32 *)(m + 0xB8);
            }
            if (lvl < 3) {
                *(u16 *)(v + 0x15E) = *(u16 *)(v + 0x15E) - 1;
            } else {
                D_L01_001E2230 = D_L01_001E2230 - 1;
            }
            if (lvl == 1) {
                *(s32 *)(v + 0x158) = 0x19;
            } else if (lvl == 2 || lvl == 3) {
                *(s32 *)(v + 0x158) = 0xC;
            }
        }
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    } else if (lvl >= 4 && D_L01_001E2230 > 0 && m[0x20] == 7) {
        f32 r1, r2, r3;
        q = *(vu0_v4 *)(m + 0x10);
        *(u8 **)(v + 0x300) = func_L01_00450010(&q, 1, 1.5707964f, 25.0f, -1.0f, -1.0f);
        t = *(u8 **)(v + 0x300);
        if (t == 0 || !func_0038CAD0(v + 0x158)) {
            goto blockF;
        }
        t = *(u8 **)(v + 0x300);
        if (t == 0 || *(u8 **)(t + 0x24) == 0 || (*(u8 **)(t + 0x24))[0x46] != 5 || !tgt_atk_003C1978(m, t)) {
            goto blockF;
        }
        func_003C2F58(m, 6, &q);
        func_003C2F58(m, 7, &q3);
        q4 = *(vu0_v4 *)(*(u8 **)(v + 0x300) + 0x10);
        func_L01_004CB128(&q4, *(u8 **)(v + 0x300), 0);
        *(s32 *)(m + 0x98) = 0;
        if (func_003D3CB0(&q, &q4, 0, *(u8 **)(v + 0x300), 0) == 0) {
            dv.x = q4.x - q.x;
            dv.y = q4.y - q.y;
            dv.z = q4.z - q.z;
            func_0038CF68(&dv, &dv, 0.5000001f);
            func_003A52A0(8, 0, m);
            if (func_00382468(2)) {
                vu0_v4 *base = &q;
                r1 = func_003824E0(1.0f, 3.0f);
                r2 = func_003824E0(12.0f, 17.0f);
                r3 = func_003824E0(0.5f, 0.9f);
                o = func_L01_00344A88(base, &dv, 0x32, 0x64, 1, 0, 0xFA, *(u8 **)(v + 0x300), r1, r2, r3, w[0x6C / 4] * 0.25f, 0, 1);
            } else {
                r1 = func_003824E0(1.0f, 3.0f);
                r2 = func_003824E0(12.0f, 17.0f);
                r3 = func_003824E0(0.5f, 0.9f);
                o = func_L01_00344A88(&q3, &dv, 0x32, 0x64, 1, 0, 0xFA, *(u8 **)(v + 0x300), r1, r2, r3, w[0x6C / 4] * 0.25f, 0, 1);
            }
            if (o != 0) {
                *(u8 **)(o + 0xB8) = m;
            }
            D_L01_001E2230 = D_L01_001E2230 - 1;
            *(s32 *)(v + 0x158) = (func_00382498(0x50, 0x78) * 5 + 2) / 6;
        }
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    }
blockF:
    if (*(s32 *)(v + 0x13C) == 1) {
        f32 f;
        *(f32 *)(v + 0x154) = func_0038DAB8(*(f32 *)(v + 0x154), *(f32 *)(v + 0x150));
        f = func_0038D0B0(*(f32 *)(v + 0x154));
        f = f * func_003824E0(0.00249999994f, 0.00749999983f);
        *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + f;
        q = *(vu0_v4 *)(m + 0x10);
        q.w = 1.0f;
        if (func_0038DC20(&q, 100.0f) != -1) {
            func_L01_003C35A0(m);
        }
        if (func_L01_004AA710(m, *(s32 *)(v + 0x318)) == 0) {
            *(s32 *)(v + 0x318) = func_003A52A0(9, 4, m);
        }
    }
    if (lvl >= 4) {
        b = m[0x43];
        if (b == 2 || b == 3) {
            q = *(vu0_v4 *)(m + 0xC0);
            *(s32 *)(v + 0x260) = 0;
            ang = -func_0038D160(func_0038CED8(&q), q.z);
            ang = ang + (b == 2 ? -1.39626336f : -0.959931076f);
            *(s32 *)(v + 0x268) = 0;
            *(s32 *)(v + 0x26C) = 0;
            *(f32 *)(v + 0x264) = ang;
            *(vu0_v4 *)(v + 0x2E0) = *(vu0_v4 *)(v + 0x260);
        }
        *(f32 *)(v + 0x2F0) = 0.45f;
        *(f32 *)(v + 0x270) = 0.45f;
        func_L01_0044E850(m, v + 0x200, 4, 0.0144000007f, 0.0288000014f);
        func_L01_0044E850(m, v + 0x280, 5, 0.0144000007f, 0.0288000014f);
        return 0;
    }
    if ((u32)(lvl - 1) < 3) {
        b = m[0x43];
        if (b == 2 || b == 3) {
            q = *(vu0_v4 *)(m + 0xC0);
            *(s32 *)(v + 0x260) = 0;
            ang = -func_0038D160(func_0038CED8(&q), q.z);
            ang = ang + (b == 2 ? -1.39626336f : -0.959931076f);
            *(s32 *)(v + 0x268) = 0;
            *(s32 *)(v + 0x26C) = 0;
            *(f32 *)(v + 0x264) = ang;
        }
        *(f32 *)(v + 0x270) = 1.0f;
        func_L01_0044E850(m, v + 0x200, 9, 0.0144000007f, 0.0288000014f);
    }
    return 0;
}
/* localdecomp:end func_L01_003C1978 */
