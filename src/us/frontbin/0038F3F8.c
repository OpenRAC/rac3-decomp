#include "common.h"

/* NTSC-U counterpart of func_00393C40 (frontbin). */
extern s32 D_U_001D5CAC;
extern u8 D_001425C0[];
extern void func_U_0038F310(s32);

/* localdecomp:start func_U_0038F3F8 */
#include "vu0.h"
typedef struct {
    s32 f0;
    s32 f4;
    s32 nb[4];
    s32 id;
} Row_00393C40;
typedef struct {
    u8 pad0[0x64];
    s32 f64;
    u8 pad68[4];
    s32 f6C;
    u8 st[4];
    s32 sel;
    s32 timer;
    s32 f7C;
} O_00393C40;
typedef struct {
    u8 pad0[0x148];
    f32 x;
    f32 y;
    u8 pad150[0x1C0 - 0x150];
    s32 pressed;
    s32 held;
    u8 pad1C8[4];
    s32 f1CC;
    u8 pad1D0[8];
    s32 f1D8;
} Pad_00393C40;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x84 - 0x14];
    u16 f84;
    u8 pad86[4];
    u16 f8A;
    u8 pad8C[0xF0 - 0x8C];
} T_00393C40;
typedef struct { u8 pad0[0x1228]; s32 f1228; u8 pad122C[0x25F8 - 0x122C]; s32 f25F8; } W_00393C40;
typedef struct { u8 pad0[0xF0]; u16 fF0; u8 padF2[2]; u32 fF4; u32 fF8; } X_00393C40;

extern s32 D_U_00319090[];
typedef struct { u8 pad0[0xA4]; u8 bA4; u8 padA5[0xB6 - 0xA5]; u8 bB6; } N_00393C40;
extern N_00393C40 D_00143950_b_00393C40;
extern s32 D_U_001D5C78_0038F3F8;
extern s32 D_U_001D5C98;
extern s32 D_U_001D5D5C;
extern u8 D_U_001D5D58;
extern f32 D_U_001D5D54;
extern Pad_00393C40 *D_001D52FC_0038F3F8;
extern u8 D_001A745E_0038F3F8[];
extern s32 D_U_001D9F68_0038F3F8;
extern Row_00393C40 **D_U_001D9F70_0038F3F8;
/* nav defaults {6, 2, 0, 4} at D_001D5D00..0C, read as [2]..[5] (from rac2-decomp's func_0028BE00, D_001A8D90[2..5]) */
extern s32 D_U_001D5CF8_0038F3F8[] __attribute__((section(".sdata")));
extern T_00393C40 D_U_001DAAC0_0038F3F8[];
extern s16 D_001CCFD4[];
extern W_00393C40 D_001A4BE0_0038F3F8;
extern X_00393C40 D_001A7C10_0038F3F8;
extern s32 D_001427F0[];
extern s32 D_001D4C38_0038F3F8;
extern s32 D_001D545C;
extern s32 D_U_001D9FAC;
extern s32 D_U_001D9FB0;
extern s32 D_U_001D9FA8;
extern s32 D_U_001D9C48_0038F3F8;
__asm__(".extern D_U_001D5C98, 4");
__asm__(".extern D_U_001D5D5C, 4");
__asm__(".extern D_U_001D5D58, 1");
__asm__(".extern D_U_001D5CAC, 4");
extern s32 func_U_003DE8A0(void);
extern void func_U_003DE8B8(void);
extern void func_U_003DE870(void);
extern void func_U_003A95A0(void *, s32);
extern s32 func_U_0039E928(s32, s32);
extern s32 func_U_0039FF28(s32, s32, s32);
extern s32 func_U_003883C8(void *);
extern f32 func_U_00388A28(f32, f32);
extern f32 func_U_003893C8(f32, f32);
extern f32 func_U_00389468(f32, f32);
extern f32 func_U_00389410(f32);
extern void func_U_0039D4D0(void);
extern s32 func_U_00395E18(s32);
extern void func_U_00395C48(s32);
extern void func_U_0037DC50(s32);
extern void func_U_0037DD18(s32);
extern s32 func_U_0038EC80(s32);
extern void func_U_00393430(void);
extern s32 func_U_00393448(void);
extern void func_U_00393428(void);
extern void func_U_00393420(void);
extern void func_U_0038F310(s32);

/* from rac2-decomp's InfoOf (func_0028BE00): an item's entry in the D_001DAA40 table */
static __inline__ T_00393C40 *info_00393C40(s32 id) {
    return &D_U_001DAAC0_0038F3F8[D_001425C0[id]];
}

void func_U_0038F3F8(O_00393C40 *o) {
    s32 active;
    u8 *st;
    u8 *st0;
    s32 old;
    s32 dir;
    s32 sel;
    s32 id;
    s32 t;
    f32 x;
    f32 y;
    f32 len;
    f32 a;

    if (D_U_00319090[0] != 0) {
        return;
    }
    {
        s32 ok = 0;
        if (D_00143950_b_00393C40.bB6 == 0 || func_U_003DE8A0() != 0 || D_00143950_b_00393C40.bB6 == 0) {
            ok = 1;
        }
        active = ok;
    }
    if (D_00143950_b_00393C40.bB6 == 0) {
        func_U_00393430();
        if (func_U_00393448() == 0) {
            active = 0;
        }
    }
    st0 = o->st;
    if (active && D_U_001D5C78_0038F3F8 != 0) {
        void *p = (u8 *)D_U_001D5C78_0038F3F8 + 0x21548;
        func_U_003A95A0(p, func_U_003DE8A0() ? D_U_001D5C98 : 2);
        func_U_003DE8B8();
    }
    if (D_001D52FC_0038F3F8->pressed & 0x10) {
        if (D_001D52FC_0038F3F8->pressed & func_U_0039E928(8, 0)) {
            D_U_001D5D5C = 0xF;
        }
        func_U_0038F310(D_U_001D5D5C > 0);
        if (D_U_001D5D58) {
            D_U_001D5D58 = 0;
            func_U_0039FF28(0x15, 0, 0);
        }
    }
    t = D_U_001D5D5C;
    D_U_001D5D5C = (--t < 0) ? 0 : t;
    o->f7C = 0xB4;
    o->f6C = 0x18;
    if (func_U_003883C8(D_001A745E_0038F3F8) && D_00143950_b_00393C40.bB6 == 0) {
        D_001D52FC_0038F3F8->f1CC = 2;
    }
    x = D_001D52FC_0038F3F8->x;
    y = D_001D52FC_0038F3F8->y;
    len = sqrt_asm(x * x + y * y);
    if (len != 0.0f) {
        x /= len;
        y /= len;
    }
    a = func_U_00388A28(x, y);
    if ((o->timer >> 24) == 0) {
        if ((D_001D52FC_0038F3F8->held & 0xF000) || len < 0.5f || --o->timer == -1) {
            o->sel = -1;
            o->timer = 0x10000FF;
        }
    }
    dir = 0;
    old = o->sel;
    if ((o->timer >> 24) == 1 && (D_001D52FC_0038F3F8->pressed & 0x10) && active) {
        Pad_00393C40 *pad = D_001D52FC_0038F3F8;
        Row_00393C40 *row;
        if (0.9f < len) {
            f32 n = (f32)D_U_001D9F68_0038F3F8;
            f32 b = a + 3.1415927f + 3.1415927f + 1.5707964f + 3.1415927f / n;
            f32 pos = b * (n / 6.2831855f);
            f32 c = (f32)old * 6.2831855f / n - 3.1415927f;
            if (old == -1 || 0.58904862f < func_U_00389468(c, func_U_003893C8(a, 1.5707964f))) {
                s32 i = (s32)pos;
                s32 m = i % D_U_001D9F68_0038F3F8;
                if ((m ^ 1) & 1) {
                    f32 frac = pos - (f32)i;
                    if (0.8f < frac) {
                        m++;
                    } else if (frac < 0.2f) {
                        m--;
                    }
                    m = (m + D_U_001D9F68_0038F3F8) % D_U_001D9F68_0038F3F8;
                }
                dir = -1;
                o->sel = m;
                D_U_001D5D54 = func_U_00389410(b - ((f32)m * 0.7853982f + 0.3926991f));
                if (0.0f < D_U_001D5D54) {
                    dir = 1;
                }
            }
        } else if (pad->f1D8 == 0) {
            if (pad->held & 0xF000) {
                s32 s = old;
                s32 t;
                if (D_001D52FC_0038F3F8->held & 0x1000) {
                    if (s == -1) t = D_U_001D5CF8_0038F3F8[4]; else t = D_U_001D9F70_0038F3F8[D_U_001D5CAC][s].nb[2];
                    s = t;
                }
                if (D_001D52FC_0038F3F8->held & 0x4000) {
                    if (s == -1) t = D_U_001D5CF8_0038F3F8[5]; else t = D_U_001D9F70_0038F3F8[D_U_001D5CAC][s].nb[3];
                    s = t;
                }
                if (D_001D52FC_0038F3F8->held & 0x8000) {
                    if (s == -1) t = D_U_001D5CF8_0038F3F8[2]; else t = D_U_001D9F70_0038F3F8[D_U_001D5CAC][s].nb[0];
                    s = t;
                }
                if (D_001D52FC_0038F3F8->held & 0x2000) {
                    if (s == -1) t = D_U_001D5CF8_0038F3F8[3]; else t = D_U_001D9F70_0038F3F8[D_U_001D5CAC][s].nb[1];
                    s = t;
                }
                o->sel = s;
            }
        }
        row = D_U_001D9F70_0038F3F8[D_U_001D5CAC];
        sel = o->sel;
        if (row[sel].f0 == 0 && dir != 0) {
            t = (sel + dir) % D_U_001D9F68_0038F3F8;
            if (row[t].f0 != 0) {
                o->sel = t;
            }
        }
    }
    st = o->st;
    if (o->sel != old) {
        func_U_0039D4D0();
        st[1] = 0;
        func_U_0039FF28(3, 0, 0);
    } else if (st[1] < 8) {
        st[1]++;
    }
    if (o->sel >= 0 && func_U_00395E18(info_00393C40(D_U_001D9F70_0038F3F8[D_U_001D5CAC][o->sel].id)->f10) == 0) {
        func_U_00395C48(info_00393C40(D_U_001D9F70_0038F3F8[D_U_001D5CAC][o->sel].id)->f10);
    } else {
        if (!(D_001D52FC_0038F3F8->pressed & 0x10) && D_001CCFD4[0] == 0) {
            if (st[0] == 0 || --st[0] == 0) {
                if (o->sel >= 0 && D_U_001D9F70_0038F3F8[D_U_001D5CAC][o->sel].id != 0) {
                    if (D_U_001D5D58 == 0) {
                        func_U_0039FF28(4, 0, 0);
                    }
                    id = D_U_001D9F70_0038F3F8[D_U_001D5CAC][o->sel].id;
                    D_U_001D5D5C = 0;
                    switch (id) {
                    case 0x24:
                        D_00143950_b_00393C40.bA4 = 0;
                        func_U_0037DC50(0);
                        break;
                    case 0x25:
                        D_00143950_b_00393C40.bA4 = 2;
                        func_U_0037DC50(2);
                        break;
                    case 0x26:
                        D_00143950_b_00393C40.bA4 = 1;
                        func_U_0037DC50(1);
                        break;
                    default: {
                        T_00393C40 *t;
                        u32 v;
                        if (D_001A4BE0_0038F3F8.f1228 != id) {
                            if (D_001A7C10_0038F3F8.fF0 < 0xFFFF) {
                                D_001A7C10_0038F3F8.fF0++;
                            }
                        }
                        v = D_001D4C38_0038F3F8;
                        if (D_001A7C10_0038F3F8.fF4 < v) {
                            D_001A7C10_0038F3F8.fF4 = v;
                        }
                        D_001A7C10_0038F3F8.fF8 = D_001A7C10_0038F3F8.fF8 | (1 << D_001D545C) | 0x80000000;
                        D_001A4BE0_0038F3F8.f25F8 = id;
                        func_U_0037DD18(id);
                        t = info_00393C40(id);
                        if (t->f84 != 0) {
                            if (t->f8A < D_001427F0[id]) {
                                D_001427F0[id] = t->f8A;
                            }
                        }
                        break;
                    }
                    }
                }
            }
            if (D_00143950_b_00393C40.bB6 != 0) {
                func_U_003DE870();
            } else {
                func_U_00393428();
                func_U_00393420();
            }
            D_U_001D5D58 = 1;
        } else if (st[0] < 8) {
            st[0]++;
        }
    }
    if (st0[0] == 0) {
        D_U_001D9FB0 = o->sel;
        D_U_001D9FAC = o->timer;
        func_U_0038EC80(o->f64);
        o->f6C = -6;
        D_U_001D9FA8 = D_U_001D9C48_0038F3F8;
    }
}
/* localdecomp:end func_U_0038F3F8 */
