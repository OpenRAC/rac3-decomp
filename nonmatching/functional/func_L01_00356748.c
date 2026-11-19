/* functional: high. Retail hoists the invariant range and 0xFF tests out of the search loop and rotates it; this C re-tests them each iteration (same results; retail $a3 is always 0 so its bnez never fires). Struct named Rec to avoid a context clash. */
#include "common.h"
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x89]; s16 hAA; } Rec;
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C_0748;
__asm__(".extern D_L01_001E001C_0748, 16");
extern s32 D_L01_001E0058_0748;
__asm__(".extern D_L01_001E0058_0748, 16");
Rec *func_L01_00356748(s32 x) {
    s16 *q = D_L01_0021DE20[x];
    if ((x & 0xFF) != 0xFF && x <= D_L01_001E0058_0748 && q != 0) {
        Rec *r = (Rec *)(D_L01_001E001C_0748 + ((*(u16 *)q & 0x7FFF) << 8));
        while (r != 0) {
            if (r->hAA == 0x16E4 && r->b20 == 0x18) return r;
            q++;
            if (!((x & 0xFF) != 0xFF && x <= D_L01_001E0058_0748 && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[x]))) break;
            r = (Rec *)(D_L01_001E001C_0748 + ((*(u16 *)q & 0x7FFF) << 8));
        }
    }
    return 0;
}
