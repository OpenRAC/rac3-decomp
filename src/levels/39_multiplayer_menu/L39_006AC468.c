#include "common.h"

/* localdecomp:start func_L39_006AC468 */
typedef struct VT_006AC468 {
    char _p0[0x30];
    void (*f30)(void *, f32 *, f32 *);
    char _p34[0x8C - 0x34];
    s32 (*f8C)(void *);
    char _p90[0xA8 - 0x90];
    void (*fA8)(void *, s32);
    s32 (*fAC)(void *);
} VT_006AC468;
typedef struct O_006AC468 {
    char _p0[4];
    s32 f4;
    char _p8[0x60 - 8];
    VT_006AC468 *f60;
} O_006AC468;
typedef struct S_006AC468 {
    char _p0[0x110];
    O_006AC468 *f110[5];
    char _p124[0x284 - 0x124];
    s32 f284;
    char _p288[0x290 - 0x288];
    s32 f290;
    char _p294[0x2A8 - 0x294];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
    s32 f2B8;
    s32 f2BC;
    s32 f2C0;
    s32 f2C4;
    s32 f2C8;
    s32 f2CC;
    s32 f2D0;
    char _p2D4[4];
    s32 f2D8;
    s32 f2DC;
    s32 f2E0;
    s32 f2E4;
} S_006AC468;

__asm__(".extern D_L39_00247A34, 16");
__asm__(".extern D_L39_00247A30, 16");
extern u8 D_L39_00247A34;
extern f32 D_L39_00247A30;
__asm__(".extern D_L39_00247914, 16");
extern void *D_L39_00247914;
extern u8 D_L39_00248AA8[];
extern S_006AC468 *D_001DC204_sda;
extern u8 D_001DC324_sda;
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_006ACC60(void *);
extern void func_L39_006ACE10(void *);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_00687750(void *, s32);
extern s32 func_L39_00687508(void *, void *, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
extern s32 func_L39_006AC860(void *);
extern void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

s32 func_L39_006AC468(S_006AC468 *self, s32 cmd) {
    s32 r;
    s32 first;
    s32 last;
    s32 i;
    s32 m;
    O_006AC468 **p;
    f32 x;
    f32 y;

    if (D_L39_00247A34) {
        if (D_L39_00247A30 <= 0.0f) {
            D_001DC204_sda->f284 = 0x18;
        }
        return 1;
    }
    r = func_L39_0068AEF8(self, cmd);
    if ((u32)(cmd - 3) < 2 || cmd == 7) {
        switch (self->f290) {
        case 0:
            func_L39_006ACC60(self);
            break;
        case 1: {
            s32 old = self->f2A8;
            func_L39_006ACE10(self);
            if (old != self->f2A8) {
                self->f2AC = self->f2A8;
            }
            break;
        }
        case 2:
            self->f2D8 = self->f110[2]->f60->fAC(self->f110[2]);
            if (((self->f2A8 == 1 && self->f2E0 == 0) || (self->f2A8 == 2 && self->f2DC == 0)) && self->f2D8 == 0) {
                if (cmd == 3) {
                    self->f2D8 = 0x23;
                } else {
                    self->f2D8 = 5;
                }
                self->f110[2]->f60->fA8(self->f110[2], self->f2D8);
            }
            break;
        }
    }
    if (((self->f2A8 == 1 && self->f2E0 == 0) || (self->f2A8 == 2 && self->f2DC == 0)) && self->f2D8 == 0) {
        self->f2D8 = 5;
        self->f110[2]->f60->fA8(self->f110[2], 5);
    }
    if (r) {
        return 1;
    }
    if (cmd == 5) {
        func_L39_00688340(0x17, 0, 0);
        D_001DC324_sda = 1;
        return 1;
    }
    if (cmd == 7) {
        func_L39_00688340(4, 0, 0);
        if (self->f290 == 3) {
            func_L39_00687750(D_L39_00247914, (s32)&self->f2D0);
            return 1;
        }
        if (self->f290 == 4) {
            S_006AC468 *g = D_001DC204_sda;
            r = self->f110[0]->f60->f8C(self->f110[0]);
            func_L39_00687508(g, D_L39_00248AA8, 0, r, self->f2A8, &self->f2B0, &self->f2E4, &self->f2DC, &self->f2B4, &self->f2B8, &self->f2BC, &self->f2E0, &self->f2C0, &self->f2C4, &self->f2C8, &self->f2CC);
            return 1;
        }
    } else if (cmd == 6) {
        func_L39_00688340(4, 0, 0);
        if (func_L39_006AC860(self)) {
            D_001DC204_sda->f284 = 0x17;
            return 1;
        }
    }
    p = self->f110;
    self->f110[self->f290]->f60->f30(self->f110[self->f290], &x, &y);
    first = -1;
    last = -1;
    for (i = 0; i < 5; i++) {
        s32 t = p[i]->f4;
        if (t == 3 ? 1 : (t == 4 ? 1 : t == 5)) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    m = self->f290 != first;
    if (self->f290 != last) {
        m |= 2;
    }
    func_L39_0068A2D0(self, m, 3, 3, 0.293f, y + -0.0015f);
    return 0;
}
/* localdecomp:end func_L39_006AC468 */
