#include "common.h"

/* NTSC-U counterpart of func_L39_00648840 (src/levels/shared/L39_006487E8.c): no *D_L39_00241120 >= 2 test; the flag byte at 0x1A5995 */
/* localdecomp:start func_L39_00645FE0 */
typedef struct { u8 pad[0xF0]; s32 bits[64]; } S_00645FE0;
extern u8 D_001A5995 __attribute__((section(".data")));
extern s32 D_001D72F4_sda;
extern s32 D_L39_002404F0[] __attribute__((section(".sdata")));
extern S_00645FE0 D_L39_001FC830[];

s32 func_L39_00645FE0(u8 *o, s32 n) {
    if (o[0x1A14] == 0 || D_001A5995 == 0) {
        return 1;
    }
    if (D_001D72F4_sda != 0) {
        return 1;
    }
    return D_L39_001FC830[D_L39_002404F0[o[0x24C9]]].bits[n / 32] & (1 << (n % 32));
}
/* localdecomp:end func_L39_00645FE0 */
