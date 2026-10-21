#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_00357570);

INCLUDE_ASM("asm/levels", func_L30_00357B88);

INCLUDE_ASM("asm/levels", func_L30_00357C78);

INCLUDE_ASM("asm/levels", func_L30_00357DD8);

INCLUDE_ASM("asm/levels", func_L30_00357ED8);

INCLUDE_ASM("asm/levels", func_L30_00357F90);

INCLUDE_ASM("asm/levels", func_L30_003580F8);

LINKER_REMNANT("asm/levels", func_L30_00358170);

INCLUDE_ASM("asm/levels", func_L30_00358180);

/* localdecomp:start func_L30_00358210 */
extern void func_L30_004CF4B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L30_00358210(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    *(s32 *)(v + 220) = 0;
    *(s32 *)(v + 216) = 0;
    func_L30_004CF4B0(154, 1);
    func_L01_004450F0(a0, 6, -1);
}
/* localdecomp:end func_L30_00358210 */

/* localdecomp:start func_L30_00358258 */
extern s32 D_L30_001DDAA4;

void func_L30_00358258(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 t = D_L30_001DDAA4;
    s32 cur = *(s32 *)(p + 220);
    f32 fc = cur;
    s32 end = *(s32 *)(p + 216);

    if (cur < t) {
        *(f32 *)(p + 208) = fc / t;
        return;
    }
    if (end - t < cur) {
        *(f32 *)(p + 208) = (f32)(cur - end) / (f32)(-t);
        return;
    }
    *(f32 *)(p + 208) = 1.0f;
}
/* localdecomp:end func_L30_00358258 */

/* localdecomp:start func_L30_003582E0 */
typedef struct {
    u16 x0;
    u8 pad[10];
} S_1A7E18;

extern S_1A7E18 D_001A7E18[];
extern s32 func_L01_0041A5B0(void *, s32);
extern void func_L01_0041BE28(void *, s32);

void func_L30_003582E0(void *a, s32 i) {
    S_1A7E18 *p = &D_001A7E18[i];

    if (p->x0 == 0) {
        if (func_L01_0041A5B0(a, i) == 0) {
            func_L01_0041BE28(a, i);
        }
        if (p->x0 == 0) {
            p->x0 = 1;
        }
    }
}
/* localdecomp:end func_L30_003582E0 */

INCLUDE_ASM("asm/levels", func_L30_00358360);

LINKER_REMNANT("asm/levels", func_L30_00358370);

INCLUDE_ASM("asm/levels", func_L30_00358380);
