#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L18_00353280 (src/levels/shared/L18_00353138.c): 0xF frames for 0xC */
/* localdecomp:start func_L18_00352678 */
extern u8 D_L18_001E2EC0[];
extern u8 D_L18_001EAB20[];
extern u8 D_L18_001E2EE0[];
extern s32 D_001D545C;
extern s32 D_001D545C_00352678;
__asm__(".extern D_001D545C_00352678, 4");
extern u8 D_0014275B[];
extern f32 D_L18_001DD3F0;
__asm__(".extern D_L18_001DD3F0, 4");
extern f32 D_L18_001DA930;
__asm__(".extern D_L18_001DA930, 4");
extern f32 D_L18_002F1D90[];
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_L01_0040C040(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388E78(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_L01_00417EA0(void);
extern s32 func_L18_00322C10(u8 *, void *, void *, u32, s32, f32, f32, f32, f32);

void func_L18_00352678(u8 *obj, f32 *vel, u32 a2) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 u70;
    vu0_v4 u80;
    vu0_v4 u90;
    u8 *p;
    f32 f;
    f32 d;
    f32 yaw;
    f32 pitch;
    f32 k;
    u8 *rot;

    p = *(u8 **)(obj + 0x68);
    *(vu0_q *)&v10 = 0;
    func_003886E8(&v50, D_L18_001E2EC0, 60.0f);
    vec_add_ab(&v30, &v50, obj + 0x10);
    if (func_003CE740(obj + 0x10, &v30, 0, obj, 0) != 0) {
        d = func_L01_0040C040(obj + 0x10, D_L18_001EAB20);
        f = D_L18_001DD3F0;
        if (d < 130.0f) {
            f = f + f;
        } else if (d < 350.0f) {
            f = f * 1.5f;
        } else if (d < 2800.0f) {
            f = f * 1.25f;
        } else if (4096.0f < d) {
            f = 0.0f;
        }
        func_003886E8(&v50, D_L18_001E2EE0, f);
        vec_add_ba(vel, &v50, vel);
    } else {
        func_003886E8(&v50, D_L18_001E2EC0, 60.0f);
        vec_add_ab(&v40, &v50, &v30);
        if (func_003CE740(&v30, &v40, 0, obj, 0) != 0) {
            if (func_L01_0040C040(&v30, D_L18_001EAB20) < 4096.0f) {
                func_003886E8(&v50, D_L18_001E2EC0 + 0x20, D_L18_001DD3F0 * 0.4f);
                vec_add_ba(vel, &v50, vel);
            }
        }
    }
    vec_sub_ba(&v10, vel, obj + 0x10);
    rot = obj + 0xC0;
    k = 10.0f;
    func_00388A28(v10.x, v10.y);
    func_00388A28(func_003887A0(&v10), v10.z);
    *(vu0_q *)&v10 = *(vu0_q *)rot;
    func_003886E8(&v20, p + 0x290, 3.0f);
    vec_add_ab(&v10, &v10, &v20);
    yaw = func_00388A28(v10.x, v10.y);
    pitch = -func_00388A28(func_003887A0(&v10), v10.z);
    func_003BDA38(obj, p[0x380], &v0);
    func_00388E78(&v60, rot);
    func_003888F0(&v50, p + 0x290, &v60);
    if (D_001D545C == 0x12 || D_001D545C == 0x1A) {
        k = 50.0f;
    } else if (D_001D545C == 0x14) {
        k = 150.0f;
    }
    if (func_L01_00417EA0() != 0) {
        if (D_001D545C_00352678 != 0x14) {
            if (D_001D545C_00352678 == 7 && D_0014275B[0] != 0) {
                k = k * D_L18_001DA930;
            } else {
                k = k * D_L18_002F1D90[D_001D545C_00352678];
            }
        }
    }
    if (func_L18_00322C10(obj, &v0, vel, a2, 0, yaw, pitch, v50.x, k) != 0) {
        if (a2 == 0xFFFFFFFF) {
            *(s16 *)(p + 0x37E) = 0xF;
        }
        p[0x380] ^= 1;
    }
}
/* localdecomp:end func_L18_00352678 */
