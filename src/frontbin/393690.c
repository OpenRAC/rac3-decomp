#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 392F68.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_00393538();
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern s32 func_00392F68(s32 key);

typedef struct { u8 p0[0x58]; s32 f58; s32 f5C; u32 f60; u8 p64[0x18]; s32 f7C; } S_38EE58;
extern f32 D_00332230[];
extern f32 D_00332290[];
/* localdecomp:start func_00393690 */
static __inline__ s32 lo0_00393690(s32 v) { return (v < 0) ? 0 : v; }
void func_00393690(S_38EE58 *p, s32 *x, s32 *y, s32 a, s32 b) {
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
    i = lo0_00393690(a);
    if (i > 23) i = 23;

    if (p->f7C) {
        s = D_00332230[i];
    } else {
        s = D_00332290[i];
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
/* localdecomp:end func_00393690 */
