#include "common.h"

LINKER_REMNANT("asm/levels", func_L40_00491568);

/* localdecomp:start func_L40_00491588 */
#include "vu0.h"
extern u8 *D_L40_00248500[];
s32 func_L40_00491588(void *pos, s32 idx) {
    extern void func_0038D000(void *, void *, void *);
    s32 tab=(s32)D_L40_00248500[0];
    vu0_v4 d;
    s32 r;
    vec_sub_ab(&d,pos,(u8 *)((idx << 7)+tab)+0x30);
    func_0038D000(&d,&d,(u8 *)((idx << 7)+tab)+0x40);
    r=0;
    if (fabs_asm(d.x)<=1.0f && fabs_asm(d.y)<=1.0f && fabs_asm(d.z)<=1.0f) r=1;
    return r;
}
/* localdecomp:end func_L40_00491588 */

/* localdecomp:start func_L40_00491620 */
#include "vu0.h"

extern u8 *D_L40_0024852C[];
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CED8(void *);

s32 func_L40_00491620(void *pos, s32 idx) {
    s32 tab = (s32)D_L40_0024852C[0];
    vu0_v4 d;
    s32 r;

    vec_sub_ab(&d, pos, (u8 *)((idx << 7) + tab) + 0x30);
    r = 0;
    func_0038D000(&d, &d, (u8 *)((idx << 7) + tab) + 0x40);
    if (func_0038CED8(&d) <= 1.0f && fabs_asm(d.z) <= 1.0f) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L40_00491620 */

/* localdecomp:start func_L40_004916B0 */
extern u8 *D_L40_00248524[];
extern f32 func_0038CEA8(void *);

s32 func_L40_004916B0(void *pos, s32 idx) {
    s32 tab = (s32)D_L40_00248524[0];
    vu0_v4 d;

    vec_sub_ab(&d, pos, (u8 *)((idx << 7) + tab) + 0x30);
    func_0038D000(&d, &d, (u8 *)((idx << 7) + tab) + 0x40);
    return func_0038CEA8(&d) <= 1.0f;
}
/* localdecomp:end func_L40_004916B0 */

LINKER_REMNANT("asm/levels", func_L40_00491728);
