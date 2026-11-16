#include "common.h"

/* NTSC-U counterpart of func_L39_006C5CC8 (src/levels/39_multiplayer_menu/L39_006C5CC8.c) */
typedef struct {
    s32 f0;
    s32 f4;
    s32 pad[2];
} S_006C5B60;
extern S_006C5B60 D_L39_004B1598[][25];
extern u8 D_L39_002498A8[];
extern void *func_0037DF98(s32);
extern s32 func_00120048(char *, char *, ...);

/* localdecomp:start func_L39_006C31B8 */
typedef struct W_006C5CC8 W_006C5CC8;
typedef struct V_006C5CC8 {
    u8 pad0[0x1C];
    s32 (*f1C)(W_006C5CC8 *, s32, s32);
    u8 pad20[0x30 - 0x20];
    void (*f30)(W_006C5CC8 *, f32 *, f32 *);
    u8 pad34[0x50 - 0x34];
    void (*f50)(W_006C5CC8 *, u32);
    u8 pad54[0x78 - 0x54];
    s32 (*f78)(W_006C5CC8 *);
    u8 pad7C[0x88 - 0x7C];
    void (*f88)(W_006C5CC8 *, s32);
    s32 (*f8C)(W_006C5CC8 *);
    u8 pad90[0x9C - 0x90];
    s32 (*f9C)(W_006C5CC8 *, f32 *, f32 *);
    s32 (*fA0)(W_006C5CC8 *, f32 *, f32 *);
    u8 padA4[0xC4 - 0xA4];
    s32 (*fC4)(W_006C5CC8 *);
} V_006C5CC8;
struct W_006C5CC8 {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x60 - 8];
    V_006C5CC8 *vt;
};
typedef struct T_006C5CC8 {
    u8 pad0[0x110];
    W_006C5CC8 *w[35];
    u8 pad19C[0x290 - 0x19C];
    s32 f290;
    u8 pad294[0x2AC - 0x294];
    u8 f2AC;
    u8 pad2AD[0x2BC - 0x2AD];
    s32 f2BC[10];
    u8 pad2E4[0xB2C - 0x2E4];
    u8 fB2C;
    u8 padB2D[0xB38 - 0xB2D];
    s32 fB38[10];
    u8 fB60;
    u8 fB61;
    u8 padB62[0xB64 - 0xB62];
    s32 fB64;
    u8 padB68[0xBA4 - 0xB68];
    s32 fBA4;
    s32 fBA8;
    s32 fBAC;
    u8 fBB0;
    u8 padBB1[0xD4C - 0xBB1];
    s32 fD4C;
    s32 fD50;
} T_006C5CC8;
typedef struct { s32 v[6]; } Q_006C5CC8;
typedef struct {
    s32 f0;
    u8 f4[0x34 - 4];
    u8 f34;
} G_006C5CC8;
typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
    s32 f20;
} E_006C5CC8;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
} R_006C5CC8;
typedef struct {
    u8 pad0[0xE0];
    void *fE0;
    u8 padE4[0x284 - 0xE4];
    s32 f284;
} M_006C5CC8;
typedef struct {
    u8 pad0[0xD0];
    void *fD0;
} P_006C5CC8;
/* a one-byte truth value, kept in a byte register (not widened like a u8 local) */
typedef struct {
    u8 on;
} F_006C5CC8;
typedef struct {
    u8 pad0[0x38];
    G_006C5CC8 *f38;
    u8 pad3C[0x48 - 0x3C];
    void *f48;
    void *f4C;
} N_006C5CC8;

extern Q_006C5CC8 D_L39_002498E8;
extern u8 D_L39_002498C8[];
extern u8 D_L39_00249908[];
extern u8 D_L39_00249910[];
extern M_006C5CC8 *D_L39_00247A74_006C31B8;
__asm__(".extern D_L39_00247A74_006C31B8, 16");
extern N_006C5CC8 *D_L39_0024D860;
__asm__(".extern D_L39_0024D860, 16");
extern s32 D_001DE070_sda;
__asm__(".extern D_001DE070_sda, 4");
extern P_006C5CC8 *D_001DC1E4_sda;
extern N_006C5CC8 *D_001E1FD0_sda;
extern u8 D_001E1B10_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001E1B10_sda, 8");
extern u8 D_001E1B50_sda_006C31B8[] __attribute__((section(".sdata")));
__asm__(".extern D_001E1B50_sda_006C31B8, 8");
extern u8 D_001E1B90_sda_006C31B8[] __attribute__((section(".sdata")));
__asm__(".extern D_001E1B90_sda_006C31B8, 8");
extern f32 D_001DDF28_sda_006C31B8;
__asm__(".extern D_001DDF28_sda_006C31B8, 4");
extern f32 D_001DDF30_sda_006C31B8;
__asm__(".extern D_001DDF30_sda_006C31B8, 4");
extern f32 D_001DDF38_sda;
__asm__(".extern D_001DDF38_sda, 4");
extern f32 D_001DDF48_sda;
__asm__(".extern D_001DDF48_sda, 4");
extern f32 D_001DDF4C_sda_006C31B8;
__asm__(".extern D_001DDF4C_sda_006C31B8, 4");
extern f32 D_001DDF50_sda;
__asm__(".extern D_001DDF50_sda, 4");
extern f32 D_001DDF54_sda_006C31B8;
__asm__(".extern D_001DDF54_sda_006C31B8, 4");
extern f32 D_001DDF58_sda_006C31B8;
__asm__(".extern D_001DDF58_sda_006C31B8, 4");
extern f32 D_001DDF5C_sda_006C31B8;
__asm__(".extern D_001DDF5C_sda_006C31B8, 4");
extern f32 D_001DE01C_sda;
__asm__(".extern D_001DE01C_sda, 4");
extern f32 D_001DE020_sda;
__asm__(".extern D_001DE020_sda, 4");

extern s32 func_00120884(void *);
extern void func_0011D534(void *, s32, s32);
extern void func_L39_005945F0(void *, void *, s32);
extern void func_L39_006C4D10(void *);
extern void func_L39_006C4638(void *);
extern s32 func_L39_00685798(s32, s32, s32);
extern s32 func_L39_006C5530(void *);
extern void func_L39_006872B0(void *, u8 *, u32, f32, f32);
extern s32 func_L39_006C51F8(void *);
extern s32 func_L39_00688350(void *, s32);
extern void func_L39_006B2920(void *, s32, s32);
extern s32 func_L39_006847C8(void *, void *, u8 *, s32, f32, s32);
extern E_006C5CC8 *func_L39_006D0818(void *, s32);
extern R_006C5CC8 *func_L39_006D67D0(void *, s32);
extern s32 func_L39_006D7310(void *, s32, u8 *, s32);
extern s32 func_L39_006D96D0(void *, s32, s32, s32 *);
extern void func_L39_006D0768(void *, s32, s32);
extern void func_L39_006BA8F0(void *, s32);
extern void func_L39_00687358(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_006C5418(void *);
extern void func_L39_006C4040(void *, s32, s32);
extern void func_L39_006C3ED0(void *, s32);
extern void func_L39_006C5238(void *, s32, s32, u8 **);
extern void func_L39_006C5320(void *, s32);
extern void func_L39_006C5150(void *, s32);
extern void func_L39_00688750(void *, s32, s32);
extern void func_L39_006C5488(void *);

/* the child widget at index i */
static __inline__ W_006C5CC8 *item_006C5CC8(T_006C5CC8 *self, s32 i)
{
    return self->w[i];
}

/* the cheat-code check: input against the sequence D_L39_002498E8, ended by -1 */
static __inline__ void cheat_006C5CC8(T_006C5CC8 *self, s32 input)
{
    Q_006C5CC8 seq = D_L39_002498E8;
    W_006C5CC8 *w;

    if (input == seq.v[D_001DE070_sda]) {
        D_001DE070_sda++;
        if (seq.v[D_001DE070_sda] == -1) {
            D_001DE070_sda = 0;
            w = item_006C5CC8(self, 6);
            w->vt->f1C(w, 3, 0);
            self->fD50 = 6;
        }
    } else {
        D_001DE070_sda = 0;
    }
}

s32 func_L39_006C31B8(T_006C5CC8 *self, s32 input)
{
    W_006C5CC8 *w;

    func_L39_006C4D10(self);
    func_L39_006C4638(self);

    if (input != 0 && item_006C5CC8(self, 6)->f4 == 0) {
        if (item_006C5CC8(self, 5)->f4 != 0) {
            cheat_006C5CC8(self, input);
        }
    }

    if (input == 3 || input == 4 || input == 1 || input == 2) {
        if (self->f290 >= 0 && self->f290 <= self->fD50) {
            if (self->f290 == self->fD50 && input == 2) {
                func_L39_00685798(3, 0, 0);
                func_L39_00688750(self, 0, 0);
                return 1;
            }
            if (self->f290 == 0 && input == 1) {
                func_L39_00685798(3, 0, 0);
                func_L39_00688750(self, self->fD50, 0);
                return 1;
            }
        }
    }

    {
        u8 empty[32];

        if (func_L39_006C5530(self)) {
            u8 buf[32];

            func_00120048(buf, D_L39_002498C8, func_0037DF98(0x1340));
            func_L39_006872B0(self, buf, 0x706EC8FF, 0.8f, 0.9f);
        } else {
            empty[0] = D_L39_00249908[0];
            func_0011D534(empty + 1, 0, 31);
            func_L39_006872B0(self, empty, 0x706EC8FF, 1.0f, 1.0f);
        }
    }

    if (input == 7 && self->f290 >= 0 && self->f290 <= self->fD50) {
        func_L39_00685798(4, 0, 0);
        func_L39_00685798(0x15, 0, 0);
        self->fD4C = self->f290;
        func_L39_006C4040(self, 1, 0);
        self->fB61 = 1;
        func_L39_006C3ED0(self, -1);
        func_L39_006C3050((u8 *)self);
        w = item_006C5CC8(self, 7);
        w->vt->f88(w, 0);
        func_L39_00688750(self, 7, 0);
        return 1;
    }

    if (input == 5 && self->f290 == 7) {
        func_L39_00685798(0x17, 0, 0);
        func_L39_00685798(0x14, 0, 0);
        func_L39_006C4040(self, 0, 0);
        self->fB64 = 0;
        self->fB61 = 0;
        func_L39_00688750(self, self->fD4C, 0);
        return 1;
    }

    if ((input == 3 || input == 4 || input == 1 || input == 2) && self->f290 == 7) {
        s32 sel;
        s32 count;

        w = item_006C5CC8(self, 7);
        sel = w->vt->f8C(w);
        w = item_006C5CC8(self, self->f290);
        count = w->vt->f78(w);

        if (input == 1 && sel == 0) {
            return 1;
        }
        if (input == 2 && sel == count - 1) {
            return 1;
        }
        func_L39_00685798(3, 0, 0);
    }

    if ((input == 7 || input == 4) && self->f290 == 7) {
        u8 *strs;
        s32 sel;
        s32 type;
        s32 i;

        func_L39_00685798(0x15, 0, 0);
        func_L39_00685798(4, 0, 0);
        w = item_006C5CC8(self, self->f290);
        sel = w->vt->f8C(w);
        self->fB64 = sel;
        func_L39_006C4040(self, 1, 1);
        type = D_L39_004B1598[self->fD4C][sel].f0;
        self->fBAC = 0x7FFFFFFF;
        self->fBA4 = type;
        self->fBA8 = 1;
        if (type != -1) {
            if (self->fBB0) {
                self->fB2C = 1;
            } else {
                self->f2AC = 1;
            }
        }
        strs = func_0037DF98(0x1341);
        func_L39_005945F0(D_001E1B10_sda, func_0037DF98(0x1341), func_00120884(func_0037DF98(0x1341)));
        strs = D_001E1B10_sda;
        func_L39_006C3050((u8 *)self);
        for (i = 0; i < 10; i++) {
            w = item_006C5CC8(self, i + 15);
            w->vt->f50(w, 0x8066CCFF);
            w = item_006C5CC8(self, i + 25);
            w->vt->f50(w, 0x8066CCFF);
        }
        func_L39_006C5238(self, 0, 1, &strs);
        func_L39_006C5320(self, 1);
        func_L39_006C5150(self, 0);
        func_L39_006C5418(self);
        if (self->fB60) {
            func_L39_006C5488(self);
        }
        return 1;
    }

    if ((input == 3 || input == 4 || (input == 5 && func_L39_006C5530(self))) && func_L39_006C5530(self)) {
        if (self->fB61) {
            func_L39_00685798(0x17, 0, 0);
            func_L39_00685798(0x14, 0, 0);
            func_L39_006C4040(self, 1, 0);
            w = item_006C5CC8(self, 7);
            w->vt->f88(w, self->fB64);
            func_L39_00688750(self, 7, 0);
        }
        return 1;
    }

    if (func_L39_006C5530(self)) {
        if (input == 1) {
            func_L39_00685798(3, 0, 0);
            func_L39_006C5150(self, (func_L39_006C51F8(self) + 9) % 10);
            return 1;
        }
        if (input == 2) {
            func_L39_00685798(3, 0, 0);
            func_L39_006C5150(self, (func_L39_006C51F8(self) + 1) % 10);
            return 1;
        }
        if (input == 14 || input == 15) {
            u8 *strs;
            s32 step;

            strs = func_0037DF98(0x1341);
            func_L39_005945F0(D_001E1B50_sda_006C31B8, func_0037DF98(0x1341), func_00120884(func_0037DF98(0x1341)));
            strs = D_001E1B50_sda_006C31B8;
            func_L39_00685798(3, 0, 0);
            func_L39_006C5238(self, 0, 1, &strs);
            func_L39_006C5320(self, 1);
            if (input == 15) {
                step = 100;
            } else {
                step = 10;
            }
            self->fBA8 += step;
            if (self->fBA8 > self->fBAC - 10) {
                self->fBA8 = self->fBAC - 10;
            }
            if (self->fBB0 == 1) {
                self->fB2C = 1;
            } else {
                self->f2AC = 1;
            }
            return 1;
        }
        if (input == 11 || input == 12) {
            u8 *strs;
            s32 step;

            func_L39_00685798(3, 0, 0);
            if (self->fBA8 < 2) {
                return 1;
            }
            strs = func_0037DF98(0x1341);
            func_L39_005945F0(D_001E1B90_sda_006C31B8, func_0037DF98(0x1341), func_00120884(func_0037DF98(0x1341)));
            strs = D_001E1B90_sda_006C31B8;
            if (input == 12) {
                step = -100;
            } else {
                step = -10;
            }
            self->fBA8 += step;
            if (self->fBA8 <= 0) {
                self->fBA8 = 1;
            }
            func_L39_006C5238(self, 0, 1, &strs);
            func_L39_006C5320(self, 1);
            if (self->fBB0 == 1) {
                self->fB2C = 1;
            } else {
                self->f2AC = 1;
            }
            return 1;
        }
    }

    if (func_L39_00688350(self, input) == 1) {
        return 1;
    }

    if (input == 7 && func_L39_006C5530(self)) {
        func_L39_00685798(4, 0, 0);
        if (!self->fBB0) {
            s32 idx = func_L39_006C51F8(self);

            if (idx != -1) {
                void *p = D_001DC1E4_sda->fD0;

                if (p != 0) {
                    func_L39_006B2920(p, self->f2BC[idx], 1);
                    D_L39_00247A74_006C31B8->f284 = 0x1B;
                }
                return 1;
            } else {
                G_006C5CC8 *game = D_L39_0024D860->f38;
                s32 name;
                s32 slot;

                w = item_006C5CC8(self, func_L39_006C51F8(self) + 15);
                name = w->vt->fC4(w);
                slot = self->fB38[func_L39_006C51F8(self)];

                if (slot >= 0 && name != 0 && game->f34) {
                    u8 msg[80];
                    u8 buf[128];
                    u8 user_name[80];
                    E_006C5CC8 *entry;
                    R_006C5CC8 *rec;
                    s32 user;
                    s32 out;
                    F_006C5CC8 ok;
                    M_006C5CC8 *mgr;

                    if (slot == game->f0) {
                        mgr = D_L39_00247A74_006C31B8;
                        func_L39_006847C8(mgr, func_0037DF98(0x1693), D_L39_002498A8, 4, 0.6f, 0);
                        return 1;
                    }
                    func_00120048(msg, func_0037DF98(0x1735), name);
                    if (func_L39_006847C8(D_L39_00247A74_006C31B8, msg, D_L39_002498A8, 3, 0.6f, 0) != 1) {
                        return 1;
                    }
                    entry = func_L39_006D0818(D_L39_0024D860->f38, name);
                    if (entry == 0) {
                        func_00120048(buf, func_0037DF98(0x1694), name);
                        func_L39_006847C8(D_L39_00247A74_006C31B8, buf, D_L39_002498A8, 4, 0.6f, 0);
                        return 1;
                    }
                    user = entry->f20;
                    rec = func_L39_006D67D0(D_001E1FD0_sda->f48, user);
                    ok.on = 0;
                    if (rec != 0) {
                        ok.on = rec->f40 != 0;
                    }
                    if (!ok.on) {
                        func_00120048(buf, func_0037DF98(0x1695), name);
                        func_L39_006847C8(D_L39_00247A74_006C31B8, buf, D_L39_002498A8, 4, 0.6f, 0);
                        return 1;
                    }
                    buf[0] = 0x43;
                    func_00120048(user_name, func_0037DF98(0x1696), &game->f4);
                    func_00120048(buf + 1, D_L39_00249910, game->f0, user_name);
                    if (func_L39_006D7310(D_L39_0024D860->f48, user, buf, 0)) {
                        if (func_L39_006D96D0(D_001E1FD0_sda->f4C, game->f0, entry->f1C, &out)) {
                            func_L39_006D0768(game, entry->f1C, user);
                            mgr = D_L39_00247A74_006C31B8;
                            func_L39_006847C8(mgr, func_0037DF98(0x1698), D_L39_002498A8, 4, 0.6f, 0);
                            func_L39_006BA8F0(D_L39_00247A74_006C31B8->fE0, out);
                            D_L39_00247A74_006C31B8->f284 = 0x1F;
                        }
                    }
                    return 1;
                }
            }
        }
    }

    if (func_L39_006C5530(self) && input != 0) {
        return 1;
    }

    {
        f32 x, y, x2, y2;

        if (func_L39_006C5530(self)) {
            w = item_006C5CC8(self, self->f290);
            w->vt->f30(w, &x, &y);
            func_L39_00687358(self, 0, 3, 3, D_001DDF38_sda, y, D_001DDF30_sda_006C31B8 - 0.025f, 0.0483f,
                              D_001DE01C_sda, D_001DE020_sda);
        } else if (self->f290 == 7 && (w = item_006C5CC8(self, 7))->vt->f9C(w, &x, &y) &&
                   (w = item_006C5CC8(self, self->f290))->vt->fA0(w, &x2, &y2)) {
            func_L39_00687358(self, 0, 3, 3, D_001DDF28_sda_006C31B8, y + 0.003f, D_001DDF30_sda_006C31B8 - 0.025f, y2,
                              D_001DE01C_sda, D_001DE020_sda);
        } else {
            w = item_006C5CC8(self, self->f290);
            w->vt->f30(w, &x, &y);
            func_L39_00687358(self, 0, 3, 3, D_001DDF48_sda + x, D_001DDF4C_sda_006C31B8 + y, D_001DDF50_sda, D_001DDF54_sda_006C31B8,
                              D_001DDF58_sda_006C31B8, D_001DDF5C_sda_006C31B8);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006C31B8 */
