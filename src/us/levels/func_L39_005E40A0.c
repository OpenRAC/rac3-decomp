#include "common.h"

/* NTSC-U counterpart of func_L39_005E6610 (src/levels/shared/L39_005E6388.c) */
/* localdecomp:start func_L39_005E40A0 */
__asm__(".extern D_001D8458_sda_005E40A0, 4");
extern s32 D_001D8458_sda_005E40A0;
__asm__(".extern D_L39_00242B2C, 16");
extern u8 D_L39_00242B2C;
extern s32 func_L01_00513698(void);
extern u8 *func_L39_006197C0(s32);
extern void func_L39_005D4508(s32, s32);
extern s32 func_003B9BD0_005E40A0(s32);
extern void func_L39_005E6028(s32, s32);
extern void func_L39_005E4708(void);
extern void func_L39_005E4598(s32, s32);
extern void func_L39_005E4CD8(void);
extern s32 func_003B97B0_005E40A0(void);
extern s32 func_L01_003BD258(void);
extern void func_L39_005992A8(s32, s32);
extern void func_001950F8(s32);
extern s32 func_L01_004300C0(void);
extern void func_L01_00417EB8(void);
extern void func_L01_00353138(s32);
extern s32 func_00381CC0_005E40A0(void);
extern void func_L01_00513758(s32);

void func_L39_005E40A0(s32 arg0) {
    s32 mode = 0;
    s32 sel;
    u8 *o;
    o = func_L39_006197C0(func_L01_00513698());
    sel = D_001D8458_sda_005E40A0;
    switch (sel) {
    case 0:
        *(s32 *)(*(u8 **)(o + 0x2534) + 0x1CC) = 2;
        sel = *(s32 *)(*(u8 **)(o + 0x2534) + 0x1C4);
        func_L39_005D4508(func_L01_00513698(), 10);
        switch (func_L01_00513698()) {
        case 0:
            mode = 0;
            break;
        case 1:
            mode = 1;
            break;
        case 2:
            mode = 2;
            break;
        case 3:
            mode = 3;
            break;
        }
        func_L39_005E6028(func_003B9BD0_005E40A0(mode), sel);
        func_L39_005E4708();
        func_L39_005E4598(arg0, sel);
        func_L39_005E4CD8();
        break;
    case 1:
        if (func_003B97B0_005E40A0() == 0) {
            D_001D8458_sda_005E40A0 = 0;
            if (func_L01_003BD258() == 1) {
                func_L39_005992A8(-1, 1);
                func_001950F8(8);
            }
        }
        break;
    }
    if (func_L01_004300C0() != 0) {
        func_L01_00417EB8();
        func_L01_00353138(arg0);
        if (D_L39_00242B2C == 0) {
            func_L01_00513758(func_00381CC0_005E40A0());
        }
    }
}
/* localdecomp:end func_L39_005E40A0 */
