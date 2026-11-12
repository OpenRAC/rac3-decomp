#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_0032ADD0);

/* localdecomp:start func_L05_0032B230 */
void func_L01_004450F0(s32, s32, s32);
void func_L05_0032B230(void *arg0) {
    s32 var_a1;
    s8 *var_v1;
    void *temp_a2;

    temp_a2 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        var_a1 = 5;
        var_v1 = temp_a2 + 0x1F;
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 0x100);
        do {
            *var_v1 = 0;
            var_a1 -= 1;
            var_v1 -= 1;
        } while (var_a1 >= 0);
        *(s8 *)((u8 *)temp_a2 + 0x18) = 0x1F;
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L05_0032B230 */

/* localdecomp:start func_L05_0032B290 */
typedef int Q_32B290 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32B290;
extern void func_0038D890(void *, void *, void *, f32);

void func_L05_0032B290(u8 *a0, u8 *obj, V4_32B290 *v, f32 angle) {
    u8 *axis = *(u8 **)(a0 + 0x68) + 0x30;
    Q_32B290 x, y, r;
    func_0038D890(obj + 0xC0, obj + 0xC0, axis, angle);
    func_0038D890(obj + 0xD0, obj + 0xD0, axis, angle);
    func_0038D890(obj + 0xE0, obj + 0xE0, axis, angle);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*v));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_32B290 *)(obj + 0x10)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_32B290 *)(obj + 0x10)) : "j"(r));
}
/* localdecomp:end func_L05_0032B290 */

/* localdecomp:start func_L05_0032B320 */
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
s32 func_L05_0032B3B8(s32);

void func_L05_0032B320(u8 *a0, s32 a1, s32 a2) {
    u8 *p;
    u8 *q;
    u8 b;

    p = *(u8 **)(a0 + 0x68);
    b = *(p + a2 + 0x1A);
    if (b >= 3) {
        p[0x19] |= 1 << a2;
    } else {
        if (b == 0) {
            func_L01_004AAC98(0, 0, a1, *(s16 *)(a0 + 0xAA));
        }
        func_L05_0032B3B8(a1);
    }
    q = p + 0x1A;
    q[a2] += 1;
}
/* localdecomp:end func_L05_0032B320 */

INCLUDE_ASM("asm/levels", func_L05_0032B3B8);

INCLUDE_ASM("asm/levels", func_L05_0032B630);
