#include "common.h"

/* localdecomp:start func_L39_004BB4C0 */
extern s32 func_L39_004BB4B0(void);
extern void *func_L39_004DA968(s32);
extern void func_L39_004DAE28(s32, s32, s32, s32);

void *func_L39_004BB4C0(s32 arg0, s32 arg1) {
    void *p;

    p = func_L39_004DA968(func_L39_004BB4B0());
    if (p == 0) {
        return 0;
    }
    func_L39_004DAE28((s32)p, 0x68, arg1, arg0);
    return p;
}
/* localdecomp:end func_L39_004BB4C0 */

/* localdecomp:start func_L39_004BB528 */
typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x4];
    s32 unk14;
    u8 pad18[0x4];
    s32 unk1C;
    s32 unk20;
} S_004BB528;

s32 func_L39_004BB528(S_004BB528 *arg0) {
    arg0->unkC = 0;
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk14 = 0;
    return 1;
}
/* localdecomp:end func_L39_004BB528 */

INCLUDE_ASM("asm/levels", func_L39_004BB540);

INCLUDE_ASM("asm/levels", func_L39_004BB5A8);

INCLUDE_ASM("asm/levels", func_L39_004BB648);

INCLUDE_ASM("asm/levels", func_L39_004BB6D0);

/* localdecomp:start func_L39_004BB838 */
extern s32 func_00120884(const char *);
extern s32 func_L39_004BB648(void *, const char *, s32);

s32 func_L39_004BB838(void *arg0, const char *arg1) {
    return func_L39_004BB648(arg0, arg1, func_00120884(arg1));
}
/* localdecomp:end func_L39_004BB838 */

/* localdecomp:start func_L39_004BB880 */
extern s32 D_L39_004433B8[];
extern void func_0011D534(void *, s32, s32);

void func_L39_004BB880(void) {
    func_0011D534(D_L39_004433B8, 0, 0xE8);
}
/* localdecomp:end func_L39_004BB880 */
