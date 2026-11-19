#include "common.h"


/* localdecomp:start func_L39_006058F8 */
typedef struct { u8 pad[0xB0]; s32 handle; } S_00607FF8;
extern void func_L01_004BF948_00607FF8(s32);
extern void func_L01_004CE7E8_00607FF8(s32);
extern void func_001260B0(s32);
extern void func_00126070(s32);
extern s32 func_00126DD0(s32);
extern void func_00125F90(s32, s32);
extern void func_0013A9D8(s32 *);
extern void func_L39_00607F38(s32);
extern void func_L39_00605A58(s32);
extern void func_L39_00606D68(s32);
extern s32 D_L39_0024CCF4;
extern s32 D_L39_0024CCE0;
extern s32 D_L39_0024CD20;
extern S_00607FF8 *D_L39_0024CD0C;
extern s32 D_L39_0024CD10;
extern s32 D_L39_0024CD08;
extern s32 D_00194F40[];
void func_L39_006058F8(void) {
    func_L01_004BF948_00607FF8(D_L39_0024CCF4);
    func_L01_004CE7E8_00607FF8(D_L39_0024CCE0);
    func_001260B0(D_L39_0024CD20);
    func_00126070(D_L39_0024CD20);
    func_00126DD0(2);
    func_00125F90(2, D_L39_0024CD0C->handle);
    func_0013A9D8(D_00194F40);
    func_L39_00607F38((s32)D_L39_0024CD0C);
    func_L39_00605A58(D_L39_0024CD10);
    func_L39_00606D68(D_L39_0024CD08);
    *(volatile u32 *)0x1000E000 &= ~2; /* D_CTRL */
}
/* localdecomp:end func_L39_006058F8 */
