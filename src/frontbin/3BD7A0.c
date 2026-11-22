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

/* localdecomp:start func_003BD7A0 */
typedef struct { u8 pad[0x78]; s32 f78; } S_003BD7A0;
extern s32 D_001D9D00;
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
void func_003BD7A0(S_003BD7A0 *p, s32 b, s32 g, s32 r, s32 a, s32 db, s32 dg, s32 dr, s32 period) {
    s32 duration = (period * 5 + 2) / 6;
    f32 v = func_0038D0B0(((f32)(D_001D9D00 % duration) / (f32)duration) * 2.0f * 3.1415927f + -3.1415927f);
    r += (s32)(v * dr) + dr / 2;
    g += (s32)(v * dg) + dg / 2;
    b += (s32)(v * db) + db / 2;
    p->f78 = func_0038DBD8(p->f78, (a << 24) | (r << 16) | (g << 8) | b, 0.06000000238418579f);
}
/* localdecomp:end func_003BD7A0 */
