/* functional: high. PAL port of the NTSC-U draft (C of func_L03_00438870), re-read against the PAL assembly. PAL differences from the draft: the 0x158 timer becomes (int)((rand*5+2)/6); both rates are scaled by 1.44 (PAL 50->60 Hz style) before the two func_L01_0044E850 calls; callees renumbered. The VU0 vsub.xyz is scalar (no VU0 flag on this file); the dead pickup copy in the draft's else-if is dropped (target is rewritten before use); qzero(s) is a plain 128-bit zero store. Not byte-matched. */
#include "structs/hero.h"
typedef int u128_0043BE98 __attribute__((mode(TI)));
extern u8 D_L03_001D66B0[];
extern struct Hero D_001A4BE0;
extern u8 D_001D5471[];
extern s32 func_L03_003FB6C8(void *, void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L03_0043BE98(u8 *m, u8 *s, s32 a2, s32 a3, s32 a4) {
    f32 delta[4] __attribute__((aligned(16)));
    f32 target[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 yaw, pitch;
    f32 rate1 = *(f32 *)(s + 0x120);
    f32 rate2 = *(f32 *)(s + 0x124);
    f32 x;
    *(s32 *)(s + 0x12C) = a4;
    if (!func_L03_003FB6C8(D_L03_001D66B0, s, 16)) {
        delta[0] = *(f32 *)(s + 0x0) - *(f32 *)(m + 0x10);
        delta[1] = *(f32 *)(s + 0x4) - *(f32 *)(m + 0x14);
        delta[2] = *(f32 *)(s + 0x8) - *(f32 *)(m + 0x18);
        yaw = func_0038DB00(func_0038D160(delta[0], delta[1]), *(f32 *)(m + 0xF8));
        pitch = -func_0038D160(func_0038CED8(delta), delta[2]);
    } else {
        if ((*(u8 *)(s + 0x14C) & 1) == 0 &&
            func_0038CF38(m + 0x10, &D_001A4BE0.pos) < *(f32 *)(s + 0x144) &&
            func_0038DBA0(*(f32 *)(m + 0xF8), func_0038D160(D_001A4BE0.pickup_point.x - *(f32 *)(m + 0x10), D_001A4BE0.pickup_point.y - *(f32 *)(m + 0x14))) < *(f32 *)(s + 0x140)) {
            if (func_0038CEA8(&D_001A4BE0.vel) > 0.01f) {
                *(s32 *)(s + 0x15C) = *(s32 *)(s + 0x148);
            } else {
                func_0038CAD0(s + 0x15C);
            }
        } else if (*(s32 *)(s + 0x15C)) {
            *(s32 *)(s + 0x15C) = 0;
        }
        if (func_0038CAD0(s + 0x158)) {
            *(s32 *)(s + 0x158) = (s32)((func_003824E0((f32)*(s32 *)(s + 0x150), (f32)*(s32 *)(s + 0x154)) * 5.0f + 2.0f) / 6.0f);
            *(f32 *)(s + 0x164) = func_003824E0(*(f32 *)(s + 0x118), *(f32 *)(s + 0x11C));
            *(f32 *)(s + 0x160) = func_003824E0(*(f32 *)(s + 0x110), *(f32 *)(s + 0x114));
        }
        if (*(s32 *)(s + 0x15C) && (*(u8 *)(s + 0x14C) & 1) == 0) {
            *(u128_0043BE98 *)target = *(u128_0043BE98 *)&D_001A4BE0.pickup_point;
            *(u128_0043BE98 *)pos = *(u128_0043BE98 *)(m + 0x10);
            target[2] += D_001A4BE0.pickup_point.z - D_001A4BE0.pos.z;
            pos[2] += *(f32 *)(s + 0x128);
            delta[0] = target[0] - pos[0];
            delta[1] = target[1] - pos[1];
            delta[2] = target[2] - pos[2];
            yaw = func_0038DB00(func_0038D160(delta[0], delta[1]), *(f32 *)(m + 0xF8));
            pitch = -func_0038D160(func_0038CED8(delta), delta[2]);
            *(f32 *)(s + 0x164) = yaw;
            *(f32 *)(s + 0x160) = pitch;
            rate2 *= 3.0f;
            rate1 *= 3.0f;
        } else {
            yaw = *(f32 *)(s + 0x164);
            pitch = *(f32 *)(s + 0x160);
            if ((*(s32 *)(s + 0x14C) & 2) == 0) {
                yaw = pitch = 0.0f;
            }
        }
    }
    if (yaw > *(f32 *)(s + 0x11C)) {
        yaw = *(f32 *)(s + 0x11C);
    } else if (yaw < *(f32 *)(s + 0x118)) {
        yaw = *(f32 *)(s + 0x118);
    }
    if (pitch > -*(f32 *)(s + 0x110)) {
        pitch = -*(f32 *)(s + 0x110);
    } else if (pitch < -*(f32 *)(s + 0x114)) {
        pitch = -*(f32 *)(s + 0x114);
    }
    if (*(s32 *)(s + 0x12C)) {
        x = yaw * *(f32 *)(s + 0x138);
        if (*(u16 *)(m + 0x34) & 0x8000) {
            x = -x;
        }
        *(f32 *)(s + 0x78) = x;
        x = yaw * *(f32 *)(s + 0x13C);
        if (*(u16 *)(m + 0x34) & 0x8000) {
            x = -x;
        }
        *(f32 *)(s + 0xF8) = x;
        *(f32 *)(s + 0xF4) = pitch * *(f32 *)(s + 0x13C);
        *(f32 *)(s + 0x74) = pitch * *(f32 *)(s + 0x138);
    }
    if (D_001D5471[0]) {
        *(f32 *)(s + 0x80) = 2.75f;
    }
    rate2 *= 1.44f;
    rate1 *= 1.44f;
    func_L01_0044E850(m, s + 0x10, a2, rate1, rate2);
    func_L01_0044E850(m, s + 0x90, a3, rate1, rate2);
    *(u128_0043BE98 *)s = 0;
}
