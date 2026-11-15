#include "common.h"

/* localdecomp:start func_L33_0034F910 */
void func_L33_0034F998(void *);
void func_L33_00350378(void *);
void func_L33_00350470(void *);
void func_L33_003505D8(void *);

void func_L33_0034F910(void *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 0:
        func_L33_00350378(arg0);
        break;
    case 1:
        func_L33_00350470(arg0);
        break;
    case 2:
        func_L33_003505D8(arg0);
        break;
    }
    func_L33_0034F998(arg0);
}
/* localdecomp:end func_L33_0034F910 */

/* localdecomp:start func_L33_0034F998 */
extern float D_001DD7D8;
extern int func_L30_0034D8D8(void *, float);
extern void func_003C2880(void *);

void func_L33_0034F998(void *p)
{
    if (func_L30_0034D8D8((char *)p + 0x10, D_001DD7D8) == 0) {
        func_003C2880(p);
    }
}
/* localdecomp:end func_L33_0034F998 */

/* localdecomp:start func_L33_0034F9D8 */
void func_L33_0034F9D8(u8 *a0, f32 f12, f32 f13, s32 a1, s32 a2, s32 a3, f32 f14, f32 f15, f32 f16) {
    u8 *p = *(u8 **)(a0 + 0x68);

    *(f32 *)(p + 0x2C) = f12;
    *(f32 *)(p + 0x30) = f13;
    *(s32 *)(p + 0x34) = a2;
    *(s32 *)(p + 0x38) = a1;
    *(s32 *)(p + 0x3C) = a3;
    *(f32 *)(p + 0x40) = f14;
    *(f32 *)(p + 0x44) = f15;
    *(f32 *)(p + 0x48) = f16;
}
/* localdecomp:end func_L33_0034F9D8 */
