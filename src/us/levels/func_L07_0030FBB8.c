#include "common.h"

/* localdecomp:start func_L07_0030FBB8 */
extern s32 func_L07_0040C3A0(void *);
extern void func_L07_00436AE0(void *);
extern void func_L07_004039F8(void *, void *);
extern void func_L07_004A5C50(s32, void *);
extern void func_L07_0030FDF0(void *, void *);
extern u8 D_L07_003101E8[];

void func_L07_0030FBB8(void *object) {
    u8 *state = *(u8 **)((u8 *)object + 0x68);
    *(f32 *)(state + 0x78) = *(f32 *)(state + 0x78) + 1.0f;
    if (*(s32 *)(state + 0x74) != 0 && func_L07_0040C3A0(state + 0x74) != 0) {
        func_L07_004A5C50(0x10, object);
        func_L07_00436AE0(object);
        return;
    }
    if (*(f32 *)(state + 0x78) > 120.0f && *(s32 *)(state + 0x74) == 0) {
        *(s32 *)(state + 0x74) = 0xF;
    } else {
        func_L07_0030FDF0(object, state);
    }
    func_L07_004039F8(D_L07_003101E8, object);
}
/* localdecomp:end func_L07_0030FBB8 */
