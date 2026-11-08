/* Near miss, ported from rac2-decomp's func_L04_00347AB8 (cross-game near pair). NEAR: SQRT: retail has inline sqrt.s (func_0038D160(d, sqrt(1-d*d))), unreachable in plain C without -ffast-math/asm; also frame/stack slot layout differs (retail 0x180 frame, locals at 0x00/0x40/0x80/0xa0/0xc0/0xd0/0xe0); real callees are core funcs 0038D570/0038CE68/0038D160(y,x)/0038CE90/0038D348/0038D */
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_L39_005B7630(f32 *position, f32 target, f32 *velocity, f32 acceleration, f32 damping, f32 limit, s32 direction);
extern void func_0038D570(void *dst, void *src);
extern f32 func_0038D160(f32 y, f32 x);
extern void func_0038D348(void *dst, void *src);
extern void func_0038D640(void *a, void *b, void *c);
extern void func_003C48A8(f32 *src, f32 *out);
extern f32 sqrtf(f32);

void func_L39_005BC798(void *a0, void *a1, void *a2, void *a3, f32 f1, f32 f2, f32 f3) {
    f32 pos;
    f32 buf0[4];
    f32 buf1[4];
    f32 mat[16];
    f32 vec[4];
    f32 res[4];
    f32 v;
    f32 d;
    f32 ang;
    f32 base;
    v = *(f32 *)((u8 *)a1 + 8);
    pos = 0.0f;
    func_0038D570(mat, a0);
    d = func_0038CE68(a3, mat + 8);
    base = func_0038D160(d, sqrtf(1.0f - d * d));
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
    func_L39_005B7630(&pos, base, (f32 *)a2, f1, f2, f3, 0);
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
    func_003C48A8(mat, (f32 *)a1);
    *(f32 *)((u8 *)a1 + 8) = v;
}
