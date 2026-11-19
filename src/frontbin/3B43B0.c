#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B3750.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);

/* localdecomp:start func_003B43B0 */
typedef struct { u8 b[0x14]; } E_3AEDF8;
extern E_3AEDF8 D_00240AA0[];
extern s32 D_001DA130;
extern void **func_003B4658(void **);
s32 *func_003B43B0(s32 idx) {
    s32 i;
    E_3AEDF8 *p;
    if (D_001DA130 == 0) {
        p = D_00240AA0;
        i = 3;
        do {
            func_003B4658((void **)p);
            i--;
            p++;
        } while (i != -1);
        D_001DA130 = 1;
    }
    return (s32 *)&D_00240AA0[idx];
}
/* localdecomp:end func_003B43B0 */
