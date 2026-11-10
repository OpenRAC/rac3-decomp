#include "common.h"

INCLUDE_ASM("asm/levels", func_L13_003AF7F0);

INCLUDE_ASM("asm/levels", func_L13_003AF8C0);

/* localdecomp:start func_L13_003AF9E0 */
void func_L13_003AF9E0(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x3D8) = 0;
}
/* localdecomp:end func_L13_003AF9E0 */

/* localdecomp:start func_L13_003AF9F0 */
extern u16 *D_L13_0021C2A0[];
extern u8 *D_L13_001DF59C;
__asm__(".extern D_L13_001DF59C, 16");
extern s32 D_L13_001DF5D8;
extern void func_L01_00445BE0(s32 a, s32 b);

void func_L13_003AF9F0(u8 *object) {
    u16 *p;
    u8 *entity;
    if (object[0x21] == 0xFF) {
        return;
    }
    func_L01_00445BE0(object[0x21], 0);
    p = D_L13_0021C2A0[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L13_001DF5D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L13_0021C2A0[object[0x21]])) {
        entity = D_L13_001DF59C + ((*p & 0x7FFF) << 8);
        if (entity == 0) {
            break;
        }
        if (*(s16 *)(entity + 0xAA) == *(s16 *)(object + 0xAA)) {
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x2F8) = 1;
        } else if (*(s16 *)(entity + 0xAA) == 0x16BD) {
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x2E8) = 1;
        } else if (*(s16 *)(entity + 0xAA) == 0x1B39) {
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x3E4) = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L13_003AF9F0 */
