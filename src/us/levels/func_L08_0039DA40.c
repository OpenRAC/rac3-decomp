#include "common.h"

/* NTSC-U counterpart of func_L08_0039F5E0 (src/levels/08_aquatos/L08_0039F5E0.c) */
#include "vu0.h"

/* localdecomp:start func_L08_0039DA40 */
extern s32 D_L08_001D6694;
extern s32 D_001D545C;
extern u8 *D_L08_001DF21C_0039DA40;
extern s32 D_L08_001F1FC0_0039DA40[];
extern s32 D_001A71A0[];
extern u8 D_001A4BE0[];

extern s32 func_L08_0039ECB8(u8 *);
extern void func_L01_004A6DF8(u8 *, s32);
extern s32 func_L01_00452EF0(u8 *);
extern s32 func_L01_00452EC8(u8 *);
extern s16 func_0037E208(s32, s32);
extern s32 func_L01_00452F60();
extern s32 func_003883C8(void *);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L08_0039F170(u8 *);
extern void func_L08_0039F590(u8 *);
extern void func_L08_0039F928(u8 *);
extern void func_L08_0039F1C0(u8 *);
extern void func_L08_0039F378(u8 *);
extern void func_003BD360(u8 *);
extern f32 func_003BE7F0(f32, void *, s32, s32);
extern void func_003BEC60(void *, f32, f32, f32, f32, void *);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_L01_00453210(void *, s32);
extern void func_L01_00458A70(f32, f32, f32, f32, u8 *);
extern void func_00388830(f32, void *, void *);
extern void func_L01_00459F10(u8 *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_L01_00457590(f32, u8 *, void *);
extern void func_L01_00445758(void *, f32, f32, f32, f32, void *, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_L01_00436500(u8 *);
extern void func_L01_00457728(u8 *, void *);
extern void func_L01_00457440(u8 *, void *);
extern void func_L01_00443790(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_L08_004295F0(f32, u8 *, void *, s32, s32, s32);
extern s32 func_L08_00429728(u8 *, void *);

/* Field access through a struct member, as the original's structs give: gcc 2.95's alias
 * analysis (MEM_IN_STRUCT_P against a fixed scalar) lets the scheduler move global loads
 * above these stores, as retail does. */

static inline void restore_flags(u8 *a) {
    u8 *m = *(u8 **)(a + 0x24);
    (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) &= ~0x41;
    (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) |= (((struct { u8 _p[0x44]; u16 v; } *)(m))->v) & 0x1000;
    (((struct { u8 _p[0x98]; s32 v; } *)(a))->v) = (((struct { u8 _p[0x10]; s32 v; } *)(m))->v);
}

void func_L08_0039DA40(u8 *a) {
    vu0_v4 v;
    vu0_v4 d;
    vu0_v4 s;
    vu0_v4 dir;
    u8 *st = *(u8 **)(a + 0x68);
    u8 *m;
    s32 t;
    s32 ok;
    f32 ang, r, f, g, q;
    u8 *rot;
    f32 *pz;
    u8 *h;

    if (func_L08_0039ECB8(a) != 0) goto kill;

    if (D_L08_001D6694 == 2) {
        if (((((struct { u8 _p[0x34]; u8 v; } *)(a))->v) ^ 1) & 1) {
            (((struct { u8 _p[0x98]; s32 v; } *)(a))->v) = 0;
            (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) = ((((struct { u8 _p[0x34]; u16 v; } *)(a))->v) | 0x41) & ~0x1000;
            func_L01_004A6DF8(a, 1);
            (((struct { u8 _p[0x250]; s32 v; } *)(st))->v) = 1;
        }
        return;
    }

    if ((((struct { u8 _p[0x250]; s32 v; } *)(st))->v) != 0) {
        restore_flags(a);
        (((struct { u8 _p[0x250]; s32 v; } *)(st))->v) = 0;
    }

    switch ((((struct { u8 _p[0x95]; u8 v; } *)(a))->v)) {
    case 0:
        if (func_L01_00452EF0(a) != 0 && (((struct { u8 _p[0x196]; s16 v; } *)(st))->v) == 0) {
            (((struct { u8 _p[0x196]; s16 v; } *)(st))->v) = func_0037E208(0, 100);
        }
        if (D_001D545C == 8 && (((struct { u8 _p[0x1C0]; s32 v; } *)(st))->v) != -1) {
            func_L01_00452F60(D_L08_001DF21C_0039DA40 + ((((struct { u8 _p[0x1C0]; s32 v; } *)(st))->v) << 8));
        }
        if ((((struct { u8 _p[0x1C4]; s32 v; } *)(st))->v) == 1) {
            (((struct { u8 _p[0x98]; s32 v; } *)(a))->v) = 0;
            (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) = ((((struct { u8 _p[0x34]; u16 v; } *)(a))->v) | 0x41) & ~0x1000;
            func_L01_004A6DF8(a, 1);
        }
        if ((((struct { u8 _p[0x174]; s16 v; } *)(st))->v) == 1 && func_003883C8(st + 0x196) != 0 && (((struct { u8 _p[0x20]; u8 v; } *)(a))->v) != 1 && (((struct { u8 _p[0x20]; u8 v; } *)(a))->v) != 2) {
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 0) {
                func_003BE4F0(a, 0, 0, 10);
            }
            func_L01_00441FB8(a, 6, 2);
            if ((((struct { u8 _p[0x1C4]; s32 v; } *)(st))->v) == 1) {
                restore_flags(a);
                if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 5) {
                    func_003BE4F0(a, 5, 2, 3);
                }
                (((struct { u8 _p[0x1D8]; f32 v; } *)(st))->v) = (((struct { u8 _p[0xF8]; f32 v; } *)(a))->v);
                func_L01_00441FB8(a, 9, -1);
            }
        } else if ((((struct { u8 _p[0x198]; s32 v; } *)(st))->v) != 0 && func_003883C8(st + 0x196) != 0) {
            func_L01_00441FB8(a, 5, 1);
            (((struct { u8 _p[0x198]; s32 v; } *)(st))->v) = 0;
            if ((((struct { u8 _p[0x190]; s32 v; } *)(st))->v) < 300) {
                (((struct { u8 _p[0x190]; s32 v; } *)(st))->v) = func_0037E208(480, 600);
            }
        }
        break;
    case 4:
        if ((((struct { u8 _p[0x1C0]; s32 v; } *)(st))->v) != -1) {
            m = D_L08_001DF21C_0039DA40 + ((((struct { u8 _p[0x1C0]; s32 v; } *)(st))->v) << 8);
            if ((((struct { u8 _p[0x1C4]; s32 v; } *)(st))->v) == 0) {
                if (m == 0 || (((struct { u8 _p[0x20]; u8 v; } *)(m))->v) == 0xFE || (((struct { u8 _p[0x20]; u8 v; } *)(m))->v) == 0xFD) {
                    restore_flags(a);
                    if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 2) {
                        func_003BE4F0(a, 2, 0, 10);
                    }
                    func_L01_00441FB8(a, 1, 2);
                }
            } else if ((((struct { u8 _p[0x1C4]; s32 v; } *)(st))->v) == 1 && func_L01_00452F60(m) != 0) {
                restore_flags(a);
                if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 2) {
                    func_003BE4F0(a, 2, 0, 10);
                }
                func_L01_00441FB8(a, 1, 2);
            }
        } else if ((((struct { u8 _p[0x1C8]; s32 v; } *)(st))->v) != -1) {
            u8 *o = D_L08_001DF21C_0039DA40 + ((((struct { u8 _p[0x1C8]; s32 v; } *)(st))->v) << 8);
            if (o == 0 || (((struct { u8 _p[0x20]; u8 v; } *)(o))->v) == 0xFE || (((struct { u8 _p[0x20]; u8 v; } *)(o))->v) == 0xFD) {
                restore_flags(a);
                if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 2) {
                    func_003BE4F0(a, 2, 0, 10);
                }
                func_L01_00441FB8(a, 1, 2);
            }
        }
        break;
    case 1:
        if ((((struct { u8 _p[0x174]; s16 v; } *)(st))->v) == 1 && (((struct { u8 _p[0x20]; u8 v; } *)(a))->v) != 1 && (((struct { u8 _p[0x20]; u8 v; } *)(a))->v) != 2) {
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 0) {
                func_003BE4F0(a, 0, 0, 10);
            }
            func_L01_00441FB8(a, 6, 2);
        } else if ((((struct { u8 _p[0x190]; s32 v; } *)(st))->v) == 0) {
            func_L01_00441FB8(a, 3, 0);
        }
        break;
    case 2:
        if ((((struct { u8 _p[0x174]; s16 v; } *)(st))->v) != 1 && func_L01_00452EF0(a) == 0) {
            func_L01_00441FB8(a, 4, 0);
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 0) {
                func_003BE4F0(a, 0, 0, 0);
            }
            (((struct { u8 _p[0x190]; s32 v; } *)(st))->v) = func_0037E208(580, 600);
        }
        break;
    case 3:
        if ((((struct { u8 _p[0x30]; f32 v; } *)(st))->v) <= 0.0f) {
            func_L08_0039F170(a);
            func_L08_0039F590(a);
            (((struct { u8 _p[0x98]; s32 v; } *)(a))->v) = 0;
            (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) |= 0x41;
            func_L01_00441FB8(a, 11, 5);
            return;
        }
        if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 0) {
            func_003BE4F0(a, 0, 0, 10);
        }
        func_L01_00441FB8(a, 6, 2);
        break;
    }

    switch ((((struct { u8 _p[0x20]; u8 v; } *)(a))->v)) {
    case 1:
        if (func_L01_00452EC8(a) != 0) {
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 2) {
                func_003BE4F0(a, 2, 2, 3);
            }
            (((struct { u8 _p[0x36]; s16 v; } *)(st))->v) = 0x28;
        }
        if (D_L08_001F1FC0_0039DA40[0] != 1) {
            func_003BEC60(a + 0x18, func_003BE7F0(0.5f, a + 0x10, 0, 0), 0.0027222223579883575f, 0.0027222223579883575f, 0.13333334028720856f, st + 0x19C);
        }
        if ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) {
            func_L01_00441FB8(a, 3, -1);
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 1) {
                func_003BE4F0(a, 1, 0, 10);
            }
        }
    case 3:
        if ((D_L08_001F1FC0_0039DA40[0] != 0 || (((struct { u8 _p[0x1C4]; s32 v; } *)(st))->v) == 0) && ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2)) {
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 0) {
                func_003BE4F0(a, 0, 0, 10);
            }
            func_L01_00441FB8(a, 4, -1);
        }
        break;
    case 11:
        func_L08_0039F928(a);
        if ((((struct { u8 _p[0x96]; u16 v; } *)(a))->v) < 31) break;
        goto kill;
    case 4:
        if (func_L01_00452EC8(a) != 0) {
            do {
                ok = 1;
                ang = func_0037E2A8();
                r = func_0037E250(4.0f, 8.0f);
                qzero(st + 0x1B0);
                (((struct { u8 _p[0x1B0]; f32 v; } *)(st))->v) = func_00388960(ang) * r;
                (((struct { u8 _p[0x1B4]; f32 v; } *)(st))->v) = func_00388978(ang) * r;
                vec_add_ab(st + 0x1B0, st + 0x1B0, st + 0x1A0);
                t = (((struct { u8 _p[0x254]; s32 v; } *)(st))->v);
                if ((u32)(t + 1) >= 2 && func_L01_00453210(st + 0x1B0, t) == 0) {
                    ok = 0;
                }
            } while (ok == 0);
            (((struct { u8 _p[0x194]; s16 v; } *)(st))->v) = func_0037E208(300, 530);
            if (D_001D545C == 0x1C) {
                (((struct { u8 _p[0xA8]; s32 v; } *)(st))->v) |= 4;
                (((struct { u8 _p[0x7C]; f32 v; } *)(st))->v) = (((struct { u8 _p[0x78]; f32 v; } *)(st))->v) = 0.7f;
                (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) |= 0x100;
                (((struct { u8 _p[0x80]; f32 v; } *)(st))->v) = 12.566371f;
                (((struct { u8 _p[0xA8]; s32 v; } *)(st))->v) |= 1;
            }
            func_L01_00458A70(0.002222222276031971f, 0.03333333507180214f, 0.0069813174195587635f, 0.20943953096866608f, a);
        }
        if (D_001D545C == 0x1C) {
            func_00388830(3.0f, &d, a + 0xC0);
            vec_add_ba(&v, a + 0x10, &d);
            func_L01_00459F10(a, &v);
            if (func_00389468((((struct { u8 _p[0xF8]; f32 v; } *)(a))->v), func_00388A28((((struct { u8 _p[0x1B0]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x1B4]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v))) > 0.17453292f) {
                func_00389158(a + 0xC0, a + 0xC0, a + 0xE0, 0.07563094049692154f);
                func_00389158(a + 0xD0, a + 0xD0, a + 0xE0, 0.07563094049692154f);
                (((struct { u8 _p[0xF8]; f32 v; } *)(a))->v) = func_00388A28((((struct { u8 _p[0xC0]; f32 v; } *)(a))->v), (((struct { u8 _p[0xC4]; f32 v; } *)(a))->v));
            }
        } else {
            func_L01_00457590((((struct { u8 _p[0xF8]; f32 v; } *)(a))->v), a, st + 0x1B0);
            rot = a + 0xF8;
            func_L01_00445758(rot, func_00388A28((((struct { u8 _p[0x1B0]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x1B4]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v)), 0.0034906587097793818f, 0.0034906587097793818f, 0.10471976548433304f, st + 0x19C, 0);
        }
        if (func_00388800(a + 0x10, st + 0x1B0) < 0.75f) {
            ang = func_0037E2A8();
            r = func_0037E250(2.0f, 6.0f);
            qzero(st + 0x1B0);
            (((struct { u8 _p[0x1B0]; f32 v; } *)(st))->v) = func_00388960(ang) * r;
            (((struct { u8 _p[0x1B4]; f32 v; } *)(st))->v) = func_00388978(ang) * r;
            vec_add_ab(st + 0x1B0, st + 0x1B0, st + 0x1A0);
        }
        if (func_003883C8(st + 0x194) != 0) {
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 1) {
                func_003BE4F0(a, 1, 0, 10);
            }
            func_L01_00441FB8(a, 3, -1);
        }
        func_L08_0039F378(a);
        break;
    case 9:
        rot = a + 0xF8;
        func_L01_00445758(rot, func_00388A28((((struct { u8 _p[0x160]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x164]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v)), 0.0037330654449760914f, 0.0013089969288557768f, 0.07853981852531433f, st + 0x19C, 0);
        if (func_L01_00452EC8(a) != 0) {
            (((struct { u8 _p[0x1C4]; s32 v; } *)(st))->v) = 0;
            (((struct { u8 _p[0x1A8]; f32 v; } *)(st))->v) = (((struct { u8 _p[0x18]; f32 v; } *)(a))->v);
            (((struct { u8 _p[0x1B8]; f32 v; } *)(st))->v) = (((struct { u8 _p[0x18]; f32 v; } *)(a))->v);
            func_L08_0039F590(a);
        }
        f = func_L01_00436500(a);
        if ((((struct { u8 _p[0x42]; u8 v; } *)(a))->v) == 5) {
            (((struct { u8 _p[0x48]; f32 v; } *)(a))->v) = 0.7f;
            if (f > 8.0f && f < 18.0f) {
                dir.x = func_00388960((((struct { u8 _p[0x1D8]; f32 v; } *)(st))->v));
                dir.y = func_00388978((((struct { u8 _p[0x1D8]; f32 v; } *)(st))->v));
                dir.z = 0.0f;
                func_00388830(0.25f, &s, &dir);
                vec_add_ba(&v, a + 0x10, &s);
            }
            if (f > 8.0f && f < 14.0f) {
                func_003BEC60(&v.z, (((struct { u8 _p[0x1B8]; f32 v; } *)(st))->v) + 2.0f + 1.0f, 0.8333333f, 1.6666666f, 0.20833333f, st + 0x1D4);
            }
            if (f == 14.0f) {
                (((struct { u8 _p[0x1D4]; s32 v; } *)(st))->v) = 0;
            }
            if (f > 14.0f && f < 18.0f) {
                (((struct { u8 _p[0x48]; f32 v; } *)(a))->v) = 0.7f;
                pz = &v.z;
                func_003BEC60(pz, func_003BE7F0(0.5f, a + 0x10, 0, 0), 0.20833333f, 2.5f, 0.125f, st + 0x1D4);
            }
            if (f > 8.0f && f < 18.0f) {
                vec_sub_ab(&d, &v, a + 0x10);
                func_L01_00457728(a, &d);
            }
        }
        if (f > 24.0f) {
            (((struct { u8 _p[0x48]; f32 v; } *)(a))->v) = 1.0f;
            func_L01_00441FB8(a, 6, -1);
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 0) {
                func_003BE4F0(a, 0, 0, 7);
            }
        }
        break;
    case 6:
        if (func_L01_00452EC8(a) != 0) {
            if (D_001D545C == 0x1C) {
                (((struct { u8 _p[0xA8]; s32 v; } *)(st))->v) |= 4;
                (((struct { u8 _p[0x7C]; f32 v; } *)(st))->v) = (((struct { u8 _p[0x78]; f32 v; } *)(st))->v) = 0.7f;
                (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) |= 0x100;
                (((struct { u8 _p[0x80]; f32 v; } *)(st))->v) = 12.566371f;
                (((struct { u8 _p[0xA8]; s32 v; } *)(st))->v) |= 1;
            }
            func_L01_00458A70(0.004444444552063942f, 0.06666667014360428f, 0.0069813174195587635f, 0.20943953096866608f, a);
        }
        if (D_001D545C == 0x1C) {
            func_L01_00459F10(a, st + 0x160);
            (((struct { u8 _p[0xF8]; f32 v; } *)(a))->v) = func_00388A28((((struct { u8 _p[0xC0]; f32 v; } *)(a))->v), (((struct { u8 _p[0xC4]; f32 v; } *)(a))->v));
        } else {
            func_L01_00457440(a, st + 0x160);
        }
        if (func_00388800(a + 0x10, st + 0x160) < 1.5f
            && func_00389468((((struct { u8 _p[0xF8]; f32 v; } *)(a))->v), func_00388A28((((struct { u8 _p[0x160]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x164]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v))) < 0.43633232f) {
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 4) {
                func_003BE4F0(a, 4, 0, 10);
            }
            func_L01_00441FB8(a, 7, -1);
        }
        func_L08_0039F378(a);
        break;
    case 7:
        if (func_L01_00452EC8(a) != 0) {
            if (D_001D545C == 0x1C) {
                (((struct { u8 _p[0xA8]; s32 v; } *)(st))->v) |= 4;
                (((struct { u8 _p[0x7C]; f32 v; } *)(st))->v) = (((struct { u8 _p[0x78]; f32 v; } *)(st))->v) = 0.7f;
                (((struct { u8 _p[0x34]; u16 v; } *)(a))->v) |= 0x100;
                (((struct { u8 _p[0x80]; f32 v; } *)(st))->v) = 12.566371f;
                (((struct { u8 _p[0xA8]; s32 v; } *)(st))->v) |= 1;
            }
            func_L01_00458A70(0.035555556416511536f, 0.46666669845581055f, 0.0069813174195587635f, 0.20943953096866608f, a);
        }
        if ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) {
            func_L01_00441FB8(a, 8, -1);
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 3) {
                func_003BE4F0(a, 3, 7, 6);
            }
        }
        if (func_L01_00436500(a) > 11.0f && func_L01_00436500(a) < 18.0f && (((struct { u8 _p[0x42]; u8 v; } *)(a))->v) == 4) {
            func_L01_00443790(a, 0, (((struct { u8 _p[0x170]; s32 v; } *)(st))->v) == D_001A71A0[0] ? 1 : 0x10001, 0, 1, 0, 0.75f, (f32)(((struct { u8 _p[0x45]; u8 v; } *)(st))->v), 1.5f);
        }
        break;
    case 2: {
        if (func_L01_00452EC8(a) != 0) {
            (((struct { u8 _p[0x200]; f32 v; } *)(st))->v) = func_0037E250(0.008333333767950535f, 0.011666666716337204f);
            (((struct { u8 _p[0x22D]; u8 v; } *)(st))->v) = 3;
            (((struct { u8 _p[0x210]; s32 v; } *)(st))->v) = 0x200;
            (((struct { u8 _p[0x218]; f32 v; } *)(st))->v) = 0.5f;
            (((struct { u8 _p[0x208]; f32 v; } *)(st))->v) = 0.0833333358168602f;
            (((struct { u8 _p[0x20C]; f32 v; } *)(st))->v) = 0.11666667461395264f;
            (((struct { u8 _p[0x214]; s32 v; } *)(st))->v) = 12;
            (((struct { u8 _p[0x244]; f32 v; } *)(st))->v) = (((struct { u8 _p[0x240]; f32 v; } *)(st))->v) = -1.0f;
            h = D_001A4BE0;
            q = func_00388A28((((struct { u8 _p[0x10]; f32 v; } *)(a))->v) - (((struct { u8 _p[0x80]; f32 v; } *)(h))->v), (((struct { u8 _p[0x14]; f32 v; } *)(a))->v) - (((struct { u8 _p[0x84]; f32 v; } *)(h))->v));
            if ((((struct { u8 _p[0x1DC]; s32 v; } *)(st))->v) != 0) {
                g = func_00389380(q, 0.17453292f);
            } else {
                g = func_00389380(q, -0.17453292f);
            }
            f = g;
            func_L08_004295F0(f, a, st + 0x1F0, 6, 3, 0);
        }
        rot = a + 0xF8;
        func_L01_00445758(rot, func_00388A28((((struct { u8 _p[0x160]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x10]; f32 v; } *)(a))->v), (((struct { u8 _p[0x164]; f32 v; } *)(st))->v) - (((struct { u8 _p[0x14]; f32 v; } *)(a))->v)), 0.0037330654449760914f, 0.0013089969288557768f, 0.07853981852531433f, st + 0x19C, 0);
        if (func_L08_00429728(a, st + 0x1F0) & 1) {
            func_L01_00441FB8(a, 1, 1);
        }
        if ((((struct { u8 _p[0x10]; f32 v; } *)(a))->v) < 2.0f || (((struct { u8 _p[0x10]; f32 v; } *)(a))->v) > 1021.0f || (((struct { u8 _p[0x14]; f32 v; } *)(a))->v) < 2.0f || (((struct { u8 _p[0x14]; f32 v; } *)(a))->v) > 1021.0f
            || (((struct { u8 _p[0x18]; f32 v; } *)(a))->v) < 2.0f || (((struct { u8 _p[0x18]; f32 v; } *)(a))->v) > 1021.0f) {
        kill:
            func_003BD360(a);
            return;
        }
        break;
    }
    case 8:
        if ((((struct { u8 _p[0x60]; u8 v; } *)(a))->v) & 2) {
            func_L01_00441FB8(a, 6, -1);
            if ((((struct { u8 _p[0x43]; u8 v; } *)(a))->v) != 0) {
                func_003BE4F0(a, 0, 0, 10);
            }
        }
        break;
    }
    func_L08_0039F1C0(a);
}
/* localdecomp:end func_L08_0039DA40 */
