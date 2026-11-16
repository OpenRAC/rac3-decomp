/* NTSC-U draft (Claude wave K): C of func_L05_0032AF58, the NTSC-U twin of func_L05_0032B880, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L05_0032AF58", whose code is not the PAL one).
 * Worker's note: 31 words off with @ps2as; spawner decoded fully (0x184D, colour at +0xB8, 3 random angles +0xF0/F4/F8); retail hoists -pi/+pi into f21/f20 and f arg into f22 (ours f20), store order of the p block differs (sched1)
 */
#include "common.h"

/* localdecomp:start func_L05_0032AF58 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003C26C8(void *);

u8 *func_L05_0032AF58(void *pos, void *vel, s32 col, f32 f) {
    u8 *obj;
    u8 *p;

    obj = func_003BCFB0(0x184D, 0x80);
    if (obj != 0) {
        obj[0x31] = 1;
        obj[0x30] = 0xFF;
        *(s16 *)(obj + 0x32) = 0x1FF;
        obj[0x23] = 0x60;
        p = *(u8 **)(obj + 0x68);
        obj[0x20] = 0;
        if (col != 0) {
            *(s32 *)(obj + 0xB8) = col;
        }
        *(u128_t *)(obj + 0x10) = *(u128_t *)pos;
        *(s32 *)(p + 0x10) = 30;
        *(f32 *)(p + 0x20) = f;
        *(u128_t *)p = *(u128_t *)vel;
        *(s32 *)(p + 0x18) = 300;
        *(s32 *)(p + 0x14) = 0;
        *(f32 *)(obj + 0xF0) = func_0037E250(-3.1415927f, 3.1415927f);
        *(f32 *)(obj + 0xF4) = func_0037E250(-3.1415927f, 3.1415927f);
        *(s32 *)(obj + 0xFC) = 0;
        *(f32 *)(obj + 0xF8) = func_0037E250(-3.1415927f, 3.1415927f);
        func_003C26C8(obj);
    }
    return obj;
}
/* localdecomp:end func_L05_0032AF58 */
