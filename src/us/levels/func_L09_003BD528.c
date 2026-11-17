#include "common.h"

/* NTSC-U counterpart of func_L09_003BEDA8 (src/levels/09_tyhrranosis/L09_003BE910.c) */
#include "vu0.h"
extern s32 func_003883C8(void *);
extern s32 func_003883C8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442050(u8 *, u8);

/* localdecomp:start func_L09_003BD528 */
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442050(u8 *, u8);
extern s32 func_003883C8(void *);
extern void func_L09_003BAF18(u8 *, s32, s32, s32, s32);
extern void func_L09_003BBCE8(u8 *, s32, s32, s32, s32);
extern void func_L09_003BC030(u8 *, s32, s32, s32);

s32 func_L09_003BD528(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (p[0xD42] & 1) {
        p[0xD42] &= ~1;
        func_L01_00441FB8(a0, 0xC, -1);
        func_L01_00442050(a0, 1);
    } else if (a4 != -1 && (*(s16 *)(p + 0xD34))++ >= (s32)((f32)a4 * 60.0f)) {
        func_L09_003BAF18(a0, a1, a2, a3, 0);
        func_L01_00441FB8(a0, 0xF, -1);
        func_L01_00442050(a0, 1);
    } else if (func_003883C8(p + 0xD38) != 0) {
        func_L09_003BAF18(a0, a1, a2, a3, 0);
    } else if (p[0xD42] & 2) {
        func_L09_003BBCE8(a0, a1, a2, a3, 0);
    } else {
        func_L09_003BC030(a0, a1, a2, a3);
    }
    return 1;
}
/* localdecomp:end func_L09_003BD528 */
