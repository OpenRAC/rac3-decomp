#include "common.h"

typedef struct Obj_004CE458 Obj_004CE458;
typedef struct {
    u8 pad[8];
    void (*fn8)(Obj_004CE458 *);
} Vt_004CE458;
struct Obj_004CE458 {
    u8 pad[36];
    Vt_004CE458 *vt;
    u8 pad2[20];
};

/* localdecomp:start func_L01_004D23E8 */
extern void func_L01_004D2470(void *p, s32 i);
extern s32 D_001D545C[];
extern void func_L01_004D0E90(u8 *, s32);
extern void func_003ACBC0(u8 *);

void func_L01_004D23E8(u8 *m) {
    s32 i;

    if (D_001D545C[0] != -2) {
        for (i = 0; i < 1; i++) {
            func_L01_004D0E90(m + 6304 + i * 2896, i);
            ((void (*)(u8 *, s32))func_L01_004D2470)(m, i);
        }
        func_003ACBC0(m + 20176);
    }
}
/* localdecomp:end func_L01_004D23E8 */

INCLUDE_ASM("asm/levels", func_L01_004D2470);

INCLUDE_ASM("asm/levels", func_L01_004D2498);
