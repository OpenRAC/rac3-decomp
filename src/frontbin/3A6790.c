#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


typedef struct { f32 x, y, z, w; } V_3A0EB0;
typedef struct { f32 x, y, z, w; } E_3A0EB0;
typedef struct {
    V_3A0EB0 v;
    u128_t q10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C;
} T_3A0EB0;
extern s32 D_001D6FA0[2];
extern s32 D_001DA010[2];
extern s32 D_00225734[];
extern void func_003C2EC0();
extern void func_0038D028();
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003A6178(void *, void *, s32, f32, f32, f32, s32);
extern void func_003A8308_003A0EB0(void *, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382498(s32, s32);

/* PAL candidate for func_003A6790. The US draft called the US build's func_003A0EB0;
   in the PAL retail the same callee lives at 0x3A62D0, so only the call target
   changes (the argument passing is identical). */


/* localdecomp:start func_003A6790 */
extern void func_003A62D0(void *, s32, s32);
void func_003A6790(void *p) {
    func_003A62D0(p, 1, 0);
    func_003A62D0(p, 2, 0);
}
/* localdecomp:end func_003A6790 */

LINKER_REMNANT("asm/remnants", func_003A67D0);

INCLUDE_ASM("asm/nonmatchings/text", func_003A6800);

/* localdecomp:start func_003A6808 */
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x38]; s32 f6C; } S_225780;
typedef struct { s32 v[0x53]; } E_160C40;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad2[0xB0]; E_160C40 e[1]; } S_160C40;
extern S_225780 D_00225700_003A6808;
extern S_160C40 D_160C40;
extern s32 func_003A2598(s32, s32, s32);
extern s32 func_003A2750(s32);
s32 func_003A6808(s32 a) {
    s32 idx = D_00225700_003A6808.f30;
    s32 h = D_00225700_003A6808.f6C;
    s32 lo = D_160C40.e[idx].v[a];
    s32 d = D_160C40.e[idx].v[a + 1] - lo;
    if (d > 0) {
        func_003A2598(h, lo + D_160C40.f1284, d);
        func_003A2750(0);
    }
    return 1;
}
/* localdecomp:end func_003A6808 */
