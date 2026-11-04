#include "common.h"

typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Vt_003E54F8;

/* localdecomp:start func_L26_003E5178 */
s32 func_L26_003E5218(s32, s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
s32 func_L26_003E5330(void *, s32);
extern u8 D_L26_001E2840[];

void func_L26_003E5178(void *arg0) {
    s32 temp_s1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if ((((*(u8 *)((u8 *)arg0 + 0x20)) != 0) || (func_L26_003E5218((s32) arg0, temp_s1) != 0)) && (func_L26_003E5330(arg0, temp_s1) != 0) && ((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L26_001E2840, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
}
/* localdecomp:end func_L26_003E5178 */

INCLUDE_ASM("asm/levels", func_L26_003E5218);

INCLUDE_ASM("asm/levels", func_L26_003E5330);

/* localdecomp:start func_L26_003E54F8 */
extern Vt_003E54F8 *func_L01_0043B548(s32 a0, s32 a1);
extern void func_003C2880(u8 *a0);

void func_L26_003E54F8(u8 *arg0, s32 arg1) {
    Vt_003E54F8 *vt;
    if (*(s32 *)(*(u8 **)(arg0 + 104) + 304) != 0) {
        vt = func_L01_0043B548(6625, 108);
        vt->f0(arg0);
        if (arg1 != 0) {
            vt->f4(arg0);
        }
    } else {
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L26_003E54F8 */

/* localdecomp:start func_L26_003E5578 */
s32 func_00382498(s32, s32);
void func_003C3A10(s32, s32, s32, s32);

void func_L26_003E5578(s32 arg0) {
    func_003C3A10(arg0, 0, func_00382498(0, 6), 0);
}
/* localdecomp:end func_L26_003E5578 */
