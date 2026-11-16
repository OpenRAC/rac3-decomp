/* NTSC-U draft (Claude wave K): C of func_L39_005D1690, the NTSC-U twin of func_L39_005D3B70, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L39_005D1690", whose code is not the PAL one).
 * Worker's note: 13 words off with @ps2as added (PAL line lacks it; 16 without); spawner decoded (0x6D, colour via func_003894A0, 210000*2.5); retail hoists lq pos before the byte stores - all 24 orders of the four leading stores give the same 13
 */
#include "common.h"

/* localdecomp:start func_L39_005D1690 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 **D_L39_00296ACC[];

extern u8 *func_003C7B98(s32);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_003894A0(s32, s32, f32);

u8 *func_L39_005D1690(void *pos, void *vel, s32 b, f32 f) {
    u8 *obj;
    u8 *e;

    obj = func_003C7B98(0x6D);
    if (obj != 0) {
        obj[3] = b;
        obj[1] = 0;
        obj[9] = 0x44;
        *(u128_t *)(obj + 0x10) = *(u128_t *)pos;
        e = obj + 0x20;
        obj[8] = func_L39_005B2498(0xFF);
        *(s16 *)(obj + 0xA) = func_L39_005B24C8(5, 0x32);
        *(f32 *)(obj + 0xC) = f * 210000.0f * 2.5f;
        *(u128_t *)(obj + 0x20) = *(u128_t *)vel;
        *(s32 *)(e + 0x10) = func_L39_005B24C8(0x40, 0x80);
        obj[2] = ***D_L39_00296ACC;
        *(s32 *)(obj + 4) = func_003894A0(0x103080, 0, func_L39_005B2510(0.0f, 0.5f)) | (*(s32 *)(e + 0x10) << 24);
    }
    return obj;
}
/* localdecomp:end func_L39_005D1690 */
