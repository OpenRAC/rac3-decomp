#include "common.h"

/* declared by functions of L39_006928D0.c, which this file was cut from */
typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_006928D0_inner;
typedef struct {
    char pad[0x38];
    S_006928D0_inner *f38;
} S_006928D0_outer;
typedef struct {
    char pad[0x284];
    s32 f284;
} S_006928D0_slot;
extern S_006928D0_outer *D_L39_0024D760;
extern S_006928D0_slot *D_001DC204_sda;

/* localdecomp:start func_L39_00693F70 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct S_00693F70_obj S_00693F70_obj;

typedef struct S_00693F70_vt {
    char pad0[0x1C];
    void (*f1C)(S_00693F70_obj *, s32, s32);
    char pad20[0x10];
    void (*f30)(S_00693F70_obj *, f32 *, f32 *);
    char pad34[0x58];
    s32 (*f8C)(S_00693F70_obj *);
    char pad90[0xC];
    s32 (*f9C)(S_00693F70_obj *, f32 *, f32 *);
} S_00693F70_vt;

struct S_00693F70_obj {
    s32 f0;
    s32 f4;
    char pad8[0x58];
    S_00693F70_vt *f60;
};

typedef struct S_00693F70_self {
    char pad0[0x110];
    S_00693F70_obj *f110[9];
    char pad134[0x15C];
    s32 f290;
    char pad294[0x30];
    s32 f2C4;
    char pad2C8[0x10C];
    s32 f3D4;
} S_00693F70_self;

typedef struct S_00693F70_mgr {
    s32 f0;
} S_00693F70_mgr;

typedef struct S_00693F70_glob {
    char pad0[0x30];
    s32 *f30;
    char pad34[4];
    S_00693F70_mgr *f38;
} S_00693F70_glob;

typedef struct S_00693F70_state {
    char pad0[0x284];
    s32 f284;
    s32 f288;
} S_00693F70_state;

typedef struct S_00693F70_sda204 {
    char pad0[0xD0];
    void *fD0;
    char padD4[0xC];
    void *fE0;
    void *fE4;
} S_00693F70_sda204;

typedef struct S_00693F70_sda2050 {
    char pad0[0x4C];
    void *f4C;
} S_00693F70_sda2050;

extern S_00693F70_state *D_L39_00247914;
extern S_00693F70_sda2050 *D_001E2050_sda;

extern s32 func_L39_00694418(S_00693F70_self *, s32);
extern void func_L39_00694C70(S_00693F70_self *);
extern void func_L39_006949F0(S_00693F70_self *);
extern void func_L39_006944B0(S_00693F70_self *);
extern void func_L39_006948A0(S_00693F70_self *);
extern void func_L39_0068A4A8(S_00693F70_self *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L39_00694770(S_00693F70_self *, s32);
extern s32 func_L39_0068AEF8(S_00693F70_self *, s32);
extern void func_L39_006B5288(void *, s32, s32);
extern s32 func_L39_006DC308(void *, s32, s32 *);
extern void func_L39_006BD408(void *, s32);
extern s32 func_L39_006D2F18(S_00693F70_mgr *, s32 *, s32 *);
extern s32 func_L39_006DC228(void *, s32, s32, s32 *);
extern void func_L39_0068B2F8(S_00693F70_self *, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_L39_006872E8(S_00693F70_state *, s32, s32, s32, s32, f32);
extern s32 func_L39_006D0228(S_00693F70_mgr *, s32);
extern s32 func_L39_006CEA18(S_00693F70_mgr *, s32);
extern void func_L39_00689F00(S_00693F70_self *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

s32 func_L39_00693F70(S_00693F70_self *self, s32 msg)
{
    s32 id;
    s32 a, b, c, d;
    f32 x0, y0, x1, y1;
    S_00693F70_mgr *m = ((S_00693F70_glob *)D_L39_0024D760)->f38;
    s32 sel;
    s32 n;
    s32 cnt;
    s32 flags;
    s32 flags2;
    s32 i;
    s32 first;
    s32 last;
    s32 type;

    sel = func_L39_00694418(self, msg);
    if (sel != 0) {
        return 1;
    }
    func_L39_00694C70(self);
    func_L39_006949F0(self);
    func_L39_006944B0(self);
    func_L39_006948A0(self);
    cnt = self->f2C4;
    if (cnt > 12) {
        cnt = 12;
    }
    if (sel >= cnt) {
        cnt = 1;
    }
    func_L39_0068A4A8(self, 0, cnt, 0.274f, 0.244999975f, 0.048f, 0.325000018f, 0x331465B7);
    if (func_L39_00694770(self, msg)) {
        return 1;
    }
    if (func_L39_0068AEF8(self, msg)) {
        return 1;
    }
    sel = self->f290;
    if (msg == 7) {
        switch (sel) {
        case 1:
            if (self->f3D4 >= 0) {
                func_L39_006B5288(((S_00693F70_sda204 *)D_001DC204_sda)->fD0, self->f3D4, 1);
                D_L39_00247914->f284 = 0x1B;
            }
            return 1;
        case 8:
            if (m->f0 != -1) {
                if (func_L39_006DC308(D_001E2050_sda->f4C, m->f0, &id)) {
                    func_L39_006BD408(((S_00693F70_sda204 *)D_001DC204_sda)->fE4, id);
                    D_L39_00247914->f284 = 0x20;
                }
            }
            return 1;
        case 9:
            if (func_L39_006D2F18(m, &a, &b)) {
                if (func_L39_006DC228(D_001E2050_sda->f4C, a, m->f0, &c)) {
                    func_L39_006BD408(((S_00693F70_sda204 *)D_001DC204_sda)->fE0, c);
                    D_L39_00247914->f284 = 0x1F;
                }
            } else {
                self->f110[9]->f60->f1C(self->f110[9], 2, 0);
                func_L39_0068B2F8(self, 8, 0);
            }
            return 1;
        case 10: {
            S_00693F70_state *g = D_L39_00247914;
            s32 t0 = func_00381FF0(0x1395);
            s32 t1 = func_00381FF0(0x1031);

            if (func_L39_006872E8(g, t0, t1, 3, 0, 0.6f) == 1) {
                func_L39_006D0228(((S_00693F70_glob *)D_L39_0024D760)->f38,
                                  *((S_00693F70_glob *)D_L39_0024D760)->f30);
                func_L39_006CEA18(((S_00693F70_glob *)D_L39_0024D760)->f38, 0);
                D_L39_00247914->f288 = 8;
            }
            return 1;
        }
        }
    }
    if (sel == 1) {
        S_00693F70_obj **p = self->f110;

        self->f110[1]->f60->f9C(self->f110[1], &x0, &y0);
        p += self->f290;
        n = (*p)->f60->f8C(*p);
        flags = 0;
        if (n > 0) {
            flags = sel;
        }
        if (n < self->f2C4 - 1) {
            flags |= 2;
        }
        func_L39_00689F00(self, flags, 3, 3, 0.274f, y0 + -0.001f, 0.325000018f, 0.032f, 0.04f, 1.0f);
    } else {
        self->f110[sel]->f60->f30(self->f110[sel], &x1, &y1);
    first = -1;
    last = -1;
    for (i = 8; i < 11; i++) {
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
/* localdecomp:end func_L39_00693F70 */
