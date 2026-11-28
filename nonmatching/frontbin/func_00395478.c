/* PAL near miss (wave 13 r21, 2026-11-28): 777 differences (build/codex/wave10/p10/check.py, frontbin, the file's flags; positional count). First draft, written from the retail assembly: the weapon-wheel HUD (two fade factors from self+0x70/0x71 clamped to 0..1, six frame sprites 0x88/0x87/0x86 through func_003ABDD8 + func_003AA320, the selection sprite 0x89 with func_003825F8's colour, then one slot per D_001D9EE8 entry placed on a circle with func_0038DAB8/func_0038D098/func_0038D0B0, its type switch (retail's jump table jtbl_0031C0C0: cases 0-3 tint by ammo with D_001D9EB4 and the sum of D_001D9EB8/EBA/EBC, 4 and 6-9 test one counter, 5 nothing, type 6 becomes 7 without D_001D9EB6), func_00396968 + func_00396E50 for the shadow and the icon, the centre icon 0xED47 and the selected weapon's name through func_00381FF0/func_0011B868/func_0038DBD8/func_00390DB8; returns self+0x58). The y rounding is a small inline (v + 0.5f, then the same zero added on both arms of D_001DA070 == 1), which leaves retail's dead li 1 / lw D_001DA070; the lui-form globals carry 16-byte .extern hints and the $gp ones (D_001D5CAC, D_001D5DA8, D_001D5D88, D_001D5D90) 4/1-byte ones. Left: self in fp where retail keeps it in s4, the order of the 208.0/0.5 constant loads in the rounding (one hazard nop more here), and everything after that shift; the switch's case bodies and the per-slot colour stores are written from the listing and not yet compared one by one. */
#include "common.h"

/* localdecomp:start func_00395478 */
typedef struct {
    u8 pad0[0x58];
    s32 f58;
    u8 pad5C[0x14];
    u8 f70;
    u8 f71;
    u8 pad72[2];
    s32 f74;
} Hud_00395478;

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad8[0x14];
} Slot_00395478;

typedef struct {
    s32 c[4];
} Cols_00395478;

extern s16 D_001D9EB4;
extern s16 D_001D9EB6;
extern s16 D_001D9EB8;
extern s16 D_001D9EBA;
extern s16 D_001D9EBC;
extern u8 *D_001D5C78;
extern s32 D_001DA070;
extern f32 D_001DA074;
extern s32 D_001D9EE8;
extern Slot_00395478 **D_001D9EF0;
extern s32 D_001D5CAC;
extern u8 D_001D5DA8;
extern s32 D_001D5D88;
extern s32 D_001D5D8C;
extern s32 D_001D5D90;
extern s32 D_001D5D94;
extern Cols_00395478 D_001D5D98;
extern Cols_00395478 D_001D5DB0;
__asm__(".extern D_001D9EB4, 16");
__asm__(".extern D_001D9EB6, 16");
__asm__(".extern D_001D9EB8, 16");
__asm__(".extern D_001D9EBA, 16");
__asm__(".extern D_001D9EBC, 16");
__asm__(".extern D_001D5C78, 16");
__asm__(".extern D_001DA070, 16");
__asm__(".extern D_001DA074, 16");
__asm__(".extern D_001D9EE8, 16");
__asm__(".extern D_001D9EF0, 16");
__asm__(".extern D_001D5D8C, 16");
__asm__(".extern D_001D5D94, 16");
__asm__(".extern D_001D5CAC, 4");
__asm__(".extern D_001D5DA8, 1");
__asm__(".extern D_001D5D88, 4");
__asm__(".extern D_001D5D90, 4");

static __inline__ s32 Round_00395478(f32 v) {
    f32 zero = 0.0f;
    f32 r = v + 0.5f;

    if (D_001DA070 == 1) {
        return (s32)(r + zero);
    }
    return (s32)(r + zero);
}

extern void func_003A9CA8(s32);
extern s32 func_003ABDD8(u8 *, s32);
extern void func_003AA320(s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003825F8(s32, s32, s32, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00396968(s32, s32);
extern void func_00396E50(s32, s32, s32, s32, s32, Cols_00395478 *);
extern char *func_00381FF0(s32);
extern s32 func_0011B868(char *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_00390DB8(s32, s32, s32, char *, s32);

s32 func_00395478(Hud_00395478 *self) {
    Cols_00395478 hl;
    Cols_00395478 cols;
    Cols_00395478 base;
    Cols_00395478 frame;
    f32 a;
    f32 b;
    f32 f;
    s32 sum;
    s32 found;
    s32 sel;
    s32 i;
    u8 *fade = &self->f70;

    a = fade[0] * 0.125f;
    sum = D_001D9EB8 + D_001D9EBC + D_001D9EBA;
    if (1.0f < a) {
        a = 1.0f;
    } else if (a < 0.0f) {
        a = 0.0f;
    }
    b = fade[1] * 0.125f;
    if (1.0f < b) {
        b = 1.0f;
    } else if (b < 0.0f) {
        b = 0.0f;
    }
    func_003A9CA8(1);
    func_003AA320(func_003ABDD8(D_001D5C78 + 0x7090, 0x88), 0x41083471, 129.0f, (f32)Round_00395478(D_001DA074 * 208.0f), 1.0f, 1.0f, 0.0f);
    func_003AA320(func_003ABDD8(D_001D5C78 + 0x7090, 0x88), 0x41083471, 129.0f, (f32)Round_00395478(D_001DA074 * 208.0f), -1.0f, 1.0f, 0.0f);
    func_003AA320(func_003ABDD8(D_001D5C78 + 0x7090, 0x87), 0x462299DE, 129.0f, (f32)Round_00395478(D_001DA074 * 208.0f), 1.0f, 1.0f, 0.0f);
    func_003AA320(func_003ABDD8(D_001D5C78 + 0x7090, 0x87), 0x462299DE, 129.0f, (f32)Round_00395478(D_001DA074 * 208.0f), -1.0f, 1.0f, 0.0f);
    func_003AA320(func_003ABDD8(D_001D5C78 + 0x7090, 0x86), 0x462299DE, 129.0f, (f32)Round_00395478(D_001DA074 * 208.0f), 1.0f, 1.0f, 0.0f);
    func_003AA320(func_003ABDD8(D_001D5C78 + 0x7090, 0x86), 0x462299DE, 129.0f, (f32)Round_00395478(D_001DA074 * 208.0f), -1.0f, 1.0f, 0.0f);
    if (self->f74 >= 0) {
        s32 col = func_003825F8(0x80442D00, 0x80FFDE8D, 0x19, 0, 0, 0);

        f = (f32)(self->f74 - 1);
        if (f < 0.0f) {
            f = 3.0f;
        }
        func_003AA320(func_003ABDD8(D_001D5C78 + 0x7090, 0x89), col, 129.0f, (f32)Round_00395478(D_001DA074 * 208.0f), 1.0f, 1.0f, f);
    }
    D_001D5DA8++;
    sel = 0;
    found = 0;
    base = D_001D5D98;
    for (i = 0; i < D_001D9EE8; i++) {
        f32 ang;
        s32 x;
        s32 y;
        s32 type;
        s32 lit;
        s32 on;
        Slot_00395478 *slot;

        ang = func_0038DAB8(((f32)i + (f32)i) * 3.1415927f / (f32)D_001D9EE8 - 3.1415927f + 0.0f, 1.5707964f);
        x = D_001D5D88 + (s32)((f32)D_001D5D90 * func_0038D098(ang));
        y = D_001D5D8C + (s32)((f32)D_001D5D94 * func_0038D0B0(ang));
        slot = &D_001D9EF0[D_001D5CAC][i];
        if (slot->f0 == 0) {
            continue;
        }
        type = slot->f4;
        lit = 0;
        on = 0;
        if (type == 6 && D_001D9EB6 == 0) {
            type = 7;
        }
        switch (type) {
        case 0:
            if (D_001D9EB4 != 0 && sum < D_001D9EB4) {
                hl.c[3] = 0x600000FF;
                goto mark;
            }
            break;
        case 1:
            if (D_001D9EB4 != 0 && sum < D_001D9EB4) {
                hl.c[3] = 0x60FF0000;
                goto mark;
            }
            break;
        case 2:
            if (D_001D9EB4 != 0) {
                hl.c[3] = 0x6000FF00;
                goto mark;
            }
            break;
        case 3:
            if (D_001D9EB4 != 0) {
                hl.c[3] = 0x6029A1FF;
            mark:
                if (i == self->f74) {
                    found = 1;
                }
                hl.c[0] = hl.c[3];
                hl.c[1] = hl.c[3];
                hl.c[2] = hl.c[3];
                lit = 1;
                on = 1;
            }
            break;
        case 4:
            if (D_001D9EBA != 0) {
                goto have;
            }
            break;
        case 6:
        case 7:
            if (D_001D9EB8 != 0) {
                goto have;
            }
            break;
        case 8:
            if (D_001D9EBC != 0) {
                goto have;
            }
            break;
        case 9:
            if (D_001D9EB4 != 0) {
            have:
                on = 1;
                if (i == self->f74) {
                    found = 1;
                }
            }
            break;
        }
        if (lit) {
            func_00396E50(func_00396968(slot->f0, 10), x + 2, Round_00395478((f32)(y + 2) * D_001DA074), Round_00395478(D_001DA074 * 28.0f), 0x1A, &hl);
        }
        if (on) {
            s32 c;

            if (self->f74 == i) {
                c = (D_001D5DA8 & 0x10) ? 0x80FFFFFF : 0x706EC8FF;
            } else {
                c = 0x706EC8FF;
            }
            cols.c[3] = c;
            cols.c[0] = c;
            cols.c[1] = c;
            cols.c[2] = c;
        } else {
            cols.c[3] = 0x40808080;
            cols.c[0] = 0x40808080;
            cols.c[1] = 0x40808080;
            cols.c[2] = 0x40808080;
        }
        func_00396E50(func_00396968(slot->f0, type), x + 2, Round_00395478((f32)(y + 2) * D_001DA074), Round_00395478(D_001DA074 * 30.0f), 0x1C, &base);
        func_00396E50(func_00396968(slot->f0, type), x, Round_00395478((f32)y * D_001DA074), Round_00395478(D_001DA074 * 30.0f), 0x1C, &cols);
        sel = on;
    }
    {
        s32 c;

        if (sel) {
            c = (D_001D5DA8 & 0x10) ? 0x80FFFFFF : 0x7069C3F0;
        } else {
            c = 0x3869C3F0;
        }
        frame.c[3] = c;
        frame.c[0] = c;
        frame.c[1] = c;
        frame.c[2] = c;
    }
    func_00396E50(func_00396968(0xED47, 0), D_001D5D88 + 2, Round_00395478((f32)(D_001D5D8C + 2) * D_001DA074), Round_00395478(D_001DA074 * 30.0f), 0x1C, &base);
    func_00396E50(func_00396968(0xED47, 0), D_001D5D88, Round_00395478((f32)D_001D5D8C * D_001DA074), Round_00395478(D_001DA074 * 30.0f), 0x1C, &frame);
    if (found && self->f74 >= 0 && self->f74 < 4) {
        char *str;

        frame = D_001D5DB0;
        str = func_00381FF0(frame.c[self->f74]);
        if (str != 0 && func_0011B868(str) != 0) {
            s32 c1;
            s32 c2;

            f = b * a;
            c1 = func_0038DBD8(0x0066CCFF, 0x8066CCFF, f);
            c2 = func_0038DBD8(0, 0x80000000, f);
            func_00390DB8(0x83, Round_00395478(D_001DA074 * 287.0f), c2, str, -1);
            func_00390DB8(0x81, Round_00395478(D_001DA074 * 285.0f), c1, str, -1);
        }
    }
    return self->f58;
}
/* localdecomp:end func_00395478 */
