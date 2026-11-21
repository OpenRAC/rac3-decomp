/* PAL near miss (haiku-w4): 55 words differ with the file's flags; the loop counter is reversed (count-down bgez, i<<2 strength-reduced to a pointer, retail counts up with slti and computes sll in the beqz slot), and the pos/rot/objects loads and loop-end order differ. Frame, saved regs and pre-loop calls match. */
#include "common.h"

#include "vu0.h"
/* localdecomp:start func_L01_00340DC0 */
void func_L01_00340DC0(char *self) {
    extern void func_0038D308(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_0038DBD8(u32, s32, f32);
    extern void func_L01_0044E820(char *, s32);
    extern void func_003C7DD8(void *);
    extern void func_L01_0044E130(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    vu0_v4 offset;
    vu0_v4 angles;
    char *state = *(char **)(self + 0x68);
    char **objects;
    s32 i;
    char *pos;
    char *rot;
    if (*(void **)(*(char **)(state + 0x10) + 0x24)) {
        *(u16 *)(*(char **)(state + 0x10) + 0x34) &= 0xFFFE;
        (*(char **)(state + 0x10))[0x31] = 1;
        *(s32 *)(*(char **)(state + 0x10) + 0x98) = *(s32 *)(*(char **)(*(char **)(state + 0x10) + 0x24) + 0x10);
    }
    func_0038D308(*(char **)(state + 0x10) + 0xC0, *(char **)(state + 0x10) + 0xF0);
    func_0038CE20(*(char **)(state + 0x10) + 0xC0, *(char **)(state + 0x10) + 0xC0, *(f32 *)(state + 0xC));
    func_0038CE20(*(char **)(state + 0x10) + 0xD0, *(char **)(state + 0x10) + 0xD0, *(f32 *)(state + 0xC));
    func_L01_0044E820(*(char **)(state + 0x10), func_0038DBD8(0x80FF8000, *(s32 *)(state + 0x30), *(f32 *)(state + 0xC)));
    func_003C7DD8(*(char **)(state + 0x10));
    objects = (char **)(state + 0x14);
    rot = state + 0x4C;
    pos = state + 0x40;
    i = 1;
    do { do {
        if (*objects) {
            if (*(void **)(*objects + 0x24)) {
                *(u16 *)(*objects + 0x34) &= 0xFFFE;
                {
                    u8 one = 1;
                    (*objects)[0x31] = one;
                    one = 0;
                }
                *(s32 *)(*objects + 0x98) = *(s32 *)(*(char **)(*objects + 0x24) + 0x10);
            }
            func_L01_0044E130(&offset, pos);
            func_0038D000(&offset, &offset, *(char **)(state + 0x10) + 0xC0);
            vec_add_ba(*objects + 0x10, *(char **)(state + 0x10) + 0x10, &offset);
            func_L01_0044E130(&angles, rot);
            func_0038D308(*objects + 0xC0, &angles);
            func_0038D5F0(*objects + 0xC0, *(char **)(state + 0x10) + 0xC0, *objects + 0xC0);
            func_L01_0044E820(*objects, func_0038DBD8(0x80FF8000, *(s32 *)((s32)state + (i << 2) + 0x30), *(f32 *)(state + 0xC)));
            func_003C7DD8(*objects);
        }
        pos += 4;
        rot += 4;
        objects++;
        i++;
    } while (i < 4); } while (0);
}
/* localdecomp:end func_L01_00340DC0 */
