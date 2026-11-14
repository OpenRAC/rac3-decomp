/* NTSC-U draft (2026-11-14, Claude worker): C of func_L08_003B1F50, the NTSC-U twin of func_L08_003B3E60, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2" (src/levels/shared/L08_003B3E60.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L08_003B1F50 */
extern u8 D_001D558C;
__asm__(".extern D_001D558C, 16");
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00452E70(void *, void *);
extern f32 func_00389380(f32, f32);
extern void func_00388BD0(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);

void func_L08_003B1F50(u8 *o) {
    u8 *st;
    u8 *m;
    vu0_v4 v;

    st = *(u8 **)(o + 0x68);
    if (o[0x31] != 0) {
        func_L01_0044EB38(o, st, 0x80909090, 0x80404040, 0.081448704f);
    }
    if (*(s32 *)(st + 4) != 0) {
        if (o[0x20] == 0) {
            if (D_001D558C != 0) {
                o[0x20] = 1;
                m = func_003BCFB0(0x1BBE, 0x80);
                func_00388830(&v, o + 0xC0, -3.0f);
                func_L01_00452E70(m, o);
                vec_add_ba(m + 0x10, m + 0x10, &v);
                func_00389380(*(f32 *)(m + 0xF8), 3.1415927f);
                func_00388BD0(m + 0xC0, m + 0xF0);
                *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 4.0f;
                if (o[0x43] != 3) {
                    func_003BE4F0(o, 3, 0, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L08_003B1F50 */
