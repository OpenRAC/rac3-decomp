#include "common.h"

/* localdecomp:start func_L39_00505048 */
s32 func_L39_00505048(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x34));
}
/* localdecomp:end func_L39_00505048 */

/* localdecomp:start func_L39_00505050 */
extern s32 func_L39_00505050();

s32 func_L39_00505050(void *p) {
    return *(s32 *)((u8 *)p + 0x0);
}
/* localdecomp:end func_L39_00505050 */

/* localdecomp:start func_L39_00505058 */
extern s32 func_L39_00505058();

s32 func_L39_00505058(void *p) {
    return *(s32 *)((u8 *)p + 0x0);
}
/* localdecomp:end func_L39_00505058 */

/* localdecomp:start func_L39_00505060 */
extern s32 func_L39_00505060();

s32 func_L39_00505060(void *p) {
    return *(s32 *)((u8 *)p + 0x0);
}
/* localdecomp:end func_L39_00505060 */

/* localdecomp:start func_L39_00505068 */
typedef struct S_00505068_O {
    u8 pad0[0x38];
    s32 f38;
} S_00505068_O;

typedef struct S_00505068 {
    S_00505068_O *f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_00505068;

extern void func_0011D534(s32, s32, s32);
extern void func_L39_004BEF28(s32);
extern s32 func_L39_004BEED8(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_00505068(S_00505068 *arg0) {
    arg0->f4 = 0;
    if (arg0->f0 != 0 && arg0->f8 != arg0->f0->f38) {
        if (arg0->fC != 0) {
            func_0011D534(arg0->fC, 0, arg0->f8);
            func_L39_004BEF28(arg0->fC);
        }
        arg0->fC = func_L39_004BEED8(arg0->f0->f38);
        if (arg0->fC == 0) {
            func_L39_004BC6C8(6, 0x74, 0x21, 0, 0);
            return 0;
        }
        arg0->f8 = arg0->f0->f38;
    }
    if (arg0->fC != 0) {
        func_0011D534(arg0->fC, 0, arg0->f8);
    }
    return 1;
}
/* localdecomp:end func_L39_00505068 */

/* localdecomp:start func_L39_00505120 */
extern s32 func_L39_0050C260(s32 *, s32);
extern void func_11D380(s32, s32, s32);

s32 func_L39_00505120(s32 *self, s32 *src)
{
    if (!func_L39_0050C260(self, src[0])) {
        return 0;
    }
    self[1] = src[1];
    if (src[3]) {
        func_11D380(self[3], src[3], src[2]);
    }
    return 1;
}
/* localdecomp:end func_L39_00505120 */
