/* functional: medium. Near miss (31 word diffs, float register allocation); retail passes a fifth arg t0=1 to func_L01_003D6158 that this C omits, so check the callee before gating. */
#include "common.h"
/* localdecomp:start func_L01_003D42D0 */
#include "vu0.h"
extern s32 D_L01_001DDB8C;
extern vu0_v4 D_L01_001E2880[];
void func_L01_003D42D0(void *arg) {
    extern void func_003A52A0(s32, s32, u8 *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_004668A0(void *, void *, s32, s32, s32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_004749C8(void *, void *, s32);
    extern void func_L01_003D6158(M_3D41E8 *, s32, s32, s32, f32, f32);
    extern void func_L01_003002A8(void *, void *, void *);
    extern void func_L01_003D4750(void *);
    extern void func_003C2880(u8 *);
    vu0_v4 v, pos;
    s32 i, j, k;
    f32 a, r, b;
    u8 *obj = arg;
    if (obj) func_003A52A0(1, 0, obj);
    for (i = 0; i < 25 - D_L01_001DDB8C; i++) {
        r = func_003824E0(0.0f, 0.37f);
        a = func_00382538();
        b = func_00382538();
        func_00382760(&pos, r, a, b);
        pos.z += func_003824E0(0.35f, 0.6f);
        vec_add_ba(&pos, &pos, obj + 0x10);
        r = func_003824E0(0.0030000002589076757f, 0.024000002071261406f);
        a = func_00382538();
        b = func_00382538();
        func_00382760(&v, r, a, b);
        func_L01_004668A0(&pos, &v, 0x4F7F7F7F, 0x202020, func_00382498(25, 47), 150000.0f);
    }
    for (j = 0; j < 30 - D_L01_001DDB8C; j++) {
        a = func_0038D160(D_L01_001E2880[20].x - *(f32 *)(obj + 0x10), D_L01_001E2880[20].y - *(f32 *)(obj + 0x14));
        func_L01_00443A18(1.0f, 2.0f);
        v.x = *(f32 *)(obj + 0x10) + func_L01_00443A18(0.0f, 0.15f);
        v.y = *(f32 *)(obj + 0x14) + func_L01_00443A18(0.0f, 0.15f);
        v.z = *(f32 *)(obj + 0x18) + func_L01_00443A18(0.0f, 0.15f);
        r = func_003824E0(3.0f, 7.0f);
        b = func_L01_00443A18(0.0f, 2.6179938316345215f);
        r *= 0.020000001415610313f;
        a = func_0038DAB8(a, b);
        pos.x = func_0038D098(a) * r;
        pos.y = func_0038D0B0(a) * r;
        pos.z = 0.0f;
        pos.z = func_003824E0(5.0f, 10.0f) * 0.020000001415610313f;
        func_L01_004749C8(&v, &pos, 142);
    }
    func_L01_003D6158((M_3D41E8 *)obj, 78, 79, 10, 1.5f, 1.2f);
    for (k = 9; k >= 0; k--) {
        r = func_003824E0(0.0f, 0.35f);
        a = func_00382538();
        b = func_00382538();
        func_00382760(&pos, r, a, b);
        pos.z += 0.25f;
        vec_add_ba(&pos, &pos, obj + 0x10);
        r = func_003824E0(0.06000000238418579f, 0.12000000476837158f);
        a = func_00382538();
        func_00382760(&v, r, a, 1.2217304706573486f);
        v.z = func_003824E0(3.0f, 5.0f) * 0.020000001415610313f;
        func_L01_003002A8(obj, &pos, &v);
    }
    D_L01_001DDB8C--;
    func_L01_003D4750(obj);
    func_003C2880(obj);
}
/* localdecomp:end func_L01_003D42D0 */
