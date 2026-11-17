/* PAL near miss (Codex wave 8): near miss: 19 words differ with the file's flags.
 * Worker's note: 19 diff; entry/object s1-s3 allocation and constant scheduling within contiguous VU sequence; three typed pointer forms unchanged; PAL switch table saved; log build/codex/w410/func_L01_003EB5E0-07.log
 */
#include "common.h"
/* localdecomp:start func_L01_003EB5E0 */
#include "vu0.h"
extern Entry_3E6C58 D_L01_001E2A40[];
void func_L01_003EB5E0(s32 player, s32 state)
{
    extern void func_L01_003F3698(s32);
    extern void func_0038D328(f32 *, f32 *);
    extern void func_0038D590(u8 *, f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    f32 add[4], neg[4], matrix[16];
    Entry_3E6C58 *entry = &D_L01_001E2A40[player];
    u8 *obj = entry->p50;
    func_L01_003F3698(player);
    switch(state) {
    case 0:
        func_0038D328(matrix,(f32 *)((u8 *)entry+0x1A0));
        func_0038D590(obj,matrix);
        func_0038CF68(neg,matrix,-1.0f);
        func_0038CF68(add,matrix+8,1.2f);
        __asm__(
            "lqc2 vf1, %1\n\t"
            "lqc2 vf2, %2\n\t"
            "vadd.xyz vf2, vf2, vf1\n\t"
            "sqc2 vf2, %0\n\t"
            "lqc2 vf1, %0\n\t"
            "lqc2 vf2, %3\n\t"
            "vadd.xyz vf1, vf1, vf2\n\t"
            "sqc2 vf1, %0"
            : "=m"(*(vu0_v4 *)(obj+0x30))
            : "m"(*(vu0_v4 *)add), "m"(*(vu0_v4 *)((u8 *)entry+0x190)), "m"(*(vu0_v4 *)neg)
            : "vf1", "vf2");
        *(s16 *)(entry->p50+0x8A)=1;
        break;
    case 1:
        *(s16 *)(obj+0x7E)=3;
        break;
    case 2:
        ((Entry_3E92A8 *)entry)->b2A3=0;
        *(s16 *)(obj+0x7E)=2;
        ((Entry_3E92A8 *)D_L01_001E2A40)[player].f2C8=0.018f;
        ((Entry_3E92A8 *)D_L01_001E2A40)[player].f2B8=0.018f;
        break;
    case 3:
        *(s16 *)(obj+0x7E)=4;
        break;
    case 4:
        ((Entry_3E92A8 *)entry)->b2A3=0;
        *(s16 *)(obj+0x7E)=5;
        ((Entry_3E92A8 *)D_L01_001E2A40)[player].f2C8=0.018f;
        ((Entry_3E92A8 *)D_L01_001E2A40)[player].f2B8=0.018f;
        break;
    }
}
/* localdecomp:end func_L01_003EB5E0 */
