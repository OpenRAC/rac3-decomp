/* PAL near miss (Codex wave 7): near miss: 95 words differ with the file's flags.
 * Worker's note: 92 differences with experimental sq_ra injection (not a matching metadata request); fixed assembler emits literal-pool loads instead of retail inline floats; 8-byte save slots vs retail 16-byte slots. Log build/codex/w375/func_003BDB58.attempt02.log
 */
#include "common.h"
/* localdecomp:start func_003BDB58 */
__asm__(".extern D_001D9D00, 16");
void func_003BDB58(TargetStruct_0037BA20 *p, s32 b, s32 g, s32 r, s32 a, s32 db, s32 dg, s32 dr, s32 period) {
    extern f32 func_0038D490(f32);
    extern s32 func_0038DFB8(f32, s32, s32);
    s32 duration = (period * 5 + 2) / 6;
    f32 v = func_0038D490(-3.1415927410125732f + ((f32)(D_001D9D00 % duration) / (f32)duration) * 2.0f * 3.1415927410125732f);
    r += (s32)(v * dr) + dr / 2;
    g += (s32)(v * dg) + dg / 2;
    b += (s32)(v * db) + db / 2;
    p->field_78 = func_0038DFB8(0.06000000238418579f, p->field_78, (a << 24) | (r << 16) | (g << 8) | b);
}
/* localdecomp:end func_003BDB58 */
