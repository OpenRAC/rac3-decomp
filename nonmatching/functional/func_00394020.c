/* functional: high. Rewritten from the PAL boot_elf assembly (no draft, frontbin twin func_00393C40 unmatched); register allocation and block order differ. Retail calls func_0038DEE0 with $f13 still holding pi/2 from the angle sum; that value is passed explicitly. sqrt.s of x*x+y*y cannot be negative, so no clamp is needed. */
#include "vu0.h"
typedef struct {
    s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 id;
} E_00394020;
typedef struct {
    u8 pad0[0x64]; s32 f64; u8 pad68[4]; s32 f6C;
    u8 st[2]; u8 pad72[2]; s32 sel; s32 f78; s32 f7C;
} P_00394020;
typedef struct {
    u8 pad0[0x148]; f32 f148; f32 f14C; u8 pad150[0x1C0 - 0x150];
    s32 f1C0; s32 f1C4; u8 pad1C8[4]; s32 f1CC; u8 pad1D0[8]; s32 f1D8;
} Pad_00394020;
typedef struct { u8 pad0[0xA4]; u8 bA4; u8 padA5[0x11]; u8 bB6; } S_143950_00394020;
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x84 - 0x14]; u16 f84; u8 pad86[4]; u16 f8A; u8 pad8C[0xF0 - 0x8C]; } T_00394020;
typedef struct { u8 pad0[0xF0]; u16 hF0; u8 padF2[2]; u32 fF4; s32 fF8; } S_1A7C10_00394020;

extern s32 D_0031D050_00394020[];
extern S_143950_00394020 D_00143950_00394020[];
extern s32 D_001D5C78_00394020[];
extern s32 D_001D5C98_00394020;
extern Pad_00394020 *D_001D52FC_00394020[];
extern s32 D_001D5D5C_00394020;
extern u8 D_001D5D58_00394020;
extern f32 D_001D5D54_00394020;
extern u8 D_001A745E_00394020[];
extern s32 D_001D9EE8_00394020[];
extern s32 D_001D5CAC_00394020;
extern E_00394020 **D_001D9EF0_00394020[];
extern s32 D_001D5D00_00394020[];
extern s32 D_001D5D04_00394020[];
extern s32 D_001D5D08_00394020[];
extern s32 D_001D5D0C_00394020[];
extern u8 D_001425C0_00394020[];
extern T_00394020 D_001DAA40_00394020[];
extern s16 D_001CCFD4_00394020[];
extern u8 D_001A4BE0_00394020[];
extern S_1A7C10_00394020 D_001A7C10_00394020[];
extern s32 D_001D4C38_00394020[];
extern s32 D_001D545C_00394020[];
extern s32 D_001427F0_00394020[];
extern s32 D_001D9F2C_00394020[];
extern s32 D_001D9F30_00394020;
extern s32 D_001D9BC8_00394020[];
extern s32 D_001D9F28_00394020[];

extern s32 func_003E41A8(void);
extern void func_00398070(void);
extern s32 func_00398088(void);
extern void func_003AEF00(void *, s32);
extern void func_003E41C0(void);
extern s32 func_003A3FB8(s32, s32);
extern void func_00393F38(s32);
extern s32 func_003A5748(s32, s32, s32);
extern s32 func_0038CEE0(void *);
extern f32 func_0038D540(f32, f32);
extern f32 func_0038DEE0(f32, f32);
extern f32 func_0038DF80(f32, f32);
extern f32 func_0038DF28(f32);
extern void func_003A2958(void);
extern s32 func_0039AFE8(s32);
extern void func_0039AE18(s32);
extern void func_00381BB8(s32);
extern void func_00381C80(s32);
extern void func_003E4178(void);
extern void func_00398068(void);
extern void func_00398060(void);
extern s32 func_00393898(s32);

#define ROW_00394020 (D_001D9EF0_00394020[0][D_001D5CAC_00394020])

/* quick_select_ring_update (boot_elf copy of frontbin func_00393C40): R1 opens the ring,
 * the left stick past 0.9 or the d-pad picks a slot, releasing Triangle closes it and
 * hands out the chosen item. */
void func_00394020(P_00394020 *p) {
    u8 *st = p->st;
    s32 held;
    s32 old;
    s32 dir;
    s32 sel;
    s32 id;
    Pad_00394020 *pad;
    f32 x, y, mag, ang;

    if (D_0031D050_00394020[0] != 0) {
        return;
    }

    held = 0;
    if (D_00143950_00394020[0].bB6 == 0 || func_003E41A8() != 0 || D_00143950_00394020[0].bB6 == 0) {
        held = 1;
    }
    if (D_00143950_00394020[0].bB6 == 0) {
        func_00398070();
        if (func_00398088() == 0) {
            held = 0;
        }
    }
    if (held && D_001D5C78_00394020[0] != 0) {
        u8 *obj = (u8 *)D_001D5C78_00394020[0] + 0x21548;
        s32 a = 2;
        if (func_003E41A8() != 0) {
            a = D_001D5C98_00394020;
        }
        func_003AEF00(obj, a);
        func_003E41C0();
    }

    if (D_001D52FC_00394020[0]->f1C0 & 0x10) {
        s32 m = func_003A3FB8(8, 0);
        if (D_001D52FC_00394020[0]->f1C0 & m) {
            D_001D5D5C_00394020 = 12;
        }
        func_00393F38(D_001D5D5C_00394020 > 0);
        if (D_001D5D58_00394020 != 0) {
            D_001D5D58_00394020 = 0;
            func_003A5748(0x15, 0, 0);
        }
    }
    {
        s32 t = D_001D5D5C_00394020 - 1;
        if (t < 0) {
            t = 0;
        }
        D_001D5D5C_00394020 = t;
    }
    p->f7C = 0x96;
    p->f6C = 0x18;
    if (func_0038CEE0(D_001A745E_00394020) != 0 && D_00143950_00394020[0].bB6 == 0) {
        D_001D52FC_00394020[0]->f1CC = 2;
    }

    pad = D_001D52FC_00394020[0];
    x = pad->f148;
    y = pad->f14C;
    mag = sqrt_asm(x * x + y * y);
    if (mag != 0.0f) {
        x = x / mag;
        y = y / mag;
    }
    ang = func_0038D540(x, y);

    if ((p->f78 >> 24) == 0) {
        if ((D_001D52FC_00394020[0]->f1C4 & 0xF000) != 0 || mag < 0.5f) {
            p->sel = -1;
            p->f78 = 0x10000FF;
        } else {
            s32 v = p->f78 - 1;
            p->f78 = v;
            if (v == -1) {
                p->sel = -1;
                p->f78 = 0x10000FF;
            }
        }
    }

    dir = 0;
    old = p->sel;
    if (((s8 *)&p->f78)[3] == 1 && (D_001D52FC_00394020[0]->f1C0 & 0x10)) {
        if (held == 0) {
            goto changed;
        }
        pad = D_001D52FC_00394020[0];
        if (0.9f < mag) {
            f32 n = (f32)D_001D9EE8_00394020[0];
            f32 a22 = ang + 3.1415927f + 3.1415927f + 1.5707964f + 3.1415927f / n;
            f32 a21 = a22 * (n / 6.2831855f);
            f32 a20 = ((f32)old * 6.2831855f) / n - 3.1415927f;
            s32 take = 1;
            if (old != -1) {
                f32 d = func_0038DF80(a20, func_0038DEE0(ang, 1.5707964f));
                if (!(0.58904862f < d)) {
                    take = 0;
                }
            }
            if (take) {
                s32 k = (s32)a21;
                s32 cnt = D_001D9EE8_00394020[0];
                s32 m = k % cnt;
                f32 r;
                if (((m ^ 1) & 1) != 0) {
                    f32 fr = a21 - (f32)k;
                    if (0.8f < fr) {
                        m = m + 1;
                    } else if (fr < 0.2f) {
                        m = m - 1;
                    }
                    m = (m + cnt) % cnt;
                }
                dir = -1;
                p->sel = m;
                r = func_0038DF28(a22 - ((f32)m * 0.78539819f + 0.39269909f));
                D_001D5D54_00394020 = r;
                if (0.0f < r) {
                    dir = 1;
                }
            }
        } else {
            s32 b;
            s32 v;
            if (pad->f1D8 != 0) {
                goto check;
            }
            b = pad->f1C4;
            if ((b & 0xF000) == 0) {
                goto check;
            }
            v = old;
            if (b & 0x1000) {
                v = (old == -1) ? D_001D5D08_00394020[0] : ROW_00394020[old].f10;
            }
            if (pad->f1C4 & 0x4000) {
                v = (v == -1) ? D_001D5D0C_00394020[0] : ROW_00394020[v].f14;
            }
            if (pad->f1C4 & 0x8000) {
                v = (v == -1) ? D_001D5D00_00394020[0] : ROW_00394020[v].f8;
            }
            if (pad->f1C4 & 0x2000) {
                v = (v == -1) ? D_001D5D04_00394020[0] : ROW_00394020[v].fC;
            }
            p->sel = v;
        }
check:
        sel = p->sel;
        if (ROW_00394020[sel].f0 == 0 && dir != 0) {
            s32 j = (sel + dir) % D_001D9EE8_00394020[0];
            if (ROW_00394020[j].f0 != 0) {
                p->sel = j;
            }
        }
    }

changed:
    if (p->sel != old) {
        func_003A2958();
        st[1] = 0;
        func_003A5748(3, 0, 0);
    } else if (st[1] < 8) {
        st[1] = st[1] + 1;
    }

    if (p->sel >= 0) {
        id = ROW_00394020[p->sel].id;
        if (func_0039AFE8(D_001DAA40_00394020[D_001425C0_00394020[id]].f10) == 0) {
            id = ROW_00394020[p->sel].id;
            func_0039AE18(D_001DAA40_00394020[D_001425C0_00394020[id]].f10);
            goto tail;
        }
    }

    if ((D_001D52FC_00394020[0]->f1C0 & 0x10) || D_001CCFD4_00394020[0] != 0) {
        if (st[0] < 8) {
            st[0] = st[0] + 1;
        }
        goto tail;
    }

    if (st[0] != 0) {
        st[0] = st[0] - 1;
        if (st[0] != 0) {
            goto closed;
        }
    }
    sel = p->sel;
    if (sel >= 0 && ROW_00394020[sel].id != 0) {
        if (D_001D5D58_00394020 == 0) {
            func_003A5748(4, 0, 0);
        }
        id = ROW_00394020[p->sel].id;
        D_001D5D5C_00394020 = 0;
        if (id == 0x25) {
            D_00143950_00394020[0].bA4 = 2;
            func_00381BB8(2);
        } else if (id == 0x24) {
            D_00143950_00394020[0].bA4 = 0;
            func_00381BB8(0);
        } else if (id == 0x26) {
            D_00143950_00394020[0].bA4 = 1;
            func_00381BB8(1);
        } else {
            T_00394020 *e;
            if (*(s32 *)(D_001A4BE0_00394020 + 0x1228) != id) {
                if (D_001A7C10_00394020[0].hF0 <= 0xFFFE) {
                    D_001A7C10_00394020[0].hF0 = D_001A7C10_00394020[0].hF0 + 1;
                }
            }
            {
                s32 q = (D_001D4C38_00394020[0] * 5 + 2) / 6;
                if (D_001A7C10_00394020[0].fF4 < (u32)q) {
                    D_001A7C10_00394020[0].fF4 = q;
                }
            }
            *(s32 *)(D_001A4BE0_00394020 + 0x25F8) = id;
            D_001A7C10_00394020[0].fF8 = D_001A7C10_00394020[0].fF8 | (1 << D_001D545C_00394020[0]) | 0x80000000;
            func_00381C80(id);
            e = &D_001DAA40_00394020[D_001425C0_00394020[id]];
            if (e->f84 != 0) {
                if ((s32)e->f8A < D_001427F0_00394020[id]) {
                    D_001427F0_00394020[id] = e->f8A;
                }
            }
        }
    }
closed:
    if (D_00143950_00394020[0].bB6 != 0) {
        func_003E4178();
    } else {
        func_00398068();
        func_00398060();
    }
    D_001D5D58_00394020 = 1;

tail:
    if (st[0] == 0) {
        D_001D9F2C_00394020[0] = p->f78;
        D_001D9F30_00394020 = p->sel;
        func_00393898(p->f64);
        p->f6C = -6;
        D_001D9F28_00394020[0] = D_001D9BC8_00394020[0];
    }
}
