#include "common.h"

/* localdecomp:start func_L39_004F4C98 */
extern s32 func_L39_004F6060(void *, void *, s32);
extern s32 func_L39_004F5EA0(void *, void *, void *);

s32 func_L39_004F4C98(void *a0, void *a1, u32 *a2) {
    u32 *buf;
    s32 ret;

    if (*a2 > 0x400) {
        return 0x201;
    }
    ret = func_L39_004F6060(a1, &buf, 4);
    if (ret != 0) {
        return ret;
    }
    *buf = *a2;
    return func_L39_004F5EA0(a1, a0, buf);
}
/* localdecomp:end func_L39_004F4C98 */

LINKER_REMNANT("asm/levels", func_L39_004F4D18);

/* localdecomp:start func_L39_004F4D20 */
typedef struct {
    u32 f0;
    u32 f4;
    s32 f8;
} S_004F4D20;
extern s32 func_L39_004F6060(void *, void *, s32);
extern s32 func_L39_004F5EA0(void *, void *, void *);

s32 func_L39_004F4D20(void *a0, void *a1, S_004F4D20 *a2) {
    S_004F4D20 *buf;
    s32 ret;

    if (a2->f0 > 0x10 || a2->f4 > 0xFF || a2->f8 != 0x20) {
        return 0x21D;
    }
    ret = func_L39_004F6060(a1, &buf, 0x10);
    if (ret != 0) {
        return ret;
    }
    buf->f0 = a2->f0;
    buf->f4 = a2->f4;
    buf->f8 = a2->f8;
    return func_L39_004F5EA0(a1, a0, buf);
}
/* localdecomp:end func_L39_004F4D20 */

LINKER_REMNANT("asm/levels", func_L39_004F4DD8);

/* localdecomp:start func_L39_004F4DE0 */
extern s32 func_L39_004F6060(void *, void *, s32);
extern s32 func_L39_004F5EA0(void *, void *, void *);

s32 func_L39_004F4DE0(void *a0, void *a1, s32 *a2) {
    s32 *buf;
    s32 v = *a2;
    s32 r;
    if (v != 0x14) {
        return 0x21D;
    }
    r = func_L39_004F6060(a1, &buf, 8);
    if (r != 0) {
        return r;
    }
    *buf = v;
    return func_L39_004F5EA0(a1, a0, buf);
}
/* localdecomp:end func_L39_004F4DE0 */
