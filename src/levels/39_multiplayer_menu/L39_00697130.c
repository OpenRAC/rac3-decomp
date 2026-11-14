#include "common.h"

/* localdecomp:start func_L39_00697130 */
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

extern G_00697130 *D_L39_0024D760;
__asm__(".extern D_L39_0024D760, 16");
extern St_00697130 *D_L39_00247914;
__asm__(".extern D_L39_00247914, 16");
extern S204_00697130 *D_001DC204_sda;
extern G_00697130 *D_001E2050_sda;
extern P_00697130 D_001A5CD0;
extern u8 D_001A5D50[];
extern char D_L39_00248030[];
extern char D_L39_00248038[];

extern void func_L39_00697E10(O_00697130 *);
extern void func_L39_00697B80(O_00697130 *);
extern void func_L39_006980F8(O_00697130 *);
extern s32 func_L39_00697B28(O_00697130 *);
extern void func_L39_0068A4A8(O_00697130 *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L39_006979B0(O_00697130 *, s32);
extern s32 func_L39_0068AEF8(O_00697130 *, s32);
extern s32 func_L39_00688340(s32, s32, s32);
extern void func_L39_006B5288(void *, s32, s32);
extern s32 func_L39_006DC308(void *, s32, s32 *);
extern void func_L39_006BD408(void *, s32);
extern char *func_00381FF0(s32);
extern void *func_001206F4(void *, void *);
extern void *func_00120D28(void *, void *, s32);
extern s32 func_00120048(u8 *, char *, ...);
extern s32 func_L39_00687450(St_00697130 *, char *, u8 *, s32, s32, s32, s32);
extern s32 func_L39_006DD608(void *, u8 *, s32);
extern void func_L39_006D2EB8(M_00697130 *, u8 *);
extern void func_L39_006983B8(O_00697130 *);
extern s32 func_L39_006D2F18(M_00697130 *, s32 *, s32 *);
extern void func_L39_006D9E68(void *, s32, u8 *, s32);
extern s32 func_L39_006D2EF0(M_00697130 *, s32, s32);
extern void func_L39_0068B2F8(O_00697130 *, s32, s32);
extern s32 func_L39_006DC228(void *, s32, s32, s32 *);
extern s32 func_L39_006878A0(St_00697130 *, char *, char *, s32);
extern s32 func_L39_006872E8(St_00697130 *, void *, char *, s32, s32, f32);
extern void func_L39_006CF0A0(M_00697130 *);
extern void func_L39_006CEA18(M_00697130 *, s32);
extern s32 func_L39_00687800(St_00697130 *, char *, s32 *, s32, s32);
extern s32 func_L39_006CF238(M_00697130 *, s32, s32);
extern void func_L39_006D0228(M_00697130 *, s32);
extern void func_L39_00689F00(O_00697130 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

s32 func_L39_00697130(O_00697130 *self, s32 msg)
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
    M_00697130 *m = D_L39_0024D760->f38;
    s32 cnt;
    s32 sel;
    s32 flags;
    s32 flags2;
    s32 n;
    s32 i;
    s32 first;
    s32 last;
    s32 type;

    func_L39_00697E10(self);
    func_L39_00697B80(self);
    func_L39_006980F8(self);
    if (func_L39_00697B28(self)) {
        return 1;
    }
    cnt = self->f2B0;
    if (cnt > 12) {
        cnt = 12;
    }
    if (cnt < 1) {
        cnt = 1;
    }
    func_L39_0068A4A8(self, 0, cnt, 0.274f, 0.244999975f, 0.048f, 0.325000018f, 0x331465B7);
    if (func_L39_006979B0(self, msg)) {
        return 1;
    }
    if (func_L39_0068AEF8(self, msg)) {
        return 1;
    }
    if (msg == 7) {
        func_L39_00688340(4, 0, 0);
        switch (self->f290) {
        case 1:
            if (self->f4C0 >= 0) {
                func_L39_006B5288(D_001DC204_sda->fD0, self->f4C0, 1);
                D_L39_00247914->f284 = 0x1B;
            }
            return 1;
        case 9:
            if (m->f0 != -1) {
                if (func_L39_006DC308(D_001E2050_sda->f4C, m->f0, &id)) {
                    func_L39_006BD408(D_001DC204_sda->fE4, id);
                    D_L39_00247914->f284 = 0x20;
                }
            }
            return 1;
        case 15: {
            u8 *src = D_001A5D50;
            s32 ok;

            St_00697130 *g;

            func_001206F4(name, src);
            g = D_L39_00247914;
            func_L39_00687450(g, func_00381FF0(0x168F), name, 0, 5, 0, 0);
            ok = 1;
            if (name[0] != 0) {
                ok = func_L39_006DD608(D_L39_0024D760->f54, name, 0);
            }
            if (ok) {
                func_L39_006D2EB8(m, name);
                func_00120D28(src, name, 5);
                src[5] = 0;
                func_00120048(label, D_L39_00248030, name);
                self->f110[7]->f60->fB8(self->f110[7], label);
            }
            return 1;
        }
        case 10:
            D_L39_00247914->f284 = 10;
            return 1;
        case 11:
            D_L39_00247914->f284 = 7;
            return 1;
        case 12:
            func_L39_006983B8(self);
            return 1;
        case 13:
            b = -1;
            a = -1;
            if (func_L39_006D2F18(m, &a, &b)) {
                func_00120048(text, D_L39_00248038, 0x4D, func_00381FF0(0x1733));
                func_L39_006D9E68(D_L39_0024D760->f48, b, text, 0);
            }
            func_L39_006D2EF0(m, -1, -1);
            self->f110[12]->f60->f1C(self->f110[12], 3, 0);
            self->f110[13]->f60->f1C(self->f110[13], 0, 0);
            self->f110[14]->f60->f1C(self->f110[14], 2, 0);
            self->f110[8]->f60->fB8(self->f110[8], func_00381FF0(0x1328));
            func_L39_0068B2F8(self, 12, 0);
            return 1;
        case 14:
            if (func_L39_006D2F18(m, &c, &d)) {
                if (func_L39_006DC228(D_001E2050_sda->f4C, c, m->f0, &e)) {
                    func_L39_006BD408(D_001DC204_sda->fE0, e);
                    D_L39_00247914->f284 = 0x1F;
                }
            }
            return 1;
        case 16: {
            s32 r = 0;
            s32 j;

            if (self->f2B0 >= 2) {
                St_00697130 *g = D_L39_00247914;
                char *t0 = func_00381FF0(0xFD2);
                char *t1 = func_00381FF0(0x1706);
                r = func_L39_006878A0(g, t0, t1, 0);
            }
            if (r == 0) {
                St_00697130 *g = D_L39_00247914;
                char *t0 = func_00381FF0(0x1037);
                char *t1 = func_00381FF0(0x1031);
                if (func_L39_006872E8(g, t0, t1, 3, 0, 0.6f) == 1) {
                    func_00120048(text2, D_L39_00248038, 0x4D, func_00381FF0(0x1732));
                    for (j = 0; j < self->f2B0; j++) {
                        if (self->f2B4[j] != D_001A5CD0.f34) {
                            func_L39_006D9E68(D_001E2050_sda->f48, self->f2B4[j], text2, 1);
                        }
                    }
                    func_L39_006D2EF0(m, -1, -1);
                    func_L39_006CF0A0(m);
                    func_L39_006CEA18(m, 0);
                    D_L39_00247914->f288 = 8;
                }
            } else if (r == 1) {
                St_00697130 *g = D_L39_00247914;
                s32 k = func_L39_00687800(g, func_00381FF0(0x1707), self->f3BC, self->f2B0, 0);
                if (k >= 0) {
                    func_L39_006D2EF0(m, -1, -1);
                    func_L39_006CF238(m, self->f2B4[k], self->f3BC[k]);
                    func_L39_006CEA18(m, 0);
                    D_L39_00247914->f288 = 6;
                }
            }
            D_001A5CD0.f80 = 0;
            return 1;
        }
        }
    }
    sel = self->f290;
    if (msg == 8 && sel == 1 && self->f4C0 >= 0 && self->f4C0 != *D_001E2050_sda->f30) {
        char *fmt = func_00381FF0(0x1038);
        St_00697130 *g;
        char *t1;

        func_00120048(name, fmt, self->f110[1]->f60->f98(self->f110[1]));
        g = D_L39_00247914;
        t1 = func_00381FF0(0x1031);
        if (func_L39_006872E8(g, name, t1, 3, 0, 0.6f) == 1) {
            func_L39_006D0228(D_L39_0024D760->f38, self->f4C0);
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
        func_L39_00689F00(self, flags, 3, 3, 0.274f, y0 + -0.001f, 0.325000018f, 0.032f, 0.04f, 1.0f);
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
        func_L39_00689F00(self, flags2, 3, 3, x1, y1 + 0.0005f, 0.405f, 0.032f, 0.041f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L39_00697130 */
