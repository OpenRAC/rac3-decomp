#include "common.h"

/* func_L39_00695BA0 (level 39 menu page handler, msg 6/7/8): wave 13c c42 near under the line
 * "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (L39_00695530/006957C0/00696010/00696308.c's), as a
 * file of its own 0x00695BA0-0x00695FA0 (both 8-aligned; 0x00695FA0 is func_L01_0048EE50, another file):
 * tools/check.py --mode S --flags "@ps2as" level 39: 201 diff, 255 instructions on both sides, only 48
 * aligned rows differ, all control flow. Changed against r27's draft: 0.32500002f (retail 0x3EA66667, the
 * spelling level 39's siblings use) and D_L39_0024D760 as a scalar with the file family's
 * .extern 16 hint (retail's lui v0/lw v0 pairs are Ps2EeAs macro loads, not split-address loads), so
 * every constant and address load now matches. Still differs: retail keeps msg 8's own `return 1` as
 * the shared return-1 block (L_31C, msg 6/7 tails branch to it) where this compiler keeps the 0068AEF8
 * check's; retail keeps the else-branch's and the default 0068A2D0 calls apart where this one
 * cross-jumps them; msg 7's 006CEA18 argument order follows from the shared block. Wordings tried
 * (W/e_*.c: nested or && msg 6 tests, separate ifs for msg 7/8, r != 1 early return, nested 0068AEF8 test,
 * explicit gotos) give the same or worse layouts.
 */

/* localdecomp:start func_L39_00695BA0 */
typedef struct W_00695BA0 W_00695BA0;
typedef struct V_00695BA0 {
    char pad0[0x8C];
    s32 (*f8C)(W_00695BA0 *);
    char pad90[0x8];
    s32 (*f98)(W_00695BA0 *);
    s32 (*f9C)(W_00695BA0 *, f32 *, f32 *);
} V_00695BA0;
struct W_00695BA0 {
    char pad0[0x60];
    V_00695BA0 *f60;
};
typedef struct O_00695BA0 {
    char pad0[0x110];
    W_00695BA0 *f110[4];
    char pad120[0x290 - 0x120];
    s32 f290;
    char pad294[0x2AC - 0x294];
    u8 f2AC;
    char pad2AD[0x2B4 - 0x2AD];
    u8 f2B4[0x50];
    s32 f304;
    s32 f308[16];
} O_00695BA0;
typedef struct G_00695BA0 {
    char pad0[0x38];
    void *f38;
    char pad3C[0x54 - 0x3C];
    s32 f54;
} G_00695BA0;

__asm__(".extern D_L39_00247914, 16");
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern void *D_001E2050_sda;
extern void *D_L39_00247914;
extern char D_L39_00247FC0[];

s32 func_L39_00695BA0(O_00695BA0 *self, s32 msg)
{
    char buf[0x50];
    f32 x, y;
    s32 f54;
    void *m;
    s32 st;
    s32 idx;
    s32 v;
    char *fmt;
    void *g;
    extern void func_L39_00695AE0(void *);
    extern s32 func_L39_00695FC0(void *);
    extern void func_L39_00696010(void *);
    extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
    extern s32 func_L39_0068AEF8(void *, s32);
    extern s32 func_L39_00687450(void *, char *, u8 *, s32, s32, s32, s32);
    extern s32 func_001205B0(char *, char *);
    extern s32 func_L39_006DD608(s32, void *, s32);
    extern s32 func_L39_006CEEE0(void *, void *);
    extern s32 func_L39_006CEA18(void *, s32);
    extern char *func_00381FF0(s32);
    extern s32 func_00120048(char *, char *, ...);
    extern s32 func_L39_006872E8(void *, char *, char *, s32, f32, s32);
    extern s32 func_L39_006D03B8(void *, s32, s32, void *);
    extern void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

    func_L39_00695AE0(self);
    m = ((G_00695BA0 *)D_L39_0024D760)->f38;
    f54 = ((G_00695BA0 *)D_L39_0024D760)->f54;
    func_L39_00689F00(self, 0, 3, 3, 1.5f, 1.5f, 0.32500002f, 0.035f, 0.045f, 0.1f);
    if (func_L39_00695FC0(self) != 0) {
        return 1;
    }
    func_L39_00696010(self);
    if (func_L39_0068AEF8(self, msg) != 0) {
        return 1;
    }
    if (msg == 6) {
        func_L39_00687450(D_L39_00247914, D_L39_00247FC0, self->f2B4, 0, 0x10, 0, 0);
        if (func_001205B0((char *)self->f2B4, D_L39_00247FC0) != 0) {
            if (func_L39_006DD608(f54, self->f2B4, 0) != 0) {
                func_L39_006CEEE0(m, self->f2B4);
                func_L39_006CEA18(m, 0);
            }
        }
        return 1;
    }
    if (msg == 7) {
        st = self->f290;
        if (st == 2) {
            s32 r;
            G_00695BA0 *t;

            idx = self->f110[2]->f60->f8C(self->f110[2]);
            if (idx < 0) {
                return 1;
            }
            v = self->f308[idx];
            if (v < 0) {
                return 1;
            }
            fmt = func_00381FF0(0x149E);
            func_00120048(buf, fmt, self->f110[2]->f60->f98(self->f110[2]));
            g = D_L39_00247914;
            r = func_L39_006872E8(g, buf, func_00381FF0(0x1031), 3, 0.6f, 0);
            if (r == 1) {
                func_L39_006D03B8(m, v, 1, D_L39_00247FC0);
                t = D_001E2050_sda;
            } else if (r == 2) {
                func_L39_006D03B8(m, v, 2, D_L39_00247FC0);
                t = D_L39_0024D760;
            } else {
                t = D_001E2050_sda;
            }
            func_L39_006CEA18(t->f38, 0);
            self->f2AC = 1;
            return 1;
        }
    } else if (msg == 8) {
        if (self->f290 == 2) {
            s32 r;

            idx = self->f110[2]->f60->f8C(self->f110[2]);
            if (idx < 0) {
                return 1;
            }
            v = self->f308[idx];
            if (v < 0) {
                return 1;
            }
            fmt = func_00381FF0(0x1039);
            func_00120048(buf, fmt, self->f110[2]->f60->f98(self->f110[2]));
            g = D_L39_00247914;
            r = func_L39_006872E8(g, buf, func_00381FF0(0x1031), 3, 0.6f, 0);
            if (r == 1) {
                func_L39_006D03B8(((G_00695BA0 *)D_L39_0024D760)->f38, v, 2, D_L39_00247FC0);
                self->f2AC = r;
            }
            return 1;
        }
    } else if (self->f290 == 2) {
        s32 r;
        s32 n;
        s32 flags;
        W_00695BA0 **w;

        w = self->f110;
        self->f110[2]->f60->f9C(self->f110[2], &x, &y);
        w += self->f290;
        r = (*w)->f60->f8C(*w);
        n = self->f304 - 1;
        flags = 0 < r;
        if (r < n) {
            flags |= 2;
        }
        func_L39_0068A2D0(self, flags, 3, 3, 0.274f, y + -0.0015f);
        return 0;
    }
    func_L39_0068A2D0(self, 0, 3, 3, 2.0f, 2.0f);
    return 0;
}
/* localdecomp:end func_L39_00695BA0 */
