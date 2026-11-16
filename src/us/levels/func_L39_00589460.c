#include "common.h"

/* localdecomp:start func_L39_00589460 */
__asm__(".extern D_L39_0024BAC8_b, 4");
__asm__(".extern D_L39_0024CBD0_b, 4");
extern s32 D_L39_0024BAC8;
extern s32 D_L39_0024BAC8_b;
extern u32 *D_L39_0024CBD0;
extern u32 *D_L39_0024CBD0_b;
extern u8 D_1A3940[];
extern void func_003A3DA0(s32);
extern s32 func_139E08(s32);
extern void func_003A3BB8(void);
extern void func_003A3C00(void);
extern void func_L39_00596BA0(void);
extern void func_0038DB18(s32);
extern void func_0038DB98(void);
extern void func_003A3EF0(s32, unsigned long);
extern void func_L39_005FA660(void);

/* Draws arg0 passes of what is probably a fade-to-black: each pass renders a frame, writes a
 * draw-buffer packet with alpha stepped from (i << 7) / (i + 1), and flips buffers; then runs two
 * more frame set-ups. */
void func_L39_00589460(s32 arg0) {
    s32 i;
    s32 t;

    func_003A3DA0(1);
    i = arg0 - 1;
    func_139E08(0);
    D_L39_0024BAC8_b = D_L39_0024BAC8 + 1;
    func_003A3BB8();

    while (i >= 0) {
        func_L39_00596BA0();
        func_0038DB18(1);
        func_0038DB98();
        func_003A3EF0(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        i--;
        func_003A3EF0(1, (long)(0x80 - t) << 24);

        D_L39_0024CBD0[0] = 0x30000014;
        D_L39_0024CBD0[1] = (u32)D_1A3940;
        D_L39_0024CBD0[2] = 0;
        D_L39_0024CBD0[3] = 0x50000014;
        D_L39_0024CBD0_b = D_L39_0024CBD0 + 4;

        func_003A3DA0(1);
        func_139E08(0);
        D_L39_0024BAC8_b = D_L39_0024BAC8 + 1;
        func_L39_005FA660();
        func_003A3C00();
    }

    func_003A3DA0(1);
    func_139E08(0);
    D_L39_0024BAC8_b = D_L39_0024BAC8 + 1;
    func_003A3BB8();
    func_L39_00596BA0();
    func_0038DB18(1);
}
/* localdecomp:end func_L39_00589460 */
