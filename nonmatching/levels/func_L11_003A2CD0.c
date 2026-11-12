/* near miss (level 11, Obani Moons): 4 differences, with the file's flags plus -mvu0-use-vf0-vf2 (needed by vec_sub_ba's "j" operands): two saved-register stores in the prologue (sd $s3 before sd $s2 here, retail sd $s2 first) and the v + 0x70 addiu, which retail schedules after the second lq; everything else matches, including the stack slots (pos, rot, d declared in that order as vu0_v4). Tried a pointer local for v + 0x70 (before and after the copies), a typed r pointer, declaration orders of r and v, the six declaration orders of the locals */
#include "common.h"

/* localdecomp:start func_L11_003A2CD0 */
#include "vu0.h"
typedef int q_3A2CD0 __attribute__((mode(TI)));
__asm__(".extern D_L11_001DE098, 4");
__asm__(".extern D_L11_001DE0A8, 1");
__asm__(".extern D_L11_001DE0B8, 4");
extern f32 D_L11_001DE098;
extern u8 D_L11_001DE0A8;
extern f32 D_L11_001DE0B8;
extern void func_003C6680(void *, void *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, u8 *, s32);
extern void func_003C6990(void *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L11_003A2CD0(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *r = a0 + 0xF0;
    vu0_v4 pos;
    vu0_v4 rot;
    vu0_v4 d;

    if (v != 0) {
        pos = *(vu0_v4 *)(a0 + 0x10);
        rot = *(vu0_v4 *)r;
        if (a0[0x20] == 0) {
            func_003C6680(a0, v + 0x70, 0, 0, &D_L11_001DE098, 0, 0, 0, &D_L11_001DE0B8, &D_L11_001DE0A8, 0);
            func_L01_004450F0(a0, 1, -1);
        }
        func_003C6990(a0, v + 0x70, 0);
        vec_sub_ba(&d, &pos, a0 + 0x10);
        func_003C4DA8(v + 0x30, &d, &rot, r);
    }
}
/* localdecomp:end func_L11_003A2CD0 */
