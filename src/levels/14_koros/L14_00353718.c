#include "common.h"

/* localdecomp:start func_L14_00353718 */
__asm__(".extern D_L14_001DD570, 4");
extern s32 D_L14_001DD570;
__asm__(".extern D_L14_001DD578, 4");
extern s32 D_L14_001DD578;
__asm__(".extern D_L14_001DD550, 4");
extern s32 D_L14_001DD550;
__asm__(".extern D_L14_001DD588, 4");
extern s32 D_L14_001DD588;
__asm__(".extern D_L14_001DD580, 4");
extern s32 D_L14_001DD580;
__asm__(".extern D_L14_001DD584, 4");
extern s32 D_L14_001DD584;
extern void func_L14_003AD768(void *);
void func_L14_00353718(u8 *a0) {
    s32 *s = *(s32 **)(a0 + 0x68);
    s32 x, y;
    if (a0[0x20] == 0) {
        a0[0x20] = 1;
        x = D_L14_001DD580;
        y = D_L14_001DD584;
        s[5] = (s32)&D_L14_001DD570;
        s[4] = (s32)&D_L14_001DD578;
        s[3] = 2;
        s[1] = (s32)&D_L14_001DD550;
        s[7] = y;
        s[2] = (s32)&D_L14_001DD588;
        s[6] = x;
        s[0] = 0;
        s[8] = x;
    }
    func_L14_003AD768(a0);
}
/* localdecomp:end func_L14_00353718 */

INCLUDE_ASM("asm/levels", func_L14_00353790);

INCLUDE_ASM("asm/levels", func_L14_00353910);

INCLUDE_ASM("asm/levels", func_L14_003539E0);

/* localdecomp:start func_L14_00353BC8 */
extern u8 D_L14_001D66B0;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L14_00353BC8(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 7, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00429840(a0, a0 + 0x10, 5, 0, &D_L14_001D66B0, 0x963C6428, 0, 0x7D, 2.0f, 10.0f, 1.5f, 2.0f);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00353BC8 */

/* localdecomp:start func_L14_00353CD0 */
extern u8 D_L14_001D66B0;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L14_00353CD0(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 7, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00429840(a0, a0 + 0x10, 5, 0, &D_L14_001D66B0, 0x963C6428, 0, 0x7D, 2.0f, 10.0f, 1.5f, 2.0f);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00353CD0 */

/* localdecomp:start func_L14_00353DD8 */
extern u8 D_L14_001D66B0;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L14_00353DD8(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 1, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00429840(a0, a0 + 0x10, 5, 0, &D_L14_001D66B0, 0x963C6428, 0, 0x7D, 2.0f, 10.0f, 1.5f, 2.0f);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00353DD8 */
