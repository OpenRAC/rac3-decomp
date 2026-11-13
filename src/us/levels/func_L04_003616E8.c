#include "common.h"

/* NTSC-U counterpart of func_L04_003626F0 (src/levels/shared/L04_00362568.c): 0.0432 -> 0.03; 0.432 -> 0.3 */
typedef struct { u8 pad0[0x98]; s32 f98; } Slot_3626F0;

/* localdecomp:start func_L04_003616E8 */
extern void func_0038CAD0(void *p);
extern void func_0038CB00(void *p);
extern void func_003C7C38(void *p);
extern void func_L01_0044EB78(void *a, void *b, s32 c, s32 d, f32 e);
extern void func_L01_0044B5C8(void *a, void *b, s32 c, f32 d, f32 e);

void func_L04_003616E8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    Slot_3626F0 **p = (Slot_3626F0 **)(s + 0x4B0);
    s32 i;
    func_0038CAD0(s + 0x2F0);
    func_0038CB00(s + 0x2F4);
    for (i = 7; i >= 0; i--) {
        if (*p != 0) {
            (*p)->f98 = 0;
            func_003C7C38(*p);
        }
        p++;
    }
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_0044EB78(a0, s + 0x260, 2, 1, 2.5f);
    func_L01_0044B5C8(a0, s + 0x390, 1, 0.0299999993f, 0.300000012f);
}
/* localdecomp:end func_L04_003616E8 */
