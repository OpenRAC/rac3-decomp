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

/* localdecomp:start func_L39_005E4A40 */
typedef struct {
    u8 pad0[0x1C4];
    s32 f1C4;
} S_005E4A40;
__asm__(".extern D_001D83A4_sda, 4");
extern s32 D_001D83A4_sda;
__asm__(".extern D_001D8384_sda, 4");
extern s32 D_001D8384_sda;
__asm__(".extern D_001D8380_sda, 4");
extern s32 D_001D8380_sda;
__asm__(".extern D_001D83E4_sda, 4");
extern s32 D_001D83E4_sda;
__asm__(".extern D_001D83E8_sda, 4");
extern s32 D_001D83E8_sda;
__asm__(".extern D_001D5A54_sda, 4");
extern S_005E4A40 *D_001D5A54_sda;
__asm__(".extern D_001D8378_sda, 4");
extern s32 D_001D8378_sda;
extern s32 D_002413A0;
extern u8 D_002429AC;
extern u8 D_L39_0049A158[];
extern u8 D_00243B00[];
extern s32 func_L01_00517688(void);
extern u8 *func_L39_0061BF38(s32);
extern s32 func_003B97B0(void);
extern s32 func_L01_003BEAA0(void);
extern s32 func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_003B9700(s32, s32, s32, s32, s32);
extern void func_003B96D8(s32, s32);
extern void func_003B6438(void);
extern void func_003B9890(void);
extern void func_00391408(s32, s32, s32);
extern void func_L39_005D6A78(s32, s32);
extern s32 func_L39_005E6118(void);
extern s32 func_003B9BD0(s32);
extern void func_L39_005E8598(s32, s32);
extern s32 func_003B9C58(s32);
extern void func_L39_005E5678(void *, s32);
extern void func_L39_005E5768(void);
extern void func_L39_005E5CD8(void);
extern s32 func_L01_00432F50(void);
extern void func_L01_0041A508(void);
extern void func_L01_00353C80(void *);
extern s32 func_00381CC0(void);
extern void func_L01_00517748(s32);

void func_L39_005E4A40(void *a0) {
    s32 sel = 0;
    s32 q = 0;
    s32 r;
    s32 u1;
    s32 u2;
    s32 x;
    s32 y;
    s32 m;
    r = func_L01_00517688();
    *(s32 *)(*(s32 *)(func_L39_0061BF38(func_L01_00517688()) + 0x2534) + 0x1CC) = 2;
    switch (r) {
    case 0: sel = 0; break;
    case 1: sel = 1; break;
    case 2: sel = 2; break;
    case 3: sel = 3; break;
    default: break;
    }
    switch (D_001D83A4_sda) {
    case 1:
        if (func_003B97B0() == 0) {
            switch (func_L01_003BEAA0()) {
            case 1:
                D_001D83E8_sda = D_001D8380_sda;
                D_001D83E4_sda = D_001D8384_sda;
                func_00120048(D_L39_0049A158, D_00243B00, func_00381FF0(0x511), func_00381FF0(0x512), D_001D83E8_sda, func_00381FF0(0x513));
                u1 = func_00381FF0(0x8E3);
                u2 = func_00381FF0(0x8DF);
                func_003B9700(0, u1, u2, (s32)D_L39_0049A158, 0);
                func_003B96D8(0x20, 0x10);
                D_001D83A4_sda = 2;
                break;
            case 2:
                D_001D83A4_sda = 0;
                break;
            }
        }
        break;
    case 2:
        D_002413A0 = D_002413A0 == 0;
        func_003B6438();
        D_001D83A4_sda = 3;
        break;
    case 3:
        func_00120048(D_L39_0049A158, D_00243B00, func_00381FF0(0x511), func_00381FF0(0x512), D_001D83E8_sda, func_00381FF0(0x513));
        if (func_003B97B0() == 0) {
            switch (func_L01_003BEAA0()) {
            case 1:
                D_001D83A4_sda = 0;
                break;
            case 2:
                D_001D83A4_sda = 4;
                break;
            }
        } else {
            if (--D_001D83E4_sda <= 0) {
                if (--D_001D83E8_sda <= 0) {
                    ((s32 (*)(void))func_003B9890)();
                    D_001D83A4_sda = 4;
                }
                D_001D83E4_sda = D_001D8384_sda;
            }
        }
        break;
    case 4:
        D_002413A0 = D_002413A0 == 0;
        func_003B6438();
        D_001D83A4_sda = 0;
        break;
    case 5:
        if (func_003B97B0() == 0) {
            D_001D83A4_sda = 0;
        } else {
            if (D_001D5A54_sda->f1C4 & 0x8000) x = -1; else { m = D_001D5A54_sda->f1C4 & 0x2000; x = m != 0; }
            if (D_001D5A54_sda->f1C4 & 0x1000) y = -1; else { m = D_001D5A54_sda->f1C4 & 0x4000; y = m != 0; }
            func_00391408(x, y, 1);
        }
        break;
    case 0:
        func_L39_005D6A78(r, 10);
        q = func_L39_005E6118();
        func_L39_005E8598(func_003B9BD0(sel), q);
        D_001D8378_sda = func_003B9C58(func_003B9BD0(sel));
        func_L39_005E5678(a0, q);
        func_L39_005E5768();
        func_L39_005E5CD8();
        break;
    }
    if (func_L01_00432F50() != 0) {
        func_L01_0041A508();
        func_L01_00353C80(a0);
        if (D_002429AC == 0) {
            func_L01_00517748(func_00381CC0());
        }
    }
}
/* localdecomp:end func_L39_005E4A40 */
