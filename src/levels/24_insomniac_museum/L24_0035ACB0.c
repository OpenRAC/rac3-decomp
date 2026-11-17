#include "common.h"

/* declared by functions of L24_0035AB58.c, which this file was cut from */
s32 func_L24_0035ACB0(void *, s32, s32);
void func_L24_0035ABD0_0035ABD0(void *arg0, s32 arg1) __asm__("func_L24_0035ABD0");

/* localdecomp:start func_L24_0035ACB0 */
#include "vu0.h"
extern u8 D_001A30B0[];
extern f32 D_L24_001DD5D8, D_L24_001DD5DC, D_L24_001DD5E0, D_L24_001DD5E4, D_L24_001DD5E8;
extern f32 D_L24_001DD5F0[] __attribute__((section(".sdata")));
extern f32 D_L24_001DD5F4, D_L24_001DD5F8, D_L24_001DD5FC, D_L24_001DD600, D_L24_001DD604;
extern f32 D_L24_001DD610, D_L24_001DD614, D_L24_001DD618, D_L24_001DD61C, D_L24_001DD620, D_L24_001DD624;
extern f32 D_L24_001DD628, D_L24_001DD62C;
__asm__(".extern D_L24_001DD5D8, 4");
__asm__(".extern D_L24_001DD5DC, 4");
__asm__(".extern D_L24_001DD5E0, 4");
__asm__(".extern D_L24_001DD5E4, 4");
__asm__(".extern D_L24_001DD5E8, 4");
__asm__(".extern D_L24_001DD5F0, 4");
__asm__(".extern D_L24_001DD5F4, 4");
__asm__(".extern D_L24_001DD5F8, 4");
__asm__(".extern D_L24_001DD5FC, 4");
__asm__(".extern D_L24_001DD600, 4");
__asm__(".extern D_L24_001DD604, 4");
__asm__(".extern D_L24_001DD610, 4");
__asm__(".extern D_L24_001DD614, 4");
__asm__(".extern D_L24_001DD618, 4");
__asm__(".extern D_L24_001DD61C, 4");
__asm__(".extern D_L24_001DD620, 4");
__asm__(".extern D_L24_001DD624, 4");
__asm__(".extern D_L24_001DD628, 4");
__asm__(".extern D_L24_001DD62C, 4");
extern void func_L24_003A53E8(void *, f32, f32, f32, f32, f32, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L24_0035A550(void *, f32);
extern void func_003C3A10(void *, s32, s32, s32);

typedef struct {
    u8 pad0[0x150];
    vu0_v4 v150;
    vu0_v4 v160;
    vu0_v4 v170;
    u8 pad180[0x198 - 0x180];
    u8 b198;
    u8 pad199[0x1BC - 0x199];
    f32 f1BC;
    u8 spring[0x228 - 0x1C0];
    s32 sound;
} S_0035ACB0;

s32 func_L24_0035ACB0(void *arg0, s32 arg1, s32 arg2) {
    u8 *a = arg0;
    S_0035ACB0 *s = *(S_0035ACB0 **)(a + 0x68);
    s32 anim = -1;
    s32 mode = 0;
    s32 idx;
    u8 *e;

    switch (arg1) {
    case 1:
        func_L24_003A53E8(s->spring, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        anim = 1;
        break;
    case 2:
    case 5:
        func_L24_003A53E8(s->spring, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        anim = 2;
        break;
    case 3:
        anim = 10;
        func_L24_003A53E8(s->spring, D_L24_001DD5DC * 0.020000001f, D_L24_001DD5D8 * 0.00040000002f, D_L24_001DD5D8 * 0.00040000002f,
                      D_L24_001DD5E8 * 0.017453292f * 0.020000001f, D_L24_001DD5E0 * 0.017453292f * 0.00040000002f, D_L24_001DD5E4 * 0.017453292f * 0.00040000002f);
        s->v160 = s->v150;
        func_003C4C18(&s->v160, D_L24_001DD5F0[0]);
        s->v160.z = s->v150.z;
        break;
    case 4:
        anim = 11;
        func_L24_003A53E8(s->spring, D_L24_001DD5F8 * 0.020000001f, D_L24_001DD5F4 * 0.00040000002f, D_L24_001DD5F4 * 0.00040000002f,
                      D_L24_001DD604 * 0.017453292f * 0.020000001f, D_L24_001DD5FC * 0.017453292f * 0.00040000002f, D_L24_001DD600 * 0.017453292f * 0.00040000002f);
        s->v160 = s->v150;
        func_003C4C18(&s->v160, D_L24_001DD5F0[0]);
        s->v160.z = s->v150.z;
        break;
    case 6:
    case 7:
        func_L24_003A53E8(s->spring, D_L24_001DD610 * 0.020000001f, D_L24_001DD614 * 0.00040000002f, D_L24_001DD618 * 0.00040000002f,
                      D_L24_001DD61C * 0.017453292f * 0.020000001f, D_L24_001DD620 * 0.017453292f * 0.00040000002f, D_L24_001DD624 * 0.017453292f * 0.00040000002f);
        anim = 3;
        break;
    case 8:
        func_L24_003A53E8(s->spring, 0.0f, 0.0f, 0.0f,
                      D_L24_001DD61C * 0.017453292f * 0.020000001f, D_L24_001DD620 * 0.017453292f * 0.00040000002f, D_L24_001DD624 * 0.017453292f * 0.00040000002f);
        anim = 9;
        break;
    case 9:
        if (s->sound == -1 || (e = D_001A30B0 + (s->sound << 7), *(void **)(e + 0xDC) != a) || e[0xD0] == 0) {
            s->sound = func_003A52A0(1, 4, a);
        }
        qzero(&s->v170);
        anim = 5;
        func_L24_0035A550(a, -s->f1BC);
        func_L24_003A53E8(s->spring, D_L24_001DD628 * 0.020000001f, D_L24_001DD62C * 0.00040000002f, D_L24_001DD62C * 0.00040000002f, 0.0f, 0.0f, 0.0f);
        break;
    case 10:
        anim = 5;
        func_L24_003A53E8(s->spring, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        break;
    case 11:
        idx = s->sound;
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(void **)(e + 0xDC) == a && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        anim = 6;
        mode = 2;
        s->sound = -1;
        func_L24_003A53E8(s->spring, 0.0f, 0.0f, 0.0f,
                      D_L24_001DD61C * 0.017453292f * 0.020000001f, D_L24_001DD620 * 0.017453292f * 0.00040000002f, D_L24_001DD624 * 0.017453292f * 0.00040000002f);
        break;
    }
    if (anim != -1 && a[0x43] != anim) {
        func_003C3A10(a, anim, mode, 2);
    }
    a[0x20] = arg1;
    if (arg2 != -1 && a[0x95] != 5) {
        a[0x95] = arg2;
        a[0xBE] &= ~2;
        s->b198 = arg2;
    }
}
/* localdecomp:end func_L24_0035ACB0 */
