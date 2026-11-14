/* NTSC-U draft (2026-11-14, Claude worker): C of func_L02_00352288, the NTSC-U twin of func_L02_00353398, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "@ps2as" (src/levels/shared/L02_00352C80.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L02_00352C80 (src/levels/shared/L02_00352C80.c) */
/* localdecomp:start func_L02_00352288 */
__asm__(".extern D_L02_001DCFD0, 4");
__asm__(".extern D_L02_001DCFD4, 4");
__asm__(".extern D_L02_001DCFD8, 4");
__asm__(".extern D_L02_001DCFDC, 4");
extern s32 D_L02_001DCFD0;
extern s32 D_L02_001DCFD4;
extern f32 D_L02_001DCFD8;
extern f32 D_L02_001DCFDC;
extern s32 func_L02_00351E50(void *, void *, void *, f32);
extern void *func_L01_002FB638(void *, void *, s32, s32, s32, s32);
extern void func_L01_00438908(void *, s32, s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E208(s32, s32);
extern void func_0037E4B8(void *, f32, f32, f32);

s32 func_L02_00352288(void *a0, void *a1) {
    f32 v[4];
    f32 w[4];
    s32 r;
    f32 f21;
    f32 f20;
    void *o;

    r = func_L02_00351E50(a0, a1, v, 0.8f);
    if (r == 0) {
        return 0;
    }
    if (r == -1) {
        return 1;
    }
    f21 = func_0037E250(0.7853982f, 1.5707964f);
    f20 = func_0037E2A8();
    func_0037E4B8(w, func_0037E250(D_L02_001DCFD8, D_L02_001DCFDC) * 0.016666668f, f20, f21);
    v[2] = v[2] + 0.1f;
    o = func_L01_002FB638(v, w, func_0037E208(D_L02_001DCFD0, D_L02_001DCFD4), 2, 0, 0);
    if (o != 0) {
        func_L01_00438908(o, 0x7F, 0x40, 0x20);
    }
    return 1;
}
/* localdecomp:end func_L02_00352288 */
