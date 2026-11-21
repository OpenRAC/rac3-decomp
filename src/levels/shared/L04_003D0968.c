#include "common.h"

/* localdecomp:start func_L04_003D0968 */
typedef struct V_003D0968 V_003D0968;
typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x68 - 0x21];
    V_003D0968 *vars;
    u8 pad6C[0x78 - 0x6C];
    s32 color;
    u8 pad7C[0x90 - 0x7C];
    s32 w90;
} M_003D0968;
struct V_003D0968 {
    u8 pad0[0x40];
    f32 f40;
    u8 pad44[0x70 - 0x44];
    s32 w70;
    u8 pad74[0x90 - 0x74];
    s32 w90;
    M_003D0968 *p94;
    u8 pad98[0x9C - 0x98];
    M_003D0968 *p9C;
    void *pA0;
    s32 wA4;
};
typedef void (*Fn_003D0968)(void *, s32);

extern s32 D_L04_001DF940;
extern s32 D_L04_001DEAE0; __asm__(".extern D_L04_001DEAE0, 4");
extern s32 D_L04_001DEAE4; __asm__(".extern D_L04_001DEAE4, 4");
extern s32 D_L04_001DEAE8; __asm__(".extern D_L04_001DEAE8, 4");
extern s32 D_L04_001DEAEC; __asm__(".extern D_L04_001DEAEC, 4");
extern s32 D_L04_001DEAF0; __asm__(".extern D_L04_001DEAF0, 4");
extern s32 D_L04_001DEAF4; __asm__(".extern D_L04_001DEAF4, 4");
extern s32 D_L04_001DEAF8; __asm__(".extern D_L04_001DEAF8, 4");
extern s32 D_L04_001DEAFC; __asm__(".extern D_L04_001DEAFC, 4");
extern s32 D_L04_001DEB00; __asm__(".extern D_L04_001DEB00, 4");
extern s32 func_L04_003D0C40(M_003D0968 *, V_003D0968 *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void (**func_L01_0043B548(s32, s32))(u8 *);
extern void func_L01_00456230(void *, s32);
extern void func_L03_003B1DD0(void *);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L04_003D1420();

void func_L04_003D0968(M_003D0968 *self) {
    V_003D0968 *v = self->vars;
    V_003D0968 *o;

    if (self->state == 0 && func_L04_003D0C40(self, v) == 0) {
        return;
    }
    switch (self->state) {
    case 1:
        if (func_L01_004561B8(self) != 0) {
            self->color = D_L04_001DEAE0;
            if (v->w90 == -1) {
                func_L01_004450F0(self, 3, -1);
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(self) != 0) {
            if (v->w90 == -2) {
                func_L01_004450F0(self, 3, -1);
            }
            if (v->p9C != 0) {
                v->p9C->state = 7;
            }
        }
        if (D_L04_001DF940 % D_L04_001DEAEC != 0) {
            break;
        }
        if (v->p9C == 0) {
            break;
        }
        self->color = func_0038DBD8(D_L04_001DEAE4, D_L04_001DEAE8, func_003824E0(0.0f, 1.0f));
        o = v->p9C->vars;
        if (o->f40 > 0.0f) {
            s32 c = func_0038DBD8(D_L04_001DEAF0, D_L04_001DEAF4, func_003824E0(0.0f, 1.0f));
            self->color = func_0038DBD8(self->color, c, o->f40);
            if (o->f40 == 1.0f) {
                func_L01_004450F0(self, 3, -1);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(self) != 0) {
            if (v->w70 != 0) {
                ((Fn_003D0968 *)func_L01_0043B548(6625, 108))[2](self, 1);
            } else {
                func_L01_00456230(self, 1);
            }
            if (v->pA0 != 0) {
                func_L03_003B1DD0(v->pA0);
            }
            if (v->p94 != 0) {
                if (v->p94->w90 == -2) {
                    func_L01_004450F0(v->p94, 3, -1);
                } else {
                    func_L01_004450F0(v->p94, 2, -1);
                }
            }
        }
        if (func_L01_004AA710(self, v->wA4) == 0) {
            v->wA4 = func_003A52A0(0, 4, self);
        }
        if (D_L04_001DF940 % D_L04_001DEB00 == 0) {
            self->color = func_0038DBD8(D_L04_001DEAF8, D_L04_001DEAFC, func_003824E0(0.0f, 1.0f));
        }
        if (v->p94 != 0) {
            func_L01_00404A10(func_L04_003D1420, self);
        }
        break;
    }
}
/* localdecomp:end func_L04_003D0968 */

INCLUDE_ASM("asm/levels", func_L04_003D0C40);
