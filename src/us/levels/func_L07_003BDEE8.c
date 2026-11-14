#include "common.h"

/* NTSC-U counterpart of func_L07_003BF838 (src/levels/07_annihilation_nation/L07_003BEAC0.c): 0.036 -> 0.03; 0.18 -> 0.15 */
/* localdecomp:start func_L07_003BDEE8 */
typedef struct {
    u8 pad0[0x10];
    f32 f10;
} S_003BF838;

extern void func_L01_00402498(void (*)(void *), void *);
void func_L07_003BDF58(void *);

void func_L07_003BDEE8(u8 *arg0) {
    S_003BF838 *p = *(S_003BF838 **)(arg0 + 0x68);
    f32 t = p->f10 + 0.0299999993f;

    p->f10 = t;
    if (t > 1.0f) {
        p->f10 = t - 0.150000006f;
    }
    func_L01_00402498(func_L07_003BDF58, arg0);
}
/* localdecomp:end func_L07_003BDEE8 */
