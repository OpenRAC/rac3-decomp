#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3BE068.c's earlier functions */
extern s32 D_001D8CFC;
extern s32 D_001D8CF8;
extern void func_003BE0C0(void);

typedef struct { u8 pad[0x64]; s32 f64; } S_16C580_3B8840;
extern S_16C580_3B8840 D_16C580_003BE0F0;
extern u8 D_001DA290_003BE0F0[1];
extern s32 D_001DA268_003BE0F0[2];
extern s32 func_00382848(s32);
/* localdecomp:start func_003BE0F0 */
/* from frontbin's func_003BDD38 (its twin) */
__asm__(".extern D_001D8CF8, 4");
__asm__(".extern D_001D8CFC, 4");
s32 func_003BE0F0(void) {
    s32 i;
    s32 r;
    s32 cur;
    u8 *used;
    used = D_001DA290_003BE0F0;
    for (i = 0; i < D_001D8CF8; i++) {
        if (i != D_001D8CFC && *(u8 *)(i + (s32)used) == 0) break;
    }
    if (i == D_001D8CF8) func_003BE0C0();
    cur = D_16C580_003BE0F0.f64;
    do {
        r = func_00382848(D_001D8CF8);
    } while (r == cur || *(u8 *)(r + (s32)used) != 0);
    *(u8 *)(r + (s32)used) = 1;
    return D_001DA268_003BE0F0[r];
}
/* localdecomp:end func_003BE0F0 */
