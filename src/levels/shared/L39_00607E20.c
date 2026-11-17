#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00607E20);

/* localdecomp:start func_L39_00607FF8 */
typedef struct { u8 pad[0xB0]; s32 handle; } S_00607FF8;
extern void func_L01_004BF948_00607FF8(s32);
extern void func_L01_004CE7E8_00607FF8(s32);
extern void func_001260B0(s32);
extern void func_00126070(s32);
extern s32 func_00126DD0(s32);
extern void func_00125F90(s32, s32);
extern void func_0013A9D8(s32 *);
extern void func_L39_0060A638(s32);
extern void func_L39_00608158(s32);
extern void func_L39_00609468(s32);
extern s32 D_L39_0024CBF4;
extern s32 D_L39_0024CBE0;
extern s32 D_L39_0024CC20;
extern S_00607FF8 *D_L39_0024CC0C;
extern s32 D_L39_0024CC10;
extern s32 D_L39_0024CC08;
extern s32 D_00194E50[];
void func_L39_00607FF8(void) {
    func_L01_004BF948_00607FF8(D_L39_0024CBF4);
    func_L01_004CE7E8_00607FF8(D_L39_0024CBE0);
    func_001260B0(D_L39_0024CC20);
    func_00126070(D_L39_0024CC20);
    func_00126DD0(2);
    func_00125F90(2, D_L39_0024CC0C->handle);
    func_0013A9D8(D_00194E50);
    func_L39_0060A638((s32)D_L39_0024CC0C);
    func_L39_00608158(D_L39_0024CC10);
    func_L39_00609468(D_L39_0024CC08);
    *(volatile u32 *)0x1000E000 &= ~2; /* D_CTRL */
}
/* localdecomp:end func_L39_00607FF8 */
