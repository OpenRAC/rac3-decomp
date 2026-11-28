#include "common.h"
/* localdecomp:start func_L01_004EB5D0 */
#include "vu0.h"
typedef struct { f32 v[4]; } Vec4_3A8;
typedef struct { u8 p0[0x1C]; s32 count; u8 p20[0x20]; vu0_v4 normal; } Hit_3A8;
extern Hit_3A8 D_L01_001EAA00_3A8[] __asm__("D_L01_001EAA80");
extern u8 D_001A4CD0[];
extern s32 D_L01_001EAA9C[];
typedef struct {
    u8 p0[0xF0]; vu0_v4 velocity;
    u8 p100[0x290 - 0x100]; s32 ground;
    u8 p294[0x25C0 - 0x294]; void *moby;
} Hero_004EF3A8;
extern Hero_004EF3A8 D_001A4BE0;
void func_L01_004EB5D0(s32 force) {
    extern f32 func_L01_0050D430(void *);
    extern void func_L01_0050D110(void *, s32, f32, f32, f32);
    extern void func_L01_005110E8_3A8b(void *, f32, f32, s32, f32) __asm__("func_L01_0050D110");
    extern f32 func_003887A0(void *);
    extern void func_00388830(void *, void *, f32);
    extern void func_L01_0050D530(void *, void *, f32);
    extern void func_003886E8(Vec4_3A8 *, Vec4_3A8 *, f32);
    extern s32 func_003CE740(void *, void *, s32, void *, void *);
    extern s32 func_003D00C0(void);
    extern f32 func_L01_0050D870(void *);
    extern f32 func_00388730(void *, void *);
    vu0_v4 origin, end, low, low_end;
    Hero_004EF3A8 *h;
    u8 *early;
    f32 height, distance;
    f32 slope;
    f32 zero = 0.0f;
    s32 kind;
    if (func_L01_0050D430(D_001A4CD0) < 0.00166666682f) {
        return;
    }
    early = D_001A4CD0 - 0xF0;
    height = 0.395f;
    distance = 0.5f;
    if ((u32)(*(s32 *)(early + 0x25CC) - 17) < 2) {
        height = 0.0f;
        distance = 0.7f;
    } else if (early[0x25E4] == 1) {
        height = 0.35f;
        distance = 0.27f;
    }
    func_L01_0050D110(&origin, 1, 0.0f, 0.0f, height);
    func_L01_005110E8_3A8b(&low, zero, zero, 1, height * 0.3f);
    if (force || func_003887A0(D_001A4CD0) < 0.01f) {
        func_00388830(&end, &D_001A4BE0, distance);
        func_00388830(&low_end, &D_001A4BE0, distance * 1.4f);
    } else {
        func_L01_0050D530(&end, D_001A4CD0, 0.0f);
        func_00388830(&end, &end, distance);
        func_003886E8((Vec4_3A8 *)&low_end, (Vec4_3A8 *)&end, 1.4f);
    }
    vec_add_ba(&end, &end, &origin);
    vec_add_ab(&low_end, &low_end, &low);
    kind = -1;
    if (func_003CE740(&low, &low_end, 2, D_001A4BE0.moby, 0) && D_L01_001EAA9C[0] > 0)
        kind = func_003D00C0();
    slope = 0.0f;
    if (func_003CE740(&origin, &end, 2, D_001A4BE0.moby, 0) && D_L01_001EAA00_3A8[0].count > 0)
        slope = func_L01_0050D870(&D_L01_001EAA00_3A8[0].normal);
    if (slope >= 0.87266463f || kind == 8 || kind == 12) {
        f32 dot;
        u8 *hit = (u8 *)D_L01_001EAA00_3A8;
        h = &D_001A4BE0;
        h->ground = *(s32 *)(hit + 0x18);
        func_L01_0050D530(hit + 0x40, hit + 0x40, 0.0f);
        func_00388830(hit + 0x40, hit + 0x40, 1.0f);
        dot = func_00388730(hit + 0x40, &h->velocity);
        if (dot < 0.0f) {
            func_003886E8((Vec4_3A8 *)(hit + 0x40), (Vec4_3A8 *)(hit + 0x40), -dot);
            vec_add_ba(&h->velocity, &h->velocity, hit + 0x40);
        }
    }
}
/* localdecomp:end func_L01_004EB5D0 */
