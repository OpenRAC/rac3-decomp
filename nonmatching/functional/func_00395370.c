/* functional: high. Rewritten from the PAL boot_elf assembly (the nonmatching draft is a US port and was not used: it had f7C = 180 and callee func_003829F8 where PAL has 150 and func_003829D8). Register allocation and block order differ from retail. */
#include "vu0.h"
typedef struct {
    u8 pad0[0x64]; s32 f64; u8 pad68[4]; s32 f6C;
    u8 st[2]; u8 pad72[2]; s32 sel; s32 f78; s32 f7C;
} P_00395370;
typedef struct {
    u8 pad0[0x148]; f32 f148; f32 f14C; u8 pad150[0x1C0 - 0x150];
    s32 f1C0; s32 f1C4; s32 f1C8; s32 f1CC;
} Pad_00395370;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 id; } E_00395370;

extern Pad_00395370 *D_001D52FC_bf5370[];
extern s16 D_001D9EB4_bf5370[];
extern s16 D_001D9EB8_bf5370[];
extern s16 D_001D9EBA_bf5370[];
extern s16 D_001D9EBC_bf5370[];
extern s32 D_001D9EE8_bf5370;
extern s32 D_001D5CAC_bf5370;
extern E_00395370 **D_001D9EF0_bf5370[];
extern s32 D_001D5D20_bf5370[];
extern s32 D_001D5D24_bf5370[];
extern s32 D_001D5D28_bf5370[];
extern s32 D_001D5D2C_bf5370[];
extern u8 D_001A4BE0_bf5370[];
extern u8 D_00143A06_bf5370[];
extern s32 D_001D9F2C_bf5370[];
extern s32 D_001D9F30_bf5370;
extern s32 D_001D9BC8_bf5370[];
extern s32 D_001D9F28_bf5370[];

extern void func_003E41C0(void);
extern f32 func_0038D540(f32, f32);
extern void func_003829D8(s32, s32, s32, s32, s32, s32);
extern s32 func_003A5748(s32, s32, s32);
extern void func_003E4178(void);
extern s32 func_00393898(s32);

#define ROW_00395370 (D_001D9EF0_bf5370[0][D_001D5CAC_bf5370])
#define SLOT_00395370 (*(s32 *)(D_001A4BE0_bf5370 + 0x286C))

/* Gadget quick-select ring update (boot_elf copy of frontbin func_00394F90): like the
 * weapon ring, the stick past 0.9 or the d-pad picks a slot; while open, a press stores
 * the slot's id into D_001A4BE0+0x286C; ids 5/6/7 are cleared when not owned. */
void func_00395370(P_00395370 *p) {
    u8 *st = p->st;
    Pad_00395370 *pad;
    f32 x, y, mag, ang;
    s32 old;

    func_003E41C0();
    p->f7C = 0x96;
    p->f6C = 0x18;
    pad = D_001D52FC_bf5370[0];
    x = pad->f148;
    y = pad->f14C;
    pad->f1CC = 2;
    mag = sqrt_asm(x * x + y * y);
    if (mag != 0.0f) {
        x = x / mag;
        y = y / mag;
    }
    ang = func_0038D540(x, y);

    if ((p->f78 >> 24) == 0 && D_001D9EB4_bf5370[0] != 0) {
        if ((D_001D52FC_bf5370[0]->f1C4 & 0xF000) != 0 || mag < 0.5f) {
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

    old = p->sel;
    if (((s8 *)&p->f78)[3] == 1) {
        if (0.0f < mag) {
            if (0.9f < mag) {
                s32 n = D_001D9EE8_bf5370;
                f32 fn = (f32)n;
                f32 a = ang + 3.1415927f + 3.1415927f + 1.5707964f + 3.1415927f / fn;
                p->sel = (s32)(a * (fn / 6.2831855f)) % n;
            }
        } else {
            pad = D_001D52FC_bf5370[0];
            if (pad->f1C4 & 0xF000) {
                s32 v = old;
                if (pad->f1C4 & 0x1000) {
                    v = (old == -1) ? D_001D5D28_bf5370[0] : ROW_00395370[old].f10;
                }
                if (pad->f1C4 & 0x4000) {
                    v = (v == -1) ? D_001D5D2C_bf5370[0] : ROW_00395370[v].f14;
                }
                if (pad->f1C4 & 0x8000) {
                    v = (v == -1) ? D_001D5D20_bf5370[0] : ROW_00395370[v].f8;
                }
                if (D_001D52FC_bf5370[0]->f1C4 & 0x2000) {
                    v = (v == -1) ? D_001D5D24_bf5370[0] : ROW_00395370[v].fC;
                }
                p->sel = v;
            }
        }
    }

    if (p->sel != old) {
        func_003829D8(0, 0, 1, 0, 1, 0);
        st[1] = 0;
        func_003A5748(3, 0, 0);
    } else if (st[1] < 8) {
        st[1] = st[1] + 1;
    }

    if (D_001D52FC_bf5370[0]->f1C0 & 0x10) {
        if (st[0] < 8) {
            st[0] = st[0] + 1;
        }
    } else {
        if (D_001D52FC_bf5370[0]->f1C8 & 0x10) {
            if (p->sel == -1) {
                SLOT_00395370 = 0;
            } else {
                SLOT_00395370 = ROW_00395370[p->sel].id;
            }
        }
        if (D_00143A06_bf5370[0] != 0) {
            func_003E4178();
        }
        if (st[0] != 0) {
            st[0] = st[0] - 1;
        }
    }

    if (SLOT_00395370 == 6 && D_001D9EB8_bf5370[0] == 0) {
        SLOT_00395370 = 0;
    }
    if (SLOT_00395370 == 7 && D_001D9EBC_bf5370[0] == 0) {
        SLOT_00395370 = 0;
    }
    if (SLOT_00395370 == 5 && D_001D9EBA_bf5370[0] == 0) {
        SLOT_00395370 = 0;
    }

    if (st[0] == 0) {
        D_001D9F2C_bf5370[0] = p->f78;
        D_001D9F30_bf5370 = p->sel;
        func_00393898(p->f64);
        p->f6C = -6;
        D_001D9F28_bf5370[0] = D_001D9BC8_bf5370[0];
    }
}
