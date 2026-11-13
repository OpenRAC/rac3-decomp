#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00572490);

/* localdecomp:start func_L39_00572B08 */
#include "vu0.h"

typedef int u128_00572B08 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00572B08;

typedef struct {
    u8 pad0[0x20];
    u8 *target[4];
    u8 pad30[0x10];
    f32 f40[4];
    f32 f50[4];
    u8 pad60[0x40];
    f32 fA0[4];
    f32 fB0[4];
    u8 padC0[0x20];
    f32 fE0[4];
} Cam_00572B08;

typedef struct {
    u8 pad0[0x1C];
    Cam_00572B08 *cam;
} Row_00572B08;

__asm__(".extern D_L39_0024B850, 16");
extern Row_00572B08 *D_L39_0024B850;
typedef struct {
    u8 pad0[0xA4];
    u8 bA4[4];
} G_00572B08;

extern G_00572B08 D_001A5810;
extern s32 D_001A5930[][8];
__asm__(".extern D_L39_0024B760, 8");
extern f32 D_L39_0024B760[] __attribute__((section(".sdata")));
extern u8 *func_L39_0061BF38(s32);
extern u8 *func_L39_00668620(u8 *);
extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

void func_L39_00572B08(u8 *a0)
{
    V_00572B08 off;
    V_00572B08 pos;
    V_00572B08 up;
    V_00572B08 dir;
    V_00572B08 t40;
    V_00572B08 t50;
    s32 flag;
    s32 p;
    Cam_00572B08 *cam;
    u8 *pl;
    u8 *tgt;
    u8 *obj;
    u8 *o;
    u8 *m;
    f32 *h;
    f32 fov;

    p = *(s32 *)(a0 + 0x94);
    flag = 1;
    cam = D_L39_0024B850[*(s16 *)(a0 + 0x84)].cam;
    fov = 80.0f;
    pl = func_L39_0061BF38(p);
    qzero(&off);
    *(u128_00572B08 *)&up = 0;
    *(u128_00572B08 *)&dir = 0;
    up.z = 1.0f;
    up.w = 1.0f;
    dir.z = 1.0f;
    dir.w = 1.0f;
    h = (f32 *)(*(u8 **)(a0 + 0x70) + 0x90);
    tgt = cam->target[p];
    if (tgt != 0) {
        obj = tgt;
        o = func_L39_00668620(obj);
        fov = D_L39_0024B760[*(s16 *)(o + 0x2FC)];
        if (*(s16 *)(obj + 0xAA) == 0x107E) {
            s32 s = *(s32 *)(pl + 0x2544);
            s32 b = D_001A5810.bA4[s];
            f32 sign;
            f32 x;
            f32 t;
            f32 speed;

            m = *(u8 **)(obj + 0x68);
            speed = 0.012f;
            sign = 1.0f;
            if (D_001A5930[b][s] != 0) {
                sign = -1.0f;
            }
            if (b == 0) {
                sign = 1.0f;
            }
            x = *(f32 *)(*(u8 **)(pl + 0x2534) + 0x100) * sign;
            if ((f32)*(s16 *)(pl + 0x320) > 0.0f) {
                x = 0.0f;
            }
            *(u128_00572B08 *)&up = *(u128_00572B08 *)(m + 0x3C0);
            if (x > 0.01f) {
                t = -1.4f;
            } else if (x < -0.01f) {
                t = 1.4f;
            } else {
                t = 0.0f;
                speed = 0.009f;
            }
            func_L01_004482A0(&cam->f40[p], &cam->f50[p], t, speed * 1.44f, 0.57600003f, 0.120000005f);
            if (*(s32 *)(m + 0x3BC) != 0) {
                f32 a = func_0038DAB8(*(f32 *)(tgt + 0xF8), 1.5707964f);
                off.x = func_0038D098(a) * cam->f40[p];
                off.y = func_0038D0B0(a) * cam->f40[p];
                off.z = 0.0f;
            } else {
                *(u128_00572B08 *)&dir = *(u128_00572B08 *)(m + 0x3C0);
                flag = 0;
                func_0038CE20(&off, m + 0x2E0, -cam->f40[p]);
            }
        } else if (*(s16 *)(obj + 0xAA) == 0x107C || *(s16 *)(obj + 0xAA) == 0x1A17) {
            if (*(f32 *)(*(u8 **)(*(u8 **)(*(u8 **)(o + 0x2D0) + 0x68) + 0x720) + 0xC) * 0.020000001f < *(f32 *)(o + 0x310) &&
                cam->fB0[p] <= *(f32 *)(o + 0x310)) {
                func_003C4138(&cam->fA0[p], 97.0f, 0.34906587f);
            } else {
                func_003C4138(&cam->fA0[p], D_L39_0024B760[0], 0.10471976f);
            }
            fov = cam->fA0[p];
            cam->fB0[p] = *(f32 *)(o + 0x310);
        }
    } else {
        obj = *(u8 **)(pl + 0x2524);
    }
    func_00382810(*(s32 *)(a0 + 0x94), 0, 0, fov * 0.017453292f, 0.005f, 0.2f, 0.0f);
    t40 = *(V_00572B08 *)(obj + 0x10);
    t40.z = cam->fE0[*(s32 *)(a0 + 0x94)];
    pos = t40;
    if (flag != 0) {
        pos.z += *h;
    } else {
        func_0038CE20(&t50, &dir, *h);
        vec_add_ab(&pos, &pos, &t50);
    }
    vec_add_ba(&pos, &pos, &off);
    vec_sub_ba(a0, &pos, a0 + 0x30);
    func_0038CF68(a0, a0, 1.0f);
    func_0038CE90(a0 + 0x10, a0, &up);
    func_0038CF68(a0 + 0x10, a0 + 0x10, 1.0f);
    func_0038CE90(a0 + 0x20, a0 + 0x10, a0);
}
/* localdecomp:end func_L39_00572B08 */
