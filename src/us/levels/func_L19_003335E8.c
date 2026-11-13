#include "common.h"

/* NTSC-U counterpart of func_L19_00333FC0 (src/levels/shared/L19_00331380.c): 0.0432 -> 0.03; 0.432 -> 0.3 */
extern s32 func_0038CAD0(void *);

/* localdecomp:start func_L19_003335E8 */
extern void func_L01_004479A8(void *a, void *b);
extern s32 func_0038CAD0(void *a);
extern void func_L19_003336C8(void *a);
extern void func_L01_0044B5C8(void *a, void *b, s32 c, f32 d, f32 e);
extern u8 D_001D5470;
__asm__(".extern D_001D5470, 16");

void func_L19_003335E8(u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    func_L01_004479A8(obj, st + 0x70);
    if (*(u16 *)(obj + 0x96) < 0xFFFF) {
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    }
    func_0038CAD0(st + 0x360);
    func_L19_003336C8(obj);
    if (D_001D5470 != 0 && obj[0x20] != 1) {
        *(f32 *)(st + 0x2A0) = 1.75f;
    }
    func_L01_0044B5C8(obj, st + 0x230, 1, 0.0299999993f, 0.300000012f);
    func_L01_0044B5C8(obj, st + 0x2B0, 0, 0.0299999993f, 0.300000012f);
}
/* localdecomp:end func_L19_003335E8 */
