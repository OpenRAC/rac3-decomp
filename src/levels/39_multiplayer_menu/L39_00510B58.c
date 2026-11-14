#include "common.h"

/* localdecomp:start func_L39_00510B58 */
extern u8 D_L39_0046F450[];

typedef struct S_00510B58_Obj S_00510B58_Obj;
typedef struct {
    s32 (*fn0)(S_00510B58_Obj *, u8 *, s32);
} S_00510B58_Vt;
struct S_00510B58_Obj {
    S_00510B58_Vt *vt;
    s32 unk4;
    s32 pad[5];
    S_00510B58_Obj *unk1C;
};

s32 func_L39_00510B58(S_00510B58_Obj *arg0) {
    if (arg0->unk4 != 1) {
        return 0;
    }
    arg0->unk4 = 0;
    arg0 = arg0->unk1C;
    return arg0->vt->fn0(arg0, D_L39_0046F450, 2);
}
/* localdecomp:end func_L39_00510B58 */
