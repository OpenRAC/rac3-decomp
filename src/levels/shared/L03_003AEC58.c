#include "common.h"

/* localdecomp:start func_L03_003AEC58 */
extern s32 func_L03_0043F5D0(s32, s32, f32);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
__asm__(".extern D_L03_001DE7E8, 4");
extern s32 D_L03_001DE7E8;
extern s32 D_L03_001DE7EC;

void func_L03_003AEC58(u8 *a0) {
    s32 c = func_L03_0043F5D0(D_L03_001DE7E8, D_L03_001DE7EC, *(f32 *)(*(u8 **)(a0 + 0x68) + 0x10));
    s32 b = (c >> 16) & 0xFF;
    s32 g = (c >> 8) & 0xFF;
    func_0038AE20(c & 0xFF, g, b, (u32)c >> 24);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L03_003AEC58 */

/* localdecomp:start func_L03_003AECB0 */
typedef struct { f32 x, y, w, h; } Rect_003AECB0;

extern void func_L01_005195E0(s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void *func_0011A264(void *, s32, s32);
__asm__(".extern D_L03_001DE7F0, 4");
extern f32 D_L03_001DE7F0;
__asm__(".extern D_L03_001DE7F4, 4");
extern f32 D_L03_001DE7F4;
__asm__(".extern D_L03_001DE7F8, 4");
extern f32 D_L03_001DE7F8;
__asm__(".extern D_L03_001DE7FC, 4");
extern f32 D_L03_001DE7FC;

void func_L03_003AECB0(void) {
    s32 i;
    func_L01_005195E0(0x150001);
    func_003E8EF0(0x150002, 0x39, 0x331465B7, D_L03_001DE7F0, D_L03_001DE7F4, 1.0f, 1.0f, 0.0f);
    func_003E8EF0(0x150004, 0x38, 0x332299DE, D_L03_001DE7F0, D_L03_001DE7F4, 1.0f, 1.0f, 0.0f);
    func_003E8A08(0x150001, 0x150002, 0x150004);
    {
        Rect_003AECB0 r;
        {
            Rect_003AECB0 t;
            {
                func_0011A264(&t, 0, sizeof(t));
                t.x = D_L03_001DE7F0 - 0.02f;
                t.y = D_L03_001DE7F4 - 0.001f;
                t.w = 0.23f;
                t.h = 0.1f;
                r = t;
            }
        }
        func_003E8FE8(0x150006, 0, 0x8066CCFF, r.x, r.y - r.h * 0.25f, 1.0f, 1.0f);
        func_L01_00516AA0(0x150006, 0x40, 1);
        func_003E8FE8(0x150007, 0, 0x8066CCFF, r.x, r.y + r.h * 0.25f, 1.0f, 1.0f);
        func_L01_00516AA0(0x150007, 0x40, 1);
        func_003E8A08(0x150001, 0x150006, 0x150007);
        {
            Rect_003AECB0 slot;
            {
                Rect_003AECB0 t;
                {
                    func_0011A264(&t, 0, sizeof(t));
                    t.x = D_L03_001DE7F0 + 0.14f;
                    t.y = D_L03_001DE7F4;
                    t.w = 0.06f;
                    t.h = 0.075f;
                    slot = t;
                }
            }
            for (i = 0; i < 8; i++) {
                func_003E9138(0x150008 + i, 0x8066CCFF, 0, slot.x + (f32)i * slot.w, slot.y,
                              slot.w - D_L03_001DE7F8 / 512.0f, slot.h - D_L03_001DE7FC / 416.0f);
                func_L01_00516AA0(0x150008 + i, 0x40, 1);
                func_003E8630(0x150001, 0x150008 + i);
            }
            {
                Rect_003AECB0 bar;
                {
                    Rect_003AECB0 t;
                    {
                        func_0011A264(&t, 0, sizeof(t));
                        t.x = D_L03_001DE7F0 - 0.016f;
                        t.y = D_L03_001DE7F4;
                        t.w = 0.2f;
                        t.h = 0.002f;
                        bar = t;
                    }
                }
                func_003E9138(0x150005, 0x8066CCFF, 0, bar.x, bar.y, bar.w, bar.h);
                func_003E8630(0x150001, 0x150005);
            }
        }
    }
    func_003E8348(1, 0x150001);
}
/* localdecomp:end func_L03_003AECB0 */

/* localdecomp:start func_L03_003AF098 */
extern s32 func_L01_005169C8(s32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L03_003AF098(s32 n) {
    s32 t = n - 1;
    s32 i;
    f32 f;
    if (t > 7) {
        t = 7;
    } else if (t < 0) {
        t = 0;
    }
    f = (f32)t / 7.0f * 0.61f;
    func_L01_005169C8(0x150002, f);
    func_L01_005169C8(0x150004, f);
    for (i = 0; i < 8; i++) {
        func_L01_00516AA0(0x150008 + i, 1, i < n);
    }
}
/* localdecomp:end func_L03_003AF098 */
