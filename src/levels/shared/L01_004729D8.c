#include "common.h"

/* localdecomp:start func_L01_004729D8 */
typedef int Q_004729D8 __attribute__((mode(TI)));

extern u8 *D_L01_00221248[];
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);

u8 *func_L01_004729D8(Q_004729D8 *pos, f32 *a, f32 *b, s32 render, s32 life, u8 c1E, u8 c1F, u8 c1C, u8 c1D, u8 tex, f32 scale)
{
    u8 *p = func_L01_004618E0(0x6C);
    u8 *s;
    f32 *v;
    s32 t, n;
    if (p != 0) {
        *(Q_004729D8 *)(p + 0x10) = *pos;
        p[3] = render;
        p[1] = 0;
        p[9] = 0x44;
        s = p + 0x20;
        p[8] = func_00382468(0xFF);
        v = (f32 *)(p + 0x30);
        p[2] = *D_L01_00221248[0];
        *(s16 *)(p + 0xA) = life;
        ((f32 *)s)[0] = a[0];
        ((f32 *)s)[1] = a[1];
        ((f32 *)s)[2] = a[2];
        v[0] = b[0];
        v[1] = b[1];
        v[2] = b[2];
        t = func_00382498(0, 0xB);
        if (tex != 0 && tex < 15) n = tex;
        else n = func_00382498(0, 0xF);
        s[0xC] = t | (n << 4);
        s[0xD] = func_00382498(1, 4) << 4;
        s[0xE] = life;
        if (c1E == 0) s[0x1E] = (s32)(func_003824E0(0.3f, 0.5f) * 128.0f);
        else s[0x1E] = c1E;
        if (c1F == 0) s[0x1F] = (s32)(func_003824E0(1.0f, 2.0f) * 128.0f);
        else s[0x1F] = c1F;
        if (c1C == 0) s[0x1C] = (s32)(func_003824E0(0.9f, 1.1f) * 0.10000001f * 128.0f);
        else s[0x1C] = c1C;
        if (c1D == 0) s[0x1D] = (s32)(func_003824E0(0.0f, 0.0125f) * 128.0f);
        else s[0x1D] = c1D;
        s[0xF] = (s32)(scale * 128.0f);
        *(s32 *)(p + 4) = ((n + 0x70) << 24) | 0x103080;
    }
    return p;
}
/* localdecomp:end func_L01_004729D8 */
