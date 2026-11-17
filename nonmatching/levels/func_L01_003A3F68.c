#include "common.h"
/* localdecomp:start func_L01_003A3F68 */
extern s32 D_001D545C;
extern s32 D_L01_001D67AC;
extern s32 D_L01_001D67B4;
extern s32 D_L01_001D67C0;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_00142758[];
void func_L01_003A3F68(u8 *obj) {
    extern void func_L01_00459C50(s32);
    extern void func_L01_00452310(void *, f32, f32, s32, f32, void *, s32, s32, f32, f32, s32, f32, f32, s32, s32);
    extern void func_L01_004443E8(void *, s32, s32);
    extern void func_0039EF28(void);
    extern void func_003A52A0(s32, s32, u8 *);
    u8 *v = *(u8 **)(obj + 0x68);
    s16 h;
    if (D_001D545C == 4 && *(u8 **)(v + 0x48) != 0 &&
        (*(s16 *)(*(u8 **)(v + 0x48) + 0xAA) == 0x185E || *(s16 *)(*(u8 **)(v + 0x48) + 0xAA) == 0x11C1)) {
        D_00142758[0] = 1;
        func_0039EF28();
        if (++D_L01_001D67AC >= 25) func_L01_00459C50(6);
    } else if (D_001D545C == 12 && *(u8 **)(v + 0x48) != 0 && v[0x47] == 9) {
        if (++D_L01_001D67B4 >= 20) func_L01_00459C50(15);
    } else if (D_001D545C == 18 && *(u8 **)(v + 0x48) != 0 &&
               (*(s16 *)(*(u8 **)(v + 0x48) + 0xAA) == 0x185E || *(s16 *)(*(u8 **)(v + 0x48) + 0xAA) == 0x11C1)) {
        if (++D_L01_001D67C0 >= 20) func_L01_00459C50(21);
    }
    if (v[0x5E] == 0) {
        func_003A52A0(11, 0, obj);
        h = *(s16 *)(obj + 0xAA);
        if (D_001D545C == 1 && *(s32 *)(v + 0x42C) != 0 && *(s32 *)(v + 0x3C0) != 0) {
            *(s16 *)(obj + 0xAA) = 0x1F02;
        }
        func_L01_00452310(obj, 0.75f, 3.0f, 0x7FFF, 6.0f, D_L01_001D66B0, 1, 20, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
        if (D_001D545C == 1 && *(s32 *)(v + 0x42C) != 0 && *(s32 *)(v + 0x3C0) != 0) {
            *(s16 *)(obj + 0xAA) = h;
        }
    }
    func_L01_004443E8(obj, 0, 3);
}
/* localdecomp:end func_L01_003A3F68 */
