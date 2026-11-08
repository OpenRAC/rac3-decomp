#include "common.h"

INCLUDE_ASM("asm/levels", func_L10_003587D8);

INCLUDE_ASM("asm/levels", func_L10_00358F48);

/* localdecomp:start func_L10_003591B0 */
void func_L10_003591B0(void *arg0) {
    void *temp_a1;

    temp_a1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(f32 *)((u8 *)temp_a1 + 4) = (f32) ((*(f32 *)((u8 *)arg0 + 0x18)) + 5.0f);
        if ((*(s32 *)temp_a1) == 2) {
            *(u8 *)((u8 *)arg0 + 0x20) = 5U;
            return;
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
}
/* localdecomp:end func_L10_003591B0 */

/* localdecomp:start func_L10_003591F8 */
extern int func_L01_00445AD0(int, int, int);
int func_L10_003591F8(char *a) {
    int *p = *(int **)(a + 0x68);
    int x = p[4];
    if (x != -1) return func_L01_00445AD0(x, -1, 0) == 0;
    return 0;
}
/* localdecomp:end func_L10_003591F8 */

INCLUDE_ASM("asm/levels", func_L10_00359238);

/* localdecomp:start func_L10_00359368 */
void func_L01_004450F0(s32, s32, s32);
void func_L10_00359368(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L10_00359368 */
