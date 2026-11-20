#include "common.h"

/* declared by functions of L35_003A5780.c, which this file was cut from */
void func_L35_003A5E20(void *);

/* localdecomp:start func_L35_003A5E20 */
extern u8 D_001A4BE0[];
extern f32 D_L35_001DEAA8;
__asm__(".extern D_L35_001DEAA8, 4");
extern f32 D_L35_001DEAA4;
__asm__(".extern D_L35_001DEAA4, 4");
extern s32 D_L35_001DF440;
__asm__(".extern D_L35_001DF440, 4");
extern u8 D_L35_001D66B0[] __attribute__((section(".sdata")));
extern s32 func_L01_00456500(void *, s32);
extern void func_L30_004CF4B0(s32, s32);
extern void func_L30_0034CC28(void *, void *, void *, s32, s32, f32);
extern void func_L01_00446978(void *, void *);

void func_L35_003A5E20(void *arg0) {
    u8 *a0 = arg0;
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *g;
    u8 buf[0x30];

    if (func_L01_00456500(D_001A4BE0 + 0x80, *(s32 *)(v + 0x40)) != 0) {
        g = D_001A4BE0;
        if (*(f32 *)(g + 0x88) + D_L35_001DEAA8 < *(f32 *)(v + 0x48)) {
            if (*(s32 *)(g + 0x25C4) != 0xA0) {
                *(s32 *)(v + 0x44) = D_L35_001DF440;
            }
            func_L30_004CF4B0(0xA0, 1);
        } else if (*(f32 *)(g + 0x88) + D_L35_001DEAA4 < *(f32 *)(v + 0x48)) {
            func_L30_0034CC28(buf, a0, D_L35_001D66B0, 1, 0, 20.0f);
            func_L01_00446978(*(void **)(g + 0x25C0), buf);
        }
    }
}
/* localdecomp:end func_L35_003A5E20 */
