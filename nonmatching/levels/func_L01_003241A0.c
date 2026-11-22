/* PAL near miss (opus-w3): 14 words differ with the file's flags plus -mvu0-use-vf0-vf2 (needed by vec_add_ab's j-form, which lets the shared sqc2 + call tail cross-jump as in retail; all 67 C blocks of L01_003241A0.c still match with the flag, which is not applied since this function does not match) and the config/levels/divs_nops.txt row 'func_L01_003241A0 2 0 0 0'. Left: the 0x60/0x64 constant load order, bnez vs retail bnel after func_L01_004BA800, the packed id t/k in $a0/$a1 instead of retail $a2/$a0, and the a0/a1 argument order of the two vt->f8 calls. The previous draft (astra-loop-1) was 52 words without the divs_nops row (397 with it). */
#include "common.h"
#include "vu0.h"

typedef struct { u8 p0[0x68]; s32 *p68; } Moby_3241A0;
typedef struct {
    u8 p0[8];
    Moby_3241A0 *f8;
    u8 pC[4];
    s32 f10;
    s32 f14;
    s32 f18;
    u8 p1C[0x28 - 0x1C];
    s32 f28;
    s32 f2C;
    s32 f30;
    u8 p34[8];
    s32 f3C;
    s32 f40;
    s32 f44;
    u8 p48[0x54 - 0x48];
    s32 f54;
    u8 p58[0x64 - 0x58];
    s32 f64;
    s32 f68;
} Vars_3241A0;
typedef struct {
    void (*f0)(void *);
    void (*f4)(void *, void *);
    void (*f8)(void *, void *);
    void (*fC)(void *, void *);
    void (*f10)(void *, s32);
    u8 p14[0x30 - 0x14];
    void (*f30)(void *);
    s32 (*f34)(void *);
    void (*f38)(void *, void *, f32);
    u8 p3C[0x50 - 0x3C];
    s32 (*f50)(void);
    s32 (*f54)(void *);
    void (*f58)(void *);
} Iface_3241A0;
typedef struct {
    u8 p0[0x20];
    s32 (*f20)(void);
} Iface2_3241A0;

extern void func_L01_00324E50(u8 *, u8 *);
extern s32 func_L01_0043B568(s32, s32, s32);
extern Iface2_3241A0 *func_L01_0043B548_003241A0(s32, s32);
extern void func_L01_00326770_003241A0(void);
extern s32 func_L01_004BA800(void);
extern void func_L01_004B0EE0(void);
extern void func_L01_004F50C8_003241A0(void *, void *, s32, s32);
extern s32 func_L01_003294A0_003241A0(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00326840_003241A0(void *, void *);
extern s32 func_L01_00326898_003241A0(void *, void *);
extern s32 func_L01_00328FE8_003241A0(void *);
extern s32 func_L01_00329038(void *);
extern void func_L01_00327678_003241A0(s32, s32);
extern void func_L01_00327728_003241A0(s32);
extern s32 func_L01_00456250(void *);
extern s32 func_00382380_003241A0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_005003D0_003241A0(s32, s32);
extern void func_L01_00459AF8(void);
extern void func_0038CAD0(s32 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_003EB438_003241A0(s32, void *, void *, s32, s32, s32);
extern void func_003A5348(s32, s32, s32);
extern void func_0045A590_003241A0(s32, s32, s32, s32, s32);
extern void func_L01_003EB350_003241A0(s32, void *);
extern void func_L01_003EB5E0_003241A0(s32, s32);
extern void func_L01_00325F60_003241A0(void *, void *, void *);
extern void func_L01_00328280_003241A0(void *, void *);
extern s32 func_L01_003B28F0(s32);
extern void func_L01_003261E8_003241A0(void *, void *, void *, void *);
extern void func_L01_00325AD8_003241A0(void *, void *);
extern void func_L01_00328458_003241A0(void *, void *);
extern void func_L01_00326468_003241A0(void *, void *);
extern void func_L01_003265C8_003241A0(void *, void *);
extern void func_L01_00329530_003241A0(void *, void *);
extern s32 func_L01_00511A98(void);
extern void func_L01_00404AD8_003241A0(void *, void *);
extern void func_L01_00329780_003241A0(void);

extern s32 D_001D545C;
extern u8 D_001426E0[];
extern u8 D_001BBC40[];
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0100;
extern f32 D_L01_001DF950 __attribute__((section(".sdata")));
extern s32 D_L01_001DFB40;
extern s32 D_L01_001D6694;
extern s32 D_L01_001D668C;
extern s32 D_L01_001D6690;
extern u8 D_L01_001DFE80[8];
extern s32 D_L01_002D15F0[];

void func_L01_003241A0(u8 *m) {
    Vars_3241A0 *v = *(Vars_3241A0 **)(m + 0x68);
    u8 *obj;
    Iface_3241A0 *vt;
    vu0_v4 a, b, pos, c;
    s32 idx;

    if (m[0x20] == 0) {
        func_L01_00324E50(m, (u8 *)v);
        return;
    }
    idx = v->f14;
    if (idx != -1) {
        obj = D_L01_001E001C + (idx << 8);
        vt = (Iface_3241A0 *)func_L01_0043B568(0x1ADD, 0, 0x68);
    } else {
        obj = 0;
        vt = 0;
    }
    switch (m[0x20]) {
    case 1: {
        f32 s;
        s32 f;
        if (D_001D545C == 12 && D_001426E0[0xCF] == 0) {
            D_001426E0[0x71] = 0x60;
            D_001426E0[0x72] = 0x64;
            func_L01_00326770_003241A0();
        }
        if ((D_001426E0[0x71] != 0 || D_001426E0[0x72] != 0) && func_L01_004BA800() == 0) {
            s32 t = (D_001426E0[0x71] << 8) + D_001426E0[0x72];
            s32 k = (t >> 11) & 0x1F;
            s = 2.0f;
            D_L01_001DF950 = s;
            if (D_L01_001DFB40 < 3) {
                if (k == D_001D545C) {
                    func_L01_004B0EE0();
                    break;
                }
                D_001426E0[0x71] = 0;
                D_001426E0[0x72] = 0;
            } else {
                if (k == D_001D545C) {
                    t &= 0x7FF;
                    if (t == 0x7FF) {
                        u8 *p;
                        func_L01_004B0EE0();
                        p = D_L01_001E0100 + (v->f28 << 7);
                        func_L01_004F50C8_003241A0(p + 0x30, p + 0x70, 0x74, 1);
                    } else if (func_L01_003294A0_003241A0(m, v) != 0) {
                        if (obj != 0) v->f54 = 1;
                        func_L01_004450F0(m, 6, -1);
                        D_L01_001DF950 = s;
                    }
                }
                D_001426E0[0x71] = 0;
                D_001426E0[0x72] = 0;
                if (m[0x20] != 1) {
                    func_L01_00326770_003241A0();
                    break;
                }
            }
        }
        if (func_L01_00326840_003241A0(m, v) != 0) {
            func_L01_00326770_003241A0();
            if ((D_001426E0[0xE5] != 0 || D_001426E0[0xE6] != 0) && func_L01_00326898_003241A0(m, v) != 0) break;
            f = 1;
            if (v->f40 != 0 && v->f8 != 0) {
                if (func_L01_00328FE8_003241A0(v->f8) != 0) {
                    if (func_L01_00329038(v->f8) != 0) f = 0;
                }
                if (f != 0) D_L01_001DF950 = 2.0f;
            }
            if (f != 0) {
                if (obj != 0) {
                    if (v->f40 != 0) {
                        s32 r = vt->f50();
                        if (r == v->f18) {
                            func_L01_00327678_003241A0(r, 0);
                            func_L01_00327728_003241A0(0);
                        }
                    } else if (vt->f50() >= 0 && vt->f54(obj) == 0) {
                        s32 r = vt->f50();
                        func_L01_00327678_003241A0(r, 0);
                        func_L01_00327728_003241A0(0);
                        if (vt->f50() != v->f18) vt->f58(obj);
                    } else {
                        Iface2_3241A0 *o2 = func_L01_0043B548_003241A0(0x19E1, 0x6C);
                        if (o2->f20() != v->f18) {
                            func_L01_00327678_003241A0(v->f18, 0);
                            func_L01_00327728_003241A0(0);
                        }
                    }
                }
                v->f54 = 1;
                func_L01_004450F0(m, 3, -1);
                break;
            }
        }
        if (v->f54 == 0 && ((obj != 0 && func_L01_00456250(obj) != 0) || (v->f10 != -1 && func_00382380_003241A0(D_001A4C60, v->f10, 0) != 0))) {
            if (obj != 0) v->f54 = 1;
            func_L01_00326770_003241A0();
            func_L01_004450F0(m, 2, -1);
        } else {
            if (obj != 0) {
                if (func_L01_00456250(obj) == 0) v->f54 = 0;
            }
            break;
        }
    }
    case 2:
        if (func_L01_004561B8(m) != 0) {
            v->f3C = 0x19;
            func_L01_005003D0_003241A0(0x74, 1);
            func_L01_00459AF8();
        }
        if (((s32 (*)(s32 *))func_0038CAD0)(&v->f3C) == 0) {
            D_L01_001DF950 = (1.0f - (f32)v->f3C / 25.0f) * 1.1f;
            break;
        }
        D_L01_001DF950 = 2.0f;
        func_L01_004450F0(m, 3, -1);
    case 3: {
        f32 s;
        if (v->f40 != 0) {
            func_L01_00329530_003241A0(m, v);
            func_L01_004450F0(m, 6, -1);
            D_L01_001DF950 = 2.0f;
            break;
        }
        if (obj != 0 && v->f2C == -1) {
            s = 5.0f;
            vt->f4(obj, &b);
            vt->f8(obj, &c);
            vt->fC(obj, &a);
        } else {
            u8 *p = D_L01_001E0100 + (v->f2C << 7);
            s = 5.0f;
            *(vu0_q *)&c = *(vu0_q *)(p + 0x70);
            *(vu0_q *)&b = *(vu0_q *)(p + 0);
            *(vu0_q *)&a = *(vu0_q *)(p + 0x30);
            if (obj != 0) s = 1.13f;
        }
        if (func_L01_004561B8(m) != 0) {
            if (v->f40 == 0) {
                if (obj != 0 && v->f2C == -1) {
                    vt->f0(obj);
                } else {
                    u8 *p = D_L01_001E0100 + (v->f28 << 7);
                    if (obj != 0) func_L01_004F50C8_003241A0(p + 0x30, p + 0x70, 0x31, 1);
                    else func_L01_004F50C8_003241A0(p + 0x30, p + 0x70, 0x74, 1);
                }
                func_0038CF68(&pos, &b, -s);
                vec_add_ab(&pos, &pos, &a);
                func_L01_003EB438_003241A0(0, &pos, &c, 1, 0, 0);
                func_003A5348(0x12, 0, 0);
            }
            v->f3C = 0x19;
        }
        if (((s32 (*)(s32 *))func_0038CAD0)(&v->f3C) != 0) {
            D_L01_001DF950 = 0;
            if (D_L01_002D15F0[0] != 0xF) func_L01_004450F0(m, 4, -1);
            qzero(&pos);
        } else {
            f32 t = (f32)v->f3C / 25.0f * 1.1f;
            D_L01_001DF950 = t;
            if (1.0f < t) D_L01_001DF950 = 1.0f;
            func_0038CF68(&pos, &b, -s * D_L01_001DF950 * D_L01_001DF950);
        }
        vec_add_ab(&pos, &pos, &a);
        func_L01_003EB350_003241A0(0, &pos);
        break;
    }
    case 4:
        if (func_L01_004561B8(m) != 0) {
            if (v->f8 == 0) func_L01_00329530_003241A0(m, v);
            v->f3C = 0;
            v->f44 = 5;
            func_0045A590_003241A0(3, 1, 0xE, 0, 0);
        }
        if (v->f8 == 0) func_L01_00329530_003241A0(m, v);
        v->f3C = 0;
        v->f44 = 5;
        if (D_L01_001D6694 == 5) break;
        if (D_L01_001D668C == 5) break;
        if (D_L01_001D6690 == 5) break;
        func_0045A590_003241A0(3, 1, 0xE, 0, 0);
        break;
    case 5: {
        f32 s;
        if (obj != 0 && v->f2C == -1) {
            s = 5.0f;
            vt->f4(obj, &b);
            vt->f8(obj, &c);
            vt->fC(obj, &a);
        } else {
            u8 *p = D_L01_001E0100 + (v->f2C << 7);
            s = 5.0f;
            *(vu0_q *)&c = *(vu0_q *)(p + 0x70);
            *(vu0_q *)&b = *(vu0_q *)(p + 0);
            *(vu0_q *)&a = *(vu0_q *)(p + 0x30);
            if (obj != 0) s = 1.13f;
        }
        s *= 0.68f;
        if (func_L01_004561B8(m) != 0) {
            if (obj != 0 && func_L01_00456250(obj) != 0) vt->f30(obj);
            v->f3C = 0x11;
        }
        if (((s32 (*)(s32 *))func_0038CAD0)(&v->f3C) != 0) {
            D_L01_001DF950 = 2.0f;
            func_L01_004450F0(m, 6, -1);
            break;
        } else {
            f32 t = (1.0f - (f32)v->f3C / 17.0f) * 1.1f;
            D_L01_001DF950 = t;
            if (1.0f < t) D_L01_001DF950 = 1.0f;
            func_0038CF68(&pos, &b, -s * D_L01_001DF950 * D_L01_001DF950);
        }
        vec_add_ab(&pos, &pos, &a);
        func_L01_003EB350_003241A0(0, &pos);
        break;
    }
    case 6:
        if (func_L01_004561B8(m) != 0) {
            s32 a1 = v->f64;
            if (a1 != 0 && v->f68 != -1 && a1 != *v->f8->p68) {
                D_001BBC40[v->f68 + (D_001D545C << 4)] &= 0x7F;
                D_L01_001DFE80[v->f68] &= 0x7F;
            }
        }
        func_L01_003EB5E0_003241A0(0, 2);
        func_L01_00325F60_003241A0(m, v, v->f8);
        func_L01_00328280_003241A0(m, v);
        func_L01_004450F0(m, 7, -1);
        break;
    case 7:
        if (func_L01_003B28F0(v->f30) != 0) {
            func_L01_003261E8_003241A0(m, v, obj, vt);
            break;
        }
        func_L01_00325AD8_003241A0(m, v);
        func_L01_00328458_003241A0(m, v);
        if (obj == 0 || vt->f34(obj) == 0) func_L01_00326468_003241A0(m, v);
        func_L01_003265C8_003241A0(m, v);
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) v->f3C = 0x11;
        if (((s32 (*)(s32 *))func_0038CAD0)(&v->f3C) != 0) {
            D_L01_001DF950 = 2.0f;
            func_L01_004450F0(m, 9, -1);
            break;
        }
        D_L01_001DF950 = (1.0f - (f32)v->f3C / 17.0f) * 1.1f;
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            if (obj != 0) {
                vt->f10(obj, 0);
                vt->f38(obj, D_001A4BE0, -100.0f);
            }
            v->f3C = 0x19;
        }
        if (func_L01_00511A98() == 0) vt->f38(obj, 0, -100.0f);
        if (((s32 (*)(s32 *))func_0038CAD0)(&v->f3C) != 0) {
            D_L01_001DF950 = 0;
            func_L01_004450F0(m, 10, -1);
            break;
        }
        D_L01_001DF950 = (f32)v->f3C / 25.0f * 1.1f;
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) v->f3C = 8;
        if (func_L01_00511A98() == 0) vt->f38(obj, 0, -100.0f);
        if (((s32 (*)(s32 *))func_0038CAD0)(&v->f3C) != 0) {
            vt->f38(obj, D_001A4BE0, -8.0f);
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 11:
        if (func_L01_004561B8(m) != 0) v->f3C = 0;
        if (func_L01_004BA800() != 0) goto clr;
        v->f3C++;
        if (v->f3C >= 2) {
            func_L01_004450F0(m, 1, -1);
        } else {
            D_L01_001DF950 = 2.0f;
        }
        break;
    default:
        break;
    clr:
        v->f3C = 0;
        break;
    }
    func_L01_00404AD8_003241A0(func_L01_00329780_003241A0, m);
}
