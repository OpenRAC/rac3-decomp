/* PAL near miss (Codex wave 10): near miss: 37 words differ with the file's flags.
 * Worker's note: 36 differing words; duplicated calls instead of shared call tail; best log build/codex/w521/0035C958-09.log; fixed flags
 */
#include "common.h"
/* localdecomp:start func_L07_0035C958 */
typedef unsigned int Quad_0035C958 __attribute__((mode(TI)));
extern s32 D_001DD6B0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DD6B0_sda, 4");
extern void func_L07_0035C880(u8 *a0);
s32 func_L07_0035C958(u8 *m)
{
    extern s32 func_L01_00450010(void *, s32, float, float, float, float);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_00404808(void (*)(u8 *), void *);
    Quad_0035C958 pos;
    u8 *p = *(u8 **)(m + 0x68);
    s32 hit;
    if (m[0x20] != 5) {
        pos = *(Quad_0035C958 *)(m + 0x10);
        hit = func_L01_00450010(&pos, 0, 1.57079637f, 20.0f, -1.0f, -1.0f);
        *(s32 *)(p + 0x140) = hit;
        if (hit && m[0x20] != 8 && m[0x20] != 7) {
            *(s32 *)(p + 0x1D0) = hit;
            func_L01_004450F0(m, 5, -1);
            D_001DD6B0_sda == 2 ? func_003C3A10(m, 0, 0, 0) : func_003C3A10(m, 3, 0, 8);
            *(float *)(m + 0x48) = 2.0f;
        }
    }
    if (m[0x42] == 2) *(float *)(m + 0x48) = 0.5f;
    else *(float *)(m + 0x48) = 1.0f;
    func_L01_00404808(func_L07_0035C880, m);
    return 0;
}
/* localdecomp:end func_L07_0035C958 */
