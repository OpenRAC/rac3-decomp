/* Level 4. File L04_00377698.c (-mno-split-addresses). check.py: 2 diff. Retail ends the inner test with `move $v0,$a0; ...; movn $v0,$zero,$v1`; the C gives `move $v0,$zero; ...; movz $v0,$a0,$v1` for every spelling of the select. */
#include "common.h"

extern s32 D_L04_001E1AA4[];
extern s32 D_L04_001E1B80[];
extern s32 D_L04_001E1B50;

s32 func_L04_00377698(s32 a0) {
    s32 v;
    if (a0 != D_L04_001E1AA4[0]) {
        return 0;
    }
    v = D_L04_001E1B80[0];
    if (v == 1) {
        return D_L04_001E1B50 < 7 ? 0 : v;
    }
    return 0;
}
