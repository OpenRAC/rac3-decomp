/* PAL near miss (Codex wave 6): near miss: 57 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -fno-sched-interblock @ps2as").
 * Worker's note: 57 positional diff in w311/func_L07_003A5670.01.log: default assembler pools 1.6f as lwc1 instead of retail lui/ori/mtc1, shortening by 8 bytes; remainder aligned identically. Fixed flags forbid assembler change; no alternate flags tested.
 */
#include "common.h"
/* localdecomp:start func_L07_003A5670 */
typedef int Quad_003A5670 __attribute__((mode(TI)));
void func_L07_003A5670(void *arg0) {
    extern s32 func_L07_003DBF10(void *, s32, void *, f32, f32);
    extern u8 *func_003C24B0(s32, s32);
    extern void func_L01_0044A7D0(void *);
    extern void func_003C7C38(void *);
    extern void func_L07_00334800(void *);
    extern void func_L07_003A5780(void *, s32);
    Quad_003A5670 offset;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *child;
    if (p[0x28D] != 3) {
        offset = 0;
        ((f32 *)&offset)[2] = 1.6f;
        *(s32 *)(p + 0x498) = func_L07_003DBF10(arg0, 1, &offset,
            *(f32 *)(*(u8 **)(p + 0x270) + 0x18), (f32)p[0x45]);
    }
    if (p[0x28D] != 4) {
        child = func_003C24B0(0x1B3F, 0x80);
        *(u8 **)(p + 0x494) = child;
        if (child != 0) {
            *(u16 *)(child + 0x34) |= 0x100;
            *(u16 *)(*(u8 **)(p + 0x494) + 0x32) = *(u16 *)((u8 *)arg0 + 0x32);
            (*(u8 **)(p + 0x494))[0x31] = ((u8 *)arg0)[0x31];
            (*(u8 **)(p + 0x494))[0x30] = 0;
            func_L01_0044A7D0(*(u8 **)(p + 0x494));
            func_003C7C38(*(u8 **)(p + 0x494));
        }
    }
    *(s32 *)(p + 0x260) = *(s32 *)(p + 0x494);
    *(s32 *)(p + 0x264) = *(s32 *)(p + 0x498);
    p[0x28D] = 5;
    *(f32 *)((u8 *)arg0 + 0x2C) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x24) + 0x24);
    func_L07_00334800(arg0);
    func_L07_003A5780(arg0, 2);
}
/* localdecomp:end func_L07_003A5670 */
