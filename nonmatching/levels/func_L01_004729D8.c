/* PAL near miss (Codex wave 10): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Contract-only diagnostic with --sq-ra: 24/175 words differ, all frame/save offsets (0x70 vs retail 0xC0); fixed -fopt-stack prevents retail layout. Ordinary wrapper blocked by existing Part_00470258 typedef declared after entry: hoist exact typedef/prototype ...
 */
#include "common.h"
/* localdecomp:start func_L01_004729D8 */
typedef int Q_004729D8 __attribute__((mode(TI)));
extern u8 *D_L01_00221248[];
u8 *func_L01_004729D8(Q_004729D8 *pos, f32 *velocity, f32 *acceleration, s32 render, s32 life, u8 a5, u8 a6, u8 a7, u8 a8, u8 kind, f32 scale) {
    extern Part_00470258 *func_L01_004618E0(s32);
    extern s32 func_00382468(s32);
    extern u8 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    u8 *s;
    f32 *a;
    u8 *p = (u8 *)func_L01_004618E0(0x6C);
    s32 tile, color;
    if (p) {
        *(Q_004729D8 *)(p + 0x10) = *pos;
        p[3] = render;
        p[1] = 0;
        p[9] = 0x44;
        s = p + 0x20;
        p[8] = func_00382468(255);
        p[2] = *D_L01_00221248[0];
        *(s16 *)(p + 0xA) = life;
        *(f32 *)(p + 0x20) = velocity[0];
        *(f32 *)(s + 4) = velocity[1];
        *(f32 *)(s + 8) = velocity[2];
        a = (f32 *)(p + 0x30);
        a[0] = acceleration[0];
        a[1] = acceleration[1];
        a[2] = acceleration[2];
        tile = func_00382498(0, 11);
        if (kind > 0 && kind < 15) color = kind;
        else color = func_00382498(0, 15);
        s[0xC] = tile | (color << 4);
        s[0xD] = func_00382498(1, 4) << 4;
        s[0xE] = life;
        if (a5 == 0) s[0x1E] = (s32)(func_003824E0(0.3f, 0.5f) * 128.0f);
        else s[0x1E] = a5;
        if (a6 == 0) s[0x1F] = (s32)(func_003824E0(1.0f, 2.0f) * 128.0f);
        else s[0x1F] = a6;
        if (a7 == 0) s[0x1C] = (s32)(func_003824E0(0.9f, 1.1f) * 0.10000000894069672f * 128.0f);
        else s[0x1C] = a7;
        if (a8 == 0) s[0x1D] = (s32)(func_003824E0(0.0f, 0.0125f) * 128.0f);
        else s[0x1D] = a8;
        s[0xF] = (s32)(scale * 128.0f);
        *(u32 *)(p + 4) = ((color + 0x70) << 24) | 0x103080;
    }
    return p;
}
/* localdecomp:end func_L01_004729D8 */
