#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AD270 */
s32 func_003AD270(void) {
}
/* localdecomp:end func_003AD270 */

void func_003873C0();
void func_003ACC38(void *);
typedef struct { u8 pad0[0xB0]; f32 fB0; } S_00225980_003A7CD0_003A7CD0;
extern S_00225980_003A7CD0_003A7CD0 D_00225900[];
/* localdecomp:start func_003AD278 */
/* from boot_elf's func_003AD630 */
extern s32 func_003AD270();
void func_003AD278(void *arg0) {
    f32 temp_f20;
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_f20 = D_00225900->fB0;
        D_00225900->fB0 = 0.62f;
        func_003873C0();
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_003ACC38(arg0);
            break;
        case 2:
            ((void (*)(void *))func_003AD270)(arg0);
            break;
        }
        D_00225900->fB0 = temp_f20;
        func_003873C0();
    }
}
/* localdecomp:end func_003AD278 */
