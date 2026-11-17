#include "common.h"

/* localdecomp:start func_L30_00340BA8 */
typedef struct {
    f32 x, y, z, w;
} V_00340BA8;

extern u8 D_L30_001D66B0;
extern u8 *D_L30_0021F16C __attribute__((section(".data")));
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00445208(f32, void *, void *, void *, void *, void *);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L30_00340BA8(u8 *a0) {
    V_00340BA8 bow;
    V_00340BA8 far;
    u8 *p;
    V_00340BA8 *out;
    s32 i;
    s32 c;
    u8 *r;

    p = *(u8 **)(a0 + 0x68);
    out = (V_00340BA8 *)(p + 0x30);
    func_0038CDF8(&bow, a0 + 0x10, *(void **)(p + 0x20), 0.333f);
    func_0038CDF8(&far, a0 + 0x10, *(void **)(p + 0x20), 0.6667f);
    bow.x += func_L01_00443A18(0.0f, 0.5f);
    bow.y += func_L01_00443A18(0.0f, 0.5f);
    bow.z += func_L01_00443A18(0.0f, 1.5f);
    far.x += func_L01_00443A18(0.0f, 0.5f);
    far.y += func_L01_00443A18(0.0f, 0.5f);
    far.z += func_L01_00443A18(0.0f, 1.5f);
    for (i = 0; i < 5; i++) {
        func_L01_00445208((f32)i * 0.25f, out, a0 + 0x10, *(void **)(p + 0x20), &bow, &far);
        out++;
    }
    c = func_00382468(0xFF);
    r = func_L01_0046FB40(*(void **)(p + 0x20), &D_L30_001D66B0, 2, 0x802020, c, 0x60, 0x10, 420000.0f, 420000.0f, 0.0f, 1);
    if (r != 0) {
        r[2] = *D_L30_0021F16C;
    }
    c = (c + 0x80) % 0xFF;
    r = func_L01_0046FB40(*(void **)(p + 0x20), &D_L30_001D66B0, 2, 0x802020, c, 0x40, 0x60, 420000.0f, 420000.0f, 0.0f, 1);
    if (r != 0) {
        r[2] = *D_L30_0021F16C;
    }
}
/* localdecomp:end func_L30_00340BA8 */
