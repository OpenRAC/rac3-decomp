#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0061BED0);

/* localdecomp:start func_L39_0061BF38 */
typedef struct {
    u8 pad0[0x4500];
} D_002FB100_t;
extern D_002FB100_t D_L39_002FB000[];

D_002FB100_t *func_L39_0061BF38(s32 i) {
    return &D_L39_002FB000[i];
}
/* localdecomp:end func_L39_0061BF38 */

INCLUDE_ASM("asm/levels", func_L39_0061BF50);

INCLUDE_ASM("asm/levels", func_L39_0061BF68);

INCLUDE_ASM("asm/levels", func_L39_0061BFB0);

INCLUDE_ASM("asm/levels", func_L39_0061BFF8);

/* localdecomp:start func_L39_0061C0E0 */
extern D_002FB100_t *func_L39_0061BF38(s32 i);
extern void func_L01_0041A6E0(void);

void func_L39_0061C0E0(int a0, int a1) {
    ((char * (*)())func_L39_0061BF38)(a0)[9496] = a1;
    if (a1) {
        func_L01_0041A6E0();
    }
}
/* localdecomp:end func_L39_0061C0E0 */

INCLUDE_ASM("asm/levels", func_L39_0061C118);

INCLUDE_ASM("asm/levels", func_L39_0061C1B0);

INCLUDE_ASM("asm/levels", func_L39_0061C1E0);

INCLUDE_ASM("asm/levels", func_L39_0061C258);

INCLUDE_ASM("asm/levels", func_L39_0061C2A8);

INCLUDE_ASM("asm/levels", func_L39_0061C2D0);

INCLUDE_ASM("asm/levels", func_L39_0061C400);
