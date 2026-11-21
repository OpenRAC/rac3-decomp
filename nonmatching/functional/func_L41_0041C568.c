/* functional: high. Callee func_L41_0041C2E8 is declared with the 64.0f it receives in $f12 (the matched C drops it: register passthrough); 134 instructions differ (frame size, scheduling). */
#include "common.h"
/* localdecomp:start func_L41_0041C568 */
#include "vu0.h"
extern s32 D_002412DC;
extern u8 *D_L41_0024865C;
extern vu0_v4 D_L41_00242930;
extern s32 D_L41_002477BC __attribute__((section(".sdata")));
extern f32 D_L41_002477C4[7] __attribute__((section(".sdata")));
extern f32 D_L41_002477DC __attribute__((section(".sdata")));
extern s32 func_L41_0041C2E8(void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L41_0041B350(void *, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L41_0041C430(void *);
extern void func_L41_0041B858(void *);

void func_L41_0041C568(u8 *obj) {
    u8 *vars = *(u8 **)(obj + 0x68);
    if (func_L41_0041C2E8(obj + 0x10, 64.0f) != 0) {
        f32 z;
        f32 rangeA;
        f32 rangeB;
        s32 i;
        s32 id;
        u8 *other;
        if (D_002412DC == 0x2D) {
            z = 1.9f;
            rangeA = 3.0f;
            rangeB = 7.5f;
        } else {
            z = D_L41_002477DC;
            rangeA = 2.8f;
            rangeB = 8.5f;
        }
        if (D_L41_002477BC > 0) {
            i = 0;
            do {
                vu0_v4 out;
                vu0_v4 off;
                vu0_v4 tmp;
                i++;
                func_0038CE20(&tmp, obj + 0xC0, func_L39_005B4410(-rangeA, rangeA));
                vec_add_ab(&off, &tmp, &D_L41_00242930);
                func_0038CE20(&tmp, obj + 0xD0, func_L39_005B4410(-rangeB, rangeB));
                vec_add_ab(&off, &tmp, &off);
                off.z = z;
                vec_add_ba(&out, obj + 0x10, &off);
                func_L41_0041B350(&out, 3, 16.0f, D_L41_002477C4[0], D_L41_002477C4[1], D_L41_002477C4[2], D_L41_002477C4[3], D_L41_002477C4[4], D_L41_002477C4[5]);
                func_L41_0041C430(&out);
            } while (i < D_L41_002477BC);
        }
        id = *(s32 *)(vars + 8);
        other = id < 0 ? 0 : D_L41_0024865C + (id << 8);
        if (other != 0 && 0.0f < *(f32 *)(*(u8 **)(other + 0x68) + 4)) {
            func_L41_0041B858(other);
        }
        id = *(s32 *)(vars + 0xC);
        other = id < 0 ? 0 : D_L41_0024865C + (id << 8);
        if (other != 0 && 0.0f < *(f32 *)(*(u8 **)(other + 0x68) + 4)) {
            func_L41_0041B858(other);
        }
    }
}
/* localdecomp:end func_L41_0041C568 */
