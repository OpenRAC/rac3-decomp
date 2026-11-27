#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B5C10();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B5C10 */
/* the copy of func_L01_00491AF0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 type;
    s32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    s32 f20;
    s32 f24;
    f32 f28;
    s32 f2C;
} E_003B5C10;
extern s32 func_003E9808_a003B5C10(s32) __asm__("func_003E9808");
extern void func_003E9110_a003B5C10(s32, s32, s32) __asm__("func_003E9110");
extern void func_003E7770_a003B5C10(s32, f32, f32) __asm__("func_003E7770");
extern void func_003E85A8_a003B5C10(s32, f32, f32) __asm__("func_003E85A8");
extern void func_003E92A8_a003B5C10(s32, s32, s32, f32, f32, f32, f32, f32) __asm__("func_003E92A8");
extern void func_003E94F0_a003B5C10(s32, s32, f32, f32, f32, f32, s32) __asm__("func_003E94F0");
extern void func_003E9628_a003B5C10(s32, s32, f32, f32, f32, f32, f32, f32) __asm__("func_003E9628");
extern void func_003E9470_a003B5C10(s32, s32, s32, f32, f32, f32, f32, f32, f32) __asm__("func_003E9470");
extern void func_003E9710_a003B5C10(s32, s32, s32, f32, f32, f32, f32, f32) __asm__("func_003E9710");
extern void func_003E7A38_a003B5C10(s32, f32) __asm__("func_003E7A38");
extern void func_003E7948_a003B5C10(s32, f32, f32) __asm__("func_003E7948");
extern s32 func_003E7BF0(s32, s32, s32);
extern void func_003E91F0_a003B5C10(s32, s32, s32) __asm__("func_003E91F0");
extern void func_003E7CE0_a003B5C10(s32, s32, s32) __asm__("func_003E7CE0");
extern void func_003E89E8_a003B5C10(s32, s32) __asm__("func_003E89E8");
extern s32 func_003823D0_003B5C10(s32);

void func_003B5C10(E_003B5C10 *tbl) {
    s32 a = 3;
    s32 b = 3;
    s32 i = 0;
    E_003B5C10 *e;

    while (tbl[i].f0 != 0) {
        e = &tbl[i];
        switch (e->type) {
        case 0:
            func_003E9808_a003B5C10(e->f0);
            if (e->f2C & 1) {
                func_003E9110_a003B5C10(e->f0, 1, 1);
                func_003E7770_a003B5C10(e->f0, e->f10, e->f14);
                func_003E85A8_a003B5C10(e->f0, e->f18, e->f1C);
            }
            break;
        case 1:
            func_003E92A8_a003B5C10(e->f0, e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.0f);
            break;
        case 2:
            func_003E94F0_a003B5C10(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f24);
            break;
        case 3:
            func_003E9628_a003B5C10(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f28, e->f28);
            break;
        case 4:
            func_003E9470_a003B5C10(e->f0, (e->f2C & 4) ? func_003823D0_003B5C10(e->f24) : e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.005f, 0.005f);
            break;
        case 5:
            func_003E9710_a003B5C10(e->f0, (e->f2C & 4) ? func_003823D0_003B5C10(e->f24) : e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 1.0f);
            func_003E7A38_a003B5C10(e->f0, e->f28);
            func_003E7948_a003B5C10(e->f0, e->f28 * 0.005f, e->f28 * 0.005f);
            func_003E7BF0(e->f0, 0x40, 1);
            if (e->f2C & 8) func_003E91F0_a003B5C10(e->f0, 1, 1);
            break;
        }
        if (e->f20 != 0) {
            if (e->f20 & 1) a = 1;
            else if (e->f20 & 2) a = 2;
            if (e->f20 & 8) b = 1;
            else if (e->f20 & 0x10) b = 2;
            func_003E7CE0_a003B5C10(e->f0, a, b);
        }
        if (e->f2C & 2) func_003E7BF0(e->f0, 1, 0);
        if (e->f4 != 0) func_003E89E8_a003B5C10(e->f4, e->f0);
        i++;
    }
}
/* localdecomp:end func_003B5C10 */

typedef struct {
    s32 f0; s32 f4; s32 f8; s32 fC; f32 f10; f32 f14; f32 f18; f32 f1C;
    u32 f20; s32 f24; f32 f28; u32 f2C;
} E_3B02A0;
extern void func_003E9808();
extern s32 func_003E9110(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E92A8(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E94F0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9628(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9470(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9710(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E7A38(s32, f32);
extern s32 func_003E7948(s32, f32, f32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E91F0(s32, s32, s32);
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E89E8(s32, s32);
