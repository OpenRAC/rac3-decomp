#include "common.h"

/* localdecomp:start func_L39_005BC798 */
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_L01_00448728(s32, f32, s32, f32, f32, f32, s32);
extern void func_0038D570(void *dst, void *src);
extern f32 func_0038D160(f32 y, f32 x);
extern void func_0038D348(void *dst, void *src);
extern void func_0038D640(void *a, void *b, void *c);
extern void func_003C48A8(void *, void *);
#include "vu0.h"

void func_L39_005BC798(void *a0, void *a1, void *a2, void *a3, f32 f1, f32 f2, f32 f3) {
    f32 buf0[16];
    f32 buf1[16];
    f32 mat[16];
    f32 vec[4];
    f32 res[4];
    f32 pos;
    f32 v;
    f32 d;
    f32 t;
    f32 ang;
    f32 base;
    v = *(f32 *)((u8 *)a1 + 8);
    pos = 0.0f;
    func_0038D570(mat, a0);
    t = func_0038CE68(a3, mat + 8);
    base = func_0038D160(t, sqrt_asm(1.0f - t * t));
    func_0038CE90(res, a3, mat + 8);
    if (res[2] < 0.99f) {
        ang = func_0038D160(res[0], res[1]);
        vec[0] = 0.0f;
        vec[1] = 0.0f;
        vec[2] = -ang;
        func_0038D348(buf1, vec);
        func_0038D640(mat, buf1, mat);
        func_0038D028(res, res, buf1);
        d = func_0038D160(res[2], res[0]);
        vec[0] = 0.0f;
        vec[1] = -d;
        vec[2] = 0.0f;
        func_0038D348(buf0, vec);
        func_0038D640(mat, buf0, mat);
        func_0038D028(res, res, buf0);
    } else {
        ang = 0.0f;
        d = 0.0f;
    }
    func_L01_00448728((s32)&pos, base, (s32)a2, f1, f2, f3, 0);
    vec[0] = 0.0f;
    vec[1] = 0.0f;
    vec[2] = pos;
    func_0038D348(buf1, vec);
    func_0038D640(mat, buf1, mat);
    vec[1] = d;
    vec[2] = 0.0f;
    func_0038D348(buf0, vec);
    func_0038D640(mat, buf0, mat);
    vec[1] = 0.0f;
    vec[2] = ang;
    func_0038D348(buf1, vec);
    func_0038D640(mat, buf1, mat);
    func_003C48A8(mat, a1);
    *(f32 *)((u8 *)a1 + 8) = v;
}
/* localdecomp:end func_L39_005BC798 */
