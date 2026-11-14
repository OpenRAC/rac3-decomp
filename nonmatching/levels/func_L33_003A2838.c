/* NTSC-U draft (2026-11-14, Claude worker): C of func_L33_003A1080, the NTSC-U twin of func_L33_003A2838, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/33_vidcomic_2/L33_003A2838.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L33_003A2838 (src/levels/33_vidcomic_2/L33_003A2838.c) */

/* localdecomp:start func_L33_003A1080 */
extern u8 *D_001A71A0[];
extern u8 D_L33_001E27A0[];
extern u8 D_L33_001D66B0;
extern u32 D_001DEB40_sda;
__asm__(".extern D_001DEB40_sda, 4");
extern void func_L01_00442E08(u8 *, s32);
extern void func_003C2868(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_L01_00452F60(void *);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_L02_00426140(void *, void *, s32, s32, void *, f32, f32, f32, f32, u32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);

void func_L33_003A1080(u8 *self) {
    s32 *s1;
    s32 s2;
    s32 a1;
    u8 *v1;
    f32 v[4];

    s1 = *(s32 **)(self + 0x68);
    switch (self[0x20]) {
    case 0:
        a1 = s1[0];
        if (a1 != *(s16 *)(self + 0xAA)) {
            if (a1 > 0) {
                func_L01_00442E08(self, a1);
                func_003C2868(self);
                *(u16 *)(self + 0x34) &= 0xFFFA;
                self[0x40] = 0;
                self[0x41] = 0;
            }
        }
        func_L01_00441FB8(self, 1, -1);
        break;
    case 1:
        s2 = 0;
        if (s1[2] != 0) {
            *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
            v1 = (u8 *)func_L01_00444358(self, 0x10000, 0);
            if (v1 != 0) {
                self[0xA8] = 0xFF;
                if (0.0f < *(f32 *)(v1 + 0x2C)) {
                    s32 x = *(s16 *)(*(u8 **)(v1 + 0x20) + 0xAA);
                    if (x == *(s16 *)(D_001A71A0[0] + 0xAA) || x == 0x173F || x == 0x1F01) {
                        s2 = 1;
                    }
                }
            }
        }
        if (func_L01_00452F60(self) == 0 && s2 == 0) {
            return;
        }
        if (s1[0] == 0x1985) {
            func_L01_004A72A8(1, 0, self, 0x1985);
        }
        if (s1[0] == 0x1C5D) {
            func_L01_004A72A8(0, 0, self, 0x1C5D);
        }
        func_L01_00441FB8(self, 2, -1);
        break;
    case 2:
        if (func_L01_00452EC8(self) == 0) {
            return;
        }
        func_00388830(v, D_L33_001E27A0, 0.0116666667f);
        func_0039FE80(0, 0, self);
        func_L01_0044ED60(self, 0x1F, v, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0x50, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        if (*(s16 *)(self + 0xAA) == 0x1907) {
            func_L02_00426140(self, self + 0x10, func_0037E208(10, 13), 1, &D_L33_001D66B0, 1.5f, 3.0f, 1.75f, 2.5f,
                              D_001DEB40_sda, 0, 0x46);
        }
        a1 = s1[1];
        if (a1 >= 0) {
            func_L01_00442E08(self, a1);
            func_003C2868(self);
            self[0x40] = 0;
            *(u16 *)(self + 0x34) &= 0xFFFA;
            self[0x41] = 0;
        } else {
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(self, 1);
        }
        break;
    }
}
/* localdecomp:end func_L33_003A1080 */
