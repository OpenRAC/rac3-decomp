/* PAL near miss (Codex wave 6): near miss: 41 words differ with the file's flags.
 * Worker's note: 41 diff; VU0 memory addressing and address hoisting/scheduling; func_L01_00366BE0.04.log
 */
#include "common.h"
/* localdecomp:start func_L01_00366BE0 */
#include "vu0.h"
extern vu0_q D_L01_001E1C40;
extern vu0_q D_L01_001E1C50;
extern vu0_q D_001A4C60;
typedef struct { u8 pad[0x25C0]; u8 *object; } State_00366BE0;
extern State_00366BE0 D_001A4BE0_00366BE0;
void func_L01_00366BE0(u8 *object) {
    extern void func_0038D308(void *, void *);
    extern void func_003C2EC0(void *, s32, void *);
    extern f32 func_0038CF00(void *, void *);
    vu0_q matrix[4];
    func_0038D308(object + 0xC0, object + 0xF0);
    func_003C2EC0(object, 0, matrix);
    D_L01_001E1C40 = matrix[3];
    __asm__("lqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf0, $vf1\n\tsqc2 $vf1, %0"
        : "=m"(D_L01_001E1C50) : "m"(matrix[1]) : "vf1");
    if (func_0038CF00(&D_L01_001E1C40, &D_001A4C60) > 5.0f) {
        func_0038CE20(&D_L01_001E1C40, (s128 *)(D_001A4BE0_00366BE0.object + 0xE0), 1.5f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(D_L01_001E1C40) : "m"(D_L01_001E1C40), "m"(D_001A4C60) : "vf1", "vf2");
        D_L01_001E1C50 = *(vu0_q *)(D_001A4BE0_00366BE0.object + 0xC0);
    }
}
/* localdecomp:end func_L01_00366BE0 */
