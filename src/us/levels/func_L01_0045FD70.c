#include "common.h"

typedef int u128_L01_0045FD70 __attribute__((mode(TI)));

/* localdecomp:start func_L01_0045FD70 */
extern u8 *D_L01_0022111C[];
extern u8 *func_L01_0045E438(s32);

/* Allocates one particle slot and fills it at the given position (raised by 0.2) with a color made
 * from code, fixed size and life 0x1B, and stores code in it. */
void func_L01_0045FD70(u8 *position, s32 code) {
    u8 *slot = func_L01_0045E438(1);
    if (slot != 0) {
        u128_L01_0045FD70 copied;
        *(f32 *)(position + 8) += 0.2f;
        copied = *(u128_L01_0045FD70 *)position;
        *(s32 *)(slot + 4) = (code << 24) | 0x00907070;
        *(u128_L01_0045FD70 *)(slot + 0x10) = copied;
        slot[9] = 0x42;
        slot[3] = 0x44;
        slot[1] = 0;
        slot[2] = D_L01_0022111C[0][0];
        *(f32 *)(slot + 0xC) = 63000.004f;
        slot[8] = 0xA0;
        *(s16 *)(slot + 0xA) = 0x1B;
        *(s32 *)(slot + 0x20) = code;
    }
}
/* localdecomp:end func_L01_0045FD70 */
