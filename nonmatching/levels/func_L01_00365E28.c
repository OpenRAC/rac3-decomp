/* PAL near miss (Codex wave 8): near miss: 30 words differ with the file's flags.
 * Worker's note: Best 30 diff confirmed after unique primitive typedef name correction: build/codex/w415/func_L01_00365E28.type-name-final.log; buffer high-address allocation/order and missing second-div padding; no all-place proof; retained out/func_L01_00365E28.near.c. ...
 */
#include "common.h"
/* localdecomp:start func_L01_00365E28 */
typedef int Quad_00365E28 __attribute__((mode(TI)));

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vector_00365E28;

extern f32 D_L01_0028F1B0[][6];
extern u32 D_L01_0028F3A8[][2];
extern f32 D_L01_0028F450[][4];
void func_L01_00365E28(Quad_00365E28 *matrix, f32 angle, f32 inner, f32 outer, s32 texture, f32 unused, s32 color, s32 mode) {
    extern void func_003A9440(s32, unsigned long);
    extern unsigned long func_00389598(s32);
    extern void func_0038C750(void);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern void func_00382760(Vector_00365E28 *, f32, f32, f32);
    extern void func_0038D028(Vector_00365E28 *, Vector_00365E28 *, Quad_00365E28 *);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    Vector_00365E28 v;
    Vector_00365E28 result;
    s32 i;
    f32 radians;
    f32 twenty;
    f32 step;
    f32 t;
    f32 a;
    f32 (*positions)[6];
    u32 (*colors)[2];
    f32 (*uv)[4];
    func_003A9440(8, 0);
    func_003A9440(20, 0xFF9000000260ULL);
    func_003A9440(71, 0x513F1);
    func_003A9440(6, func_00389598(texture));
    if (mode) func_003A9440(66, 0x8000000048ULL);
    else func_003A9440(66, 0x8000000041ULL);
    radians = 0.017453292f;
    func_0038C750();
    twenty = 20.0f;
    step = angle * radians / twenty;
    uv = D_L01_0028F450;
    positions = D_L01_0028F1B0;
    colors = D_L01_0028F3A8;
    for (i = 0; i < 42; i += 2) {
        t = (f32)(i / 2);
        a = func_0038DB48(t * step);
        func_0038D098(a);
        (*colors)[0] = color;
        (*colors)[1] = color;
        (*uv)[2] = (*uv)[0] = t / twenty;
        (*uv)[1] = 0.0f;
        (*uv)[3] = 1.0f;
        colors++;
        uv++;
        func_00382760(&v, 1.0f, a, inner * radians);
        v.w = 1.0f;
        func_0038D028(&result, &v, matrix);
        (*positions)[0] = result.x;
        (*positions)[1] = result.y;
        (*positions)[2] = result.z;
        func_00382760(&v, 1.0f, a, outer * radians);
        v.w = 1.0f;
        func_0038D028(&result, &v, matrix);
        (*positions)[3] = result.x;
        (*positions)[4] = result.y;
        (*positions)[5] = result.z;
        positions++;
    }
    func_003D3A24(42, D_L01_0028F1B0, D_L01_0028F3A8, D_L01_0028F450, 1);
}
/* localdecomp:end func_L01_00365E28 */
