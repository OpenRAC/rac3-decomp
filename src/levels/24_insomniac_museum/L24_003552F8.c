#include "common.h"

/* localdecomp:start func_L24_003552F8 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00446BC8(u8 *, u8 *, s32, u8 *, f32);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern void func_L01_004472C0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern u8 D_L24_001E2200[];

void func_L24_003552F8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *p;

    func_0038CAD0(s + 0x2D0);
    func_0038CB00(s + 0x2D4);
    if (*(u16 *)(obj + 0x96) <= 0xFFFE) {
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    }
    if (*(s32 *)(s + 0xF0) >= 0x1A) {
        p = *(u8 **)(s + 0xF4);
        if (p != 0) {
            if (*(s16 *)(p + 0xAA) == 0x1F4) {
                func_L01_00446BC8(p, obj, 0x10000, p + 0x10, 10.0f);
            }
        }
    }
    func_L01_00451DF8(obj, s + 0x240, 2, 1, 2.5f);
    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_L24_001E2200, obj + 0x10) < 576.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L24_003552F8 */
