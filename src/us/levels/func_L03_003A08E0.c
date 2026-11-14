#include "common.h"

/* NTSC-U counterpart of func_L03_003A20E0 (src/levels/03_starship_phoenix/L03_003A20E0.c) */
/* localdecomp:start func_L03_003A08E0 */
typedef struct { s32 w0; f32 f4; } S_003A08E0;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad1[0x47]; S_003A08E0 *s; u8 pad2[0x3C]; u8 fA8; u8 padA9; s16 hAA; u8 padAC[0x48]; f32 fF4; } O_003A08E0;
typedef struct { u8 pad[0x20]; O_003A08E0 *q; } T_003A08E0;

extern f32 D_001DE420_sda; __asm__(".extern D_001DE420_sda, 4");
extern f32 D_001DE41C_sda; __asm__(".extern D_001DE41C_sda, 4");
extern u8 D_001A4C60[];
extern void func_L03_003A0B08(void *);
extern int func_L03_003A0B40();
extern void func_L01_00441FB8(void *, s32, s32);
extern T_003A08E0 *func_L01_00444358(void *, s32, s32);
extern void func_L01_00417F60(s32, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern f32 func_003BE6A8(f32, f32, f32);

void func_L03_003A08E0(O_003A08E0 *self) {
    S_003A08E0 *s;
    T_003A08E0 *t;
    func_L03_003A0B08(self);
    s = self->s;
    switch (self->state) {
    case 1:
        if (func_L03_003A0B40(self)) {
            func_L01_00441FB8(self, 5, -1);
        } else {
            t = func_L01_00444358(self, 0x30000, 0);
            if (t != 0) {
                self->fA8 = 0xFF;
                if (t->q != 0) {
                    if (t->q->hAA == 0x47) {
                        func_L01_00417F60(0xA18, 5);
                    }
                }
            }
        }
        break;
    case 2:
        s->f4 = s->f4 + D_001DE420_sda;
        if (s->f4 >= 1.0f) {
            s->f4 = 1.0f;
            func_L01_00441FB8(self, 3, -1);
        }
        self->fF4 = func_003BE6A8(0.0f, D_001DE41C_sda * 0.017453292f, s->f4);
        if (func_0037E0F0(D_001A4C60, s->w0, 0) == 0) {
            func_L01_00441FB8(self, 4, -1);
        }
        break;
    case 3:
        if (func_0037E0F0(D_001A4C60, s->w0, 0) == 0) {
            func_L01_00441FB8(self, 4, -1);
        }
        break;
    case 4:
        s->f4 = s->f4 - D_001DE420_sda;
        if (s->f4 <= 0.0f) {
            s->f4 = 0.0f;
            func_L01_00441FB8(self, 5, -1);
        }
        self->fF4 = func_003BE6A8(0.0f, D_001DE41C_sda * 0.017453292f, s->f4);
        if (func_0037E0F0(D_001A4C60, s->w0, 0) != 0) {
            func_L01_00441FB8(self, 2, -1);
        }
        break;
    case 5:
        if (func_0037E0F0(D_001A4C60, s->w0, 0) != 0) {
            func_L01_00441FB8(self, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L03_003A08E0 */
