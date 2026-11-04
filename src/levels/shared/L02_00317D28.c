#include "common.h"

typedef struct { u8 p0[0x23]; u8 f23; u8 p24[0x10]; u16 f34; } E_00318E78;

INCLUDE_ASM("asm/levels", func_L02_00317D28);

INCLUDE_ASM("asm/levels", func_L02_00318910);

/* localdecomp:start func_L02_003189D8 */
typedef struct { u8 p0[0x2C]; f32 f2C; } V_318528;
typedef struct { u8 p0[0x68]; V_318528 *v; } M_318528;
extern f32 D_L02_001DE2D0;
void func_L02_003189D8(M_318528 *m) {
    f32 f = m->v->f2C;
    if (f > 1.0f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    D_L02_001DE2D0 = 1.0f - f;
}
/* localdecomp:end func_L02_003189D8 */

INCLUDE_ASM("asm/levels", func_L02_00318A28);

INCLUDE_ASM("asm/levels", func_L02_00318CA8);

/* localdecomp:start func_L02_00318E78 */
extern u8 D_001A4BE0[];

void func_L02_00318E78(void) {
    u8 *base = D_001A4BE0;
    s32 p;
    s32 end;
    s32 c;

    (*(E_00318E78 **)(base + 0x25C0))->f23 = 0x7F;
    (*(E_00318E78 **)(base + 0x25C0))->f34 &= 0xDFFF;
    c = 0x7F;
    p = (s32)base;
    end = (s32)base + 0x230;
    do {
        if (*(E_00318E78 **)(p + 0x1200) != 0) {
            (*(E_00318E78 **)(p + 0x1200))->f23 = c;
            (*(E_00318E78 **)(p + 0x1200))->f34 &= 0xDFFF;
        }
        if (*(E_00318E78 **)(p + 0x1204) != 0) {
            (*(E_00318E78 **)(p + 0x1204))->f23 = c;
            (*(E_00318E78 **)(p + 0x1204))->f34 &= 0xDFFF;
        }
        if (*(E_00318E78 **)(p + 0x1208) != 0) {
            (*(E_00318E78 **)(p + 0x1208))->f23 = c;
            (*(E_00318E78 **)(p + 0x1208))->f34 &= 0xDFFF;
        }
        p += 0x50;
    } while (p < end);
}
/* localdecomp:end func_L02_00318E78 */

INCLUDE_ASM("asm/levels", func_L02_00318F28);

INCLUDE_ASM("asm/levels", func_L02_00319BB0);
