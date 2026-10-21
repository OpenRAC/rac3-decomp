#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CE568(void);
/* --- end of declarations from other files --- */

/* declarations of 3CE2E8.c's earlier functions (tools/port_from_us.py) */
typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001DA5F0_003CE450;
extern s32 D_001DA610[2];
extern void func_0038D728(void *, void *);

/* localdecomp:start func_003CE568 */
extern s32 func_003CE450(s32, s32);
s32 func_003CE798_003CE568(s32);                         /* extern */
extern s32 D_001D9D00;
extern void *D_001DA5F0_003CE568;
extern s32 D_001DA650;

void func_003CE568(void) {
    s32 temp_s1;
    s32 temp_s1_2;
    s32 var_s0;

    var_s0 = 0;
    temp_s1 = D_001D9D00 - D_001DA650;
    temp_s1_2 = (temp_s1 >= 3) ? 2 : temp_s1;
    if ((*(s16 *)((u8 *)(D_001DA5F0_003CE568) + 6)) > 0) {
        do {
            func_003CE450(var_s0, temp_s1_2);
            func_003CE798_003CE568(var_s0);
            var_s0 += 1;
        } while (var_s0 < (*(s16 *)((u8 *)(D_001DA5F0_003CE568) + 6)));
    }
    D_001DA650 = D_001D9D00;
}
/* localdecomp:end func_003CE568 */
