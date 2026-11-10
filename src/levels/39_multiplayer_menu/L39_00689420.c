#include "common.h"

/* localdecomp:start func_L39_00689420 */
extern s32 D_L39_003D2880[];
extern s32 D_001DC354_sda;
__asm__(".extern D_001DC354_sda, 4");
extern void func_L01_00516AA0();
extern void func_L01_00516470(int);
extern s32 func_L01_005168F0(s32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
void func_L39_00689420(void) {
    s32 i;
    s32 *p;
    if (D_L39_003D2880[0x260 / 4] > 0) {
        p = &D_L39_003D2880[0x260 / 4];
        for (i = 4; i >= 0; i--) {
            func_L01_00516AA0(*p, 1, 1);
            ((void (*)(s32, f32, f32))func_L01_00516470)(*p, 0.5f, 0.5f);
            func_L01_00517538(*p, 0.12f, 0.1475f);
            p++;
        }
        func_L01_005168F0(D_L39_003D2880[0x274 / 4],
                          (D_001DC354_sda++ % 60) * -6.2831855f / 60.0f + 3.1415927f);
        func_L01_00516AA0(D_L39_003D2880[0x274 / 4], 1, 1);
        ((void (*)(s32, f32, f32))func_L01_00516470)(D_L39_003D2880[0x274 / 4], 0.5f, 0.5f);
        func_L01_00517538(D_L39_003D2880[0x274 / 4], 0.1f, 0.125f);
        func_L01_005170B8(D_L39_003D2880[0x274 / 4], 0x80808080);
    }
}
/* localdecomp:end func_L39_00689420 */

/* localdecomp:start func_L39_00689570 */
extern s32 D_L39_003D2880[];
extern s32 D_001DC354_sda;
__asm__(".extern D_001DC354_sda, 4");
extern s32 func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_005168F0(s32, f32);
void func_L39_00689570(void) {
    u8 flag;
    if (D_L39_003D2880[0x260 / 4] > 0) {
        flag = 0;
        func_L01_00516B90(D_L39_003D2880[0x260 / 4], 1, (s32)&flag);
        if (flag) {
            func_L01_005168F0(D_L39_003D2880[0x274 / 4],
                              (D_001DC354_sda++ % 60) * -6.2831855f / 60.0f + 3.1415927f);
        }
    }
}
/* localdecomp:end func_L39_00689570 */
