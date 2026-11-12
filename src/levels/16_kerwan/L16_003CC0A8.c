#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L16_003CC0A8);

/* localdecomp:start func_L16_003CC150 */
extern void func_0038D000(float *, float *, float *);

void func_L16_003CC150(void *arg0, void *arg1) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_0038D000(arg1, (float *)((u8 *)temp_s0 + 0x230),
                  (float *)((u8 *)*(void **)((u8 *)temp_s0 + 0x22C) + 0xC0));
    vec_add_ab(arg1, arg1, (u8 *)*(void **)((u8 *)temp_s0 + 0x22C) + 0x10);
}
/* localdecomp:end func_L16_003CC150 */

INCLUDE_ASM("asm/levels", func_L16_003CC1A8);
