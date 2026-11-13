#include "common.h"

/* NTSC-U counterpart of func_L03_003CFB90 (src/levels/03_starship_phoenix/L03_003CF7B0.c): 0.00392 -> 0.00272222; 0.0512 -> 0.0355556; 0.16 -> 0.133333; 0.0150796 -> 0.010472; 0.335103 -> 0.279253 */
extern void func_L03_003CDB60(u8 *);

/* localdecomp:start func_L03_003CDB60 */
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00474678(void *);

void func_L03_003CDB60(u8 *a0) {
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
    *(f32 *)(obj + 0x5C) = 0.00272222236f;
    func_L01_00458A70(a0, 0.0355555564f, 0.13333334f, 0.0104719754f, 0.279252708f);
    *(s32 *)(obj + 0x2CC) = 1;
    p = (void **)(obj + 0x2A0);
    i = 1;
    do {
        i--;
        func_L01_00474678(*p);
        p++;
    } while (i >= 0);
}
/* localdecomp:end func_L03_003CDB60 */
