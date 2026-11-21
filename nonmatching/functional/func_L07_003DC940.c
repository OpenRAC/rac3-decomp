/* functional: high. PAL near-miss draft re-read against PAL asm (phase +0.1 wrapping at 4.0, 7 segment calls, random width/life ranges incl. the 0x95==1 variant, constants and submit args match); only scheduling and constant loading differ. */
#include "common.h"
typedef int Q_003DC940 __attribute__((mode(TI)));
typedef struct { Q_003DC940 points[8]; u8 pad80[0xA0]; f32 phase; } Vars_003DC940;
void func_L07_003DC940(u8 *obj) {
    extern void func_L07_003DCFF8(void *, void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_L07_003DCB60(void *, s32, s32, s32, s32, s32, f32, f32);
    Q_003DC940 a, b;
    Vars_003DC940 *vars;
    Q_003DC940 *p;
    s32 i;
    f32 width, life, phase;
    if (obj == 0 || obj[0x20] == 254 || obj[0x20] == 253) return;
    vars = *(Vars_003DC940 **)(obj + 0x68);
    phase = vars->phase + 0.1f;
    vars->phase = phase;
    if (phase >= 4.0f) vars->phase = phase - 4.0f;
    p = &vars->points[1];
    for (i = 6; i >= 0; i--) {
        a = p[-1];
        b = p[0];
        p++;
        func_L07_003DCFF8(obj, &a, &b);
    }
    width = func_003824E0(0.03f, 0.05f);
    life = func_003824E0(3.0f, 5.0f);
    if (obj[0x95] == 1) {
        width = func_003824E0(0.05f, 0.07f);
        life = func_003824E0(3.0f, 5.0f);
    }
    func_L07_003DCB60(vars, 7, 79, 0x7F7F7F, 0xFF2020, 0, width, life);
}
