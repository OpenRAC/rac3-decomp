#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BB0D8(void);
extern void func_003BB0E8(s32);
extern void func_003BB180(void);
extern s32 func_003BB118(u32);
extern s32 func_003BB100(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003BB0D8 */
extern s32 D_0037FA44[];
 
void func_003BB0D8(void) {
    D_0037FA44[0] = 7;
}
/* localdecomp:end func_003BB0D8 */

/* localdecomp:start func_003BB0E8 */
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;

extern TargetStruct_0037BA20 D_0037F9D0;

void func_003BB0E8(s32 arg_a0) {
    D_0037F9D0.field_74 = 1;
    D_0037F9D0.field_78 = arg_a0;
}
/* localdecomp:end func_003BB0E8 */

/* localdecomp:start func_003BB100 */
extern s32 D_0037FA44[];
s32 func_003BB100(s32 a0) {
    return D_0037FA44[0] == a0;
}
/* localdecomp:end func_003BB100 */

/* localdecomp:start func_003BB118 */
s32 func_003BB118(u32 i) {
    if (i < 4) {
        return ((struct { s32 pad[3]; s32 arr[4]; } *)&D_0037F9D0)->arr[i];
    }
    return 0;
}
/* localdecomp:end func_003BB118 */

LINKER_REMNANT("asm/remnants", func_003BB140);

/* localdecomp:start func_003BB148 */
extern s8 D_001D8BF0[1];
s32 func_003BB148(s32 i) {
    if (i >= 60) return -1;
    return D_001D8BF0[i];
}
/* localdecomp:end func_003BB148 */

LINKER_REMNANT("asm/remnants", func_003BB170);

/* localdecomp:start func_003BB180 */
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
extern S_3B5CA0 D_0037F9D0_003BB180[];
extern u8 D_002CFFC0[];
extern void func_0038CB78();
void func_003BB180(void) {
    s32 i;
    u8 *p = D_002CFFC0;
    for (i = 0; i < 4; i++) { u8 *q = p + i * 0x800; D_0037F9D0_003BB180[0].buf[i] = q; func_0038CB78(q, 0, 0x800); }
}
/* localdecomp:end func_003BB180 */
