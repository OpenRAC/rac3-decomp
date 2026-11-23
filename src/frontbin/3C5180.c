#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3C4B40.c's earlier functions */
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C5110(void *a, f32 *out, s32 f);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFC18;
typedef int Q_3BFC18 __attribute__((mode(TI)));
extern s32 D_001D5BEC_003C5180;
extern s32 D_001D5BF0;
typedef struct { u8 p0[0xB0]; V4_3BFC18 v; } S_3BFC18;
extern S_3BFC18 D_001A4BE0;
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C5110(void *, f32 *, s32);
/* localdecomp:start func_003C5180 */
/* func_003C5180: from boot_elf's twin func_003C5538 (src/boot_elf/text/3C5538.c), callees renamed
   through config/frontend_pairs.tsv. Its types and externs (V4_3BFC18, Q_3BFC18, S_3BFC18,
   D_001D5BEC_003C5180, D_001D5BF0, D_001A4BE0, func_0038CE20, func_003C5110) are already in
   3C4B40.c right above the marker; func_0038CF68 is declared there as (s32, s32, f32). */
void func_003C5180(void *a, f32 *out, s32 flag) {
    if (D_001D5BEC_003C5180 == 0) {
        Q_3BFC18 r;
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(r));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
    } else if (D_001D5BF0 != 0) {
        func_003C5110(a, out, 1);
    } else {
        Q_3BFC18 p, q, r;
        S_3BFC18 *d = &D_001A4BE0;
        f32 s = 1.0f;
        if (d->v.w > 0.0f) {
            s = -1.0f;
        }
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(V4_3BFC18 *)a));
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(d->v));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(q), "j"(p));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
        func_0038CF68((s32)out, (s32)out, s);
    }
    if (flag == 0) {
        func_0038CE20(out, out, -1.0f);
    }
}
/* localdecomp:end func_003C5180 */
