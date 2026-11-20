#include "common.h"
#include "vu0.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern void func_0038D028();
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_0038CF68);

ASM_FUNC("asm/handwritten", func_0038CFB8);

/* localdecomp:start func_0038D000 */
void func_0038D000(void) {
    __asm__ __volatile__(
        "lqc2 $vf5, 0($5)\n"
        "lqc2 $vf1, 0($6)\n"
        "lqc2 $vf2, 16($6)\n"
        "lqc2 $vf3, 32($6)\n"
        "vmulax.xyzw ACC, $vf1, $vf5x\n"
        "vmadday.xyzw ACC, $vf2, $vf5y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf5z\n"
        "vmaddw.xyzw $vf6, $vf0, $vf5w\n"
        "sqc2 $vf6, 0($4)\n"
    );
}
/* localdecomp:end func_0038D000 */

/* localdecomp:start func_0038D028 */
void func_0038D028(void) {
    __asm__ __volatile__(
        "lqc2 $vf5, 0($5)\n"
        "lqc2 $vf1, 0($6)\n"
        "lqc2 $vf2, 16($6)\n"
        "lqc2 $vf3, 32($6)\n"
        "lqc2 $vf4, 48($6)\n"
        "nop\n"
        "vmulax.xyzw ACC, $vf1, $vf5x\n"
        "vmadday.xyzw ACC, $vf2, $vf5y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf5z\n"
        "vmaddw.xyzw $vf6, $vf4, $vf5w\n"
        "sqc2 $vf6, 0($4)\n"
    );
}
/* localdecomp:end func_0038D028 */

ASM_FUNC("asm/handwritten", func_0038D058);

/* localdecomp:start func_0038D080 */
void func_0038D080(vu0_v4 *d, vu0_q v) {
    vu0_q f;
    __asm__("qmtc2.ni %1, %0" : "=j"(f) : "r"(psraw_asm(pextlh_asm(v, 0), 16)));
    __asm__("vitof0.xyzw %0, %1" : "=j"(f) : "j"(f));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(f));
}
/* localdecomp:end func_0038D080 */
