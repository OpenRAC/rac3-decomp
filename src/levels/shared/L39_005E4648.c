#include "common.h"

/* localdecomp:start func_L39_005E4648 */
extern s32 D_001D837C_sda;
extern f32 D_001D8388_sda;
extern f32 D_001D8390_sda;
extern f32 D_001D8394_sda;
extern f32 D_001D8398_sda;
extern f32 D_001D839C_sda;
extern f32 D_001D83A0_sda;
__asm__(".extern D_001D8388_sda, 4");
__asm__(".extern D_001D8390_sda, 4");
__asm__(".extern D_001D8394_sda, 4");
__asm__(".extern D_001D8398_sda, 4");
__asm__(".extern D_001D839C_sda, 4");
__asm__(".extern D_001D83A0_sda, 4");
extern s32 D_L39_0049A258[];
extern void func_L01_004637C0_005E4648(void);
extern void func_L01_004903F0(s32 *);
extern void func_L01_00499B20(s32, f32 *, f32 *);
extern s32 func_00381FF0(s32);
extern void func_L39_005E7598(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern s32 func_003E8348(s32, s32);
extern void func_L39_005E5118(void);
extern void func_L01_00484A80(s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516C78_005E4648(s32, s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_003E8B98(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern void func_L39_005E5CD8(void);

static __inline__ f32 rowY_005E4648(s32 row) {
    return D_001D8388_sda + D_001D8390_sda * row;
}

void func_L39_005E4648(void) {
    f32 a = 1.0f;
    f32 b = 0.0f;
    D_001D837C_sda = -1;
    func_L01_004637C0_005E4648();
    func_L01_004903F0(D_L39_0049A258);
    func_L01_00499B20(0xCBD, &a, &b);
    func_L39_005E7598(0x10, b, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_00381FF0(0xCBD), 0xD0006, 0xFF, 0xD0007, 0xCD5);
    func_L01_00517538(0xD0005, a, a);
    func_003E8348(0x11, 0x1E0000);
    func_L39_005E5118();
    func_L01_00484A80(0x1E0006);
    func_003E9270(0x1E0009, 0x706EC8FF, D_001D8394_sda + D_001D839C_sda, rowY_005E4648(1), 0.01953f, 0.040868f, 0.004f, 0.005f);
    func_003E9270(0x1E0008, 0x332299DE, (D_001D8394_sda + D_001D839C_sda + D_001D8398_sda) * 0.5f, rowY_005E4648(1), D_001D8398_sda - (D_001D8394_sda + D_001D839C_sda), D_001D83A0_sda, 0.004f, 0.005f);
    func_003E9138(0x1E0007, 0x332299DE, 0, D_001D8394_sda + D_001D839C_sda + 0.004f, rowY_005E4648(1), D_001D8398_sda - (D_001D8394_sda + D_001D839C_sda) - 0.008f, D_001D83A0_sda - 0.01f);
    func_L01_00516C78_005E4648(0x1E0007, 1, 3);
    func_003E9270(0x1E000C, 0x706EC8FF, D_001D8394_sda + D_001D839C_sda, rowY_005E4648(2), 0.01953f, 0.040868f, 0.004f, 0.005f);
    func_003E9270(0x1E000B, 0x332299DE, (D_001D8394_sda + D_001D839C_sda + D_001D8398_sda) * 0.5f, rowY_005E4648(2), D_001D8398_sda - (D_001D8394_sda + D_001D839C_sda), D_001D83A0_sda, 0.004f, 0.005f);
    func_003E9138(0x1E000A, 0x332299DE, 0, D_001D8394_sda + D_001D839C_sda + 0.004f, rowY_005E4648(2), D_001D8398_sda - (D_001D8394_sda + D_001D839C_sda) - 0.008f, D_001D83A0_sda - 0.01f);
    func_L01_005170B8(0x1E0008, 0x331465B7);
    func_L01_005170B8(0x1E0007, 0x60000000);
    func_L01_005170B8(0x1E000B, 0x331465B7);
    func_L01_005170B8(0x1E000A, 0x60000000);
    func_L01_00516C78_005E4648(0x1E000A, 1, 3);
    func_003E8B98(0x1E0006, 0x1E0007, 0x1E0008, 0x1E000A, 0x1E0009, 0x1E000B, 0x1E000C);
    func_003E8A08(0x1E0000, 0x1E0006, 0x1E000D);
    func_L39_005E5CD8();
}
/* localdecomp:end func_L39_005E4648 */

INCLUDE_ASM("asm/levels", func_L39_005E4A40);
