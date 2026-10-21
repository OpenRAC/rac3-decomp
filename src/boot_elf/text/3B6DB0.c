#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B6DB0 */
extern void func_00393340(s32);
extern void func_0039E9C0(s32);
extern void func_003BB5A8(s32);
extern s32 func_003BB760(s32);
extern s32 D_001D8AA0;
extern s32 D_001D8A9C;
extern s32 D_001D8AAC;
extern s32 D_001D8AB0;
extern s32 D_001D8AA4;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC[];
extern u8 D_001D5BDC_003B6DB0[];
void func_003B6DB0(void) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_3;
    s32 temp_3_2;

    if (D_001D5BDC[0] != 0) {
        func_003BB5A8(0);
    }
    temp_2 = func_003BB760(1);
    D_001D8AA0 = temp_2;
    D_001D8A9C = (s32) ((temp_2 + 0xF) & 0xFFFFFFF0);
    if (D_001D5BDC_003B6DB0[0] == 0) {
        temp_2_2 = func_003BB760(1);
        D_001D8AAC = temp_2_2;
        temp_3 = (temp_2_2 + 0xF) & 0xFFFFFFF0;
        D_001D8AB0 = temp_3;
        func_00393340(temp_3);
        temp_2_3 = func_003BB760(1);
        D_001D8AA4 = temp_2_3;
        temp_3_2 = (temp_2_3 + 0xF) & 0xFFFFFFF0;
        D_001D8AA8 = temp_3_2;
        func_0039E9C0(temp_3_2);
    }
}
/* localdecomp:end func_003B6DB0 */

/* localdecomp:start func_003B6E50 */
extern void func_003A5748(s32, s32, s32);
 
void func_003B6E50(void) {
    func_003A5748(5, 0, 0);
}
/* localdecomp:end func_003B6E50 */
