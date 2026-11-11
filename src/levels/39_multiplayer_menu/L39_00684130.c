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

/* declared by functions of L39_00681758.c, which this file was cut from */
extern s32 func_003E7F20(s32, s32);
s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);

/* localdecomp:start func_L39_00684130 */
void func_L39_00684130(u8 *arg0, s32 arg1) {
    s32 v;

    switch (arg1) {
    case -1:
        v = 1;
        break;
    case 0:
        v = 3;
        break;
    case 1:
        v = 2;
        break;
    default:
        v = arg1;
        break;
    }
    if (*(s32 *)(arg0 + 0xBC) != -1) {
        func_L01_00516C78(*(s32 *)(arg0 + 0xBC), v, 3);
    }
}
/* localdecomp:end func_L39_00684130 */

/* localdecomp:start func_L39_00684190 */
extern s32 func_003E7F20(s32, s32);
s32 func_L39_00684190(s8 *a, s32 b) {
    s32 mode;
    *(s32 *)(a + 0xC4) = b;
    mode = (b == 1) ? 1 : 2;
    if (*(s32 *)(a + 0xB4) != -1) {
        func_003E7F20(*(s32 *)(a + 0xB4), mode);
    }
    if (*(s32 *)(a + 0xB8) != -1) {
        func_003E7F20(*(s32 *)(a + 0xB8), mode);
    }
    if (*(s32 *)(a + 0xBC) != -1) {
        func_003E7F20(*(s32 *)(a + 0xBC), mode);
    }
    return 1;
}
/* localdecomp:end func_L39_00684190 */

/* localdecomp:start func_L39_00684218 */
typedef struct {
    char _p0[0xB4];
    s32 fB4;
    s32 fB8;
    s32 fBC;
} S_684218;

/* from rac4-decomp's func_L00_0053BEF0 */
void func_L39_00684218(S_684218 *arg0) {
    arg0->fB4 = -1;
    arg0->fB8 = -1;
    arg0->fBC = -1;
}
/* localdecomp:end func_L39_00684218 */
