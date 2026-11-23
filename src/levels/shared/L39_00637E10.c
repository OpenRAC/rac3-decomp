#include "common.h"

/* declared by functions of L39_00637D38.c, which this file was cut from */
extern void func_L39_00637E10(void *);

/* localdecomp:start func_L39_00637E10 */
extern void func_L39_00633308(void *, s32, f32, f32, f32);

typedef int Q_00637E10 __attribute__((mode(TI)));

void func_L39_00637E10(void *p) {
    u8 *o = p;
    f32 b;
    f32 c;
    Q_00637E10 q;

    if (o[0x1A14] != 0 && *(s16 *)(*(u8 **)(*(u8 **)(o + 0x2530) + 0x50) + 0x86) == 0x21) {
        return;
    }
    q = *(Q_00637E10 *)(o + 0x23C0);
    *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x23B8);
    *(f32 *)(o + 0xFD4) = *(f32 *)(o + 0x3EC);
    *(Q_00637E10 *)(o + 0xFC0) = q;
    func_L39_00633308(o, 0, 0.1296f, 0.36f, 0.45378562808f);
    c = *(f32 *)(o + 0xFD8);
    b = *(f32 *)(o + 0xFD4);
    *(f32 *)(o + 0x41C) = c;
    *(f32 *)(o + 0x3EC) = b;
    if (c == 0.0f) {
        *(s32 *)(o + 0x3FC) = *(s32 *)(o + 0x3FC) + 1;
    } else {
        *(s32 *)(o + 0x3FC) = 0;
    }
}
/* localdecomp:end func_L39_00637E10 */
