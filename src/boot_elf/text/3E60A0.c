#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3E5C60.c's earlier functions */
extern s32 func_003E6730();
extern s32 func_003E74D0();

extern s32 D_001D96D0[];
extern s32 func_003E74D0();
extern void func_003E74C0();
/* localdecomp:start func_003E60A0 */
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_003E60A0;
typedef struct { u8 pad[8]; VT_003E60A0 *vt; } O_003E60A0;
s32 func_003E60A0(s32 *a0, u32 a1, s32 a2) {
    s32 *p;
    O_003E60A0 *obj;
    O_003E60A0 *s1;
    if (a1 < 0x23) {
        if (*(s32 *)(a1 * 4 + *a0 + 0x50) == 0) {
            obj = (O_003E60A0 *)func_003E6730(a0, a2);
            if (obj != 0 && obj->vt->isA(obj, D_001D96D0[0]) != 0) s1 = obj; else s1 = 0;
            if (s1 != 0) {
                p = (s32 *)(a1 * 4 + *a0); p += 0x14;
                if (*p != 0) func_003E74D0(*p);
                *p = (s32)s1;
                func_003E74C0(s1);
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_003E60A0 */
