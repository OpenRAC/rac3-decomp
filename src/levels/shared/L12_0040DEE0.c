#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L12_0040DEE0 */
typedef struct { f32 x, y, z; } P_40DEE0;
typedef struct { f32 a, b; } T_40DEE0;
__asm__(".extern D_001D6500, 4");
__asm__(".extern D_001D64D0, 4");
extern f32 D_001D6500;
extern f32 D_001D64D0;
extern s32 D_L12_001DBBA0;
extern vu0_v4 D_L12_001E2700;
extern P_40DEE0 D_L12_001E8F00[];
extern s32 D_L12_001E9008[];
extern T_40DEE0 D_L12_001E9060[];
extern void func_L12_00449F60(void *, void *);
extern void func_L01_0040EE50(void *, void *);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
void func_L12_0040DEE0(void *m, s32 tex, s32 rgba, s32 cnt, s32 mode, f32 t, f32 k1, f32 k2) {
    f32 v[4];
    f32 o[4];
    f32 n1[4];
    f32 n2[4];
    u8 mat[0x30];
    s32 i, n, r, r0, col, mask;
    f32 da, ang, acc, step, c, x;
    s32 k;
    func_L12_00449F60(mat, m);
    func_L01_0040EE50(mat, mat);
    func_003A9440(8, 0);
    da = 0.31415927f;
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(6, func_00389598(tex));
    if (mode != 0) {
        if (mode == 2) {
            func_003A9440(0x47, 0x513F1);
            D_L12_001DBBA0 |= 1;
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
    func_0038D000(n1, v, mat);
    func_0038CF68(n1, n1, 1.0f);
    vec_sub_ab(n2, o, &D_L12_001E2700);
    func_0038CF68(n2, n2, 1.0f);
    x = (fabs_asm(func_0038CE68(n1, n2)) - k1) * k2;
    if (x > 1.0f) {
        x = 1.0f;
    } else if (x < 0.0f) {
        x = 0.0f;
    }
    r0 = func_0038DBD8(col, rgba, x);
    for (i = 0; i < 22; i++) {
        D_L12_001E9060[i].a = (f32)((i / 2) & 1);
        if ((i ^ 1) & 1) {
            D_L12_001E8F00[i].x = o[0];
            D_L12_001E8F00[i].y = o[1];
            D_L12_001E8F00[i].z = o[2];
            D_L12_001E9008[i] = r0;
            D_L12_001E9060[i].b = t;
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
            v[0] = c * (&D_001D64D0)[k];
            v[1] = c * (&D_001D6500)[k];
            func_0038D028(o, v, m);
            D_L12_001E8F00[i].x = o[0];
            D_L12_001E8F00[i].y = o[1];
            D_L12_001E8F00[i].z = o[2];
            func_0038D000(n1, v, mat);
            func_0038CF68(n1, n1, 1.0f);
            vec_sub_ab(n2, o, &D_L12_001E2700);
            func_0038CF68(n2, n2, 1.0f);
            x = (fabs_asm(func_0038CE68(n1, n2)) - k1) * k2;
            if (x > 1.0f) {
                x = 1.0f;
            } else if (x < 0.0f) {
                x = 0.0f;
            }
            D_L12_001E9008[i] = func_0038DBD8(col, r, x);
            D_L12_001E9060[i].b = t;
        }
        func_003D3A24(0x16, D_L12_001E8F00, D_L12_001E9008, D_L12_001E9060, 1);
        n--;
        if (n == 0) break;
        ang += da;
        acc += step;
        t -= 1.0f;
        c = func_0038D0B0(ang);
        v[2] = func_0038D098(ang);
        r = func_0038DBD8(rgba, col, acc);
        for (i = 0, k = 0; i < 22; i += 2, k++) {
            v[0] = c * (&D_001D64D0)[k];
            v[1] = c * (&D_001D6500)[k];
            func_0038D028(o, v, m);
            D_L12_001E8F00[i].x = o[0];
            D_L12_001E8F00[i].y = o[1];
            D_L12_001E8F00[i].z = o[2];
            func_0038D000(n1, v, mat);
            func_0038CF68(n1, n1, 1.0f);
            vec_sub_ab(n2, o, &D_L12_001E2700);
            func_0038CF68(n2, n2, 1.0f);
            x = (fabs_asm(func_0038CE68(n1, n2)) - k1) * k2;
            if (x > 1.0f) {
                x = 1.0f;
            } else if (x < 0.0f) {
                x = 0.0f;
            }
            D_L12_001E9008[i] = func_0038DBD8(col, r, x);
            D_L12_001E9060[i].b = t;
        }
        func_003D3A24(0x16, D_L12_001E8F00, D_L12_001E9008, D_L12_001E9060, 1);
        n--;
    }
}
/* localdecomp:end func_L12_0040DEE0 */
