#include "common.h"

/* NTSC-U counterpart of the L34_003515A0.c function at the same place (src/levels/34_vidcomic_3/L34_003515A0.c).
 * Case 2 stores f154 BEFORE w14C (then cross-jumping shares the func_L01_00441FB8 call of the three states); the path test
 * reads self->f10 each time (no local x: retail copies it with mov.s f2,f1 because cse turns the later loads into a copy). */
#include "vu0.h"

/* localdecomp:start func_L34_00350928 */
typedef struct {
    u8 p0[0x64];
    f32 f64;
    u8 p68[0x140 - 0x68];
    s32 w140;
    s32 w144;
    u8 p148[4];
    s32 w14C;
    u8 p150[4];
    f32 f154;
    u8 p158[0x168 - 0x158];
    f32 f168;
    f32 f16C;
    f32 f170;
    f32 f174;
    u8 p178[4];
    s32 w17C;
    s32 w180;
    s32 w184;
    s32 w188;
    s32 w18C;
} S_00350928;
typedef struct {
    u8 p0[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
    u8 p1C[4];
    u8 b20;
    u8 p21[0x22];
    u8 b43;
    u8 p44[0x1C];
    u8 b60;
    u8 p61[7];
    S_00350928 *p68;
    u8 p6C[0x8C];
    f32 fF8;
} O_00350928;
typedef struct {
    u8 p0[0x80];
    f32 f80;
    f32 f84;
} H_00350928;
typedef struct { u8 b[0x80]; } Snd80_00350928;
typedef struct {
    s32 count;
    u8 p4[0xC];
    struct { f32 x, y, z, w; } pts[1];
} Path_00350928;
extern H_00350928 D_001A4BE0;
extern Snd80_00350928 D_001A30B0[];
extern Path_00350928 *D_L34_0021D8C0[];
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L34_00350E38(void *);
extern void func_L34_003512F8(void *);
extern void func_L34_00350F48(void *);
extern void func_L34_00351028(void *);
extern void func_L34_00350880(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00445758(f32 *, f32 *, s32, f32, f32, f32, f32);
extern void func_003BEC60(f32 *, f32 *, f32, f32, f32, f32);
extern s32 func_00388398(s32 *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_0037E208(s32, s32);

void func_L34_00350928(O_00350928 *self) {
    S_00350928 *s = self->p68;
    s32 id;
    Snd80_00350928 *e;
    Path_00350928 *P;
    f32 x;

    id = s->w18C;
    if (id == -1 || (e = &D_001A30B0[id], *(O_00350928 **)&e->b[0xDC] != self) || e->b[0xD0] == 0) {
        s->w18C = func_0039FE80(0, 4, self);
    }
    func_L34_00350E38(self);
    switch (self->b20) {
    case 0:
        func_L34_003512F8(self);
        func_L01_00441FB8(self, 3, -1);
        break;
    case 1:
        s->f64 = 0.2617994f;
        func_L01_00445758(&self->fF8, &s->f168, 0, -1.5707964f, 0.004848137f, 0.0024240685f, 0.14544411f);
        func_003BEC60(&self->f18, &s->f170, s->f16C, 0.004166667f, 0.0019444445f, 0.116666675f);
        func_L34_00350F48(self);
        if (fabs_asm(self->f18 - s->f16C) < 2.5f) {
            func_L01_00441FB8(self, 2, -1);
        }
        break;
    case 2:
        s->f64 = 0.7853982f;
        func_L01_00445758(&self->fF8, &s->f168, 0, -1.5707964f, 0.004848137f, 0.0024240685f, 0.14544411f);
        func_003BEC60(&self->f18, &s->f170, s->f16C, 0.004166667f, 0.0019444445f, 0.083333336f);
        func_003BEC60(&self->f14, &s->f174, D_001A4BE0.f84, 0.0019444445f, 0.0013888889f, 0.083333336f);
        func_L34_00350F48(self);
        if (fabs_asm(self->f14 - D_001A4BE0.f84) < 1.5f) {
            s->f154 = self->f18;
            s->w14C = 0;
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 3:
        func_003BEC60(&self->f14, &s->f174, D_001A4BE0.f84, 0.0019444445f, 0.0013888889f, 0.083333336f);
        if (s->w17C == 0) {
            if (func_00388398(&s->w188) != 0) {
                if (func_00389468(self->fF8, func_00388A28(D_001A4BE0.f80 - self->f10, D_001A4BE0.f84 - self->f14)) < 1.5707964f) {
                    if (fabs_asm(D_001A4BE0.f80 - self->f10) < 3.0f) {
                        s->w17C = 1;
                        s->w180 = 3;
                    }
                }
            }
        }
        if (s->w17C != 0) {
            if (self->b43 == 0) {
                func_003BE4F0(self, 1, 0, 3);
            } else if ((self->b60 & 2) != 0 && self->b43 != 2) {
                func_003BE4F0(self, 2, 0, 3);
            }
            if (func_00388398(&s->w184) != 0) {
                func_L34_00350880(self, 1);
                s->w184 = func_0037E208(7, 15);
                s->w180 = s->w180 - 1;
                if (s->w180 <= 0) {
                    s->w17C = 0;
                    s->w188 = 0x78;
                }
            }
        } else {
            if (self->b43 == 2) {
                func_003BE4F0(self, 3, 0, 3);
            } else if ((self->b60 & 2) != 0) {
                if (self->b43 != 0) {
                    func_003BE4F0(self, 0, 0, 3);
                }
            }
        }
        if (s->w140 != -1) {
            P = D_L34_0021D8C0[s->w140];
            if (self->f10 < P->pts[0].x && self->f10 < P->pts[P->count - 1].x) {
                s->w144 = 1;
            } else if (P->pts[0].x < self->f10 && P->pts[P->count - 1].x < self->f10) {
                s->w144 = -1;
            }
            func_L34_00351028(self);
        }
        break;
    }
}
/* localdecomp:end func_L34_00350928 */
