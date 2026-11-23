#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 D_001D4BC0;
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038D200(f32 *, void *, f32);
extern u128_t D_00222400[];
extern void func_0038D408();
/* --- end of declarations from other files --- */

/* localdecomp:start func_00389858 */
#include "vu0.h"

void func_00389858(f32 *arg0, f32 *arg1, f32 *arg2) {
    extern s8 D_225B20[];
    extern s32 D_001D4BC4;
    f32 sp[4];
    s8 *base = (s8 *)D_00222400;
    f32 den;
    f32 temp_f1;
    f32 temp_f2;

    vec_sub_ba(sp, arg0, base);
    func_0038D200(sp, sp, 1024.0f);
    sp[3] = 1.0f;
    func_0038D408(sp, sp, base - 0x100);
    den = sp[3];
    func_0038D200(sp, sp, *(f32 *)D_225B20 / den);
    temp_f1 = sp[0] + (f32)(D_001D4BC0 >> 1);
    *arg1 = temp_f1;
    *arg1 = temp_f1 / (f32)D_001D4BC0;
    temp_f2 = sp[1] + (f32)(D_001D4BC4 >> 1);
    *arg2 = temp_f2;
    *arg2 = temp_f2 / (f32)D_001D4BC4;
}
/* localdecomp:end func_00389858 */
TEXT_PADDING(2);
