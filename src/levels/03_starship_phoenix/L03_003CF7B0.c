#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003CF7B0);

/* localdecomp:start func_L03_003CFAE8 */
extern s32 func_0038CAD0(void *);
extern void *func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern s32 D_001A71A4[];

void func_L03_003CFAE8(u8 *a0) {
    u8 *obj = *(u8 **)(a0 + 0x68);
    void *r;

    if (func_0038CAD0(obj + 0x2D0) != 0) {
        s32 flag;
        r = func_L01_00447490(a0, 0x10000, 0);
        flag = 0;
        if (r != 0) {
            void *q = *(void **)((u8 *)r + 0x20);
            if (q != 0 && *(s16 *)((u8 *)q + 0xAA) == 0x47) {
                flag = D_001A71A4[0] != 0x15;
            }
        }
        *(s32 *)(obj + 0x2D4) = flag;
        if (r != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
    }
    *(u8 *)(a0 + 0xA8) = 0xFF;
    func_L01_0044ABD0(a0, obj + 0x290);
}
/* localdecomp:end func_L03_003CFAE8 */

/* localdecomp:start func_L03_003CFB90 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_00477ED0(void *);

void func_L03_003CFB90(u8 *a0) {
    u8 *obj = *(u8 **)(a0 + 0x68);
    void **p;
    s32 i;

    *(s32 *)(obj + 0x68) |= 0x90;
    *(f32 *)(obj + 0x30) = 0.3f;
    *(f32 *)(obj + 0x38) = 0.8f;
    *(f32 *)(obj + 0x34) = 0.3f;
    *(f32 *)(obj + 0x64) = 0.2f;
    *(f32 *)(obj + 0x3C) = 0.8f;
    *(f32 *)(obj + 0x40) = 1.4835298f;
    *(f32 *)(obj + 0x60) = 0.08726646f;
    *(f32 *)(obj + 0x5C) = 0.00392f;
    func_L01_0045BD78(a0, 0.051200002f, 0.16000001f, 0.015079645f, 0.33510324f);
    *(s32 *)(obj + 0x2CC) = 1;
    p = (void **)(obj + 0x2A0);
    i = 1;
    do {
        i--;
        func_L01_00477ED0(*p);
        p++;
    } while (i >= 0);
}
/* localdecomp:end func_L03_003CFB90 */
