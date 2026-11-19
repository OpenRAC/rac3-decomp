/* functional: high. Same search as the matched twin in other levels (compare-only differences: retail hoists the invariant range/0xFF tests out of the loop). Level-04 names; slot list entries are 15-bit object table indices. */
#include "common.h"
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x89]; s16 hAA; } Rec3628D8;
Rec3628D8 *func_L04_003628D8(s32 x) {
    s16 *q = D_L04_0021C9A0[x];
    if ((x & 0xFF) != 0xFF && x <= D_L04_001DFDD8 && q != 0) {
        Rec3628D8 *r = (Rec3628D8 *)(D_L04_001DFD9C + ((*(u16 *)q & 0x7FFF) << 8));
        while (r != 0) {
            if (r->hAA == 0x16E5 && r->b20 == 0x1A) return r;
            q++;
            if (!((x & 0xFF) != 0xFF && q != 0 && (q[-1] >= 0 || q == D_L04_0021C9A0[x]))) break;
            r = (Rec3628D8 *)(D_L04_001DFD9C + ((*(u16 *)q & 0x7FFF) << 8));
        }
    }
    return 0;
}
