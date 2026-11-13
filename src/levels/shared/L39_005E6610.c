#include "common.h"

/* localdecomp:start func_L39_005E6610 */
__asm__(".extern D_001D8470_sda, 4");
extern s32 D_001D8470_sda;
__asm__(".extern D_L39_002429AC, 16");
extern u8 D_L39_002429AC;
extern s32 func_L01_00517688(void);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_005D6A78(s32, s32);
extern s32 func_003B9BD0(s32);
extern void func_L39_005E8598(s32, s32);
extern void func_L39_005E6C78(void);
extern void func_L39_005E6B08(s32, s32);
extern void func_L39_005E7248(void);
extern s32 func_003B97B0(void);
extern s32 func_L01_003BEAA0(void);
extern void func_L39_0059A578(s32, s32);
extern void func_00195008(s32);
extern s32 func_L01_00432F50(void);
extern void func_L01_0041A508(void);
extern void func_L01_00353C80(s32);
extern s32 func_00381CC0(void);
extern void func_L01_00517748(s32);

void func_L39_005E6610(s32 arg0) {
    s32 mode = 0;
    s32 sel;
    u8 *o;
    o = func_L39_0061BF38(func_L01_00517688());
    sel = D_001D8470_sda;
    switch (sel) {
    case 0:
        *(s32 *)(*(u8 **)(o + 0x2534) + 0x1CC) = 2;
        sel = *(s32 *)(*(u8 **)(o + 0x2534) + 0x1C4);
        func_L39_005D6A78(func_L01_00517688(), 10);
        switch (func_L01_00517688()) {
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
        func_L39_005E8598(func_003B9BD0(mode), sel);
        func_L39_005E6C78();
        func_L39_005E6B08(arg0, sel);
        func_L39_005E7248();
        break;
    case 1:
        if (func_003B97B0() == 0) {
            D_001D8470_sda = 0;
            if (func_L01_003BEAA0() == 1) {
                func_L39_0059A578(-1, 1);
                func_00195008(8);
            }
        }
        break;
    }
    if (func_L01_00432F50() != 0) {
        func_L01_0041A508();
        func_L01_00353C80(arg0);
        if (D_L39_002429AC == 0) {
            func_L01_00517748(func_00381CC0());
        }
    }
}
/* localdecomp:end func_L39_005E6610 */
