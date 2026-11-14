#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_003A97D8);

/* localdecomp:start func_L24_003A9A48 */
extern s32 D_L24_001DF0C0;
extern s32 D_L24_001DE438;
extern f32 D_L24_001DE444;
extern s32 D_L24_001DE430;
extern s32 D_L24_001DE434;
extern f32 D_L24_001DE460;
__asm__(".extern D_L24_001DE438, 4");
__asm__(".extern D_L24_001DE444, 4");
__asm__(".extern D_L24_001DE430, 4");
__asm__(".extern D_L24_001DE434, 4");
__asm__(".extern D_L24_001DE460, 4");
extern void func_003C2880(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);

typedef struct {
    u8 pad0[4];
    u8 *e[4];
    s32 t[4];
    f32 f[4];
    u8 pad34[0xC];
    f32 f40;
    u8 pad44[8];
    s32 w4C;
} S_003A9A48;

void func_L24_003A9A48(u8 *a0)
{
    S_003A9A48 *q = *(S_003A9A48 **)(a0 + 0x68);
    s32 i;
    f32 t;
    u32 c;

    for (i = 0; i < 4; i++) {
        if (q->e[i] != 0) {
            t = (f32)(D_L24_001DF0C0 - q->t[i]) / (f32)D_L24_001DE438;
            if (t > 1.0f) {
                func_003C2880(q->e[i]);
                q->e[i] = 0;
            } else {
                q->e[i][0x23] = D_L24_001DE444 * (1.0f - q->f40) * (1.0f - t);
                c = func_0038DBD8(D_L24_001DE430, D_L24_001DE434, q->f[i]);
                c = func_0038DBD8(q->w4C, c, q->f40 * t);
                func_L01_0043B9E8(q->e[i], c & 0xFF, (c & 0xFF00) >> 8, (c >> 16) & 0xFF);
                func_0038D308(q->e[i] + 0xC0, a0 + 0xF0);
                if (!(i & 1)) {
                    func_0038CE20(q->e[i] + 0xC0, q->e[i] + 0xC0, 1.0f - q->f40 * t);
                    func_0038CE20(q->e[i] + 0xE0, q->e[i] + 0xE0, q->f40 * D_L24_001DE460 * t + 1.0f);
                } else {
                    func_0038CE20(q->e[i] + 0xE0, q->e[i] + 0xE0, 1.0f - q->f40 * t);
                    func_0038CE20(q->e[i] + 0xC0, q->e[i] + 0xC0, q->f40 * D_L24_001DE460 * t + 1.0f);
                }
            }
        }
    }
}
/* localdecomp:end func_L24_003A9A48 */

INCLUDE_ASM("asm/levels", func_L24_003A9C10);

INCLUDE_ASM("asm/levels", func_L24_003A9E20);

INCLUDE_ASM("asm/levels", func_L24_003AA000);
