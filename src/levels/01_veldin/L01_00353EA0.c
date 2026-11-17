#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00353EA0);

/* localdecomp:start func_L01_00355D88 */
extern s32 func_L01_00356050(void *);
extern void func_L01_00356588(void *);
extern void func_L01_00356668(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L01_00452860(void *, void *, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 D_L01_001E2A40[];
extern s32 D_001DD61C_sda;
__asm__(".extern D_001DD61C_sda, 4");
s32 func_L01_00355D88(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L01_00356050(a0) != 0) return 1;
    }
    if (p[0x3e] == 2) goto L68;
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L01_001E2A40, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6f] = 0x16;
        }
    }
    if (*(s32 *)(p + 0x360) != 0) func_L01_0044FD88(a0, *(s32 *)(p + 0x360), 1, D_001DD61C_sda);
    func_L01_00452860(a0, p + 0x30, 0);
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) func_L01_00356668(a0);
    if (p[0x5e] != 0) {
L68:
        func_L01_00356588(a0);
        return 1;
    }
    if (p[0x5f] != 0) {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) func_L01_00456BD0(a0, 5);
        }
        if (a0[0x95] == 1) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E0), *(f32 *)(p + 0x2E4), p + 0x320, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E8), *(f32 *)(p + 0x2EC), p + 0x320, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
    } else {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) func_L01_00456BD0(a0, 3);
        }
        if (a0[0x95] == 1 || a0[0x95] == 4) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E0), *(f32 *)(p + 0x2E4), p + 0x320, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E8), *(f32 *)(p + 0x2EC), p + 0x320, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00355D88 */

INCLUDE_ASM("asm/levels", func_L01_00356050);

/* localdecomp:start func_L01_003564D0 */
typedef struct {
    void (*fn0)(void *);
    void (*fn1)(void *);
} Vt_003564D0;

extern void *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L01_003564D0(u8 *obj, s32 a1) {
    u8 *p = *(u8 **)(obj + 0x68);

    if (*(void **)(p + 0x360) != 0) {
        func_003C2880(*(void **)(p + 0x360));
        *(void **)(p + 0x360) = 0;
        *(s32 *)(p + 0x240) = 0;
    }
    if (*(s32 *)(p + 0x250) != 0) {
        Vt_003564D0 *t = func_L01_0043B548(6625, 108);
        t->fn0(obj);
        if (a1 != 0) {
            t->fn1(obj);
        }
    } else {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003564D0 */
