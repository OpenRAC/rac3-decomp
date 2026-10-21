#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005DE818);

/* localdecomp:start func_L39_005DEBD0 */
extern u8 D_L39_001D8204;
extern s32 D_L39_001D8200;
extern s32 *D_L39_00241120[];
extern void func_003E82F8(s32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005DEBD0(s32 arg0) {
    if (D_L39_001D8204) {
        func_003E82F8((*D_L39_00241120[0] < 2) ? 0 : 4);
        D_L39_001D8200 = arg0;
        func_L01_00516AA0(0x80000, 1, 1);
        func_L01_00516AA0(0x80001, 1, 1);
        func_L01_00516AA0(0x80002, 1, 1);
        func_L01_00516AA0(0x80003, 1, 0);
    }
}
/* localdecomp:end func_L39_005DEBD0 */

/* localdecomp:start func_L39_005DEC68 */
extern u8 D_L39_001D8204;
extern s32 D_L39_001D8200;
extern s32 *D_L39_00241120[];
extern void func_003E82F8(s32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005DEC68(s32 arg0) {
    if (D_L39_001D8204) {
        func_003E82F8((*D_L39_00241120[0] < 2) ? 0 : 4);
        D_L39_001D8200 = arg0;
        func_L01_00516AA0(0x80000, 1, 1);
        func_L01_00516AA0(0x80001, 1, 0);
        func_L01_00516AA0(0x80002, 1, 0);
        func_L01_00516AA0(0x80003, 1, 1);
    }
}
/* localdecomp:end func_L39_005DEC68 */
