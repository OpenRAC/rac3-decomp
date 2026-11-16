/* NTSC-U draft (Claude wave K): C of func_L01_004CAA98, the NTSC-U twin of func_L01_004CE758, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 34 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_004CAA98", whose code is not the PAL one).
 * Worker's note: 34 diff; retail keeps o,i,0x230 in s3/s1/s2 and re-multiplies after the call, ours CSEs the product
 */
#include "common.h"

/* localdecomp:start func_L01_004CAA98 */
typedef struct E_004CAA98 {
    u8 pad[0x230];
} E_004CAA98;

typedef struct O_004CAA98 {
    u8 pad[0x4610];
    E_004CAA98 e[1];
} O_004CAA98;

extern s32 func_0011BB58(void *, s32, s32);
extern void func_L01_004C9F98(void *, s32, s32, f32, f32);

void func_L01_004CAA98(u8 *o, s32 i, s32 a, s32 b) {
    s32 v;

    func_0011BB58(o + 0x4698 + i * 0x230, a, 0xFE);
    v = 0xB4;
    if (b != -1) {
        v = b;
    }
    func_L01_004C9F98(o + 0x4610 + i * 0x230, 1, v, 255.0f, 135.0f);
}
/* localdecomp:end func_L01_004CAA98 */
