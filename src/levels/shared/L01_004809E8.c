#include "common.h"

/* declared by functions of L01_0047F220.c, which this file was cut from */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_L01_00480B10(s32);

/* localdecomp:start func_L01_004809E8 */
extern void func_L01_00517918(s32);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9E90(s32);
extern u8 *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);
extern void func_L01_00425FE0(s32);
extern void func_L01_003F1E98(s32);
extern s32 D_L01_001D8318;
extern u8 D_001D5475[] __attribute__((section(".sdata")));
extern s32 D_001D4BA0[] __attribute__((section(".sdata")));

void func_L01_004809E8(void) {
    u8 *o;
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    func_003B9E90(func_003B9BD0(0));
    o = func_003B42F8(0);
    (*(void (**)(u8 *))(*(u8 **)(o + 4) + 0xC))(o);
    func_003A2750(1);
    func_003BB468(D_L01_001D8318);
    if (D_001D4BA0[0] != D_001D5475[0]) {
        func_L01_00425FE0(D_001D5475[0]);
    }
    func_003A2750(1);
    func_L01_003F1E98(0);
}
/* localdecomp:end func_L01_004809E8 */

/* localdecomp:start func_L01_00480A78 */
extern void func_L01_0047E4B8_00480A78();

void func_L01_00480A78(void) {
    func_L01_0047E4B8_00480A78();
}
/* localdecomp:end func_L01_00480A78 */

/* localdecomp:start func_L01_00480A98 */
extern void func_L01_0047E520_00480A98();

void func_L01_00480A98(void) {
    func_L01_0047E520_00480A98();
}
/* localdecomp:end func_L01_00480A98 */

/* localdecomp:start func_L01_00480AB8 */
extern s32 func_L01_00480AB8(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E06C8;
extern s32 D_L01_001E06B0[2];
extern void func_L01_00480170();
extern void func_L01_004809E8();
extern void func_L01_00480800();
extern void func_L01_00480A78_00480AB8(void);
extern void func_L01_00480A98_00480AB8();
s32 func_L01_00480AB8(void) {
    if (D_L01_001E06C8 == 0) {
        func_003E6FA0(D_L01_001E06B0, (s32)func_L01_00480170, (s32)func_L01_004809E8, (s32)func_L01_00480800, (s32)func_L01_00480A78_00480AB8, (s32)func_L01_00480A98_00480AB8);
        D_L01_001E06C8 = 1;
    }
    return (s32)D_L01_001E06B0;
}
/* localdecomp:end func_L01_00480AB8 */

/* localdecomp:start func_L01_00480B10 */
extern s32 D_L01_001D8368;

void func_L01_00480B10(s32 a) {
    D_L01_001D8368 = a;
}
/* localdecomp:end func_L01_00480B10 */
