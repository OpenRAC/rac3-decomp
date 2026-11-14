#include "common.h"

/* NTSC-U counterpart of func_L39_006A0BF8 (src/levels/39_multiplayer_menu/L39_006A0BF8.c) */
typedef struct W_006A0AC0 W_006A0AC0;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(W_006A0AC0 *, s32, s32);
    u8 pad20[4];
    void (*f24)(W_006A0AC0 *, void *);
} VT_006A0AC0;
struct W_006A0AC0 {
    u8 pad0[0x60];
    VT_006A0AC0 *vt;
};
typedef struct {
    u8 pad0[4];
    s32 state;
} T_006A0AC0;
typedef struct {
    u8 pad0[0x110];
    W_006A0AC0 *w110;
    W_006A0AC0 *w114;
    u8 pad118[4];
    T_006A0AC0 *t11C;
    u8 pad120[4];
    T_006A0AC0 *t124;
    T_006A0AC0 *t128;
} S_006A0AC0;
extern void func_L39_00688750(S_006A0AC0 *, s32, s32);

/* localdecomp:start func_L39_0069E3E8 */
typedef struct {
    u8 pad0[0x284];
    s32 f284;
} S_006A0BF8_g;

typedef struct {
    u8 pad0[0x290];
    s32 f290;
    u8 pad294[0x14];
    s32 f2A8;
    s32 f2AC;
    u8 pad2B0[0x14];
    s32 f2C4;
    u8 pad2C8[0x4];
    u8 f2CC;
} S_006A0BF8_self;

extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_L39_00688638(void *, s32);
extern s32 func_L39_00688350(void *, s32);
extern s32 D_001A4568[];
extern S_006A0BF8_g *D_L39_00247A74;

s32 func_L39_0069E3E8(S_006A0BF8_self *self, s32 arg1)
{
    s32 ok;
    s32 sel;

    switch (self->f290) {
    case 6:
        func_L01_00512480(self->f2C4, 0.36f, 0.6f);
        func_L01_00513548(self->f2C4, 0.16f, 0.05f);
        break;
    case 2:
        func_L01_00512480(self->f2C4, 0.4f, 0.6f);
        break;
    case 4:
        func_L01_00512480(self->f2C4, 0.5f, 0.6f);
        break;
    case 3:
    case 5:
    case 7:
        func_L01_00512480(self->f2C4, 0.6f, 0.6f);
        func_L01_00513548(self->f2C4, 0.25f, 0.05f);
        break;
    }
    if (arg1 >= 1 && arg1 <= 4) {
        if (arg1 == 3 || arg1 == 4) {
            func_L39_00688750((S_006A0AC0 *)self, func_L39_00688638(self, -1), arg1);
        }
        return 1;
    }
    if (func_L39_00688350(self, arg1) == 1) {
        return 1;
    }
    if (self->f2CC != 0 && D_001A4568[0] != 2) {
        self->f2A8 = 0x40;
        D_L39_00247A74->f284 = 0x2C;
        return 1;
    }
    if (arg1 == 7) {
        ok = 0;
        sel = self->f290;
        if (sel == 2) {
            self->f2A8 = 1;
            ok = 1;
        } else if (sel == 3) {
            self->f2A8 = 2;
            ok = 1;
        } else if (sel == 4) {
            self->f2A8 = 4;
            ok = 1;
        } else if (sel == 5) {
            self->f2A8 = 8;
            ok = 1;
        } else if (sel == 6) {
            self->f2A8 = 0x10;
            ok = 1;
        } else if (sel == 7) {
            self->f2A8 = 0x20;
            ok = 1;
        }
        if (ok == 1) {
            D_L39_00247A74->f284 = 0x2C;
            return 1;
        }
        return 0;
    }
    if (arg1 == 5 && self->f2AC >= 2) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_0069E3E8 */
