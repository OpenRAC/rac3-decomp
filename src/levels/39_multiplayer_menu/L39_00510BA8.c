#include "common.h"

/* localdecomp:start func_L39_00510BA8 */
typedef struct S_00510BA8_Obj S_00510BA8_Obj;
typedef struct {
    s32 (*fn0)(S_00510BA8_Obj *, void *, u32);
} S_00510BA8_Vt;
struct S_00510BA8_Obj {
    S_00510BA8_Vt *vt;
    s32 unk4;
    s32 pad8;
    s32 unkC;
    u32 unk10;
    void *unk14;
    s32 pad18;
    S_00510BA8_Obj *unk1C;
};

extern s32 func_L39_0050CEE0(u32 *, s32 *, s32);
extern void func_L39_004F74E8(void *, s32, s32);
extern void *func_L39_004F75B0(void *, u32);
extern void func_L39_0050D0C0(void *, u32 *, u32, s32 *, s32, s32);
extern void func_L39_00515C70(s32, s32);

s32 func_L39_00510BA8(S_00510BA8_Obj *arg0) {
    u32 size;
    s32 info;
    s32 ret;
    void *p;

    if (arg0->unk4 == 0) {
        return 0;
    }
    ret = func_L39_0050CEE0(&size, &info, arg0->unkC);
    if (ret != 0) {
        return ret;
    }
    if (arg0->unk10 < size) {
        if (arg0->unk14 != 0) {
            func_L39_004F74E8(arg0->unk14, 0, arg0->unk10);
        }
        p = func_L39_004F75B0(arg0->unk14, size);
        arg0->unk14 = p;
        if (p == 0) {
            return 0x803;
        }
        arg0->unk10 = size;
    }
    func_L39_0050D0C0(arg0->unk14, &size, size, &info, arg0->unkC, arg0->unk4 - 1);
    func_L39_00515C70(*(s32 *)arg0, 1);
    arg0->unk4 = 0;
    return arg0->unk1C->vt->fn0(arg0->unk1C, arg0->unk14, size);
}
/* localdecomp:end func_L39_00510BA8 */

LINKER_REMNANT("asm/levels", func_L39_00510C88);
