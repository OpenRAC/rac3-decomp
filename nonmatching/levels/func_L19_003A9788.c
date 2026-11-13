/* func_L19_003A9788: 282 diff (140 aligned) in L19_003A96A8.c's flags plus -mvu0-use-vf0-vf2 and #include vu0.h, which the file lacks now (func_L19_003A96A8, its C block, not rechecked with them): a three-state mover with an aiming block (yaw/pitch clamps to +-pi/2 and +-pi/6) and two func_L01_0044E850 calls. The instructions are right up to scheduling; left is a saved-register rotation: retail has obj in s0, p in s1 and the constant 1 (also &D_L19_001E8C00 and hero+0x80 on other paths) in s2; here regalloc.py ranks obj first but it gets s1, so a local pseudo holds s0 across obj's life. Fixed so far: the D_L19_001DF438 stores as .x4 of an 8-byte struct at D_L19_001DF434 with .extern 16 (level 5's lui-at form, kept out of the jal slot), hero data as D_001A4BE0 + 0x80/0x90/0x110/0xE0 (retail's CSE of hero+0x80), the p + 0x100 vadd as j-form statements with direct memory operands (the vu0.h helper's pointer formals kept p + 0x100 in s0 across func_00382760). Not tried: which block-local pseudo takes s0 (regalloc.py lists only global ones) */
#include "vu0.h"
typedef int u128_t_3A9788 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A9788;
extern u8 D_001A4BE0[];
extern u32 D_00142C54;
typedef struct { s32 x0; s32 x4; } S_3A9788;
__asm__(".extern D_L19_001DF434, 16");
extern S_3A9788 D_L19_001DF434;
extern u8 *D_L19_001DF800;
extern u8 D_L19_001E8C00[];
extern void func_L19_003A96A8(u8 *);
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern s32 func_L04_0046FFA0(u8 *, s32, f32);
extern void *func_L01_0047F3B0(void *);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_004A3610(void *, void *);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L19_003A9788(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    s32 one = 1;
    s32 aim;
    f32 fa, fb, k;
    f32 yaw, pt;
    V4_3A9788 tgt;
    V4_3A9788 o;
    V4_3A9788 d;

    func_L19_003A96A8(obj);
    switch (obj[0x20]) {
    case 0:
        if (D_00142C54 & 0x400000) {
            func_003C2880(obj);
            return;
        }
        if (D_00142C54 & 0x200000) {
            func_L01_004450F0(obj, 3, -1);
            if (obj[0x43] != 0)
                func_003C3A10(obj, 0, 0, 0);
            *(u128_t_3A9788 *)(obj + 0x10) = *(u128_t_3A9788 *)(D_L19_001DF800 + *(s32 *)(p + 0x128) * 0x80 + 0x30);
            *(u128_t_3A9788 *)(obj + 0xF0) = *(u128_t_3A9788 *)(D_L19_001DF800 + *(s32 *)(p + 0x128) * 0x80 + 0x70);
        } else {
            func_L01_004450F0(obj, 1, -1);
            if (obj[0x43] != 2)
                func_003C3A10(obj, 2, 0, 0);
        }
        break;
    case 1:
        if (func_L04_0046FFA0(obj, 0xA, 2.5f) != 0) {
            func_L01_0047F3B0(obj);
            if (!(D_00142C54 & 0x200000) && func_00392B20(D_L19_001E8C00, 0xB5) != 0) {
                func_00392C78(D_L19_001E8C00);
                func_L01_004450F0(obj, 2, -1);
            }
        }
        break;
    case 2:
        if (D_L19_001D66D4 == 2) {
            obj[0x31] = 0;
            *(u16 *)(obj + 0x34) |= 1;
        }
        D_L19_001DF434.x4 = one;
        if (func_L01_004BA800() == 0) {
            if (*(s32 *)(p + 0x124) >= 0)
                func_L01_004F50C8(D_L19_001DF800 + *(s32 *)(p + 0x124) * 0x80 + 0x30,
                                  D_L19_001DF800 + *(s32 *)(p + 0x124) * 0x80 + 0x70, 0, 1);
            func_L01_004A3610(D_001A4BE0 + 0x80, D_001A4BE0 + 0x90);
            if (obj[0x43] != 0)
                func_003C3A10(obj, 0, 0, 0);
            *(u128_t_3A9788 *)(obj + 0x10) = *(u128_t_3A9788 *)(D_L19_001DF800 + *(s32 *)(p + 0x128) * 0x80 + 0x30);
            *(u128_t_3A9788 *)(obj + 0xF0) = *(u128_t_3A9788 *)(D_L19_001DF800 + *(s32 *)(p + 0x128) * 0x80 + 0x70);
            D_L19_001DF434.x4 = 0;
            obj[0x31] = one;
            *(u16 *)(obj + 0x34) &= 0xFFFE;
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    }
    if (obj[0x20] == 3) {
        if (obj[0x43] == 0 && func_0038CAD0(p + 0x11C) != 0) {
            *(s32 *)(p + 0x11C) = (s32)((func_003824E0(1200.0f, 2400.0f) * 5.0f + 2.0f) / 6.0f);
            if (obj[0x43] != 1)
                func_003C3A10(obj, 1, 0, 8);
        } else if ((obj[0x60] & 2) && obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 8);
        }
    }
    fa = 0.02f;
    fb = 0.3f;
    aim = 0;
    if (obj[0x43] == 0) {
        aim = 1;
        if (func_0038CF38(obj + 0x10, D_001A4BE0 + 0x80) < 8.0f &&
            func_0038DBA0(*(f32 *)(obj + 0xF8), func_0038D160(*(f32 *)(D_001A4BE0 + 0xE0) - *(f32 *)(obj + 0x10),
                                                              *(f32 *)(D_001A4BE0 + 0xE4) - *(f32 *)(obj + 0x14))) < 1.5707964f &&
            (D_00142C54 & 0x200000)) {
            if (0.01f < func_0038CEA8(D_001A4BE0 + 0x110))
                *(s32 *)(p + 0x114) = 0x64;
            else
                func_0038CAD0(p + 0x114);
        } else if (*(s32 *)(p + 0x114) != 0) {
            *(s32 *)(p + 0x114) = 0;
            *(u128_t_3A9788 *)(p + 0x100) = *(u128_t_3A9788 *)(D_001A4BE0 + 0xE0);
        }
        if (func_0038CAD0(p + 0x118) != 0) {
            *(s32 *)(p + 0x118) = (s32)((func_003824E0(180.0f, 300.0f) * 5.0f + 2.0f) / 6.0f);
            yaw = func_0038DAB8(*(f32 *)(obj + 0xF8), func_003824E0(-90.0f, 90.0f) * 0.017453292f);
            func_00382760(p + 0x100, 6.0f, yaw, func_003824E0(0.0f, 30.0f) * 0.017453292f);
            {
                vu0_q qa, qb, qr;
                __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(p + 0x100)));
                __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(obj + 0x10)));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(p + 0x100)) : "j"(qr));
            }
        }
        if (*(s32 *)(p + 0x114) != 0) {
            fa = 0.04f;
            fb = 0.3f;
            tgt = *(V4_3A9788 *)(D_001A4BE0 + 0xE0);
        } else {
            tgt = *(V4_3A9788 *)(p + 0x100);
        }
    }
    if (aim) {
        o = *(V4_3A9788 *)(obj + 0x10);
        o.z = o.z + 2.0f;
        vec_sub_ab(&d, &tgt, &o);
        yaw = func_0038DB00(func_0038D160(d.x, d.y), *(f32 *)(obj + 0xF8));
        pt = -func_0038D160(func_0038CED8(&d), d.z);
        if (1.5707964f < yaw)
            yaw = 1.5707964f;
        else if (yaw < -1.5707964f)
            yaw = -1.5707964f;
        if (0.5235988f < pt)
            pt = 0.5235988f;
        else if (pt < -0.5235988f)
            pt = -0.5235988f;
        *(f32 *)(p + 0xE4) = pt;
        *(f32 *)(p + 0xE8) = yaw * 0.6f;
        *(f32 *)(p + 0x68) = yaw * 0.4f;
    }
    if (D_001D5471 != 0)
        *(f32 *)(p + 0x70) = 2.75f;
    if (obj[0x20] != 3)
        *(f32 *)(p + 0xE4) = 0.2f;
    k = 1.44f;
    func_L01_0044E850(obj, p, 1, fa * k, fb * k);
    func_L01_0044E850(obj, p + 0x80, 0, fa * k, fb * k);
}
