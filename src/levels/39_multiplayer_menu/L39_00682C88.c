#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* localdecomp:start func_L39_00682C88 */
s32 func_L01_00516C78(s32, s32, s32);

void func_L39_00682C88(void *arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = arg1;
    switch (var_a1) {                               /* irregular */
    case -1:
        var_a1 = 1;
        break;
    case 1:
        var_a1 = 2;
        break;
    case 0:
        var_a1 = 3;
        break;
    }
    if ((*(s32 *)((u8 *)arg0 + 0xA8)) != -1) {
        func_L01_00516C78((*(s32 *)((u8 *)arg0 + 0xA8)), var_a1, 3);
    }
}
/* localdecomp:end func_L39_00682C88 */

/* localdecomp:start func_L39_00682CE8 */
typedef struct S_682CE8 {
    char _p0[0xA0];
    s32 fA0;
    s32 fA4;
    s32 fA8;
} S_682CE8;

/* from rac4-decomp's func_L00_0053BEF0 */
void func_L39_00682CE8(S_682CE8 *arg0) {
    arg0->fA0 = -1;
    arg0->fA4 = -1;
    arg0->fA8 = -1;
}
/* localdecomp:end func_L39_00682CE8 */
