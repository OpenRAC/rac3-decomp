#include "common.h"

/* localdecomp:start func_L09_00317798 */
s32 func_L01_00517918(s32);

void func_L09_00317798(void) {
    func_L01_00517918(0x15);
}
/* localdecomp:end func_L09_00317798 */

/* localdecomp:start func_L09_003177B8 */
typedef struct Fn_003177B8 {
    u8 pad0[0x40];
    s32 (*f40)(void *);
    u8 pad44[4];
    s32 (*f48)(void *);
} Fn_003177B8;
extern u8 *D_L09_001E009C;
extern s32 D_001A71A4[];
extern s32 D_L09_001DFDB4[2];
extern s32 D_L09_001DF9DC;
extern u8 D_L09_001E1660[];
__asm__(".extern D_L09_001E009C, 16");
__asm__(".extern D_L09_001DFDB4, 16");
__asm__(".extern D_L09_001DF9DC, 16");
extern Fn_003177B8 *func_L01_0043B568(s32, s32, s32);
extern void *func_003E6C08();
extern s32 func_L01_00515C78(void *, void *);
extern void func_L09_00317D00(void);

void func_L09_003177B8(void *a0, void *a1) {
    u8 *row = D_L09_001E009C + (*(s32 *)((u8 *)a1 + 0x60) << 8);
    Fn_003177B8 *fn = func_L01_0043B568(0x1ADD, 0, 0x68);
    if (fn->f48(row) == 0) return;
    if (fn->f40(row) == 0) return;
    if (D_001A71A4[0] == 0x74) return;
    if (D_001A71A4[0] == 0x65) return;
    if (D_L09_001DFDB4[1] != 0) return;
    if (D_L09_001DF9DC != 0) return;
    {
        void *x = D_L09_001E1660;
        if (*(s32 *)((u8 *)x + 0x4) == 0) {
            x = func_003E6C08();
        }
        func_L01_00515C78(x, func_L09_00317D00);
    }
}
/* localdecomp:end func_L09_003177B8 */

INCLUDE_ASM("asm/levels", func_L09_00317890);

INCLUDE_ASM("asm/levels", func_L09_00317B20);

INCLUDE_ASM("asm/levels", func_L09_00317D00);
