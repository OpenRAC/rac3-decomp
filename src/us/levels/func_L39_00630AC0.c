#include "common.h"

/* NTSC-U counterpart of func_L39_00633308 (src/levels/shared/L39_00632C48.c): 0.288 -> 0.2; 1.0472 -> 0.872665 */
typedef struct {
    u8 pad0[0x474];
    s32 mode;
    s32 kind;
    u8 pad1[0x142F - 0x47C];
    u8 alternate;
    u8 pad2[0x1A07 - 0x1430];
    u8 special;
    u8 pad3[0x2468 - 0x1A08];
    f32 speed;
} View_00633428;
#include "vu0.h"
extern s32 func_L01_0045D358(s32, s32, void *, void *);
extern s32 func_L39_0061EB48(void *);
extern f32 func_L01_004455F0(f32 *out, void *a, void *b, f32 f0, f32 f1, f32 f2, f32 f3);

/* localdecomp:start func_L39_00630AC0 */
extern void func_L39_00630A08(u8 *self, void *arg, f32 a, f32 b, f32 c);

void func_L39_00630AC0(View_00633428 *v, s32 arg, f32 a, f32 b, f32 c) {
    u8 *s = (u8 *)v;

    if (*(s32 *)(s + 0x1310) != 0) {
        if (v->special != 0 || func_L01_0045D358(0x28, 2, 0, *(void **)(s + 0x2534)) != 0) {
            if (func_L39_0061EB48(v) != 10) {
                if (a < 0.200000003f) {
                    a = 0.200000003f;
                }
                if (c < 0.87266469f) {
                    c = 0.87266469f;
                }
            }
        }
    }
    if (s[0x1A06] != 0) {
        ((void (*)(u8 *, f32, f32, f32, void *))func_L39_00630A08)(s, a, b, c, (void *)arg);
    } else {
        *(f32 *)(s + 0xFD8) = ((f32 (*)(f32 *, f32, void *, f32, f32, f32, void *))func_L01_004455F0)((f32 *)(s + 0xB8), *(f32 *)(s + 0xFD0), s + 0xFD4, a, b, c, (void *)arg);
    }
}
/* localdecomp:end func_L39_00630AC0 */
