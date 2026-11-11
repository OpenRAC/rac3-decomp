#include "common.h"

/* localdecomp:start func_L22_003BCF38 */
extern f32 func_0038D0B0(f32);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
void func_L22_003BCF38(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    s32 t;
    f32 s;
    if (*(s32 *)(st + 0x178) > 0) {
        t = *(s32 *)(st + 0x170) + 1;
        *(s32 *)(st + 0x170) = t;
        if (t >= 0x19) {
            *(s32 *)(st + 0x178) = -1;
        }
    } else {
        t = *(s32 *)(st + 0x170) - 1;
        *(s32 *)(st + 0x170) = t;
        if (t <= 0) {
            *(s32 *)(st + 0x178) = 1;
        }
    }
    s = func_0038D0B0((f32)*(s32 *)(st + 0x170) * 3.14159274f / 60.0f);
    func_0038AE20(0x7F, 0, 0, (s32)(s * 0.85000002f * 16.0f));
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L22_003BCF38 */

INCLUDE_ASM("asm/levels", func_L22_003BCFF8);

/* localdecomp:start func_L22_003BD410 */
void func_0038CB78(void *, s32, s32);
void func_003C2F58(void *, s32, void *);
void func_L01_004513A8(s32, void *, s32);
extern f32 D_L22_001DE6C0;
__asm__(".extern D_L22_001DE6C0, 4");

void func_L22_003BD410(void *arg0) {
    s32 temp_a0;
    void *temp_s1;

    temp_a0 = arg0 + 0x10;
    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    *(s32 *)((u8 *)temp_s1 + 0x130) = 0;
    func_L01_004513A8(temp_a0, arg0, temp_a0);
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 0x4000);
    func_003C2F58(arg0, 1, temp_s1 + 0x160);
    *(f32 *)((u8 *)temp_s1 + 0x168) = (f32) ((*(f32 *)((u8 *)temp_s1 + 0x168)) + D_L22_001DE6C0);
    func_0038CB78(temp_s1 + 0x30, 0, 0x80);
    func_0038CB78(temp_s1 + 0xB0, 0, 0x80);
}
/* localdecomp:end func_L22_003BD410 */
