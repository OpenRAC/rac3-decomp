/* PAL near miss (Codex wave 6): near miss: 56 words differ with the file's flags.
 * Worker's note: 2 diff: build/codex/w257/func_L01_0030B880.a6-object.log; --divs 2 injected; only loads at +0x48/+0x64 swapped (vf1 source+0x30 and vf2 source+0x20); three wordings same bytes; metadata not exact
 */
#include "common.h"
/* localdecomp:start func_L01_0030B880 */
static __inline__ void prepare_0030B880(vu0_v4 *a, vu0_v4 *b, vu0_v4 *tangent, vu0_v4 *source) {
    vu0_q x, y;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(source[2]));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(source[3]));
    __asm__("sqc2 %1, %0" : "=m"(*tangent) : "j"(x));
    *(vu0_q *)b = *(vu0_q *)&source[1];
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*tangent));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*b) : "j"(x));
}
void func_L01_0030B880(void *object, vu0_v4 *source) {
    extern void func_L01_0030ABF8(void *, void *, void *, void *, void *, f32);
    extern void func_L01_0030B9C8(void *, s32, void *, s32);
    extern s32 func_00382498(s32, s32);
    vu0_v4 points[9];
    vu0_v4 a, b, tangent;
    s32 i;
    for (i=0; i<8; i++) {
        *(vu0_q *)&a = *(vu0_q *)&source[0];
        prepare_0030B880(&a, &b, &tangent, source);
        func_L01_0030ABF8(&points[i], &source[2], &source[3], &a, &b, (f32)i/7.0f);
    }
    if (*(s32 *)((u8 *)source+0x98) >= (*(s32 *)((u8 *)source+0x9C) >> 1)) {
        func_L01_0030B9C8(object,func_00382498(64,128),points,9);
    } else {
        func_L01_0030B9C8(object,func_00382498(0,64),points,9);
    }
}
/* localdecomp:end func_L01_0030B880 */
