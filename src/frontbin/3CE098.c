#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CE1B0(void);
/* --- end of declarations from other files --- */

typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28;
extern S_3C8B28 *D_001DA5F0_003CE098;
extern s32 D_001DA610[2];
extern void func_0038D348(void *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003CE098);

extern s32 func_003CE098(s32, s32);
s32 func_003CE3E0_003CE1B0(s32);
extern s32 D_001D9D00;
extern void *D_001DA5F0_003CE1B0;
extern s32 D_001DA650;
/* localdecomp:start func_003CE1B0 */
/* declarations of 3CE2E8.c's earlier functions (tools/port_from_us.py) */
typedef struct { u8 pad[0x20]; s16 *arr[1]; } S_3C8B28_003CE1B0;
extern S_3C8B28_003CE1B0 *D_001DA5F0_003CE098_003CE1B0;
extern s32 D_001DA610_003CE1B0[2];
extern void func_0038D728(void *, void *);

extern s32 func_003CE098_003CE1B0(s32, s32);
s32 func_003CE3E0_003CE1B0(s32);                         /* extern */
extern s32 D_001D9D00_003CE1B0;
extern void *D_001DA5F0_003CE1B0_003CE1B0;
extern s32 D_001DA650_003CE1B0;

void func_003CE1B0(void) {
    s32 temp_s1;
    s32 temp_s1_2;
    s32 var_s0;

    var_s0 = 0;
    temp_s1 = D_001D9D00_003CE1B0 - D_001DA650_003CE1B0;
    temp_s1_2 = (temp_s1 >= 3) ? 2 : temp_s1;
    if ((*(s16 *)((u8 *)(D_001DA5F0_003CE1B0_003CE1B0) + 6)) > 0) {
        do {
            func_003CE098_003CE1B0(var_s0, temp_s1_2);
            func_003CE3E0_003CE1B0(var_s0);
            var_s0 += 1;
        } while (var_s0 < (*(s16 *)((u8 *)(D_001DA5F0_003CE1B0_003CE1B0) + 6)));
    }
    D_001DA650_003CE1B0 = D_001D9D00_003CE1B0;
}
/* localdecomp:end func_003CE1B0 */
