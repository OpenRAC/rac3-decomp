#include "common.h"

/* NTSC-U counterpart of func_L30_004E5410 (src/levels/shared/L30_004E5370.c) */
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;
extern S_004E6988 D_001A4BE0;
extern void func_L01_0050BB98(s32, s32, f32);

/* localdecomp:start func_L30_004E1510 */
#include "vu0.h"
/* log: (s32)func_L30_0041CC48(...) switch; -4 passed through an s32 local (retail converts it
 * at run time with cvt.s.w; a literal folds to lui 0xc080); fabs_asm (not __builtin_fabsf)
 * fixes the f2260/f2264 load order -> MATCH. */
typedef struct {
    u8 pad0[0x43];
    u8 b43;
} P_004E5410;

typedef struct {
    u8 pad0[0xC08];
    s32 wC08;
    u8 pad1[0x1B24 - 0xC0C];
    void *p1B24;
    u8 pad2[0x2260 - 0x1B28];
    f32 f2260;
    f32 f2264;
    u8 pad3[0x25C0 - 0x2268];
    P_004E5410 *p25C0;
    u8 pad4[0x2838 - 0x25C4];
    f32 f2838;
} S_004E5410;

extern u8 *D_001D52FC;
extern f32 func_00388A28(f32, f32);
extern f32 func_L30_0041CC48(s32, f32);

void func_L30_004E1510(void) {
    f32 v[2];
    s32 anim;
    s32 cur;
    s32 blend = -4;

    if ((((S_004E5410 *)&D_001A4BE0)->f2838 < 0.2f && !(*(s32 *)(D_001D52FC + 0x1A0) & 0x20))
        || ((S_004E5410 *)&D_001A4BE0)->p1B24 == 0) {
        if (((S_004E5410 *)&D_001A4BE0)->p25C0->b43 != 0x10) {
            func_L01_0050BB98(0x10, 0, 7.0f);
        }
        return;
    }
    anim = 0x17;
    v[0] = fabs_asm(((S_004E5410 *)&D_001A4BE0)->f2260);
    v[1] = ((S_004E5410 *)&D_001A4BE0)->f2264;
    switch ((s32)func_L30_0041CC48(0, func_00388A28(v[0], v[1]) / 0.7853982f)) {
    case -1:
        anim = 0x1A;
        break;
    case 1:
        anim = 0x14;
        break;
    case 2:
        anim = 0x11;
        break;
    case -2:
        anim = 0x1D;
        break;
    }
    cur = ((S_004E5410 *)&D_001A4BE0)->p25C0->b43;
    if (cur == anim) {
        return;
    }
    if (!(((S_004E5410 *)&D_001A4BE0)->wC08 & 2) && (u32)(cur - 0x11) < 0xF) {
        return;
    }
    func_L01_0050BB98(anim, 0, blend);
}
/* localdecomp:end func_L30_004E1510 */
