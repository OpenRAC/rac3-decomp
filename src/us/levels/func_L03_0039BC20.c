#include "common.h"

/* NTSC-U counterpart of func_L03_0039D380 (src/levels/03_starship_phoenix/L03_0039C888.c): 8 -> 10 */
extern s32 func_00382468();
extern void func_003C3A10();
extern void func_L01_00441FB8();
extern void func_L03_0039BC20();
extern void func_L03_0039BC20(void *, void *);
extern void func_003C3A10();
extern void func_L01_00441FB8();

/* localdecomp:start func_L03_0039BC20 */
#include "vu0.h"
typedef struct { u8 pad0[0x43]; u8 b43; } A_0039D380;
typedef struct { u8 pad0[0x58]; s32 f58; u8 pad5C[0x74]; vu0_v4 vD0; } P_0039D380;
void func_L03_0039BC20(void *arg, void *b) {
    A_0039D380 *a = arg;
    P_0039D380 *p = b;
    if (func_00382468(2) != 0) {
        if (a->b43 != 7) {
            func_003C3A10(a, 7, 0, 10);
        }
    } else if (a->b43 != 0) {
        func_003C3A10(a, 0, 0, 10);
    }
    p->f58 = 0;
    qzero(&p->vD0);
    func_L01_00441FB8(a, 1, -1);
}
/* localdecomp:end func_L03_0039BC20 */
