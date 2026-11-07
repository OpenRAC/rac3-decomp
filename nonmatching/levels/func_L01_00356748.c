/* Level 01. 41 diff at default flags. Semantics right; retail hoists the invariant "x <= D_001E0058" and "x & 0xFF" tests out of the search loop (always-zero $a3, copy in $a2) and rotates the loop so the r computation heads it; this C emits the loop with the tests and constants in a different order/place. gcc does not invert the loop for plain while/for forms (46-50 diff). */
#include "common.h"
#include "common.h"
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x89]; s16 hAA; } R;
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C_0748;
__asm__(".extern D_L01_001E001C_0748, 16");
extern s32 D_L01_001E0058_0748;
__asm__(".extern D_L01_001E0058_0748, 16");
R *func_L01_00356748(s32 x) {
    s16 *q = D_L01_0021DE20[x];
    if ((x & 0xFF) != 0xFF && x <= D_L01_001E0058_0748 && q != 0) {
        R *r = (R *)(D_L01_001E001C_0748 + ((*(u16 *)q & 0x7FFF) << 8));
        while (r != 0) {
            if (r->hAA == 0x16E4 && r->b20 == 0x18) return r;
            q++;
            if (!((x & 0xFF) != 0xFF && x <= D_L01_001E0058_0748 && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[x]))) break;
            r = (R *)(D_L01_001E001C_0748 + ((*(u16 *)q & 0x7FFF) << 8));
        }
    }
    return 0;
}
