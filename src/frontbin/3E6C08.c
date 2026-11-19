#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003E6C08();
/* --- end of declarations from other files --- */

void func_0038CB78(void *, s32, s32);
typedef struct { u8 pad0[0x4]; u8 *f4; } S_001DA9B8_003E16B8;
extern S_001DA9B8_003E16B8 D_001DA938[];
extern u8 D_0031B750[];
/* localdecomp:start func_003E6C08 */
void *func_003E6C08() {
    D_001DA938->f4 = D_0031B750;
    func_0038CB78(D_0031B750 + 0x18, 0, 8);
    func_0038CB78(D_001DA938->f4, 0, 0x14);
    func_0038CB78(D_001DA938->f4 + 0x20, 0, 0x30);
    func_0038CB78(D_001DA938->f4 + 0x50, 0, 0x10);
    func_0038CB78(D_001DA938->f4 + 0x64, 0, 0x10);
    (*(s32 *)((u8 *)(D_001DA938->f4) + 0x60)) = 0;
    (*(s32 *)((u8 *)(D_001DA938->f4) + 0x74)) = 0;
    (*(s32 *)((u8 *)(D_001DA938->f4) + 0x14)) = 0;
    return D_001DA938;
}
/* localdecomp:end func_003E6C08 */
