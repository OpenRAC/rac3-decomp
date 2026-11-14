/* NTSC-U draft (2026-11-14, Claude worker): C of func_L02_00306A00, the NTSC-U twin of func_L02_00306C88, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (PAL line lacks @ps2as)" (src/levels/shared/L02_003067B8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L02_00306A00 */
extern f32 D_001E0120_sda;
__asm__(".extern D_001E0120_sda, 4");
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_00301508(void *, s32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00467288(void *, void *, s32, f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00465410(void *, void *, s32, s32);

void func_L02_00306A00(u8 *o) {
    vu0_v4 pos;
    vu0_v4 v10;
    vu0_v4 v20;
    s32 n = 2;
    s32 i;
    s32 c;
    s32 j;
    f32 a;
    f32 k;
    f32 t;

    pos = *(vu0_v4 *)(o + 0x10);
    D_001E0120_sda = func_003BE7F0(o + 0x10, 0, 0, 0.5f);
    pos.z = D_001E0120_sda;
    func_L01_00301508(&pos, 3, 4.5f, 1.025f);
    for (i = 4; i >= 0; i--) {
        v10.x = *(f32 *)(o + 0x10) + (f32)n * func_0037E250(-0.3f, 0.3f);
        v10.y = *(f32 *)(o + 0x14) + (f32)n * func_0037E250(-0.3f, 0.3f);
        v10.z = D_001E0120_sda;
        func_L01_00467288(&v10, &D_001E0120_sda, -1, (f32)n * func_0037E250(0.3f, 0.6f), 5250.0f);
    }
    for (j = 39; j >= 0; j--) {
        a = func_0037E2A8();
        k = (f32)n * func_0037E250(0.0f, 0.050000004f);
        v10.x = func_00388960(a) * k;
        v10.y = func_00388978(a) * k;
        v10.z = (f32)n * func_0037E250(0.033333335f, 0.083333336f);
        t = v10.x * 8.0f;
        v20.x = *(f32 *)(o + 0x10) + t;
        v20.y = *(f32 *)(o + 0x14) + t;
        v20.z = D_001E0120_sda - func_0037E250(0.0f, 0.2f);
        c = func_0037E1D8(2);
        func_L01_00465410(&v20, &v10, c, n * func_0037E208(0x5A, 0x78));
    }
}
/* localdecomp:end func_L02_00306A00 */
