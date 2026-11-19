#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


extern u8 D_001DA2D4[];
extern u8 D_001DA300[];
extern s32 D_001D9364[];
u8 func_003BDBF8(void);
/* localdecomp:start func_003BEE98 */
s32 func_003BEE98(s32 a) {
    s32 r = 0;
    if ((D_001DA2D4[0] = func_003BDBF8()) != 0 && a) {
        r = D_001DA300[0] != 0;
    }
    D_001D9364[0] = 1;
    return r;
}
/* localdecomp:end func_003BEE98 */
