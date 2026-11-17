#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

/* localdecomp:start func_L31_00349270 */
extern u8 *D_L31_001DF880;
extern void func_L30_0034CCD0(u8 *, f32 *, f32 *, f32 *, f32 *);
extern f32 func_0038D098(f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);

f32 func_L31_00349270(u8 *m) {
    s32 i = *(s32 *)(*(u8 **)(m + 0x68) + 0xC0);
    f32 v[4];
    f32 a;
    f32 r;

    if (i == -1) {
        return *(f32 *)(m + 0x10);
    }
    func_L30_0034CCD0(D_L31_001DF880 + i * 0x80, &v[0], &v[1], &v[2], &v[3]);
    if (func_0038D098(*(f32 *)(m + 0xF8)) < 0.0f) {
        a = v[0];
        r = func_003824E0(0.2f, 0.4f);
        return func_003C4088(a, *(f32 *)(m + 0x10), r);
    } else {
        a = v[1];
        r = func_003824E0(0.6f, 0.8f);
        return func_003C4088(*(f32 *)(m + 0x10), a, r);
    }
}
/* localdecomp:end func_L31_00349270 */
