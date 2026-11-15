#include "common.h"

/* localdecomp:start func_L30_004BD6C0 */
#include "vu0.h"
#include "structs/hero.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004BD6C0;

extern struct Hero D_001A4BE0;
typedef struct {
    u8 pad0[0x18];
    struct Moby *moby;
    s32 count;
    u8 pad20[0x20];
    V4_004BD6C0 normal;
} Coll_004BD6C0;

extern Coll_004BD6C0 D_L30_001E9000;
extern f32 func_L01_00511408(void *);
extern void func_L01_005110E8(void *, f32, f32, f32, s32);
extern f32 func_0038CED8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00511508(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern f32 func_L01_00511848(void *);
extern f32 func_0038CE68(void *, void *);

void func_L30_004BD6C0(s32 force) {
    V4_004BD6C0 a;
    V4_004BD6C0 b;
    V4_004BD6C0 c;
    V4_004BD6C0 d;
    f32 dot;
    f32 h;
    f32 len;
    s32 hit;

    if (func_L01_00511408(&D_001A4BE0.intended_vel) < 0.002f) {
        return;
    }
    h = 0.395f;
    len = 0.5f;
    if ((u32)(D_001A4BE0.state_type - 0x11) < 2) {
        h = 0.0f;
        len = 0.7f;
    } else if (D_001A4BE0.body_kind == 1) {
        h = 0.35f;
        len = 0.27f;
    } else if (D_001A4BE0.body_kind == 5) {
        h = 0.4f;
        len = 0.9f;
    }
    func_L01_005110E8(&a, 0.0f, 0.0f, h, 1);
    func_L01_005110E8(&c, 0.0f, 0.0f, h * 0.3f, 1);
    if (force != 0 || func_0038CED8(&D_001A4BE0.intended_vel) < 0.01f) {
        func_0038CF68(&b, &D_001A4BE0, len);
        func_0038CF68(&d, &D_001A4BE0, len * 1.4f);
    } else {
        func_L01_00511508(&b, &D_001A4BE0.intended_vel, 0.0f);
        func_0038CF68(&b, &b, len);
        func_0038CE20(&d, &b, 1.4f);
    }
    vec_add_ba(&b, &b, &a);
    vec_add_ab(&d, &d, &c);
    hit = -1;
    if (func_003D3CB0(&c, &d, 2, D_001A4BE0.hero_moby, 0) && D_L30_001E9000.count > 0) {
        hit = func_003D5630();
    }
    dot = 0.0f;
    if (func_003D3CB0(&a, &b, 2, D_001A4BE0.hero_moby, 0) && D_L30_001E9000.count > 0) {
        dot = func_L01_00511848(&D_L30_001E9000.normal);
    }
    if (dot >= 0.87266463f || hit == 8 || hit == 12) {
        f32 along;
        D_001A4BE0.moby_stood_on = D_L30_001E9000.moby;
        func_L01_00511508(&D_L30_001E9000.normal, &D_L30_001E9000.normal, 0.0f);
        func_0038CF68(&D_L30_001E9000.normal, &D_L30_001E9000.normal, 1.0f);
        along = func_0038CE68(&D_L30_001E9000.normal, &D_001A4BE0.intended_vel);
        if (along < 0.0f) {
            func_0038CE20(&D_L30_001E9000.normal, &D_L30_001E9000.normal, -along);
            vec_add_ba(&D_001A4BE0.intended_vel, &D_001A4BE0.intended_vel, &D_L30_001E9000.normal);
        }
    }
}
/* localdecomp:end func_L30_004BD6C0 */
