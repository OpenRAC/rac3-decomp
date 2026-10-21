#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004CD878);

/* localdecomp:start func_L01_004CD880 */
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad[238];
} Entry240;

extern u8 D_001425C0[];
extern Entry240 D_L01_002C5600[];
extern s32 D_L01_001DB358[2];
extern s32 func_L01_00418D48(s32);

void func_L01_004CD880(s32 idx, s32 *p1, s32 *p2, s32 *out) {
    *p1 = 0;
    *p2 = 0;
    *out = D_L01_001DB358[(D_L01_002C5600 + D_001425C0[idx])->b1];
    if (D_L01_002C5600[D_001425C0[idx]].b0 != 0) {
        if (func_L01_00418D48(idx) > 0) {
            *p1 = 0x706EC8FF;
            *p2 = 0x706EC8FF;
        }
    }
}
/* localdecomp:end func_L01_004CD880 */
