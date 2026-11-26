#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00393A70 */
/* the copy of func_00393690 */
extern f32 D_00332290_00393A70[] __asm__("D_00332290");
extern f32 D_00332230_00393A70[] __asm__("D_00332230");
typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58_00393A70;
static __inline__ s32 lo0_00393A70(s32 v) { return (v < 0) ? 0 : v; }
void func_00393A70(S_38EE58_00393A70 *p, s32 *x, s32 *y, s32 a, s32 b) {
    s32 dx = 0;
    s32 dy = 0;
    s32 i;
    f32 s;
    f32 *tbl;

    if (p->f7C) {
        a -= b;
    } else {
        a += b;
    }
    i = lo0_00393A70(a);
    if (i > 23) i = 23;

    if (p->f7C) {
        s = D_00332230_00393A70[i];
    } else {
        s = D_00332290_00393A70[i];
    }
    if (p->f60 & 1) {
        dy = -(s32)(s * (p->f5C + 52.0f) + 0.5f);
    } else if (p->f60 & 2) {
        dy = s * (p->f5C + 52.0f) + 0.5f;
    } else if (p->f60 & 4) {
        dx = -(s32)(s * (p->f58 + 20.0f) + 0.5f);
    } else if (p->f60 & 8) {
        dx = s * (p->f58 + 20.0f) + 0.5f;
    }
    *x += dx;
    *y += dy;
}
/* localdecomp:end func_00393A70 */

typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
extern f32 D_00332230[];
extern f32 D_00332290[];
