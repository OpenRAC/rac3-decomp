#include "common.h"

/* localdecomp:start func_L39_006487E8 */
typedef struct Obj00645F88 Obj00645F88;
typedef struct {
    u8 pad[28];
    s32 (*fn)(Obj00645F88 *, s32);
} VT00645F88;
struct Obj00645F88 {
    u8 pad[20];
    VT00645F88 *vt;
};

extern s32 func_L39_005B8928(u8 *);

s32 func_L39_006487E8(u8 *o, Obj00645F88 *b) {
    if (*(s16 *)(o + 170) == 4253) {
        if (b->vt->fn(b, -1)) {
            return 1;
        }
    }
    return func_L39_005B8928(o) != 0;
}
/* localdecomp:end func_L39_006487E8 */

INCLUDE_ASM("asm/levels", func_L39_00648840);

INCLUDE_ASM("asm/levels", func_L39_006488E8);

INCLUDE_ASM("asm/levels", func_L39_00648960);

INCLUDE_ASM("asm/levels", func_L39_00648A20);

/* localdecomp:start func_L39_00648A90 */
extern s32 func_L39_0061D1D8(s32);

s32 func_L39_00648A90(u8 *a0) {
    s32 r;
    if (a0 == 0) {
        r = 0;
    } else {
        r = func_L39_0061D1D8(*(s32 *)(a0 + 144));
    }
    return r;
}
/* localdecomp:end func_L39_00648A90 */

/* localdecomp:start func_L39_00648AB8 */
s32 func_L39_00648AB8(u8 *a0, s32 a1) {
    return *(s32 *)(a0 + 0x2548) == a1;
}
/* localdecomp:end func_L39_00648AB8 */

LINKER_REMNANT("asm/levels", func_L39_00648AC8);

INCLUDE_ASM("asm/levels", func_L39_00648AE0);

INCLUDE_ASM("asm/levels", func_L39_00648B98);

/* localdecomp:start func_L39_00648BA8 */
s32 func_L39_00648BA8(void) {
    return 0;
}
/* localdecomp:end func_L39_00648BA8 */

/* localdecomp:start func_L39_00648BB0 */
extern s32 func_L01_003EB2D8(s32);

s32 func_L39_00648BB0(u8 *a0) {
    return func_L01_003EB2D8(*(s32 *)(*(u8 **)(*(u8 **)(a0 + 9520) + 80) + 148)) != 0;
}
/* localdecomp:end func_L39_00648BB0 */

INCLUDE_ASM("asm/levels", func_L39_00648BD8);

/* localdecomp:start func_L39_00648C00 */
s32 func_L39_00648C00(void) {
    return 1;
}
/* localdecomp:end func_L39_00648C00 */
