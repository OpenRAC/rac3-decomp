/* PAL near miss (Codex wave 6): near miss: 75 words differ with the file's flags.
 * Worker's note: 4 diff: retained w296/out/func_L01_0038C9B0.near.c; best w296/func_L01_0038C9B0.07.log; color/UV high-half allocation differs; tested metadata divs 0 2; GS writer call uses explicit 64-bit argument cast to retain declared file prototype.
 */
#include "common.h"
/* localdecomp:start func_L01_0038C9B0 */
extern f32 D_L01_00291360[][3];
typedef struct { s32 values[42]; } Colors_0038C9B0;
extern Colors_0038C9B0 D_L01_00291558;
extern f32 D_L01_00291600[][2];
void func_L01_0038C9B0(s128 *matrix, f32 radius, f32 angle0, f32 angle1, s32 texture, f32 unused, s32 color, s32 blend) {
    extern void func_003A9440(s32, s32);
    extern unsigned long func_00389598(s32);
    extern void func_0038C750(void);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    f32 v[4];
    f32 transformed[4];
    s32 i;
    f32 step, x, angle, u;
    f32 deg;
    f32 count;
    ((void (*)(s32, unsigned long))func_003A9440)(8, 0);
    ((void (*)(s32, unsigned long))func_003A9440)(20, 0xFF9000000260UL);
    ((void (*)(s32, unsigned long))func_003A9440)(71, 0x513F1);
    ((void (*)(s32, unsigned long))func_003A9440)(6, func_00389598(texture));
    if (blend) {
        ((void (*)(s32, unsigned long))func_003A9440)(66, 0x8000000048UL);
    } else {
        ((void (*)(s32, unsigned long))func_003A9440)(66, 0x8000000041UL);
    }
    deg = 0.0174532924f;
    func_0038C750();
    count = 20.0f;
    step = radius * deg / count;
    for (i = 0; i < 42; i += 2) {
        x = (f32)(i / 2);
        angle = func_0038DB48(x * step);
        func_0038D098(angle);
        deg = 0.0174532924f;
        u = (f32)(i / 2) / count;
        D_L01_00291558.values[i] = color;
        D_L01_00291558.values[i + 1] = color;
        D_L01_00291600[i][1] = 0;
        D_L01_00291600[i][0] = u;
        D_L01_00291600[i + 1][1] = 1.0f;
        D_L01_00291600[i + 1][0] = u;
        func_00382760(v, 1.0f, angle, angle0 * deg);
        v[3] = 1.0f;
        func_0038D028(transformed, v, matrix);
        D_L01_00291360[i][0] = transformed[0];
        D_L01_00291360[i][1] = transformed[1];
        D_L01_00291360[i][2] = transformed[2];
        func_00382760(v, 1.0f, angle, angle1 * deg);
        v[3] = 1.0f;
        func_0038D028(transformed, v, matrix);
        D_L01_00291360[i + 1][0] = transformed[0];
        D_L01_00291360[i + 1][1] = transformed[1];
        D_L01_00291360[i + 1][2] = transformed[2];
    }
    {
        void *c = &D_L01_00291558;
        void *uv = D_L01_00291600;
        func_003D3A24(42, D_L01_00291360, c, uv, 1);
    }
}
/* localdecomp:end func_L01_0038C9B0 */
