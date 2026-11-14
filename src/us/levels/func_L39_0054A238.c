#include "common.h"

/* NTSC-U counterpart of func_L39_0054AB58 (src/levels/shared/L39_0054A250.c) */
/* localdecomp:start func_L39_0054A238 */
typedef struct {
    u8 pad0[0x128];
    s32 w128;
} S_1A5CD0_0054AB58;
typedef struct {
    s32 id;
    s32 t;
} E_0054AB58;

extern S_1A5CD0_0054AB58 D_001A5E50;
extern E_0054AB58 D_L39_0024B148;
__asm__(".extern D_L39_0024B148, 8");
extern s32 D_L39_0024B14C[] __attribute__((section(".sdata")));

void func_L39_0054A238(s32 a) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((&D_L39_0024B148)[i].id == a) {
            if (D_001A5E50.w128 - 2000 < D_L39_0024B14C[i * 2]) {
                (&D_L39_0024B148)[i].id = -1;
                return;
            }
        }
    }
}
/* localdecomp:end func_L39_0054A238 */
