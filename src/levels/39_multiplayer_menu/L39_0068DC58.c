#include "common.h"

/* localdecomp:start func_L39_0068DC58 */
typedef struct V_0068DC58 V_0068DC58;
typedef struct O_0068DC58 {
    char _p0[0x60];
    V_0068DC58 *f60;
} O_0068DC58;
struct V_0068DC58 {
    char _p0[0xD8];
    void (*fD8)(O_0068DC58 *, f32, f32);
};
typedef struct {
    char _p0[0x114];
    O_0068DC58 *f114;
    char _p118[0x770 - 0x118];
    f32 f770;
    f32 f774;
} S_0068DC58;
typedef struct {
    char _p0[0x284];
    s32 f284;
} G_0068DC58;

__asm__(".extern D_L39_00247914, 16");
extern G_0068DC58 *D_L39_00247914;
void func_L39_0068DDC8(S_0068DC58 *);
s32 func_L39_00688340(s32, s32, s32);
void func_L39_0068E110(S_0068DC58 *);
void func_L39_0068E0E8(S_0068DC58 *);
s32 func_L39_0068AEF8(S_0068DC58 *, s32);
void func_003C4138(f32 *, f32, f32);

s32 func_L39_0068DC58(S_0068DC58 *arg0, s32 arg1) {
    O_0068DC58 *o;

    func_L39_0068DDC8(arg0);
    if (arg1 == 5) {
        func_L39_00688340(0x17, 0, 0);
        func_L39_0068E110(arg0);
        func_L39_0068E0E8(arg0);
        D_L39_00247914->f284 = 0;
        return 1;
    }
    if (func_L39_0068AEF8(arg0, arg1) != 0) {
        return 1;
    }
    if (arg1 == 7) {
        func_L39_00688340(4, 0, 0);
        D_L39_00247914->f284 = 0x19;
        return 1;
    }
    if (arg1 == 1 || arg1 == 0xE) {
        func_003C4138(&arg0->f770, 0.0f, 0.03f);
        o = arg0->f114;
        o->f60->fD8(o, 0.0f, arg0->f770);
        return 1;
    }
    if (arg1 == 2 || arg1 == 0xF) {
        func_003C4138(&arg0->f770, -arg0->f774, 0.03f);
        o = arg0->f114;
        o->f60->fD8(o, 0.0f, arg0->f770);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_0068DC58 */
