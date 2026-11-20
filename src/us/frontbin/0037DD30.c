#include "common.h"

/* NTSC-U counterpart of func_00381D88 (src/frontbin/381140.c): fade timed for 60 Hz (90/15/30/165/181 for 75/12/25/138/151) */
/* localdecomp:start func_U_0037DD30 */
typedef struct { u8 p0[0xAD]; u8 bAD; } S_143950_37DD30;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; } S_142430_37DD30;
extern S_143950_37DD30 D_00143950;
extern S_142430_37DD30 D_00142430;
extern s32 D_U_001D568C;
extern s32 D_U_001D5690;
extern s32 D_U_001D5694;
extern s32 D_U_00227480[];
extern s32 D_001D4D40;
extern void func_U_00389920(s32);
extern void func_13D3C0(s32);
extern s32 func_U_0038E2E8();
extern s32 func_U_0038E440();
extern s32 func_U_0037DF98(s32);
extern void func_U_0038C888(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
__asm__(".extern D_U_001D568C, 4");
__asm__(".extern D_U_001D5690, 4");
__asm__(".extern D_U_001D5694, 4");
extern void func_U_0037E070(void);
extern void func_U_0038B1E8(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_U_0037DD30(void) {
    s16 buf[16];
    s32 x;
    if (D_U_001D5694 < 0x5A) x = (D_U_001D5694 - 0xF) * 0xE0 / 0x1E;
    else x = (0xA5 - D_U_001D5694) * 0xE0 / 0x1E;
    if (x < 0) x = 0;
    if (x > 0xE0) x = 0xE0;
    D_U_001D5694++;
    x = (x | (((x << 16) | 0x80000000) | (x << 8)));
    func_U_00389920(1);
    switch (D_U_001D5690) {
    case 7:
        D_001D4D40 = 0;
        if (D_00143950.bAD != 0) func_U_0038E2E8(D_U_00227480, 0x1D);
        else func_U_0038E2E8(D_U_00227480, 0x1F);
        D_U_00227480[0] = 4;
        func_U_0038E440(D_U_00227480);
        D_U_001D5694 = 0;
        D_U_001D5690 = 8;
        break;
    case 8:
        D_U_001D568C = 0;
        func_13D3C0(10);
        if (D_00142430.f15C == 2 && D_00142430.f164 < 0) {
            D_00142430.f168 = 0;
            D_00142430.f164 = 0x18;
        }
        break;
    case 9:
        D_U_001D568C = 1;
        func_U_0038C888(buf, 0, 0x1E0, 0x20, 0x1E0, 0x100, 0xC8, 0x10, 3);
        ((void (*)(s16 *, s32, s32, s32, unsigned long, f32, f32))func_U_0038B1E8)(buf, x, func_U_0037DF98(0x1700), -1, 0x80000000UL, 1.0f, 1.0f);
        if (D_U_001D5694 >= 0xB5) func_U_0037E070();
        break;
    }
}
/* localdecomp:end func_U_0037DD30 */
