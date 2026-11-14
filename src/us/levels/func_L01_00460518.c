#include "common.h"

/* localdecomp:start func_L01_00460518 */
extern s32 func_00388398(void *);
extern void func_003C7CE0(u8 *);
extern void func_L01_004C6EC8(void *, void *);

void func_L01_00460518(u8 *p) {
    s32 life;
    u8 *v = p + 0x20;

    if (func_00388398(v) != 0) {
        func_003C7CE0(p);
        return;
    }
    func_L01_004C6EC8(p + 0x10, p + 0x10);
    life = *(s32 *)(p + 0x20);
    *(f32 *)(p + 0xC) = *(f32 *)(p + 0xC) + *(f32 *)(v + 4);
    if (life < 6) {
        *(u32 *)(p + 4) = (*(u32 *)(p + 4) & 0xFFFFFF) | (((life * 127) / 6) << 24);
    }
}
/* localdecomp:end func_L01_00460518 */
