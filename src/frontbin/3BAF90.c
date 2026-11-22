#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BB0B0(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003BB0C0();
extern void func_003BB0C8();
extern s32 func_003BB0C0(void);
extern void func_003BB0C8(void);
/* --- end of declarations from other files --- */

extern s32 func_0038E548(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_001D9698;
extern void func_003BAF90(s32, s32, s32);
/* localdecomp:start func_003BAF90 */
void func_003BAF90(s32 a, s32 pp, s32 qq) {
    f32 *p = (f32 *)pp;
    f32 *q = (f32 *)qq;
    f32 r;
    f32 t;
    f32 k;
    f32 c;
    f32 lo;
    f32 hi;
    if (a != 0) {
        c = 0.49f;
        t = (f32)func_0038E548(1.2f, a, -1) / D_001D9698;
        k = 1.2f;
        lo = 6.0f;
        hi = 11.0f;
        if (c < t) {
            k = 0.588000059f / t;
            t = c;
        }
        r = func_003C4088(lo, hi, (t - 0.0f) / c);
        *q = r;
        if (hi < r) {
            *q = hi;
        } else if (r < lo) {
            *q = lo;
        }
        *p = k;
    }
}
/* localdecomp:end func_003BAF90 */

extern s32 D_001D8BE8[];
/* localdecomp:start func_003BB0B0 */
extern s32 D_001D8BE8_003BB0B0;
void func_003BB0B0(void) {
    *(u8 *)&D_001D8BE8_003BB0B0 = 1;
}
/* localdecomp:end func_003BB0B0 */

/* localdecomp:start func_003BB0C0 */
extern u8 D_001D8BE8_003BB0C0;
s32 func_003BB0C0(void) {
    return D_001D8BE8_003BB0C0;
}
/* localdecomp:end func_003BB0C0 */

/* localdecomp:start func_003BB0C8 */
extern u8 D_001D8BE8_003BB0C8;
void func_003BB0C8(void) {
    D_001D8BE8_003BB0C8 = 0;
}
/* localdecomp:end func_003BB0C8 */

LINKER_REMNANT("asm/remnants", func_003BB0D0);
