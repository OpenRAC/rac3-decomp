#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0060B948);

INCLUDE_ASM("asm/levels", func_L39_0060BCC0);

/* localdecomp:start func_L39_0060BE00 */
__asm__(".extern D_L39_0024B9C8, 16");
__asm__(".extern D_L39_0024B9C8_b, 4");
__asm__(".extern D_L39_0024BB40, 16");
__asm__(".extern D_L39_00243E90, 16");
__asm__(".extern D_00240288, 16");
extern s32 D_L39_0024B9C8;
extern s32 D_L39_0024B9C8_b;
extern s32 D_L39_0024BB40;
extern s32 D_L39_00243E90;
extern s32 D_00240288;
extern u8 D_001DA120_sda;
extern u8 D_001DA121_sda;
extern u8 D_001DA144_sda;
extern f32 D_001DA140_sda;
extern s32 D_L39_0024BB94;

extern s32 func_001959F8(void);
extern void func_L39_0060B750(void);
extern void func_L39_0060B948(void);
extern void func_00387EF0(void);
extern void func_L01_00461818(void);
extern s32 func_L39_0060B4C8(s32);
extern void func_00387218(void);
extern void func_L39_0060B428(void);
extern void func_L39_005A61D8(void);
extern void func_L39_005A5010(void);
extern void func_003A92F0(s32);
extern s32 func_00139E08(s32);
extern s32 func_L39_005A4058(void);
extern void func_L39_005FCDF8(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_003BE200(void);
extern void func_00392748(s32);
extern void func_L39_00597E70(void);
extern void func_00392350(s32);
extern void func_L39_0058A5D0(s32);
extern void func_L39_0060BCC0(void);

s32 func_L39_0060BE00(void) {
    s32 done;

    func_001959F8();
    if (D_L39_0024BB40 < 0) {
        func_L39_0060B750();
        return 1;
    }
    done = 0;
    func_001959F8();
    func_L39_0060B948();
    func_001959F8();
    D_001DA120_sda = 0;
    D_001DA121_sda = 0;
    while (1) {
        func_L39_005FCDF8();
        func_003A9150();
        func_003923D0();
        if (D_001DA144_sda != 0) {
            func_003BE200();
        } else {
            func_00392748(1);
        }
        func_L39_00597E70();
        func_00392350(0);
        if (done != 0) {
            break;
        }
        func_00387EF0();
        func_L01_00461818();
        func_001959F8();
        done = func_L39_0060B4C8(D_001DA120_sda);
        D_L39_0024BB94 = 0;
        func_00387218();
        func_L39_0060B428();
        func_L39_005A61D8();
        func_L39_005A5010();
        func_003A92F0(1);
        func_00139E08(0);
        D_L39_0024B9C8_b = D_L39_0024B9C8 + 1;
        if (D_L39_00243E90 == 0) {
            D_001DA121_sda = func_L39_005A4058() != 0;
        }
        D_001DA120_sda = D_00240288 >= 2;
    }
    func_003A92F0(1);
    func_00139E08(0);
    if (D_001DA140_sda > 0.0f) {
        func_L39_0058A5D0(2);
    }
    func_L39_0060BCC0();
    return 1;
}
/* localdecomp:end func_L39_0060BE00 */

LINKER_REMNANT("asm/levels", func_L39_0060BF90);
