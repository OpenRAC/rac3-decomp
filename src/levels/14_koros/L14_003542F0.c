#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L14_00354C28);
