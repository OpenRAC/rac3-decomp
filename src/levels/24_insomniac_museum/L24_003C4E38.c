#include "common.h"

typedef struct {
    u8 b[0x1C];
} S_003C5138;

INCLUDE_ASM("asm/levels", func_L24_003C4E38);

/* localdecomp:start func_L24_003C5138 */
extern u8 D_L24_001DEA30[];
extern s32 func_00381FF0(s32);
extern void func_003AF408(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L24_003C5138(void) {
    S_003C5138 buf;
    s32 v;

    buf = *(S_003C5138 *)D_L24_001DEA30;
    v = func_00381FF0(0x850);
    func_003AF408(&buf, 0x80F0F0F0, v, 1, 0, -1, 0, 0, 0, 0);
}
/* localdecomp:end func_L24_003C5138 */
