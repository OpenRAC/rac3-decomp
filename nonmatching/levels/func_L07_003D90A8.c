/* PAL near miss (Codex wave 8): near miss: 9 words differ with the file's flags.
 * Worker's note: 9 word differences, loop slot/index s2/s3 allocation swapped; three statement-order variants unchanged (90A8-03.log to 05.log). Uses exact S_3D9330 declaration from later block; integration must reuse it without duplicate and move declaration earlier.
 */
#include "common.h"
/* localdecomp:start func_L07_003D90A8 */
typedef struct {
    u8 pad[0x14];
    f32 f14;
    f32 f18;
    u8 tail[0x100 - 0x1C];
} S_3D9330;
extern S_3D9330 *D_L07_001DF41C;
typedef unsigned int Q_003D90A8 __attribute__((mode(TI)));
void func_L07_003D90A8(u8 *obj) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_003C7C38(void *);
    extern void func_L07_003D9218(s32);
    extern void func_L07_003D9260(s32);
    u8 *child;
    u8 *state;
    s32 i;
    u8 **slot;
    u8 *copy;
    if (obj[0x20] != 0) return;
    state = *(u8 **)(obj + 0x68);
    slot = (u8 **)(state + 0x34);
    copy = (u8 *)D_L07_001DF41C + (*(s32 *)(state + 0x30) << 8);
    *(Q_003D90A8 *)(copy + 0x10) = *(Q_003D90A8 *)(obj + 0x10);
    *(Q_003D90A8 *)(copy + 0xF0) = *(Q_003D90A8 *)(obj + 0xF0);
    copy[0x30] = obj[0x30];
    *(u16 *)(copy + 0x32) = *(u16 *)(obj + 0x32);
    i = 0;
    do {
        child = func_003C24B0(0x1CA1, 0x80);
        if (child) {
            child[0x31] = 1;
            *(u16 *)(child + 0x32) = *(u16 *)(obj + 0x32);
            child[0x30] = obj[0x30];
            *(unsigned long *)(child + 0x38) = *(unsigned long *)(obj + 0x38);
            if (i != 0) *(u16 *)(child + 0x34) |= 0x8000;
            *(Q_003D90A8 *)(child + 0x10) = *(Q_003D90A8 *)(obj + 0x10);
            *(f32 *)(child + 0x14) -= 7.07f;
            *(f32 *)(child + 0xF8) = (f32)i * 3.1415927f;
            func_003C7C38(child);
        }
        *slot = child;
        i++;
        slot++;
    } while (i < 2);
    *(void (**)(s32))(state + 4) = func_L07_003D9218;
    *(void (**)(s32))(state + 8) = func_L07_003D9260;
    func_L07_003D9218((s32)obj);
}
/* localdecomp:end func_L07_003D90A8 */
