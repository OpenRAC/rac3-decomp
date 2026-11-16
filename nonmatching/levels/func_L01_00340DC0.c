/* PAL near miss (Codex wave 8): near miss: 109 words differ with the file's flags.
 * Worker's note: 110 diff: extra s7 constant-one register/frame save, loop strength reduction and pointer allocation. Indexed/struct/do-while/inline variants did not improve. Best log w424/func_L01_00340DC0.try02.log
 */
#include "common.h"

/* localdecomp:start func_L01_00340DC0 */
#include "vu0.h"
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
    pos = state + 0x40;
    rot = state + 0x4C;
    for (i = 1; i < 4; i++) {
        if (*objects) {
            if (*(void **)(*objects + 0x24)) {
                *(u16 *)(*objects + 0x34) &= 0xFFFE;
                (*objects)[0x31] = 1;
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
    }
}
/* localdecomp:end func_L01_00340DC0 */
