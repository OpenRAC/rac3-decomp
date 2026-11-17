#include "common.h"

typedef struct {
    u8 pad[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_1A4BE0_0034CE78;

/* localdecomp:start func_L30_0034CF28 */
typedef int q_0034CF28 __attribute__((mode(TI)));


extern s32 D_L30_001DF2C0;
extern u8 D_L30_001F0140[];

extern int func_L30_0034D8D8(void *, float);
extern s32 func_L01_00424B88(void *, f32, s32, f32);
extern void func_L30_0034DAC0(void *);

void func_L30_0034CF28(void *pos, s32 *id, s32 color, f32 size, f32 f) {
    s32 n;
    u8 *e;

    if (D_L30_001DF2C0 < 5) {
        *id = -1;
        return;
    }
    if (func_L30_0034D8D8(pos, 1.05f) != 0) {
        n = *id;
        if (n == -1) {
            *id = func_L01_00424B88(pos, size, color, f);
            if (*id == n) {
                return;
            }
        }
        e = D_L30_001F0140 + *id * 32;
        *(q_0034CF28 *)(e + 0x10) = *(q_0034CF28 *)pos;
        *(f32 *)(e + 0x1C) = size;
        *(f32 *)(e + 0x0) = (color & 0xFF) * 0.0078125f;
        *(f32 *)(e + 0x4) = ((color >> 8) & 0xFF) * 0.0078125f;
        *(f32 *)(e + 0x8) = ((color >> 16) & 0xFF) * 0.0078125f;
    } else {
        func_L30_0034DAC0(id);
    }
}
/* localdecomp:end func_L30_0034CF28 */

LINKER_REMNANT("asm/levels", func_L30_0034D068);

INCLUDE_ASM("asm/levels", func_L30_0034D088);
