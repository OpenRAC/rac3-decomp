#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003AFD88(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AFD88 */
// Declare the external game function target matching address 0x0011ECD0
extern void func_0011ECD0(s32 parameter);

// Signature must be void to eliminate the implicit return zero instruction (0x102d)
void func_003AFD88(void) {
    // Calling this function with 1 triggers the 'li $a0, 1' optimization pass, 
    // which naturally slides directly into the jal branch delay slot at offset c:
    func_0011ECD0(1);
}
/* localdecomp:end func_003AFD88 */

/* localdecomp:start func_003AFDA8 */
extern s32 func_003B03A8();
extern s32 D_001DA0B8[];

void func_003AFDA8(void) {
    func_003B03A8(D_001DA0B8[0]);
}
/* localdecomp:end func_003AFDA8 */
