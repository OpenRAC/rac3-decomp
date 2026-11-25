#include "common.h"

/* declared by functions of L01_004BCAE8.c, which this file was cut from */
typedef struct {
    s32 id;
    u8 pad4[12];
    u8 b16;
    u8 b17;
    u8 pad18[2];
} Slot_004B6C98;
typedef struct {
    u8 pad0[128];
    s32 cur;
    u8 pad84[188];
    Slot_004B6C98 slots[79];
    u8 pad76C[16];
    s32 unk77C;
} S_00244740;
typedef struct {
    s32 type;
    u8 b4;
    u8 p5[11];
    u8 b16;
    u8 p17[2];
    u8 b19;
} E_4BBAF0;

/* localdecomp:start func_L01_004BD4A8 */
typedef struct {
    s32 state;
    u8 pad4[8];
    s32 held;
    u8 pad10[0x90];
} Pad_4BD4A8_004BD4A8;
typedef struct {
    u8 pad0[8];
    Pad_4BD4A8_004BD4A8 pads[2];
    u8 pad148[0x14];
    s32 f15C;
    u8 pad160[4];
    s32 f164;
} Pads_4BD4A8_004BD4A8;
typedef struct {
    u8 pad0[0x38];
    s32 f38;
    u8 pad3C[0x14];
    s32 mode;
    u8 pad54[0x2C];
    s32 cur;
    s32 pending;
    u8 pad88[0xB8];
    E_4BBAF0 e[76];
} Menu_4BD4A8_004BD4A8;
extern S_00244740 D_L01_002446C0_004BD4A8[];
extern Pads_4BD4A8_004BD4A8 D_00142430;
extern char *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern u8 D_L01_001E0F30_004BD4A8;
extern u8 D_L01_001E0F31_004BD4A8;
__asm__(".extern D_L01_001E0F30_004BD4A8, 1");
__asm__(".extern D_L01_001E0F31_004BD4A8, 1");
extern void func_L01_004BC0F8_004BD4A8(u8 *, u8 *);
extern void func_L01_004BCAE8_004BD4A8(u8 *, u8 *);
extern void func_L01_004BCD08_004BD4A8(u8 *, u8 *);
extern void func_L01_004BCFB0_004BD4A8(u8 *, u8 *);
extern s32 *func_003B9BD0(s32);
extern void func_003BA4F8(void *, s32);

void func_L01_004BD4A8(void) {
    s32 mode;
    s32 a;
    s32 b;

    if (((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->pending == 0) {
        return;
    }
    mode = ((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->mode;
    if (mode == 0) {
        if (((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->e[((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->cur].b19 == 0) {
            func_L01_004BC0F8_004BD4A8(&D_L01_001E0F30_004BD4A8, &D_L01_001E0F31_004BD4A8);
            return;
        }
        a = 0;
        if (D_00142430.f15C < 3 && D_00142430.f164 < 0 && D_00142430.pads[0].state == 2) {
            a = D_00142430.pads[0].held != 0;
        }
        b = 0;
        if (D_00142430.f15C < 3 && D_00142430.f164 < 0 && D_00142430.pads[1].state == 2) {
            b = D_00142430.pads[1].held != 0;
        }
        if (a | b) {
            ((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->f38 = 4;
        }
        ((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->pending = 0;
    } else if (mode == 2) {
        func_L01_004BCFB0_004BD4A8(&D_L01_001E0F30_004BD4A8, &D_L01_001E0F31_004BD4A8);
    } else if (mode == 3) {
        func_L01_004BCAE8_004BD4A8(&D_L01_001E0F30_004BD4A8, &D_L01_001E0F31_004BD4A8);
    } else if (mode == 5) {
        func_003BA4F8(func_003B9BD0(0), *(s32 *)(D_001D52FC + 0x1C4));
        func_L01_004BCD08_004BD4A8(&D_L01_001E0F30_004BD4A8, &D_L01_001E0F31_004BD4A8);
    }
}
/* localdecomp:end func_L01_004BD4A8 */
