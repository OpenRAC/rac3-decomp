#include "common.h"

INCLUDE_ASM("asm/levels", func_L08_00407380);

/* localdecomp:start func_L08_00407680 */
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u32 D_L08_001E60B0[];
__asm__(".extern D_L08_001E60B0, 16");
void *func_L08_00406A30(s32);

void func_L08_00407680(void) {
    u8 *p;

    if (D_001D545C == 8) {
        if (D_L08_001E60B0[0] < 2) {
            p = func_L08_00406A30(0x1ADF);
            if (p != 0) {
                p[0x31] = 0;
                *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) | 1;
            }
        }
    }
}
/* localdecomp:end func_L08_00407680 */

/* localdecomp:start func_L08_004076E0 */
__asm__(".extern D_001D545C, 16");
extern u32 D_L08_001E60B0[];
__asm__(".extern D_L08_001E60B0, 16");
void *func_L08_00406A30(s32);

void func_L08_004076E0(void) {
    void *temp_v0;

    if (D_001D545C == 8) {
        if (D_L08_001E60B0[0] <= 1) {
            temp_v0 = func_L08_00406A30(0x1ADF);
            if (temp_v0 != 0) {
                *(u8 *)((u8 *)temp_v0 + 0x31) = 1;
                *(u16 *)((u8 *)temp_v0 + 0x34) &= 0xFFFE;
            }
        }
    }
}
/* localdecomp:end func_L08_004076E0 */
