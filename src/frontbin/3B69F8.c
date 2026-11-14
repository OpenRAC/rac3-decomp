#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B69F8 */
extern void func_00392F60(s32);
extern void func_0039E5E0(s32);
extern void func_003BB1F0(s32);
extern s32 func_003BB3A8(s32);
extern s32 D_001D8AA0;
extern s32 D_001D8A9C;
extern s32 D_001D8AAC;
extern s32 D_001D8AB0;
extern s32 D_001D8AA4;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC[];
extern u8 D_001D5BDC_003B69F8[];
void func_003B69F8(void) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_3_2;

    if (D_001D5BDC[0] != 0) {
        func_003BB1F0(0);
    }
    temp_2 = func_003BB3A8(1);
    D_001D8AA0 = temp_2;
    D_001D8A9C = (s32) ((temp_2 + 0xF) & 0xFFFFFFF0);
    if (D_001D5BDC_003B69F8[0] == 0) {
        temp_2_2 = func_003BB3A8(1);
        D_001D8AAC = temp_2_2;
        temp_3 = (temp_2_2 + 0xF) & 0xFFFFFFF0;
        D_001D8AB0 = temp_3;
        func_00392F60(temp_3);
        temp_2_3 = func_003BB3A8(1);
        D_001D8AA4 = temp_2_3;
        temp_3_2 = (temp_2_3 + 0xF) & 0xFFFFFFF0;
        D_001D8AA8 = temp_3_2;
        func_0039E5E0(temp_3_2);
    }
}
/* localdecomp:end func_003B69F8 */

/* localdecomp:start func_003B6A98 */
extern void func_003A5348(s32, s32, s32);
 
void func_003B6A98(void) {
    func_003A5348(5, 0, 0);
}
/* localdecomp:end func_003B6A98 */

typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A18_003B6AC0;
extern F D_001D8A48_003B6AC0[1];
extern T D_001D8A4C[1];
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B6848();
extern void func_003B6910();
extern void func_003B6970();
extern void func_003B69B0();
INCLUDE_ASM("asm/nonmatchings/text", func_003B6AC0);
