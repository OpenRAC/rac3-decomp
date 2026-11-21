#include "common.h"

/* NTSC-U counterpart of func_L13_003B8010 (src/levels/13_holostar_studios_ratchet/L13_003B8010.c) */
#include "vu0.h"

/* localdecomp:start func_L13_003B60D0 */
typedef struct {
    s32 w0;
    s32 w4;
    f32 f8;
    f32 fC;
    s32 w10;
    s32 w14;
    s32 w18;
    f32 f1C;
    f32 f20;
    s32 w24;
    s32 w28;
} V_3B8010;

__asm__(".extern D_L13_001DF61C, 4");
extern u8 (*D_L13_001DF61C)[0x100];
extern s32 D_L13_001DF140;
extern vu0_v4 (*D_L13_001DF700)[8];
extern u8 D_00142CA0[];
extern u8 D_001A4C60[];
extern void func_003BD360(void *);
extern s32 func_0037E0F0(void *, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00438430(s32);
extern f32 func_003BEB48(f32, f32, f32);
extern void *func_L13_0034B6C0(s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L13_0034B798(void *, void *, void *);

void func_L13_003B60D0(u8 *self) {
    V_3B8010 *v = *(V_3B8010 **)(self + 0x68);
    vu0_v4 out;
    vu0_v4 pos;
    vu0_v4 dir;

    if (self[0x20] == 0) {
        if (v->w24 != 0 && D_00142CA0[0x1D] != 0) {
            func_003BD360(self);
            return;
        }
        if (func_0037E0F0(D_001A4C60, v->w0, 0) != 0) {
            func_L01_00441FB8(self, 1, -1);
        }
        if (v->w28 >= 0) {
            if (v->w10 == -1 || D_L13_001DF61C[v->w10][0x20] == 0xFE ||
                D_L13_001DF61C[v->w10][0x20] == 0xFD) {
                func_L01_00438430(v->w28);
            }
        }
    }
    if (self[0x20] == 1) {
        void *m;
        f32 f;
        f32 a;
        if (func_0037E0F0(D_001A4C60, v->w0, &out) == 0) {
            func_L01_00441FB8(self, 0, -1);
            return;
        }
        f = func_003BEB48(v->f8, v->fC, (out.z + 1.0f) * 0.5f);
        if (v->w14 + (s32)(60.0f / f) < D_L13_001DF140) {
            m = func_L13_0034B6C0(v->w4);
            if (m != 0) {
                f32 dirAng = func_00388A28(out.x, out.y);
                a = func_00389380(dirAng, func_L01_00440918(0.0f, v->f20 * 0.017453292f));
                pos = D_L13_001DF700[v->w18][3];
                dir.x = func_00388960(a) * v->f1C;
                dir.y = func_00388978(a) * v->f1C;
                dir.z = 0.0f;
                vec_add_ab(&dir, &pos, &dir);
                func_L13_0034B798(m, &pos, &dir);
                v->w14 = D_L13_001DF140;
            }
        }
    }
}
/* localdecomp:end func_L13_003B60D0 */
