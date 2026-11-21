/* functional: high. Hand-written from the PAL retail asm (near miss, 29 of 1122 rows differ: jump-table placement, one addu operand order, register/schedule order in case 1 and 3; no behavioural differences noted by its author). Needs -mvu0-use-vf0-vf2 and @ps2as on the file's flag line (case 3 uses the vec_*_ab/ba helpers from vu0.h, and the file needs a divs_nops line 'func_L04_00313DD0 0 2'). Uses local F32/S32/... access macros as in the draft. */
#include "common.h"
#include "vu0.h"

#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))

extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CBA0(void *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C4138(void *, f32, f32);
extern s32 func_003C4B50(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void (**func_L01_0043B548(s32, s32))();
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_004A3610(void *, void *);
extern void func_L01_0043B510(s32);
extern void func_L01_0041A5B0(s32, s32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_0040E408(void *, void *, f32);
extern void func_L01_004482A0(void *, void *, f32, f32, f32, f32);
extern void func_L01_00448690(void *, s32, f32, f32);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_L02_003E71A8(void *, void *, f32);
extern s32 func_L04_0050CB28(s32, s32);
extern void func_L04_003FDBF0(s32, f32, f32);
extern void func_L04_004B3440(void *, s32, void *, s32, void *);

extern u8 D_001A4BE0[];
extern u8 D_001A4C78[];
extern u8 D_001A7E18[];
extern u8 D_001BBE90[];
extern u8 D_001BBC40[];
extern s32 D_001D545C;
extern s32 D_001D4C38;
extern u8 D_001D5469;
extern f32 D_L04_001DC550;
extern u8 *D_L04_001DFDA0;
extern u8 *D_L04_001DFE80;
extern s32 D_L04_001E2890[];
extern u8 D_L04_001E2840[];
extern u8 *D_L04_0021D3E0[];
extern u8 D_L04_00235770[];
extern u8 D_L04_00236380[];
__asm__(".extern D_L04_001DC550, 4");

static void v3_add_ba(void *d, void *a, void *b) {
    ((f32 *)d)[0] = ((f32 *)a)[0] + ((f32 *)b)[0];
    ((f32 *)d)[1] = ((f32 *)a)[1] + ((f32 *)b)[1];
    ((f32 *)d)[2] = ((f32 *)a)[2] + ((f32 *)b)[2];
}
static void v3_add_ab(void *d, void *a, void *b) {
    ((f32 *)d)[0] = ((f32 *)a)[0] + ((f32 *)b)[0];
    ((f32 *)d)[1] = ((f32 *)a)[1] + ((f32 *)b)[1];
    ((f32 *)d)[2] = ((f32 *)a)[2] + ((f32 *)b)[2];
}
static void v3_sub_ab(void *d, void *a, void *b) {
    ((f32 *)d)[0] = ((f32 *)a)[0] - ((f32 *)b)[0];
    ((f32 *)d)[1] = ((f32 *)a)[1] - ((f32 *)b)[1];
    ((f32 *)d)[2] = ((f32 *)a)[2] - ((f32 *)b)[2];
}

void func_L04_00313DD0(u8 *m) {
    u8 *pv = PTR(m, 0x68);

    if (pv == 0) {
        F32(m, 0xF8) = func_0038DAB8(F32(m, 0xF8), 0.12566371f);
        return;
    }
    if (({ u8 *h = D_001A4BE0; S32(h, 0x25C4); }) != 0x37 && m[0x20] == 3) {
        func_L01_004450F0(m, 1, -1);
        if (D_L04_001E2890[0] != 0) {
            func_L01_003EB5E0(0, 4);
        }
        return;
    }
    switch (m[0x20]) {
    case 0:
        func_L01_00456230(m, 0);
        if (S32(pv, 0x30) > 0) {
            void (**vt)() = func_L01_0043B548(0x19E1, 0x6C);
            S32(pv, 0x30) = -1;
            pv[0x3E] = 8;
            (*vt[0])(m);
            return;
        }
        F32(pv, 0x7C) = F32(m, 0x18);
        qzero(pv + 0x80);
        func_L01_004450F0(m, 1, -1);
        if (F32(pv, 0x40) == 1.0f) {
            F32(m, 0x18) = F32(pv, 0x7C) - 0.5f;
            func_L01_004450F0(m, 5, -1);
            if (S32(pv, 0x30) != 0) {
                func_L01_0043B548(0x19E1, 0x6C)[2](m, 1);
            } else {
                func_L01_00456230(m, 1);
            }
            return;
        }
        F32(pv, 0x40) = 0.0f;
        break;
    case 1:
        if (m < D_L04_001DFDA0 && S32(pv, 0x30) == 0) {
            u16 id = U16(m, 0xB2);
            if (D_L04_00236380[(s16)id + 0x464] != 0) {
                goto open;
            }
            {
                s32 b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                if (id & 1) {
                    if ((b >> 4) & 7) {
                        goto open;
                    }
                } else if (b & 7) {
                open:
                    F32(m, 0x18) = F32(m, 0x18) - 0.5f;
                    func_L01_004450F0(m, 5, -1);
                    F32(pv, 0x40) = 1.0f;
                    if (S32(pv, 0x30) != 0) {
                        func_L01_0043B548(0x19E1, 0x6C)[2](m, 1);
                    } else {
                        func_L01_00456230(m, 1);
                    }
                    return;
                }
            }
        }
        {
            if (func_0038CF38(m + 0x10, D_001A4BE0 + 0x80) < 3.0f && D_001A4BE0[0x121A] == 0 && D_001A4BE0[0x25E4] == 0 &&
                func_0038DBA0(F32(D_001A4BE0, 0x98), func_0038D160(F32(m, 0x10) - F32(D_001A4BE0, 0x80), F32(m, 0x14) - F32(D_001A4BE0, 0x84))) < 19.198622f &&
                fabs_asm(F32(D_001A4BE0, 0x88) - 0.3f - F32(m, 0x18)) < 0.2f && S32(D_001A4BE0, 0x1228) == 9 && S32(D_001A4BE0, 0x1200) != 0 &&
                func_L01_004606E8(0x80, 0xA, 0, 0) != 0 && U32(pv, 0x54) >= 0x1A && F32(m, 0x18) == F32(pv, 0x7C) &&
                F32(pv, 0x40) < 1.0f) {
                s32 ok = 1;
                s32 i;
                u8 *o;
                U32(pv, 0x54) = 0;
                D_L04_001DC550 = 0.0f;
                i = 0;
                o = D_L04_0021D3E0[0];
                while (o != 0) {
                    if (func_003C4B50(o) == 0) {
                        if (PTR(o, 0x24) == 0 || PTR(o, 0x24)[0x46] != 0x16) {
                            if (func_L02_003E71A8(m + 0x10, o + 0x10, 4.5f) != 0) {
                                ok = 0;
                                break;
                            }
                        }
                    }
                    i++;
                    o = D_L04_0021D3E0[i];
                }
                if (ok) {
                    func_L04_0050CB28(0x37, 1);
                    func_L01_003EB438(0, D_L04_001E2840, D_L04_001E2840 + 0x10, 3, 0x96, 0);
                    func_L01_003EB3C0(0, D_L04_001DFE80 + (S32(pv, 0x60) << 7) + 0x70);
                    func_L01_003EB350(0, D_L04_001DFE80 + (S32(pv, 0x60) << 7) + 0x30);
                    func_L04_003FDBF0(0, F32(pv, 0x68), F32(pv, 0x6C));
                    func_L01_004450F0(m, 3, -1);
                    F32(pv, 0x64) = 0.0f;
                    F32(pv, 0x58) = F32(pv, 0x40) * (F32(pv, 0x70) * 6.2831855f);
                    return;
                }
            } else if (F32(pv, 0x40) < 1.0f) {
                U32(pv, 0x54)++;
                func_003C4138(pv + 0x40, 0.0f, 0.02f);
                if (0.0f < F32(pv, 0x40)) {
                    F32(m, 0xF8) = func_0038DB00(F32(m, 0xF8), F32(pv, 0x70) * 6.2831855f / 50.0f);
                }
                F32(m, 0x18) = F32(m, 0x18) + 0.010000001f;
                if (F32(pv, 0x7C) <= F32(m, 0x18)) {
                    F32(m, 0x18) = F32(pv, 0x7C);
                }
            } else if (S32(pv, 0x78) != 0) {
                if (m < D_L04_001DFDA0 && S32(pv, 0x30) == 0 && S32(pv, 0x74) != -1 &&
                    !(D_001BBC40[m[0xB0] + D_001D545C * 16] & 0x80)) {
                    func_L04_004B3440(pv + 0x40, 4, m, 2, D_L04_00235770);
                    func_L01_0043B510(m[0xB0]);
                    if (S32(pv, 0x74) != -1) {
                        u8 *c = D_L04_001DFE80 + (S32(pv, 0x74) << 7);
                        func_L01_004A3610(c + 0x30, c + 0x70);
                    }
                }
                F32(m, 0x18) = F32(m, 0x18) - 0.010000001f;
                if (F32(m, 0x18) <= F32(pv, 0x7C) - 0.5f) {
                    F32(m, 0x18) = F32(pv, 0x7C) - 0.5f;
                }
            }
            {
            u8 *g = D_001A7E18;
            if (U16(g, 0x8A84) == 0 && func_L01_0040E548(m + 0x10, D_001A4BE0 + 0x80) < 9.0f) {
                u32 t = (D_001D4C38 * 5 + 2) / 6;
                u32 cur = U32(g, 0x22C);
                if (t - cur >= 0x385 || cur == 0) {
                    func_L01_0041A5B0(0xB8B, 0x2E);
                    return;
                }
                if (cur < t) {
                    U32(g, 0x22C) = t;
                }
            }
            }
        }
        break;
    case 3: {
        u8 *hero = D_001A4BE0;
        f32 mat[16] __attribute__((aligned(16)));
        vu0_v4 v40, v50, v60, v70, v80, v90, vA0, vB0;
        f32 ang, ang2, z, d, t;

        *(vu0_q *)&v80 = 0;
        {
            u8 *c = D_L04_001E2840;
            v80.z = F32(c, 0x18);
        }
        *(vu0_q *)&v70 = *(vu0_q *)&v80;
        ang = func_0038D160(F32(hero, 0x80) - F32(m, 0x10), F32(hero, 0x84) - F32(m, 0x14));
        if ((func_L01_004606E8(0x80, 6, 0, 0) != 0 && S32(hero, 0x1B8) >= 0x33) || F32(pv, 0x40) == 1.0f) {
            func_L04_0050CB28(0, 1);
            if (S32(pv, 0x78) != 0) {
                func_L01_004450F0(m, 1, -1);
            } else if (F32(pv, 0x40) == 1.0f) {
                {
                    u8 *g = D_001A7E18;
                    if (U16(g, 0x8A84) == 0) {
                        U16(g, 0x8A84) = 1;
                    }
                }
                if (m < D_L04_001DFDA0 && S32(pv, 0x30) == 0) {
                    u16 id;
                    func_L04_004B3440(pv + 0x40, 4, m, 2, D_L04_00235770);
                    func_L01_004450F0(m, 4, -1);
                    id = U16(m, 0xB2);
                    if (id & 1) {
                        u8 *p = &D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                        if (((*p >> 4) & 7) != 7) {
                            *p += 0x10;
                        }
                    } else {
                        u8 *p = &D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                        if ((*p & 7) != 7) {
                            *p += 1;
                        }
                    }
                    func_003A52A0(0, 0, m);
                    if (S32(pv, 0x74) != -1 && !(D_001BBC40[m[0xB0] + D_001D545C * 16] & 0x80)) {
                        func_L04_004B3440(pv + 0x40, 4, m, 2, D_L04_00235770);
                        func_L01_0043B510(m[0xB0]);
                        if (S32(pv, 0x74) != -1) {
                            u8 *c = D_L04_001DFE80 + (S32(pv, 0x74) << 7);
                            func_L01_004A3610(c + 0x30, c + 0x70);
                        }
                    }
                } else {
                    func_L01_004450F0(m, 4, -1);
                    func_003A52A0(0, 0, m);
                }
            }
            if (S32(pv, 0x90) != -1) {
                func_L01_003EB5E0(0, 4);
                func_L01_003EB438(0, D_L04_001E2840, D_L04_001E2840 + 0x10, 2, 0x96, 0);
                func_L01_003EB3C0(0, D_L04_001DFE80 + (S32(pv, 0x90) << 7) + 0x70);
                func_L01_003EB350(0, D_L04_001DFE80 + (S32(pv, 0x90) << 7) + 0x30);
                return;
            }
            func_L01_003EB5E0(0, 4);
            return;
        }
        qzero(&v40);
        v40.x = -F32(hero, 0x2260);
        v40.y = -F32(hero, 0x2264);
        t = func_0038CED8(&v40);
        if (1.0f < t) {
            func_L01_0040E408(&v40, &v40, t);
        }
        func_0038D328(mat, &v70);
        func_0038D028(&v40, &v40, mat);
        v60.x = func_0038D098(F32(PTR(hero, 0x25C0), 0xF8));
        v60.y = func_0038D0B0(F32(PTR(hero, 0x25C0), 0xF8));
        v60.z = 0.0f;
        d = func_0038CE68(pv + 0x80, &v40) - F32(pv, 0x5C);
        if (d > 0.0022f) {
            d = 0.0022f;
        }
        if (d < -0.0022f) {
            d = -0.0022f;
        }
        *(vu0_q *)(pv + 0x80) = *(vu0_q *)&v40;
        F32(pv, 0x5C) = F32(pv, 0x5C) + d;
        if (F32(pv, 0x5C) > 0.07400001f) {
            F32(pv, 0x5C) = 0.07400001f;
        }
        if (F32(pv, 0x5C) < 0.0f) {
            F32(pv, 0x5C) = 0.0f;
        }
        if (fabs_asm(F32(pv, 0x5C)) < 0.00055f) {
            F32(pv, 0x5C) = 0.0f;
        }
        func_0038CF68(&v50, &v60, F32(pv, 0x5C));
        if ((S32(hero, 0xC08) & 2) && PTR(hero, 0x25C0)[0x43] == 0x3F) {
            func_L01_0050FB40(0x3A, 0, 6.0f);
        }
        if (PTR(hero, 0x25C0)[0x43] != 0x3F) {
            u8 *h1 = D_001A4BE0;
            if (S32(h1, 0xC0C) == 0) {
                if (PTR(h1, 0x25C0)[0x42] == 0x3B && fabs_asm(F32(pv, 0x5C)) == 0.0f) {
                    func_L01_0050FB40(0x3A, 0, 12.0f);
                } else if (({ u8 *h2 = D_001A4BE0; PTR(h2, 0x25C0)[0x42]; }) == 0x3A) {
                    if (F32(pv, 0x5C) > 0.0f) {
                        func_L01_0050FB40(0x3B, 0, 12.0f);
                    }
                } else if (({ u8 *h2 = D_001A4BE0; PTR(h2, 0x25C0)[0x42]; }) == 0x3B && F32(pv, 0x5C) > 0.044400007f) {
                    func_L01_0050FB40(0x3C, 0, 12.0f);
                } else if (({ u8 *h3 = D_001A4BE0; PTR(h3, 0x25C0)[0x42]; }) == 0x3C && F32(pv, 0x5C) < 0.029600004f) {
                    func_L01_0050FB40(0x3B, 0, 13.0f);
                }
            }
        }
        {
        u8 *hero = D_001A4BE0;
        z = F32(hero, 0x88);
        v3_add_ba(hero + 0x80, hero + 0x80, &v50);
        ang2 = func_0038D160(F32(hero, 0x80) - F32(m, 0x10), F32(hero, 0x84) - F32(m, 0x14));
        v50.x = func_0038D098(ang2) * 1.05f;
        v50.y = func_0038D0B0(ang2) * 1.05f;
        *(s32 *)&v50.z = 0;
        *(vu0_v4 *)&vB0 = *(vu0_v4 *)(hero + 0x80);
        v3_add_ab(&v80, m + 0x10, &v50);
        v3_sub_ab(&v90, &v80, &vB0);
        *(s32 *)&v90.z = 0;
        vA0.x = -func_0038CED8(&v90);
        func_L01_004482A0(&vA0, &D_L04_001DC550, 0.0f, 0.0216f, 0.43200004f, 0.14000002f);
        func_0038CF68(&v90, &v90, D_L04_001DC550);
        v3_add_ab(hero + 0x80, hero + 0x80, &v90);
        F32(hero, 0x88) = z;
        F32(hero, 0x1A0) = func_0038DAB8(D_001D5469 ? -1.5707964f : 1.5707964f, ang2);
        }
        {
        u8 *h;
        func_L01_00448690(D_001A4C78, 0, F32(h = D_001A4C78 - 0x98, 0x1A0), 0.12566371f);
        F32(pv, 0x64) = F32(pv, 0x64) + 0.00392f;
        F32(h, 0x88) = F32(h, 0x88) - (F32(pv, 0x64) - 2.0f);
        t = func_003C3D30(D_001A4C78 - 0x18, 0, 0, 0.5f);
        F32(h, 0x88) = F32(h, 0x88) - 2.0f;
        if (F32(h, 0x88) < t) {
            F32(h, 0x88) = t;
            S32(pv, 0x64) = 0;
        }
        if (PTR(h, 0x25C0)[0x43] != 0x3F) {
            f32 a = func_0038DAB8(0.2617994f, ang2);
            func_L01_00448690(m + 0xF8, 0, a, 0.06283186f);
            if (func_0038DB00(F32(m, 0xF8), a) > 1.0471976f) {
                F32(m, 0xF8) = func_0038DB00(F32(m, 0xF8), 1.0471976f);
            } else if (func_0038DB00(F32(m, 0xF8), a) < -1.0471976f) {
                F32(m, 0xF8) = func_0038DAB8(F32(m, 0xF8), 1.0471976f);
            }
        }
        }
        F32(pv, 0x58) = F32(pv, 0x58) + func_0038DBA0(ang2, ang);
        F32(pv, 0x40) = F32(pv, 0x58) / (F32(pv, 0x70) * 6.2831855f);
        if (1.0f < F32(pv, 0x40)) {
            F32(pv, 0x40) = 1.0f;
        }
        if (F32(pv, 0x40) < 0.0f) {
            F32(pv, 0x40) = 0.0f;
        }
        func_0038CBA0(D_001A4BE0 + 0xF0, 0xA0);
        return;
    }
    case 4:
        F32(m, 0x18) = F32(m, 0x18) - 0.010000001f;
        if (F32(m, 0x18) <= F32(pv, 0x7C) - 0.5f) {
            if (S32(pv, 0x90) != -1) {
                func_L01_003EB5E0(0, 4);
            }
            F32(m, 0x18) = F32(pv, 0x7C) - 0.5f;
            func_L01_004450F0(m, 5, -1);
            F32(pv, 0x40) = 1.0f;
            if (S32(pv, 0x30) != 0) {
                func_L01_0043B548(0x19E1, 0x6C)[2](m, 1);
            } else {
                func_L01_00456230(m, 1);
            }
            return;
        }
        break;
    case 5:
        F32(pv, 0x40) = 1.0f;
        if (S32(pv, 0x30) != 0) {
            func_L01_0043B548(0x19E1, 0x6C)[2](m, 1);
        } else {
            func_L01_00456230(m, 1);
        }
        return;
    case 6:
        F32(pv, 0x40) = 0.0f;
        if (S32(pv, 0x30) != 0) {
            func_L01_0043B548(0x19E1, 0x6C)[2](m, 0);
        } else {
            func_L01_00456230(m, 0);
        }
        F32(m, 0x18) = F32(pv, 0x7C) - 0.5f;
        break;
    case 7:
        if (F32(m, 0x18) == F32(pv, 0x7C) - 0.5f) {
            func_003A52A0(0, 0, m);
        }
        F32(m, 0x18) = F32(m, 0x18) + 0.010000001f;
        if (F32(pv, 0x7C) <= F32(m, 0x18)) {
            F32(m, 0x18) = F32(pv, 0x7C);
            func_L01_004450F0(m, 1, -1);
        }
        break;
    }
}
