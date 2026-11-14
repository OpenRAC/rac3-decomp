/* near miss (levels 40-53): c13's draft (2026-11-14, 168 rows) taken to 11 aligned rows by c18 (2026-11-14) under -mvu0-use-vf0-vf2 @ps2as and SPLIT addresses (check.py --mode S; the file's -mno-split-addresses gives ~20 more rows: retail's `lui $v0; lwc1 -0x4658($v0)`, `lui $v0; lw 0x5df8($v0)` and the la+addu+lw table reads are split-mode code), so landing needs a file cut giving this function its own S-mode file (the file's later C keeps -mno-split-addresses). c18's changes: each exit writes the done tail inline and the end is `if (0x539) tail else 003EFD50` (no goto; the exits keep their own 004450F0 calls); the dead float compare is `t = S32(s,0x2C0)` in two identical arms (cross-jumped) before one call; the two 0x50 stores share an s32 local (sh first); 0.010053097f/0.00083775813f literals; the gp slots named by their level-40 addresses (D_L40_00246D8C..., lesson 45; with _sda names only level 40 can match), D_001DB714..728 split into six scalars; func_0038CF38(...) > F32(s,0xA4)*2 (call first) and F32(g,0x18) > F32(s,0x260); g + 0x10 in a local p in cases 23-else/25 (retail's $s4/$s1); case 22's three func_L01_004450F0 calls; qzero through a static inline helper so the two case-25 qzero merge (asm line); D_L40_00242960 declared u8[8] with an .extern 16 hint (one la: retail's nop delay slot); D_001A5DF8 as an array; the 0x90 store as a member access; case 3 copies b then a; case 28's two vectors as one array v[2] (stack slots 0xa0/0xb0); prototypes func_L01_00448728(void *, f32, void *, f32, f32, f32, s32), func_L01_0045A898(u8 *, f32, void *). Left (11 rows): the dead compare loads its zero first (our mtc1 $f1 before lwc1; retail lwc1 $f1, mtc1 $f2, nop: 5 rows; insn 225 is the zero, scheduled before the load by LUID), the jump table's %hi/%lo (2: check.py does not resolve the .data table; check in the full build), and one `lw $v0, ($v1)` issued a slot early in each table read (4). */
#include "common.h"

/* localdecomp:start func_L40_003EFDE0 */
#include "vu0.h"

#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))

__asm__(".extern D_L40_00246E18, 4");
extern f32 D_L40_00246E18;
__asm__(".extern D_L40_00246E0C, 4");
extern f32 D_L40_00246E0C;
__asm__(".extern D_L40_00246D8C, 4");
extern s32 D_L40_00246D8C;
__asm__(".extern D_L40_00246E24, 4");
extern s32 D_L40_00246E24;
__asm__(".extern D_L40_00246E28, 4");
extern s32 D_L40_00246E28;
__asm__(".extern D_L40_00246E2C, 4");
extern s32 D_L40_00246E2C;
__asm__(".extern D_L40_00246E30, 4");
extern s32 D_L40_00246E30;
__asm__(".extern D_L40_00246E34, 4");
extern s32 D_L40_00246E34;
__asm__(".extern D_L40_00246E38, 4");
extern s32 D_L40_00246E38;
__asm__(".extern D_L40_00246E3C, 4");
extern f32 D_L40_00246E3C;
__asm__(".extern D_L40_00246E40, 4");
extern f32 D_L40_00246E40;
__asm__(".extern D_L40_00246D9C, 4");
extern f32 D_L40_00246D9C;
__asm__(".extern D_L40_00246E20, 4");
extern f32 D_L40_00246E20;
__asm__(".extern D_L40_0024846C, 4");
extern u8 *D_L40_0024846C;
__asm__(".extern D_L40_00242960, 16");
extern u8 D_L40_00242960[8];
extern f32 D_L40_0025B9A0[];
extern u8 *D_L40_0028FD80[];
extern s32 D_001A5DF8[];

extern void func_L40_003F1568(u8 *);
extern void func_L39_0066C470(s32);
extern void func_L40_0053F6E0(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L40_003F1858(u8 *);
extern s32 func_L40_003F12A0(u8 *, s32);
extern void func_L40_003EDA10(u8 *, u8 *);
extern void func_L40_003ED980(u8 *, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L40_003F1660(u8 *, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern void  func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_0044E1B8(f32, u8 *);
extern void func_003C2F58(void *, s32, void *);
extern u8 *func_00382348(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00565750(u8 *, void *, void *, s32, s32, f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L40_003EEC40(f32, u8 *, void *);
extern void func_L40_003F1958(u8 *);
extern void func_L01_0045A9F0(u8 *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045A898(u8 *, f32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L40_0053F018(u8 *);
extern s32 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, s32, s32, s32, void *);
extern u8 *func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_003EFC00(u8 *);
extern void func_L40_003F0E18(u8 *, s32);
extern void func_L40_003F1688(u8 *);
extern void func_L40_003EFD50(u8 *);
extern void func_L39_005F2FF8(u8 *, s32);

static inline void qz_3EFDE0(u8 *s) { qzero(s + 0x110); }

void func_L40_003EFDE0(u8 *g) {
    u8 *s;
    s32 id;
    vu0_v4 pos;

    if (g == 0) {
        return;
    }
    s = PTR(g, 0x68);
    id = S32(PTR(g, 0x90), 0);
    ((struct { u8 _p[0x18]; s32 v; } *)PTR(g, 0x90))->v = S32(s, 0x2C0);
    F32(g, 0x2C) = F32(PTR(g, 0x24), 0x24) * D_L40_00246E18;
    if (U8(s, 0x3E) == 2) {
        func_L40_003F1568(g);
        func_L39_0066C470(id);
        func_L40_0053F6E0(g);
        func_L01_004450F0(g, 0x25, -1);
        S32(g, 0x98) = 0;
        U16(g, 0x34) = (U16(g, 0x34) | 0x41) & ~0x1000;
        func_L39_005F2FF8(g, 1);
        return;
    }
    if (S32(s, 0x264) == 0x539) {
        func_L40_003F1858(g);
        if (S32(s, 0x2FC) == 1) {
            func_L40_003F1568(g);
            func_L40_0053F6E0(g);
            func_L01_004450F0(g, 0x25, -1);
            S32(g, 0x98) = 0;
            U16(g, 0x34) = (U16(g, 0x34) | 0x41) & ~0x1000;
            func_L39_005F2FF8(g, 1);
            return;
        }
    }
    if (func_L40_003F12A0(g, id) != 0) {
        return;
    }
    if ((u8)(U8(g, 0x20) + 3) < 2 || U8(g, 0x20) == 0x25) {
        return;
    }
    func_L40_003EDA10(g, s);
    {
        s32 t;
        if (F32(g, 0x10) < 0.0f || F32(g, 0x14) < 0.0f) {
            t = S32(s, 0x2C0);
        } else {
            t = S32(s, 0x2C0);
        }
        func_L40_003ED980(g, t);
    }
    {
        s32 k = 0x50;
        S16(g, 0x32) = k;
        U8(g, 0x30) = k;
    }
    pos = *(vu0_v4 *)(g + 0x10);
    switch (U8(g, 0x20)) {
    case 12:
        if (func_L01_004561B8(g)) {
            func_L40_003F1660(g, 6, 0, 8);
        }
        if (S16(s, 0x234) == 1) {
            func_L01_00448728(g + 0xF8, func_0038D160(F32(s, 0x220) - F32(g, 0x10), F32(s, 0x224) - F32(g, 0x14)), s + 0x274, 0.010053097f, 0.00083775813f, 0.50265485f, 0);
            if (func_L01_0044E1B8(D_L40_00246E0C, g)) {
                if (S32(s, 0x264) != 0x539) {
                    vu0_v4 a;
                    vu0_v4 b;
                    vu0_v4 c;
                    vu0_v4 d;
                    s32 x;
                    s32 y;
                    func_003C2F58(g, D_L40_00246D8C, &a);
                    c = *(vu0_v4 *)(s + 0x220);
                    if (S32(s, 0x230) != 0) {
                        u8 *e = func_00382348(S32(s, 0x230));
                        if (e != 0) {
                            func_0038CF68(&d, D_L40_00242960, F32(e, 0x10));
                            vec_add_ab(&c, &c, &d);
                        }
                    }
                    vec_sub_ab(&b, &c, &a);
                    func_0038CF68(&b, &b, 1.2f);
                    x = D_L40_00246E24;
                    y = D_L40_00246E30;
                    if (S32(s, 0x2C0) == 0) {
                        x = D_L40_00246E28;
                        y = D_L40_00246E34;
                    } else if (S32(s, 0x2C0) == 1) {
                        x = D_L40_00246E2C;
                        y = D_L40_00246E38;
                    }
                    func_L39_00565750(g, &a, &b, x, y, 2.0f, D_L40_00246E3C, D_L40_00246E40);
                }
                func_L01_004450F0(g, 0xD, -1);
            }
            if (U8(s, 0x33D) == 1) {
                if (S32(s, 0x2B8) != -1 &&
                    !(func_0038CF38(g + 0x10, D_L40_0028FD80[S32(s, 0x2B8)] + (S32(s, 0x280) * 16 + 0x10)) > 0.2f) &&
                    U8(g, 0x43) != 6) {
                    func_003C3A10(g, 6, 0, 8);
                }
            }
        } else {
            func_L40_003F1660(g, 0, 0, 8);
        }
        if (U16(g, 0x96) >= 0x33) {
            func_L01_004450F0(g, 0xD, -1);
        }
        if (S32(s, 0x354) == 1) {
            s32 sv = S32(s, 0xA8);
            S32(s, 0xA8) = sv | 0x10;
            func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
            S32(s, 0xA8) = sv;
            func_L40_003F1958(g);
        }
        func_L01_0045A9F0(g);
        break;
    case 13:
        if (func_L01_004561B8(g)) {
            if (S16(s, 0x234) == 1) {
                func_003C3A10(g, 7, 0, 0x11);
            } else {
                func_003C3A10(g, 0, 0, 8);
            }
        } else if (U8(g, 0x60) & 2) {
            if (U8(g, 0x42) == 7) {
                func_003C3A10(g, 5, 0, 0x11);
            } else if (U8(g, 0x42) == 5) {
                func_L01_004450F0(g, 0xC, -1);
            }
        }
        if (U16(g, 0x96) >= 0x3F) {
            func_L01_004450F0(g, 0xC, -1);
        }
        if (U8(s, 0x33D) == 1) {
            if (S32(s, 0x2B8) != -1 &&
                !(func_0038CF38(g + 0x10, D_L40_0028FD80[S32(s, 0x2B8)] + (S32(s, 0x280) * 16 + 0x10)) > 0.2f) &&
                U8(g, 0x43) != 6) {
                func_003C3A10(g, 6, 0, 8);
            }
        }
        if (S32(s, 0x354) == 1) {
            s32 sv = S32(s, 0xA8);
            S32(s, 0xA8) = sv | 0x10;
            func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
            S32(s, 0xA8) = sv;
            func_L40_003F1958(g);
        }
        break;
    case 23:
        if (func_L01_004561B8(g)) {
            func_003C3A10(g, 0, 0, 0x11);
        }
        S32(s, 0xA8) |= 5;
        if (S32(s, 0x264) == 0x539) {
            if (S32(s, 0x354) != 0 && D_L40_00246D9C < func_0038CF38(g + 0x10, s + 0x2E0)) {
                s32 sv = S32(s, 0xA8);
                S32(s, 0xA8) = sv | 0x10;
                func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
                S32(s, 0xA8) = sv;
                if (func_0038CF38(g + 0x10, s + 0x2E0) > F32(s, 0xA4) + F32(s, 0xA4)) {
                    func_L01_00448728(g + 0xF8, F32(s, 0x350), s + 0x274, 0.0025132743f, 0.0025132743f, 0.12566371f, 0);
                }
            }
        } else {
            u8 *p = g + 0x10;
            vu0_v4 a = *(vu0_v4 *)p;
            if (S32(s, 0x354) != 0) {
                s32 sv = S32(s, 0xA8);
                S32(s, 0xA8) = sv | 0x10;
                func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
                S32(s, 0xA8) = sv;
                if (func_0038CF38(p, s + 0x2E0) > F32(s, 0xA4) + F32(s, 0xA4)) {
                    func_L01_00448728(g + 0xF8, F32(s, 0x350), s + 0x274, 0.0025132743f, 0.0025132743f, 0.12566371f, 0);
                }
            }
        }
        func_L40_003F1958(g);
        break;
    case 25: {
        u8 *p = g + 0x10;
        vu0_v4 a = *(vu0_v4 *)p;
        if (func_L01_004561B8(g)) {
            func_003C3A10(g, 0, 0, 0x11);
            S32(s, 0x2CC) = 0;
        }
        if (S32(s, 0x264) == 0x539) {
            if (S32(s, 0x354) != 0 && D_L40_00246D9C < func_0038CF38(p, s + 0x2E0)) {
                func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
            } else {
                qz_3EFDE0(s);
            }
        } else if (S32(s, 0x354) != 0) {
            func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
        } else {
            qz_3EFDE0(s);
        }
        func_L40_003F1958(g);
    }
    case 1:
        if (func_L01_004561B8(g) || (U8(g, 0x42) >= 2 && U8(g, 0x43) >= 2)) {
            func_L40_003F1660(g, 0, 0, 0x11);
        }
        break;
    case 3:
        if (S32(g, 0x28) != 0 || g == D_L40_0024846C) {
            vu0_v4 a;
            vu0_v4 b;
            vu0_v4 c;
            s32 sv;
            f32 ang;
            func_L01_0045BD78(g, 0.002f, 0.080000006f, 0.50265485f, 0.50265485f);
            vec_sub_ba(&c, s + 0x390, g + 0x10);
            b = c;
            a = c;
            ang = func_0038D160(F32(s, 0x390) - F32(g, 0x10), F32(s, 0x394) - F32(g, 0x14));
            sv = S32(s, 0xA8);
            S32(s, 0xA8) = sv | 0x14;
            func_L01_0045A898(g, ang, s + 0x390);
            if (F32(g, 0x18) < F32(s, 0x100) + 0.5f) {
                F32(g, 0x18) = F32(s, 0x100) + 0.5f;
            }
            func_L01_00448728(g + 0xF8, ang, s + 0x274, 0.010053097f, 0.010053097f, 0.20943952f, 0);
            if (F32(g, 0x18) < F32(s, 0x398)) {
                F32(g, 0x18) = F32(g, 0x18) + 0.20000002f;
            }
            S32(s, 0xA8) = sv;
        }
        break;
    case 22:
        if (func_L01_004561B8(g) && U8(g, 0x43) != 8) {
            func_003C3A10(g, 8, 0, 8);
        }
        if (S32(s, 0x354) != 0 && D_L40_00246D9C < func_0038CF38(g + 0x10, s + 0x2E0)) {
            s32 sv = S32(s, 0xA8);
            S32(s, 0xA8) = sv | 0x10;
            func_L40_003EEC40(F32(s, 0x350), g, s + 0x2E0);
            S32(s, 0xA8) = sv;
            if (func_0038CF38(g + 0x10, s + 0x2E0) > F32(s, 0xA4) + F32(s, 0xA4)) {
                func_L01_00448728(g + 0xF8, F32(s, 0x350), s + 0x274, 0.0025132743f, 0.0025132743f, 0.12566371f, 0);
            }
        }
        if (U8(g, 0x60) & 2) {
            if ((u32)(S32(s, 0x308) + 1) < 2) {
                if (S32(s, 0x29C) != 0) {
                    func_L01_004450F0(g, 0x17, -1);
                } else {
                    func_L01_004450F0(g, 1, -1);
                }
            } else {
                func_L01_004450F0(g, 0xC, -1);
            }
        }
        break;
    case 28:
        if (func_L01_004561B8(g)) {
            vu0_v4 v[2];
            if (U8(g, 0x43) != 9) {
                func_003C3A10(g, 9, 0, 8);
            }
            v[1] = *(vu0_v4 *)(g + 0x10);
            v[0] = v[1];
            v[1].z += 1.0f;
            v[0].z -= 4.0f;
            if (func_003D3CB0(&v[1], &v[0], 0, g, 0)) {
                F32(s, 0x260) = D_L40_0025B9A0[2];
            } else if (S32(s, 0x2C0) == -1) {
                F32(s, 0x260) = F32(g, 0x18);
            } else {
                F32(s, 0x260) = v[0].z;
            }
            if (func_L40_0053F018(g)) {
                s32 *r = func_L39_0066C2B8();
                if (r == 0) {
                    return;
                }
                *r = func_L39_0066C280(2, id, D_001A5DF8[0], id, r);
            }
        }
        if (F32(g, 0x18) > F32(s, 0x260)) {
            f32 d = D_L40_00246E20 * 0.020000001f;
            if (d < F32(g, 0x18) - F32(s, 0x260)) {
                F32(g, 0x18) = F32(g, 0x18) - d;
            }
        }
        if (U8(g, 0x60) & 2) {
            u8 *o;
            func_L40_003F1568(g);
            func_L40_0053F6E0(g);
            o = func_L01_003303B8(g + 0x10, 0, 5, 5, 5, 10, 10, 3, 1.0f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 0, 0x1010000, 0,
                                  0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            if (o != 0) {
                PTR(o, 0xB8) = g;
            }
            func_L01_004450F0(g, 0x25, -1);
            S32(g, 0x98) = 0;
            U16(g, 0x34) = (U16(g, 0x34) | 0x41) & ~0x1000;
            func_L39_005F2FF8(g, 1);
            return;
        }
        break;
    case 24:
        func_L40_003EFC00(g);
        break;
    }
    if (U8(s, 0x33D) == 1 && S32(s, 0x2B8) == -1) {
        func_L40_003F0E18(g, id);
    }
    func_L40_003F1688(g);
    if ((F32(g, 0x10) < 10.0f || F32(g, 0x14) < 10.0f || F32(g, 0x18) < 10.0f) && U8(g, 0x20) != 0x1C) {
        func_L39_0066C470(id);
    }
    if (S32(s, 0x264) == 0x539) {
        S32(g, 0x98) = 0;
        U16(g, 0x34) = (U16(g, 0x34) | 0x41) & ~0x1000;
        func_L39_005F2FF8(g, 1);
    } else {
        func_L40_003EFD50(g);
    }
}
/* localdecomp:end func_L40_003EFDE0 */
