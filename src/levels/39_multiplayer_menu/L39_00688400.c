#include "common.h"

/* localdecomp:start func_L39_00688400 */
typedef struct {
    u8 pad0[0x60];
    u8 *unk60;
    u8 pad64[0x10C - 0x64];
    s32 unk10C;
    s32 unk110[0x60];
    s32 unk290;
} S_00688400;
extern void func_L39_0067EEC8(u8 *, s32);
extern u8 D_L39_0047C2F8[];
void func_L39_00688400(S_00688400 *p, s32 flags) {
    s32 i;
    p->unk10C = 0;
    p->unk60 = D_L39_0047C2F8;
    for (i = 0x5F; i >= 0; i--) {
        p->unk110[i] = 0;
    }
    p->unk290 = -1;
    func_L39_0067EEC8((u8 *)p, flags);
}
/* localdecomp:end func_L39_00688400 */

INCLUDE_ASM("asm/levels", func_L39_00688460);

INCLUDE_ASM("asm/levels", func_L39_006888B8);
