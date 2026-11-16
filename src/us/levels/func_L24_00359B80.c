#include "common.h"

/* NTSC-U counterpart of func_L24_0035ACB0 (src/levels/24_insomniac_museum/L24_0035ACB0.c) */
s32 func_L24_00359B80(void *, s32, s32);

/* localdecomp:start func_L24_00359B80 */
#include "vu0.h"
extern u8 D_001A30B0[];
extern f32 D_L24_001DD618_00359B80, D_L24_001DD61C_00359B80, D_L24_001DD620_00359B80, D_L24_001DD624_00359B80, D_L24_001DD628_00359B80;
extern f32 D_L24_001DD630_00359B80[] __attribute__((section(".sdata")));
extern f32 D_L24_001DD634_00359B80, D_L24_001DD638, D_L24_001DD63C, D_L24_001DD640, D_L24_001DD644;
extern f32 D_L24_001DD650, D_L24_001DD654, D_L24_001DD658, D_L24_001DD65C, D_L24_001DD660, D_L24_001DD664;
extern f32 D_L24_001DD668, D_L24_001DD66C;
__asm__(".extern D_L24_001DD618_00359B80, 4");
__asm__(".extern D_L24_001DD61C_00359B80, 4");
__asm__(".extern D_L24_001DD620_00359B80, 4");
__asm__(".extern D_L24_001DD624_00359B80, 4");
__asm__(".extern D_L24_001DD628_00359B80, 4");
__asm__(".extern D_L24_001DD630_00359B80, 4");
__asm__(".extern D_L24_001DD634_00359B80, 4");
__asm__(".extern D_L24_001DD638, 4");
__asm__(".extern D_L24_001DD63C, 4");
__asm__(".extern D_L24_001DD640, 4");
__asm__(".extern D_L24_001DD644, 4");
__asm__(".extern D_L24_001DD650, 4");
__asm__(".extern D_L24_001DD654, 4");
__asm__(".extern D_L24_001DD658, 4");
__asm__(".extern D_L24_001DD65C, 4");
__asm__(".extern D_L24_001DD660, 4");
__asm__(".extern D_L24_001DD664, 4");
__asm__(".extern D_L24_001DD668, 4");
__asm__(".extern D_L24_001DD66C, 4");
extern void func_L24_003A3818(void *, f32, f32, f32, f32, f32, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_L24_00359460(void *, f32);
extern void func_003BE4F0(void *, s32, s32, s32);

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

s32 func_L24_00359B80(void *arg0, s32 arg1, s32 arg2) {
    u8 *a = arg0;
    S_0035ACB0 *s = *(S_0035ACB0 **)(a + 0x68);
    s32 anim = -1;
    s32 mode = 0;
    s32 idx;
    u8 *e;

    switch (arg1) {
    case 1:
        func_L24_003A3818(s->spring, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        anim = 1;
        break;
    case 2:
    case 5:
        func_L24_003A3818(s->spring, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        anim = 2;
        break;
    case 3:
        anim = 10;
        func_L24_003A3818(s->spring, D_L24_001DD61C_00359B80 * 0.01666666753590107f, D_L24_001DD618_00359B80 * 0.00027777778450399637f, D_L24_001DD618_00359B80 * 0.00027777778450399637f,
                      D_L24_001DD628_00359B80 * 0.017453292f * 0.01666666753590107f, D_L24_001DD620_00359B80 * 0.017453292f * 0.00027777778450399637f, D_L24_001DD624_00359B80 * 0.017453292f * 0.00027777778450399637f);
        s->v160 = s->v150;
        func_003BF6A8(&s->v160, D_L24_001DD630_00359B80[0]);
        s->v160.z = s->v150.z;
        break;
    case 4:
        anim = 11;
        func_L24_003A3818(s->spring, D_L24_001DD638 * 0.01666666753590107f, D_L24_001DD634_00359B80 * 0.00027777778450399637f, D_L24_001DD634_00359B80 * 0.00027777778450399637f,
                      D_L24_001DD644 * 0.017453292f * 0.01666666753590107f, D_L24_001DD63C * 0.017453292f * 0.00027777778450399637f, D_L24_001DD640 * 0.017453292f * 0.00027777778450399637f);
        s->v160 = s->v150;
        func_003BF6A8(&s->v160, D_L24_001DD630_00359B80[0]);
        s->v160.z = s->v150.z;
        break;
    case 6:
    case 7:
        func_L24_003A3818(s->spring, D_L24_001DD650 * 0.01666666753590107f, D_L24_001DD654 * 0.00027777778450399637f, D_L24_001DD658 * 0.00027777778450399637f,
                      D_L24_001DD65C * 0.017453292f * 0.01666666753590107f, D_L24_001DD660 * 0.017453292f * 0.00027777778450399637f, D_L24_001DD664 * 0.017453292f * 0.00027777778450399637f);
        anim = 3;
        break;
    case 8:
        func_L24_003A3818(s->spring, 0.0f, 0.0f, 0.0f,
                      D_L24_001DD65C * 0.017453292f * 0.01666666753590107f, D_L24_001DD660 * 0.017453292f * 0.00027777778450399637f, D_L24_001DD664 * 0.017453292f * 0.00027777778450399637f);
        anim = 9;
        break;
    case 9:
        if (s->sound == -1 || (e = D_001A30B0 + (s->sound << 7), *(void **)(e + 0xDC) != a) || e[0xD0] == 0) {
            s->sound = func_0039FE80(1, 4, a);
        }
        qzero(&s->v170);
        anim = 5;
        func_L24_00359460(a, -s->f1BC);
        func_L24_003A3818(s->spring, D_L24_001DD668 * 0.01666666753590107f, D_L24_001DD66C * 0.00027777778450399637f, D_L24_001DD66C * 0.00027777778450399637f, 0.0f, 0.0f, 0.0f);
        break;
    case 10:
        anim = 5;
        func_L24_003A3818(s->spring, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        break;
    case 11:
        idx = s->sound;
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(void **)(e + 0xDC) == a && e[0xD0] != 0) {
                func_0039FB08(idx);
            }
        }
        anim = 6;
        mode = 2;
        s->sound = -1;
        func_L24_003A3818(s->spring, 0.0f, 0.0f, 0.0f,
                      D_L24_001DD65C * 0.017453292f * 0.01666666753590107f, D_L24_001DD660 * 0.017453292f * 0.00027777778450399637f, D_L24_001DD664 * 0.017453292f * 0.00027777778450399637f);
        break;
    }
    if (anim != -1 && a[0x43] != anim) {
        func_003BE4F0(a, anim, mode, 3);
    }
    a[0x20] = arg1;
    if (arg2 != -1 && a[0x95] != 5) {
        a[0x95] = arg2;
        a[0xBE] &= ~2;
        s->b198 = arg2;
    }
}
/* localdecomp:end func_L24_00359B80 */
