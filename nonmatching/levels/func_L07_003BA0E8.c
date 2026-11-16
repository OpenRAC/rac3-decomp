/* PAL level-07 reconstruction from the owned retail ELF (Wave2 P04).
 * Near miss: stock tools/check.py reports 169 diff with the owning-file flags.
 * State-handler reconstruction; global addressing, expression scheduling and loop/state-tail layout still differ.
 * Checked with the owning file's normal prelude/earlier declarations; not linked.
 */
#include "common.h"
extern u8 *D_001DE508_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DE508_sda, 4");
extern f32 D_001DED50_sda;
extern s32 D_L07_001F2140;
extern s32 D_L07_001A8018;
extern s32 D_L07_001D545C;
extern u16 D_L07_001A7D00, D_L07_001A7DA8;
extern s32 D_L07_001A8060, D_L07_001A7F4C;
extern s32 D_L07_001D4C38, D_L07_001DF518, D_L07_001D7B20;
extern s32 D_L07_001A7430;
extern f32 D_L07_001E0540;
extern void func_L01_005003D0(s32, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_L01_00479280(void);
extern void func_L01_0047B420(void);
extern void func_L01_0047B990(void);
extern s32 func_L01_004561B8(u8 *);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L07_003BB360(u8 *);
extern void func_L07_003BB410(u8 *);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_L01_00513EF0(void);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L07_003A2380(s32, u8 *, s32, s32);
extern void func_L07_003BA970(u8 *);
void func_L07_003BA0E8(u8 *self) {
    u8 *p = *(u8 **)(self + 0x68);
    s32 i, choice;
    u8 *row;
    f32 time;
    switch (self[0x20]) {
    case 0:
        D_001DE508_sda = self;
        self[0x30] = 255;
        p[0xAE] = 255;
        p[0xAF] = 0;
        *(u16 *)(self + 0x34) |= 1;
        func_L01_004450F0(self, 1, -1);
        break;
    case 1: break;
    case 2:
        if (D_001DED50_sda <= 0.0f) {
            D_001DED50_sda = 0.0f;
            func_L01_005003D0(0, 1);
            p[0xB0] = 1;
            func_L01_0045F1E8(*(s32 *)(p + 0x90), -1);
            func_L01_00479280();
            func_L01_0047B420();
            func_L01_0047B990();
            func_L01_004450F0(self, 3, -1);
        } else D_001DED50_sda -= 0.0960000008f;
        break;
    case 3:
        if (!D_L07_001F2140 && func_L01_004561B8(self)) {
            func_003A52A0(0, 4, self);
            func_003A52A0(1, 4, self);
        }
        func_L07_003BB360(self);
        func_L07_003BB410(self);
        if (++*(u16 *)(self + 0x96) > 900 && !(D_L07_001A8018 & (1 << D_L07_001D545C)) && !D_L07_001A7D00)
            func_L01_0041A5B0(0xB87, 0x2A);
        if (!func_L01_00513EF0()) {
            if (func_00382380((u8 *)&D_001A4BE0 + 0x80, *(s32 *)(p + 0x48), 0) && !D_L07_001A7DA8 && !(D_L07_001A8060 & (1 << D_L07_001D545C)))
                func_L01_0041A5B0(0xB8D, 0x30);
        }
        D_L07_001D7B20 = p[0xAE] + 0x21;
        D_L07_001DF518 = D_L07_001D4C38;
        for (i = 0, row = p; i < 8; i++, row += 4) {
            if (*(s32 *)row != -1 && *(s32 *)(row + 0x20) != -1) {
                if (func_00382380((u8 *)&D_001A4BE0 + 0x80, *(s32 *)row, 0)) p[0xAF] |= 1 << i;
                else p[0xAF] &= ~(1 << i);
            }
        }
        if (p[0xB0] == 1) {
            time = (f32)D_L07_001A7430 + D_L07_001E0540;
            if (*(f32 *)(p + 0x9C) < time) *(f32 *)(p + 0x9C) = time;
            else if (time < *(f32 *)(p + 0x9C)) p[0xB0] = 0;
        }
        if (!func_L01_00513EF0()) {
            if (*(s32 *)(p + 0xBC) != -1 && func_00382380((u8 *)&D_001A4BE0 + 0x80, *(s32 *)(p + 0xBC), 0) && !(D_L07_001A7F4C & (1 << D_L07_001D545C)))
                func_L01_0041A5B0(0xB76, 0x19);
        }
        if (*(s16 *)(p + 0xA0) & 0x8080) {
            choice = func_00382468(4);
            switch (choice) {
            case 0: func_L07_003A2380(0x4F, self, 0, 100); break;
            case 1: func_L07_003A2380(0x50, self, 0, 100); break;
            default: func_L07_003A2380((u8)func_00382498(0x67, 0x69), self, 0, 100); break;
            }
            func_L07_003BA970(self);
        }
        break;
    }
}
