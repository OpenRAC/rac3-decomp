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

typedef struct { s32 f0; s32 f4; u8 p8[0x18]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; u8 p3C[0x28]; s32 f64; s32 f68; u8 p6C[4]; s32 f70; u8 p74[8]; s32 f7C; u8 p80[0x10]; } S_EB;
extern S_EB D_00331AE0_00393348[];
extern s32 D_001D5B94_00393348;
extern s32 D_001D9E88_00393348;
/* localdecomp:start func_00393348 */
extern void func_00393450();
s32 func_00393348(s32 a, s32 b, void *c, void *d, void *e, s32 f, s32 g) {
    s32 i = a & 0xF;
    s32 m = a & 0xFFF0;
    S_EB *s = &D_00331AE0_00393348[i];
    if (D_001D5B94_00393348 == 5 && i != 2 && i != 0) return 0;
    if (s->f2C != f || s->f28 != g || s->f20 != b || s->f24 != m || s->f30 != (s32)c || s->f34 != (s32)d || s->f38 != (s32)e) {
        s->f2C = f;
        s->f28 = g;
        s->f20 = b;
        s->f30 = (s32)c;
        s->f34 = (s32)d;
        s->f38 = (s32)e;
        s->f64 = D_001D9E88_00393348++;
        s->f68 = 1;
        s->f24 = m;
        s->f7C = 0;
        s->f70 = 0;
        if (m & s->f4 & 0x20) func_00393450(s);
    }
    return s->f64;
}
/* localdecomp:end func_00393348 */
