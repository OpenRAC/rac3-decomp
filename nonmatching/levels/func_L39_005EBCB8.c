/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_005E9748, the NTSC-U twin of func_L39_005EBCB8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "@ps2as" (src/levels/shared/L39_005EB698.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_005EB698 (src/levels/shared/L39_005EB698.c) */
/* localdecomp:start func_L39_005E9748 */
__asm__(".extern D_L39_00243E0C, 4");
__asm__(".extern D_L39_00243E10, 4");
__asm__(".extern D_L39_00243E14, 4");
extern f32 D_L39_00243E0C;
extern f32 D_L39_00243E10;
extern f32 D_L39_00243E14;
extern s32 D_L39_0024C990[];
extern s32 D_001A5990[];
extern s32 func_L01_00513698(void);
extern void func_L01_00512568(s32, f32 *, f32 *);
extern void func_L01_00512480(s32, f32, f32);

void func_L39_005E9748(void) {
    f32 v[2];
    f32 f20;
    f32 f1;
    f32 f0;
    s32 i;
    s32 *t;

    i = func_L01_00513698();
    v[1] = 0.0f;
    t = (s32 *)((u8 *)D_001A5990 + i * 4 + D_L39_0024C990[i] * 16);
    f20 = (f32)t[0x74 / 4] / 100.0f;
    v[0] = 0.0f;
    func_L01_00512568(0x54003D, &v[0], &v[1]);
    f1 = D_L39_00243E0C + D_L39_00243E14;
    f0 = D_L39_00243E10 - f1;
    f1 = f1 + 0.007f;
    f0 = f0 - 0.012f;
    f0 = f0 * f20;
    f1 = f1 + f0;
    v[0] = f1;
    func_L01_00512480(0x54003D, f1, v[1]);
}
/* localdecomp:end func_L39_005E9748 */
