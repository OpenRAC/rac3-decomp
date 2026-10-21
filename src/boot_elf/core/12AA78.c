#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0012AA78 */
extern s32 func_0012B098(s32);
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 D_15A140;
extern void *D_15A144;

s32 func_0012AA78(s32 a) {
    register void *gp __asm__("$28");
    s32 old;
    s32 r;

    if (func_0012B098(1) != 0) {
        return 0;
    }
    r = func_00124920();
    old = D_15A140;
    D_15A140 = a;
    *(void * volatile *)&D_15A144 = gp;
    if (r != 0) {
        func_00124970();
    }
    return old;
}
/* localdecomp:end func_0012AA78 */

/* localdecomp:start func_0012AAE0 */
extern volatile int D_0013F914;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F934;
extern volatile int D_0013F960;
extern volatile int D_0013F964;
extern int D_15A140;
extern void func_0011EE50(s32);

void func_0012AAE0(s32 *p) {
    u64 new_var;

    D_0013F960 = p[0];
    D_0013F964 = D_0013F960;
    if (D_0013F960 == 11) {
        D_0013F960 = 0;
        D_0013F934 = 0;
        return;
    }
    func_0011EE50(D_0013F928);
    new_var = D_0013F914;
    if (new_var != 0 && D_15A140 != 0) {
        func_0011EE50(D_0013F920);
    } else {
        D_0013F934 = 0;
    }
    D_0013F960 = 0;
}
/* localdecomp:end func_0012AAE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0012AB80);
