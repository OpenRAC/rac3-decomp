#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 38E518.c's earlier functions */
extern s32 func_0038E5A8(void);

typedef struct { u32 w0; u32 w4; } E_3899B8;
extern E_3899B8 *D_001D55C4_0038E5C8;
/* localdecomp:start func_0038E5C8 */
s32 func_0038E5C8(f32 *w, f32 *h, s32 mode) {
    s32 r;
    *w = 0.0f;
    *h = 0.0f;
    r = 0;
    if (D_001D55C4_0038E5C8 != 0) {
        if (mode != 0) {
            *w = (f32)((D_001D55C4_0038E5C8[0x41].w4 >> 17) & 0x3F);
            *h = (f32)((D_001D55C4_0038E5C8[0x41].w4 >> 9) & 0xFF) * 0.25f;
            r = 1;
        } else {
            s32 n = func_0038E5A8();
            if (n > 0) {
                s32 i;
                u32 mx = 0;
                for (i = 0; i < n; i++) {
                    u32 a = (D_001D55C4_0038E5C8[i].w4 >> 17) & 0x3F;
                    if (mx < a) {
                        mx = a;
                        *h = (f32)((D_001D55C4_0038E5C8[i].w4 >> 9) & 0xFF) * 0.25f;
                    }
                }
                *w = (f32)mx;
                r = 1;
            }
        }
    }
    return r;
}
/* localdecomp:end func_0038E5C8 */
