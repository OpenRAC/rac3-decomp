/* functional: high. 3 diff vs retail, all instruction scheduling; draft's vec_add_ba helper spills vf17 under the file flags so the VU0 add is written as inline lqc2/vadd.xyz/sqc2 with vf1/vf2 clobbers */
#include "common.h"
#include "vu0.h"

extern void func_0038D000(void *, void *, void *);

extern f32 D_001DDD88_sda;
__asm__(".extern D_001DDD88_sda, 4");

void func_L01_00385188(s32 a0, void *a1) {
    vu0_v4 r;
    vu0_v4 v;

    *(vu0_q *)&v = 0;
    v.x = D_001DDD88_sda;
    v.w = 1.0f;
    *(vu0_q *)&r = *(vu0_q *)&v;
    func_0038D000(&r, &r, (u8 *)a0 + 0xC0);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)a1) : "m"(*(vu0_v4 *)((u8 *)a0 + 0x10)), "m"(r) : "vf1", "vf2");
}
