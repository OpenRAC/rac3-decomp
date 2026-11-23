/* functional: high. 4 diff vs retail, instruction scheduling only (retail multiset identical); VU0 add via inline asm */
#include "common.h"
typedef struct {
    u8 pad0[0x16B0]; s32 mode;
    u8 pad16B4[0x25C0-0x16B4]; u8 *camera;
    u8 pad25C4[0x2874-0x25C4]; s16 aiming;
} State_003886E8;
extern State_003886E8 D_001A4BE0;
extern s128 D_L01_001E29E0;
extern f32 D_001DDE00_sda, D_001DDE04_sda, D_001DDE08_sda;
extern s32 D_001DDDF4_sda, D_001DDDF8_sda, D_001DDDFC_sda;
extern s32 D_L01_001E1EA4;
extern f32 D_L01_001E1EA8, D_L01_001E1EAC, D_L01_001E1EB0;
__asm__(".extern D_001DDE00_sda, 4");
__asm__(".extern D_001DDE04_sda, 4");
__asm__(".extern D_001DDE08_sda, 4");
__asm__(".extern D_001DDDF4_sda, 4");
__asm__(".extern D_001DDDF8_sda, 4");
__asm__(".extern D_001DDDFC_sda, 4");
void func_L01_003886E8(u8 *moby) {
    extern void func_003C2F58(u8 *, s32, s128 *);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern f32 func_0038CED8(s128 *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D328(s128 *, S_38C110v *);
    extern void func_0038D890(s128 *, s128 *, s128 *, f32);
    extern void func_003D9740(s128 *, s32, s32, s32, s32, f32);
    struct { s128 matrix[4], position, direction; S_38C110v rotation; s128 second; } v;
    func_003C2F58(moby, 0, &v.position);
    if (D_001A4BE0.aiming) {
        func_0038CE20(&v.direction, (s128 *)(moby + 0xD0), -1.0f);
    } else if (D_001A4BE0.mode == 1) {
        v.direction = D_L01_001E29E0;
    } else {
        v.direction = *(s128 *)(D_001A4BE0.camera + 0xC0);
    }
    v.rotation.x = 0.0f;
    v.rotation.y = -func_0038D160(func_0038CED8(&v.direction), ((f32 *)&v.direction)[2]) + -1.57079637f;
    v.rotation.z = func_0038D160(((f32 *)&v.direction)[0], ((f32 *)&v.direction)[1]);
    v.rotation.w = 1.0f;
    func_0038D328(v.matrix, &v.rotation);
    if (D_001A4BE0.aiming) {
        func_0038CE20(&v.second, (s128 *)(moby + 0xD0), -1.0f);
    } else if (D_001A4BE0.mode == 1) {
        v.second = D_L01_001E29E0;
    } else {
        v.second = *(s128 *)(D_001A4BE0.camera + 0xC0);
    }
    func_0038CE20(&v.second, &v.second, D_001DDE00_sda - 0.5f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(v.position) : "m"(v.position), "m"(v.second) : "vf1", "vf2");
    v.matrix[3] = v.position;
    func_0038CE20(&v.matrix[0], &v.matrix[0], D_001DDE08_sda);
    func_0038CE20(&v.matrix[1], &v.matrix[1], D_001DDE04_sda);
    func_0038CE20(&v.matrix[2], &v.matrix[2], D_001DDE00_sda);
    D_L01_001E1EA8 += 0.15f;
    if (D_L01_001E1EA8 >= 7.0f) D_L01_001E1EA8 -= 7.0f;
    D_L01_001E1EAC += 0.1f;
    if (D_L01_001E1EAC >= 7.0f) D_L01_001E1EAC -= 7.0f;
    D_L01_001E1EB0 += 0.05f;
    if (D_L01_001E1EB0 >= 7.0f) D_L01_001E1EB0 -= 7.0f;
    func_0038D890(&v.matrix[0], &v.matrix[0], &v.matrix[2], 0.785398185f);
    func_0038D890(&v.matrix[1], &v.matrix[1], &v.matrix[2], 0.785398185f);
    func_003D9740(v.matrix, D_001DDDF4_sda, (D_L01_001E1EA4 << 25) | 0x804020, 8, 1, D_L01_001E1EA8);
    func_0038D890(&v.matrix[0], &v.matrix[0], &v.matrix[2], -1.57079637f);
    func_0038D890(&v.matrix[1], &v.matrix[1], &v.matrix[2], -1.57079637f);
    func_003D9740(v.matrix, D_001DDDF8_sda, (D_L01_001E1EA4 << 25) | 0x801040, 8, 1, D_L01_001E1EAC);
    func_003D9740(v.matrix, D_001DDDFC_sda, (D_L01_001E1EA4 << 25) | 0x804010, 8, 1, D_L01_001E1EB0);
    func_0038CE20(&v.matrix[0], &v.matrix[0], 1.1f);
    func_0038CE20(&v.matrix[1], &v.matrix[1], 1.1f);
    func_003D9740(v.matrix, 10, (D_L01_001E1EA4 << 24) | 0xD20A40, 6, 1, D_L01_001E1EA8);
}
