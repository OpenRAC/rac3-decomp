/* functional: high. Read block by block from the PAL asm (both sweep halves, the three clamp-to-0.5 tests, the shared and the asymmetric distance-update blocks, every early return). 235 word diffs vs retail (regalloc and scheduling; frame size 0xF0 matches). */
#include "vu0.h"
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *D_L05_001EA6D8[];
extern u8 D_L05_001EA6E0[];

void func_L05_0035E148(u8 *obj, f32 min_len) {
    u8 *d;
    u8 *hit;
    vu0_v4 p0;
    vu0_v4 p1;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    f32 t;
    f32 yaw;
    f32 len;
    f32 ang;
    f32 dist;

    d = *(u8 **)(obj + 0x68);
    *(vu0_v4 *)(d + 0x2F0) = *(vu0_v4 *)(d + 0x300);
    p0 = *(vu0_v4 *)(obj + 0x10);
    p1 = *(vu0_v4 *)(d + 0x300);
    p0.z += *(f32 *)(d + 0x78);
    p1.z += *(f32 *)(d + 0x78);
    if (func_003D3CB0(&p0, &p1, 0x10, obj, 0) == 0) {
        return;
    }
    hit = D_L05_001EA6D8[0];
    if (hit != 0 && hit == *(u8 **)(d + 0x230)) {
        return;
    }
    for (t = 10.0f; t <= 100.0f; t += 10.0f) {
        vec_sub_ab(&v30, &p1, &p0);
        yaw = func_0038D160(v30.x, v30.y);
        len = func_0038CED8(&v30);
        if (len < min_len) {
            len = min_len;
        }
        ang = t * 0.017453292f;
        v20.x = func_0038D098(func_0038DAB8(ang, yaw)) * len;
        v20.y = func_0038D0B0(func_0038DAB8(ang, yaw)) * len;
        v20.z = 0.0f;
        vec_add_ab(&v20, &p0, &v20);
        if (v20.x < 0.0f) {
            v20.x = 0.5f;
        }
        if (v20.y < 0.0f) {
            v20.y = 0.5f;
        }
        if (v20.z < 0.0f) {
            v20.z = 0.5f;
        }
        if (func_003D3CB0(&p0, &v20, 0x10, obj, 0) == 0) {
            *(vu0_v4 *)(d + 0x2F0) = v20;
            return;
        }
        hit = D_L05_001EA6D8[0];
        if (hit != 0) {
            if (hit == *(u8 **)(d + 0x230)) {
                *(vu0_v4 *)(d + 0x2F0) = v20;
            } else if (*(s16 *)(hit + 0xAA) == *(s16 *)(obj + 0xAA)) {
                *(vu0_v4 *)(d + 0x2F0) = *(vu0_v4 *)(d + 0x220);
                return;
            }
        }
        vec_sub_ab(&v40, obj + 0x10, D_L05_001EA6E0);
        dist = func_0038CED8(&v40);
        if (*(f32 *)(d + 0x2E8) < dist && t < 60.0f) {
            if (func_0038CF38(D_L05_001EA6E0, d + 0x300) < func_0038CF38(d + 0x320, d + 0x300)) {
                *(f32 *)(d + 0x2E8) = dist;
                *(vu0_v4 *)(d + 0x320) = *(vu0_v4 *)D_L05_001EA6E0;
            }
        }
        ang = -(t * 0.017453292f);
        v20.x = func_0038D098(func_0038DAB8(ang, yaw)) * len;
        v20.y = func_0038D0B0(func_0038DAB8(ang, yaw)) * len;
        v20.z = 0.0f;
        vec_add_ab(&v20, &p0, &v20);
        if (v20.x < 0.0f) {
            v20.x = 0.5f;
        }
        if (v20.y < 0.0f) {
            v20.y = 0.5f;
        }
        if (v20.z < 0.0f) {
            v20.z = 0.5f;
        }
        if (func_003D3CB0(&p0, &v20, 0x10, obj, 0) == 0) {
            *(vu0_v4 *)(d + 0x2F0) = v20;
            return;
        }
        hit = D_L05_001EA6D8[0];
        if (hit != 0) {
            if (hit == *(u8 **)(d + 0x230)) {
                *(vu0_v4 *)(d + 0x2F0) = v20;
            } else if (*(s16 *)(hit + 0xAA) == *(s16 *)(obj + 0xAA)) {
                *(vu0_v4 *)(d + 0x2F0) = *(vu0_v4 *)(d + 0x220);
                return;
            }
        }
        vec_sub_ab(&v40, obj + 0x10, D_L05_001EA6E0);
        dist = func_0038CED8(&v40);
        if (*(f32 *)(d + 0x2E8) < dist && t < 60.0f) {
            *(f32 *)(d + 0x2E8) = dist;
            *(vu0_v4 *)(d + 0x320) = *(vu0_v4 *)D_L05_001EA6E0;
        }
    }
}
