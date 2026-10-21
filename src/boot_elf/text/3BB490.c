#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BB490(void);
extern void func_003BB4A0(s32);
extern void func_003BB538(void);
extern s32 func_003BB4D0(u32);
extern s32 func_003BB4B8(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003BB490 */
extern s32 D_0037FA44[];
 
void func_003BB490(void) {
    D_0037FA44[0] = 7;
}
/* localdecomp:end func_003BB490 */

/* localdecomp:start func_003BB4A0 */
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;

extern TargetStruct_0037BA20 D_0037F9D0;

void func_003BB4A0(s32 arg_a0) {
    D_0037F9D0.field_74 = 1;
    D_0037F9D0.field_78 = arg_a0;
}
/* localdecomp:end func_003BB4A0 */

/* localdecomp:start func_003BB4B8 */
extern s32 D_0037FA44[];
s32 func_003BB4B8(s32 a0) {
    return D_0037FA44[0] == a0;
}
/* localdecomp:end func_003BB4B8 */

/* localdecomp:start func_003BB4D0 */
s32 func_003BB4D0(u32 i) {
    if (i < 4) {
        return ((struct { s32 pad[3]; s32 arr[4]; } *)&D_0037F9D0)->arr[i];
    }
    return 0;
}
/* localdecomp:end func_003BB4D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003BB4F8);

/* localdecomp:start func_003BB500 */
extern s8 D_001D8BF0[1];
s32 func_003BB500(s32 i) {
    if (i >= 60) return -1;
    return D_001D8BF0[i];
}
/* localdecomp:end func_003BB500 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003BB528);

/* US draft of func_003BB538 (rac3-uya-decomp func_003BB460, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003BB538 */
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
extern S_3B5CA0 D_0037F9D0_003BB538[];
extern u8 D_2CFFC0[];
extern void func_0038CF58();
void func_003BB538(void) {
    s32 i;
    u8 *p = D_2CFFC0;
    for (i = 0; i < 4; i++) { u8 *q = p + i * 0x800; D_0037F9D0_003BB538[0].buf[i] = q; func_0038CF58(q, 0, 0x800); }
}
/* localdecomp:end func_003BB538 */
