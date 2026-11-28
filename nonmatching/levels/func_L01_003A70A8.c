/* func_L01_003A70A8 (Claude wave 14 r71, 2026-11-28). First draft kept here. */
/* PAL near miss (r71, wave 14, 2026-11-28), first draft: 339 differences (wave10/p10/check.py, level 01, the file's flags,
 * with NEEDS divs row 'func_L01_003A70A8 1': retail has two nops before its div.s and the compiler already emits one for the
 * mtc1 before it). Written from the retail assembly over the functional C (nonmatching/functional/func_L01_003A70A8.c):
 * VU0 adds/subs through vu0.h in retail's load order; the hero block reached through an inline accessor returning
 * D_001A4BE0 (retail keeps only %hi(D_001A4BE0) in $s6 and rebuilds the address per region, which a constant address
 * folded with each field offset (496) or one pointer variable kept whole in $s4 (460) do not give: 387); the aim chain
 * rebuilt from retail's branches with one func_0038CF68 call after it (retail's three direction paths share one jal);
 * D_001D52FC read where it is used (retail loads it in each test's delay slot); plain externs for the small level globals
 * (Ps2EeAs gives lui/lw outside delay slots and the $gp form inside them, as retail shows for D_001D52FC, D_L01_001E2100,
 * D_L01_001E2104, D_L01_001E2120) and .extern hints for D_L01_001DE300/310/340/360, which retail always reaches through
 * $gp; fabs_asm for the abs.s; 0.020000001f for the 1/50 factor. Still differs: register allocation through the body
 * (retail keeps v + 0x10 in $s7 from the second store on, obj + 0xD0 in $fp, the aim chain's hero address in $s0 where
 * this C uses $a0), and one recomputed hero address before the fire test shifts the rest. */
#include "common.h"

/* localdecomp:start func_L01_003A70A8 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_00142A60[];
typedef struct { u8 x0; u8 x1; u8 pad2[0x6A]; f32 f6C; u8 pad70[0x80]; } Row_003A70A8;
extern Row_003A70A8 D_L01_002C5600[];
extern u8 D_L01_002BAE80[];
extern u8 *D_001D52FC;
extern s32 D_L01_001D6694;
extern s32 D_L01_001E2100;
extern s32 D_L01_001E2104;
extern s32 D_L01_001E2120;
extern u8 D_L01_001DAFF0;
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001E29E0[];
extern s32 D_L01_001DE360;
__asm__(".extern D_L01_001DE360, 4");
extern s32 D_L01_001DE340;
__asm__(".extern D_L01_001DE340, 4");
extern u8 D_L01_001DE300[8];
__asm__(".extern D_L01_001DE300, 8");
extern u8 D_L01_001DE310[8];
__asm__(".extern D_L01_001DE310, 8");

static __inline__ u8 *hero_003A70A8(void) {
    return D_001A4BE0;
}

void func_L01_003A70A8(u8 *obj) {
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern u8 *func_L01_00450BB0(void *, void *, s32, f32, f32, f32, f32, f32);
    extern void func_L01_004CB128(void *, void *, s32);
    extern void func_L01_003F6F20(s32, void *, s32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern void func_L01_0035BF48(u8 *, void *, void *, s32, s32, f32, f32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_003A78E8(u8 *);
    extern void func_L01_003A7B38(u8 *);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32, s32);
    extern s32 func_L01_003F1FC0(s32, s32);
    u128_t a, b, c;
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *target;
    s32 t;
    f32 d;
    f32 ang;
    f32 w;
    f32 f13;
    Vec4 *dir;
    f32 k;

    if (obj[0x20] == 0) {
        obj[0x30] = 0xFF;
        D_L01_001E2104 = 0;
        *(s32 *)(v + 0x58) = -1;
        obj[0x20] = 1;
    }
    if (D_L01_002C5600[D_001425C0[0x2F]].x1 >= 2) D_00142A60[0x2F] |= 0x20;
    if (D_L01_002C5600[D_001425C0[0x2F]].x1 >= 3) D_00142A60[0x2F] |= 2;
    t = D_L01_002C5600[D_001425C0[0x2F]].x1;
    if (t == 2) {
        *(s16 *)(obj + 0x7C) = 3;
    } else if (t == 1) {
        *(s16 *)(obj + 0x7C) = 1;
    }
    if (*(s32 *)(hero_003A70A8() + 0x25C4) == 1) func_L01_005003D0(0x1D, 1);
    if (obj[0x42] == obj[0x43] && (obj[0x60] & 2)) {
        func_L01_00444F38(obj, 1, 0, 2, 0);
    }
    func_0038D000(&a, D_L01_001DE300, obj + 0xC0);
    vec_add_ab(&a, &a, obj + 0x10);
    *(u128_t *)(v + 0x10) = a;
    func_0038D000(&b, D_L01_001DE310, obj + 0xC0);
    vec_add_ab(&b, &b, obj + 0x10);
    *(u128_t *)(v + 0x20) = b;
    func_0038CF68(v + 0x40, (Vec4 *)(obj + 0xD0), -20.0f);
    func_0038CF68(v + 0x30, (Vec4 *)(*(u8 **)(hero_003A70A8() + 0x25C0) + 0xC0), 1.0f);
    if (D_L01_001DAFF0 != 0) {
        target = func_L01_00450BB0(v + 0x10, v + 0x30, 0, 0.34906584f, 0.17453292f, 50.0f, 0.78539819f, 0.78539819f);
    } else {
        target = func_L01_00450BB0(v + 0x10, v + 0x30, 0, 0.052359879f, 0.10471976f, 35.0f, 0.78539819f, 0.78539819f);
    }
    if (*(u8 **)(hero_003A70A8() + 0x1430) != 0) {
        *(u8 **)(hero_003A70A8() + 0xBD8) = *(u8 **)(hero_003A70A8() + 0x1430);
        target = *(u8 **)(hero_003A70A8() + 0x1430);
    }
    if (target != 0) {
        func_L01_004CB128(&c, target, 0);
        vec_sub_ba(v + 0x30, &c, v + 0x10);
        func_0038CF68(v + 0x30, (Vec4 *)(v + 0x30), 20.0f);
        vec_add_ab(v, v + 0x30, &a);
        if (*(s32 *)(hero_003A70A8() + 0x25C4) != 0x1D && *(s32 *)(hero_003A70A8() + 0x16B0) == 0) {
            d = func_0038CF00(D_L01_001E29C0, &c) / 150.0f;
            ang = func_0038DAB8(*(f32 *)(v + 0x5C), 0.034906585f);
            *(f32 *)(v + 0x5C) = ang;
            w = fabs_asm(0.9f - d * 0.65f);
            func_L01_003F6F20(0, obj, 0xFF0FFF0F, &c, 0x26, -1, 4, w, -ang, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            *(u8 **)(hero_003A70A8() + 0xBD8) = target;
        }
    }
    if (*(s16 *)(hero_003A70A8() + 0x2874) != 0 && *(s32 *)(hero_003A70A8() + 0x25C4) != 0x1D &&
        (*(s32 *)(hero_003A70A8() + 0x16B0) == 0 || *(s32 *)(hero_003A70A8() + 0x1430) != 0)) {
        dir = (Vec4 *)(obj + 0xD0);
        k = -20.0f;
    } else if (*(s32 *)(hero_003A70A8() + 0x25C4) == 0x1D ||
               (*(s32 *)(hero_003A70A8() + 0x16B0) != 0 && *(s32 *)(hero_003A70A8() + 0x1430) == 0)) {
        s32 h;
        func_0038CF68(v + 0x30, (Vec4 *)D_L01_001E29E0, 20.0f);
        vec_add_ba(v, v + 0x30, &a);
        h = func_L01_004CB1F0(0.99f, 150.0f);
        func_L01_003F6F20(0, obj, h, 0, 0x56, -1, 4, 0.75f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        *(u8 **)(hero_003A70A8() + 0xBD8) = target;
        goto after_aim;
    } else if (*(s32 *)(hero_003A70A8() + 0x25C4) == 0x1D ||
               (*(s32 *)(hero_003A70A8() + 0x16B0) != 0 && *(s32 *)(hero_003A70A8() + 0x1430) != 0)) {
        func_L01_004CB128(&c, target, 0);
        vec_sub_ba(v + 0x30, &c, v + 0x10);
        dir = (Vec4 *)(v + 0x30);
        k = 20.0f;
    } else if (target == 0) {
        dir = (Vec4 *)(*(u8 **)(hero_003A70A8() + 0x25C0) + 0xC0);
        k = 20.0f;
    } else {
        goto after_aim;
    }
    func_0038CF68(v + 0x30, dir, k);
    vec_add_ab(v, v + 0x30, &a);
    *(s32 *)(hero_003A70A8() + 0x16D8) = 0;
    *(s32 *)(hero_003A70A8() + 0x16D4) = 0;
after_aim:
    if ((hero_003A70A8()[0x25ED] == 0 && D_L01_001D6694 == 0 && *(s32 *)(hero_003A70A8() + 0x1220) >= 0x13 &&
         (*(s32 *)(D_001D52FC + 0x1A0) & *(s32 *)(hero_003A70A8() + 0x1210)) != 0) ||
        ((*(s32 *)(D_001D52FC + 0x1A0) & 8) != 0 && *(s32 *)(hero_003A70A8() + 0x25C4) == 0x1D)) {
        D_L01_001E2104 = D_L01_001E2104 + 1;
        *(s32 *)(v + 0x54) = 0x11;
        if (func_0038CAD0(&D_L01_001E2100) != 0) {
            if (func_L01_005118D0(-1, 1) != 0) {
                func_L01_004EA7D8(-1);
                D_L01_001E2120 = 1;
                *(s32 *)(v + 0x58) = func_L01_003F2058(D_L01_002BAE80, 0);
                w = func_003824E0(60.0f, 80.0f);
                func_0038CF68((u8 *)&c, (Vec4 *)(v + 0x30), w * 0.020000001f);
                func_003A52A0(3, 0, obj);
                f13 = 0.75f;
                if (target != 0) f13 = 0.0f;
                if (D_L01_001DE360 != 0) {
                    func_L01_0035BF48(obj, v + 0x20, &c, 0x10000, D_L01_001DE340, D_L01_002C5600[D_001425C0[0x2F]].f6C, f13);
                    D_L01_001DE360 = 0;
                } else {
                    func_L01_0035BF48(obj, v + 0x10, &c, 0x10000, D_L01_001DE340, D_L01_002C5600[D_001425C0[0x2F]].f6C, f13);
                    D_L01_001DE360 = 1;
                }
                D_L01_001E2100 = 12;
                func_L01_00404A10(func_L01_003A7B38, obj);
                func_L01_003A78E8(obj);
            } else if ((*(s32 *)(D_001D52FC + 0x1A4) & *(s32 *)(hero_003A70A8() + 0x1210)) != 0 || D_L01_001E2120 == 1) {
                func_003A52A0(4, 0, obj);
                D_L01_001E2120 = 0;
            }
        }
    } else {
        func_L01_004EAA80();
        D_L01_001E2100 = 0;
        if (*(s32 *)(v + 0x54) <= 0) D_L01_001E2104 = 0;
    }
    if (!((*(s32 *)(D_001D52FC + 0x1A0) & *(s32 *)(hero_003A70A8() + 0x1210)) != 0 && func_L01_005119E0(-1) != 0 &&
          hero_003A70A8()[0x25E9] != 0)) {
        if (*(s32 *)(v + 0x58) < 0) return;
        func_L01_003F2278(*(s32 *)(v + 0x58), 0);
        *(s32 *)(v + 0x58) = -1;
    }
    if (*(s32 *)(v + 0x58) > 0) {
        if (func_L01_003F1FC0(*(s32 *)(v + 0x58) - 1, 0) == 0) {
            *(s32 *)(v + 0x58) = -1;
        }
    }
}
/* localdecomp:end func_L01_003A70A8 */
