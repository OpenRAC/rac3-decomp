#include "common.h"

/* NTSC-U counterpart of func_L39_00697130 (src/levels/39_multiplayer_menu/L39_00697130.c) */
/* localdecomp:start func_L39_00694A20 */
typedef struct W_00697130 W_00697130;
typedef struct V_00697130 {
    char pad0[0x1C];
    void (*f1C)(W_00697130 *, s32, s32);
    char pad20[0x10];
    void (*f30)(W_00697130 *, f32 *, f32 *);
    char pad34[0x58];
    s32 (*f8C)(W_00697130 *);
    char pad90[0x8];
    s32 (*f98)(W_00697130 *);
    s32 (*f9C)(W_00697130 *, f32 *, f32 *);
    char padA0[0x18];
    void (*fB8)(W_00697130 *, void *);
} V_00697130;
struct W_00697130 {
    s32 f0;
    s32 f4;
    char pad8[0x58];
    V_00697130 *f60;
};
typedef struct O_00697130 {
    char pad0[0x110];
    W_00697130 *f110[17];
    char pad154[0x290 - 0x154];
    s32 f290;
    char pad294[0x2A8 - 0x294];
    u8 f2A8;
    char pad2A9[0x2B0 - 0x2A9];
    s32 f2B0;
    s32 f2B4[66];
    s32 f3BC[65];
    s32 f4C0;
} O_00697130;
typedef struct M_00697130 {
    s32 f0;
} M_00697130;
typedef struct G_00697130 {
    char pad0[0x30];
    s32 *f30;
    char pad34[4];
    M_00697130 *f38;
    char pad3C[0xC];
    void *f48;
    void *f4C;
    char pad50[4];
    void *f54;
} G_00697130;
typedef struct St_00697130 {
    char pad0[0x284];
    s32 f284;
    s32 f288;
} St_00697130;
typedef struct S204_00697130 {
    char pad0[0xD0];
    void *fD0;
    char padD4[0xC];
    void *fE0;
    void *fE4;
} S204_00697130;
typedef struct P_00697130 {
    char pad0[0x34];
    s32 f34;
    char pad38[0x80 - 0x38];
    u8 f80;
} P_00697130;

extern G_00697130 *D_L39_0024D860;
__asm__(".extern D_L39_0024D860, 16");
extern St_00697130 *D_L39_00247A74_00694A20;
__asm__(".extern D_L39_00247A74_00694A20, 16");
extern S204_00697130 *D_001DC1E4_sda;
extern G_00697130 *D_001E1FD0_sda;
extern P_00697130 D_001A5E50;
extern u8 D_001A5ED0[];
extern char D_L39_00248190[];
extern char D_L39_00248198[];

extern void func_L39_00695700(O_00697130 *);
extern void func_L39_00695470(O_00697130 *);
extern void func_L39_006959C8(O_00697130 *);
extern s32 func_L39_00695418(O_00697130 *);
extern void func_L39_00687900(O_00697130 *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L39_006952A0(O_00697130 *, s32);
extern s32 func_L39_00688350(O_00697130 *, s32);
extern s32 func_L39_00685798(s32, s32, s32);
extern void func_L39_006B2920(void *, s32, s32);
extern s32 func_L39_006D97B0(void *, s32, s32 *);
extern void func_L39_006BA8F0(void *, s32);
extern char *func_0037DF98(s32);
extern void *func_001206F4(void *, void *);
extern void *func_00120D28(void *, void *, s32);
extern s32 func_00120048(u8 *, char *, ...);
extern s32 func_L39_00684930(St_00697130 *, char *, u8 *, s32, s32, s32, s32);
extern s32 func_L39_006DAAA8(void *, u8 *, s32);
extern void func_L39_006D0730(M_00697130 *, u8 *);
extern void func_L39_00695C88(O_00697130 *);
extern s32 func_L39_006D0790(M_00697130 *, s32 *, s32 *);
extern void func_L39_006D7310(void *, s32, u8 *, s32);
extern s32 func_L39_006D0768(M_00697130 *, s32, s32);
extern void func_L39_00688750(O_00697130 *, s32, s32);
extern s32 func_L39_006D96D0(void *, s32, s32, s32 *);
extern s32 func_L39_00684D80(St_00697130 *, char *, char *, s32);
extern s32 func_L39_006847C8(St_00697130 *, void *, char *, s32, s32, f32);
extern void func_L39_006CC918_00694A20(M_00697130 *);
extern void func_L39_006CC290(M_00697130 *, s32);
extern s32 func_L39_00684CE0(St_00697130 *, char *, s32 *, s32, s32);
extern s32 func_L39_006CCAB0(M_00697130 *, s32, s32);
extern void func_L39_006CDAA0(M_00697130 *, s32);
extern void func_L39_00687358(O_00697130 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

s32 func_L39_00694A20(O_00697130 *self, s32 msg)
{
    u8 name[16];
    u8 label[16];
    u8 text[128];
    u8 text2[256];
    s32 id;
    s32 a, b;
    s32 c, d;
    s32 e;
    f32 x0, y0;
    f32 x1, y1;
    M_00697130 *m = D_L39_0024D860->f38;
    s32 cnt;
    s32 sel;
    s32 flags;
    s32 flags2;
    s32 n;
    s32 i;
    s32 first;
    s32 last;
    s32 type;

    func_L39_00695700(self);
    func_L39_00695470(self);
    func_L39_006959C8(self);
    if (func_L39_00695418(self)) {
        return 1;
    }
    cnt = self->f2B0;
    if (cnt > 12) {
        cnt = 12;
    }
    if (cnt < 1) {
        cnt = 1;
    }
    func_L39_00687900(self, 0, cnt, 0.274f, 0.244999975f, 0.048f, 0.325000018f, 0x331465B7);
    if (func_L39_006952A0(self, msg)) {
        return 1;
    }
    if (func_L39_00688350(self, msg)) {
        return 1;
    }
    if (msg == 7) {
        func_L39_00685798(4, 0, 0);
        switch (self->f290) {
        case 1:
            if (self->f4C0 >= 0) {
                func_L39_006B2920(D_001DC1E4_sda->fD0, self->f4C0, 1);
                D_L39_00247A74_00694A20->f284 = 0x1B;
            }
            return 1;
        case 9:
            if (m->f0 != -1) {
                if (func_L39_006D97B0(D_001E1FD0_sda->f4C, m->f0, &id)) {
                    func_L39_006BA8F0(D_001DC1E4_sda->fE4, id);
                    D_L39_00247A74_00694A20->f284 = 0x20;
                }
            }
            return 1;
        case 15: {
            u8 *src = D_001A5ED0;
            s32 ok;

            St_00697130 *g;

            func_001206F4(name, src);
            g = D_L39_00247A74_00694A20;
            func_L39_00684930(g, func_0037DF98(0x168F), name, 0, 5, 0, 0);
            ok = 1;
            if (name[0] != 0) {
                ok = func_L39_006DAAA8(D_L39_0024D860->f54, name, 0);
            }
            if (ok) {
                func_L39_006D0730(m, name);
                func_00120D28(src, name, 5);
                src[5] = 0;
                func_00120048(label, D_L39_00248190, name);
                self->f110[7]->f60->fB8(self->f110[7], label);
            }
            return 1;
        }
        case 10:
            D_L39_00247A74_00694A20->f284 = 10;
            return 1;
        case 11:
            D_L39_00247A74_00694A20->f284 = 7;
            return 1;
        case 12:
            func_L39_00695C88(self);
            return 1;
        case 13:
            b = -1;
            a = -1;
            if (func_L39_006D0790(m, &a, &b)) {
                func_00120048(text, D_L39_00248198, 0x4D, func_0037DF98(0x1733));
                func_L39_006D7310(D_L39_0024D860->f48, b, text, 0);
            }
            func_L39_006D0768(m, -1, -1);
            self->f110[12]->f60->f1C(self->f110[12], 3, 0);
            self->f110[13]->f60->f1C(self->f110[13], 0, 0);
            self->f110[14]->f60->f1C(self->f110[14], 2, 0);
            self->f110[8]->f60->fB8(self->f110[8], func_0037DF98(0x1328));
            func_L39_00688750(self, 12, 0);
            return 1;
        case 14:
            if (func_L39_006D0790(m, &c, &d)) {
                if (func_L39_006D96D0(D_001E1FD0_sda->f4C, c, m->f0, &e)) {
                    func_L39_006BA8F0(D_001DC1E4_sda->fE0, e);
                    D_L39_00247A74_00694A20->f284 = 0x1F;
                }
            }
            return 1;
        case 16: {
            s32 r = 0;
            s32 j;

            if (self->f2B0 >= 2) {
                St_00697130 *g = D_L39_00247A74_00694A20;
                char *t0 = func_0037DF98(0xFD2);
                char *t1 = func_0037DF98(0x1706);
                r = func_L39_00684D80(g, t0, t1, 0);
            }
            if (r == 0) {
                St_00697130 *g = D_L39_00247A74_00694A20;
                char *t0 = func_0037DF98(0x1037);
                char *t1 = func_0037DF98(0x1031);
                if (func_L39_006847C8(g, t0, t1, 3, 0, 0.6f) == 1) {
                    func_00120048(text2, D_L39_00248198, 0x4D, func_0037DF98(0x1732));
                    for (j = 0; j < self->f2B0; j++) {
                        if (self->f2B4[j] != D_001A5E50.f34) {
                            func_L39_006D7310(D_001E1FD0_sda->f48, self->f2B4[j], text2, 1);
                        }
                    }
                    func_L39_006D0768(m, -1, -1);
                    func_L39_006CC918_00694A20(m);
                    func_L39_006CC290(m, 0);
                    D_L39_00247A74_00694A20->f288 = 8;
                }
            } else if (r == 1) {
                St_00697130 *g = D_L39_00247A74_00694A20;
                s32 k = func_L39_00684CE0(g, func_0037DF98(0x1707), self->f3BC, self->f2B0, 0);
                if (k >= 0) {
                    func_L39_006D0768(m, -1, -1);
                    func_L39_006CCAB0(m, self->f2B4[k], self->f3BC[k]);
                    func_L39_006CC290(m, 0);
                    D_L39_00247A74_00694A20->f288 = 6;
                }
            }
            D_001A5E50.f80 = 0;
            return 1;
        }
        }
    }
    sel = self->f290;
    if (msg == 8 && sel == 1 && self->f4C0 >= 0 && self->f4C0 != *D_001E1FD0_sda->f30) {
        char *fmt = func_0037DF98(0x1038);
        St_00697130 *g;
        char *t1;

        func_00120048(name, fmt, self->f110[1]->f60->f98(self->f110[1]));
        g = D_L39_00247A74_00694A20;
        t1 = func_0037DF98(0x1031);
        if (func_L39_006847C8(g, name, t1, 3, 0, 0.6f) == 1) {
            func_L39_006CDAA0(D_L39_0024D860->f38, self->f4C0);
            self->f2A8 = 1;
        }
        return 1;
    }
    if (sel == 1) {
        W_00697130 **p = self->f110;

        self->f110[1]->f60->f9C(self->f110[1], &x0, &y0);
        p += self->f290;
        n = (*p)->f60->f8C(*p);
        flags = 0;
        if (n > 0) {
            flags = sel;
        }
        if (n < self->f2B0 - 1) {
            flags |= 2;
        }
        func_L39_00687358(self, flags, 3, 3, 0.274f, y0 + -0.001f, 0.325000018f, 0.032f, 0.04f, 1.0f);
    } else {
        self->f110[self->f290]->f60->f30(self->f110[self->f290], &x1, &y1);
        first = -1;
        last = -1;
        for (i = 9; i < 17; i++) {
            if ((type = self->f110[i]->f4) == 3 || type == 4 || type == 5) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        flags2 = self->f290 != first;
        if (self->f290 != last) {
            flags2 |= 2;
        }
        func_L39_00687358(self, flags2, 3, 3, x1, y1 + 0.0005f, 0.405f, 0.032f, 0.041f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L39_00694A20 */
