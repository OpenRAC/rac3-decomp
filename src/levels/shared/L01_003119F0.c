#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3119F0;

extern V4_3119F0 D_L01_001E2A40;
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);

/* localdecomp:start func_L01_003119F0 */
void func_L01_003119F0(u8 *obj, f32 *pos) {
    V4_3119F0 d;
    V4_3119F0 w;
    V4_3119F0 v;
    f32 len;
    f32 a;
    f32 b;
    s32 i;
    s32 flag;

    vec_sub_ab(&d, &D_L01_001E2A40, pos);
    len = func_0038CEA8(&d);
    v = (V4_3119F0){0.0f, 0.0f, 0.0f, 0.0f};
    v.x = func_003824E0(-1.0f, 1.0f);
    v.y = func_003824E0(-1.0f, 1.0f);
    v.z = func_003824E0(-1.0f, 1.0f);
    w = v;
    d.z = d.z + len * 0.5f;
    func_0038CF68(&w, &w, len / 5.0f * 0.0200000014f);
    func_0038CF68(&d, &d, (len + len) * 0.0200000014f);
    vec_add_ab(&w, &w, &d);
    func_L01_0040E6B8(&w, &w, 0.200000018f);
    func_L01_002FB660(pos, &w, func_00382498(50, 75), 0, 0, 0);
    for (i = 8; i >= 0; i--) {
        a = func_003824E0(0.2617994f, 1.3089969f);
        b = func_00382538();
        func_00382760(&v, func_003824E0(8.0f, 12.0f) * 0.0200000014f, b, a);
        v.z = v.z + 0.0600000024f;
        if (func_0013D3E0() % 3 == 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        func_0038D000(&v, &v, obj + 0xC0);
        func_L01_002FB660(pos, &v, func_00382498(50, 75), flag, 0, 0);
    }
}
/* localdecomp:end func_L01_003119F0 */
