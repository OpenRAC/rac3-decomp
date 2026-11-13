#include "common.h"

/* NTSC-U counterpart of func_L39_0060BE00 (src/levels/shared/L39_0060B948.c) */
/* localdecomp:start func_L39_00609700 */
__asm__(".extern D_L39_0024BAC8, 16");
__asm__(".extern D_L39_0024BAC8_b, 4");
__asm__(".extern D_L39_0024BC40, 16");
__asm__(".extern D_L39_00244000, 16");
__asm__(".extern D_L39_00240408_00609700, 16");
extern s32 D_L39_0024BAC8;
extern s32 D_L39_0024BAC8_b;
extern s32 D_L39_0024BC40;
extern s32 D_L39_00244000;
extern s32 D_L39_00240408_00609700;
extern u8 D_001DA120_sda_00609700;
extern u8 D_001DA121_sda_00609700;
extern u8 D_001DA144_sda_00609700;
extern f32 D_001DA140_sda_00609700;
extern s32 D_L39_0024BC94;

extern s32 func_00195AE8(void);
extern void func_L39_00609050(void);
extern void func_L39_00609248(void);
extern void func_00383848(void);
extern void func_L01_0045E370(void);
extern s32 func_L39_00608DC8(s32);
extern void func_00382F40(void);
extern void func_L39_00608D28(void);
extern void func_L39_005A43D8(void);
extern void func_L39_005A33A0(void);
extern void func_003A3DA0(s32);
extern s32 func_00139E08(s32);
extern s32 func_L39_005A23F0(void);
extern void func_L39_005FA660(void);
extern void func_003A3C00(void);
extern void func_0038DB98(void);
extern void func_003B8D08(void);
extern void func_0038DF10(s32);
extern void func_L39_00596BA0(void);
extern void func_0038DB18(s32);
extern void func_L39_00589460(s32);
extern void func_L39_006095C0(void);

s32 func_L39_00609700(void) {
    s32 done;

    func_00195AE8();
    if (D_L39_0024BC40 < 0) {
        func_L39_00609050();
        return 1;
    }
    done = 0;
    func_00195AE8();
    func_L39_00609248();
    func_00195AE8();
    D_001DA120_sda_00609700 = 0;
    D_001DA121_sda_00609700 = 0;
    while (1) {
        func_L39_005FA660();
        func_003A3C00();
        func_0038DB98();
        if (D_001DA144_sda_00609700 != 0) {
            func_003B8D08();
        } else {
            func_0038DF10(1);
        }
        func_L39_00596BA0();
        func_0038DB18(0);
        if (done != 0) {
            break;
        }
        func_00383848();
        func_L01_0045E370();
        func_00195AE8();
        done = func_L39_00608DC8(D_001DA120_sda_00609700);
        D_L39_0024BC94 = 0;
        func_00382F40();
        func_L39_00608D28();
        func_L39_005A43D8();
        func_L39_005A33A0();
        func_003A3DA0(1);
        func_00139E08(0);
        D_L39_0024BAC8_b = D_L39_0024BAC8 + 1;
        if (D_L39_00244000 == 0) {
            D_001DA121_sda_00609700 = func_L39_005A23F0() != 0;
        }
        D_001DA120_sda_00609700 = D_L39_00240408_00609700 >= 2;
    }
    func_003A3DA0(1);
    func_00139E08(0);
    if (D_001DA140_sda_00609700 > 0.0f) {
        func_L39_00589460(2);
    }
    func_L39_006095C0();
    return 1;
}
/* localdecomp:end func_L39_00609700 */
