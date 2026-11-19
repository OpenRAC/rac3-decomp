#include "common.h"

/* localdecomp:start func_L03_003A3838 */
extern s32 D_001D67C8;
extern u8 *D_001D52FC;
extern u8 D_001427BB[16];
extern s32 D_L03_001DD638;
__asm__(".extern D_L03_001DE3F8, 4");
__asm__(".extern D_L03_001DE3FC, 4");
__asm__(".extern D_L03_001DE400, 4");
__asm__(".extern D_L03_001DE404, 4");
__asm__(".extern D_L03_001DE408, 4");
__asm__(".extern D_L03_001DE40C, 4");
__asm__(".extern D_L03_001DE410, 4");
__asm__(".extern D_L03_001DE414, 4");
__asm__(".extern D_L03_001DE418, 4");
__asm__(".extern D_L03_001DE41C, 4");
__asm__(".extern D_L03_001DE420, 4");
__asm__(".extern D_L03_001DE424, 4");
__asm__(".extern D_L03_001DE428, 4");
__asm__(".extern D_L03_001DE42C, 4");
__asm__(".extern D_L03_001DE430, 4");
extern s32 D_L03_002BA300[];
extern f32 D_L03_001DE3F8;
extern f32 D_L03_001DE3FC;
extern f32 D_L03_001DE400;
extern f32 D_L03_001DE404;
extern f32 D_L03_001DE408;
extern f32 D_L03_001DE40C;
extern f32 D_L03_001DE410;
extern f32 D_L03_001DE414;
extern f32 D_L03_001DE418;
extern f32 D_L03_001DE41C;
extern f32 D_L03_001DE420;
extern f32 D_L03_001DE424;
extern f32 D_L03_001DE428;
extern f32 D_L03_001DE42C;
extern f32 D_L03_001DE430;
__asm__(".extern D_001D67C8, 16");
__asm__(".extern D_001D52FC, 16");

extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004CB548(void);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L03_00503EB8(s32);
extern void func_003B5060(s32);
extern void func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00381FF0(s32);
extern s32 func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_003E8C68(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8B98(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_L01_005003D0(s32, s32);
extern s32 func_L01_00517918(s32);
extern void func_00392DF0(s32, s32);
extern void func_L01_004DB2E8(void);
extern void *func_L01_00496378(void);
extern void func_L01_00517748(s32);

void func_L03_003A3838(u8 *a0) {
    s32 *s1;
    s32 s2;
    s32 i;

    *(s32 *)(a0 + 0x98) = 0;
    s1 = *(s32 **)(a0 + 0x68);
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(a0, 1);
    if (func_L01_004CB548() != 0) {
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
    }
    if (*(u8 *)(a0 + 0x20) == 0 && D_001D67C8 != 0 && func_L01_004CB548() != 0) {
        func_L03_00503EB8(0);
        func_003B5060(0xB0000);
        func_003B5060(0xB0001);
        func_003B5060(0xB0002);
        func_003B5060(0xB0003);
        func_003E8EF0(0xB0004, 0xC, 0x332299DE, D_L03_001DE3F8, D_L03_001DE400, -1.0f, 1.0f, D_L03_001DE430);
        func_003E8EF0(0xB0005, 0xC, 0x332299DE, D_L03_001DE3FC, D_L03_001DE400, 1.0f, 1.0f, D_L03_001DE430);
        func_003E8EF0(0xB0006, 0xD, 0x332299DE, D_L03_001DE3FC, D_L03_001DE400, 1.0f, 1.0f, D_L03_001DE430);
        func_003E8EF0(0xB0008, 0xD, 0x332299DE, D_L03_001DE3F8, D_L03_001DE400, -1.0f, 1.0f, D_L03_001DE430);
        func_003E8EF0(0xB0009, 0xD, 0x332299DE, D_L03_001DE3FC, D_L03_001DE404, 1.0f, -1.0f, D_L03_001DE430);
        func_003E8EF0(0xB000A, 0xD, 0x332299DE, D_L03_001DE3F8, D_L03_001DE404, -1.0f, -1.0f, D_L03_001DE430);
        func_003E9138(0xB0021, 0x331465B7, 0, 0.5f, 0.4655f, 0.36f, 0.23f);
        for (i = 7; i >= 0; i--) {
            s1[4 + i] = 0;
        }
        func_003E90B8(0xB000E, func_00381FF0(0x18C2), 0x7075D5FF, D_L03_001DE408, D_L03_001DE40C, 0.95f, 0.95f, 0.005f, 0.005f);
        func_003E90B8(0xB000F, func_00381FF0(0x177B), 0x7075D5FF, D_L03_001DE410 + D_L03_001DE418, D_L03_001DE414, D_L03_001DE41C, 1.0f, 0.003f, 0.003f);
        func_003E90B8(0xB0010, func_00381FF0(0x177B), 0x7075D5FF, D_L03_001DE410 + D_L03_001DE418 * 2.0f, D_L03_001DE414, D_L03_001DE41C, 1.0f, 0.003f, 0.003f);
        func_003E90B8(0xB0011, func_00381FF0(0x177B), 0x7075D5FF, D_L03_001DE410 + D_L03_001DE418 * 3.0f, D_L03_001DE414, D_L03_001DE41C, 1.0f, 0.003f, 0.003f);
        func_003E90B8(0xB0012, func_00381FF0(0x177B), 0x7075D5FF, D_L03_001DE410 + D_L03_001DE418 * 4.0f, D_L03_001DE414, D_L03_001DE41C, 1.0f, 0.003f, 0.003f);
        func_003E90B8(0xB0013, func_00381FF0(0x177B), 0x7075D5FF, D_L03_001DE410 + D_L03_001DE418 * 5.0f, D_L03_001DE414, D_L03_001DE41C, 1.0f, 0.003f, 0.003f);
        func_003E90B8(0xB0014, func_00381FF0(0x177B), 0x7075D5FF, D_L03_001DE410 + D_L03_001DE418 * 6.0f, D_L03_001DE414, D_L03_001DE41C, 1.0f, 0.003f, 0.003f);
        func_003E90B8(0xB0015, func_00381FF0(0x177B), 0x7075D5FF, D_L03_001DE410 + D_L03_001DE418 * 7.0f, D_L03_001DE414, D_L03_001DE41C, 1.0f, 0.003f, 0.003f);
        func_003E90B8(0xB0016, func_00381FF0(0x177B), 0x7075D5FF, D_L03_001DE410 + D_L03_001DE418 * 8.0f, D_L03_001DE414, D_L03_001DE41C, 1.0f, 0.003f, 0.003f);
        func_003E90B8(0xB0017, D_L03_002BA300[s1[4]], 0x7075D5FF, D_L03_001DE42C + D_L03_001DE418, D_L03_001DE420, D_L03_001DE424, D_L03_001DE428, 0.005f, 0.005f);
        func_003E90B8(0xB0018, D_L03_002BA300[s1[5]], 0x7075D5FF, D_L03_001DE42C + D_L03_001DE418 * 2.0f, D_L03_001DE420, D_L03_001DE424, D_L03_001DE428, 0.005f, 0.005f);
        func_003E90B8(0xB0019, D_L03_002BA300[s1[6]], 0x7075D5FF, D_L03_001DE42C + D_L03_001DE418 * 3.0f, D_L03_001DE420, D_L03_001DE424, D_L03_001DE428, 0.005f, 0.005f);
        func_003E90B8(0xB001A, D_L03_002BA300[s1[7]], 0x7075D5FF, D_L03_001DE42C + D_L03_001DE418 * 4.0f, D_L03_001DE420, D_L03_001DE424, D_L03_001DE428, 0.005f, 0.005f);
        func_003E90B8(0xB001B, D_L03_002BA300[s1[8]], 0x7075D5FF, D_L03_001DE42C + D_L03_001DE418 * 5.0f, D_L03_001DE420, D_L03_001DE424, D_L03_001DE428, 0.005f, 0.005f);
        func_003E90B8(0xB001C, D_L03_002BA300[s1[9]], 0x7075D5FF, D_L03_001DE42C + D_L03_001DE418 * 6.0f, D_L03_001DE420, D_L03_001DE424, D_L03_001DE428, 0.005f, 0.005f);
        func_003E90B8(0xB001D, D_L03_002BA300[s1[10]], 0x7075D5FF, D_L03_001DE42C + D_L03_001DE418 * 7.0f, D_L03_001DE420, D_L03_001DE424, D_L03_001DE428, 0.005f, 0.005f);
        func_003E90B8(0xB001E, D_L03_002BA300[s1[11]], 0x7075D5FF, D_L03_001DE42C + D_L03_001DE418 * 8.0f, D_L03_001DE420, D_L03_001DE424, D_L03_001DE428, 0.005f, 0.005f);
        func_L01_005170B8(0xB0021, 0x60804040);
        func_003E8C68(0xB0000, 0xB0021, 0xB0004, 0xB0005, 0xB0006, 0xB0008, 0xB0009, 0xB000A);
        func_003E8348(0, 0xB0000);
        func_003E8C68(0xB0001, 0xB000E, 0xB000F, 0xB0010, 0xB0011, 0xB0012, 0xB0013, 0xB0014);
        func_003E8348(1, 0xB0001);
        func_003E8B98(0xB0002, 0xB0015, 0xB0016, 0xB0017, 0xB0018, 0xB0019, 0xB001A);
        func_003E8348(2, 0xB0002);
        func_003E8B98(0xB0003, 0xB001D, 0xB001E, 0xB001F, 0xB0020, 0xB001B, 0xB001C);
        func_003E8348(3, 0xB0003);
        *(u8 *)(a0 + 0x20) = 1;
        func_L01_005003D0(0x74, 1);
        s1[2] = 0;
        s1[0] = 0xB000F;
        s1[1] = 0xB0017;
        func_L03_00503EB8(0);
    }
    s2 = *(u8 *)(a0 + 0x20);
    if (s2 == 1) {
        s32 fl;
        func_L01_005170B8(s1[0], 0x70FFFFFF);
        func_L01_005170B8(s1[1], 0x70FFFFFF);
        func_L01_00516FD8(0xB0017, D_L03_002BA300[s1[4]]);
        func_L01_00516FD8(0xB0018, D_L03_002BA300[s1[5]]);
        func_L01_00516FD8(0xB0019, D_L03_002BA300[s1[6]]);
        func_L01_00516FD8(0xB001A, D_L03_002BA300[s1[7]]);
        func_L01_00516FD8(0xB001B, D_L03_002BA300[s1[8]]);
        func_L01_00516FD8(0xB001C, D_L03_002BA300[s1[9]]);
        func_L01_00516FD8(0xB001D, D_L03_002BA300[s1[10]]);
        func_L01_00516FD8(0xB001E, D_L03_002BA300[s1[11]]);
        fl = *(s32 *)(D_001D52FC + 0x1A4);
        if (fl & 0x2000) {
            if (s1[0] <= 0xB0015) {
                func_L01_005170B8(s1[0], 0x7075D5FF);
                func_L01_005170B8(s1[1], 0x7075D5FF);
                s1[0] = s1[0] + 1;
                s1[1] = s1[1] + 1;
                s1[2] = s1[2] + 1;
            }
        } else if (fl & 0x8000) {
            if (s1[0] > 0xB000F) {
                func_L01_005170B8(s1[0], 0x7075D5FF);
                func_L01_005170B8(s1[1], 0x7075D5FF);
                s1[0] = s1[0] - 1;
                s1[1] = s1[1] - 1;
                s1[2] = s1[2] - 1;
            }
        } else if (fl & 0x1000) {
            s32 *b4 = s1 + 4;
            s32 *e = &b4[s1[2]];
            if (*e < 0x1A) {
                *e = *e + 1;
            } else if (*e == 0x1A) {
                *e = 0;
            }
        } else if (fl & 0x4000) {
            s32 *b4 = s1 + 4;
            s32 *e = &b4[s1[2]];
            if (*e > 0) {
                *e = *e - 1;
            } else if (*e == 0) {
                *e = 0x1A;
            }
        } else if (fl & 0x800) {
            if (s1[4] == 0 && s1[5] == 0xD && s1[6] == 5 && s1[7] == 7 && s1[8] == 8 && s1[9] == s2 && s1[10] == 0xE && s1[11] == 0) {
                func_L01_00517918(0);
                func_L01_00517918(1);
                func_L01_00517918(2);
                func_L01_00517918(3);
                D_001427BB[0] = s2;
                *(u8 *)(a0 + 0x20) = 2;
                func_00392DF0(0x18, 1);
            }
            if (s1[4] == 0x19 && s1[5] == 9 && s1[6] == 0xE && s1[7] == 7 && s1[8] == 0 && s1[9] == 0x14) {
s2 = 0;
 i = 0;
            }
        } else if (fl & 0x10) {
            func_L01_005003D0(0, 1);
            func_L01_00517918(0);
            func_L01_00517918(1);
            func_L01_00517918(2);
            func_L01_00517918(3);
            func_L01_004DB2E8();
            func_L01_00517748((s32)func_L01_00496378());
            *(u8 *)(a0 + 0x20) = 0;
            *(u8 *)(a0 + 0xBC) = 0;
        }
    } else if (s2 == 2 || D_001427BB[0] != 0) {
        if (*(s32 *)(D_001D52FC + 0x1A4) & 0x800) {
            D_L03_001DD638 = 0;
        }
    }
}
/* localdecomp:end func_L03_003A3838 */
