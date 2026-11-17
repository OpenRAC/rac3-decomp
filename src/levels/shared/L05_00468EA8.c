#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_00468EA8 */
extern u8 *func_L01_004618E0(s32);
extern s32 func_0013D3E0(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00447470_00468EA8(s32, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *D_L05_002208B0[];

typedef struct {
    s32 *col;
    s16 *size;
    s16 *life;
    s32 pad0C;
    s32 w10;
    f32 f14;
} Spec_468EA8;

u8 *func_L05_00468EA8(void *pos, void *dir, Spec_468EA8 *spec, s32 flag, s32 a4) {
    u8 *e;
    u8 *p;
    vu0_v4 v;
    f32 r;
    f32 k;
    s32 t;
    e = func_L01_004618E0(0x56);
    if (e != 0) {
        e[9] = 0xA0;
        e[3] = flag != 0 ? 0x48 : 0x44;
        e[1] = 0;
        e[2] = **D_L05_002208B0;
        e[8] = func_0013D3E0();
        r = func_003824E0(0.0f, 1.0f);
        k = r / (f32)(spec->life[1] - spec->life[0]);
        *(s32 *)(e + 4) = func_L01_00447470_00468EA8(spec->col[0], spec->col[1], k);
        *(f32 *)(e + 0xC) = ((f32)spec->size[0] + k * (f32)(spec->size[1] - spec->size[0])) * 1000.0f;
        func_0038CE20(&v, dir, r);
        vec_add_ab(e + 0x10, pos, &v);
        t = spec->w10 - (r > 0.5f);
        *(s16 *)(e + 0xA) = t;
        p = e + 0x20;
        func_0038CE20(p, dir, r * spec->f14);
        *(s32 *)(p + 0x18) = a4;
        *(Spec_468EA8 **)(p + 0x10) = spec;
        *(s16 *)(p + 0x14) = 0;
    }
    return e;
}
/* localdecomp:end func_L05_00468EA8 */
