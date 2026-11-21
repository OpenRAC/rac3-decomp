/* functional: high. Rewritten from the PAL boot_elf assembly (frontbin twin func_00395478 unmatched, no draft). Retail's y-scaling is an inline with two identical arms on D_001DA070 == 1 (both add 0.0f), written once here; its dead loads of D_001DA070 are dropped. Register allocation and block order differ. */
typedef struct {
    u8 pad0[0x58]; s32 f58; u8 pad5C[0x70 - 0x5C];
    u8 st[2]; u8 pad72[2]; s32 sel;
} P_00395858;
typedef struct { s32 f0; s32 type; s32 f8; s32 fC; s32 f10; s32 f14; s32 id; } E_00395858;
typedef struct { s32 w[4]; } Q_00395858;

extern s16 D_001D9EB4_bf5858[];
extern s16 D_001D9EB6_bf5858[];
extern s16 D_001D9EB8_bf5858[];
extern s16 D_001D9EBA_bf5858[];
extern s16 D_001D9EBC_bf5858[];
extern s32 D_001D5C78_bf5858[];
extern f32 D_001DA074_bf5858[];
extern s32 D_001D9EE8_bf5858[];
extern s32 D_001D5CAC_bf5858;
extern E_00395858 **D_001D9EF0_bf5858[];
extern u8 D_001D5DA8_bf5858;
extern s32 D_001D5D88_bf5858;
extern s32 D_001D5D90_bf5858;
extern s32 D_001D5D8C_bf5858[];
extern s32 D_001D5D94_bf5858[];
extern Q_00395858 D_001D5D98_bf5858[];
extern Q_00395858 D_001D5DB0_bf5858[];

extern void func_003AA060(s32);
extern s32 func_003AC190(u8 *, s32);
extern void func_003AA6D8(s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003829D8(s32, s32, s32, s32, s32, s32);
extern f32 func_0038DE98(f32, f32);
extern f32 func_0038D478(f32);
extern f32 func_0038D490(f32);
extern s32 func_00396D48(s32, s32);
extern void func_00397230(s32 idx, s32 x, s32 y, s32 w, s32 h, s32 *uv);
extern s32 func_003823D0(s32);
extern s32 func_0011B868(s32);
extern s32 func_0038DFB8(s32, s32, f32);
extern s32 func_00391198(s32, s32, unsigned long, s32, s32);

static __inline__ s32 ys_00395858(f32 v) {
    return (s32)(v * D_001DA074_bf5858[0] + 0.5f + 0.0f);
}

/* clank_ring_draw (boot_elf copy of frontbin func_00395478): draws Clank's gadget ring:
 * the ring sprites, the selector, each slot's icon (tinted by type and whether it is owned),
 * the centre icon, and the selected slot's name with a fade. Returns p->f58. */
s32 func_00395858(P_00395858 *p) {
    Q_00395858 cols;     /* sp+0x00 */
    Q_00395858 cols10;   /* sp+0x10 */
    Q_00395858 uv20;     /* sp+0x20 */
    Q_00395858 buf30;    /* sp+0x30 */
    f32 open, sub;
    s32 owned;
    s32 found;
    s32 any;
    s32 i;
    u8 *tex;

    open = (f32)p->st[0] * 0.125f;
    owned = D_001D9EB8_bf5858[0] + D_001D9EBC_bf5858[0] + D_001D9EBA_bf5858[0];
    if (1.0f < open) {
        open = 1.0f;
    } else if (open < 0.0f) {
        open = 0.0f;
    }
    sub = (f32)p->st[1] * 0.125f;
    if (1.0f < sub) {
        sub = 1.0f;
    } else if (sub < 0.0f) {
        sub = 0.0f;
    }

    func_003AA060(1);
    tex = (u8 *)D_001D5C78_bf5858[0] + 0x7090;
    func_003AA6D8(func_003AC190((u8 *)D_001D5C78_bf5858[0] + 0x7090, 0x88), 0x41083471, 129.0f, (f32)ys_00395858(208.0f), 1.0f, 1.0f, 0.0f);
    func_003AA6D8(func_003AC190((u8 *)D_001D5C78_bf5858[0] + 0x7090, 0x88), 0x41083471, 129.0f, (f32)ys_00395858(208.0f), -1.0f, 1.0f, 0.0f);
    func_003AA6D8(func_003AC190((u8 *)D_001D5C78_bf5858[0] + 0x7090, 0x87), 0x462299DE, 129.0f, (f32)ys_00395858(208.0f), 1.0f, 1.0f, 0.0f);
    func_003AA6D8(func_003AC190((u8 *)D_001D5C78_bf5858[0] + 0x7090, 0x87), 0x462299DE, 129.0f, (f32)ys_00395858(208.0f), -1.0f, 1.0f, 0.0f);
    func_003AA6D8(func_003AC190((u8 *)D_001D5C78_bf5858[0] + 0x7090, 0x86), 0x462299DE, 129.0f, (f32)ys_00395858(208.0f), 1.0f, 1.0f, 0.0f);
    func_003AA6D8(func_003AC190((u8 *)D_001D5C78_bf5858[0] + 0x7090, 0x86), 0x462299DE, 129.0f, (f32)ys_00395858(208.0f), -1.0f, 1.0f, 0.0f);
    (void)tex;

    if (p->sel >= 0) {
        s32 c = func_003829D8(0x80442D00, 0x80FFDE8D, 0x19, 0, 0, 0);
        f32 rot;
        cols.w[0] = c;
        rot = (f32)(p->sel - 1);
        if (rot < 0.0f) {
            rot = 3.0f;
        }
        func_003AA6D8(func_003AC190((u8 *)D_001D5C78_bf5858[0] + 0x7090, 0x89), cols.w[0], 129.0f, (f32)ys_00395858(208.0f), 1.0f, 1.0f, rot);
    }

    D_001D5DA8_bf5858 = D_001D5DA8_bf5858 + 1;
    any = 0;
    found = 0;
    uv20 = D_001D5D98_bf5858[0];

    for (i = 0; i < D_001D9EE8_bf5858[0]; i++) {
        f32 n = (f32)D_001D9EE8_bf5858[0];
        f32 a = func_0038DE98(((f32)i + (f32)i) * 3.1415927f / n - 3.1415927f + 0.0f, 1.5707964f);
        s32 x = D_001D5D88_bf5858 + (s32)((f32)D_001D5D90_bf5858 * func_0038D478(a));
        s32 y = D_001D5D8C_bf5858[0] + (s32)((f32)D_001D5D94_bf5858[0] * func_0038D490(a));
        E_00395858 *e = &D_001D9EF0_bf5858[0][D_001D5CAC_bf5858][i];

        if (e->f0 != 0) {
            s32 type = e->type;
            s32 tinted = 0;
            s32 lit = 0;
            s32 col = 0;
            s32 v;

            if (type == 6 && D_001D9EB6_bf5858[0] == 0) {
                type = 7;
            }
            switch (type) {
            case 0:
                if (D_001D9EB4_bf5858[0] != 0 && owned < D_001D9EB4_bf5858[0]) {
                    col = 0x600000FF;
                    tinted = 1;
                }
                break;
            case 1:
                if (D_001D9EB4_bf5858[0] != 0 && owned < D_001D9EB4_bf5858[0]) {
                    col = 0x60FF0000;
                    tinted = 1;
                }
                break;
            case 2:
                if (D_001D9EB4_bf5858[0] != 0) {
                    col = 0x6000FF00;
                    tinted = 1;
                }
                break;
            case 3:
                if (D_001D9EB4_bf5858[0] != 0) {
                    col = 0x6029A1FF;
                    tinted = 1;
                }
                break;
            case 4:
                v = D_001D9EBA_bf5858[0];
                goto owned_check;
            case 6:
            case 7:
                v = D_001D9EB8_bf5858[0];
                goto owned_check;
            case 8:
                v = D_001D9EBC_bf5858[0];
                goto owned_check;
            case 9:
                v = D_001D9EB4_bf5858[0];
            owned_check:
                if (v != 0) {
                    lit = 1;
                    if (i == p->sel) {
                        found = 1;
                    }
                }
                break;
            }
            if (tinted) {
                if (i == p->sel) {
                    found = 1;
                }
                cols.w[0] = col;
                cols.w[1] = col;
                cols.w[2] = col;
                cols.w[3] = col;
                lit = 1;
            }

            if (tinted) {
                func_00397230(func_00396D48(e->f0, 10), x + 2, ys_00395858((f32)(y + 2)), ys_00395858(28.0f), 0x1A, cols.w);
            }

            if (lit) {
                if (p->sel == i) {
                    col = (D_001D5DA8_bf5858 & 0x10) ? 0x80FFFFFF : 0x706EC8FF;
                } else {
                    col = 0x706EC8FF;
                }
            } else {
                col = 0x40808080;
            }
            cols10.w[0] = col;
            cols10.w[1] = col;
            cols10.w[2] = col;
            cols10.w[3] = col;

            func_00397230(func_00396D48(e->f0, type), x + 2, ys_00395858((f32)(y + 2)), ys_00395858(30.0f), 0x1C, uv20.w);
            func_00397230(func_00396D48(e->f0, type), x, ys_00395858((f32)y), ys_00395858(30.0f), 0x1C, cols10.w);
            any = lit;
        }
    }

    {
        s32 c;
        if (any) {
            c = (D_001D5DA8_bf5858 & 0x10) ? 0x80FFFFFF : 0x7069C3F0;
        } else {
            c = 0x3869C3F0;
        }
        buf30.w[0] = c;
        buf30.w[1] = c;
        buf30.w[2] = c;
        buf30.w[3] = c;
    }
    func_00397230(func_00396D48(0xED47, 0), D_001D5D88_bf5858 + 2, ys_00395858((f32)(D_001D5D8C_bf5858[0] + 2)), ys_00395858(30.0f), 0x1C, uv20.w);
    func_00397230(func_00396D48(0xED47, 0), D_001D5D88_bf5858, ys_00395858((f32)D_001D5D8C_bf5858[0]), ys_00395858(30.0f), 0x1C, buf30.w);

    if (found && p->sel >= 0 && p->sel < 4) {
        s32 str;
        buf30 = D_001D5DB0_bf5858[0];
        str = func_003823D0(buf30.w[p->sel]);
        if (str != 0 && func_0011B868(str) != 0) {
            f32 f = sub * open;
            s32 c1 = func_0038DFB8(0x66CCFF, 0x8066CCFF, f);
            s32 c2 = func_0038DFB8(0, 0x80000000, f);
            func_00391198(0x83, ys_00395858(287.0f), c2, str, -1);
            func_00391198(0x81, ys_00395858(285.0f), c1, str, -1);
        }
    }
    return p->f58;
}
