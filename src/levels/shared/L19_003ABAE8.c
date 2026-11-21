#include "common.h"

/* localdecomp:start func_L19_003ABAE8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x68];
    u8 *p68;
    u8 pad6C[0x78 - 0x6C];
    s32 w78;
    u8 pad7C[0x96 - 0x7C];
    u16 h96;
} S_003ABAE8;
extern s32 func_0038CAD0(void *);

void func_L19_003ABAE8(S_003ABAE8 *m) {
    u8 *p = m->p68;
    f32 a;
    f32 b;
    s32 r;
    s32 g;

    if (m->h96 < 0xFFFF) {
        m->h96++;
    }
    func_0038CAD0(p + 0x27C);
    if (*(s32 *)(p + 0x240) != 0) {
        a = fabs_asm(0.75f - (f32)(s32)(m->h96 % 60) / 40.0f) + 0.25f;
        b = a - 0.25f;
        r = a * 127.0f;
        g = b * 32.0f;
        m->w78 = 0x7F000000 | (g << 16) | (g << 8) | r;
    } else {
        m->w78 = 0x7F000020;
    }
}
/* localdecomp:end func_L19_003ABAE8 */

INCLUDE_ASM("asm/levels", func_L19_003ABBD8);
