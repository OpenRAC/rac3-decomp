/* US draft of func_003D9740 (rac3-uya-decomp func_003D41E0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003D9740 */
typedef struct { f32 x, y, z; } P_3D41E0;
typedef struct { f32 a, b; } T_3D41E0;
__asm__(".extern D_001D9390, 4");
__asm__(".extern D_001D93C0, 4");
extern f32 D_001D9390;
extern f32 D_001D93C0;
extern s32 D_001D9348;
extern P_3D41E0 D_002FF880[];
extern s32 D_002FF988[];
extern T_3D41E0 D_002FF9E0[];
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_0038D028();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
void func_003D9740(void *m, s32 tex, s32 rgba, s32 cnt, s32 mode, f32 t) {
    f32 v[4];
    f32 o[4];
    s32 i, n, r, col, mask;
    f32 da, ang, acc, step, c;
    s32 k;
    func_003A9440(8, 0);
    da = 0.31415927f;
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(6, func_00389598(tex));
    if (mode != 0) {
        if (mode == 2) {
            func_003A9440(0x47, 0x513F1);
            D_001D9348 |= 1;
        } else {
            func_003A9440(0x47, 0x53001);
        }
        func_003A9440(0x42, 0x8000000048UL);
        mask = 0xFF000000;
        col = rgba & mask;
    } else {
        func_003A9440(0x47, 0x513F1);
        func_003A9440(0x42, 0x8000000044UL);
        col = rgba & 0xFFFFFF;
    }
    func_0038C750();
    t = t - (f32)(s32)t + 7.0f;
    v[0] = 0;
    v[1] = 0;
    v[2] = 1.0f;
    v[3] = 1.0f;
    func_0038D028(o, v, m);
    for (i = 0; i < 22; i++) {
        D_002FF9E0[i].a = (f32)((i / 2) & 1);
        if ((i ^ 1) & 1) {
            D_002FF880[i].x = o[0];
            D_002FF880[i].y = o[1];
            D_002FF880[i].z = o[2];
            D_002FF988[i] = rgba;
            D_002FF9E0[i].b = t;
        }
    }
    if (cnt < 0) {
        step = 0;
        cnt = -cnt;
    } else {
        step = 1.0f / (f32)cnt;
    }
    acc = 0;
    if (cnt > 10) cnt = 10;
    n = cnt;
    ang = acc;
    while (n != 0) {
        ang += da;
        acc += step;
        t -= 1.0f;
        c = func_0038D0B0(ang);
        v[2] = func_0038D098(ang);
        r = func_0038DBD8(rgba, col, acc);
        for (i = 1, k = 0; i < 22; i += 2, k++) {
            v[0] = c * (&D_001D9390)[k];
            v[1] = c * (&D_001D93C0)[k];
            func_0038D028(o, v, m);
            D_002FF880[i].x = o[0];
            D_002FF880[i].y = o[1];
            D_002FF880[i].z = o[2];
            D_002FF988[i] = r;
            D_002FF9E0[i].b = t;
        }
        func_003D3A24(0x16, D_002FF880, D_002FF988, D_002FF9E0, 1);
        n--;
        if (n == 0) break;
        ang += da;
        acc += step;
        t -= 1.0f;
        c = func_0038D0B0(ang);
        v[2] = func_0038D098(ang);
        r = func_0038DBD8(rgba, col, acc);
        for (i = 0, k = 0; i < 22; i += 2, k++) {
            v[0] = c * (&D_001D9390)[k];
            v[1] = c * (&D_001D93C0)[k];
            func_0038D028(o, v, m);
            D_002FF880[i].x = o[0];
            D_002FF880[i].y = o[1];
            D_002FF880[i].z = o[2];
            D_002FF988[i] = r;
            D_002FF9E0[i].b = t;
        }
        func_003D3A24(0x16, D_002FF880, D_002FF988, D_002FF9E0, 1);
        n--;
    }
}
/* localdecomp:end func_003D9740 */
