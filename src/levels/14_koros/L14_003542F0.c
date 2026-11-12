#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad_00[0xAA];
    s16 f_AA;
} S_L14_00354B90;

INCLUDE_ASM("asm/levels", func_L14_003542F0);

INCLUDE_ASM("asm/levels", func_L14_00354538);

INCLUDE_ASM("asm/levels", func_L14_003547F8);

/* localdecomp:start func_L14_00354B90 */
extern s32 D_L14_001DBC20;
extern u8 D_L14_002856A0[];
extern void func_L01_00450DE8(void *, f32, f32, f32, void *);
extern void func_L14_003F81B8(void *, void *);

void func_L14_00354B90(S_L14_00354B90 *p) {
    u8 buf[16];

    D_L14_001DBC20 |= 1;
    if (p->f_AA != 0x1690) {
        func_L01_00450DE8(p, 0.0f, -4.0f, 5.7f, buf);
    } else {
        func_L01_00450DE8(p, 0.0f, 3.6f, 5.5f, buf);
    }
    func_L14_003F81B8(D_L14_002856A0, buf);
}
/* localdecomp:end func_L14_00354B90 */

/* localdecomp:start func_L14_00354C28 */
extern u8 D_L14_001D66B0;
extern s32 D_L14_001D67B8;
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L01_00459C50(s32);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
void func_L14_00354C28(void *a0) {
    vu0_v4 v10;
    vu0_v4 v20;
    s32 i;
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0xFFF, &D_L14_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        qzero(&v10);
        qzero(&v20);
        for (i = 0; i < 7; i++) {
            func_003C2F58(a0, i, &v20);
            func_L02_003E2E38(a0, &v20, 2.0f, &v10, 10, 0, 0.040000003f, 1.5f, 3.0f, 2.0f, 0);
        }
        D_L14_001D67B8 = D_L14_001D67B8 + 1;
        if (D_L14_001D67B8 >= 100) {
            func_L01_00459C50(0x11);
        }
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_00354C28 */
