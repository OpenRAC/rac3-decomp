/* functional: high. EXACT MATCH (byte-identical per tools/check.py). EXACT: tools/check.py reports MATCH at its only place (level 35) with the file's own flags (needs the .extern 4-byte size hints on the three gp floats, as the repo's matched code does). Callees as in the L33 sibling func_L33_0034E8C0. */
#include "common.h"
#include "vu0.h"

extern f32 D_001A4C64[];
extern void func_L31_003473F0(void *, f32, f32);
extern f32 D_L35_001DEA04;
__asm__(".extern D_L35_001DEA04, 4");
extern f32 D_L35_001DEA2C;
__asm__(".extern D_L35_001DEA2C, 4");
extern f32 D_L35_001DEA54;
__asm__(".extern D_L35_001DEA54, 4");

void func_L35_003A3E40(u8 *a) {
    u8 *st;
    u8 *r;
    f32 dmg;
    f32 v[4] __attribute__((aligned(16)));

    st = *(u8 **)(a + 0x68);
    func_0038CAD0(st + 0xF4);
    func_L01_0044ABD0(a, st + 0x40);
    r = (u8 *)func_L01_00447490(a, 0x10000, 0);
    if (r != 0) {
        a[0xA8] = 0xFF;
        dmg = *(f32 *)(r + 0x2C);
        if (0.0f < dmg) {
            if (a[0x20] != 0x42 && *(s32 *)(st + 0xF4) == 0) {
                *(s32 *)(st + 0xF4) = 0xC;
                *(f32 *)st = *(f32 *)st - dmg;
                func_003C4A40(a, st + 0x40);
                if (*(f32 *)st <= 0.0f) {
                    func_L35_003A4180(a, 0x42);
                    func_0038CF68(st + 0xE0, r + 0x10, D_L35_001DEA04);
                } else {
                    func_L35_003A4180(a, 1);
                    func_0038CF68(v, r + 0x10, D_L35_001DEA2C);
                    vec_add_ab(st + 0xE0, st + 0xE0, v);
                }
            }
        }
    }
    if (*(f32 *)(a + 0x18) < *(f32 *)(st + 0xD8) - 2.0f) {
        if (a[0x20] != 0x42) {
            func_L35_003A4180(a, 0x42);
        }
    }
    *(f32 *)(a + 0x14) = D_001A4C64[0];
    if (a[0x20] != 0x42) {
        func_L31_003473F0(a + 0x10, D_L35_001DEA54, D_L35_001DEA54);
    }
}
